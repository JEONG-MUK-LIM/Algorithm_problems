#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector<int> need;
int ans = 0;
vector<int> available;
void backtrack(int mask,int choose,int k,int n,int cur){
    if(k == choose){
        int count = 0;
        for(int i=0; i<n; i++){
            if((need[i] & mask) == need[i]) count++;
        }
        ans = max(ans,count);
        return;
    }

    for(int i=cur; i<available.size(); i++){
        backtrack(mask | (1 << available[i]),choose+1,k,n,i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin >> n >> k;

    unordered_map<char,int> toInt;
    string alpabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<26; i++){
        toInt.insert({alpabet[i],i});
    }
    need.resize(n,0);
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++){
            need[i] |= (1<<toInt[str[j]]);
        }
    }
    if(k < 5) cout << 0;
    else{
        int mask = (1<<toInt['a']);
        mask |= (1 <<toInt['n']);
        mask |= (1 << toInt['c']);
        mask |= (1 << toInt['t']);
        mask |= (1 << toInt['i']);
        for(int i=0; i<26; i++){
            if(i == toInt['a'] 
                || i == toInt['n'] 
                ||i == toInt['c'] 
                ||i == toInt['t'] 
                || i == toInt['i']) continue;
            available.push_back(i);
        }
        backtrack(mask,5,k,n,0);
        cout << ans;
    }
}           