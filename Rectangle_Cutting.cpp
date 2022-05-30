#include <iostream>
#include <algorithm>
#define f first
#define s second
#define ll long long
using namespace std;
 
int n, m;
int dp[501][501];
 
void dfs(int a, int b) {
    if(a == b) {
        dp[a][b] = 0;
        return;
    }
    if(a == 1) {
        dp[a][b] = b - 1;
        return;
    }
    if(b == 1) {
        dp[a][b] = a - 1;
        return;
    }
    for(int i = 1; i < a; ++i) {
        if(dp[i][b] == 1000000000 && dp[a - i][b] == 1000000000) {
            dfs(i, b);
            dfs(a - i, b);
        } else if(dp[i][b] == 1000000000) {
            dfs(i, b);
        } else if(dp[a - i][b] == 1000000000) {
            dfs(a - i, b);
        }
        dp[a][b] = min(dp[a][b], 1 + dp[i][b] + dp[a - i][b]);
    }
    for(int i = 1; i < b; ++i) {
        if(dp[a][i] == 1000000000 && dp[a][b - i] == 1000000000) {
            dfs(a, i);
            dfs(a, b - i);
        } else if(dp[a][i] == 1000000000) {
            dfs(a, i);
        } else if(dp[a][b - i] == 1000000000) {
            dfs(a, b - i);
        }
        dp[a][b] = min(dp[a][b], 1 + dp[a][i] + dp[a][b - i]);
    }
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) dp[i][j] = 1000000000;
    }
    dfs(n, m);
    cout << dp[n][m] << "\n";
}
