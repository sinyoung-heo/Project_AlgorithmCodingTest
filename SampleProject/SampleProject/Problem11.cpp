#include <iostream>

using namespace std;

/*
	11. ������ �� ����(small)

	 �ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���ڴ� �� �� ���������?
	���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5����
	�� 21���� �������� �� �� �ֽ��ϴ�.
	�ڿ��� N�� �ԷµǸ� 1���� N���� �� ���ڴ� �� ���� ���Ǿ������� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù ��° �ٿ��� �ڿ��� N(3<=N<100,000)�� �־�����.

	�� ��¼���
	 ù ��° �ٿ� ������ �Ѱ����� ����Ѵ�.
*/

int countDigit(int input)
{
	int cnt = 0;

	while (true)
	{
		input /= 10;
		++cnt;

		if (input == 0)
			break;
	}

	return cnt;
}

int main()
{
	int input = 0;
	cin >> input;

	int cnt = 0;
	for (int i = 1; i <= input; ++i)
	{
		cnt += countDigit(i);
	}

	cout << cnt;

	return 0;
}