#pragma once

namespace Minecraft {

	class TimeStep {

	private:
		float m_TimeStep;
		float m_LastTime;

	public:
		TimeStep() = delete;
		TimeStep(float initialTime);

		void Update(float currentTime);

		float GetMillis() const { return m_TimeStep; }
		float GetSeconds() const { return m_TimeStep / 1000.0f; }
	};
}
