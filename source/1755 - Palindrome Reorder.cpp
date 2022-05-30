#include <iostream>
#include <algorithm>
using namespace std;
string s;
int arr[30];
string solution()
{
    for (char ch : s) {
        arr[ch - 'A']++;
    }
    int odd = 0;
    char tmp = ' ';
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 == 1) {
            tmp = char(i + 'A');
            odd++;
            if (odd > 1) return "NO SOLUTION";
        }
    }
    string subLeft = "";
    for (int i = 0; i < 26; i++) {
        if (arr[i]) {
            subLeft.append(arr[i]/2, char(i + 'A'));
        }
    }
    string subRight = subLeft;
    reverse(subRight.begin(), subRight.end());
    if (tmp == ' ') return subLeft + subRight;
    return subLeft + tmp + subRight;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> s;
        cout << solution() << "\n";
    }
}
