#include <iostream>
using namespace std;
void towerOfHanoi(int n, int left, int mid, int right)
{
    if (n == 0) return;
    towerOfHanoi(n - 1, left, right, mid);
    cout << left << " " << right << "\n";
    towerOfHanoi(n - 1, mid, left, right);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    cout << (1<<n) - 1 << "\n";
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}
