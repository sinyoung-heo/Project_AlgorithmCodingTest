#include <iostream>
#include <vector>

using namespace std;

/*
	61. Ư�� �� �����(DFS : MS ���ͺ�)

	N���� ���ҷ� ������ �ڿ��� ������ �־�����, ������ ���ҿ� ��+��, ��-�� ������ ����Ͽ� Ư��
	���� M�� ����� ��찡 �� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���. 
	�� ���Ҵ� ���꿡 �� ���� ����մϴ�.
	���� ��� {2, 4, 6, 8}�� �Էµǰ�, M=12�̸�
	2+4+6=12
	4+8=12
	6+8-2=12
	2-4+6+8=12
	�� �� 4������ ��찡 �ֽ��ϴ�. ��������� ��찡 �������� ������ -1�� ����Ѵ�.

	�� �Է¼���
	ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� M(1<=M<=100) �־����ϴ�.
	�� ��° �ٿ� ������ ���� N���� �־�����. �� ���Ҵ� �ߺ����� �ʴ´�.

	�� ��¼���
	ù ��° �ٿ� ��YES" �Ǵ� ��NO"�� ����Ѵ�.

	�� �Է¿��� 1
	4 12
	2 4 6 8

	�� ��¿��� 1
	4
*/

int answer;

int N;
int M;
vector<int> v;

void findAnswer(const int& idx, const int& num)
{
	if (idx > v.size() - 1)
		return;

	// +
	int localSum1 = num;
	localSum1 += v[idx];
	if (localSum1 == M)
		++answer;

	findAnswer(idx + 1, localSum1);

	// -
	int localSum2 = num;
	localSum2 += (v[idx] * -1);
	if (localSum2 == M)
		++answer;

	findAnswer(idx + 1, localSum2);

	// 0
	 int localSum3 = num;
	//if (localSum3 == M)
	//	++answer;
	findAnswer(idx + 1, localSum3);
}

int main()
{
	cin >> N >> M;
	
	v.resize(N);
	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	findAnswer(0, 0);

	if (answer != 0)
		cout << answer << endl;
	else
		cout << -1 << endl;
}