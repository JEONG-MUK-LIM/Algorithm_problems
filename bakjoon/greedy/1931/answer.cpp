#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare2(pair<int,int>a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    int begin,end;
    vector<pair<int,int>> arr(n);
    
    for(int i=0; i<n; i++){
        cin >> begin >> end;
        arr[i] = {begin,end};
    }
    sort(arr.begin(), arr.end(), compare2);

    int preEnd = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(preEnd <= arr[i].first){
            preEnd = arr[i].second;
            count++;
        }
    }
    cout << count;
}