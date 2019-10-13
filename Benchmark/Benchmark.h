#pragma once

#include<chrono>
#include<iostream>

#define Print(x)  std::cout << x << "\n"

enum TimerResolution
{
	Nanoseconds,
	Milliseconds,
	Seconds,
	Minutes,
	Hours,
	Days,
	System,
};
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<std::chrono::system_clock> SystemClock;
typedef std::chrono::time_point<std::chrono::steady_clock> SteadyClock;
typedef std::chrono::duration<float> fDuration;



class Benchmark
{
public:
	Benchmark();
	Benchmark(std::string name);

	~Benchmark();
	std::chrono::time_point<std::chrono::steady_clock>  PerformanceTimer;

	float NumberOfSamples = 100;
	int Accumulator;
	std::string Name;

	static int ObjectCounter;
	static long long AverageTimer;
	static long long AverageResult;

	void Start();
	void End();
};





