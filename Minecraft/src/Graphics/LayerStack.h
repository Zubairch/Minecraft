#pragma once

#include <MC.h>

namespace Minecraft {

	class Layer;
	
	class LayerStack {

	private:
		eastl::vector<Layer*> m_Layers;

	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer();

		eastl::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		eastl::vector<Layer*>::iterator end() { return m_Layers.end(); }
	};
}
