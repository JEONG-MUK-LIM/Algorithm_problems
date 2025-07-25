#include <iostream>
#include <vector>
#include <algorithm>
#include <string>   //문자열 비교를 위한 헤더추가
#include <cmath>

using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

string base;

int cost(int l,int len, const string& str){
    string str2 = base.substr(l,len);
    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        if(str2[i] != str[i]) cnt++;
    }
    string copy = str;
    sort(copy.begin(),copy.end());
    sort(str2.begin(),str2.end());
    if(copy == str2) return cnt;
    else return 1e9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> base;
    int n;
    cin >> n;
    vector<string> word(n);
    for(int i=0; i<n; i++){
        cin >> word[i];
    }
    int size = base.size();
    
    vector<int> dp(size+1,1e9);
    dp[0] = 0;
    
    for(int i=0; i<size; i++){
        if(dp[i] == 1e9) continue; 
        for(int k=0; k<n; k++){
            int len = word[k].size();
            if(len + i > size) continue;
            int c = cost(i,len,word[k]);
            if(c == 1e9) continue;
            dp[i+len] = min(dp[i]+c,dp[i+len]); 
        }
    }
    if(dp[size] == 1e9)cout << -1;
    else cout << dp[size];
}