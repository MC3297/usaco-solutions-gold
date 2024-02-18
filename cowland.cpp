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

template<typename T> struct LazySegTree {
    vector<T> t, lazy;
    int n;
    LazySegTree(vector<T> &arr) {
        n = arr.size();
        t.resize(2*n);
        lazy.resize(2*n,0);//change depending on f()
        for (int i = 0; i < n; i++) t[n+i] = arr[i];
        build();
    }
    T f(T a, T b) {
        return a^b;
    }
    void build() {  // build the tree
        //original array is 0 indexed, seg is 1 indexed
        for (int i = n - 1; i > 0; --i) t[i] = f(t[i<<1], t[i<<1|1]);
    }
    T query(int p) {// value at position p
        vector<int> temp;
        for (int q = (p += n)>>1; q; q >>= 1) temp.push_back(q);
        for (int i = (int)temp.size()-1; i >= 0; --i) {
            int j = temp[i];
            if (2*j < 2*n) lazy[2*j] = f(lazy[2*j],lazy[j]);
            if (2*j+1 < 2*n) lazy[2*j+1] = f(lazy[2*j+1],lazy[j]);
            lazy[j] = 0;//CAREFUL IF f() IS MIN/MAX/GCD
        }
        return f(t[p],lazy[p]);
    }
    void update(int l, int r, T val) {  // increment on interval [l, r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                lazy[l] = f(lazy[l], val);
                l++;
            }
            if (r&1) {
                r--;
                lazy[r] = f(lazy[r], val);
            }
        }
    }
};

const int N = 1E5+1;
vector<int> adj[N];
int depth[N], anc[N][20];//20 is log of max n
void dfslca(int v, int p) {//dfslca(1,0)
	anc[v][0] = p;
	for (int i = 1; i < 20; i++) 
        anc[v][i] = anc[anc[v][i-1]][i-1];
	for (int i : adj[v]) if (i != p) {
        depth[i] = depth[v]+1;
        dfslca(i, v);
    }
}
int kth_anc(int k, int v) {//k=0 is itself
    for (int i = 0; i < 20; i++) 
        if (k>>i&1) v = anc[v][i];
    return v;
}
int LCA(int a, int b) {
    if (depth[a] > depth[b]) swap(a,b);
    b = kth_anc(depth[b]-depth[a], b);//make same level
    if (a == b) return a;//if one of them is lca
    for (int i = 20-1; i >= 0; i--) {
        if (anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}

vt<int> val, temp;
void dfs(int v, int p) {
    val[v] ^= val[p];
    for (int i: adj[v]) if (i != p) {
        dfs(i,v);
    }
}
int tin[N], tout[N], tme = 0;
void dfsFlatten(int v, int p) {
    tin[v] = tme++;
    temp.pb(val[v]);
    for (int i: adj[v]) if (i != p) {
        dfsFlatten(i,v);
    }
    tout[v] = tme;
}

void solve() {
    read(n,q);
    val.resize(n+1,0);
    F0R(i,n) re(val[i+1]);
    vt<int> save = val;
    F0R(i,n-1) {
        read(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfslca(1,0);//for lca
    dfs(1,0);//to get cumulative xors
    dfsFlatten(1,0);//flatten tree, obtain temp

    LazySegTree<int> seg(temp);
    while (q--) {
        read(t,a,b);
        if (t == 1) {
            seg.update(tin[a], tout[a], save[a]^b);
            save[a] = b;
        }
        else {
            int left = seg.query(tin[a]), right = seg.query(tin[b]);
            cout << (left^right^save[LCA(a,b)]) << '\n';
        }
    }
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}