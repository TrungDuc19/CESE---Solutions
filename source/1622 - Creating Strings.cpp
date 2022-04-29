#include <iostream>
#include <set>
using namespace std;
set <string> res;
void permute(string s, int l, int r) {
    if (l == r) {
        res.insert(s);
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    permute(s, 0, s.size()-1);
    cout << res.size() << "\n";
    for (string it : res) {
        cout << it << "\n";
    }
}
