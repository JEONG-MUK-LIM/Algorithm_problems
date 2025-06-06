#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
 
    int pre_count[2][2] = {0,};
    int cur_count[2] = {0,};
    pre_count[0][0] = arr[0]; /* i = 0인 지점에서는 count가 1인 경우는 존재하지 않으니 
    i = 1부터 시작, 거기서 한칸 전의 계단이면서 count가 0인 부분을 직접 초기화 
    */
    for(int i=1; i<n; i++){
        cur_count[0] = max(pre_count[1][0], pre_count[1][1]) + arr[i];
        cur_count[1] = pre_count[0][0] + arr[i];

        pre_count[1][0] = pre_count[0][0];  //두칸 전,계단을 연속해서 밟지 않은 경우 최댓값
        pre_count[1][1] = pre_count[0][1];  //두칸 전,계단을 연속해서 밟은 경우 최댓값
        pre_count[0][0] = cur_count[0];     //한칸 전,계단을 연속해서 밟지 않은 경우 최댓값
        pre_count[0][1] = cur_count[1];     //한칸 전,계단을 연속해서 밟은 경우 최댓값
    }
    if(n == 1) cout << arr[0];
    else cout << max(cur_count[0], cur_count[1]);
}