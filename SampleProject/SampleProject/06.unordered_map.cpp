#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> us{ 1, 2, 3, 4, 5 };

	cout << "vector   list" << endl;
	cout << "��Ŷ     ����" << endl;
	for (int i = 0; i < us.bucket_count(); ++i)
	{
		cout << "[" << i << "] ";

		// i��° ��Ŷ�� ���Ұ� ���ִ�?
		if (us.bucket_size(i))
		{
			// i��° ����Ʈ�� ��Ŷ �ݺ���.
			for (auto p = us.begin(i); p != us.end(i); ++p)
			{
				cout << " --> " << *p;
			}

		}

		cout << endl;
	}
}