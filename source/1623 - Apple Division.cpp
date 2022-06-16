#include <iostream>
#include <cmath>
using namespace std;
long long arr[21];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long res = 1e9;
    for (int mask = 1; mask < (1<<n); mask++) {
        long long sumA = 0, sumB = 0;
        for (int pos = 0; pos < n; pos++) {
            if (mask & (1<<pos)) {
                sumA += arr[pos];
            }
            else {
                sumB += arr[pos];
            }
        }
        res = min(res, abs(sumA - sumB));
    }
    cout << res;
}
