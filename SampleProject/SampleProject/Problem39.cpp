#include <iostream>
#include <vector>

using namespace std;

/*
	39. �� �迭 ��ġ��

	������������ ������ �� �� �迭�� �־����� �� �迭�� ������������ ���� ����ϴ� ���α׷� �� �ۼ��ϼ���.

	�� �Է¼���
	ù ��° �ٿ� ù ��° �迭�� ũ�� N(1<=N<=100)�� �־����ϴ�.
	�� ��° �ٿ� N���� �迭 ���Ұ� ������������ �־����ϴ�.
	�� ��° �ٿ� �� ��° �迭�� ũ�� M(1<=M<=100)�� �־����ϴ�.
	�� ��° �ٿ� M���� �迭 ���Ұ� ������������ �־����ϴ�.
	�� �迭�� ���Ҵ� int�� ������ ũ�⸦ ���� �ʽ��ϴ�.

	�� ��¼���
	������������ ���ĵ� �迭�� ����մϴ�.
*/

vector<int> MergeSort(vector<int>& v)
{
	if (v.size() == 1)
		return v;

	vector<int> vecSort;
	vector<int> vecLeft;
	vector<int> vecRight;

	for (int i = 0; i < v.size() / 2; ++i)
		vecLeft.emplace_back(v[i]);

	for (int i = v.size() / 2; i < v.size(); ++i)
		vecRight.emplace_back(v[i]);

	vecLeft = MergeSort(vecLeft);
	vecRight = MergeSort(vecRight);

	auto iter_begin_left = vecLeft.begin();
	auto iter_begin_right = vecRight.begin();

	while (true)
	{
		if (iter_begin_left == vecLeft.end() || iter_begin_right == vecRight.end())
			break;

		if (*iter_begin_left <= *iter_begin_right)
		{
			vecSort.emplace_back(*iter_begin_left);
			++iter_begin_left;
			continue;
		}

		if (*iter_begin_left > *iter_begin_right)
		{
			vecSort.emplace_back(*iter_begin_right);
			++iter_begin_right;
			continue;
		}
	}

	// left�� ���� ���� ���.
	if (iter_begin_left == vecLeft.end() && iter_begin_right != vecRight.end())
	{
		for (; iter_begin_right != vecRight.end(); ++iter_begin_right)
			vecSort.emplace_back(*iter_begin_right);
	}
	// right�� ���� ���� ���.
	else if (iter_begin_right == vecRight.end() && iter_begin_left != vecLeft.end())
	{
		for (; iter_begin_left != vecLeft.end(); ++iter_begin_left)
			vecSort.emplace_back(*iter_begin_left);
	}

	return vecSort;
}

int main()
{
	vector<int> v1;
	
	int size_a = 0;
	int size_b = 0;
	int temp = 0;


	cin >> size_a;
	for (int i = 0; i < size_a; ++i)
	{
		cin >> temp;
		v1.emplace_back(temp);
	}

	cin >> size_b;
	for (int i = 0; i < size_b; ++i)
	{
		cin >> temp;
		v1.emplace_back(temp);
	}

	vector<int> answer = MergeSort(v1);

	for (auto& n : answer)
		cout << n << " ";

	return 0;
}