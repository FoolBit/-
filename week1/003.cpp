#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100100
int T,N,K;
int father[MAX];
int relation[MAX];
int suspicious;

void Init()
{
    memset(father, 0, sizeof(father));
    memset(relation, 0, sizeof(relation));
    suspicious = 0;
}

int GetFather(int x)
{
    if(!father[x])
        return x;

    int fx = father[x];
    father[x] = GetFather(fx);
    relation[x] = relation[x] ^ relation[fx];

    return father[x];
}

void Judge(int x, int y)
{
    int fx = GetFather(x);
    int fy = GetFather(y);
    int r = relation[x] ^ relation[y];

    if(fx != fy)
    {
        father[fx] = fy;
        relation[fx] = r^1;
        return;
    }

    if(r==0)
        suspicious = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;

    for(int i=1; i<=T; ++i)
    {
        cout << "Scenario #" << i << ':' <<endl;
        cin >> N >> K;
        Init();
        int x,y;
        while(K--)
        {
            cin >> x >> y;
            Judge(x,y);
        }
        if(suspicious)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;

        if(i!=T)
            cout << endl;
    }
}
