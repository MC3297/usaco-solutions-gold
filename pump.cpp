#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
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

#define cost se.fi
#define flow se.se
void solve() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int n,m; read(n,m);
    vector<pair<int,pii>> adj[n+1];
    vector<pair<pii,pii>> edges;
    F0R(i,m) {
        int a,b,c,f; read(a,b,c,f);
        adj[a].pb({b,{c,f}});
        adj[b].pb({a,{c,f}});
        edges.pb({{a,b},{c,f}});
    }
    double ans = 0;
    for (auto e: edges) {
        vector<int> dist(n+1, INT_MAX);
        min_priority_queue<pii> pq;
        pq.push({0,e.fi.fi});
        pq.push({0,e.fi.se});
        while (sz(pq)) {
            int w = pq.top().fi;
            int v = pq.top().se;
            pq.pop();
            dist[v] = min(dist[v], w);
            for (auto i: adj[v]) {
                if (i.flow >= e.flow && dist[i.fi] > w+i.cost) {
                    dist[i.fi] = w+i.cost;
                    pq.push({w+i.cost, i.fi});
                }
            }
        }
        if (dist[1] != INT_MAX && dist[n] != INT_MAX) {
            ans = max(ans, (double)(e.flow)/(dist[1]+dist[n]+e.cost));
        }
    }
    cout << (int)(ans*1E6) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}