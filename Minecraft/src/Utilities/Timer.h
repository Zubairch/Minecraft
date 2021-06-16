#pragma once

#include <MC.h>

namespace Minecraft {

	class Timer {

	public:
		Timer() = delete;
		~Timer() = delete;

		static float GetMillis() { return (float)glfwGetTime() * 1000.0f; }
		static float GetSeconds() { return (float)glfwGetTime(); }
	};
}
