#include <iostream>

using namespace std;

/*
	15. �Ҽ��� ����(*)
	 �ڿ��� N�� �ԷµǸ� 1���� N������ �Ҽ��� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
	���� 20�� �ԷµǸ� 1���� 20������ �Ҽ��� 2, 3, 5, 7, 11, 13, 17, 19�� �� 8���Դϴ�.
	���ѽð��� 1���Դϴ�.

	�� �Է¼���
	 ù �ٿ� �ڿ����� ���� N(2<=N<=200,000)�� �־����ϴ�.

	�� ��¼���
	 ù �ٿ� �Ҽ��� ������ ����մϴ�.
*/

bool isPrime(const int& x)
{
	int flag = 1;

	// �������� Ȱ���Ͽ� �ݺ� ���� ������.
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
			flag = 0;

		if (!flag)
			return false;
	}

	return true;
}

int main()
{
	int input = 0;
	cin >> input;

	int cnt = 0;
	for (int i = 2; i <= input; ++i)
	{
		if (isPrime(i))
			++cnt;
	}
	
	cout << cnt;

	return 0;
}