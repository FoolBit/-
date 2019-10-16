// 正匹配+反匹配
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define reset(a) memset(a, 0, sizeof(a))
using namespace std;

constexpr int MAXN = 5101000;
constexpr int LETTERS = 26;

struct MyString
{
    int len;
    char s[MAXN];
    int t[MAXN];

    int read(char* str, int &i)
    {
        int x=0;
        ++i;
        while(str[i]>='0'&&str[i]<='9' )
        {
            x = x*10+str[i]-'0';
            ++i;
        }
        return x;
    }

    void init(char* str)
    {
        int i=0;
        len = 0;
        while(str[i])
        {
            if(str[i]=='[')
            {
                t[len] = read(str, i);
                if(t[len]>1000)
                    t[len] = 1000;
                s[len] = str[i];
                ++i;
            }
            else
            {
                t[len] = 1;
                s[len] = str[i];
            }
            ++i;++len;
        }
    }
}codes;

int ch[250100][LETTERS];
int fail[250100];
int last[250100];
int badNode[250100];
int idx[250100];
int vis[252];
int cnt;
int N;
char str[MAXN];

void init()
{
    reset(ch);
    cnt = 0;
}

void Insert(char* s)
{
    int p = 0;
    for(int i=0; s[i]; ++i)
    {
        if(!ch[p][s[i]-'A' ])
        {
            ch[p][s[i]-'A' ] = ++cnt;
            fail[cnt] = 0;
            last[cnt] = 0;
            badNode[cnt] = 0;
            idx[cnt] = 0;
        }
        p = ch[p][s[i]-'A' ];
    }
    badNode[p] = 1;
    idx[p] = N;
    vis[N] = 0;
}

void BuildTrie()
{
    queue<int> q;
    for(int i=0; i<LETTERS; ++i)
        if(ch[0][i]) q.push(ch[0][i]);

    while(q.size())
    {
        int p = q.front();q.pop();
        for(int i=0; i<LETTERS; ++i)
        {
            if(ch[p][i])
            {
                fail[ch[p][i] ] = ch[fail[p]][i];
                q.push(ch[p][i]);
                if(badNode[fail[ch[p][i]]])
                    last[ch[p][i]] = fail[ch[p][i] ];
                else
                    last[ch[p][i] ] = last[fail[ch[p][i] ]];
            }
            else
                ch[p][i] = ch[fail[p]][i];
        }
    }
}

void readin()
{
    scanf("%d", &N);
    while(N)
    {
        scanf("%s", str);
        Insert(str);
        --N;
    }
    BuildTrie();
    scanf("%s", str);
    codes.init(str);
}

void Move(char c, int &p,int &sum)
{
    p = ch[p][c-'A'];
    int now = p;
    while(now)
    {
        sum += badNode[now];
        badNode[now] = 0;
        vis[idx[now]] = 1;
        now = last[now];
        if(vis[idx[now]])
            break;
    }
}

void Run()
{
    init();
    readin();

    int p = 0;
    int sum = 0;
    for(int i=0; i<codes.len; ++i)
    {
        for(int j=0; j<codes.t[i]; ++j)
        {
            Move(codes.s[i], p, sum);
        }
    }

    p = 0;
    for(int i=codes.len-1; i>=0; --i)
    {
        for(int j=0; j<codes.t[i]; ++j)
        {
            Move(codes.s[i], p, sum);
        }
    }
    printf("%d\n", sum);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
        Run();
}
