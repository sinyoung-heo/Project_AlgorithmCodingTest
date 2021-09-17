#include <iostream>
#include <vector>

using namespace std;

/*
	17. ������ ����
	 ������ ���� �л��� N�� �ֽ��ϴ�. 
	�������� �������� ��� �ڸ��� ����� �ϴµ� �� ���� �л����� ����ų� ���� �ʵ��� �� �л��鿡�� ��� �½��ϴ�.
	�������� �� �л��鿡�� ���ڰ� ���� ī�带 ����ϴ�. �� �л����� 1���� �ڱ� ī�忡 ���� ���ڱ����� ���� ���ϴ� �����Դϴ�.
	�������� ���ƿͼ� �� �л����� ���� �¾Ҵ��� Ȯ���� �Ϸ��� �ϴµ� �ʹ� ���� 
	�����п��� �ڵ����� ä���� �ϴ� ���α׷��� ��Ź�߽��ϴ�. �������� �������� �����ּ���.

	�� �Է¼���
	 ù �ٿ� �� �л����� �ڿ��� N(1<=N<=10)�� �־����ϴ�.
	�� �л����� 1���� N���� ��ȣ�� �ο��Ǿ� �ִٰ� �����մϴ�.
	�� ��° �ٺ��� 1�� �л������� ī�忡 ���� ���� �л��� ���� ������ ������ ���̿� �ΰ��Էµȴ�. 
	ī�忡 ���� ���� 1000�� ���� �ʴ´�.

	�� ��¼���
	ù �ٺ��� 1�� �л��� ������ ���߸� ��YES", Ʋ���� ��NO"�� ����ϼ���.
*/

int getSum(int x)
{
	int sum = 0;

	for (int i = 1; i <= x; ++i)
		sum += i;

	return sum;
}

int main()
{

	int input = 0;
	cin >> input;

	vector<int> vecNumber;
	vector<int>	vecSum;
	vecNumber.resize(input);
	vecSum.resize(input);

	for (int i = 0; i < input; ++i)
		cin >> vecNumber[i] >> vecSum[i];

	for (int i = 0; i < input; ++i)
	{
		if (vecSum[i] == getSum((vecNumber[i])))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}