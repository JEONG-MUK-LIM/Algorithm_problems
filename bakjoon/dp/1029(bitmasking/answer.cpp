#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int dp[16][1<<16][10];

int dfs(vector<vector<int>>& matrix, int& n, int cur,int mask,int cost){
    if(dp[cur][mask][cost] != -1) return dp[cur][mask][cost];

    int ret = 1;
    for(int i=2; i<=n; i++){
        if(!(mask & 1<<i) && matrix[cur][i] >= cost){
            ret = max(ret,1 + dfs(matrix,n,i,(mask | 1<<i),matrix[cur][i]));
        }
    }
    return dp[cur][mask][cost] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> matrix(n+1,vector<int>(n+1));
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=1; j<=n; j++){
            matrix[i][j] = str[j-1] - '0';
        }
    }
    for(int i=1; i<16; i++){
        for(int j=1<<1; j<1<<16; j++){
            for(int k=0; k<10; k++) dp[i][j][k] = -1;
        }
    }
    cout << dfs(matrix,n,1,1<<1,0);
}   