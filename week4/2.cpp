#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 400008

struct Node
{
    int l,r;
    int pLeft, pRight;
    int mid;
    vector<int> q;
}st[MAXN];
int N,M;
int v;
int cnt = 1;

void buildTree(int rt, int l, int r)
{
    st[rt].l = l;
    st[rt].r = r;
    if( l == r )
    {
        int tmp;
        cin >> tmp;
        st[rt].q.push_back(tmp);
        return;
    }

    int mid = (l + r) >> 1;
    int pLeft = rt << 1;
    int pRight = pLeft + 1;
    st[rt].mid = mid;
    st[rt].pLeft = pLeft;
    st[rt].pRight = pRight;

    buildTree(pLeft, l, mid);
    buildTree(pRight, mid+1, r);

    int i=0, j=0;
    while(i < st[pLeft].q.size() && j < st[pRight].q.size())
    {
        if(st[pLeft].q[i] < st[pRight].q[j])
            st[rt].q.push_back(st[pLeft].q[i++]);
        else
            st[rt].q.push_back(st[pRight].q[j++]);
    }
    while(i < st[pLeft].q.size())
        st[rt].q.push_back(st[pLeft].q[i++]);
    while(j < st[pRight].q.size())
        st[rt].q.push_back(st[pRight].q[j++]);
}

int query(int rt, int l, int r)
{
    if(st[rt].l == l && st[rt].r == r)
    {
        auto lb = upper_bound(st[rt].q.begin(),st[rt].q.end(), v);
        return lb - st[rt].q.begin();
    }

    int mid = st[rt].mid;
    int pLeft = st[rt].pLeft;
    int pRight = st[rt].pRight;

    if(r <= mid)
    {
        return query(pLeft, l, r);
    }
    else if(l > mid)
    {
        return query(pRight, l, r);
    }
    else
    {
        return query(pLeft, l, mid) + query(pRight, mid+1, r);
    }
}

int kNumber(int a, int b, int k)
{
    int l=0;
    int r=N-1;
    int pos;
    int mid;
    while(l <= r)
    {
        mid = (l+r)>>1;
        v = st[1].q[mid];
        pos = query(1, a, b);
        if(pos>=k)
            r = mid-1;
        else
            l = mid + 1;
    }
    if(pos == k)
        return st[1].q[mid];
    else return st[1].q[mid+1];
}

void init()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    buildTree(1, 1, N);
}

void process()
{
    int l,r,k;
    while(M--)
    {
        cin >> l >> r >> k;
        cout << kNumber(l, r, k) << endl;
    }

}

int main()
{
    init();
    process();
}
