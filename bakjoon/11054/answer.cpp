#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> recordLIS(n,0);
    vector<int> recordLDS(n,0);
    vector<int> lis;
    vector<int> lds;
    for(int i=0; i<n; i++){
        int x = lower_bound(lis.begin(),lis.end(),arr[i]) - lis.begin();
        if(x == lis.size()) lis.push_back(arr[i]);
        else lis[x] = arr[i];
        recordLIS[i] = lis.size();
    }
    for(int i=n-1; i>=0; i--){  // 역방향으로 처리
        int x = lower_bound(lds.begin(),lds.end(),arr[i]) - lds.begin();
        if(x == lds.size()) lds.push_back(arr[i]);
        else lds[x] = arr[i];
        recordLDS[i] = lds.size();
    }
    int maxSize = 0;
    for(int i=0; i<n; i++){
        if(maxSize < recordLIS[i] + recordLDS[i] - 1) 
        maxSize = recordLIS[i] + recordLDS[i] - 1;   
        // arr[i]에서 lis의 크기와 lds의 크기에 1씩 두번 포함되니 -1 
    }
    cout << maxSize;
}