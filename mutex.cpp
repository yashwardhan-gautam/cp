// MUTEX- mutual exclusion
// Race condition is a situation where two or more threads happened to change the data at the same time
// If there is a race condition then we have to protect it and the protected section is called critical region.

// mutex is used to avoid race conditon
// we use lock()  and unlock() mutex to avoid race condition

#include<bits/stdc++.h>
using namespace std;
int amount = 0;
mutex m;
void addmoney()
{
	m.lock();
	amount++;
	m.unlock();
}
int main()
{
	thread t1(addmoney);
	thread t2(addmoney);
	t1.join();
	t2.join();
	cout << amount << endl;
}