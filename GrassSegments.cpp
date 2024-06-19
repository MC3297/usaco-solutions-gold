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
#define ir(...) int __VA_ARGS__; re(__VA_ARGS__);
#define pr(...) cout << (__VA_ARGS__) << '\n'
#define cmp(x) [&](auto&a,auto&b){return a x<b x;}
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void re(T &x) {cin >> x;}
template<class H, class... T> void re(H &h, T &...t) { re(h); re(t...); }
#pragma endregion

#undef int
#include <ext/pb_ds/assoc_container.hpp>//careful define int ll
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T, typename T2> using ordered_map = tree<T,T2,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<typename T> struct ordered_multiset {
    const int mx = 1E9;//negative??
    ordered_set<pair<T,int>> s;
    void insert(const T& x) {
        s.insert({x, count(x)});
    }
    void erase(const T& x) {
        auto erased = prev(s.lower_bound({x,mx}));
        assert(erased->fi == x);
        s.erase(erased);
    }
    int size() {
        return s.size();
    }
    int count(const T& x) {
        if (s.size() == 0) return 0;
        auto it = prev(s.lower_bound({x,mx}));
        if (it->first != x) return 0;
        return it->second + 1;//-1??
    }
    //number of elements strictly less than x
    int order_of_key(const T& x) {
        auto it = s.lower_bound({x,0});
        if (it == s.end()) return s.size();
        return s.order_of_key(*it);
    }
    //basically find_by_order but doesnt return iterator
    T operator[](int ind) {
        assert(ind < s.size());
        return s.find_by_order(ind)->first;
    }
};

void solve() {
    ir(n);
    vt<array<int,4>> stor(n), len(n);
    F0R(i,n) {
        ir(a,b,k);
        stor[i] = len[i] = {a,b,k,i};
    }
    sort(rall(stor), cmp([2]));
    sort(rall(len), [&](auto&a, auto&b){return a[1]-a[0]<b[1]-b[0];});
    debug(stor);
    debug(len);

    int p = 0;
    ordered_multiset<int> left, right;
    vt<int> ans(n);
    F0R(i,n) {
        auto [l,r,k,ind] = stor[i];
        while (p < n && len[p][1]-len[p][0] >= k) {
            left.insert(len[p][0]);
            right.insert(len[p][1]);
            p++;
        }
        ans[ind] = p-1;
        ans[ind] -= right.order_of_key(l+k);
        ans[ind] -= p - left.order_of_key(r-k+1);
    }

    debug(ans);
    for (int i: ans) cout << i << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    cout << "running file: " << __FILE__ << '\n';
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}