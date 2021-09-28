#include <iostream>
#include <vector>

using namespace std;

/*
	47. ���츮

	���� ������ N*N �����ǿ� �־����ϴ�. �� ���ڿ��� �� ������ ���̰� �����ֽ��ϴ�. 
	�� �������� ���� �� �ڽ��� �����¿� ���ں��� ū ���ڴ� ���츮 �����Դϴ�. 
	���츮 ������ �� �� �ִ� �� �˾Ƴ��� ���α׷��� �ۼ��ϼ���.
	������ �����ڸ��� 0���� �ʱ�ȭ �Ǿ��ٰ� �����Ѵ�.
	���� N=5 �̰�, �������� ���ڰ� ������ ���ٸ� ���츮�� ������ 10���Դϴ�.
	0 0 0 0 0 0 0
	0 5 3 7 2 3 0	-> 3
	0 3 7 1 6 1 0	-> 2
	0 7 2 5 3 4 0	-> 2
	0 4 3 6 4 1 0	-> 1
	0 8 7 3 5 2 0	-> 2
	0 0 0 0 0 0 0

	�� �Է¼���
	ù �ٿ� �ڿ��� N�� �־�����.(1<=N<=50)
	�� ��° �ٺ��� N�ٿ� ���� �� �ٿ� N���� �ڿ����� �־�����. 
	�� �ڿ����� 100�� ���� �ʴ´�.

	�� ��¼���
	���츮�� ������ ����ϼ���.

	�� �Է¿��� 1
	5
	5 3 7 2 3
	3 7 1 6 1
	7 2 5 3 4
	4 3 6 4 1
	8 7 3 5 2

	�� ��¿��� 1
	10
*/

int answer = 0;
int n = 0;
vector<vector<bool>> vecCheckComplete;
vector<vector<int>> vecHeight;

// ��, ��, ��, ��.
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

			// ��, ��, ��, ��
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
			
			// ���� ��ġ�� ���츮�̸�? �����¿�� ���� �ʿ� X.
			++answer;
			vecCheckComplete[y][x] = true;

			if (y - 1 > -1)
				vecCheckComplete[y - 1][x] = true;	// ��
			if (y + 1 < vecHeight.size())
				vecCheckComplete[y + 1][x] = true;	// ��
			if (x - 1 > -1)
				vecCheckComplete[y][x - 1] = true;	// ��
			if (x + 1 < vecHeight[y].size())
				vecCheckComplete[y][x + 1] = true;	// ��
		}
	}

	cout << answer << endl;
}