#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> sum(n+1,0);
        for(int i=1; i<=n; i++){
            int a;
            cin >> a;
            sum[i] = sum[i-1] + a;
        }
        for(int len = 1; len < n; len++){
            for(int i=1; i+len <= n; i++){
                int j = i + len;
                dp[i][j] = 1e9;
                for(int k = i; k<j; k++){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
                }
            }
        }
        cout << dp[1][n] << '\n';
    }
}