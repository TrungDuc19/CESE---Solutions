#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n; cin >> n;
    if (n * (n + 1) % 4 == 0) {
        long long sum = n * (n + 1) / 4;
        set<int> s1, s2;
        for (int i = n; i >= 1; i--) {
            if (sum - i >= 0) {
                sum -= i;
                s1.insert(i);
            }
            else s2.insert(i);
        }
        cout << "YES\n" << s1.size() << "\n";
        for (int num : s1) cout << num << " ";
        cout << "\n" << s2.size() << "\n";
        for (int num : s2) cout << num << " ";
    }
    else cout << "NO";
}
