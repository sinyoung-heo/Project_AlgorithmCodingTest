#include <iostream>
#include <stack>

using namespace std;

/*
	54. �ùٸ� ��ȣ(stack)

	��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� ��YES", �ùٸ��� ������ ��NO"�� ����մϴ�.
	(())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�.

	�� �Է¼���
	ù ��° �ٿ� ��ȣ ���ڿ��� �Էµ˴ϴ�. ���ڿ��� �ִ� ���̴� 30�̴�.

	�� ��¼���
	ù ��° �ٿ� YES, NO�� ����Ѵ�.

	�� �Է¿��� 1
	(()(()))(()
	�� ��¿��� 1
	NO

	�� �Է¿��� 2
	()()(()())
	�� ��¿��� 2
	YES
*/

stack<char> s;

int main()
{
	string str;
	cin >> str;

	for (auto& ch : str)
	{
		if (ch == '(')
			s.push(ch);
		else if (ch == ')')
		{
			if (s.empty())
			{
				cout << "NO" << endl;
				return 0;
			}
			else
				s.pop();
		}
	}

	if (s.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}