#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (true)
    {
        if (b - a == 1 && b % 2 == 0)
            return answer + 1;

        if (a > 1)
            a = (int)(ceil((float)a / 2.0f));
        else
            a = 1;

        b = (int)(ceil((float)b / 2.0f));

        ++answer;
    }


    return answer;
}

int main()
{

    return 0;
}