#include <iostream>
using namespace std;
int marker[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, x; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        marker[x] = i;
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (marker[i] < marker[i-1]) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
