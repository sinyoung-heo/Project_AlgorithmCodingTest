#include "vld.h"
#include <iostream>
#include <vector>

using namespace std;

class CMyString
{
public:
	CMyString() { cout << "기본생성자 호출" << endl; }
	CMyString(const char* str)
	{
		cout << str << " 인자있는 생성자 호출" << endl;

		len = strlen(str);
		p = new char[len + 1];

		for (int i = 0; i < len; ++i)
			p[i] = str[i];

		p[len] = '\0';
	}
	CMyString(const CMyString& rhs) 
		: len(rhs.len)
	{ 
		cout << rhs.p << " 복사생성자 호출" << endl;

		p = new char[len + 1];

		for (int i = 0; i < len; ++i)
			p[i] = rhs.p[i];

		p[len] = '\0';
	}

	CMyString(CMyString&& rhs)
		: p(rhs.p) , len(rhs.len)
	{
		cout << rhs.p <<" 이동생성자 호출" << endl;

		// 임시 객체 소멸시 메모리 해제 X.
		rhs.p = nullptr;
		rhs.len = 0;
	}
	~CMyString() 
	{ 
		if (p != nullptr)
			cout << p << " 소멸자 호출" << endl; 
		else
			cout << "p = nullptr 소멸자 호출" << endl;


		if (nullptr != p)
		{
			delete[] p;
			p = nullptr;
		}
	}

	char* p = nullptr;
	int len = 0;
};

int main()
{
	//CMyString* s1 = new CMyString("Test");	// 인자있는 생성자.
	//CMyString* s2 = new CMyString(*s1);		// 복사 생성자.
	//CMyString* s3 = move(s1);

	//delete s1;
	//delete s2;




	vector<CMyString> v;
	//CMyString t1{ "T1" };
	////v.push_back(t1);		// 복사생성자 호출
	//v.push_back(move(t1));	// 이동생성자 호출



	/*
		push_back vs emplace_back
	*/
	//v.push_back(CMyString("PushBack"));
	//cout << "------------------------" << endl;
	v.emplace_back("EmplaceBack");
	cout << "------------------------" << endl;
}