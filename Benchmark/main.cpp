#include"Benchmark.h"
#include"Window.h"

#include<array>
#include<vector>
#include<list>

const int Samples = 1000;

using namespace std;
int main()
{
	Window Win(640, 480, "Benchmark Tests");
 	Benchmark 
		Timer,
	    Timer2;

	list<int> A(Samples);
	vector<int> B(Samples);


	Timer.Start();

	for (int i{ 0 }; i < Samples; i++)
	{
	//	A[i] = i;
	}

 
	Timer.End();

	Timer2.Start();
	for (int i{ 0 }; i < Samples; i++)
	{
		B[i] = Samples;
	}
	//Print(A);
	Timer2.End();

	bool Running = true;
	while (Running) 
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
			{
				Running = false;
			}
		}
		DrawGraph(&Win);
		Win.Sync();
		Win.CLS();
	}
}



