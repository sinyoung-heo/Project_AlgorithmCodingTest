#include <iostream>
#include <vector>

using namespace std;

/*
	65. 미로탐색(DFS)
	7*7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하세요. 
	출발점은 격자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7)좌표이다. 
	격자판의 1은 벽이고, 0은 통로이다. 
	격자판의 움직임은 상하좌우로만 움직인다. 
	미로가 다음과 같다면
	출발	  0 0 0 0 0 0
		0 1 1 1 1 1 0
		0 0 0 1 0 0 0
		1 1 0 1 0 1 1
		1 1 0 0 0 0 1
		1 1 0 1 1 0 0
		1 0 0 0 0 0  도착
	위의 지도에서 출발점에서 도착점까지 갈 수 있는 방법의 수는 8가지이다.
	▣ 입력설명
	첫 번째 줄부터 7*7 격자의 정보가 주어집니다.
	▣ 출력설명
	첫 번째 줄에 경로의 가지수를 출력한다.

	▣ 입력예제 1
	0 0 0 0 0 0 0
	0 1 1 1 1 1 0
	0 0 0 1 0 0 0
	1 1 0 1 0 1 1
	1 1 0 0 0 0 1
	1 1 0 1 1 0 0
	1 0 0 0 0 0 0
	▣ 출력예제 1
	8
*/

int answer;

const int SIZE = 7;

vector<vector<int>> path;
vector<vector<bool>> visit;

// 상, 하, 좌, 우
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

void searchExit(int x, int y)
{
	if (y == SIZE - 1 && x == SIZE - 1)
	{
		++answer;
		return;
	}

	// 상, 하, 좌, 우 탐색
	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if ((nextX >= 0 && nextX < SIZE) && (nextY >= 0 && nextY < SIZE) &&
			path[nextY][nextX] == 0 && !visit[nextY][nextX])
		{
			visit[nextY][nextX] = true;

			searchExit(nextX, nextY);

			visit[nextY][nextX] = false;
		}
	}
}

int main()
{
	visit.resize(SIZE);
	path.resize(SIZE);

	for (auto& v : path)
		v.resize(SIZE);
	for (auto& v : visit)
		v.resize(SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cin >> path[i][j];
		}
	}

	visit[0][0] = true;
	searchExit(0, 0);

	cout << answer << endl;
}