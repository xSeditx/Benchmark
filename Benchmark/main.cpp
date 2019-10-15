#include"Benchmark.h"
#include"Window.h"

#include<array>
#include<vector>
#include<list>

const int Samples = 1000000;






using namespace std;
int main()
{
	Window Win(1400, 800, "Benchmark Tests");
 
	vector<int> A(Samples);
	vector<int> B(Samples);

	BENCH_MARK(BENCHA, Samples)
		A.push_back(i);
	END_BENCHMARK(BENCHA);

	BENCH_MARK(BENCHB, Samples)
		B.emplace_back(i);
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


