#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1005;
constexpr int LETTERS = 4;
constexpr int INF = 0x3f3f3f3f;

inline int idx(char c)
{
    if(c == 'A')
        return 0;
    if(c == 'T')
        return 1;
    if(c == 'C')
        return 2;
    return 3;
}

struct Node
{
    int ch[LETTERS];
    int fail;
    int badNode;
}Tree[MAXN];

int N;
int cnt;
char s[MAXN];
int dp[MAXN][MAXN];

void Insert()
{
    int p = 0;
    for(int i=0; s[i]; ++i)
    {
        if(!Tree[p].ch[idx(s[i])])
            Tree[p].ch[idx(s[i])] = ++cnt;
        p = Tree[p].ch[idx(s[i])];
    }
    Tree[p].badNode = 1;
}

void BuildTrie()
{
    queue<int> q;

    for(int i=0; i<LETTERS; ++i)
        if(Tree[0].ch[i]) q.push(Tree[0].ch[i]);

    while(q.size())
    {
        int p = q.front();q.pop();
        for(int i=0; i<LETTERS; ++i)
        {
            int child = Tree[p].ch[i];
            if(child)
            {
                Tree[child].fail = Tree[Tree[p].fail].ch[i];
                if(Tree[Tree[child].fail].badNode)
                    Tree[child].badNode = 1;
                q.push(child);
            }
            else
                Tree[p].ch[i] = Tree[Tree[p].fail].ch[i];
        }
    }
}

int Solve()
{
    memset(dp, INF, sizeof(dp));

    dp[0][0] = 0;
    int l = strlen(s);
    for(int i=0; i<l; ++i)
    {
        for(int j=0; j<=cnt; ++j)
        {
            if(Tree[j].badNode)
                continue;
            if(dp[i][j]>=INF)
                continue;

            for(int k=0; k<LETTERS; ++k)
            {
                int p = Tree[j].ch[k];
                if(Tree[p].badNode)
                    continue;
                dp[i+1][p] = min(dp[i+1][p], dp[i][j]+int(idx(s[i])!=k));
            }
        }
    }

    int MIN = INF;
    for(int i=0; i<=cnt; ++i)
        MIN = min(MIN, dp[l][i]);

    if(MIN>=INF)
        return -1;
    return MIN;
}

void Init()
{
    memset(Tree, 0, sizeof(Tree));
    cnt = 0;
    while(N--)
    {
        scanf("%s", s);
        Insert();
    }
    BuildTrie();
    scanf("%s", s);
}

void Run()
{
    int num = 0;
    while(scanf("%d", &N)&&N)
    {
        ++num;
        Init();
        printf("Case %d: %d\n",num, Solve());
    }
}

int main()
{
    Run();
}
