#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	42. �̺а˻�
	 ������ N���� ���ڰ� �Է����� �־����ϴ�. N���� ���� ������������ ������ ���� N���� �� �� �� ���� ���� M�� �־����� 
	 �̺а˻����� M�� ���ĵ� ���¿��� �� ��°�� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù �ٿ� �� �ٿ� �ڿ��� N(3<=N<=1,000,000)�� M�� �־����ϴ�.
	�� ��° �ٿ� N���� ���� ������ ���̿� �ΰ� �־����ϴ�.

	�� ��¼���
	 ù �ٿ� ���� �� M�� ���� ��ġ ��ȣ�� ����Ѵ�.
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