#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define modulus 1000000007;

typedef unsigned long long ull;

unordered_map<ull,ull> memo;

ull divCon(ull n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(memo.count(n)) return memo[n];

    ull k = n/2;
    ull result;
    if(n % 2 == 0){
        ull a = divCon(k);
        ull b = divCon(k+1);
        b = (b + divCon(k-1)) % modulus;

        result = (a * b) % modulus;
    }
    else {
        ull a = (divCon(k+1)) % modulus;
        a = (a*a) % modulus;
        ull b = (divCon(k)) % modulus;
        b = (b*b) % modulus;
        result = (a + b) % modulus;
    } 
    return memo[n] = result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ull n;
    cin >> n;
    if(n == 0) cout << 0;
    else if(n == 1) cout << 1;
    else if(n == 2) cout << 1;
    else cout << divCon(n);
}