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
#define cmp(x,y) [&](auto&aa,auto&bb){return x aa y<x bb y;}
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<class T, size_t SIZE> istream& operator>>(istream&in, array<T,SIZE>& a) {for(auto &x: a) in >> x; return in;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void re(T &x) {cin >> x;}
template<class H, class... T> void re(H &h, T &...t) { re(h); re(t...); }
template<class T> void pr(T &x) {cout << (x) << '\n';}
template<class H, class... T> void pr(H &h, T &...t) { cout << (h) << ' '; pr(t...); }
#pragma endregion

template<typename T> struct fastSegTree {
    vector<T> t;
    int n;
    fastSegTree(vector<T> arr) {
        n = arr.size();
        t.resize(2*n);
        for (int i = 0; i < n; i++) t[n+i] = arr[i];
        //original array is 0 indexed, seg is 1 indexed
        for (int i = n - 1; i > 0; --i) t[i] = f(t[i<<1], t[i<<1|1]);
    }
    void dbg() {
        cout << "[";
        for (int i = 0; i < n; i++) cout << t[n+i] << ", ";
        cout << "]\n";
    }
    T f(T a, T b) {
        return min(a,b);
    }
    void modify(int p, T value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    void update(int p, T value) {  // update value at position p
        for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    T query(int l, int r) {  // sum on interval [l, r)
        T res = 2E9; //CAREFUL IF MIN/MAX/GCD
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = f(res, t[l++]);
            if (r&1) res = f(res, t[--r]);
        }
        return res;
    }
};

void solve() {
    ir(n,p);
    vt<array<int,4>> spring(p);
    re(spring);
    
    //coord compress y coord
    vt<int> get;
    for (auto [a,b,c,d]: spring) {
        get.pb(b);
        get.pb(d);
    }
    sort(all(get));
    get.erase(unique(get.begin(), get.end()),get.end());
    auto id = [&](int x){return lb(all(get), x)-get.begin();};
    
    vt<array<int,3>> pts;//(x,y,start/end)
    map<pii,pii> start;//start pt of endpt
    for (auto& [a,b,c,d]: spring) {
        b = id(b);
        d = id(d);
        start[{c,d}] = {a,b};
        pts.pb({a,b,0});
        pts.pb({c,d,1});
    }
    sort(all(pts));//sort by x
    
    //min dist from (0,0) to (x,y) + dist from (x,y) to (n,n)
    map<pii,int> dist;
    for (auto [x,y,t]: pts) dist[{x,y}] = 2*n;
    
    //gets min(dist) for all pts less than (x,y)
    fastSegTree<int> seg(vt<int>(sz(get), 2*n));
    F0R(i,sz(pts)) {
        auto [x,y,t] = pts[i];
        int res = seg.query(0, y+1);
        dist[{x,y}] = min(dist[{x,y}], res);
        if (t) {//end pt
            pii st = start[{x,y}];
            dist[{x,y}] = min(dist[{x,y}], dist[st]+st.fi+get[st.se]-x-get[y]);
        }
        if (seg.query(y, y+1) > dist[{x,y}]) seg.modify(y, dist[{x,y}]);//chmin
    }
    
    int ans = 2*n;
    for (auto& [k,v]: dist) ans = min(ans, v);
    pr(ans);
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("boards.in","r",stdin);
    freopen("boards.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}