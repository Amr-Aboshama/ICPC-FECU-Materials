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
int par[N], arr[N];
int findPar(int n)
{
    if (n == par[n])
        return n;
    return par[n] = findPar(par[n]);
}

void unionSet(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (v == u)
        return;
    par[u] = v;
    arr[v] += arr[u];
}
char in[25];

int main() 
{
    int t;
    sc(t);
    while (t--)
    {
        map<string, int> mp;
        int idx = 0;
        int n;
        sc(n);
        iota(par, par+2*n, 0);
        fill(arr, arr+2*n, 1);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", in);
            if (!mp.count(in))
                mp[in] = idx++;
            int u = mp[in];
            scanf("%s", in);
            if (!mp.count(in))
                mp[in] = idx++;
            int v = mp[in];
            unionSet(u, v);
            printf("%d\n", arr[findPar(u)]);
        }
        
    }
    
    
    return 0;
}