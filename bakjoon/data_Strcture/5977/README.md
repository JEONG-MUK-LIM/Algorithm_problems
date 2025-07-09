# 문제: 5977(Mowing the Lawn)

After winning the annual town competition for best lawn a year ago, Farmer John has grown lazy; he has not mowed the lawn since then and thus his lawn has become unruly. However, the competition is once again coming soon, and FJ would like to get his lawn into tiptop shape so that he can claim the title.

Unfortunately, FJ has realized that his lawn is so unkempt that he will need to get some of his N (1 <= N <= 100,000) cows, who are lined up in a row and conveniently numbered 1..N, to help him. Some cows are more efficient than others at mowing the lawn; cow i has efficiency E_i (0 <= E_i <= 1,000,000,000).

FJ has noticed that cows near each other in line often know each other well; he has also discovered that if he chooses more than K (1 <= K <= N) consecutive (adjacent) cows to help him, they will ignore the lawn and start a party instead. Thus, FJ needs you to assist him: determine the largest total cow efficiency FJ can obtain without choosing more than K consecutive cows.

1년 전 마을 최고의 잔디밭 대회에서 우승한 후, 농부 존은 게으르게 변했습니다. 그 이후로 잔디를 깎지 않아 잔디밭이 엉망이 되었습니다. 하지만 곧 다시 대회가 열리고, FJ는 우승을 차지하기 위해 잔디밭을 최상의 상태로 만들고 싶어 합니다.

안타깝게도 FJ는 잔디밭이 너무 관리가 안 되어 N마리(1 <= N <= 100,000)의 소 중 몇 마리를 데려와야 한다는 것을 깨달았습니다. 소들은 일렬로 줄지어 있고 편의상 1~N으로 번호가 매겨져 있습니다. 어떤 소들은 다른 소들보다 잔디 깎는 데 더 효율적입니다. 소 i의 효율성은 E_i(0 <= E_i <= 1,000,000,000)입니다.

FJ는 줄지어 서 있는 소들이 서로 잘 아는 경우가 많다는 것을 알아챘습니다. 또한 K마리(1 <= K <= N) 이상의 연속된(인접한) 소를 선택했을 때, 그 소들이 잔디밭을 무시하고 무리를 지어 이동한다는 사실도 발견했습니다. 따라서 FJ는 여러분의 도움이 필요합니다. K마리 이상의 연속된 소를 선택하지 않고도 FJ가 얻을 수 있는 최대 총 소 효율을 계산해 보세요.

힌트:
FJ는 효율성이 순서대로 1, 2, 3, 4, 5인 소 다섯 마리를 가지고 있습니다. 그는 소들의 총 효율성이 극대화되도록 소들을 선택하고 싶지만, 연속된 소는 두 마리 이상 선택할 수 없습니다.

FJ는 세 번째 소를 제외한 모든 소를 선택합니다. 따라서 소들의 총 효율성은 1 + 2 + 4 + 5 = 12입니다.

## 입력

Line 1: Two space-separated integers: N and K
Lines 2..N+1: Line i+1 contains the single integer: E_i

## 출력

Line 1: A single integer that is the best total efficiency FJ can obtain.

## 해결방법

dp[i]는 i까지 입력받았을 때 나타낼 수 있는 최댓값이라고 하자

점화식으로 나타내보면 dp[i] = dp[i-k-1] + (i-k+1 부터 i까지의 합) k개, i-k를 선택하지 않는다는 의미
                         
                         = dp[i-k+2] + (i-k+2 부터 i까지의 합) k-1개, i-k+1을 선택하지 않는다

                         ...

                         = dp[i-1] , i를 선택하지 않는다

(이때, i > k 여야한다.  i<=k라면 1부터 i까지의 합이 dp[i]가 된다.)

즉 i-k부터 i까지 까지 가장 작은 값을 찾는 것이고 

이는 11003번에서 했던 연속된 입력을 받는 동안 정해진 구간에서의 최솟값을 구하는 알고리즘과 동일하다.

데큐를 사용하지 않으면 o(n^2)이 되기 때문에 문제를 시간내로 풀 수 없다.

데큐에 선택하지 않을 원소의 인덱스 (마지막에 연속되는 원소의 인덱스 - 1)를 이용해 마지막에 연속될 구간의 길이를 알아낼 수 있다.

데큐 내의 존재할 수 있는 인덱스들의 조건 두가지를 이용해 답을 구한다.

<br/>

조건 1. 구간의 길이가 k를 넘어간다면 그 구간을 더이상 이용하지 못하므로 덱의 앞에서 제거한다.

''''  ''''   '''' 같은 형태는  [''''   '''']  '''' 에 포함되니 신경 쓸 것 없다.
    ^
  사용하지 않을 원소위치

''''  '''''''' 가 가능하다면 조건1이 발동될 일은 없다.
<br/>

조건 2. 덱의 쌓여 있는 선택하지 않을 원소의 위치들을 이용해 구한 dp[i]값이 dp[i-1]보다 작다면 그 인덱스들은 쓸모 없으므로 제거

조건1에서 범위를 벗어나는 인덱스를 제거했으니 데큐안에 있는 원소들은 모두 선택하지 않을 원소들의 가능한 위치가 된다.

그리고 dp[i]는 dp[i-1] 부터 dp[i-k-1] + (i-k+1부터 i까지 구간합) 까지의 값을 갖는다.

여기서 데큐의 쌓여있는 인덱스(선택하지 않을 원소)로 dp[i]를 구하면 

dp[dq.back()-1] + (dq.back()+1부터 i까지 구간합)이 된다.

그런데 dp[i-1]은 이미 알고 있는 상황이고, dp[i-1]보다 작다면 그 값을 굳이 덱에 넣어두고 있을 필요가 없다.

생각해보면 dp[i-1]보다 작으면서 i번째를 선택한 경우가 dp[i-1] + num[i+1]보다 값이 클 리가 없고 선택될 리도 없기 때문이다.


이러한 방법이 사용가능한 이유는 데큐안에는 구간의 시작점이 오래된 순으로 들어가고(push_back만 사용) , 맨 앞쪽 후보가 범위내에 있다면 항상 뒤의 값보다 더 최적의 값을 가짐을 보장하기 때문에 뒤의 값은 앞으로도 사용할 수 없는 값이 되기 때문이다.

그리고 맨 앞쪽 후보가 범위를 벗어나 pop_front()하게 된다면, 덜 좋은 값은 진작에 pop해서 제거 되었고, 오래 남아 있는 값일 수록 맨 앞쪽 후보에 가까운 값을 가지게 되므로 두번째 있는 값이 최적의 값이 된다.

(dp[i] = dp[dq.front()-1] + {구간합} 이므로 맨앞쪽 원소 자체는 dp에 포함된다.)

## 복잡도

o(n)