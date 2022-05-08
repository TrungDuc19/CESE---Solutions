#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[200001];
long long solution()
{
    sort(arr+1, arr+1+n);
    long long res = 0, mid_value = arr[(n+1)/2];
    for (int i = 1; i <= n; i++) {
        res += abs(arr[i] - mid_value);
    }
    if (n % 2 == 0) {
        mid_value = arr[n/2+1];
        long long tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp += abs(arr[i] - mid_value);
        }
        res = min(res, tmp);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        cout << solution() << "\n";
    }
}
