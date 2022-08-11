/* Sparse Table */
#include <iostream>
#include <cmath>
using namespace std;
int n, q;
int ST[200005][32];
void RMQ()
{
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; i + (1<<j) <= n; i++) {
            ST[i][j] = min(ST[i][j-1], ST[i + (1<<(j-1))][j-1]);
        }
    }
}
int querry(int l, int r)
{
    int j = log2(r - l + 1);
    return min(ST[l][j], ST[r - (1<<j) + 1][j]);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> ST[i][0];
        }
        RMQ();
        int l, r;
        while (q--) {
            cin >> l >> r;
            cout << querry(l-1, r-1) << "\n";
        }
    }
	return 0;
}



/* Segment Tree */
#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, q, l, r;
int arr[N], STree[4*N];
void build(int id, int u, int v)
{
    if (u == v) {
        STree[id] = arr[u];
        return;
    }
    int m = (u + v)/2;
    build(2*id, u, m);
    build(2*id+1, m+1, v);
    STree[id] = min(STree[2*id], STree[2*id+1]);
}
int get(int id, int u, int v)
{
    if (v < l || u > r) return 2e9;
    if (l <= u && v <= r) {
        return STree[id];
    }
    int m = (u + v)/2;
    return min(get(2*id, u, m), get(2*id+1, m+1, v));
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        build(1, 1, n);
        while (q--) {
            cin >> l >> r;
            cout << get(1, 1, n) << '\n';
        }
    }
    return 0;
}
//
