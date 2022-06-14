#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
char grid[1001][1001];
int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> grid[i][j];
    }
    dp[0][1] = (grid[1][1] == '.');
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '.') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            else dp[i][j] = 0;
        }
    }
    cout << dp[n][n];
    return 0;
}
