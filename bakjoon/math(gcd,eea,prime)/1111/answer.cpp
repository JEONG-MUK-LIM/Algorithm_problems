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
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    if(n == 1) {cout << 'A';}
    else if(n == 2){
        if(arr[0] == arr[1]) cout << arr[0]; // 두 값이 같으면 세번째는 반드시 같은 수여야함
        else cout << 'A';               //같지 않으면 무수히 많은 수가 가능
    }
    else{
        int a,b;
        
        if(arr[1] - arr[0] == 0) { a = 0; }     //두 값이 같을 때
        else if((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0){ // a가 정수가 아닌경우
            cout << 'B';
            return 0;
        }
        else {
            a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
        }
        b = arr[1] - a*arr[0];
        bool isB = 0;
        for(int i=2; i<n; i++){
            if(arr[i] !=  (arr[i-1] * a + b)) {isB=1; break;}
        }
        if(isB) cout << 'B';
        else cout << arr[n-1]*a + b;
    }
}