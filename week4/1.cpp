// Bind update & query
// So confusing
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


struct Poster
{
    int l,r;
}posters[10002];

int seg[20008];
int ans;
int N,cnt;

struct Node
{
    int l,r;
    bool covered;
    int pLeft,pRight;

    int mid()
    {
        return seg[(l+r)>>1];
    }

}st[80008];

void buildTree(int rt, int l, int r)
{
    st[rt].l = l;
    st[rt].r = r;
    st[rt].covered = 0;
    if(l == r)
        return;

    int mid = (l+r)>>1;
    int pLeft = rt << 1;
    int pRight = pLeft+1;
    st[rt].pLeft = pLeft;
    st[rt].pRight = pRight;

    buildTree(pLeft, l, mid);
    buildTree(pRight, mid+1, r);
}

int query(int rt, int l, int r)
{
    if(st[rt].covered)
        return 1;
    if(seg[st[rt].l] == l && seg[st[rt].r] == r)
    {
        int covered = st[rt].covered;
        st[rt].covered = 1;
        return covered;
    }

    int midIdx = (st[rt].l+st[rt].r)>>1;
    int midValue = st[rt].mid();
    int pLeft = st[rt].pLeft;
    int pRight = st[rt].pRight;

    if(r <= midValue)
    {
        int covered = query(pLeft, l, r);
        st[rt].covered = st[pLeft].covered && st[pRight].covered;
        return covered;
    }
    else if(l > midValue)
    {
        int covered = query(pRight, l, r);
        st[rt].covered = st[pLeft].covered && st[pRight].covered;
        return covered;
    }
    else
    {
        int coveredL = query(pLeft, l, midValue);
        int coveredR = query(pRight, seg[midIdx+1], r);
        st[rt].covered = st[pLeft].covered && st[pRight].covered;
        return coveredL && coveredR;
    }
}

void init()
{
    cin >> N;
    cnt = 1;
    for(int i=0; i<N; ++i)
    {
        cin >> posters[i].l >> posters[i].r;
        seg[cnt++] = posters[i].l;
        seg[cnt++] = posters[i].r;
    }
    seg[cnt] = -1;
    sort(seg+1, seg+cnt);
    unique(seg+1, seg+cnt);
    cnt = 1;
    while(seg[cnt]<seg[cnt+1])
        ++cnt;
    buildTree(1, 1, cnt);
}

void process()
{
    ans = 0;
    for(int i=N-1; i>=0; --i)
    {
        ans += (1-query(1, posters[i].l, posters[i].r));
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);

    int c;
    cin >> c;
    while(c--)
    {
        init();
        process();
    }
}
