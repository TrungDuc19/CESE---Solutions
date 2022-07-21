#include <iostream>
#include <vector>
using namespace std;
const int N = 1005;
int n, m;
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};
bool visited[N][N];
bool check(int y, int x)
{
    return (y >= 1 && y <= n && x >= 1 && x <= m);
}
void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int Y = y + row[i];
        int X = x + col[i];
        if (check(Y, X) && (!visited[Y][X])) {
            dfs(Y, X);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ch; cin >> ch;
                if (ch == '#') {
                    visited[i][j] = true;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!visited[i][j]) {
                    res++;
                    dfs(i, j);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
