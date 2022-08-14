#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;
long long a, b;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        cin >> a >> b;
        long long res = 1;
        while (b) {
            if (b&1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        cout << res << '\n';
    }
    return 0;
}
