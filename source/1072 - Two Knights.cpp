#include <iostream>
using namespace std;
long long n;
void solution()
{
    for (long long i = 1; i <= n; i++) {
        cout << i*i*(i*i - 1)/2 - 4*(i - 1)*(i - 2) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n;
        solution();
    }
}
