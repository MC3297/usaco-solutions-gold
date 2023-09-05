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
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

void solve() {
    int n; cin >> n;
    vector<int> stor(n+1,0);
    FOR(i,1,n+1) cin >> stor[i];
    stor.pb(0);

    vector<int> a(n+1,0), b(n+1,0), cut;
    int btwn = 0;
    F0R(i,sz(stor)) b[stor[i]]++;
    F0R(i,sz(stor)) {
        if (a[stor[i]] == 0) {
            cut.pb(stor[i]);
            if (stor[i] != 0) btwn++;
        }
        a[stor[i]]++;
        b[stor[i]]--;
        if (b[stor[i]] == 0) {
            cut.pb(stor[i]);
            if (stor[i] != 0) btwn--;
        }
        if (stor[i] == 0 && btwn) {
            cout << -1 << '\n'; return;
        }
    }

    debug(cut);

    vector<int> stack{0};
    int depth = 0, ans = 0;
    FOR(i,1,sz(cut)) {
        if (stack.back() == cut[i]) {
            stack.pop_back();
            depth--;
            continue;
        }
        stack.pb(cut[i]);
        depth++;
        ans = max(ans, depth);
    }
    if (sz(stack)) cout << -1 << '\n';
    else cout << ans << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("art2.in","r",stdin);
    freopen("art2.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}