#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50002

int f[MAX];
int cnt;
int getRoot(int x)
{
    if(f[x]==-1)
        return x;
    f[x] = getRoot(f[x]);
    return f[x];
}

void pull(int x,int y)
{
    int fx = getRoot(x);
    int fy = getRoot(y);
    if(fx == fy)
        cout << "Yes" << endl;
    else
    {
        --cnt;
        cout << "No" << endl;
        f[fy] = fx;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m)
    {
        cnt = n;
        memset(f,-1,sizeof(f));
        int x,y;
        while(m--)
        {
            cin >> x >> y;
            pull(x,y);
        }
        cout << cnt << endl;
        for(int i=1; i<=n; ++i)
        {
            if(f[i]==-1)
                cout << i << ' ';
        }
        cout << endl;
    }
}