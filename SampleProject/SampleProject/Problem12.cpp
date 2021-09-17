#include <iostream>

using namespace std;

/*
	11. ������ �� ����(large)

	 �ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���ڴ� �� �� ���������?
	���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5����
	�� 21���� �������� �� �� �ֽ��ϴ�.
	�ڿ��� N�� �ԷµǸ� 1���� N���� �� ���ڴ� �� ���� ���Ǿ������� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù ��° �ٿ��� �ڿ��� N(3<=N<100,000,000)�� �־�����.

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
	// 1 ~ 9
	// 10 ~ 99
	// 100 ~ 999
	// 1 * 9
	// 2 * 90
	// 3 * 900

	int input = 0;
	cin >> input;

	int cnt = 0;
	int input_cnt = countDigit(input);

	for (int i = 1; i < input_cnt; ++i)
	{
		cnt += i * (pow(10, i) - pow(10, i - 1));
	}

	cnt += input_cnt * (input - pow(10, input_cnt - 1) + 1);

	cout << cnt;

	return 0;
}