#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1100

int a[MAX][MAX];
int C[MAX][MAX];
int S;

inline int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y,int delta)
{
    int row = y;
    while(x<=S)
    {
        y = row;
        while(y<=S)
        {
            C[x][y] += delta;
            y += lowbit(y);
        }
        x += lowbit(x);
    }
}

int query(int x, int y)
{
    if(x < 0 || y < 0)
        return 0;

    int sum = 0;
    int row = y;

    while(x>0)
    {
        y = row;
        while(y>0)
        {
            sum += C[x][y];

            if(!y)
                break;
            y -= lowbit(y);
        }
        if(!x)
            break;
        x -= lowbit(x);
    }

    return sum;
}

int getResult(int l,int b,int r,int t)
{
    // down right
    int s1 = query(r,t);
    // top left
    int s2 = query(l-1, b-1);
    // top right
    int s3 = query(l-1, t);
    // down left
    int s4 = query(r, b-1);

    return s1 + s2 - s3 - s4;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> S >> S;

    int ins;
    int X,Y,A;
    int L,B,R,T;
    while(1)
    {
        cin >> ins;
        if(ins == 1)
        {
            cin >> X >> Y >> A;
            update(X+1,Y+1,A);
        }
        else if(ins == 2)
        {
            cin >> L >> B >> R >> T;
            cout << getResult(L+1,B+1,R+1,T+1) << endl;
        }
        else
        {
            break;
        }
    }
}
