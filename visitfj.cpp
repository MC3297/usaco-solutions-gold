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

int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
const int N = 101;
int dist[N][N][3];
void solve() {
    int n,time; read(n,time);
    vector<vector<int>> grid(n,vector<int>(n));
    cin >> grid;
    F0R(i,n) F0R(j,n) F0R(k,3) dist[i][j][k] = INT_MAX;
    min_priority_queue<array<int,4>> pq;
    pq.push({0,0,0,0});
    while (sz(pq)) {
        auto [w,t,r,c] = pq.top();
        pq.pop();
        if (w > dist[r][c][t]) continue;
        dist[r][c][t] = w;
        F0R(i,4) {
            int nr = r+dx[i], nc = c+dy[i], nt = (t+1)%3;
            if (!(0 <= nr && nr < n && 0 <= nc && nc < n)) continue;
            int nw = w+grid[nr][nc]*(!nt)+time;
            if (nw >= dist[nr][nc][nt]) continue;
            dist[nr][nc][nt] = nw;
            pq.push({nw, nt, nr, nc});
        }
    }
    int ans = dist[n-1][n-1][0];
    F0R(i,3) ans = min(ans, dist[n-1][n-1][i]);
    cout << ans << '\n';
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("visitfj.in","r",stdin);
    freopen("visitfj.out","w",stdout);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}