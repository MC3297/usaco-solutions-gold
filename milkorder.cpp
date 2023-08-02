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
#define ROF(i,s,e) for (int i = (b)-1; i >= (a); --i) 
#define R0F(i,e) ROF(i,0,e) 
#define printv(v,s,e) FOR(i,s,e+1) cout << v[i] << ' '; cout << '\n'
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

int n,m;
vector<int> topo;
bool good(vector<vector<int>>& order, int k) {
    topo.clear();
    vector<int> adj[n+1], indeg(n+1,0);
    F0R(i,k) {
        F0R(j,sz(order[i])-1) {
            adj[order[i][j]].pb(order[i][j+1]);
            indeg[order[i][j+1]]++;
        }
    }
    min_priority_queue<int> pq;
    FOR(i,1,n+1) {
        if (!indeg[i]) pq.push(i);
    }
    while (sz(pq)) {
        int v = pq.top();
        pq.pop();
        topo.pb(v);
        for (int i: adj[v]) {
            indeg[i]--;
            if (!indeg[i]) {
                pq.push(i);
            }
        }
    }
    return sz(topo) == n;
}
void solve() {
    read(n,m);
    vector<vector<int>> order;
    F0R(i,m) {
        int mi; cin >> mi;
        vector<int> ord(mi); cin >> ord;
        order.pb(ord);
    }
    int l = 0, r = m;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (good(order, mid)) l = mid;
        else r = mid-1;
    }
    good(order, l);
    F0R(i,n-1) cout << topo[i] << ' ';
    cout << topo[n-1];
}
signed main() {
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}