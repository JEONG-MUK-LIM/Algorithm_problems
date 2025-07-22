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
    
    int n,m;
    cin >> n;
    vector<int> arr(n);
    int first = -1;
    int minCostIdx = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(i!=0 && (first == -1 || arr[first] > arr[i])) first = i;
        if(arr[minCostIdx] > arr[i]) minCostIdx = i;
    }
    cin >> m;
    
    if(first == -1 || m < arr[first]){
        cout << 0; // 0이외 숫자가 없는경우, 0이외 숫자를 선택할 수 없는 경우
        return 0;
    }
    int size = 0;
    m -= arr[first];
    if(m >= 0) {
        size++;
        size +=(m / arr[minCostIdx]);
        m %= arr[minCostIdx];
    }
    vector<int> number(size,minCostIdx);
    number[0] = first;
    for(int i=0; i<size; i++){
        for(int j=n-1; j>=0; j--){
            int cost = arr[j] - (i==0 ? arr[first] : arr[minCostIdx]);
            if(cost <= m && j > number[i]){
                m -= cost;
                number[i] = j;
                break;
            }
        }
    }
    for(int i:number) cout << i;
}