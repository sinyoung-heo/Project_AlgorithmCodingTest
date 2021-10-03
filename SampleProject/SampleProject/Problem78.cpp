#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	78. ��������(Kruskal MST �˰��� : Union & Find Ȱ��)

	�������忡 ������ �����. ���������� �� ���θ� ���������ϴ� ������ �ٴڳ� ���̴�.
	��������� ��� ���ø� ���� �����ϸ鼭 �ּ��� ��������� �鵵�� ���θ� �����ϰ� ���������δ� ����Ϸ��� �Ѵ�.
	�Ʒ��� �׸��� �� �� ���� �����ϴ� �׸��̴�.

	���� ������ �� ���ð� 1���� 9�� ǥ���Ǿ���, ������ �������� �ּҺ�� 196���� ��� ���ø� �����ϴ� ����� ã�Ƴ� ���̴�.

	�� �Է¼���
	ù° �ٿ� ������ ���� V(1 ��V�� 25)�� ������ ���� E(1 �� E �� 200�� �־�����. 
	���� E���� �ٿ��� �� ���ο� ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����. 
	�̴� A�� ���ÿ� B�� ���ð� ��������� C�� ���η� ����Ǿ� �ִٴ� �ǹ��̴�. C�� ���� 1,000,000�� ���� �ʴ´�.

	�� ��¼���
	��� ���ø� �����ϸ鼭 ��� �ּҺ���� ����Ѵ�.

	�� �Է¿��� 1
	9 12
	1 2 12
	1 9 25
	2 3 10
	2 8 17
	2 9 8
	3 4 18
	3 7 55
	4 5 44
	5 6 60
	5 7 38
	7 8 35
	8 9 15

	�� ��¿��� 1
	196
*/

int answer;
int V, E;

typedef struct tagEdge
{
	tagEdge() 
		: v1(0), v2(0), value(0) 
	{}
	tagEdge(const int& v1, const int& v2, const int& value)
		: v1{ v1 }, v2{ v2 }, value{ value }
	{}

	bool operator<(tagEdge& rhs) { return value < rhs.value; }

	int v1, v2, value;

}EDGE;

vector<int> unf;
vector<EDGE> graph;


int Find(int v)
{
	if (v == unf[v])
		return v;
	else
		return unf[v] = Find(unf[v]);	// ������ Root�� ã�� ������.
}

void Union(EDGE& edge)
{
	int a = Find(edge.v1);
	int b = Find(edge.v2);

	// ���� �ٸ� �����̸� ���� �������� �����.
	if (a != b)
		unf[a] = b;
}

int main()
{
	cin >> V >> E;
	
	unf.resize(V + 1);
	for (int i = 1; i <= V; ++i)
		unf[i] = i;

	for (int i = 0; i < E; ++i)
	{
		int a = 0, b = 0, value = 0;
		cin >> a >> b >> value;
		graph.emplace_back(a, b, value);
	}

	// value(���)�� �������� ���͸� �����Ѵ�.
	sort(graph.begin(), graph.end());

	for (auto& edge : graph)
	{
		int a = Find(edge.v1);
		int b = Find(edge.v2);

		// ���� �ٸ� �����̸�, ���� �������� Unionȭ �Ѵ�.
		// �׸��� ����ġ�� �����Ѵ�.
		if (a != b)
		{
			answer += edge.value;
			Union(edge);
		}
	}

	cout << answer << endl;
}
