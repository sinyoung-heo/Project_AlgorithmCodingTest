#include <iostream>

using namespace std;

// �ڿ��� A, B�� �־����� A���� B������ ���� ���İ� �Բ� ����ϼ���.

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