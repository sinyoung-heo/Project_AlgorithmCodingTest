#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
	49. ����� �ִ�
	������ ��ϳ��̸� �����մϴ�. 
	�������� ���鿡�� �� �ܸ�� ������ ���鿡�� �� �ܸ��� �ְ� 
	�ִ� ��ϰ����� ����Ͽ� ����� ������ ���鿡�� �� ������� ����� ������ �߽��ϴ�.
	������ ����� �״µ� ����ؾ� �� �ִ� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

	������ �� ����(�ִ밳��)
	������ ���� �� �� ĭ�� ����� �����Դϴ�. 
	���鿡���� ���� ������ ������ ���鿡���� ���� ������ �־����� ����� �� �ִ� ����� ���� ������ ����ϼ���.

	�� �Է¼���
	ù �ٿ� ����� ũ�� N(3<=N<=10)�� �־����ϴ�. ����� ũ��� ���簢�� N*N�Դϴ�.
	�� ��° �ٿ� N���� ���鿡���� ���� ������ ���� �������� �־����ϴ�.
	�� ��° �ٿ� N���� ������ ���� ���� ������ ���ʺ��� �־����ϴ�.
	����� ���̴� 10 �̸��Դϴ�.

	�� ��¼���
	ù �ٿ� ����� �ִ� ������ ����մϴ�.

	�� �Է¿��� 1
	4
	2 0 3 1
	1 1 2 3

	�� ��¿��� 1
	17
*/

int answer = 0;

vector<vector<int>> v;
vector<int> vecFront;
vector<int> vecRight;
int n;

int main()
{
	cin >> n;

	v.resize(n);
	for (auto& vec : v)
		vec.resize(n);

	// front
	vecFront.resize(n);
	for (int i = 0; i < vecFront.size(); ++i)
		cin >> vecFront[i];

	// right
	vecRight.resize(n);
	for (int i = 0; i < vecRight.size(); ++i)
		cin >> vecRight[i];
	
	// �켱 ���鿡�� �� ������ ��� ä���.
	for (int y = 0; y < v.size(); ++y)
	{
		for (int x = 0; x < v[y].size(); ++x)
		{
			v[y][x] = vecFront[x];
		}
	}

	// �����ʿ��� �� ���� ���� ���Ѵ�. �����ʿ��� �� ������ ũ��, �����ʿ��� �� ������ ġȯ�Ѵ�.
	auto iter_rbegin = vecRight.rbegin();
	for (int y = 0; y < v.size(); ++y, ++iter_rbegin)
	{
		for (int x = 0; x < v[y].size(); ++x)
		{
			if (v[y][x] > *iter_rbegin)
				v[y][x] = *iter_rbegin;

			answer += v[y][x];
		}
	}

	cout << answer << endl;
}