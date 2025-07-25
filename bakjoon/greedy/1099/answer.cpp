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
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    vector<vector<int>> cardColor(n);
    //카드를 움직일 때, 한번에 하나의 카드가 아닌 여러개의 여러색의 카드를 한번에 옮길 수 있음
    // 하나의 박스에 같은색의 카드가 9개를 넘지않는다고 했지만 그건 입력받는 경우만으로 한정됨 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] > 0) cardColor[i].push_back(j);
        }
    }
    vector<bool> oneColorBox(m,0);
    vector<bool> notNeedMove(n,0);
    for(int i=0; i<n; i++){
        if(cardColor[i].size() == 0){ // 카드가 0개인 경우도 움직일 필요가 없음
            notNeedMove[i] = true;
        }
        if(cardColor[i].size() == 1 && !oneColorBox[cardColor[i][0]]){
            oneColorBox[cardColor[i][0]] = true;
            notNeedMove[i] = true;
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(!notNeedMove[i]) cnt++;  
    }
    cout << (cnt > 0 ? cnt - 1 : cnt); // 조커박스로 지정해도 의미없는 경우가 있을 수있음
}