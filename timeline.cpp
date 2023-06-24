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
#define ROF(i,s,e) for (int i = (b)-1; i >= (a); --i) 
#define R0F(i,e) ROF(i,0,e) 
#define printv(v,s,e) FOR(i,s,e+1) cout << v[i] << ' '; cout << '\n'
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

void solve() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n,m,c; read(n,m,c);
    vector<int> indeg(n+1, 0);
    vector<ll> low(n); cin >> low;
    vector<pii> adj[n+1];
    F0R(i,c) {
        int a,b,w; read(a,b,w);
        adj[a].pb({b,w});
        indeg[b]++;
    }
    
    queue<int> q;
    FOR(i,1,n+1) {
        if (indeg[i] == 0) q.push(i);
    }
    
    while (sz(q)) {
        int v = q.front();
        q.pop();
        for (pii i: adj[v]) {
            low[i.fi-1] = max(low[i.fi-1], low[v-1]+i.se);
            indeg[i.fi]--;
            if (!indeg[i.fi]) q.push(i.fi);
        }
    }
    FOR(i,1,n+1) cout << low[i-1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}