#include <MC.h>

#include "LayerStack.h"
#include "Layer.h"

namespace Minecraft {

	LayerStack::~LayerStack() {

		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer) {

		m_Layers.push_back(layer);
		layer->OnAttach();
	}

	void LayerStack::PopLayer() {

		auto layer = m_Layers.back();
		layer->OnDetach();

		delete layer;
	}
}