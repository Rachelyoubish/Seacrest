#include "scpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/DirectX/DirectXBuffer.h"

namespace Seacrest {

	VertexBuffer* VertexBuffer::Create( const std::vector<float>& vertices, uint32_t size )
	{
		switch (Renderer::GetCurrentAPI())
		{
			case RendererAPI::None:     SEACREST_ASSERT(false, "RendererAPI::None is currently not supported!");  return nullptr;
			case RendererAPI::Direct3D: return new DirectXVertexBuffer(vertices, size);
		}

		SEACREST_ASSERT( false, "Unknown RendererAPI!" );
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create( const std::vector<unsigned short>& indices, unsigned short size)
	{
		switch (Renderer::GetCurrentAPI())
		{
			case RendererAPI::None:     SEACREST_ASSERT( false, "RendererAPI::None is currently not supported!" );  return nullptr;
			case RendererAPI::Direct3D: return new DirectXIndexBuffer( indices, size );
		}

		SEACREST_ASSERT( false, "Unknown RendererAPI!" );
		return nullptr;
	}
}