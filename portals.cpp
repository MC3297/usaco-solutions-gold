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


struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1, -1);
        size.resize(n+1, 0);
        for (int i = 0; i < n+1; i++) make(i);
    }
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int get_size(int v) {
        return size[find(v)];
    }
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
    ir(n);
    vt<array<int,5>> p(n);
    vt<vt<int>> e(2*n+1);
    vt<bool> vis(2*n+1);
    F0R(i,n) {
        ir(x,a,b,c,d);
        p[i] = {x,a,b,c,d};
        e[a].pb(b);
        e[b].pb(a);
        e[c].pb(d);
        e[d].pb(c);
    }
    sort(all(p));

    DSU dsu(2*n);
    FOR(i,1,2*n+1) if (!vis[i]) {
        vis[i] = 1;
        int cur = e[i][0];
        while (1) {
            vis[cur] = 1;
            dsu.unite(i, cur);
            if (!vis[e[cur][0]]) cur = e[cur][0];
            else if (!vis[e[cur][1]]) cur = e[cur][1];
            else break;
        }
    }

    int ans = 0;
    for (auto [x,a,b,c,d]: p) {
        if (dsu.find(a) != dsu.find(c)) {
            dsu.unite(a,c);
            ans += x;
        }
    }
    pr(ans);
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}