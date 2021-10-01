#include <iostream>
#include <vector>

using namespace std;

/*
	63. 인접행렬(가중치 방향그래프)
	아래 그림과 같은 그래프 정보를 인접행렬로 표현해보세요.

	▣ 입력설명
	첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
	결정보와 거리비용이 주어진다.

	▣ 출력설명
	인접행렬을 출력하세요.
	▣ 입력예제 1
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
	▣ 출력예제 1
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