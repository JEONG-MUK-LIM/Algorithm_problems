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
    vector<string> str(n);
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    vector<bool> prefix(n,0);
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(str[j] < str[i] || i == j) continue;
            if(prefix[j]) continue;     //중복으로 체크되는 것만 스킵
            bool check = 1;
            for(int k=0; k<str[i].size(); k++){
                if(str[i][k] != str[j][k]) {check = 0; break;}
            }
            if(check) { prefix[i] = 1; break;}
        }
    }
    for(int i=0; i<n; i++) if(!prefix[i]) cnt++;
    cout << cnt;
}   