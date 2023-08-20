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
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

void solve() {
    int n,d; read(n,d);
    vector<pii> stor(2*n); cin >> stor;
    set<pii> x,y;
    F0R(i,n) {
        x.insert({stor[i].se,i});
    }
    FOR(i,n,2*n) {
        y.insert({stor[i].fi,i});
    }
    vector<int> ans(2*n,INT_MAX);
    debug(x); debug(y);
    //bessie gives elsie last pie, se=0
    queue<int> q;
    F0R(i,n) if (stor[i].se == 0) {
        ans[i] = 1;
        x.erase({stor[i].fi,i});
        q.push(i);
    }
    //elsie gives bessie last pie, fi=0
    FOR(i,n,2*n) if (stor[i].fi == 0) {
        ans[i] = 1;
        x.erase({stor[i].se,i});
        q.push(i);
    }
    //cout << q << '\n';
    while (sz(q)) {
        int cur = q.front();
        q.pop();
        debug(cur);
        if (cur < n) {
            auto yit = y.lb({stor[cur].fi-d,INT_MIN});
            while (yit != y.end() && yit->fi <= stor[cur].fi) {
                ans[yit->se] = min(ans[yit->se],ans[cur]+1);
                q.push(yit->se);
                y.erase(yit++);
            }
        }
        else {
            auto xit = x.lb({stor[cur].se-d,INT_MIN});
            while (xit != x.end() && xit->fi <= stor[cur].se) {
                ans[xit->se] = min(ans[xit->se],ans[cur]+1);
                q.push(xit->se);
                x.erase(xit++);
            }
        }
        //cout << q << '\n';
    }
    //cout << ans << '\n';
    F0R(i,n) cout << ((ans[i]==INT_MAX)?(-1):ans[i]) << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("piepie.in","r",stdin);
    freopen("piepie.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}