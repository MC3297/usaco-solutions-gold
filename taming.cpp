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
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

const int N = 101;
int dp[N][N][N];
//from 0 to i in stor, last breakout at j, k breakouts total
void solve() {
    int n; cin >> n;
    vector<int> stor(n); cin >> stor;

    F0R(i,N) F0R(j,N) F0R(k,N) dp[i][j][k] = 2E9;
    dp[0][0][1] = (stor[0] != 0);
    FOR(k,1,n+1) {
        FOR(i,1,n) {
            F0R(j,i) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+(stor[i] != i-j));
            F0R(j,i) dp[i][i][k] = min(dp[i][i][k], dp[i-1][j][k-1]+(stor[i] != 0));
        }
        int ans = 2E9;
        F0R(j,n) ans = min(ans,dp[n-1][j][k]);
        cout << ans << '\n';
    }
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}