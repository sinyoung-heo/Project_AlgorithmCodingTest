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

    // ���ڿ� ������ ���� ���Ѵ�.
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

               // ���տ� ���� ������ ���ڷ� ��ȯ�� �� �Ҽ� �Ǵ�.
			while (next_permutation(result.begin(), result.end()))
			{
                set_permutation.emplace(result);
			}

        } while (prev_permutation(v.begin(), v.end()));
    }

    for (auto& str : set_permutation)
    {
        int num = atoi(str.c_str());

        // �ߺ� ���� �˻縦 �����Ѵ�.
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