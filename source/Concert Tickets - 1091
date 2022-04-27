#include <iostream>
#include <set>
using namespace std;
multiset <int, greater<int>> tickets;
int person[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 1; i <= m; i++) cin >> person[i];
    for (int i = 1; i <= m; i++) {
        auto ind = tickets.lower_bound(person[i]);
        if (ind != tickets.end()) {
            cout << *ind << "\n";
            tickets.erase(ind);
        }
        else cout << -1 << "\n";
    }
}
