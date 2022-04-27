#include <iostream>
using namespace std;
int arr[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    long long tmp_sum = 0, max_sum = -1e9;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > tmp_sum + arr[i]) {
            tmp_sum = arr[i];
        }
        else tmp_sum += arr[i];
        max_sum = max(max_sum, tmp_sum);
    }
    cout << max_sum;
}
