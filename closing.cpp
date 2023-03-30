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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
    int n,m; cin >> n >> m;
    vector<int> edges[n+1];
    for (int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    DSU dsu(n);
    vector<int> perm(n);
    for (auto& a: perm) cin >> a;
    vector<string> ans(n);
    for (int i = n-1; i >= 0; i--) {
        dsu.make(perm[i]);
        for (int j: edges[perm[i]]) {
            if (dsu.parent[j] != -1) {
                dsu.unite(perm[i], j);
            }
        }
        ans[i] = (dsu.numcomps == 1)?"YES":"NO";
    }
    for (auto a: ans) cout << a << '\n';
}