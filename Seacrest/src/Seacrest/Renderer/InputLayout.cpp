#include "scpch.h"
#include "InputLayout.h"

#include "Renderer.h"
#include "Platform/Direct3D/Direct3DInputLayout.h"

namespace Seacrest {

	InputLayout* InputLayout::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:     SEACREST_ASSERT( false, "RendererAPI::None is currently not supported!" );  return nullptr;
			case RendererAPI::API::Direct3D: return new Direct3DInputLayout();
		}

		SEACREST_ASSERT( false, "Unknown RendererAPI!" );
		return nullptr;
	}
}
