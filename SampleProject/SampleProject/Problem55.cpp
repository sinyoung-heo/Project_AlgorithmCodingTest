#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
	55. ��������(stack ����)
	A���ÿ��� ����� ������ B���÷� �����Ѵ�. �׷��� ���� �߰��� T���� �����ΰ� �־� ����ѱ����� ���� ������ ������ �� �ִ�.
	�����ο����� ������ ���� �� ���� �۾��� �մϴ�.
	P(push)�۾� : A���ÿ��� ���� ������ �����ο� �ִ´�.
	O(out)�۾� : �����ο� ���� ���� �ֱ� ������ B���÷� ������.
	���� 2 1 3 ���� ��ȣ ������ A���ÿ��� ����ϴ��� B���ÿ��� T�����θ� �̿��Ͽ� 1 2 3������ �����ϰ� �� �� �ֽ��ϴ�.
	�� �۾� P, P, O, O, P, O������ �۾��� �ϸ� B���ÿ� 1, 2, 3 ������ �����մϴ�.
	1���� N���� ��ȣ�� ���� ������ A���ÿ��� � ������ ����ϵ�, B���ÿ� ��ȣ������ �����ϵ��� �ϴ� ������ �۾��� ����մϴ�. 
	��� ������ �����ο� ���߸� B���÷� �� �� �ֽ��ϴ�. 
	��ȣ������� ������ �Ұ����ϸ� impossible �̶�� ����մϴ�.

	�� �Է¼���
	ù ��° �ٿ� �ڿ��� N(3<=N<=30)�� �־�����.
	�� ��° �ٿ� A���ÿ��� ����ϴ� ������ȣ���� ���ʴ�� �Էµȴ�.

	�� ��¼���
	������ �۾��� ������� P�� O�� ����Ѵ�.

	�� �Է¿��� 1
	3
	2 1 3
	�� ��¿��� 1
	PPOOPO
*/

int n;
vector<int> v;

vector<char> answer;
stack<int> s;
vector<int> vecArrive;

int main()
{
	cin >> n;
	v.resize(n);

	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	int next = 1;
	for (int i = 0; i < v.size(); ++i)
	{
		if (next != v[i])
		{
			s.push(v[i]);
			answer.emplace_back('P');
		}
		else
		{
			vecArrive.emplace_back(v[i]);
			answer.emplace_back('P');
			answer.emplace_back('O');
			++next;

			if (s.empty())
				continue;
			else
			{
				while (!s.empty() && s.top() == next)
				{
					vecArrive.emplace_back(v[i]);
					answer.emplace_back('O');

					s.pop();
					++next;
				}
			}
		}
	}

	if (vecArrive.size() != n)
		cout << "impossible" << endl;
	else
	{
		for (auto& ch : answer)
			cout << ch;
		cout << endl;
	}
}