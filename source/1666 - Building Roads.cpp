#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> edges[N];
bool visited[N];
int dfs(int u)
{
    stack<int> st;
    st.push(u);
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        for (int e : edges[curr]) {
            if (!visited[e]) {
                st.push(e);
            }
        }
    }
    return u;
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
        vector<pair<int, int>> res;
        int last = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (last) res.push_back({last, i});
                last = dfs(i);
            }
        }
        cout << res.size() << '\n';
        for (auto x : res) cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
