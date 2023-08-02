#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
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


void solve() {
    int n,m; read(n,m);

    //find primes
    vector<bool> prime(n+1,1);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.pb(i);
            if ((ll)i*i > n) continue;
            for (int j = i*i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    //dp[i][j] represents
    //sum of all k leq i using only first j primes
    ll dp[n+1][sz(primes)+1];
    F0R(i,sz(primes)+1) dp[0][i] = 1;
    F0R(i,n+1) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sz(primes); j++) {
            dp[i][j] = dp[i][j-1];
            int p = primes[j-1];
            while (i-p >= 0) {
                dp[i][j] = (dp[i][j]+dp[i-p][j-1]*p%m)%m;
                p *= primes[j-1];
            }
        }
    }
    cout << dp[n][sz(primes)] << '\n';
}
signed main() {
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}