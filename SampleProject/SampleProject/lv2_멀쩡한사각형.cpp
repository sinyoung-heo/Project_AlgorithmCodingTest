#include <iostream>

using namespace std;

// ********************


// 최대 공약수
long long gcd(long a, long b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (true)
    {
        int r = a % b;
        if (r != 0)
        {
            a = b;
            b = r;
            gcd(a, b);
        }
        else
            return b;
    }
}

long long solution(int w, int h) 
{
    long long answer = 1;

    answer = w * (long)h - w - (long)h + gcd(w, (long)h);

    return answer;
}

