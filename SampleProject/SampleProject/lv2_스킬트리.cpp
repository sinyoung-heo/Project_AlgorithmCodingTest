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
            // ������ ��ų�� skill�� �ִ°�?
            auto iter_find = mapPreSkillIndex.find(skills[i]);
            if (mapPreSkillIndex.end() != iter_find)
            {
                // int idx = mapPreSkillIndex[skills[i]];
                int idx = iter_find->second;
                // skill Index�� 0��° �ΰ�?
                if (0 == idx)
                {
                    vecIsGetPreSkill[idx] = true;
                    bIsOK = true;
                    continue;
                }
                else
                {
                    // ���� ��ų�� ����°�?
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
            // ������ ��ų�� skill�� ���°�?
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