#include <iostream>
using namespace std;
int price[1001], page[1001], dp[100001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> page[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }
    cout << dp[x];
    return 0;
}
