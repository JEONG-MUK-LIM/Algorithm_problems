#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,v,w;
    cin >> n >> k;
    vector<int> sum(k+1,0);
    for(int i=0; i<n; i++){
        cin >> w >> v;
        for(int j = k; j>=0; j--){
            if(j >= w){
                sum[j] = max(sum[j],sum[j-w]+v);
            }
        }
    }
    cout << sum[k];
}