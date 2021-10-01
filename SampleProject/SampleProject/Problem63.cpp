#include <iostream>
#include <vector>

using namespace std;

/*
	63. �������(����ġ ����׷���)
	�Ʒ� �׸��� ���� �׷��� ������ ������ķ� ǥ���غ�����.

	�� �Է¼���
	ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ��
	�������� �Ÿ������ �־�����.

	�� ��¼���
	��������� ����ϼ���.
	�� �Է¿��� 1
	6 9
	1 2 7
	1 3 4
	2 1 2
	2 3 5
	2 5 5
	3 4 5
	4 2 2
	4 5 5
	6 4 5
	�� ��¿��� 1
	0 7 4 0 0 0
	2 0 5 0 5 0
	0 0 0 5 0 0
	0 2 0 0 5 0
	0 0 0 0 0 0
	0 0 0 5 0 0
*/

int N, M;
vector<vector<int>> v;

int main()
{
	cin >> N >> M;

	v.resize(N);
	for (auto& vec : v)
		vec.resize(N);

	int x = 0, y = 0, value = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> y >> x >> value;
		v[y - 1][x - 1] = value;
	}

	for (auto& vec : v)
	{
		for (auto& num : vec)
			cout << num << " ";

		cout << endl;
	}
}