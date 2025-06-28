#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;

    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i] <= k){
            count += k / arr[i];
            k = k % arr[i];
        }
    }
    cout << count;
}