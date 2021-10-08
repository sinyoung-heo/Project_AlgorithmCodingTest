#include <string>
#include <vector>
#include <cmath>

using namespace std;

// ********************

int solution(string word) 
{
    int answer = 0;

    int arrFirstACnt[5] = { 0, 0, 0, 0, 0 };
    int cnt = 5;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = cnt; j > 0; --j)
        {
            arrFirstACnt[i] += pow(5, j);
        }
        arrFirstACnt[i] /= 5;
        --cnt;
    }

    for (int i = 0; i < word.size(); ++i)
    {
        int value = 0;
        if (word[i] == 'A')
            value = 0;
        else if (word[i] == 'E')
            value = 1;
        else if (word[i] == 'I')
            value = 2;
        else if (word[i] == 'O')
            value = 3;
        else if (word[i] == 'U')
            value = 4;

        answer += arrFirstACnt[i] * value + 1;
    }

    return answer;
}

int main()
{

    return 0;
}