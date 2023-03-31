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
    int numcomps = 0;//*
    DSU(int n) {
        parent.resize(n+1, -1);
        size.resize(n+1, 0);
    }
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
        numcomps++;//*
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
            numcomps--;//*
        }
    }
};
ll dist(pii a, pii b) {
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    vector<pii> coord(n);
    for (auto& a: coord) {
        cin >> a.fi >> a.se;
    }
    vector<pair<ll, pii>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edges.push_back({dist(coord[i], coord[j]), {i,j}});
        }
    }
    sort(edges.begin(), edges.end());
    //cout << edges << '\n';
    DSU dsu(n);
    for (int i = 0; i < n; i++) dsu.make(i);
    ll min = 0;
    for (auto a: edges) {
        if (dsu.find(a.se.fi) != dsu.find(a.se.se)) {
            dsu.unite(a.se.fi, a.se.se);
            min = a.fi;
        }
    }
    cout << min << '\n';
}