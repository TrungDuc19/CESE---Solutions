#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int res = 0;
    while (n > 0) {
        res += n/5;
        n /= 5;
    }
    cout << res;
}
