#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/*
	80. ���ͽ�Ʈ�� �˰���

	�Ʒ��� ����ġ ����׷������� 1�� �������� ��� ���������� �ּ� �Ÿ������ ����ϴ� ���α׷��� �ۼ��ϼ���. 
	(��ΰ� ������ Impossible�� ����Ѵ�)

	�� �Է¼���
	ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ���������� �Ÿ������ �־�����.

	�� ��¼���
	1�� �������� �� �������� ���� �ּ� ����� 2�� �������� ���ʴ�� ����ϼ���.

	�� �Է¿��� 1
	6 9
	1 2 12
	1 3 4
	2 1 2
	2 3 5
	2 5 5
	3 4 5
	4 2 2
	4 5 5
	6 4 5

	�� ��¿��� 1
	2 : 11
	3 : 4
	4 : 9
	5 : 14
	6 : impossible
*/

int N, M;
vector<int> vecDist;

vector<vector<pair<int, int>>> path;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> N >> M;
	path.resize(N + 1);

	for (int i = 0; i < N + 1; ++i)
		vecDist.emplace_back(INT_MAX);

	for (int i = 0; i < M; ++i)
	{
		int y = 0, x = 0, value = 0;
		cin >> y >> x >> value;

		path[y].emplace_back(value, x);
	}

	// first : cost, second : edge.
	// ���(cost) ���� �ּ��� ����.
	pq.emplace(0, 1);
	vecDist[1] = 0;	// 1 --> 1 ����� 0
	
	while (!pq.empty())
	{
		int now = pq.top().second;
		int dist = pq.top().first;

		pq.pop();

		// ���� ���������� ���� �Ÿ��� �� ũ�� ���� X. (�ּڰ��� ã�ƾ� �ϹǷ�)
		if (dist > vecDist[now]) continue;

		for (auto& pair : path[now])
		{
			int next = pair.second;				// ���� ������ ����Ǿ��ִ� ����
			int next_sum = dist + pair.first;	// ���� �������� ����� �������� ���� �Ÿ�.

			if (vecDist[next] > next_sum)		// �������� �� ���� ���̸� ����.
			{
				vecDist[next] = next_sum;
				pq.emplace(next_sum, next);
			}
		}
	}

	for (int i = 1 ; i < vecDist.size(); ++i)
	{
		if (vecDist[i] == 0) continue;
		if (vecDist[i] != INT_MAX)
			cout << i << " : " << vecDist[i] << endl;
		else
			cout << i << " : impossible" << endl;
	}
}