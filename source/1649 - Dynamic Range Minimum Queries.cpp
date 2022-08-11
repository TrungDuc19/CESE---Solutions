#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, q, pos, val, l, r;
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
void update(int id, int u, int v)
{
    if (u > pos || v < pos) return;
    if (u == v) {
        STree[id] = val;
        return;
    }
    int m = (u + v)/2;
    update(2*id, u, m);
    update(2*id+1, m+1, v);
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
            int choose; cin >> choose;
            if (choose == 1) {
                cin >> pos >> val;
                update(1, 1, n);
            }
            else {
                cin >> l >> r;
                cout << get(1, 1, n) << '\n';
            }
        }
    }
    return 0;
}
