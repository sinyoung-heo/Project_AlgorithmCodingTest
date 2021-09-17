#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/*
	60. ���� ���� �κ�����(DFS : �Ƹ��� ���ͺ�)

	 N���� ���ҷ� ������ �ڿ��� ������ �־�����, �� ������ �� ���� �κ��������� �������� ��
	�� �κ������� ������ ���� ���� ���� ��찡 �����ϸ� ��YES"�� ����ϰ�, �׷��� ������ ��NO"�� ����ϴ� ���α׷��� �ۼ��ϼ���.
	���� ��� {1, 3, 5, 6, 7, 10}�� �ԷµǸ� {1, 3, 5, 7} = {6, 10} ���� 
	�� �κ������� ���� 16���� ���� ��찡 �����ϴ� ���� �� �� �ִ�.

	�� �Է¼���
	 ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� �־����ϴ�.
	�� ��° �ٿ� ������ ���� N���� �־�����. �� ���Ҵ� �ߺ����� ������ �� ũ��� 1,000,000�����Դϴ�.

	�� ��¼���
	 ù ��° �ٿ� ��YES" �Ǵ� ��NO"�� ����Ѵ�.
*/

int num = 0;
vector<int> vecNumber;
vector<bool> vecVisit;
vector<bool> vecIsSame;
set<int> setSum;

void powerSet(int idx)
{
	if (idx > vecNumber.size() - 1)
	{
		int sum = 0;
		for (int i = 0; i < vecVisit.size(); ++i)
		{
			if (vecVisit[i])
				sum += vecNumber[i];
		}

		auto iter_find = setSum.find(sum);
		if (iter_find == setSum.end() && sum != 0)
			setSum.emplace(sum);
		else
			vecIsSame.emplace_back(true);

		return;
	}

	vecVisit[idx] = true;
	powerSet(idx + 1);

	vecVisit[idx] = false;
	powerSet(idx + 1);
}

int main()
{
	cin >> num;

	vecVisit.resize(num);
	vecNumber.resize(num);
	for (int i = 0; i < num; ++i)
		cin >> num;
	
	powerSet(0);

	if (!vecIsSame.empty())
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}