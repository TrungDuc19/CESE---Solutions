#include <iostream>
#include <algorithm>
using namespace std;
pair <int, int> p[200001];
int binSearch(int l, int r, int x)
{
    int m;
    while (l <= r) {
        m = (l + r)/2;
        if (p[m].first == x) return p[m].second;
        else if (p[m].first > x) r = m - 1;
        else l = m + 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p+1, p+1+n);
    int ind;
    for (int i = 1; i <= n; i++) {
        ind = binSearch(i+1, n, k-p[i].first);
        if (ind) {
            cout << p[i].second << " " << ind;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
