#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;   

bool check2(string& str, int size,int idx);

bool check1(string& str,int size, int idx){
    if(idx + 2 >= size || str[idx] != '1' || str[idx+1] != '0' || str[idx+2] !='0') return false;
    while(idx + 3 < size && str[idx + 3] == '0') idx++;
    idx += 3;
    if(idx >= size || str[idx] != '1') return false;
    if(idx == size-1 && str[idx] == '1') return true;
    while(idx + 1 < size && str[idx + 1] == '1'){
        if(check1(str,size,idx+1)) return true;
        idx++;
    }
    if(idx == size-1 && str[idx] == '1') return true;
    return (check2(str,size,idx+1));
}
bool check2(string& str, int size,int idx){
    if(idx + 1 >= size || str[idx] != '0' || str[idx+1] !='1') return false; 
    if(idx + 1 == size-1 && str[idx] == '0' && str[idx+1] == '1') return true;
    return (check1(str,size,idx+2) || check2(str,size,idx+2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        if(check1(str,str.size(),0) || check2(str,str.size(),0)) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}   