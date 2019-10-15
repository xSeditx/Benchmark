#pragma once

#include<chrono>
#include<iostream>
#include<vector>

#include"Window.h"

#include<algorithm>// Minmax algorithm
#include<utility> // std::pair

/* Starts the Benchmark named str and Cycles it x amount of times.*/
#define BENCH_MARK(str, _cycles)  Benchmark Timer##str(#str, _cycles);\
for(unsigned int i{0}; i < (_cycles); ++i){\



/* Cycles the Loop and Samples the Timer. At the end it stops the Timer and Stores the values*/
#define END_BENCHMARK(str)   Timer##str.Sample();\
}\
Timer##str.End()


/* Renders an Event Loop which displays the Benchmark results */
#define DISPLAY_BENCHMARKS bool Running = true;\
while (Running)\
{\
DrawGraph(&Win);\
	SDL_Event event;\
	while (SDL_PollEvent(&event)) {\
		if (event.type == SDL_QUIT)\
		{\
			Running = false;\
		}\
	}\

#define DISPLAY_END Win.Sync();\
	Win.CLS();\
    SDL_Delay(500)/*else our CPU usage gets to high*/;\
}\


#define DISPLAY(str)  Timer##str.Render(&Win, .01);


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

extern double MAX_GRAPH_VALUE;

class Benchmark
{
public:
	Benchmark();
	Benchmark(std::string name, unsigned int _samples_per_store);
	~Benchmark();

	std::chrono::time_point<std::chrono::steady_clock>  StartTime;
	unsigned long long  TotalTime;

	std::vector<double> Values;

	unsigned int Accumulator{ 0 };
	unsigned int TotalSamplesTaken{ 0 };
	unsigned long long PreviousClock{ 0 };

	long long AverageTimer{ 0 };
	long long AverageResult{ 0 };

	std::string Name{ "" };

 	unsigned char r{ 0 }, g{ 0 }, b{ 0 };

	double MinValue, MaxValue;
	void Sample();
	void Start();
	void End();

	void Render(Window *_win,float Normalize);
};


//
//
//
//template<class ForwardIt>
//std::pair<ForwardIt, ForwardIt>// Return value
//minmax_element(ForwardIt first, ForwardIt last)
//{// For normalizing the Datas Min and Max values for display on our graph
//	using value_type = typename std::iterator_traits<ForwardIt>::value_type;
//	return std::minmax_element(first, last, std::less<value_type>());
//}