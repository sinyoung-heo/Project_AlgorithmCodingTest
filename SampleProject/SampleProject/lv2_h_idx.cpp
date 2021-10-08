#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
    ���� ����
    H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.
    � �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.
    � �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

    ���ѻ���
    �����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
    ���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.

    ����� ��
    citations	return
    [3, 0, 6, 1, 5]	3

    ����� �� ����
    �� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.
*/

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    set<int> setSelectIdx;
    for (int i = 0; i < citations.back(); ++i)
    {
        setSelectIdx.clear();
        int cntSelect = 0;
        for (int j = 0; j < citations.size(); ++j)
        {
            if (citations[j] >= i)
            {
                ++cntSelect;
                setSelectIdx.emplace(j);
            }
        }

        if (cntSelect < i) continue;

        int cntNone = 0;
        for (int k = 0; k < citations.size(); ++k)
        {
            auto iter_find = setSelectIdx.find(k);
            if (iter_find != setSelectIdx.end()) continue;

            if (citations[k] <= i)
                ++cntNone;
        }

        if (cntNone == citations.size() - cntSelect)
        {
            if (answer < i)
                answer = i;
        }
    }

    return answer;
}