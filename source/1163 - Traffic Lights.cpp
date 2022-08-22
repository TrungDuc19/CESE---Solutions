#include <iostream>
#include <set>
#include <map>
using namespace std;
int x, n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> x >> n;
        set<int> light = {0, x};
        map<int, int> cnt;
        cnt[x] = 1;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            auto itRight = light.upper_bound(k);
            auto itLeft = itRight;
            --itLeft;
            if (--cnt[*itRight - *itLeft] == 0) cnt.erase(*itRight - *itLeft);
            cnt[*itRight - k]++;
            cnt[k - *itLeft]++;
            light.insert(k);
            cout << cnt.rbegin()->first << ' ';
        }
    }
    return 0;
}
