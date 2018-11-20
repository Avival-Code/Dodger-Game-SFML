#include "FrameTimer.h"

using namespace std::chrono;

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
	Buff = steady_clock::now();
	TotalT = steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frametime = last - old;
	return frametime.count();
}

void FrameTimer::SetTimer()
{
	Buff = steady_clock::now();
}

float FrameTimer::ReturnTimerDifference()
{
	steady_clock::time_point curr = steady_clock::now();
	const duration<float> TotT = curr - Buff;
	return TotT.count();
}

float FrameTimer::GetTime()
{
	steady_clock::time_point curr = steady_clock::now();
	const duration<float> TotalTime = curr - TotalT;
	return TotalTime.count();
}
