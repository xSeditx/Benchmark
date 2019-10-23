#include<string>
#include"Benchmark.h"


#include <ctime>
#include<cmath>

#define POINT_SIZE  2
#define CYCLES_PER_SAMPLE  100


#pragma optimize( "BenchMark::Start()", off )
#pragma optimize( "BenchMark::End()", off )
#pragma optimize( "", off )

long long MAX_GRAPH_VALUE{ 0 };

using Resolution = std::chrono::nanoseconds; // std::chrono::microseconds;


Benchmark::Benchmark()
	:
	Accumulator(0)
{
	StartTime = std::chrono::high_resolution_clock::now();
}
Benchmark::Benchmark(std::string _name, unsigned int _samples_per_store)
{
	Name = _name;
	StartTime = std::chrono::high_resolution_clock::now();
 
	Accumulator = 0;
	Values.reserve(100000);
 
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
}
Benchmark::~Benchmark()
{}

void Benchmark::Start()
{
	Accumulator++;
	StartTime = std::chrono::high_resolution_clock::now();	
}
void Benchmark::End()
{
	TotalTime = std::chrono::duration_cast  <Resolution>  (std::chrono::high_resolution_clock::now() - StartTime).count();
	Print("Total Time was " << TotalTime << " for " << TotalSamplesTaken << " samples.");
	Print("Average Results for " << Name << " : " << (float)TotalTime / (float)TotalSamplesTaken << " m\s");

	AverageResult = (long long)((float)AverageTimer / (float)TotalSamplesTaken);
	Values.erase(Values.begin(), Values.begin() + 2);
	 
	std::pair< std::vector<long long>::iterator, std::vector<long long>::iterator> MM;
	MM = minmax_element(Values.begin(), Values.end());
	MinValue = *MM.first;
	MaxValue = *MM.second;
	if (MaxValue > MAX_GRAPH_VALUE)
	{
		MAX_GRAPH_VALUE = MaxValue;
		std::cout << "Graph Max = " << MAX_GRAPH_VALUE << "\n";
	}
}
void Benchmark::Sample()
{
	unsigned long long Current = std::chrono::duration_cast <Resolution> (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	AverageTimer += (Current - PreviousClock);
	PreviousClock = Current;
	TotalSamplesTaken++;
	if (++Accumulator >= CYCLES_PER_SAMPLE)
	{
		Values.emplace_back((float)AverageTimer / CYCLES_PER_SAMPLE);  

		Accumulator = 0;
		AverageTimer = 0;
	}
}

void Benchmark::Render(Window *_win, float Normalize)
{
	SDL_SetRenderDrawColor(_win->Context, r, g, b, (255 * 0.5f));

	float
		x = BOARDER, 
		x2 = BOARDER;

	float Xincrement = (float)(_win->width  - (BOARDER * 2.0f)) / (float)Values.size();
	float Yincrement = (float)(_win->height - (BOARDER * 2.0f)) / (float)MAX_GRAPH_VALUE;

	float // Set them as such to prevent chart starting at zero
		y  = (_win->height - BOARDER) - (Values[0] * Yincrement),
		y2 = (_win->height - BOARDER) - (Values[0] * Yincrement);


	for (auto& V : Values)
	{
		x2 += Xincrement;
		y2 = (_win->height - BOARDER) - (V * Yincrement); 

		SDL_RenderDrawLine(_win->Context, x, y, x2, y2);

		SDL_Rect R
		{
			(x - (POINT_SIZE * 0.5f)),
			(y - (POINT_SIZE * 0.5f)),
			(POINT_SIZE),
			(POINT_SIZE),
		};

		SDL_RenderFillRect(_win->Context, &R);
		x = x2;	y = y2;
	}
	SDL_SetRenderDrawColor(_win->Context, COLOR_BLACK);
}




	//PerformanceTimer = std::chrono::high_resolution_clock::now();
	//std::chrono::time_point<std::chrono::steady_clock> Time;
	//const auto P = std::chrono::system_clock::now();
	//std::time_t epoch_time = std::chrono::system_clock::to_time_t(P);
/**/
	//AverageTimer = //std::chrono::duration_cast <std::chrono::nanoseconds> (std::chrono::high_resolution_clock::now() - PerformanceTimer).count();
	//Print("Timer: " << Name);
	//Print
	//(
	//	"Average: "
	//	<<
	//	std::chrono::duration_cast <std::chrono::nanoseconds> (std::chrono::high_resolution_clock::now() - PerformanceTimer).count() / 1000000 << " m/s  "
	//);

//TotalTime = std::chrono::duration_cast  <std::chrono::milliseconds>  (std::chrono::high_resolution_clock::now() - StartTime).count();
//Print("Total Time was " << TotalTime << " for " << TotalSamplesTaken << " samples.");
//Print("Average Results for " << Name << " : " << (float)TotalTime / (float)TotalSamplesTaken << " m\s");
	//  Print("LastFrame: "
	//  	<<
	//  	std::chrono::duration_cast  <std::chrono::milliseconds>  (std::chrono::high_resolution_clock::now() - PerformanceTimer).count()
	//  	<< "n/s    "
	//  	<< "AvgSpeed: "
	//  	<< float((AverageResult)) << " m/s  "
	//  );
	//  
