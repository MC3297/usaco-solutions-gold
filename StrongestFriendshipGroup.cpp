#pragma region
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int,int>;
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
#define re(...) int __VA_ARGS__; read(__VA_ARGS__);
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }
#pragma endregion

struct DSU {
    //* stuff are totally optional
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

const int N = 1E5+1;
vector<int> adj[N];
void solve() {
    re(n,m);
    F0R(i,m) {
        re(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> deg(n+1);
    FOR(i,1,n+1) deg[i] = sz(adj[i]);
    vector<bool> used(n+1,0);
    vector<pii> vertex;
    
    set<pii> s;
    FOR(i,1,n+1) s.insert({deg[i], i});
    while (sz(s)) {
        auto [d,v] = *s.begin();
        s.erase(s.begin());
        vertex.pb({d,v});
        used[v] = 1;

        for (int i: adj[v]) {
            if (!used[i]) {
                s.erase({deg[i], i});
                deg[i]--;
                s.insert({deg[i], i});
            }
        }
    }
    
    reverse(all(vertex));
    debug(vertex);
    used.assign(n+1,0);
    DSU dsu(n);
    int mx = 1, ans = 0;
    for (auto [d,v]: vertex) {
        used[v] = 1;
        for (int i: adj[v]) {
            if (used[i]) {
                dsu.unite(v, i);
                mx = max(mx, dsu.get_size(v));
            }
        }
        ans = max(ans, mx*d);
    }
    cout << ans << '\n';
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