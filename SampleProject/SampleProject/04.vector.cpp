#include <iostream>
#include <vector>

using namespace std;

class CTest
{
public:
	CTest() { cout << "�⺻ ������ ȣ��" << endl; }
	CTest(const int& n)
		: n{ n }
	{
		cout << "�����ִ� ������ ȣ��" << endl;
	}
	CTest(const CTest& rhs)
		: n(rhs.n)
	{
		cout << "���� ������ ȣ��" << endl;
	}
	~CTest() { cout << "�⺻ �Ҹ��� ȣ��" << endl; }

	int n = 0;
};

int main()
{
	vector<int> v;
	
	v.resize(5);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	cout << "Data : " << v.data() << endl;
}