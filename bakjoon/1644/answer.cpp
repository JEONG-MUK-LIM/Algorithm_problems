#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<bool> isPrime(N+1,1);
    vector<int> prime;
    int i=2;
    for(int i=2; i<=N; i++){
        for(int j=2; i*j <=N; j++){
            isPrime[i*j] = 0;
        }
    }
    for(int i=2; i<=N; i++){
        if(isPrime[i]) prime.push_back(i);
    }
    int count = 0;
    int begin = 0;
    int end = 0;
    int sum = 0;
    while(begin != prime.size()){
        if(sum < N && end < prime.size()){
            sum += prime[end++];
        }
        else{
            if(sum == N) count++;
            if(begin < prime.size()) sum -= prime[begin++];
        }
    }
    cout << count;
}