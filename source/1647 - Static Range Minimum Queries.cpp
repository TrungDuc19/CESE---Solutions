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
