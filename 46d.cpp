#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int l,b,f;
int n;

typedef struct node {
  int l,r;
  int car;
  int ln,rn;
}node;

node tree[400000];

int m (int l, int r)
{
  return (l + r) / 2;
}

void build (int root, int l, int r)
{
  tree[root].l = l;
  tree[root].r = r;
  tree[root].car = 0;
  tree[root].ln = tree[root].rn = r - l + 1;
  int mid = m(l,r);
  if (l == r)
    return;
  else
    {
      build(root*2,l,mid);
      build (root*2+1,mid+1,r);
    }
}

int query (int root, int l, int r, int len, int car)
{
  if (tree[root].car != -1 && tree[root].car != 0)
    {
      return -1;
    }
  if (tree[root].car == 0 && tree[root].r - tree[root].l + 1 >= len)
    {
      return l;
    }
}

int main ()
{
  scanf("%d%d%d",&l,&b,&f);
  scanf("%d",&n);
  int com,a;
  int i;
  for (i = 0; i < n; i++)
    {
      scanf("%d%d",&com,&a);
    }
  return 0;
}
