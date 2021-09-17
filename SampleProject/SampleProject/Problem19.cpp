#include <iostream>
#include <vector>

using namespace std;

/*
	19. �г� ������ (*)

	 ������ ������ ���� �������� ���弱������ 1, 2�г� ���л��鿡�� ���翡 �� 
	����� ��ȭ�� �����شٰ� �Ͽ� �л����� ���翡 �𿴽��ϴ�.
	������ �¼��� ��ȭ��ó�� ������� �ƴ϶� ������ �ٴڿ� ���ڸ� ��ġ�ϰ� �л����� �ɽ��ϴ�. 
	�׷��� ���� ���ڸ��� ���� Ű�� ū �л��� ������ �� �л����� ����Ű�� ���� ���ڸ� �л��� ��ũ���� ������ �ʽ��ϴ�. 
	�� �ٿ� ����Ű ������ �־����� �޻�� ����� �þ߸� ���� 
	��ȭ ��û�� �Ұ����ϰ� �ϴ� �г������ڰ� �� �ٿ� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù �ٿ� �� �ٿ� ���� �л��� N(3<=N<=100)�� �־����ϴ�.
	�� ��° �ٿ� N���� ���� Ű ����(45�̻� 100����)�� �� �ڸ� �л����� ���ʴ�� �־����ϴ�.

	�� ��¼���
	 �ڽ��� �� ��� ��θ� ��û�����ϴ� �л����� ����մϴ�.
*/

int main()
{
	int N = 0;
	cin >> N;

	vector<int> vecHeight;
	vecHeight.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> vecHeight[i];

	int cnt = -1;
	int max = INT_MIN;

	for (auto iter_rbegin = vecHeight.rbegin(); iter_rbegin != vecHeight.rend(); ++iter_rbegin)
	{
		if (max < (*iter_rbegin))
		{
			++cnt;
			max = *iter_rbegin;
		}
	}

	cout << cnt << endl;



	//bool isBigger = false;
	//for (int i = 0; i < N - 1; ++i)
	//{
	//	for (int j = i + 1; j < N; ++j)
	//	{
	//		if (vecHeight[i] <= vecHeight[j])
	//		{
	//			isBigger = true;
	//			break;
	//		}
	//	}

	//	if (!isBigger)
	//		++cnt;

	//	isBigger = false;
	//}

	//cout << cnt << endl;

	return 0;
}