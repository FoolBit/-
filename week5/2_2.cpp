//pattern 插入两次
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define miku(s) s-'A'
#define reset(a) memset(a, 0, sizeof(a))

constexpr int MAXN = 500010;
constexpr int LETTERS = 26;

int ch[MAXN][LETTERS];
int fail[MAXN];
int last[MAXN];
int badNode[MAXN];
int idx[MAXN];
int vis[260];
int N;
int cnt;
char str[5100100];

void Init()
{
    reset(ch);
    cnt = 0;
}

void rev(char* s)
{
    int len = strlen(s);
    --len;
    char c;
    int i=0;
    while(i < len)
    {
        c = s[i];
        s[i] = s[len];
        s[len] = c;
        ++i;--len;
    }
}

bool Insert(char *s)
{
    int p = 0;
    for(int i=0; s[i]; ++i)
    {
        if(!ch[p][miku(s[i])])
        {
            ch[p][miku(s[i])] = ++cnt;
            last[cnt] = 0;
            fail[cnt] = 0;
            badNode[cnt] = 0;
            idx[cnt] = 0;
        }
        p = ch[p][miku(s[i])];
    }
    badNode[p] = 1;
    vis[N] = 0;
    if(idx[p])
    {
        idx[p] = N;
        return 0;
    }
    idx[p] = N;
    return 1;
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
                fail[ch[p][i]] = ch[fail[p]][i];
                q.push(ch[p][i]);
                if(badNode[fail[ch[p][i]]])
                    last[ch[p][i]] = fail[ch[p][i]];
                else
                    last[ch[p][i]] = last[fail[ch[p][i]]];
            }
            else
                ch[p][i] = ch[fail[p]][i];
        }
    }
}

void Read()
{
    scanf("%d", &N);
    while(N)
    {
        scanf("%s", str);
        if(Insert(str))
            rev(str),Insert(str);
        --N;
    }
    BuildTrie();
    scanf("%s", str);
}

int Move(char c, int &p)
{
    p = ch[p][miku(c)];
    int now = p;
    int sum = 0;
    while(now)
    {
        if(!vis[idx[now]])
        {
            sum += badNode[now];
            vis[idx[now]] = 1;
            badNode[now] = 0;
        }
        else if(idx[now]&&!badNode[now])
            break;
        now = last[now];
    }
    return sum;
}

int getNum(char*s, int &i)
{
    ++i;
    int x = 0;
    while(s[i]>='0' && s[i]<='9')
    {
        x = x*10 + s[i]-'0';
        ++i;
    }
    return x;
}

void Process(char *s)
{
    int sum = 0;
    int p = 0;
    int i = 0;
    while(s[i])
    {
        if(s[i] == '[')
        {
            int q = getNum(s, i);
            if(q>1000)
                q = 1000;
            while(q--)
                sum += Move(s[i], p);
            ++i;
        }
        else
            sum += Move(s[i], p);
        ++i;
    }
    printf("%d\n", sum);
}

void Run()
{
    Init();
    Read();
    Process(str);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
        Run();
}