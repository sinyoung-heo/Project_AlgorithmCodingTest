#include <iostream>
#include <stack>

using namespace std;

/*
	8. �ùٸ� ��ȣ(*)

	 ��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� ��YES", �ùٸ��� ������ ��NO"�� ����մϴ�.
	(())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�.

	�� �Է¼���
	 ù ��° �ٿ� ��ȣ ���ڿ��� �Էµ˴ϴ�. ���ڿ��� �ִ� ���̴� 30�̴�.

	�� ��¼���
	 ù ��° �ٿ� YES, NO�� ����Ѵ�.
*/

int main()
{
	char input[32] = "";
	cin.getline(input, sizeof(input));

	int openCnt = 0;
	
	for (int i = 0; i < strlen(input); ++i)
	{
		if (input[i] == '(')
			++openCnt;
		else if (input[i] == ')')
			--openCnt;

		if (openCnt < 0)
			break;
	}

	if (0 == openCnt)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}