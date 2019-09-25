#include <iostream>

using namespace std;

#define MAX 100002


struct Node
{
    int L,R;
    int sum;
    int lChild, rChild;
    int mid;
    int half();
};

int N;
Node tree[MAX*4];
int cows[MAX];

int Node::half()
{
    return tree[lChild].sum;
}

void Build(int root,int L, int R)
{
    tree[root].L = L;
    tree[root].R = R;
    tree[root].sum = R - L + 1;
    if(L == R)
    {
        return;
    }

    tree[root].lChild = (root << 1) + 1;
    tree[root].rChild = tree[root].lChild + 1;

    tree[root].mid = (L + R) >> 1;

    Build(tree[root].lChild, L, tree[root].mid);
    Build(tree[root].rChild, tree[root].mid+1, R);
}

int GetRank(int root, int p)
{
    if(tree[root].L == tree[root].R)
    {
        tree[root].sum = 0;
        return tree[root].L;
    }

    tree[root].sum -= 1;

    int half = tree[root].half();
    if(p <= half)
    {
        return GetRank(tree[root].lChild, p);
    }
    else
    {
        return GetRank(tree[root].rChild, p-half);
    }
}

void init()
{
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i=1; i<N; ++i)
        cin >> cows[i];
}

void process()
{
    for(int i=N-1; i>=0; --i)
        cows[i] = GetRank(0, cows[i]+1);
}

void print()
{
    for(int i=0; i<N; ++i)
        cout << cows[i] << endl;
}

int main()
{
    init();
    Build(0, 1, N);
    process();
    print();
}
