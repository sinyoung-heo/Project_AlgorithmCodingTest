#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	42. 이분검색
	 임의의 N개의 숫자가 입력으로 주어집니다. N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면 
	 이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는 프로그램을 작성하세요.

	▣ 입력설명
	 첫 줄에 한 줄에 자연수 N(3<=N<=1,000,000)과 M이 주어집니다.
	두 번째 줄에 N개의 수가 공백을 사이에 두고 주어집니다.

	▣ 출력설명
	 첫 줄에 정렬 후 M의 값의 위치 번호를 출력한다.
*/

int BinarySearch(int left, int right, vector<int>& v, const int& findNum)
{
	int mid = (left + right) / 2;

	if (findNum == v[mid])
		return mid;

	else if (findNum < v[mid])
		return BinarySearch(left, mid, v, findNum);
	else if (findNum > v[mid])
		return BinarySearch(mid, right, v, findNum);

	if (left == mid || right == mid)
		return -2;
}

int main()
{
	int size = 0;
	int findNumber = 0;

	cin >> size >> findNumber;

	vector<int> v;
	v.resize(size);
	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	
	cout << BinarySearch(0, v.size() - 1, v, findNumber) + 1 << endl;

	//auto iter_find = find(v.begin(), v.end(), findNumber);
	//int idx = iter_find - v.begin();
	//cout << idx + 1 << endl;

	return 0;
}