/**
 *
 *  __  __ _            ___                                  _
 * |  \/  (_)__ _ _ ___| __| _ __ _ _ __  _____ __ _____ _ _| |__
 * | |\/| | / _| '_/ _ \ _| '_/ _` | '  \/ -_) V  V / _ \ '_| / /
 * |_|  |_|_\__|_| \___/_||_| \__,_|_|_|_\___|\_/\_/\___/_| |_\_\
 *
 * MIT License
 *
 * Copyright (c) 2024- Alves Quentin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **/

#include "__micro_framework_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroImVKBackend::MicroImVKBackend( )
	: MicroImBackend{ },
	m_local_pools{ VK_NULL_HANDLE }
{ }

bool MicroImVKBackend::Create(
    const MicroWindow& window,
    const MicroImSpecification& specification,
    void* graphics
) {
    return  CreatePools( specification, micro_ref_as( graphics, MicroVulkan ) ) &&
            CreateInstance( window, specification, micro_ref_as( graphics, MicroVulkan ) );
}

void MicroImVKBackend::Prepare( ) {
    ImGui_ImplVulkan_NewFrame( );
    ImGui_ImplSDL3_NewFrame( );
}

void MicroImVKBackend::Flush( void* context ) {
    auto* render_context = micro_cast( context, MicroVulkanRenderContext* );
    auto* draw_data      = ImGui::GetDrawData( );

    ImGui_ImplVulkan_RenderDrawData( draw_data, render_context->CommandBuffer );
}

void MicroImVKBackend::Terminate( void* graphics ) {
    auto* vk_graphics = micro_cast( graphics, MicroVulkan* );
    auto& device      = vk_graphics->GetDevice( );

    ImGui_ImplVulkan_Shutdown( );
    ImGui_ImplSDL3_Shutdown( );

    vk::DestroyDescriptorPool( device, m_local_pools );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImVKBackend::CreatePools(
    const MicroImSpecification& specification,
    MicroVulkan& graphics
) {
    VkDescriptorPoolSize pool_sizes[] = {
        { VK_DESCRIPTOR_TYPE_SAMPLER               , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE         , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE         , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER  , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER  , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER        , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER        , specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, specification.PoolSize },
        { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT      , specification.PoolSize }
    };

    auto pool_info = VkDescriptorPoolCreateInfo{ VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO };
    auto device    = graphics.GetDevice( );
    auto size      = (uint32_t)IM_ARRAYSIZE( pool_sizes );

    pool_info.pNext         = VK_NULL_HANDLE;
    pool_info.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
    pool_info.maxSets       = specification.PoolSize * size;
    pool_info.poolSizeCount = size;
    pool_info.pPoolSizes    = pool_sizes;

    return vk::CreateDescriptorPool( device, pool_info, m_local_pools ) == VK_SUCCESS;
}

bool MicroImVKBackend::CreateInstance(
    const MicroWindow& window,
    const MicroImSpecification& specification,
    MicroVulkan& graphics
) {
    const auto& swap_spec = graphics.GetSwapchainSpecification( );
    auto& device          = graphics.GetDevice( );
    auto& queues          = graphics.GetQueues( );
    auto init_info        = ImGui_ImplVulkan_InitInfo{ };
    auto queue            = queues.Acquire( vk::QUEUE_TYPE_GRAPHICS );
    auto state            = false;

    init_info.Instance        = graphics.GetInstance( );
    init_info.PhysicalDevice  = device.GetPhysical( );
    init_info.Device          = device;
    init_info.QueueFamily     = queues.GetQueueFamily( vk::QUEUE_TYPE_GRAPHICS );
    init_info.Queue           = queue.Queue;
    init_info.DescriptorPool  = m_local_pools;
    init_info.RenderPass      = VK_NULL_HANDLE;
    init_info.MinImageCount   = swap_spec.ImageCount;
    init_info.ImageCount      = swap_spec.ImageCount;
    init_info.MSAASamples     = VK_SAMPLE_COUNT_1_BIT;
    init_info.PipelineCache   = graphics.GetPipelineCache( );
    init_info.Subpass         = specification.Subpass;
    init_info.Allocator       = micro_ptr( vk::GetAllocationCallback( ) );
    init_info.CheckVkResultFn = MicroImVKBackend::CheckVulkanResult;

    state = ImGui_ImplSDL3_InitForVulkan( window ) &&
            ImGui_ImplVulkan_Init( micro_ptr( init_info ) );

    queues.Release( queue );

    return state;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE STATIC ===
////////////////////////////////////////////////////////////////////////////////////////////
void MicroImVKBackend::CheckVulkanResult( VkResult result ) {
    if ( result == VK_SUCCESS )
        return;

    const auto* message = vk::GetResultString( result );
    
    switch ( result ) {
        default:
        case  VK_NOT_READY:
        case  VK_TIMEOUT:
        case  VK_EVENT_SET:
        case  VK_EVENT_RESET:
        case  VK_INCOMPLETE:
        case  VK_SUBOPTIMAL_KHR:
        case  VK_THREAD_IDLE_KHR:
        case  VK_THREAD_DONE_KHR:
        case  VK_OPERATION_DEFERRED_KHR:
        case  VK_OPERATION_NOT_DEFERRED_KHR:
        case  VK_PIPELINE_COMPILE_REQUIRED_EXT:
            micro::log_warn( "ImGui Backend : {0:s}", message );
            break;

        case  VK_ERROR_OUT_OF_HOST_MEMORY:
        case  VK_ERROR_OUT_OF_DEVICE_MEMORY:
        case  VK_ERROR_INITIALIZATION_FAILED:
        case  VK_ERROR_DEVICE_LOST:
        case  VK_ERROR_MEMORY_MAP_FAILED:
        case  VK_ERROR_LAYER_NOT_PRESENT:
        case  VK_ERROR_EXTENSION_NOT_PRESENT:
        case  VK_ERROR_FEATURE_NOT_PRESENT:
        case  VK_ERROR_INCOMPATIBLE_DRIVER:
        case  VK_ERROR_TOO_MANY_OBJECTS:
        case  VK_ERROR_FORMAT_NOT_SUPPORTED:
        case  VK_ERROR_FRAGMENTED_POOL:
        case  VK_ERROR_SURFACE_LOST_KHR:
        case  VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
        case  VK_ERROR_OUT_OF_DATE_KHR:
        case  VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
        case  VK_ERROR_INVALID_SHADER_NV:
        case  VK_ERROR_OUT_OF_POOL_MEMORY:
        case  VK_ERROR_INVALID_EXTERNAL_HANDLE:
        case  VK_ERROR_FRAGMENTATION:
        case  VK_ERROR_INVALID_DEVICE_ADDRESS_EXT:
        case  VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
        case  VK_ERROR_UNKNOWN:
            micro::log_errr( "ImGui Backend : {0:s}", message );
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
const VkDescriptorPool& MicroImVKBackend::GetLocalPools( ) const {
    return m_local_pools;
}
