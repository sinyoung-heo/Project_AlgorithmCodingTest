#include <iostream>
#include <vector>
#include <map>

using namespace std;

void fuc(int n)
{
	if (n > 7)
		return;

	cout << n << " ";
	fuc(n * 2);
	fuc(n * 2 + 1);
}

int main()
{
	fuc(1);

	return 0;
}