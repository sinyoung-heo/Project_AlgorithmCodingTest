#include <iostream>

using namespace std;

/*
	7. ����ܾ� ����

	 ������ ��ǻ�Ͱ� ���̷����� �ɷ� ����ܾ �پ��� ��ҹ��ڰ� ȥ�յǾ� ǥ���ȴ�.
	���� ��� �Ƹ��ٿ� �̶� ���� ������ �ִ� beautiful �ܾ ��bE au T I fu L�� �� ����
	��ǻ�Ϳ� ǥ�õǰ� �ֽ��ϴ�. ���� ���� ������ ǥ�õǴ� ����ܾ ������ ǥ����� ������
	�����ϰ� �ҹ���ȭ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù �ٿ� ���̷����� �ɸ� ����ܾ �־�����. ���̷����� �ɸ� ����ܾ��� ����(��������)��
	100�� ���� �ʴ´�. ���ڻ����� ������ ���������� ������ �� �ֽ��ϴ�. �Է��� ���ĺ��� ��
	�鸸 �־����ϴ�.

	�� ��¼���
	 ù �ٿ� �ҹ��ڷ� �� �������� ����ܾ ����Ѵ�.
*/

int main()
{
	char input[64];
	cin.getline(input, sizeof(input));

	string output = "";
	for (int i = 0; i < strlen(input); ++i)
	{
		// �빮��
		if (1 == isalpha(input[i]))
		{
			output.push_back(tolower(input[i]));
		}
		// �ҹ���
		else if (2 == isalpha(input[i]))
		{
			output.push_back(input[i]);
		}
	}

	cout << output << endl;

	return 0;
}