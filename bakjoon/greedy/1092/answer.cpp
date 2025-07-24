#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> m;
    vector<int> weight(m);
    for(int i=0; i<m; i++){
        cin >> weight[i];
    }
    sort(arr.begin(),arr.end(),greater<int>());
    sort(weight.begin(),weight.end(),greater<int>());

    if(arr[0] < weight[0]){
        cout << -1;
        return 0;
    }

    int minute = 0;

    vector<bool> moved(m,0);
    vector<int> pos(n,0);
    int rest = m;
    while(rest > 0){
        for(int i=0; i<n; i++){
            int idx = pos[i];
            for(int j=idx; j<m; j++){
                pos[i]++;
                if(!moved[j] && weight[j] <= arr[i]){
                    moved[j] = true;
                    rest--;
                    break;
                }
            }
        }
        minute++;
    }
    
    cout << minute;
}