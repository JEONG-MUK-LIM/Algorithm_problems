#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull n,m;
    cin >> n >> m;
    vector<ull> sum(n,0);
    vector<ull> remainder(m,0);
    cin >> sum[0];
    remainder[sum[0]%m]++; 
    for(int i=1; i<n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
        remainder[sum[i]%m]++;
    }
    remainder[0]++;
    ull result = 0;
    for(int i=0; i<m; i++){
        result += remainder[i] * (remainder[i] - 1) / 2;
    }
    cout << result;
}