#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50002

int father[MAX];
int relation[MAX];  // 0:同类 1: 吃 -1: 被吃
int N,K;
int lier;

void Init()
{
    for(int i=1; i<=N; ++i)
    {
        father[i] = i;
    }
}

int ComputeRelation(int ar, int rb)
{
    int r = ar + rb;
    if(r == 2)
    {
        return -1;
    }
    if(r == -2)
    {
        return 1;
    }
    return r;
}

int GetRoot(int x)
{
    if(father[x] == x)
        return x;
    int fx = father[x];

    father[x] = GetRoot(fx);
    relation[x] = ComputeRelation(relation[x], relation[fx]);

    return father[x];
}

void judge(int d, int x, int y)
{
    if(x > N || y > N)
    {
        ++lier;
        return;
    }

    int fx = GetRoot(x);
    int fy = GetRoot(y);

    int r;
    if(fx != fy)
    {
        // fx->y
        r = ComputeRelation(-relation[x], d-1);
        // fx->fy
        r = ComputeRelation(r, relation[y]);
        father[fx] = fy;
        relation[fx] = r;
        return;
    }

    r = ComputeRelation(relation[x], -relation[y]);
    if(r != d-1)
    {
        ++lier;
    }

}

int main()
{
    cin >> N >> K;
    Init();
    int d,x,y;
    while(K--)
    {
        cin >> d >> x >> y;
        judge(d,x,y);
    }
    cout << lier;
}