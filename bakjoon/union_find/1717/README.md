# 문제: 1717(집합의 표현)

초기에 
n+1개의 집합 
0,1,2,3,...,n이 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

## 입력

첫째 줄에 
n, m이 주어진다. (n<=1e6, m <= 1e5, 0 <= a,b <=n, a와 b는 같을 수도 있다)
m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0,a,b의 형태로 입력이 주어진다. 이는 
a가 포함되어 있는 집합과, 
b가 포함되어 있는 집합을 합친다는 의미이다. 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1,a,b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.

## 출력

1로 시작하는 입력에 대해서 
a와 b가 같은 집합에 포함되어 있으면 "YES" 또는 "yes"를, 그렇지 않다면 "NO" 또는 "no"를 한 줄에 하나씩 출력한다.

## 해결방법

먼저 union - find란 disjoint-set(서로소집합, 교집합이 없는 두 집합)을 이용하는 것으로 

여러개의 원소가 존재할 때, 이 원소들이 어떤 집합에 속해 있는지 파악하고 두 그룹을 합치는 연산을 효율적으로 진행한다.

각 집합에는 루트(id)가 존재하며 루트와의 비교로 각각 어떤 집합에 속해있는지 판단한다.

또한 집합내 루트가 다른 원소로 이어지지 않는다면 그 집합은 사이클이 존재하지 않음을 판단할 수 있다.

find(u) 함수로 u의 루트(id)를 리턴하고, union(u,v)로 u와 v를 같은 id를 갖는 트리로 합치게 된다.

union일때는 한 집합의 루트노드를 다른 집합의 루트노드로 바꿔놓기만 하고, 실제 루트노드의 변화는 find함수에서 바꿔준 다음 루트노드를 반환하게 된다. (필요할 때 연산을 진행하는 것을 lazy evaluation 이라고 함)

이때 find 함수에서 찾아가는 모든 노드의 부모를 한번에 대표노드로 바꿔준다. (경로압축,Path Compression)

경로 압축을 하지 않으면 매번 루트노드의 루트노드의.... 루트노드를 찾아야하므로 최악의 경우 find에 n번의 연산이 걸리는데, 한번 경로압축을 해놓으면 다음에는 o(1)에 찾을 수 있게 된다.

## 복잡도

초기화: o(n), find: o(α(N)) α(N)는 5이하의 매우 작은 값

union : o(α(N)), 전체 연산 o(M*(α(N)))
