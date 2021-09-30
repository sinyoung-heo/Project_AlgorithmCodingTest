#include "vld.h"
#include <iostream>
#include <vector>

using namespace std;

class CMyString
{
public:
	CMyString() { cout << "�⺻������ ȣ��" << endl; }
	CMyString(const char* str)
	{
		cout << str << " �����ִ� ������ ȣ��" << endl;

		len = strlen(str);
		p = new char[len + 1];

		for (int i = 0; i < len; ++i)
			p[i] = str[i];

		p[len] = '\0';
	}
	CMyString(const CMyString& rhs) 
		: len(rhs.len)
	{ 
		cout << rhs.p << " ��������� ȣ��" << endl;

		p = new char[len + 1];

		for (int i = 0; i < len; ++i)
			p[i] = rhs.p[i];

		p[len] = '\0';
	}

	CMyString(CMyString&& rhs)
		: p(rhs.p) , len(rhs.len)
	{
		cout << rhs.p <<" �̵������� ȣ��" << endl;

		// �ӽ� ��ü �Ҹ�� �޸� ���� X.
		rhs.p = nullptr;
		rhs.len = 0;
	}
	~CMyString() 
	{ 
		if (p != nullptr)
			cout << p << " �Ҹ��� ȣ��" << endl; 
		else
			cout << "p = nullptr �Ҹ��� ȣ��" << endl;


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
	//CMyString* s1 = new CMyString("Test");	// �����ִ� ������.
	//CMyString* s2 = new CMyString(*s1);		// ���� ������.
	//CMyString* s3 = move(s1);

	//delete s1;
	//delete s2;




	vector<CMyString> v;
	//CMyString t1{ "T1" };
	////v.push_back(t1);		// ��������� ȣ��
	//v.push_back(move(t1));	// �̵������� ȣ��



	/*
		push_back vs emplace_back
	*/
	//v.push_back(CMyString("PushBack"));
	//cout << "------------------------" << endl;
	v.emplace_back("EmplaceBack");
	cout << "------------------------" << endl;
}