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
    int n,b; read(n,b);
    vector<int> stor(n); cin >> stor;

    map<int,vector<pii>,greater<int>> query;
    map<int,vector<int>,greater<int>> pos;
    set<int> vis = {-1};
    F0R(i,n+1) vis.insert(i);
    F0R(i,b) {
        int s,d; read(s,d);
        query[s].pb({d,i});
    }
    F0R(i,n) pos[stor[i]].pb(i);

    int mx = 1;
    vector<bool> ans(b);
    for (auto [k,v]: query) {
        while (sz(pos) && pos.begin()->fi > k) {
            for (int i: pos.begin()->se) {
                auto it = vis.find(i);
                mx = max(mx, *next(it)-*prev(it));
                vis.erase(it);
            }
            pos.erase(pos.begin());
        }
        for (pii i: v) ans[i.se] = i.fi >= mx;
    }
    debug(ans);
    for (bool i: ans) cout << i << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}