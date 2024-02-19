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
    read(n,k);
    vt<int> stor(n);
    re(stor);

    vt<int> v = stor;
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    //[sz(v)] is min of that row
    vt<vt<vt<int>>> dp(n+1, vt<vt<int>>(sz(v)+1, vt<int>(k+1,1E9)));
    F0R(b,sz(v)) F0R(c,k+1) dp[0][b][c] = 0;

    //base case for k=0, no switch
    FOR(i,1,n+1) F0R(j,sz(v)) {
        if (dp[i-1][j][0] != 1E9 && v[j] >= stor[i-1]) {
            dp[i][j][0] = dp[i-1][j][0] + v[j]-stor[i-1];
            dp[i][sz(v)][0] = min(dp[i][sz(v)][0], dp[i][j][0]);
        }
    }
    
    FOR(c,1,k+1) {
        FOR(i,1,n+1) F0R(j,sz(v)) if (v[j] >= stor[i-1]) {
            dp[i][j][c] = min(dp[i-1][sz(v)][c-1], dp[i-1][j][c]);
            dp[i][j][c] += v[j]-stor[i-1];
            dp[i][sz(v)][c] = min(dp[i][sz(v)][c], dp[i][j][c]);
        }
    }

    int ans = 1E9;
    F0R(j,sz(v)+1) F0R(c,k+1) ans = min(ans, dp[n][j][c]);
    cout << ans << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}