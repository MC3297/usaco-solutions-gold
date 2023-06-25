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

ll bExpo(ll base, ll power, ll mod) {
    ll answer = 1;
    while (power != 0) {
        if (power%2 == 1) answer = (answer*base)%mod;
        base = (base * base)%mod;
        power /= 2;
    }
    return answer;
}
const int mod = 1E9+7;
void solve() {
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n; cin >> n;
    vector<pii> stor(n);
    cin >> stor;
    vector<int> pref(2*n+2, 0);
    for (pii i: stor) {
        pref[i.fi]++;
        pref[i.se]--;
    }
    FOR(i,1,2*n+2) {
        pref[i] += pref[i-1];
    }
    ll ans = 0;
    for (pii i: stor) {
        ans += bExpo(2, n-1-pref[i.fi-1], mod);
        ans %= mod;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}