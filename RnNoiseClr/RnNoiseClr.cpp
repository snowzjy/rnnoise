#include "RnNoiseClr.h"

using namespace System;
using namespace RnNoiseClr;

RNNoiseCLR::RNNoiseCLR() : native{ *new RNNoise{} } { }

RNNoiseCLR::!RNNoiseCLR() { delete &native; }

RNNoiseCLR::~RNNoiseCLR() { this->!RNNoiseCLR(); }

float RNNoiseCLR::Transform(array<short> ^out, array<const short> ^in)
{
	if (!out)
		throw gcnew ArgumentNullException{ "out" };
	if (!in)
		throw gcnew ArgumentNullException{ "in" };
	if (out->Length != FRAME_SIZE || in->Length != FRAME_SIZE)
		throw gcnew ArgumentOutOfRangeException{ "Frame size must be 480" };
	pin_ptr<short> _out{ &out[0] };
	pin_ptr<const short> _in{ &in[0] };
	return native.transform(_out, _in);
}