#include <iostream>
#include <cstring>
using namespace std;

#define MAX 200004

int N,M;
int a[MAX];
int C[MAX];

struct Node
{
	int l, r;
	bool apple=1;
}nodes[MAX];

struct E
{
	int s, t;
	int next;
}Edge[MAX];

int head[MAX];
int nEdge;

void addEdge(int s, int t)
{
	++nEdge;
	Edge[nEdge].s = s;
	Edge[nEdge].t = t;
	Edge[nEdge].next = head[s];

	head[s] = nEdge;
}

int dfs(int root, int k)
{
	nodes[root].l = k;

	++k;
	for (int j = head[root]; j; j = Edge[j].next)
	{
		k = dfs(Edge[j].t, k);
	}

	nodes[root].r = k;
	return k + 1;
}

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int pos,int delta)
{
	while (pos <= M)
	{
		C[pos] += delta;
		pos += lowbit(pos);
	}
}

int query(int pos)
{
	int sum = 0;
	while (pos)
	{
		sum += C[pos];
		pos -= lowbit(pos);
	}

	return sum;
}

void init()
{
	for (int i = 1; i <= M; ++i)
	{
		C[i] = lowbit(i);
	}
}

void change(int x)
{
	int l = nodes[x].l;
	int r = nodes[x].r;

	int delta = -nodes[x].apple;
	if (delta == 0)
		delta = 1;

	update(l, delta);
	update(r, delta);
	nodes[x].apple += delta;
}

int  Q(int x)
{
    int s1 = query(nodes[x].l-1);
    int s2 = query(nodes[x].r);

    return (s2 - s1) >> 1;
}

int main()
{
    ios::sync_with_stdio(0);
	cin >> N;
	M = N << 1;

	init();

	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}

	dfs(1, 1);

	int T;
	cin >> T;

	char c;
	int x;
	while (T--)
	{
		cin >> c >> x;
		if (c == 'Q')
			cout << Q(x) << endl;
		else
			change(x);
	}
}
