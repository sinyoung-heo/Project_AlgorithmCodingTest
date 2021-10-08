#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer = 0;
int target_num = 0;

void makeTarget(vector<int>& numbers, int sum, int level)
{
    if (level == numbers.size() && sum == target_num)
    {
        ++answer;
        return;
    }

    if (level == numbers.size()) return;

    makeTarget(numbers, sum + numbers[level], level + 1);
    makeTarget(numbers, sum - numbers[level], level + 1);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    target_num = target;

    makeTarget(numbers, 0, 0);

    return answer;
}

int main()
{
	return 0;
}