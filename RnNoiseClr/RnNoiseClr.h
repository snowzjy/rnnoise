#pragma once

#include "../RnNoise/RNNoise.h"

namespace RnNoiseClr {
	public ref class RNNoiseCLR
	{
		RNNoise *native;

	public:
		literal int FRAME_SIZE = 480;

		RNNoiseCLR();
		!RNNoiseCLR();
		~RNNoiseCLR();

		inline float Transform(array<float> ^out, array<const float> ^in) { return Transform(out, 0, in, 0); }
		float Transform(array<float> ^out, int out_offset, array<const float> ^in, int in_offset);
	};
}