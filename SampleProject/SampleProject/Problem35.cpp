#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input = 0;
	cin >> input;

	vector<int> v;
	v.resize(input);
	for (int i = 0; i < input; ++i)
		cin >> v[i];

	vector<int> p;
	vector<int> m;

	for (auto& n : v)
	{
		if (n > 0)
			p.emplace_back(n);
		else
			m.emplace_back(n);
	}

	for (auto& n : p)
		m.emplace_back(n);

	for (auto& n : m)
		cout << n << " ";

	return 0;
}