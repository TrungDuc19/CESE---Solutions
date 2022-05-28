#include <iostream>
#include <set>
using namespace std;
int arr[200001];
set <int> s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        while (s.find(arr[i]) != s.end()) {
            s.erase(arr[i - s.size()]);
        }
        s.insert(arr[i]);
        if (s.size() > res) res = s.size();
    }
    cout << res;
}
