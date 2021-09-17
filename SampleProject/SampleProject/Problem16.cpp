#include <iostream>
#include <map>

using namespace std;

/*
	16. Anagram(�Ƴ��׷� : ���� ���ͺ� ����)

	 Anagram�̶� �� ���ڿ��� ���ĺ��� ���� ������ �ٸ����� �� ������ ��ġ�ϸ� �� �ܾ�� �Ƴ��׷��̶�� �մϴ�.
	���� ��� AbaAeCe �� baeeACA �� ���ĺ��� ���� ������ �ٸ����� �� ������ ���캸��
	A(2), a(1), b(1), C(1), e(2)�� ���ĺ��� �� ������ ��� ��ġ�մϴ�. 
	�� ��� �� �ܾ ��迭�ϸ� ����� �ܾ �� �� �ִ� ���� �Ƴ��׷��̶� �մϴ�.
	���̰� ���� �� ���� �ܾ �־����� �� �ܾ �Ƴ��׷����� �Ǻ��ϴ� ���α׷��� �ۼ��ϼ���. 
	�Ƴ��׷� �Ǻ��� ��ҹ��ڰ� ���е˴ϴ�.

	�� �Է¼���
	 ù �ٿ� ù ��° �ܾ �Էµǰ�, �� ��° �ٿ� �� ��° �ܾ �Էµ˴ϴ�.
	�ܾ��� ���̴� 100�� ���� �ʽ��ϴ�.

	�� ��¼���
	 �� �ܾ �Ƴ��׷��̸� ��YES"�� ����ϰ�, �ƴϸ� ��NO"�� ����մϴ�.
*/

int main()
{
	string inputSrc = "";
	string inputDst = "";

	cin >> inputSrc >> inputDst;

	map<char, int> mapSrcAlpha;
	map<char, int> mapDstAlpha;

	for (int i = 0 ;i < inputSrc.size(); ++i)
	{
		auto iter_find = mapSrcAlpha.find(inputSrc[i]);
		if (iter_find == mapSrcAlpha.end())
			mapSrcAlpha.emplace(inputSrc[i], 1);
		else
			++mapSrcAlpha[inputSrc[i]];
	}

	for (int i = 0; i < inputDst.size(); ++i)
	{
		auto iter_find = mapDstAlpha.find(inputDst[i]);
		if (iter_find == mapDstAlpha.end())
			mapDstAlpha.emplace(inputDst[i], 1);
		else
			++mapDstAlpha[inputDst[i]];
	}

	if (equal(mapSrcAlpha.begin(), mapSrcAlpha.end(), mapDstAlpha.begin(), mapDstAlpha.end()))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}