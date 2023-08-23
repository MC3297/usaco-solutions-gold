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

const int N = 1E5+10;
int dist[N];
void solve() {
    int n,sx,sy,ex,ey; read(n,sx,sy,ex,ey);
    vector<pii> stor(n+1);
    FOR(i,1,n+1) cin >> stor[i];
    stor[0] = {sx,sy};
    stor.pb({ex,ey});
    map<int,vector<int>> x,y;
    FOR(i,1,n+2) {
        x[stor[i].fi].pb(i);
        y[stor[i].se].pb(i);
    }
    fill(dist,dist+N,INT_MAX);
    
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (sz(q)) {
        int v = q.front();
        q.pop();
        for (int i: x[stor[v].fi]) {
            if (dist[i] > dist[v]+1) {
                dist[i] = dist[v]+1;
                q.push(i);
            }
        }
        for (int i: y[stor[v].se]) {
            if (dist[i] > dist[v]+1) {
                dist[i] = dist[v]+1;
                q.push(i);
            }
        }
        x[stor[v].fi].clear();
        y[stor[v].se].clear();
    }
    cout << dist[n+1]-1 << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}