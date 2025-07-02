#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T,n;
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> arr(n+1);
        vector<int> sum(n+1,0);
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        vector<vector<int>> dp1(n+1,vector<int>(n+1,0));
        vector<vector<int>> dp2(n+1,vector<int>(n+1,0));

        for(int len = 1; len <= n; len++){
            for(int i=1; i + len <= n; i++){
                int j = i + len;
                if(len % 2 == 0){
                    dp1[i][j] = max(arr[i] + , arr[j] + )
                    dp2[i][j] = sum[j] - sum[i-1] - dp1[i][j];
                }
            }
        }
    }
}       