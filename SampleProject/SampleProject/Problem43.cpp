#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
	43. ��������(�̺а˻� ����)

	 ���Ϸ��ڵ忡���� �Ҽ����� ���� �������� ���̺� �������� DVD�� ����� �Ǹ��Ϸ� �Ѵ�.
	DVD���� �� N���� ���� ���µ�, DVD�� ��ȭ�� ������ ���̺꿡���� ������ �״�� �����Ǿ�� �Ѵ�. 
	������ �ٲ�� ���� �츮�� ���� �����ʾ��� �ſ� �Ⱦ��Ѵ�. 

	 ��, 1�� �뷡�� 5�� �뷡�� ���� DVD�� ��ȭ�ϱ� ���ؼ��� 1���� 5�� ������ ��� �뷡�� ���� DVD�� ��ȭ�ؾ� �Ѵ�.
	���Ϸ��ڵ� ���忡���� �� DVD�� �ȸ� ������ Ȯ���� �� ���� ������ �� ����� ����Ǵ� DVD�� ������ ���̷��� �Ѵ�. 

	��� ���� ���Ϸ��ڵ�� M���� DVD�� ��� �������� ��ȭ�ϱ�� �Ͽ���. 
	�� �� DVD�� ũ��(��ȭ ������ ����)�� �ּҷ� �Ϸ��� �Ѵ�. 
	�׸��� M���� DVD�� ��� ���� ũ�⿩�� ���������� ���� ��� ������ �� ���� ũ��� �ؾ� �Ѵ�.

	�� �Է¼���
	 ù° �ٿ� �ڿ��� N(1��N��1,000), M(1��M��N)�� �־�����. 
	 ���� �ٿ��� �������� ���̺꿡�� �θ� ������� �θ� ���� ���̰� �� ������(�ڿ���) �־�����. 
	 �θ� ���� ���̴� 10,000���� ���� �ʴ´ٰ� ��������.

	�� ��¼���
	 ù ��° �ٺ��� DVD�� �ּ� �뷮 ũ�⸦ ����ϼ���.
*/

int answer = INT_MAX;
int maxCnt = 0;
vector<int> v;

int CountDVD(const int& mid)
{
	int sum = 0;

	// ó���� DVD 1���� ����.
	int cnt = 1;

	for (int i = 0; i < v.size(); ++i)
	{
		if (sum + v[i] > mid)
		{
			++cnt;
			sum = v[i];
		}
		else
			sum += v[i];
	}

	return cnt;
}

int main()
{
	int size = 0;
	int sum = 0;

	cin >> size >> maxCnt;
	
	v.resize(size);
	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	
	sort(v.begin(), v.end());

	int left = 0;
	int right = sum;
	int mid = (left + right) / 2;

	while (left <= right)
	{
		mid = (left + right) / 2;

		// move left
		if (CountDVD(mid) <= maxCnt)
		{
			answer = mid;
			right = mid - 1;
		}
		// move right
		else
			left = mid + 1;
	}

	cout << answer << endl;

	return 0;
}