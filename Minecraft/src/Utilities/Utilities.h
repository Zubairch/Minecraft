#pragma once

#include <math.h>

#define BIT(X) (1 << X)

namespace Minecraft {

	inline static double round(double d) {

		return floor(d + 0.5);
	}

	inline static double Map(double x, double x0, double x1, double y1, double y2) {

		double slope = 1.0 * (y2 - y1) / (x1 - x0);

		return y1 + round(slope * (x - x1));
	}

	inline static int Abs(int value) {

		if (value < 0)
			return -value;
		return value;
	}
}




