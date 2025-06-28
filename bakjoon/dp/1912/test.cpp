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

    int max = arr[0];
    int pre_max = max;
    for(int i=1; i<n; i++){
        if(max + arr[i] < arr[i]){
            max = arr[i];
            if(pre_max < max) pre_max = max;
        }
        else {
            max += arr[i];
            if(pre_max < max) pre_max = max;
        }
    }
    cout << pre_max;

    return 0;
}