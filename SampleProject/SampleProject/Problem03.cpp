#include <iostream>

using namespace std;

// �ڿ��� N�� �־����� �ڿ��� N�� ������� ���� ���İ� �Բ� ���.

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