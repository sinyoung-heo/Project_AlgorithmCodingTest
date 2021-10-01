#include <iostream>
#include <vector>

using namespace std;

class CTest
{
public:
	CTest() { cout << "기본 생성자 호출" << endl; }
	CTest(const int& n)
		: n{ n }
	{
		cout << "인자있는 생성자 호출" << endl;
	}
	CTest(const CTest& rhs)
		: n(rhs.n)
	{
		cout << "복사 생성자 호출" << endl;
	}
	~CTest() { cout << "기본 소멸자 호출" << endl; }

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