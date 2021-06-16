#include <MC.h>

#include "Timestep.h"

namespace Minecraft {

	TimeStep::TimeStep(float initialTime)
		: m_TimeStep(0), m_LastTime(initialTime) { }

	void TimeStep::Update(float currentTime) {

		m_TimeStep = currentTime - m_LastTime;
		m_LastTime = currentTime;
	}
}