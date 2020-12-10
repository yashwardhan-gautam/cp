// every application has a default thread called in main(), in side this we create other threads.
// A thread is also known as lightweight process, Idea is to achieve parallelism by dividing the process into multiple threads
// a) the browser has mutliple tabs that can be different treads
// b) MS word must be using multiple threads, one thread to format the text, another to process the input
// c) Visual studio code editor would be using threading for auto code completion
// Ways to create a thread in c++11(or later)
// 1. Function pointers
// 2. Lambda functions
// 3. Functors
// 4. Member functions
// 5. Static member functions

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int unsigned long long int
int odd_sum = 0;
int even_sum = 0;
void findodd(int start, int end)
{
	for (int i = start; i <= end; i++)
		if (i & 1)
			odd_sum += i;
}
void findeven(int start, int end)
{
	for (int i = start; i <= end; i++)
		if (!(i & 1))
			even_sum += i;
}
int32_t main()
{
	int start = 0, end = 190000000;
	auto  start_time = high_resolution_clock::now();
	std::thread t1(findeven, start, end);  // parallelization using function pointer
	std::thread t2(findodd, start, end);
	t1.join();
	t2.join();
	//findodd(start, end);
	//findeven(start, end);
	auto end_time = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end_time - start_time);
	cout << odd_sum << " " << even_sum << endl;
	cout << duration.count() << endl;
}
// command to run: g++ -std=c++11 -pthread threading1.cpp