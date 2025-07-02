#include <iostream>
#include <vector>
#include <algorithm>
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
        for(int i=1; i<=n; i++) {
            dp1[i][i] = arr[i]; // 본인차례일 때 i부터 j까지 카드가 있을 때 만들 수 있는 최댓값
        }

        for(int len = 1; len <= n; len++){
            for(int i=1; i + len <= n; i++){
                int j = i + len;
                dp1[i][j] = max(arr[i] + sum[j] - sum[i] - dp1[i+1][j]
                    , arr[j] + sum[j-1] - sum[i-1] - dp1[i][j-1]);
            }
        }
        cout << dp1[1][n] << '\n';
    }
}       
