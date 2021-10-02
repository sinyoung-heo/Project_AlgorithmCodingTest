#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

/*
	71. �۾��� ã��(BFS : ����Ʈ��Ž��)

	������ �۾����� �Ҿ���ȴ�. ������ �۾������� ��ġ�����Ⱑ �޷� �ִ�. 
	������ ��ġ�� �۾����� ��ġ�� �������� ��ǥ ������ �־����� ������ ���� ��ġ���� �۾����� ��ġ���� ������ ���� ������� �̵��Ѵ�.
	������ ��ī�� ������ Ÿ�� ���µ� �� ���� ������ ������ 1, �ڷ� 1, ������ 5�� �̵��� ���ִ�. 
	�ּ� �� ���� ������ ������ �۾����� ��ġ���� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	ù ��° �ٿ� ������ ��ġ S�� �۾����� ��ġ E�� �־�����. ������ ��ǥ ���� 1���� 10,000�����̴�.

	�� ��¼���
	������ �ּ�Ƚ���� ���Ѵ�.

	�� �Է¿��� 1
	5 14

	�� ��¿��� 1
	3
*/

int S, E;
queue<int> q;

int JUMP[3] { 1, -1, 5 };
const int MAX_POS = 10'000;
int cnt[MAX_POS + 1] { };

int main()
{
	cin >> S >> E;

	q.push(S);
	cnt[S] = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < 3; ++i)
		{
			int pos = x + JUMP[i];

			if (pos <= 0 || pos > MAX_POS) continue;

			if (pos == E)
			{
				cout << cnt[x] << endl;
				exit(0);
			}

			if (cnt[pos] == 0)
			{
				cnt[pos] = cnt[x] + 1;
				q.push(pos);
			}
		}
	}
}