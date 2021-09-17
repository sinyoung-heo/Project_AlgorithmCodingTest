#include <iostream>
#include <vector>

using namespace std;

/*
	59. �κ�����(DFS)

	 �ڿ��� N�� �־����� 1���� N������ ���Ҹ� ���� ������ �κ������� ��� ����ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� �־����ϴ�.

	�� ��¼���
	 ù ��° �ٺ��� ������ �κ������� ����մϴ�. �κ������� ����ϴ� ������ ��¿������� ����� ������ ���� �մϴ�. 
	�� �������� ������� �ʽ��ϴ�.
*/

int input = 0;
vector<bool> vecVisit;

void DFS(int n)
{
	if (n == input + 1)
	{
		for (int i = 0; i < vecVisit.size(); ++i)
		{
			if (vecVisit[i])
				cout << i + 1 << " ";
		}
		cout << endl;

		return;
	}

	vecVisit[n - 1] = true;
	DFS(n + 1);

	vecVisit[n - 1] = false;
	DFS(n + 1);
}

int main()
{
	cin >> input;
	vecVisit.resize(input);

	DFS(1);

	return 0;
}