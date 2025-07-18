# 문제: 1053(팰린드롬 공장)

팰린드롬이란, 앞에서부터 읽었을 때와, 뒤에서부터 읽었을 때가 같은 문자열이다.

모든 문자열이 팰린드롬이 아니기 때문에 다음과 같은 4가지 연산으로 보통 문자열을 팰린드롬으로 만든다.

1.문자열의 어떤 위치에 어떤 문자를 삽입 (시작과 끝도 가능)

2.어떤 위치에 있는 문자를 삭제

3.어떤 위치에 있는 문자를 교환

4.서로 다른 문자를 교환

1, 2, 3번 연산은 마음껏 사용할 수 있지만, 마지막 연산은 많아야 한 번 사용할 수 있다.

문자열이 주어졌을 때, 팰린드롬으로 만들기 위해 필요한 연산의 최솟값을 출력하는 프로그램을 작성하시오.


## 입력

첫째 줄에 문자열이 주어진다. 영어 소문자로만 이루어져 있고, 길이는 최대 50이다.

## 출력

첫째 줄에 문제의 정답을 출력한다.

## 해결방법

팰린드롬 문자열은 dp로 채워서 해결할 수 있다.

어떤 문자열이 팰린드롬 문자열이 되기 위해서는 1~3번까지의 연산을 하기전의 문자열에 영향을 받는다.

팰린드롬 문자열이 되기위해서는 중간 구간의 문자열 또한 팰린드롬 문자열이기 때문이다.

dp[i][j]는 양끝 문자열이 i,j일 때, 팰린드롬문자열을 만들기 위한 최소한의 연산횟수이다.

양쪽 끝이 같다면, 그 내부 문자열을 확인해야한다.

aXXXXXXa - > XXXXXX 의 양쪽 끝을 확인해서 팰린드롬인지 확인한다.

만약 팰린드롬문자열이 아니라면, 양쪽 끝을 삽입,삭제,교환처리를 해주어야한다.

aXXXb -> a,b에서 XXX을 팰린드롬으로 만든 다음에 한쪽을 교환처리를 한다.(dp[i+1][j-1]에서 +1) 

aXXXb -> aXXXba로 삽입하고 XXXb를 팰린드롬으로 만듬 (dp[i+1][j]에서 +1)

aXXXb -> a를 삭제하고 XXXb를 팰린드롬 문자열로 만듬 (dp[i+1][j]에서 +1)

여기서 삭제,삽입 방향이 바꾸어도 동일한 결과가 나온다.

세가지 선택지가 있고, 처음부터 bottom up으로 팰린드롬 문자열의 길이별로 반복문을 작성하여 팰린드롬을 만들어나가기 위한 횟수를 dp에 저장하여 최종적인 팰린드롬문자열을 만들기 위한 횟수를 구할 수 있다.

여기서 이 문제는 문자열 내부의 교환까지 생각해야 하는데,

잘 생각해보면 최대 1번만 교환할 수 있기 때문에

문자열 내부를 교환한 다음 팰린드롬을 구하는 것과,

팰린드롬을 구하면서 문자열 내부를 교환하는 것은 동일하다는 걸 알 수 있다.

그러므로 반복문으로 swap을 사용한 경우들을 비교하고, swap을 안한 오리지널 문자열의 최소 횟수를 비교해서 최솟값을 출력한다.

## 복잡도

o(n^4)