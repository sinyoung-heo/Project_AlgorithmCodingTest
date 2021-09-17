#include <iostream>
#include <vector>

using namespace std;

/*
	18. �������� (*)

	  T���� ���� ����Ʈ�� �������� �߻� �� ������ �߻��� �����ϱ� ���� ���� ����Ʈ�� ���� �� �ٴڿ� ���������� ��ġ�߽��ϴ�. 
	 �� ������ �� ������ ���� �������� ����ġ�� �ʴ����� ����Ʈ �����ǿ� �ǽð����� �����մϴ�. 
	 �׸��� �� ������ ����ġ�� M���� ������ ����ȣ���� ���� �溸���� ������ ����Ϳ��� �︳�ϴ�. 
	 �� ������ N�� ������ �ǽð� ����ġ�� �־����� �ִ� �������� �溸���� �︰ �ð��� ���ϼ���. 
	 �溸���� ������ -1�� ����մϴ�.

	�� �Է¼���
	 ù �ٿ� �ڿ��� N(10<=N<=100)�� M�� �־����ϴ�.
	�� ��° �ٿ� N���� ������(1000���� �ڿ���)�� �� ������� �Էµȴ�.

	�� ��¼���
	 �ִ� ���� �溸���� �︰ �ð�(��)�� ����ϼ���.
*/

int main()
{
	int N, M = 0;
	cin >> N >> M;

	vector<int> vecPower;
	vecPower.resize(N);

	int length = 0;
	int max = INT_MIN;

	for (int i = 0; i < N; ++i)
	{
		cin >> vecPower[i];

		if (vecPower[i] > M)
		{
			++length;

			if (max < length)
				max = length;
		}
		else
			length = 0;
	}

	if (max == 0)
		cout << -1 << endl;
	else
		cout << max << endl;




	//for (int i = 0; i < vecPower.size(); ++i)
	//{
	//	if (vecPower[i] > M)
	//	{
	//		++length;

	//		if (max < length)
	//			max = length;
	//	}
	//	else
	//		length = 0;
	//}

	//cout << max << endl;





	//for (int i = 0; i < vecPower.size(); ++i)
	//{
	//	if (vecPower[i] > M)
	//	{
	//		++length;
	//		if (max < length)
	//			max = length;

	//		if (i + 1 < vecPower.size())
	//		{
	//			if (vecPower[i + 1] > M)
	//			{
	//				++length;
	//				++i;
	//				if (max < length)
	//					max = length;

	//				continue;
	//			}
	//			else
	//			{
	//				length = 0;
	//				continue;
	//			}
	//		}
	//	}
	//	else
	//		length = 0;

	//}

	// cout << max << endl;

	return 0;
}