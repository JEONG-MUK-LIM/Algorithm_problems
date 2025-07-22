#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool operator<(const vector<int>& num1, const vector<int>& num2){
    if(num2.size() == 0) return false;
    if(num1.size() < num2.size()) return true;
    else if(num1.size() == num2.size()) {
        for(int i=0; i<num1.size(); i++){
            if(num1[i] > num2[i]) return false;
            else if(num1[i] < num2[i]) return true;
        }
        return false; // 두 숫자가 완전히 같은 경우 값을 할당할 필요없으므로
    }
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> m;
    vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(m+1));
    
    for(int i=0; i<m; i++){
        for(int j=0; j <= m; j++){
            if(dp[i+1][j] < dp[i][j]) dp[i+1][j] = dp[i][j];
            for(int k=0; k<n; k++){
                if(j + arr[k] > m) continue;
                if(dp[i][j].size() == 0 && k == 0) continue;
                vector<int> number = dp[i][j];
                number.push_back(k);
                sort(number.begin(),number.end(),greater<int>());
                if(dp[i+1][j+arr[k]] < number) dp[i+1][j+arr[k]] = number;
            }
        }   
    }
    if(dp[m][m].size() > 0){
        for(int d:dp[m][m]) cout << d;
    }
    else cout << 0;
}           