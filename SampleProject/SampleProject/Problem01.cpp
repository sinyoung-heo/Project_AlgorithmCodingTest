#include <iostream>

using namespace std;

//	1부터 N까지의 수 중 M의 배수의 합 출력.

int main()
{
	int num = 0;
	int n = 0, m = 0, sum = 0;

	cin >> n >> m;

	if (m >= 3 && m < n && n <= 1000)
	{
		num += m;

		while (num <= n)
		{
			sum += num;
			num += m;
		}
	}

	cout << sum << endl;

	return 0;
}