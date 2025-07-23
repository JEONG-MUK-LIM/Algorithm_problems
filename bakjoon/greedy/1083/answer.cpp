#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,s;
    cin >> n;
    vector<int> arr(n);
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> s;

    
    for(int i=0; i<n && s > 0; i++){
        int maxIdx = i;
        for(int j=i+1; j<n && j-i <= s; j++){
            if(arr[j] > arr[maxIdx]) maxIdx = j;
        }
        for(int j=maxIdx; j>i; j--){
            swap(arr[j],arr[j-1]);
        }
        s -= (maxIdx - i);
    }
    for(int i:arr) cout << i << ' ';
}