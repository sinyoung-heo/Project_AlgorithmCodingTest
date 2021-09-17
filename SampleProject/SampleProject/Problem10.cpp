#include <iostream>
#include <vector>

using namespace std;

/*
	10. �ڸ����� ��
	 N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ��� �ϴ� ���α׷��� �ۼ��ϼ���. 
	�� �ڿ����� �ڸ����� ���� ���ϴ� �Լ��� int digit_sum(int x)�� �� �ۼ��ؼ� ���α׷��� �ϼ���.

	�� �Է¼���
	 ù �ٿ� �ڿ����� ���� N(3<=N<=100)�� �־�����, �� ���� �ٿ� N���� �ڿ����� �־�����.
	�� �ڿ����� ũ��� 10,000,000�� ���� �ʴ´�.

	�� ��¼���
	 �ڸ����� ���� �ִ��� �ڿ����� ����Ѵ�. �ڸ����� ���� �ִ��� �ڿ����� �������� ��� ��
	�� ���� ���� ū ���� ����մϴ�.
*/

int digit_sum(int x)
{
	int sum = 0;

	while (true)
	{
		sum += x % 10;
		x /= 10;

		if (x == 0)
		{
			sum += x % 10;
			break;
		}
	}

	return sum;
}

int main()
{
	int num = 0;
	cin >> num;

	vector<int> vecInput;
	vecInput.resize(num);

	for (int i = 0; i < num; ++i)
		cin >> vecInput[i];

	int result = 0;
	int sum = 0;
	for (int i = 0; i < vecInput.size(); ++i)
	{
		if (sum <= digit_sum(vecInput[i]))
		{
			if (sum == digit_sum(vecInput[i]))
			{
				if (result < vecInput[i])
				{
					sum = digit_sum(vecInput[i]);
					result = vecInput[i];
					continue;
				}
				else
				{
					sum = digit_sum(vecInput[i]);
					continue;
				}
			}

			sum = digit_sum(vecInput[i]);
			result = vecInput[i];
		}
	}

	cout << result << endl;

	return 0;
}