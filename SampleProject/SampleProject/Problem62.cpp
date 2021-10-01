#include <iostream>
#include <vector>

using namespace std;

/*
	62. ��������
	N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
	�����ϴ� ����� ���������Դϴ�.

	�� �Է¼���
	ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
	�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�. �� �ڿ����� ������ ���� �ȿ�
	�ֽ��ϴ�.

	�� ��¼���
	������������ ���ĵ� ������ ����մϴ�.

	�� �Է¿��� 1
	8
	7 6 3 1 5 2 4 8

	�� ��¿��� 1
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

	// left�� ���� �����̹Ƿ�, right�� ��Ҹ� �־��ش�.
	if (leftStart >= vecLeft.size())
	{
		for (int i = rightStart; i < vecRight.size(); ++i)
			vecMerge.emplace_back(vecRight[i]);
	}
	// right�� ���� �����̹Ƿ�, left�� ��Ҹ� �־��ش�.
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