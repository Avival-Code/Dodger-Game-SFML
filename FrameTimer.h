#pragma once
#include <chrono>
#include <string>

class FrameTimer
{
public:
	FrameTimer();
	float Mark();
	void SetTimer();
	float ReturnTimerDifference();
	float GetTime();
private:
	std::chrono::steady_clock::time_point last;
	std::chrono::steady_clock::time_point Buff;
	std::chrono::steady_clock::time_point TotalT;
};
