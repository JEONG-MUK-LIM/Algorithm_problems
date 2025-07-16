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

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    cout << arr[0] * arr[n-1];  
    // 1과 그 자체의 값을 제외한 약수들에서 가장 작은 약수와 큰 약수를 곱하면 원래의 값이 나온다
}       