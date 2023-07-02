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
#define ROF(i,s,e) for (int i = (e)-1; i >= (s); --i) 
#define R0F(i,e) ROF(i,0,e) 
#define printv(v,s,e) FOR(i,s,e+1) cout << v[i] << ' '; cout << '\n'
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

struct SegTree {
    vector<int> t;
    int n;
    SegTree(vector<int> &arr) {
        n = (int)arr.size();
        t.resize(2*n);
        for (int i = 0; i < n; i++) t[n+i] = arr[i];
        build();
    }
    int f(int a, int b) {
        return a+b;
    }
    void build() {  // build the tree
        //original array is 0 indexed, seg is 1 indexed
        for (int i = n - 1; i > 0; --i) t[i] = f(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    void update(int p, int value) {  // update value at position p
        for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0; //CAREFUL IF MIN/MAX/GCD
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = f(res, t[l++]);
            if (r&1) res = f(res, t[--r]);
        }
        return res;
    }
};
void solve() {
    int n; cin >> n;
    vector<int> stor(n), pos[n+1], ptr(n,0), x(n,0); cin >> stor;
    F0R(i,n) pos[stor[i]].pb(i);
    SegTree seg(x);
    FOR(i,1,n+1) {
        if (sz(pos[i])) {
            seg.modify(pos[i][ptr[i]],1);
        }
        pos[i].pb(n);
    }
    ll sum = 0;
    F0R(i,n) {
        if (ptr[stor[i]] < sz(pos[stor[i]])-1) {
            sum += seg.query(i,pos[stor[i]][ptr[stor[i]]+1])-1;
            seg.modify(pos[stor[i]][ptr[stor[i]]],0);
            ptr[stor[i]]++;
            if (ptr[stor[i]] < sz(pos[stor[i]])-1) 
                seg.modify(pos[stor[i]][ptr[stor[i]]],1);
        }
    }
    cout << sum << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}