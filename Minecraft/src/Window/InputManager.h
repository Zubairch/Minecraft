#pragma once

#include <MC.h>

namespace Minecraft {

	enum class MouseCursor {
		Normal = 0,
		Hidden,
		Disabled
	};

	class InputManager {

	private:
		static InputManager* s_Instance;

	public:
		InputManager() = default;
		~InputManager() = default;

		void Init();
		void Shutdown();

		inline static InputManager* Create() { return s_Instance = new InputManager(); }
		inline static InputManager* GetInstance() { return s_Instance; }

		bool IsKeyPressed(int key) const;
		bool IsButtonPressed(int button) const;

		glm::vec2 GetMousePosition() const;
		void SetMousePosition(const glm::vec2& position);

		void SetMouseCursor(MouseCursor cursor);

	private:
		int ToGLFWCursorMode(MouseCursor cursor) const;
	};
}
