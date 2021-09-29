#include <iostream>
#include <vector>

using namespace std;

/*
	51. ����(territory) ���� : (large) [ ���� ���α׷��� ]
	�� �Է¼���
	ù �ٿ� H(���α���)�� W(���α���)�� �Էµȴ�. (1<=H,W<=700) 
	�� ���� H�ٿ� ���� �� �簢�� ������ �������� ���� ����(1~9��) ������ �־�����.
	�� ���� ������ ũ���� ���α���(1~H)�� ���α���(1~W)�� ���ʷ� �Էµȴ�.

	�� ��¼���
	ù �ٿ� ������ ���� �� �ִ� ������ ������ �ִ� ������ ����Ѵ�.

	�� �Է¿��� 1
	6 7
	3 5 1 3 1 3 2
	1 2 1 3 1 1 2
	1 3 1 5 1 3 4
	5 1 1 3 1 3 2
	3 1 1 3 1 1 2
	1 3 1 3 1 2 2
	2 3
	�� ��¿��� 1
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