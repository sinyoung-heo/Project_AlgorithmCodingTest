#include <iostream>

using namespace std;

// 자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력.

int main()
{
	int n, sum = 0;

	cin >> n;

	cout << 1;
	sum += 1;

	for (int i = 2; i <= n; ++i)
	{
		if (n % i == 0)
		{
			if (i != n)
			{
				cout << " + " << i;
				sum += i;
			}
			else
			{
				cout << " = " << sum;
			}
		}
	}

	return 0;
}