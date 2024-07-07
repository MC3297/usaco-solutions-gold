#pragma region
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int,int>;
#define vt vector
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...)
#endif
#define fi first
#define se second
#define pb push_back 
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define IMP cout << "IMPOSSIBLE" << '\n'
#define FOR(i,s,e) for (int i = (s); i < (e); ++i) 
#define F0R(i,e) FOR(i,0,e) 
#define ROF(i,s,e) for (int i = (e)-1; i >= (s); --i) 
#define R0F(i,e) ROF(i,0,e) 
#define printv(v,s,e) FOR(z,s,e+1) cout << v[z] << ' '; cout << '\n'
#define ir(...) int __VA_ARGS__; re(__VA_ARGS__);
#define pr(...) cout << (__VA_ARGS__) << '\n'
#define cmp(x,y) [&](auto&a,auto&b){return x a y<x b y;}
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void re(T &x) {cin >> x;}
template<class H, class... T> void re(H &h, T &...t) { re(h); re(t...); }
#pragma endregion

const int N = 1E5+1;
vt<int> adj[N];
int leafdist[N], ans;
void dfs1(int v, int p) {
    leafdist[v] = 1E9;
    for (int i: adj[v]) if (i != p) {
        dfs1(i,v);
        leafdist[v] = min(leafdist[v], leafdist[i]+1);
    }
    if (sz(adj[v]) == 1) leafdist[v] = 0;
}
void dfs2(int v, int p, int d) {
    if (leafdist[v] <= d) {
        ans++; return;
    }
    for (int i: adj[v]) if (i != p) {
        dfs2(i,v,d+1);
    }
}
void solve() {
    ir(n,k);
    F0R(i,n-1) {
        ir(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(k,0);
    dfs2(k,0,0);
    pr(ans);
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}