#include <iostream>
#include <vector>

using namespace std;

/*
	51. 영지(territory) 선택 : (large) [ 동적 프로그래밍 ]
	▣ 입력설명
	첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (1<=H,W<=700) 
	그 다음 H줄에 걸쳐 각 사각형 지역에 오렌지의 나무 개수(1~9개) 정보가 주어진다.
	그 다음 영지의 크기인 세로길이(1~H)와 가로길이(1~W)가 차례로 입력된다.

	▣ 출력설명
	첫 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력한다.

	▣ 입력예제 1
	6 7
	3 5 1 3 1 3 2
	1 2 1 3 1 1 2
	1 3 1 5 1 3 4
	5 1 1 3 1 3 2
	3 1 1 3 1 1 2
	1 3 1 3 1 2 2
	2 3
	▣ 출력예제 1
	16
*/

int answer = INT_MIN;
vector<vector<int>> v;
vector<vector<int>> dynamicTable;

int main()
{
	int h = 0, w = 0;
	cin >> h >> w;

	v.resize(h);
	dynamicTable.resize(h);
	int temp = 0;

	for (auto& vec : v)
	{
		for (int i = 0; i < w; ++i)
		{
			cin >> temp;
			vec.emplace_back(temp);
		}
	}

	int cy = 0, cx = 0;
	cin >> cy >> cx;



	int result = 0;
	for (int y = 0; y < v.size(); ++y)
	{
		if (y == 0)
		{
			for (int x = 0; x < v[y].size(); ++x)
			{
				if (dynamicTable[y].empty())
					dynamicTable[y].emplace_back(v[y][x]);
				else
					dynamicTable[y].emplace_back(v[y][x] + dynamicTable[y].back());
			}
		}
		else
		{
			for (int x = 0; x < v[y].size(); ++x)
			{
				if (x == 0)
					dynamicTable[y].emplace_back(v[y][x] + v[y - 1][x]);
				else
					dynamicTable[y].emplace_back(v[y][x] + dynamicTable[y][x - 1] + dynamicTable[y - 1][x] - dynamicTable[y - 1][x - 1]);

				if ((x > cx - 1 && y > cy - 1) && x - cx >= 0 && y - cy >= 0)
				{
					result = dynamicTable[y][x] - dynamicTable[y - cy][x] - dynamicTable[y][x - cx] + dynamicTable[y - cy][x - cx];

					if (result > answer)
						answer = result;
				}
			}
		}
	}

	cout << answer << endl;
}