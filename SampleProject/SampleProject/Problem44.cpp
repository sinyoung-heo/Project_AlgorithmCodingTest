#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	44. ������ ���ϱ�(�̺а˻� ����)

	 N���� �������� 1���� �������� �ֽ��ϴ�. �� �������� x1, x2, x3, ......, xN�� ��ǥ�� ������, ������ ���� ��ǥ�� �ߺ��Ǵ� ���� �����ϴ�.
	������ C������ ���� ������ �ִµ�, �� ������ ���� ������ �ִ� ���� �������� �ʽ��ϴ�.
	�� ���������� �� ������ ���� ���� �� �ְ�, ���� ����� �� ���� �Ÿ��� �ִ밡 �ǰ� ���� �������� ��ġ�ϰ� �ͽ��ϴ�.
	C������ ���� N���� �������� ��ġ���� �� ���� ����� �� ���� �Ÿ��� �ִ밡 �Ǵ� �� �ִ� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù �ٿ� �ڿ��� N(3 <= N <= 200,000)�� C(2 <= C <= N)�� ������ ���̿� �ΰ� �־����ϴ�.
	��° �ٺ��� N���� �ٿ� ���� �������� ��ǥ xi(0 <= xi <= 1,000,000,000)�� �� �ٿ� �ϳ��� �־����ϴ�.

	�� ��¼���
	 ù �ٿ� ���� ����� �� ���� �ִ� �Ÿ��� ����ϼ���.

	5 3
	1
	2
	8
	4
	9
	--------------
	3
*/

int answer = INT_MIN;
int n, c;

bool checkHorse(vector<int>& v, const int& value)
{
	int horseCnt = 1;
	int pos = v.front();

	for (int i = 1; i < v.size(); ++i)
	{
		int result = v[i] - pos;
		if (result >= value)
		{
			++horseCnt;
			pos = v[i];
		}
	}

	if (horseCnt >= c)
	{
		answer = value;
		return true;
	}

	return false;
}

int main()
{
	cin >> n >> c;

	vector<int> vecInput;
	vecInput.resize(n);

	for (auto& v : vecInput)
		cin >> v;

	sort(vecInput.begin(), vecInput.end());

	int left = 1;
	int right = vecInput.back();
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		// move right
		if (checkHorse(vecInput, mid))
		{
			left = mid + 1;
		}

		// move left
		else
		{
			right = mid - 1;
		}
	}

	cout << answer << endl;
}