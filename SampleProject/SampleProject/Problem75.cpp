#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
	75. 최대 수입 스케쥴(priority_queue 응용문제)

	현수는 유명한 강연자이다. N개의 기업에서 강연 요청을 해왔다. 
	각 기업은 D일 안에 와서 강연을 해 주면 M만큼의 강연료를 주기로 했다.
	각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
	단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.

	▣ 입력설명
	첫 번째 줄에 자연수 N(1<=N<=10,000)이 주어지고, 다음 N개의 줄에 M(1<=M<=10,000)과 D(1<=D<=10,000)가 차례로 주어진다.

	▣ 출력설명
	첫 번째 줄에 최대로 벌 수 있는 수입을 출력한다.

	▣ 입력예제 1
	6
	50 2
	20 1
	40 2
	60 3
	30 3
	30 1

	▣ 출력예제 1
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