#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int,int>;
#ifndef LOCAL
#define debug(...)
#endif
#define fi first
#define se second
#define pb push_back 
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define IMP cout << "IMPOSSIBLE" << '\n'
#define FOR(i,s,e) for (int i = (s); i < (e); ++i) 
#define F0R(i,e) FOR(i,0,e) 
#define ROF(i,s,e) for (int i = (e)-1; i >= (s); --i) 
#define R0F(i,e) ROF(i,0,e) 
#define printv(v,s,e) FOR(i,s,e+1) cout << v[i] << ' '; cout << '\n'
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

const int N = 1E5+1, mod = 1E9+7;
int color[N], ways[N][4], pa[N], in[N];
vector<int> adj[N];
void dfs(int v, int p) {
    pa[v] = p;
    in[p]++;
    for (int i: adj[v]) if (i != p) {
        dfs(i,v);
    }
}
void solve() {
    int n,k; read(n,k);
    F0R(i,n-1) {
        int a,b; read(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    F0R(i,k) {
        int a,b; read(a,b);
        color[a] = b;
    }
    FOR(i,1,n+1) {
        if (pa[i] == 0) {
            dfs(i,0);
        }
    }
    int ans = 0;
    queue<int> q;
    FOR(i,1,n+1) if (!in[i]) q.push(i);
    while (sz(q)) {
        int v = q.front();
        q.pop();
        ways[v][1] = ways[v][2] = ways[v][3] = 1;
        for (int i: adj[v]) if (i != pa[v]) {
            ways[v][1] *= ways[i][2]+ways[i][3];
            ways[v][2] *= ways[i][1]+ways[i][3];
            ways[v][3] *= ways[i][1]+ways[i][2];
            FOR(j,1,4) ways[v][j] %= mod;
        }
        if (color[v] != 0) {
            FOR(j,1,4) if (j != color[v]) ways[v][j] = 0;
        }
        if (!pa[v] && v != 0) ans = (ans+ways[v][1]+ways[v][2]+ways[v][3])%mod;
        in[pa[v]]--;
        if (!in[pa[v]]) q.push(pa[v]);
    }
    cout << ans << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}