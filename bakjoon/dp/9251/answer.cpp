#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1,str2;
    cin >> str1 >> str2;

    int size1 = str1.size();
    int size2 = str2.size();

    vector<vector<int>> matrix(size1+1,vector<int>(size2+1,0));

    for(int i=1; i<size1+1; i++){
        for(int j=1; j<size2+1; j++){
            if(str1[i-1] != str2[j-1]) matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
            else matrix[i][j] = matrix[i-1][j-1] + 1;
        }
    }
    cout << matrix[size1][size2];
}