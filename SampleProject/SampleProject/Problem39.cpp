#include <iostream>
#include <vector>

using namespace std;

/*
	39. 두 배열 합치기

	오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램 을 작성하세요.

	▣ 입력설명
	첫 번째 줄에 첫 번째 배열의 크기 N(1<=N<=100)이 주어집니다.
	두 번째 줄에 N개의 배열 원소가 오름차순으로 주어집니다.
	세 번째 줄에 두 번째 배열의 크기 M(1<=M<=100)이 주어집니다.
	네 번째 줄에 M개의 배열 원소가 오름차순으로 주어집니다.
	각 배열의 원소는 int형 변수의 크기를 넘지 않습니다.

	▣ 출력설명
	오름차순으로 정렬된 배열을 출력합니다.
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

	// left가 먼저 끝난 경우.
	if (iter_begin_left == vecLeft.end() && iter_begin_right != vecRight.end())
	{
		for (; iter_begin_right != vecRight.end(); ++iter_begin_right)
			vecSort.emplace_back(*iter_begin_right);
	}
	// right가 먼저 끝난 경우.
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