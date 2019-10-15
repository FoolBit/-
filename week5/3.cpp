#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

constexpr int MAXN = 30003;
constexpr int LETTERS = 2;

struct Node
{
    int ch[LETTERS];
    int fail;
    int badNode;
    Node()
    {
        memset(ch, 0, sizeof(ch));
        fail = 0;
        badNode = 0;
    }
}Tree[MAXN];

char s[MAXN];
int n;
int vis[MAXN];
int cnt;

void Insert()
{
    int p = 0;
    for(int i=0; s[i]; ++i)
    {
        if(!Tree[p].ch[s[i]-'0'])
            Tree[p].ch[s[i]-'0'] = ++cnt;
        p = Tree[p].ch[s[i]-'0'];
    }
    Tree[p].badNode = 1;
}

void BuildTrie()
{
    queue<int > q;

    for(int i=0; i<LETTERS; ++i)
        if(Tree[0].ch[i])
            q.push(Tree[0].ch[i]);

    while(q.size())
    {
        int p = q.front(); q.pop();

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

bool dfs(int root)
{
    if(vis[root])
        return 1;
    if(Tree[root].badNode)
        return 0;

    vis[root] = 1;
    for(int i=0; i<LETTERS; ++i)
        if(dfs(Tree[root].ch[i])) return 1;

    vis[root] = 0;
    return 0;
}

void init()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", s);
        Insert();
    }
    BuildTrie();
}

void run()
{
    if(dfs(0))
        printf("TAK");
    else
        printf("NIE");
}

int main()
{
    init();
    run();
}
