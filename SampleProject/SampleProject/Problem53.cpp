#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
	10���� N�� �ԷµǸ� K������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. 
	���� �ڷᱸ���� ����Ͻñ� �ٶ��ϴ�.

	�� �Է¼���
	ù ��° �ٿ� 10���� N(10<=N<=1,000)�� K(2, 5, 8, 16)�� �־�����.

	�� ��¼���
	K������ ����Ѵ�.

	�� �Է¿��� 1
	11 2
	�� ��¿��� 1
	1011

	�� �Է¿��� 2
	31 16
	�� ��¿��� 2
	1F
*/


int n, k;
stack<int> s;

int main()
{
	cin >> n >> k;

	int num = n;
	int result = 0;
	while (num != 0)
	{
		result = num % k;

		if (k != 16)
			s.push(result);
		else
		{
			switch (result)
			{
			case 10:
				result = 'A';
				break;
			case 11:
				result = 'B';
				break;
			case 12:
				result = 'C';
				break;
			case 13:
				result = 'D';
				break;
			case 14:
				result = 'E';
				break;
			case 15:
				result = 'F';
				break;
			default:
				break;
			}

			s.push(result);
		}

		num /= k;
	}

	while (!s.empty())
	{
		int n = s.top();
		if (n >= 10)
			cout << (char)n;
		else
			cout << n;

		s.pop();
	}
	cout << endl;
}