#include <iostream>
using namespace std;
long long arr[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    long long sum = 0;
    int l = 1, cnt = 0;
    for (int r = 1; r <= n; r++) {
        sum += arr[r];
        while (l <= r && sum > x) sum -= arr[l++];
        if (sum == x) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
