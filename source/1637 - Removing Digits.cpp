#include <iostream>
#include <set>
using namespace std;
int arr[1000001], dp[1000001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        set<int> s;
        for (auto x : to_string(i)) {
            s.insert(x - '0');
        }
        dp[i] = 1e9;
        for (auto x : s) {
            dp[i] = min(dp[i], dp[i - x]+1);
        }
    }
    cout << dp[n];
}
