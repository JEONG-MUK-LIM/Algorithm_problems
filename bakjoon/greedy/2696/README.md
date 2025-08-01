# 문제:2696(중앙값 구하기)

어떤 수열을 읽고, 홀수번째 수를 읽을 때 마다, 지금까지 입력받은 값의 중앙값을 출력하는 프로그램을 작성하시오.

예를 들어, 수열이 1, 5, 4, 3, 2 이면, 홀수번째 수는 1번째 수, 3번째 수, 5번째 수이고, 1번째 수를 읽었을 때 중앙값은 1, 3번째 수를 읽었을 때는 4, 5번째 수를 읽었을 때는 3이다.

## 입력

첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 각 테스트 케이스의 첫째 줄에는 수열의 크기 M(1 ≤ M ≤ 9999, M은 홀수)이 주어지고, 그 다음 줄부터 이 수열의 원소가 차례대로 주어진다. 원소는 한 줄에 10개씩 나누어져있고, 32비트 부호있는 정수이다.

## 출력

각 테스트 케이스에 대해 첫째 줄에 출력하는 중앙값의 개수를 출력하고, 둘째 줄에는 홀수 번째 수를 읽을 때 마다 구한 중앙값을 차례대로 공백으로 구분하여 출력한다. 이때, 한 줄에 10개씩 출력해야 한다.

## 해결방법

중앙값이란 수열의 중앙에 위치한 값이다.

수열의 개수가 홀수개라면 중간에 위치한 값이고

짝수개라면 중간의 위치한 두 값의 평균을 중앙값으로 한다.

즉 주어진 모든 원소의 입력을 기억하고 있어야한다는 것이다.

매번 입력이 주어질 때 마다 주어진 원소의 위치를 알아낼 필요가 있으며 현재의 중앙 값이 어딘지 알고 있어야 한다.

내가 떠오른 방법은 세가지이다.

1. 입력 받을 때마다 매번 정렬하고 중간의 인덱스의 값을 구한다.

2. 이분탐색을 이용하여 중간의 위치를 구한다.

3. 수열의 절반을 나눠 각각 최대 힙과 최소 힙으로 만든다.

<br/>

1번선택시에는 최악의 경우 n^2이 넘는 연산을 하게 된다.

(Σ x log x = log 1 + 2 log 2 + ... + n log n) 

n = T * M 이므로 10^10이면 1억이 넘으므로 시간제한인 1초를 초과할 것이다.

<br/>

2번을 선택한다면 배열을 이용해서는 안된다. 

값을 삽입할 위치가 맨앞이라면 그 뒤에 있는 모든 원소를 한칸씩 이동시켜야 하기 때문에 시간제한에 걸릴 것이다. 

그러므로 연결 리스트를 이용해서 포인터만 옮겨줘야 하는데 그러면 이분탐색을 할 수 없다.

<br/>

수열의 절반을 나눠 큰 쪽 절반은 최소 힙으로 넣고 작은 쪽 절반은 최대 힙으로 만드는 방법을 이용해보자.

첫번째 입력을 아무 힙에나 넣고 다음 입력부터 어떤 힙에 넣을지 대소비교로 알아낸다.

중앙값을 알아내기 위해 최대 힙과 최소 힙의 크기가 2이상의 차이가 없도록 해야 하므로 적절히 값을 이동시키면 된다.

예를 들어 11개의 입력이라면 크기가 각각 5,6인 힙에서 6인 쪽이 중앙 값을 가질 것이다. 

## 복잡도

한번의 값의 입력에서 힙에 값을 넣고 빼는 연산을 하므로 

k * log n (k는 상수, n = 1, 2,...,m)의 연산을 한다. 

어림잡아서 최악의 경우 o(nlogn)의 복잡도를 가지므로 시간제한내 풀 수 있다.
