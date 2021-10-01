#include <iostream>
#include <vector>

using namespace std;

/*
	65. �̷�Ž��(DFS)
	7*7 ������ �̷θ� Ż���ϴ� ����� �������� ����ϴ� ���α׷��� �ۼ��ϼ���. 
	������� ������ (1, 1) ��ǥ�̰�, Ż�� �������� (7, 7)��ǥ�̴�. 
	�������� 1�� ���̰�, 0�� ����̴�. 
	�������� �������� �����¿�θ� �����δ�. 
	�̷ΰ� ������ ���ٸ�
	���	  0 0 0 0 0 0
		0 1 1 1 1 1 0
		0 0 0 1 0 0 0
		1 1 0 1 0 1 1
		1 1 0 0 0 0 1
		1 1 0 1 1 0 0
		1 0 0 0 0 0  ����
	���� �������� ��������� ���������� �� �� �ִ� ����� ���� 8�����̴�.
	�� �Է¼���
	ù ��° �ٺ��� 7*7 ������ ������ �־����ϴ�.
	�� ��¼���
	ù ��° �ٿ� ����� �������� ����Ѵ�.

	�� �Է¿��� 1
	0 0 0 0 0 0 0
	0 1 1 1 1 1 0
	0 0 0 1 0 0 0
	1 1 0 1 0 1 1
	1 1 0 0 0 0 1
	1 1 0 1 1 0 0
	1 0 0 0 0 0 0
	�� ��¿��� 1
	8
*/

int answer;

const int SIZE = 7;

vector<vector<int>> path;
vector<vector<bool>> visit;

// ��, ��, ��, ��
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

void searchExit(int x, int y)
{
	if (y == SIZE - 1 && x == SIZE - 1)
	{
		++answer;
		return;
	}

	// ��, ��, ��, �� Ž��
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