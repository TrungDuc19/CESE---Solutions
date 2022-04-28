#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int res = 1;
    while (n--) {
        res = (res<<1) % mod;
    }
    cout << res;
}
