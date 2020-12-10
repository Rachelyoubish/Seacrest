#include "scpch.h"
#include "Renderer.h"

#include "Platform/Direct3D/Direct3DShader.h"

namespace Seacrest {

    Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData;

    void Renderer::BeginScene( OrthographicCamera& camera  )
    {
        s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit( const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<IndexBuffer>& indexBuffer, const DirectX::XMMATRIX& transform  )
    {
        shader->Bind();
        std::dynamic_pointer_cast<Direct3DShader>(shader)->UploadConstantMat( "Camera", s_SceneData->ViewProjectionMatrix );
        std::dynamic_pointer_cast<Direct3DShader>( shader )->UploadConstantMat( "Transform", transform);


        vertexBuffer->Bind();
        indexBuffer->Bind();
        RenderCommand::DrawIndexed( indexBuffer );
    }
}