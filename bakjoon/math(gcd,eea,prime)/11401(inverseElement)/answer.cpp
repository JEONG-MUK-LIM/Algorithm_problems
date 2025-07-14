#include <iostream>
using namespace std;

typedef long long ll;

#define modulus 1000000007

ll EEA(ll a){
    ll t1 = 0;
    ll t2 = 1;
    ll x1 = modulus;
    ll x2 = a;
    while(x2 != 1){
        ll q = x1 / x2;
        ll r = x1 % x2;
        ll t = t1 - q*t2;
        x1 = x2;
        x2 = r;
        t1 = t2;
        t2 = t;
    }
    if(t2 < 0) t2 += modulus;
    return t2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    ll nPk = 1;
    ll reverse = 1;
    cin >> n >> k;
    if(k == 0 || k == n) {
        cout << 1;
        return 0;
    }
    for(int i=1; i<=n; i++){
        nPk = (nPk * i) % modulus;
    }
    for(int i=1; i<=k; i++){
        reverse = (reverse * i) % modulus;
    }
    for(int i=1; i<=n-k; i++){
        reverse = (reverse * i) % modulus; 
    }   

    cout << (nPk * EEA(reverse) % modulus);
}