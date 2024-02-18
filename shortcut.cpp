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
#define printv(v,s,e) FOR(i,s,e+1) cout << v[i] << ' '; cout << '\n'
#define read(...) int __VA_ARGS__; re(__VA_ARGS__);
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void re(T &x) {cin >> x;}
template<class H, class... T> void re(H &h, T &...t) { re(h); re(t...); }
#pragma endregion

void solve() {
    read(n,m,t);
    vt<int> cow(n+1);
    F0R(i,n) re(cow[i+1]);
    vt<pii> adj[n+1];
    F0R(i,m) {
        read(a,b,w);
        adj[a].pb({w,b});
        adj[b].pb({w,a});
    }

    vt<int> dist(n+1,1E9), parent(n+1,1E9);
    min_priority_queue<pii> pq;
    pq.push({0,1});
    dist[1] = 0;
    while (sz(pq)) {
        auto [d,v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        for (auto [w,i]: adj[v]) {
            if (dist[i] > d+w || (dist[i] == d+w && parent[i] > v)) {
                dist[i] = d+w;
                parent[i] = v;
                pq.push({d+w,i});
            }
        }
    }

    vt<vt<int>> tree(n+1);
    FOR(i,1,n+1) {
        if (parent[i] != 1E9) {
            tree[parent[i]].pb(i);
        }
    }
    
    int ans = 0;
    auto dfs = [&](int v, auto&& dfs) -> void {
        for (int i: tree[v]) {
            dfs(i,dfs);
            cow[v] += cow[i];
        }
        ans = max(ans, cow[v]*(dist[v]-t));
    };
    dfs(1,dfs);

    cout << ans << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}