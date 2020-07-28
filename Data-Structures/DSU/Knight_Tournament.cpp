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
const int oo = 1e9;
const ll MOD = 1e9+7;

const int N = 3e5+5;
int par[N], ans[N];
int findPar(int n)
{
    if (n == par[n])
        return n;
    return par[n] = findPar(par[n]);
}

void link(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (v == u)
        return;
    par[u] = v;
}

int main() 
{
    int n, m;    
    scanf("%d%d", &n, &m);

    iota(par, par+n+1, 0);
    while (m--)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--, r--, x;
        for (int i = findPar(l); i <= r; )
        {
            if (x-1 != i)
            {
                ans[i] = x;
                link(i, i+1);
                i = findPar(i);
            }
            else
                i = findPar(i+1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    
    return 0;
}