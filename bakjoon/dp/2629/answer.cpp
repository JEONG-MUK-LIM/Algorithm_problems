#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> weight(n);
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(15001,0));
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<15001; j++){
            if(dp[i][j]){
                dp[i+1][j + weight[i]] = true;
                dp[i+1][abs(j - weight[i])] = true;
                dp[i+1][j] = true;
            }
        }
    }
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int b;
        cin >> b;
        if(b < 15001 && dp[n][b]){
            cout << "Y ";
        }
        else cout << "N ";
    }
}       