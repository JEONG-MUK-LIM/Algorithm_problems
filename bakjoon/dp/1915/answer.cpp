#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<string> matrix(n);
    for(int i=0; i<n; i++){
        cin >> matrix[i];
    }
    int answer = 0;
    vector<vector<int>> dp(n,vector<int>(m,0));
    if(matrix[0][0] == '1') {
        dp[0][0] = 1;
        answer = 1;
    }
    for(int i=1; i<n; i++) {
        if(matrix[i][0] == '1') {
            dp[i][0] = 1;
            answer = 1;
        }
    }
    for(int i=1; i<m; i++){
        if(matrix[0][i] == '1') {
            dp[0][i] = 1;
            answer = 1;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] == '1') {
                dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) + 1;
                answer = max(answer,dp[i][j]);
            }
        }
    }
    cout << answer * answer;
}