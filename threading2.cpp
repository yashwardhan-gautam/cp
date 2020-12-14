// If we create mutliple threads first, it doesn't gurantee which one will start first


#include<bits/stdc++.h>
using namespace std;

// 1.Function Pointer
/*void fun(int x)
{
	while (x--)
	{
		cout << x << endl;
	}
}
int main()
{
	thread t1(fun, 11);
	t1.detach();
	return 0;
}
*/

//2. Lambda function
/*int main()
{
	auto fun = [](int x)
	{
		while (x--)
		{
			cout << x << endl;
		}
	};
	thread t(fun, 10);
	t.join();
	return 0;
}*/

//3. Functor
/*class Base
{
public:
	void operator() (int x)
	{
		while (x--)
		{
			cout << x << endl;
		}
	}
};
int main()
{
	thread t((Base()), 10);
	t.join();
	return 0;
}*/

// 4. Non-static member function
/*class Base
{
public:
	void run(int x)
	{
		while (x--)
		{
			cout << x << "\n";
		}
	}
};
int main()
{
	Base b;
	thread t(&Base::run, &b, 10);
	t.join();
	return 0;
}*/

// 5. Static member functions
class Base
{
public:
	static void run(int x)
	{
		while (x--)
		{
			cout << x << endl;
		}
	}
};
int main()
{
	thread t(&Base::run, 10);
	t.join();
	return 0;
}