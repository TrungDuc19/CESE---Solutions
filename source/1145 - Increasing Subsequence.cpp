#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int n, arr[N], res[N];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        res[0] = -2e9;
        for (int i = 1; i < n; i++) res[i] = 2e9;
        int len = 0;
        for (int i = 0; i < n; i++) {
            int k = lower_bound(res, res+n, arr[i]) - res;
            res[k] = arr[i];
            len = max(len, k);
        }
        cout << len;
    }
    return 0;
}
