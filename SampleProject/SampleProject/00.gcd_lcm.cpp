#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

// �ִ�����
int gcd(int a, int b)
{
	// ��, a > b
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

// �ּҰ����
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{

	return 0;
}