/***********************************
cut-vertex-tarjan      by GreatStone   2014.05.28

note:
    call init() before input the graph
    after tarjan, do step that res++ if root > 1.

call:
    tarjan(1); // use the first node as the root node in tarjan
************************************/

int n;
vector<int> gra[110];
int pre[110],low[110],is[110];
int cnt;
int res;
int root;

int cmin (int a, int b)
{
    return a < b ? a : b;
}

void init ()
{
    int i;
    for (i = 0; i < 110; i++)
    {
        gra[i].clear();
        pre[i] = low[i] = -1;
    }
    root = 0;
    cnt = 0;
    res = 0;
    memset(is,0,sizeof(is));
}

void tarjan (int v)
{
    pre[v] = low[v] = cnt++;
    vector<int>::iterator it;
    for (it = gra[v].begin(); it != gra[v].end(); it++)
    {
        if (pre[*it] == -1)
        {
            tarjan (*it);

            if (low[*it] >= pre[v] && v!= 1)
            {
                is[v]++;
                //v is an cut-vertex
            }
            else if (v == 1)
            {
                root++;
            }
            low[v] = cmin (low[*it],low[v]);
        }
        else
        {
            low[v] = cmin (pre[*it],low[v]);
        }
    }
    if (low[v] < pre[v])
    {
        return;
    }
}