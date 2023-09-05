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

const int N = 1E5+1;
vector<int> adj[N];
int val[N], sub[N], start = 0, leafs = 0, ans = 0;
void dfs1(int v, int sum) {
    int a = 0;
    if (!sz(adj[v])) {
        start += sum;
        a++;
        leafs++;
    }
    for (int i: adj[v]) {
        dfs1(i,sum+val[i]);
        a += sub[i];
    }
    sub[v] = a;
}
void dfs2(int v, int sum) {
    ans = min(ans, sum);
    for (int i: adj[v]) {
        dfs2(i, sum-sub[i]*val[i]+3*(leafs-sub[i]));
    }
}
void solve() {
    int n; cin >> n;
    FOR(i,1,n+1) {
        string s; int m;
        read(s,m);
        val[i] = sz(s)+(m != 0);
        F0R(j,m) {
            int a; cin >> a;
            adj[i].pb(a);
        }
    }
    dfs1(1,0);
    ans = start;
    dfs2(1,start);
    cout << ans << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("dirtraverse.in","r",stdin);
    freopen("dirtraverse.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}