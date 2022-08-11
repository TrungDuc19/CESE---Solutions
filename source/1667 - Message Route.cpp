#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> edges[N];
int visited[N];
void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = -1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == n) return;
        for (int e : edges[curr]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = curr;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bfs();
        if (!visited[n]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        vector<int> res = {n};
        int curr = n;
        while (visited[curr] != -1) {
            res.push_back(visited[curr]);
            curr = visited[curr];
        }
        cout << res.size() << '\n';
        for (int i = res.size()-1; i >= 0; i--) cout << res[i] << ' ';
    }
    return 0;
}
