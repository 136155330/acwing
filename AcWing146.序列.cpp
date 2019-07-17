#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int t, n, m;
const int MAXN = 2005;
ll arr[MAXN][MAXN];
vector<ll> vec;
map<pair<int, int>, int> M;
void Init()
{
    memset(arr, 0, sizeof(arr));
    vec.clear();
    M.clear();
}
struct node
{
    int i, j;
    ll data;
    friend bool operator<(const node &a, const node &b)
    {
        return a.data > b.data;
    }
};
void solve(int j)
{
    priority_queue<node> que;
    while (!que.empty())
    {
        que.pop();
    }
    vec.clear();
    node be;
    be.i = 0;
    be.j = 0;
    be.data = arr[0][be.i] + arr[j][be.j];
    M.clear();
    M[make_pair(be.i, be.j)] = 1;
    que.push(be);
    while (!que.empty())
    {
        if (vec.size() == n)
            break;
        node en = que.top();
        que.pop();
        vec.push_back(en.data);
        node ends;
        ends.i = en.i + 1;
        ends.j = en.j;
        ends.data = arr[0][ends.i] + arr[j][ends.j];
        if (M[make_pair(ends.i, ends.j)] == 0)
        {
            M[make_pair(ends.i, ends.j)] = 1;
            que.push(ends);
        }
        ends.i = en.i;
        ends.j = en.j + 1;
        ends.data = arr[0][ends.i] + arr[j][ends.j];
        if (M[make_pair(ends.i, ends.j)] == 0)
        {
            M[make_pair(ends.i, ends.j)] = 1;
            que.push(ends);
        }
    }
    for(int i = 0; i < n; i ++){
        arr[0][i] = vec[i];
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        Init();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%lld", &arr[i][j]);
            }
        }
        for(int i = 0; i < m; i ++){
            sort(arr[i], arr[i] + n);
        }
        for(int i = 1; i < m; i ++){
            solve(i);
        }
        for(int i = 0; i < n; i ++){
            printf("%lld ", arr[0][i]);
        }
        printf("\n");
    }
    return 0;
}