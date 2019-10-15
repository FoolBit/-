#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

constexpr int LETTERS = 26;
constexpr int MAXN = 120003;

struct Node
{
    int childs[LETTERS];
    int fail;
    bool badNode;
    Node()
    {
        memset(childs, 0, sizeof(childs));
        fail = 0;
        badNode = 0;
    }
}Tree[MAXN];

int n,m;
int cnt;
char str[10002];

void Insert(char* s)
{
    int p = 0;
    for(int i=0; s[i]; ++i)
    {
        if(!Tree[p].childs[s[i]-'a'])
        {
            Tree[p].childs[s[i]-'a'] = ++cnt;
        }
        p = Tree[p].childs[s[i]-'a'];
    }
    Tree[p].badNode = 1;
}

void BuildDfa()
{
    queue<int> q;
    for(int i=0; i<LETTERS; ++i)
    {
        if(Tree[0].childs[i])
        {
            //Tree[Tree[0].childs[i]].fail = 0;
            q.push(Tree[0].childs[i]);
        }
    }

    while(q.size())
    {
        int p = q.front();q.pop();
        for(int i=0; i<LETTERS; ++i)
        {
            int child = Tree[p].childs[i];
            if(child)
            {
                Tree[child].fail = Tree[Tree[p].fail].childs[i];
                if(Tree[Tree[child].fail].badNode)
                    Tree[child].badNode = 1;
                q.push(child);
            }
            else
                Tree[p].childs[i] = Tree[Tree[p].fail].childs[i];
        }
    }
}

bool Query(char* s)
{
    int p = 0;
    for(int i=0; s[i]; ++i)
    {
        p = Tree[p].childs[s[i]-'a'];
        if(Tree[p].badNode)
            return 1;
    }
    return 0;
}

void init()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", str);
        Insert(str);
    }
    BuildDfa();
}

void run()
{
    scanf("%d",&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%s", str);
        if(Query(str))
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    init();
    run();
}