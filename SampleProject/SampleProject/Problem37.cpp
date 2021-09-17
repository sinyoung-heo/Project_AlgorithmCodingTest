#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
	37. Least Recently Used(īī�� ĳ�� ���� ����)

	 ĳ�ø޸𸮴� CPU�� �ֱ����ġ(DRAM) ������ ����� �ӽ� �޸𸮷μ� 
	CPU�� ó���� �۾��� ������ ���Ҵٰ� �ʿ��� �ٷ� ����ؼ� ó���ӵ��� ���̴� ��ġ�̴�. 
	���� ��ΰ� �뷮�� �۾� ȿ�������� ����ؾ� �Ѵ�. 
	ö���� ��ǻ�ʹ� ĳ�ø޸� ��� ��Ģ�� LRU �˰����� ������. 
	LRU �˰����� Least Recently Used �� ���ڷ� �������ڸ� ���� �ֱٿ� ������ ���� �� ������ �ǹ̸� ������ �ֽ��ϴ�. 
	ĳ�ÿ��� �۾��� ������ �� ���� �������� ������� ���� ���� �����ϰڴٴ� �˰����Դϴ�.
	���� ĳ���� ����� 5�̰� �۾��� 2 3 1 6 7 ������ ����Ǿ� �ִٸ�,
	(�� ���� ���� �ֱٿ� ���� �۾��̰�, �� �ڴ� ���� �������� ������ ���� �۾��̴�.)
	1) Cache Miss : �ؾ��� �۾��� ĳ�ÿ� ���� ���·� �� ���¿��� ���� ���ο� �۾��� 5�� �۾��� CPU�� ����Ѵٸ� 
	Cache miss�� �ǰ� ��� �۾��� �ڷ� �и��� 5���۾��� ĳ���� �Ǿտ� ��ġ�Ѵ�.
	5 2 3 1 6
	(7�� �۾��� ĳ�ÿ��� �����ȴ�.)

	2) Cache Hit : �ؾ��� �۾��� ĳ�ÿ� �ִ� ���·� �� ���¿��� ���� 3�� �۾��� CPU�� ����Ѵٸ� Cache Hit�� �ǰ�, 
	63�� �տ� �ִ� 5, 2�� �۾��� �� ĭ �ڷ� �и���, 3���� �� ������ ��ġ�ϰ� �ȴ�.
	5 2 3 1 6
	--->
	3 5 2 1 6
	ĳ���� ũ�Ⱑ �־�����, ĳ�ð� ����ִ� ���¿��� N���� �۾��� CPU�� ���ʷ� ó���Ѵٸ�
	N���� �۾��� ó���� ��ĳ�ø޸��� ���¸� ���� �ֱ� ���� �۾����� ���ʴ�� ����ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù ��° �ٿ� ĳ���� ũ���� S(3<=S<=10)�� �۾��� ���� N(5<=N<=1,000)�� �Էµȴ�.
	�� ��° �ٿ� N���� �۾���ȣ�� ó�������� �־�����. �۾���ȣ�� 1 ~100 �̴�.

	�� ��¼���
	 ������ �۾� �� ĳ�ø޸��� ���¸� ���� �ֱ� ���� �۾����� ���ʷ� ����մϴ�.
*/

int cacheSize = 0;
int jobSize = 0;

void checkCacheMemory(list<int>& lst, const int& job)
{
	if (lst.empty())
		lst.emplace_back(job);
	else
	{
		// Check Cache
		list<int>::iterator iter_find = find(lst.begin(), lst.end(), job);
		
		// Cahce Miss
		if (iter_find == lst.end())
		{
			lst.emplace_front(job);

			if (lst.size() > cacheSize)
				lst.pop_back();
		}

		// Cache Hit
		else
		{
			int hitJob = *iter_find;
			lst.erase(iter_find);
			lst.emplace_front(hitJob);
		}
	}
}

int main()
{
	cin >> cacheSize >> jobSize;

	list<int> lstCache;

	vector<int> vecJob;
	vecJob.resize(jobSize);

	for (int i = 0; i < vecJob.size(); ++i)
		cin >> vecJob[i];

	for (int i = 0; i < vecJob.size(); ++i)
		checkCacheMemory(lstCache, vecJob[i]);


	auto iter_begin = lstCache.begin();
	auto iter_end = lstCache.end();

	for (int i = 0; i < cacheSize; ++i, ++iter_begin)
	{
		if (iter_begin != iter_end)
			cout << *iter_begin << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}