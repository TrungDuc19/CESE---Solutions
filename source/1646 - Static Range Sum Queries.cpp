#include <iostream>
using namespace std;
long long sum[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum[i] = sum[i-1] + x;
    }
    int a, b;
    for (int i = 1; i <= q; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
}
