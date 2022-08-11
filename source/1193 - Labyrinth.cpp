#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1005;
struct point
{
    int y, x;
};
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};
int n, m, stX, stY, edX, edY;
vector<char> trace;
int visited[N][N];
int bfs()
{
    queue<point> q;
    q.push({stY, stX});
    visited[stY][stX] = 1;
    while(!q.empty()) {
        point curr = q.front();
        q.pop();
        if (curr.y == edY && curr.x == edX) return visited[curr.y][curr.x];
        for (int i = 0; i < 4; i++) {
            int Y = row[i] + curr.y;
            int X = col[i] + curr.x;
            if (Y >= 1 && Y <= n && X >= 1 && X <= m && (!visited[Y][X])) {
                q.push({Y, X});
                visited[Y][X] = visited[curr.y][curr.x] + 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ch; cin >> ch;
                if (ch == '#') visited[i][j] = -1;
                if (ch == 'A') {
                    stY = i;
                    stX = j;
                }
                if (ch == 'B') {
                    edY = i;
                    edX = j;
                }
            }
        }
        int cnt = bfs();
        if (cnt == 0) {
            cout << "NO";
            return 0;
        }
        while (cnt--) {
            for (int i = 0; i < 4; i++) {
                int Y = row[i] + edY;
                int X = col[i] + edX;
                if (Y >= 1 && Y <= n && X >= 1 && X <= m && visited[edY][edX] == visited[Y][X]+1) {
                    if (i == 0) trace.push_back('U');
                    else if (i == 1) trace.push_back('L');
                    else if (i == 2) trace.push_back('D');
                    else trace.push_back('R');
                    edY = Y;
                    edX = X;
                    break;
                }
            }
        }
        cout << "YES\n" << trace.size() << '\n';
        for (int i = trace.size()-1; i >= 0; i--) cout << trace[i];
    }
    return 0;
}
