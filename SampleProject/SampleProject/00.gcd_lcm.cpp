#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

// 최대공약수
int gcd(int a, int b)
{
	// 단, a > b
	while (true)
	{
		int r = a % b;

		if (r != 0)
		{
			a = b;
			b = r;
			gcd(a, b);
		}
		else
			return b;
	}
}

// 최소공배수
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{

	return 0;
}