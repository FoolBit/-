#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 300004

struct Node
{
    int value;
    int pos;
    Node(){};
    Node(int v, int p):value(v), pos(p){};

    bool operator < (const Node& a) const
    {
        if(value == a.value)
            return pos > a.pos;
        return value < a.value;
    }
}n[MAX];

int a[MAX];
int C[MAX];
int N;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int LIS)
{
    while(x <= N)
    {
        C[x] = max(C[x], LIS);
        x += lowbit(x);
    }
}

int query(int x)
{
    int LIS = 0;
    while(x>0)
    {
        LIS = max(LIS, C[x]);
        x -= lowbit(x);
    }

    return LIS;
}

void init()
{
    cin >> N;
    int v;
    for(int i=1; i<=N; ++i)
    {
        cin >> v;
        n[i] = Node(v, i);
    }

    sort(n+1, n+N+1);
}

void process()
{
    for(int i=1; i<=N; ++i)
    {
        int v = n[i].pos;
        int LIS = query(v) + 1;
        update(v, LIS);
    }
}

void print()
{
    cout << query(N);
}

int main()
{
    ios::sync_with_stdio(0);
    init();
    process();
    print();
}
