#pragma once

#include "Core.h"

#include "Window.h"

#include "Seacrest/LayerStack.h"
#include "Events/Event.h"
#include "Seacrest/Events/ApplicationEvent.h"

#include "Seacrest/ImGui/ImGuiLayer.h"

#include "Seacrest/Renderer/Shader.h"

namespace Seacrest {

	class SEACREST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent( Event& e );

		void PushLayer( Layer* layer );
		void PushOverlay( Layer* layer );

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize( WindowResizeEvent& e );

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		GraphicsContext* m_Context;
		// TEMP
		ID3D11Device* m_Device;
		ID3D11DeviceContext* m_DeviceContext;
		UINT m_VertexBuffer;
		UINT m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT. 
	Application* CreateApplication();
}