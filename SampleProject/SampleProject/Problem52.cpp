#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

/*
	52. Ugly Numbers (�� ����Ʈ �˰��� ����)

	� ���� ���μ����� ���� �� �� ���μ��� 2 �Ǵ� 3 �Ǵ� 5�θ� �̷���� ���� Ugly Number��� �θ��ϴ�. 
	Ugly Number�� ���ʴ�� ����� 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......�Դϴ�. 
	���� 1�� Ugly Number�� ù ��° ���� �մϴ�. 
	�ڿ��� N�� �־����� Ugly Number�� ���ʷ� ���� �� N��° Ugly Number�� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	ù �ٿ� �ڿ��� N(3<=N<=1500)�� �־����ϴ�.

	�� ��¼���
	ù �ٿ� N��° Ugly Number�� ����ϼ���.

	�� �Է¿��� 1
	10
	�� ��¿��� 1
	12

	�� �Է¿��� 2
	1500
	�� ��¿��� 2
	859963392
*/

vector<int> v{ 1 };
int n;
int answer;

int idxP2;
int idxP3;
int idxP5;

int findMin(const int& a, const int& b, const int& c)
{
	int min = 0;
	
	if (a < b) min = a;
	else min = b;

	if (min > c)
		min = c;

	return min;
}

int main()
{
	cin >> n;

	int r2 = 0, r3 = 0, r5 = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		r2 = v[idxP2] * 2;
		r3 = v[idxP3] * 3;
		r5 = v[idxP5] * 5;

		int ug = findMin(r2, r3, r5);
		v.emplace_back(ug);

		// index ����.
		if (ug == r2)
			++idxP2;
		if (ug == r3)
			++idxP3;
		if (ug == r5)
			++idxP5;
	}

	cout << v.back() << endl;
}