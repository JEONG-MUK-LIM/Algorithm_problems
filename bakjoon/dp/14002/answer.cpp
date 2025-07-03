#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    vector<int> lis(n,1);
    vector<int> record(n,0);
    int max = 0;
    int idx = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && lis[j] + 1 > lis[i]){
                lis[i] = lis[j] + 1;
                record[i] = j;
            }
        }
        if(max < lis[i]){
            max = lis[i];
            idx = i;
        }
    }

    vector<int> sequence;
    sequence.push_back(arr[idx]);

    while(lis[idx] > 1){
        idx = record[idx];
        sequence.push_back(arr[idx]);
    }
    
    cout << max << '\n';
    for(int i=sequence.size()-1; i>=0; i--) cout << sequence[i] << ' '; 
}       