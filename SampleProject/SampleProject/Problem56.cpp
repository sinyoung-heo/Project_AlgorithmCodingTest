#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

/*
	56. ����Լ� �м�

	 �ڿ��� N�� �־����� �Ʒ��� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. ����Լ��� �̿��ؼ� ����ؾ� �մϴ�.

	�� �Է¼���
	 ù ��° �ٿ� �ڿ��� N(1<=N<=20)�� �־����ϴ�.

	�� ��¼���
	 ù ��° �ٿ� ����Լ��� �̿��ؼ� ����ϼ���.
*/

void fuc(int n)
{
	if (n <= 0)
		return;

	cout << n << " ";
	fuc(--n);
}

int main()
{
	int input = 0;
	cin >> input;

	fuc(input);

	return 0;
}