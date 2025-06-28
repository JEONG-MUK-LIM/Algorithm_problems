#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> find(vector<int>& arr,int c){
    vector<int> arr3(1,0);
    for(int k=0; k<arr.size(); k++){
        int size = arr3.size();
        for(int i=0; i<size; i++){
            if(arr3[i]+arr[k] <= c){
                arr3.push_back(arr3[i]+arr[k]); 
            }
        }
    }
    return arr3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,c;
    vector<int> arr;
    cin >> n >> c;
    for(int i=0; i<n; i++){
        int w;
        cin >> w;
        if(w <= c) {
            arr.push_back(w);
        }
    }
    int size = arr.size()/2;
    vector<int> arr1(size);
    vector<int> arr2(arr.size() - size);
    for(int i=0; i<size; i++){
        arr1[i] = arr[i];
    }
    for(int i=0; i<arr2.size(); i++){
        arr2[i] = arr[i+size];
    }
    vector<int> arr3;
    vector<int> arr4;
    arr3 = find(arr1,c);
    arr4 = find(arr2,c);
    sort(arr4.begin(),arr4.end());
    int count = 0;
    for(int i=0; i<arr3.size(); i++){
        int idx = upper_bound(arr4.begin(),arr4.end(),c - arr3[i]) - arr4.begin();
        count += idx;
    }
    cout << count;
}