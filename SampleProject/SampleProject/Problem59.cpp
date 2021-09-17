#include <iostream>
#include <vector>

using namespace std;

/*
	59. 부분집합(DFS)

	 자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하는 프로그램을 작성하세요.

	▣ 입력설명
	 첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.

	▣ 출력설명
	 첫 번째 줄부터 각각의 부분집합을 출력합니다. 부분집합을 출력하는 순서는 출력예제에서 출력한 순서와 같게 합니다. 
	단 공집합은 출력하지 않습니다.
*/

int input = 0;
vector<bool> vecVisit;

void DFS(int n)
{
	if (n == input + 1)
	{
		for (int i = 0; i < vecVisit.size(); ++i)
		{
			if (vecVisit[i])
				cout << i + 1 << " ";
		}
		cout << endl;

		return;
	}

	vecVisit[n - 1] = true;
	DFS(n + 1);

	vecVisit[n - 1] = false;
	DFS(n + 1);
}

int main()
{
	cin >> input;
	vecVisit.resize(input);

	DFS(1);

	return 0;
}