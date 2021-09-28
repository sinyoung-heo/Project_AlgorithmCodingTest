#include <iostream>
#include <vector>

using namespace std;

/*
	47. 봉우리

	지도 정보가 N*N 격자판에 주어집니다. 각 격자에는 그 지역의 높이가 쓰여있습니다. 
	각 격자판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다. 
	봉우리 지역이 몇 개 있는 지 알아내는 프로그램을 작성하세요.
	격자의 가장자리는 0으로 초기화 되었다고 가정한다.
	만약 N=5 이고, 격자판의 숫자가 다음과 같다면 봉우리의 개수는 10개입니다.
	0 0 0 0 0 0 0
	0 5 3 7 2 3 0	-> 3
	0 3 7 1 6 1 0	-> 2
	0 7 2 5 3 4 0	-> 2
	0 4 3 6 4 1 0	-> 1
	0 8 7 3 5 2 0	-> 2
	0 0 0 0 0 0 0

	▣ 입력설명
	첫 줄에 자연수 N이 주어진다.(1<=N<=50)
	두 번째 줄부터 N줄에 걸쳐 각 줄에 N개의 자연수가 주어진다. 
	각 자연수는 100을 넘지 않는다.

	▣ 출력설명
	봉우리의 개수를 출력하세요.

	▣ 입력예제 1
	5
	5 3 7 2 3
	3 7 1 6 1
	7 2 5 3 4
	4 3 6 4 1
	8 7 3 5 2

	▣ 출력예제 1
	10
*/

int answer = 0;
int n = 0;
vector<vector<bool>> vecCheckComplete;
vector<vector<int>> vecHeight;

// 상, 하, 좌, 우.
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool isContinue = false;

int main()
{
	cin >> n;

	int input = 0;

	for (int y = 0; y < n; ++y)
	{
		vecHeight.emplace_back();
		vecCheckComplete.emplace_back();

		for (int x = 0; x < n; ++x)
		{
			cin >> input;
			vecHeight[y].emplace_back(input);
			vecCheckComplete[y].emplace_back(false);
		}
	}

	for (int y = 0; y < vecHeight.size(); ++y)
	{
		for (int x = 0; x < vecHeight[y].size(); ++x)
		{
			isContinue = false;

			if (vecCheckComplete[y][x])
				continue;

			int curHeight = vecHeight[y][x];

			// 상, 하, 좌, 우
			for (int k = 0; k < 4; ++k)
			{
				int idxY = y + dy[k];
				int idxX = x + dx[k];

				if (idxY < 0 || idxY > vecHeight.size() - 1) continue;
				if (idxX < 0 || idxX > vecHeight[y].size() - 1) continue;

				if (curHeight <= vecHeight[idxY][idxX])
				{
					isContinue = true;
					break;
				}
			}

			if (isContinue)
				continue;
			
			// 현재 위치가 봉우리이면? 상하좌우는 비교할 필요 X.
			++answer;
			vecCheckComplete[y][x] = true;

			if (y - 1 > -1)
				vecCheckComplete[y - 1][x] = true;	// 상
			if (y + 1 < vecHeight.size())
				vecCheckComplete[y + 1][x] = true;	// 하
			if (x - 1 > -1)
				vecCheckComplete[y][x - 1] = true;	// 좌
			if (x + 1 < vecHeight[y].size())
				vecCheckComplete[y][x + 1] = true;	// 우
		}
	}

	cout << answer << endl;
}