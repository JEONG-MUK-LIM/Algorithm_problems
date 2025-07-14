#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll min,max;
    cin >> min >> max;
    ll count = max-min+1;
    vector<bool> num(count,false);
    ll cnt_sq = 0;
    ll sq;
    for(ll i=0; sq <= max; i++){
        sq = (i+2)*(i+2);
        ll q = min/sq;
        if(q*sq < min) q++;
        while(q*sq <= max){
            if(!num[q*sq-min]) cnt_sq++; 
            num[q*sq-min] = true;
            q++;
        }
    }
    cout << count - cnt_sq;
}   