#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
	57. ����Լ� ������ ���
	 10���� N�� �ԷµǸ� 2������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. �� ����Լ��� �̿��ؼ� ����ؾ� �մϴ�.

	�� �Է¼���
	 ù ��° �ٿ� 10���� N(1<=N<=1,000)�� �־����ϴ�.

	�� ��¼���
	 ù ��° �ٿ� �������� ����ϼ���.
*/

void makeBinary(int n)
{
	if (n <= 0)
		return;

	makeBinary(n / 2);
	cout << n % 2;
}

int main()
{
	int input = 0;
	cin >> input;

	makeBinary(input);

	return 0;
}