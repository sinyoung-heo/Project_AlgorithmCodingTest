#include <iostream>

using namespace std;

// 자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.

int main()
{
	int a = 0, b = 0, sum = 0;

	cin >> a >> b;

	for (int i = a; i <= b; ++i)
	{
		sum += i;

		cout << i;

		if (i != b)
			cout << " " << "+ ";
		else
			cout << " = " << sum;
	}
}