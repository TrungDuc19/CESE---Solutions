#include <iostream>
using namespace std;
const int N = 10;
int block[N][N], col[N], fiDiag[2*N], seDiag[2*N];
int cnt;
void Try(int i)
{
    for (int j = 1; j <= 8; j++) {
        if (!block[i][j] && !col[j] && !fiDiag[i-j+8] && !seDiag[i+j-1]) {
            col[j] = fiDiag[i-j+8] = seDiag[i+j-1] = 1;
            if (i == 8) cnt++;
            else Try(i+1);
            col[j] = fiDiag[i-j+8] = seDiag[i+j-1] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                char ch; cin >> ch;
                block[i][j] = (ch == '*');
            }
        }
        Try(1);
        cout << cnt;
    }
    return 0;
}
