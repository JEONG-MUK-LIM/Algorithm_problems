#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef unsigned long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    ll num;
    deque<int> dq;   //선택하지 않을 원소의 인덱스(=마지막 연속부분의 시작 인덱스-1), i-k부터 i-1까지
    vector<ll> dp(n+1,0);
    vector<ll> preSum(n+1,0);                                                                                                                           
    for(int i=1; i<=n; i++){
        cin >> num;
        preSum[i] = preSum[i-1] + num;
        while(!dq.empty() && i - dq.front() > k) dq.pop_front(); // 마지막 연속부분의 길이가 k를 넘는경우
        while(!dq.empty() && dp[dq.back()-1] + preSum[i] - preSum[dq.back()] < dp[i-1]) dq.pop_back(); 
        //i번째 원소를 선택하지 않은 경우보다 작은 건 선택될 일 없으므로 삭제
        dq.push_back(i);
        dp[i] = dp[dq.front()-1] + preSum[i] - preSum[dq.front()];
        if(i<=k) dp[i] = max(dp[i],preSum[i]);
    }
    cout << dp[n];
}