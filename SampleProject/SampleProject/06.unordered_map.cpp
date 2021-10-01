#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> us{ 1, 2, 3, 4, 5 };

	cout << "vector   list" << endl;
	cout << "버킷     색인" << endl;
	for (int i = 0; i < us.bucket_count(); ++i)
	{
		cout << "[" << i << "] ";

		// i번째 버킷에 원소가 들어가있니?
		if (us.bucket_size(i))
		{
			// i번째 리스트의 버킷 반복자.
			for (auto p = us.begin(i); p != us.end(i); ++p)
			{
				cout << " --> " << *p;
			}

		}

		cout << endl;
	}
}