#include <iostream>
#include <array>

using namespace std;

int main()
{
	// 10���� ��Ҵ� �ʱ�ȭ���� �ʴ´�. �����Ⱚ.
	array<int, 10> arr1;
	
	// 10���� ��Ҵ� �ش� ��� ������ �⺻ ������ �ʱ�ȭ �ȴ�.
	// int�� 0���� �ʱ�ȭ.
	array<int, 10> arr1 { };

	// ���� ��õ��� ���� ������ ��ҵ��� �⺻ ������ �ʱ�ȭ.	
	array<int, 10> arr2{ 1, 2, 3, 4, 5 };
}