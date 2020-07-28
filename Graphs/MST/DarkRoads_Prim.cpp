#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &(x))
#define sclld(x) scanf("%lld", &(x))
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define MT make_tuple
#define MP make_pair
#define lastOne(x) (31 - __builtin_clz(x))
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl

typedef long long ll;
typedef pair<int, int> ii;
const double PI = 2*acos(0); 
const double EPS =  1e-9;
const int oo = 2e9;
const ll MOD = 1e9+7;

const int N = 2e5+5;
vector<ii> adj[N];
int prim(int st);
bool vis[N];

int main() 
{
    while (1)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (!n)
            break;
        for (int i = 0; i < n; i++)
            adj[i].clear();
        fill(vis, vis+n, 0);

        int total = 0;
        while (m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            total += w;
        }
        printf("%d\n", total-prim(0));
    }
    return 0;
}

int prim(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, st});
    int cost = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (vis[u])
            continue;
        cost += w;
        vis[u] = 1;
        for (auto& v: adj[u])
        {
            if (!vis[v.first])
                pq.push({v.second, v.first});
        }
    }
    return cost;
}