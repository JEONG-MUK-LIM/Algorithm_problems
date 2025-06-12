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
    vector<int> lis;
    vector<int> record;  // 실제 lis를 구하기 위한 배열
    cin >> arr[0];
    lis.push_back(arr[0]);
    record.push_back(0);

    for(int i=1; i<n; i++){
        cin >> arr[i];
        int idx = lower_bound(lis.begin(),lis.end(),arr[i]) - lis.begin();
        if(idx == lis.size()){
            lis.push_back(arr[i]);
        }
        else{
            lis[idx] = arr[i];
        }
        record.push_back(idx); // 실제 lis를 구하기 위한 코드
    }
    cout << lis.size();

    /*
    //여기서 부터는 실제 lis를 구하기
    cout << '\n';
    int idx = lis.size() - 1;
    vector<int> trueLIS(lis.size());
    for (int i=n-1; i>=0; i--){
        if(record[i] == idx){
            trueLIS[idx] = arr[i];
            idx--;
        }
    }
    for(int i=0; i<lis.size(); i++){
        cout << trueLIS[i] << ' ';
    }
    */
}