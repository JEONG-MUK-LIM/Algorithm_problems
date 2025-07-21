#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void reverse(vector<string>& matrix,int r,int c){
    for(int i=r; i<r+3; i++){
        for(int j=c; j<c+3; j++){
            matrix[i][j] = (matrix[i][j] == '0')? '1':'0';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;

    vector<string> matrix(n);
    vector<string> obj(n);
    for(int i=0; i<2*n; i++){
        string str;
        if(i<n) cin >> matrix[i];
        else cin >> obj[i-n];
    }
    int cnt = 0;
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-2; j++){
            if(matrix[i][j] != obj[i][j]) {
                reverse(matrix,i,j); cnt++;
            }
        }
    }
    bool check = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] != obj[i][j]) {
                check = 0;
                break;
            }
        }
        if(!check) break;
    }
    if(check) cout << cnt;
    else cout << -1;
}           