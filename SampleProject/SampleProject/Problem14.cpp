#include <iostream>
#include <vector>

using namespace std;

/*
	14. ������ �Ҽ�

	 N���� �ڿ����� �ԷµǸ� �� �ڿ����� ������ �� �� ������ ���� �Ҽ��̸� �� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. 
	���� ��� 32�� �������� 23�̰�, 23�� �Ҽ��̴�. �׷��� 23�� ����Ѵ�. 
	�� 910�� �������� 19�� ����ȭ �ؾ� �Ѵ�. ù �ڸ������� ���ӵ� 0�� �����Ѵ�.
	������ �Լ��� int reverse(int x) �� �Ҽ������� Ȯ���ϴ� �Լ� bool isPrime(int x)�� �ݵ�� �ۼ��Ͽ� ���α׷��� �Ѵ�.

	�� �Է¼���
	 ù �ٿ� �ڿ����� ���� N(3<=N<=100)�� �־�����, �� ���� �ٿ� N���� �ڿ����� �־�����.
	�� �ڿ����� ũ��� 100,000�� ���� �ʴ´�.

	�� ��¼���
	 ù �ٿ� ������ �Ҽ��� ����մϴ�. ��¼����� �Էµ� ������� ����մϴ�.
*/

int reverse(int x)
{
	vector<int> vecNumber;

	while (true)
	{
		vecNumber.emplace_back(x % 10);
		x /= 10;

		if (x == 0)
			break;
	}

	int sum = 0;
	int j = 0;
	for (int i = vecNumber.size() - 1; i >= 0; --i, ++j)
		sum += vecNumber[i] * pow(10, j);

	return sum;
}

bool isPrime(int x)
{
	int cnt = 0;

	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
			++cnt;

		if (cnt > 2)
			return false;
	}

	if (cnt == 1)
		return false;

	return true;
}

int main()
{
	int input = 0;
	cin >> input;

	vector<int> vecNumber;
	vecNumber.resize(input);

	for (int i = 0; i < input; ++i)
		cin >> vecNumber[i];
	
	for (auto& number : vecNumber)
	{
		int revValue = reverse(number);

		if (isPrime(revValue))
			cout << revValue << " ";
	}



	return 0;
}