#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

vector<bool> isPrime;
pair<int,int> two_prime(int num){
    for(int i=2; i<=num/2; i++){
        if(isPrime[i] == 1 && isPrime[num-i] == 1)
            return {i,num-i};
    }
    return {-1,-1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    isPrime.resize(n+1,1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i=2; i*i<n; i++){
        for(int j=i*i; j <= n; j+= i){
            isPrime[j] = 0;
        }
    }
    if(n < 8) {cout << -1; return 0;}
    int a,b,c,d;
    if(n % 2 == 0) {
        a = b = 2;
        tie(c,d) = two_prime(n-4);
    }
    else{
        a = 2; b = 3;
        tie(c,d) = two_prime(n-5);
    }
    if(c == -1) cout << -1;
    else {
        cout << a << ' ' << b << ' ' << c << ' ' << d;
    }
}   