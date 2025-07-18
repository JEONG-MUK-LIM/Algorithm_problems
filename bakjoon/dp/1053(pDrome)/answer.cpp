#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector<vector<int>> dp;
int n;

int pd(string str,int l,int r){
    for(int len=2; len<=n; len++){
        for(int i=0; i+len-1<n; i++){
            int j = len+i-1;
            if(str[i] == str[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 1 + min({dp[i+1][j],dp[i][j-1],dp[i+1][j-1]});
        }
    }
    return dp[0][n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;
    n = str.size();
    dp.resize(n,vector<int>(n,0));
    
    int ans = 1e9;
    ans = min(ans,pd(str,0,n-1)); // 스왑을 안하는 경우
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            for(int k=0; k<n; k++) fill(dp[k].begin(),dp[k].end(),0);
            swap(str[i],str[j]);
            ans = min(ans,pd(str,0,n-1)+1);
            swap(str[i],str[j]);
        }
    }
    cout << ans;
}           