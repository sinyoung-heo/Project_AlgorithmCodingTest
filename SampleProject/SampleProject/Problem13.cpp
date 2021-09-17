#include <iostream>
#include <map>

using namespace std;

/*
	13. ���� ���� ���� �ڸ���

	 N�ڸ��� �ڿ����� �ԷµǸ� �Էµ� �ڿ����� �ڸ��� �� ���� ���� ���� ���ڸ� ����ϴ� ���α׷��� �ۼ��ϼ���.
	���� ��� 1230565625��� �ڿ����� �ԷµǸ� 5�� 3�� ���Ǿ� ���� ���� ���� �����Դϴ�. 
	���� ���� ���� ��� �� �� ���� ū ���� ����ϼ���.

	�� �Է¼���
	 ù �ٿ� �ڿ����� �Էµ˴ϴ�. �ڿ����� ���̴� 100�� ���� �ʽ��ϴ�.

	�� ��¼���
	 �ڸ����� ���� ����մϴ�.
*/


int main()
{
	string input;
	cin >> input;

	map<char, int> mapNumberCnt;
	for (int i = 0; i < 10; ++i)
		mapNumberCnt.emplace((char)(i + 48), 0);

	for (int i = 0; i < input.size(); ++i)
		++mapNumberCnt[input[i]];


	int max = -1;
	char answer = -1;
	for (auto& pair : mapNumberCnt)
	{
		if (max <= pair.second)
		{
			if (max == pair.second)
			{
				if (answer <= pair.first)
					answer = pair.first;

				continue;
			}

			answer = pair.first;
			max = pair.second;
		}
	}

	cout << answer << endl;

	return 0;
}