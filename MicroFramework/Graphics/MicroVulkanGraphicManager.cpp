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

#pragma once

#include "__micro_framework_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroVulkanGraphicManager::MicroVulkanGraphicManager( )
	: MicroGraphicManager{ },
	m_vulkan{ },
	m_render_context{ }
{ }

bool MicroVulkanGraphicManager::Create(
	MicroWindow& window, 
	const MicroVulkanSpecification& specification 
) {
	return m_vulkan.Create( window, specification );
}

bool MicroVulkanGraphicManager::Acquire( const MicroWindow& window ) {
	return m_should_render && m_vulkan.Acquire( window, m_render_context, m_should_resize );
}

MicroVulkanRenderPassInfo MicroVulkanGraphicManager::AcquireRenderPass(
	const uint32_t render_pass 
) {
	return m_vulkan.AcquireRenderPass( m_render_context, render_pass );
}

void MicroVulkanGraphicManager::Submit( ) {
	m_vulkan.Submit( m_render_context );
}

void MicroVulkanGraphicManager::Present( const MicroWindow& window ) {
	m_vulkan.Present( window, m_render_context, m_should_resize );
}

void MicroVulkanGraphicManager::Destroy( MicroWindow& window ) {
	m_vulkan.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroVulkan& MicroVulkanGraphicManager::GetVulkan( ) {
	return m_vulkan;
}

const MicroVulkan& MicroVulkanGraphicManager::GetVulkan( ) const {
	return m_vulkan;
}

MicroVulkanRenderContext& MicroVulkanGraphicManager::GetRenderContext( ) {
	return m_render_context;
}

const MicroVulkanDevice& MicroVulkanGraphicManager::GetDevice( ) const {
	return m_vulkan.GetDevice( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroVulkanGraphicManager::operator MicroVulkan& ( ) {
	return GetVulkan( );
}

MicroVulkanGraphicManager::operator const MicroVulkan& ( ) const {
	return GetVulkan( );
}

MicroVulkanGraphicManager::operator MicroVulkanRenderContext& ( ) {
	return GetRenderContext( );
}
