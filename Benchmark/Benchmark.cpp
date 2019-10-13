#include<string>
#include"Benchmark.h"

#pragma optimize( "BenchMark::Start()", off )
#pragma optimize( "BenchMark::End()", off )

int Benchmark::ObjectCounter;
long long Benchmark::AverageTimer;
long long Benchmark::AverageResult;



Benchmark::Benchmark()
	:
	Accumulator(0)
{
	PerformanceTimer = std::chrono::high_resolution_clock::now();
	ObjectCounter++;
}
Benchmark::Benchmark(std::string _name)
{
	Name = _name;
	PerformanceTimer = std::chrono::high_resolution_clock::now();
	ObjectCounter++;
	Accumulator = 0;
}

Benchmark::~Benchmark()
{
	AverageTimer += std::chrono::duration_cast  <std::chrono::nanoseconds>  (std::chrono::high_resolution_clock::now() - PerformanceTimer).count();
	if (ObjectCounter > NumberOfSamples)
	{
		Print("LastFrame: "
			<<
			std::chrono::duration_cast  <std::chrono::nanoseconds>  (std::chrono::high_resolution_clock::now() - PerformanceTimer).count()
			<< "n/s    "
			<< "AvgSpeed: "
			<< float((AverageResult) / 1000000.0f) << " m/s  "
		);

		ObjectCounter = 0;
		AverageResult = AverageTimer / NumberOfSamples;
		AverageTimer = 0;
	}
}

void Benchmark::Start()
{
	Accumulator++;
	PerformanceTimer = std::chrono::high_resolution_clock::now();
	NumberOfSamples = 100;
}
void Benchmark::End()
{
	AverageTimer += std::chrono::duration_cast <std::chrono::nanoseconds> (std::chrono::high_resolution_clock::now() - PerformanceTimer).count();
	Print("Timer: " << Name);
	Print
	(
		"LastFrame: "
		<<
		std::chrono::duration_cast <std::chrono::nanoseconds> (std::chrono::high_resolution_clock::now() - PerformanceTimer).count() / 1000000 << "m/s  "
	);

	Accumulator = 0;
	AverageResult = AverageTimer / NumberOfSamples;
	AverageTimer = 0;
}