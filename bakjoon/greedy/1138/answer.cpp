#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> sequence(n,n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(cnt == num && sequence[j] == n) {sequence[j] = i+1; break;}
            if(sequence[j] >= i+1) cnt++;     
        }
    }
    for(int i:sequence) cout << i << ' ';   
}   