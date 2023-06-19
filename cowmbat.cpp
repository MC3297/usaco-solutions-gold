#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define fi first
#define se second
#define pb push_back 
#define lb lower_bound
#define ub upper_bound
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
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};

#define int long long
int pref[(int)1E5+1][26];
void solve() {
    freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
    int n,m,k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<int>> cost(m, vector<int>(m));
    for (int i = 0; i < m; i++) cin >> cost[i];

    //floyd warshall
    for (int h = 0; h < m; h++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][h] + cost[h][j]); 
            }
        }
    }

    int dp[n+1][m];
    F0R(i,n+1) fill(dp[i], dp[i]+m, 1E9);
    //pref is used to find cost to flip k consec chars
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i][j] = pref[i-1][j] + cost[s[i-1]-'a'][j];
        }
    }
    //actual dp now
    vector<int> mn(n+1, 1E9);
    mn[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]+cost[s[i-1]-'a'][j]);
            if (i-k >= 0) dp[i][j] = min(dp[i][j], mn[i-k]+pref[i][j]-pref[i-k][j]);
            mn[i] = min(mn[i], dp[i][j]);
        }
    }

    cout << mn[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}