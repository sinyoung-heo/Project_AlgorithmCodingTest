#include <iostream>
#include <vector>

using namespace std;

/*
	62. 병합정렬
	N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
	정렬하는 방법은 병합정렬입니다.

	▣ 입력설명
	첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
	두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에
	있습니다.

	▣ 출력설명
	오름차순으로 정렬된 수열을 출력합니다.

	▣ 입력예제 1
	8
	7 6 3 1 5 2 4 8

	▣ 출력예제 1
	1 2 3 4 5 6 7 8
*/

int N;
vector<int> v;

vector<int> MergeSort(int left, int mid, int right)
{
	if (left >= right)
		return vector<int>{ v[left] };

	vector<int> vecLeft		= MergeSort(left, (left + mid) / 2, mid);
	vector<int> vecRight	= MergeSort(mid + 1, (mid + 1 + right) / 2, right);

	// Merge
	vector<int> vecMerge;
	vecMerge.reserve(left + right);
	int leftStart = 0;
	int rightStart = 0;

	while (true)
	{
		if (leftStart >= vecLeft.size()) break;
		if (rightStart >= vecRight.size()) break;

		if (vecLeft[leftStart] < vecRight[rightStart])
		{
			vecMerge.emplace_back(vecLeft[leftStart]);
			++leftStart;
		}
		else
		{
			vecMerge.emplace_back(vecRight[rightStart]);
			++rightStart;
		}
	}

	// left가 끝난 상태이므로, right의 요소를 넣어준다.
	if (leftStart >= vecLeft.size())
	{
		for (int i = rightStart; i < vecRight.size(); ++i)
			vecMerge.emplace_back(vecRight[i]);
	}
	// right가 끝난 상태이므로, left의 요소를 넣어준다.
	else
	{
		for (int i = leftStart; i < vecLeft.size(); ++i)
			vecMerge.emplace_back(vecLeft[i]);
	}

	return vecMerge;
}

int main()
{
	cin >> N;

	v.resize(N);
	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	int left = 0;
	int right = v.size() - 1;
	int mid = (left + right) / 2;

	vector<int> answer = MergeSort(left, mid, right);

	for (auto& num : answer)
		cout << num << " ";

	cout << endl;
}