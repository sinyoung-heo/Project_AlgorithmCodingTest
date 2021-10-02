#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
	75. �ִ� ���� ������(priority_queue ���빮��)

	������ ������ �������̴�. N���� ������� ���� ��û�� �ؿԴ�. 
	�� ����� D�� �ȿ� �ͼ� ������ �� �ָ� M��ŭ�� �����Ḧ �ֱ�� �ߴ�.
	�� ����� ��û�� D�� M�� �������� ���� ���� ���� �� �� �ֵ��� ���� �������� ¥�� �Ѵ�.
	�� ������ Ư���� ������ �Ϸ翡 �ϳ��� ��������� ������ �� �� �ִ�.

	�� �Է¼���
	ù ��° �ٿ� �ڿ��� N(1<=N<=10,000)�� �־�����, ���� N���� �ٿ� M(1<=M<=10,000)�� D(1<=D<=10,000)�� ���ʷ� �־�����.

	�� ��¼���
	ù ��° �ٿ� �ִ�� �� �� �ִ� ������ ����Ѵ�.

	�� �Է¿��� 1
	6
	50 2
	20 1
	40 2
	60 3
	30 3
	30 1

	�� ��¿��� 1
	150
*/

int N, M, D;
priority_queue<pair<int, int>> pq;

vector<int> answer;

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> M >> D;
		pq.push(make_pair(D, M));

	}
	pq.top();

	int curDay = pq.top().first;
	int preDay = pq.top().first;

	priority_queue<int> tempPQ;

	int sum = 0;

	while (curDay != 0)
	{
		while (true)
		{
			if (pq.empty())
				break;

			if (curDay == pq.top().first)
			{
				tempPQ.push(pq.top().second);
				pq.pop();
			}
			else
				break;
		}

		if (!tempPQ.empty())
		{
			sum += tempPQ.top();
			tempPQ.pop();
		}

		--curDay;
	}

	cout << sum << endl;

	return 0;
}