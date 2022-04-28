#include <iostream>
#include <algorithm>
using namespace std;
pair <int, int> movies[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
   sort(movies+1, movies+1+n, [](pair<int, int> a, pair<int, int> b)
        {
            return a.second < b.second;
        });
    int cnt = 1, ind = 1;
    for (int i = 1; i < n; i++) {
        if (movies[ind].second <= movies[i+1].first) {
            cnt++;
            ind = i+1;
        }
    }
    cout << cnt;
}
