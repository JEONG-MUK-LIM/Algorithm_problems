#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;   
 
void backtrack(vector<pair<int,int>>& point,vector<bool>&visited,int& n,int count,int next,double& minVal){
    if(count == n/2){
        int resultX = 0;
        int resultY = 0;
        for(int i=0; i<n; i++){
            if(visited[i]) {
                resultX += point[i].first;
                resultY += point[i].second;
            }
            else {
                resultX -= point[i].first;
                resultY -= point[i].second;
            }
        }
        double d = sqrt((double)resultX*resultX + (double)resultY*resultY);
        if(minVal == -1 || minVal > d) minVal = d;
    }
    for(int i=next; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            backtrack(point,visited,n,count+1,i,minVal);
            visited[i] = false;
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<pair<int,int>> point(n);
        vector<bool> visited(n,0);
        double minVal = -1;
        for(int i=0; i<n; i++){
            cin >> point[i].first >> point[i].second;
        }
        backtrack(point,visited,n,0,0,minVal);
        cout << fixed << setprecision(6) << minVal << '\n';
        minVal = -1;
    }
}       