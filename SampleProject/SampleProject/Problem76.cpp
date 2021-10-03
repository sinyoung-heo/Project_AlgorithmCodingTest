#include <iostream>
#include <vector>

using namespace std;

/*
	76. ���װ��(�޸������̼�)
	���װ���� N���� ���Ҹ� ������ ���տ��� R���� ���Ҹ� �̾� �κ������� ����� ����� �� �� �ǹ��Ѵ�. 
	������ nCr �� ǥ���ȴ�.
	N�� R�� �־����� ���װ���� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	ù ��° �ٿ� �ڿ��� N(1<=N<=20)�� R(0<=R<=20)�� �־�����. �� (N>=R)

	�� ��¼���
	ù ��° �ٿ� ���װ�� ���� ����Ѵ�.

	�� �Է¿��� 1
	5 3

	�� ��¿��� 1
	10

	nPr = n! / (n-r)!
	nCr = nPr / r!
*/

int n, r;

vector<int> v;

void fac(int n)
{
	if (n == 1)
		return;

	fac(n - 1);
	v[n - 1] = n * v[n - 2];
}


int main()
{
	cin >> n >> r;

	v.resize(n);
	v[0] = 1;

	fac(n);

	int nPr = v[n - 1] / v[n - r - 1];
	int nCr = nPr / v[r - 1];

	cout << nCr << endl;
}