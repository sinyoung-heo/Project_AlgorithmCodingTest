#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
	49. 블록의 최댓값
	현수는 블록놀이를 좋아합니다. 
	현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주고 
	최대 블록개수를 사용하여 정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
	현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.

	위에서 본 높이(최대개수)
	위에서 봤을 때 각 칸의 블록의 개수입니다. 
	정면에서의 높이 정보와 오른쪽 측면에서의 높이 정보가 주어지면 사용할 수 있는 블록의 쵀대 개수를 출력하세요.

	▣ 입력설명
	첫 줄에 블록의 크기 N(3<=N<=10)이 주어집니다. 블록이 크기는 정사각형 N*N입니다.
	두 번째 줄에 N개의 정면에서의 높이 정보가 왼쪽 정보부터 주어집니다.
	세 번째 줄에 N개의 오른쪽 측면 높이 정보가 앞쪽부터 주어집니다.
	블록의 높이는 10 미만입니다.

	▣ 출력설명
	첫 줄에 블록의 최대 개수를 출력합니다.

	▣ 입력예제 1
	4
	2 0 3 1
	1 1 2 3

	▣ 출력예제 1
	17
*/

int answer = 0;

vector<vector<int>> v;
vector<int> vecFront;
vector<int> vecRight;
int n;

int main()
{
	cin >> n;

	v.resize(n);
	for (auto& vec : v)
		vec.resize(n);

	// front
	vecFront.resize(n);
	for (int i = 0; i < vecFront.size(); ++i)
		cin >> vecFront[i];

	// right
	vecRight.resize(n);
	for (int i = 0; i < vecRight.size(); ++i)
		cin >> vecRight[i];
	
	// 우선 정면에서 본 값으로 모두 채운다.
	for (int y = 0; y < v.size(); ++y)
	{
		for (int x = 0; x < v[y].size(); ++x)
		{
			v[y][x] = vecFront[x];
		}
	}

	// 오른쪽에서 본 값을 통해 비교한다. 오른쪽에서 본 값보다 크면, 오른쪽에서 본 값으로 치환한다.
	auto iter_rbegin = vecRight.rbegin();
	for (int y = 0; y < v.size(); ++y, ++iter_rbegin)
	{
		for (int x = 0; x < v[y].size(); ++x)
		{
			if (v[y][x] > *iter_rbegin)
				v[y][x] = *iter_rbegin;

			answer += v[y][x];
		}
	}

	cout << answer << endl;
}