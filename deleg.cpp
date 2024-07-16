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
#define printv(v,s,e) FOR(z,s,e+1) cout << v[z] << ' '; cout << '\n'
#define ir(...) int __VA_ARGS__; re(__VA_ARGS__);
#define pr(...) cout << (__VA_ARGS__) << '\n'
#define cmp(x,y) [&](auto&a,auto&b){return x a y<x b y;}
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void re(T &x) {cin >> x;}
template<class H, class... T> void re(H &h, T &...t) { re(h); re(t...); }
#pragma endregion

const int N = 1E5+1;
vt<int> adj[N];
int len[N];
bool ans;
void dfs(int v, int p, int k) {
    multiset<int> s;
    for (int i: adj[v]) if (i != p) {
        dfs(i,v,k);
        if (len[i] != k-1) {
            if (s.find(k-len[i]-2) != s.end()) s.erase(s.find(k-len[i]-2));
            else s.insert(len[i]);
        }
    }
    if (sz(s) > 1) {
        ans = 0; return;
    }
    if (sz(s) == 1) len[v] = (*s.begin() + 1)%k;
}
void solve() {
    ir(n);
    F0R(i,n-1) {
        ir(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR(k,1,n) {
        if ((n-1)%k != 0) cout << 0;
        else {
            ans = 1;
            FOR(i,1,n+1) len[i] = 0;
            dfs(1,0,k);
            if (ans && len[1] == 0) cout << 1;
            else cout << 0;
        }
    }
    dfs(1,0,3);
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}