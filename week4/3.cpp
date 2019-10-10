#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10003

struct Point
{
    int v, idx;
    void setPoint(int v_, int idx_)
    {
        v = v_;
        idx = idx_;
    }
    bool operator < (const Point& a) const
    {
        return v < a.v;
    }
}xPoints[MAXN], yPoints[MAXN];

int idxHash[MAXN];
int seg[MAXN];

struct Line
{
    int pos, l, r;
    int type;
    void setLine(int pos_, int l_, int r_, int type_)
    {
        pos = pos_;
        l = l_;r = r_;
        type = type_;
    }

    bool operator < (const Line& a) const
    {
        if(pos == a.pos)
            return type > a.type;
        return pos < a.pos;
    }

}vLines[MAXN], hLines[MAXN];
int nLines;
int N;
int perimeter;

struct Node
{
    int l, r;
    int mid;
    int pLeft, pRight;
    int sum; // 当前值
    int covered;
    int len; // 该区间的实际值
}st[MAXN*4];

void buildTree(int rt, int l, int r)
{
    st[rt].l = l;
    st[rt].r = r;
    st[rt].covered = 0;
    st[rt].sum =0;
    if(l == r)
    {
        st[rt].len = seg[l];
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

    st[rt].len = st[pLeft].len + st[pRight].len;
}

void update(int rt, int l, int r, int delta)
{
    int pLeft = st[rt].pLeft;
    int pRight = st[rt].pRight;
    if(st[rt].l == l && st[rt].r == r)
    {
        st[rt].covered += delta;
        if(st[rt].covered)
        {
            st[rt].sum = st[rt].len;
        }
        else
        {
            if(l == r)
                st[rt].sum = 0;
            else
                st[rt].sum = st[pLeft].sum + st[pRight].sum;
        }
        return;
    }

    int mid = st[rt].mid;
    if(r <= mid)
    {
        update(pLeft, l, r, delta);
    }
    else if(l > mid)
    {
        update(pRight, l, r, delta);
    }
    else
    {
        update(pLeft, l, mid, delta);
        update(pRight, mid+1, r, delta);
    }

    if(!st[rt].covered)
        st[rt].sum = st[pLeft].sum + st[pRight].sum;
}

void init()
{
    int x1, y1, x2, y2;
    int idx = 1;

    scanf("%d", &N);

    for(int i=1; i<=N; ++i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        vLines[idx].setLine(x1, idx, idx+1, 1);
        vLines[idx+1].setLine(x2, idx, idx+1, -1);

        hLines[idx].setLine(y1, idx, idx+1, 1);
        hLines[idx+1].setLine(y2, idx, idx+1, -1);

        xPoints[idx].setPoint(x1, idx);
        xPoints[idx+1].setPoint(x2, idx+1);

        yPoints[idx].setPoint(y1, idx);
        yPoints[idx+1].setPoint(y2, idx+1);

        idx += 2;
    }

    sort(vLines+1, vLines+idx);
    sort(hLines+1, hLines+idx);
    sort(xPoints+1, xPoints+idx);
    sort(yPoints+1, yPoints+idx);
    nLines = N << 1;
}

int  discrete(Point *points)
{
    int ub = nLines;
    int cnt = 0;
    idxHash[points[1].idx] = ++cnt;
    for(int i=2; i<=ub; ++i)
    {
        if(points[i].v == points[i-1].v)
            idxHash[points[i].idx] = cnt;
        else
        {
            seg[cnt] = points[i].v - points[i-1].v;
            idxHash[points[i].idx] = ++cnt;
        }

    }
    return cnt-1;
}

void process()
{
    int lastValue = 0;
    int newValue = 0;
    int l,r;
    int nSeg;

    // 竖线对应yPOints
    nSeg = discrete(yPoints);
    buildTree(1, 1, nSeg);
    for(int i=1; i<=nLines; ++i)
    {
        l = idxHash[vLines[i].l];
        r = idxHash[vLines[i].r] - 1;
        update(1, l, r, vLines[i].type);
        newValue = st[1].sum;
        perimeter += abs(newValue - lastValue);
        lastValue = newValue;
    }

    // 横线对应xPoints
    nSeg = discrete(xPoints);
    buildTree(1, 1, nSeg);
    for(int i=1; i<=nLines; ++i)
    {
        l = idxHash[hLines[i].l];
        r = idxHash[hLines[i].r] - 1;
        update(1, l, r, hLines[i].type);
        newValue = st[1].sum;
        perimeter += abs(newValue - lastValue);
        lastValue = newValue;
    }

    printf("%d", perimeter);
}

int main()
{
    init();
    process();
}

