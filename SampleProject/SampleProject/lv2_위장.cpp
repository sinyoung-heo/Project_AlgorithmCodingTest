#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;

    map<string, int> m;

    for (auto& clothes_type : clothes)
    {
        // clothes_type[0];    // clothes name
        ++m[clothes_type[1]];   // clothes type
    }

    for (auto& pair : m)
    {
        answer *= (pair.second + 1);   // +1 --> no wear
    }
    // -1 --> none all wear
    return answer - 1;
}

int main()
{

    return 0;
}