#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(const int& num)
{
    if (num < 2) 
        return false;

    int a = (int)sqrt(num);

    for (int i = 2; i <= a; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers)
{
    int answer = 0;

    set<string> set_permutation;
    set<int> set_check_prime;

    vector<int> v;
    v.resize(numbers.size());

    sort(numbers.begin(), numbers.end());

    // 문자열 조합의 수를 구한다.
    for (int i = 0; i < numbers.length(); ++i)
    {
        v[i] = 1;

        do 
        {
            string result = "";
            for (int i = 0; i < numbers.size(); ++i)
            {
                if (v[i] == 1)
                    result += numbers[i];
            }

            set_permutation.emplace(result);

               // 조합에 대한 순열을 숫자로 변환한 후 소수 판단.
			while (next_permutation(result.begin(), result.end()))
			{
                set_permutation.emplace(result);
			}

        } while (prev_permutation(v.begin(), v.end()));
    }

    for (auto& str : set_permutation)
    {
        int num = atoi(str.c_str());

        // 중복 숫자 검사를 방지한다.
        auto iter_find = set_check_prime.find(num);
        if (iter_find == set_check_prime.end())
        {
            set_check_prime.emplace(num);

			if (isPrime(num)) 
                ++answer;
        }

    }

    return answer;
}

int main()
{
    solution("011");

    return 0;
}