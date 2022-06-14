#include <iostream>
using namespace std;
int arr[101], dp[100001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) dp[j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= sum; i++) cnt += dp[i];
    cout << cnt << "\n";
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) cout << i << " ";
    }
    return 0;
}
