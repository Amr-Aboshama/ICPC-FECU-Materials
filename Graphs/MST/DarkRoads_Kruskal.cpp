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
int par[N];
int findSet(int n)
{
    if (n == par[n])
        return n;
    return par[n] = findSet(par[n]);
}

bool unionSet(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if (u == v)
        return false;
    par[u] = v;
    return true;
}

struct Edge
{
    int u, v, w;
    Edge(int pu = 0, int pv = 0, int pw = 0)
    {
        u = pu, v = pv, w = pw;
    }
    bool operator < (const Edge& b)
    {
        return w < b.w;
    }
};

int main() 
{
    while (1)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (!n)
            break;
        
        iota(par, par+n, 0);
        int total = 0;
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }
        
        sort(all(edges));
        int cost = 0;
        for (int i = 0; i < m; i++)
            if (unionSet(edges[i].u, edges[i].v))
                cost += edges[i].w;
        
        printf("%d\n", total-cost);
    }
    return 0;
}
