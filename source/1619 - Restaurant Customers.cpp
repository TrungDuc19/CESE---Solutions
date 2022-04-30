#include <iostream>
#include <algorithm>
using namespace std;
int start_time[200001], end_time[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> start_time[i] >> end_time[i];
    }
    sort(start_time+1, start_time+1+n);
    sort(end_time+1, end_time+1+n);
    int i = 1, j = 1, res = 0, cnt = 0;
    while (i <= n && j <= n) {
        if (start_time[i] <= end_time[j]) {
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        res = max(res, cnt);
    }
    cout << res;
}
