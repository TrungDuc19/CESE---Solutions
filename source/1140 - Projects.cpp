#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
struct project {
    int st, ed, m;
} arr[N];
int n;
long long dp[N];
int binSearch(int ind)
{
    int m, l = 0, r = ind-1, res = -1;
    while(l <= r) {
        m = (l + r)/2;
        if (arr[m].ed >= arr[ind].st) r = m - 1;
        else {
            res = max(res, m);
            l = m + 1;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].st >> arr[i].ed >> arr[i].m;
        }
        sort(arr, arr+n, [](project a, project b){
            return a.ed < b.ed;
        });
        dp[0] = arr[0].m;
        for (int i = 1; i < n; i++) {
            long long sum = arr[i].m;
            int ind = binSearch(i);
            if (ind != -1) {
                sum += dp[ind];
            }
            dp[i] = max(sum, dp[i-1]);
        }
        cout << dp[n-1];
    }
    return 0;
}
