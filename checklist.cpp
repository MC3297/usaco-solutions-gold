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

const int N = 1E3+1;
pii dp[N][N];
//dp[i][j].fi: cost to tour first i hols, first j guers, end in hol
//dp[i][j].se: cost to tour first i hols, first j guers, end in guer
int dist(pii a, pii b) {
    return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se);
}
void solve() {
    int n,m; read(n,m);
    vector<pii> h(n+1), g(m+1);
    FOR(i,1,n+1) cin >> h[i];
    FOR(i,1,m+1) cin >> g[i];

    F0R(i,n+1) F0R(j,m+1) dp[i][j] = {INT_MAX,INT_MAX};
    dp[1][0].fi = 0;
    FOR(i,2,n+1) 
        dp[i][0].fi = dp[i-1][0].fi + dist(h[i],h[i-1]);

    FOR(i,1,n+1) {
        FOR(j,1,m+1) {
            // H -> H, G -> H
            dp[i][j].fi = min(dp[i][j].fi, min(dp[i-1][j].fi+dist(h[i],h[i-1]), dp[i-1][j].se+dist(h[i],g[j])));
            // H -> G, G -> G
            dp[i][j].se = min(dp[i][j].se, min(dp[i][j-1].fi+dist(h[i],g[j]), dp[i][j-1].se+dist(g[j],g[j-1])));
        }
    }
    cout << dp[n][m].fi << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}