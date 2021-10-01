#include <iostream>
#include <array>

using namespace std;

int main()
{
	// 10개의 요소는 초기화되지 않는다. 쓰레기값.
	array<int, 10> arr1;
	
	// 10개의 요소는 해당 요소 형식의 기본 값으로 초기화 된다.
	// int는 0으로 초기화.
	array<int, 10> arr1 { };

	// 값이 명시되지 않은 나머지 요소들은 기본 값으로 초기화.	
	array<int, 10> arr2{ 1, 2, 3, 4, 5 };
}