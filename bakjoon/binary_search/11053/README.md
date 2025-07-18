# 문제:11053(LIS,가장 긴 증가하는 부분 수열)

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {__10__, __20__, 10, __30__, 20, __50__} 이고, 길이는 4이다.

## 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

## 출력

첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

## 해결방법

오로지 lis의 길이만을 구하는 문제이므로

각각 동적프로그래밍과 이분탐색방법을 사용할 수 있다.

수열의 값을 모두합쳐도 10^6 이므로 int를 사용한다.

<br/>

동적프로그래밍은 n^2의 시간이 걸린다.

탐색시 해당 원소가 이전까지의 원소보다 크다면 

지금의 lis값과 이전까지의 lis에서 + 1 한 것 중에 큰 것을 선택할 수 있다.
```
for(int i=0; i<n; i++){
    lis[i] = 1
    for(int j =0; j<i; j++){ 
    if (arr[i] > arr[j]) lis[i] = max(lis[i],lis[j] + 1) 
    }
}
```

이후 가장 큰 값을 lis배열에서 찾는다.

<br/>

이분탐색으로 풀기 위해선 해당 원소가 LIS에서 몇번째의 원소가 될 수 있는지 파악할 필요가 있다.

log n의 시간이 걸리므로 그리 오래걸리는 작업이 아니다.

실제 함수로 구현할 수도 있고 algorithm 헤더의 lower_bound(arr,arr+n,key) - arr을 이용 할 수 도있다.

참고로

upper_bound 는 key 값보다 큰 숫자의 반복자 + 인덱스를,

lower_bound 는 key 값보다 같거나 큰 숫자의 반복자 + 인덱스를 리턴한다.


해당 원소의 위치를 파악한 이후 lis를 업데이트하는 식으로 반복한다.

단, 그 lis가 진짜 lis를 의미하지는 않는다. 

입력이 만약 10 20 1 2 10으로 주어졌을 때,

10 -> 10 20 -> 1 20 -> 1 2 -> 1 2 10 으로 답은 3이된다.

<br/>

하지만 다른 입력인 10 20 1 로 주어진다면

10 -> 10 20 -> 1 20 으로 배열의 lis는 1 20 이지만 실제 lis는 10 20이 된다.

실제 lis를 구하기 위해선 추가적인 정보를 저장해야한다.

그 정보는 lis의 길이가 늘어나는 순간의 데이터 일 것이다.

그러므로 입력받은 배열의 각 a_i 에서 lis를 업데이트 한 위치를 따로 record[i]에 기록한다.

그리고 마지막으로 길이가 늘어난 순간의 데이터가 실제 lis의 마지막 원소가 되므로 

lis.size() - 1과 일치하는 record[i]의 마지막 원소를 찾고, 그 원소를 벡터에 추가한다.

그리고 lis.size() - 2 와 일치하는 record[i]의 마지막 원소를 찾고... 

이런 식으로 반복 할 것이니

반복문을 역방향으로 하도록 한다.

## 복잡도

n번의 연산에서 각각 이분탐색으로 log n 의 시간을 사용하므로

시간복잡도는 o(nlogn)이 되고, 공간복잡도는 n개의 배열을 3개 사용하므로 o(n)이 된다.

