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

void dijkstra(vt<vt<pii>>& adj, vt<int>& dist, int n) {
    min_priority_queue<pii> pq;
    pq.push({0,n});
    dist[n] = 0;
    while (sz(pq)) {
        auto [d,v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        for (auto [w,i]: adj[v]) {
            if (d+w < dist[i]) {
                dist[i] = d+w;
                pq.push({d+w,i});
            }
        }
    }
}
void solve() {
    read(n,m,k);
    vt<vt<pii>> adj(n+1), adj2(n+1);
    F0R(i,m) {
        read(a,b,w);
        adj[a].pb({w,b});
        adj[b].pb({w,a});
    }
    vt<pii> haybale(k);
    re(haybale);

    vt<int> distA(n+1,1E9), distB(n+1,1E9);
    dijkstra(adj, distA, n);
    //delete nodes to N, make edges to N from haybale
    for (auto [v,y]: haybale) {
        adj[0].pb({distA[v]-y,v});
    }
    dijkstra(adj, distB, 0);
    debug(distA);
    debug(distB);
    FOR(i,1,n) cout << (distB[i] <= distA[i]) << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}