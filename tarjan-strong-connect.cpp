/*****************************
tarjan-strong-connect   by GreatStone   2014.05.28

note:
    call init() before input the graph
    not correct when get cut-vectex

call:
    foreach u : (1 to n)
        tarjan(u)
******************************/

int n,m;
vector<int> vec[10010];
int pre[10010],low[10010];
int cnt,scnt;
int bl[10010];
stack<int> sta;
int out[10010];

int cmin (int a, int b)
{
    return a < b ? a : b;
}

int cmax (int a, int b)
{
    return a > b ? a : b;
}

void init ()
{
    int i;
    for (i = 0; i < 10010; i++)
    {
        vec[i].clear();
        pre[i] = low[i] = -1;
    }
    cnt = scnt = 0;
    while (!sta.empty())
    {
        sta.pop();
    }
    memset(out,0,sizeof(out));
}

void tarjan (int v)
{
    sta.push(v);
    int minc = low[v] = pre[v] = cnt++;
    vector<int>::iterator cur;
    cur = vec[v].begin();
    for (; cur != vec[v].end(); cur++)
    {
        if (pre[*cur] == -1)
        {
            tarjan (*cur);
        }
        if (minc > low[*cur])
        {
            minc = low[*cur];
        }
    }
    if (minc < low[v])
    {
        low[v] = minc;
        return;
    }
    int s = 0;
    while (1)
    {
        s++;
        bl[sta.top()] = v;
        low[sta.top()] = n+1;
        if (sta.top() == v)
        {
            sta.pop();
            break;
        }
        sta.pop();
    }
    scnt++;
}