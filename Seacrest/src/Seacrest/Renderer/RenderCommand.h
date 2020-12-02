#pragma once

#include "RendererAPI.h"

namespace Seacrest {

    class RenderCommand
    {
    public:
        inline static void SetRenderTargets()
        {
            s_RendererAPI->SetRenderTargets();
        }
        inline static void SetClearColor( const DirectX::XMFLOAT4& color )
        {
            s_RendererAPI->SetClearColor( color );
        }
        inline static void Clear()
        {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed( const std::shared_ptr<InputLayout>& inputLayout )
        {
            s_RendererAPI->DrawIndexed( inputLayout );
        }
    private:
        static RendererAPI* s_RendererAPI;
    };

}