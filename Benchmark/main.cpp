#include"Benchmark.h"
#include"Window.h"

#include<array>
#include<vector>
#include<list>

const int Samples = 1000;



#include<map>
#include<unordered_map>

using namespace std;
#define CAT(str, in)     str##in 

//http://index-of.co.uk/Game-Development/Programming/
int main()
{
	Window Win(1400, 800, "Benchmark Tests");
 
 	std::map<std::string, int> A;
	std::unordered_map<std::string, int> B;
//	std::string C = std::string(CAT(Tag, 10));
	for (int i{ 0 }; i < Samples; ++i)
	{
		std::string Num = std::to_string(i);
		A.insert({ std::string("Tag") + Num , i });
		B.insert({ std::string("Tag") + Num , i });
	}


	BENCH_MARK(BENCHA, Samples)

		for (unsigned int H{ 0 }; H < i; ++H)
		{
			std::string Num = std::to_string(H);
			B[std::string("Tag") + Num] = i;
		}
	END_BENCHMARK(BENCHA);

	BENCH_MARK(BENCHB, Samples)

		for (unsigned int H{ 0 }; H < i; ++H)
		{
			std::string Num = std::to_string(H);
			A[std::string("Tag") + Num] = i;
		}
	END_BENCHMARK(BENCHB);

 

	DISPLAY_BENCHMARKS
 	   DISPLAY(BENCHA);
	   DISPLAY(BENCHB);
 	DISPLAY_END
}

//for (int a =1; a < 10000; ++a)
//{
// 	B[i] = B[i] / a;
//}


