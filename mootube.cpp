//#include <bits/bedugging.h>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define fi first
#define se second
struct DSU {
    //* stuff are totally optional
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1, -1);
        size.resize(n+1, 0);
    }
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
bool cmp(pair<pii, int> a, pair<pii, int> b) {
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    int n,q; cin >> n >> q;
    vector<pair<pii, int>> stor(n-1);
    for (int i = 0; i < n-1; i++) {
        int a,b,w; cin >> a >> b >> w;
        stor[i] = {{a,b},w};
    }
    sort(stor.begin(), stor.end(), cmp);
    
    //cout << stor << '\n';
    vector<pii> queries(q);
    vector<int> sorted(q), answer(q);
    for (int i = 0; i < q; i++) {
        int k,v; cin >> k >> v;
        queries[i] = {k,v};
        sorted[i] = i;
    }
    sort(sorted.begin(), sorted.end(), [&] (int a, int b) -> bool {
        return queries[a] < queries[b];
    });
    //cout << sorted << '\n';
    //cout << queries << '\n';

    DSU dsu(n);
    for (int i = 1; i <= n; i++) dsu.make(i);
    int p = stor.size()-1;
    for (int i = q-1; i >= 0; i--) {
        while (p >= 0 && stor[p].se >= queries[sorted[i]].fi) {
            dsu.unite(stor[p].fi.fi, stor[p].fi.se);
            p--;
        }
        answer[sorted[i]] = dsu.size[dsu.find(queries[sorted[i]].se)];
        //cout << answer << '\n';
    }
    for (auto& a: answer) cout << a-1 << '\n';
}