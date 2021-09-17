#include <iostream>
#include <vector>

using namespace std;

/*
	 ���ڿ� ���ڰ� �����ִ� ���ڿ��� �־����� �� �� ���ڸ� �����Ͽ� �� ������� �ڿ����� ����ϴ�. 
	������� �ڿ����� �� �ڿ����� ��� ������ ����մϴ�.
	���� ��t0e0a1c2her������ ���ڸ� �����ϸ� 0, 0, 1, 2�̰� �̰��� �ڿ����� ����� 12�� �˴ϴ�. 
	�� ù �ڸ� 0�� �ڿ���ȭ �� �� �����մϴ�. ����� 12�� ����ϰ�, ���� �ٿ� 12�� ����� ������ ����ϸ� �˴ϴ�.
	�����Ͽ� ��������� �ڿ����� 100,000,000�� ���� �ʽ��ϴ�.

	�� �Է¼���
	 ù �ٿ� ���ڰ� ���� ���ڿ��� �־����ϴ�. ���ڿ��� ���̴� 50�� ���� �ʽ��ϴ�.

	�� ��¼���
	 ù �ٿ� �ڿ����� ����ϰ�, �� ��° �ٿ� ����� ������ ����մϴ�.
*/

int main()
{
	char input[64];
	cin >> input;

	vector<char> vecNumber;

	for (int i = 0; i < strlen(input); ++i)
	{
		if (!isalpha(input[i]))
			vecNumber.emplace_back(input[i]);
	}

	int sum = 0;
	int j = 0;
	for (int i = vecNumber.size() - 1; i >= 0; --i, ++j)
	{
		int num = vecNumber[i] - 48;
		sum += num * (int)pow(10.0, (double)j);
	}

	int cnt = 0;
	for (int i = 1; i <= sum; ++i)
	{
		if (sum % i == 0)
			++cnt;
	}

	cout << sum << endl;
	cout << cnt << endl;

	return 0;
}