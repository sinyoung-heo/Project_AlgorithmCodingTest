#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    vector<bool> vecIsGetPreSkill;
    vecIsGetPreSkill.resize(skill.size());

    map<char, int> mapPreSkillIndex;
    for (int i = 0; i < skill.size(); ++i)
    {
        mapPreSkillIndex[skill[i]] = i;
        vecIsGetPreSkill[i] = false;
    }

    bool bIsOK = false;
    for (auto& skills : skill_trees)
    {
        for (int i = 0; i < skills.size(); ++i)
        {
            // 배우려는 스킬이 skill에 있는가?
            auto iter_find = mapPreSkillIndex.find(skills[i]);
            if (mapPreSkillIndex.end() != iter_find)
            {
                // int idx = mapPreSkillIndex[skills[i]];
                int idx = iter_find->second;
                // skill Index가 0번째 인가?
                if (0 == idx)
                {
                    vecIsGetPreSkill[idx] = true;
                    bIsOK = true;
                    continue;
                }
                else
                {
                    // 이전 스킬을 배웠는가?
                    if (vecIsGetPreSkill[idx - 1])
                    {
                        vecIsGetPreSkill[idx] = true;
                        bIsOK = true;
                        continue;
                    }
                    else
                    {
                        bIsOK = false;
                        break;
                    }
                }

            }
            // 배우려는 스킬이 skill에 없는가?
            else
                bIsOK = true;
        }

        for (auto isGet : vecIsGetPreSkill)
            isGet = false;

        if (bIsOK)
            ++answer;
    }


    return answer;
}

int main()
{

    return 0;
}