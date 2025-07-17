#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin >> n;
    vector<string> str(n);
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    cin >> k;

    unordered_map<char,int> hash; //알파벳을 숫자로 변환할 해시
    unordered_map<int,char> hash2; // 숫자를 알파벳으로 변환할 해시
    string alpabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<36; i++){
        if(i<10){
            hash.insert({i+'0',i});
            hash2.insert({i,i+'0'});
        }
        else{   
            hash.insert({alpabet[i-10],i});
            hash2.insert({i,alpabet[i-10]});
        }
    }
    int num [60][36] = {0,};        //각 자리수의 숫자의 개수
    for(int i=0; i<n; i++){ 
        int size = str[i].size()-1;
        for(int j=size; j>=0; j--){
            num[size-j][hash[str[i][j]]]++;
        }
    }
    for(int i=0; i<60; i++){        //캐리아웃
        for(int j=0; j<36; j++){
            while(num[i][j] >= 36) {
                num[i+1][j]++;
                num[i][j] -= 36; 
            }
        }
    }

    int change[60][36]{0,};         //숫자를 Z로 변화시 각 자리수 변화량
    for(int i=0; i<60; i++){
        for(int j=0; j<36; j++){
            int increase = num[i][j] * (35 - j);
            if(increase > 0){
                if(increase >= 36) change[i+1][j] += increase/36; 
                change[i][j] += increase % 36;
                while(change[i][j] >= 36){
                    change[i+1][j]++;
                    change[i][j] -= 36;
                } 
            }
        }   
    }

    unordered_set<int> selected;  //숫자 k개 선택
    while(k--){
        int maxChange = 0;
        int maxIdx = -1;
        for(int i=59; i>=0; i--){
            for(int j=0; j<36; j++){
                if(selected.count(j)) continue;
                if(maxChange < change[i][j]){
                    maxChange = change[i][j];
                    maxIdx = j;
                }
                else if(maxChange > 0 && maxChange == change[i][j]){ //선택시 가장 높은 자리수의 변화가 같은 숫자가 있으면 더 확인
                    for(int l=i-1; l>=0; l--){
                        if(change[l][maxIdx] < change[l][j]) {
                            maxChange = change[i][j];
                            maxIdx = j; 
                            break;
                        }
                        else if(change[l][maxIdx] > change[l][j]) break;
                    }
                }
            }
            if(maxIdx != -1) break;
        }
        if(!selected.count(maxIdx)){
            selected.insert(maxIdx);
        }
    }

    int result[60]{0,};
    for(auto iter:selected){
        for(int i=0; i<60; i++){
            result[i] += change[i][iter];
        }
    }
    for(int i=0; i<60; i++){
        int sum = 0;
        for(int j=0; j<36; j++){
            sum += num[i][j] * j;
        }
        result[i+1] += sum / 36;
        result[i] += sum % 36;

        if(result[i] >= 36){
            result[i+1] += result[i] / 36;
            result[i] = result[i] % 36;
        }
    }

    
    bool first = 0;
    for(int i=59; i>=0; i--){
        if(result[i] != 0){
            first = 1;
        }
        if(first || i==0) cout << hash2[result[i]];
    }
}         