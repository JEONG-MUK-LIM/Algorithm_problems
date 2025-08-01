# 문제: 1099(알 수 없는 문장)

형택이와 그의 친구들은 자꾸 다른 사람들이 대화를 엿듣는 것이 짜증났다. 따라서, 새로운 언어를 만들었다.

이 언어에는 단어가 N개 있다. 그리고 이 언어의 문장은 단어를 공백없이 붙여쓴 것이다. 이 문장에서 각 단어는 0번 또는 그 이상 나타날 수 있다. 이 언어가 형택스러운 이유는 (특별한 이유는) 단어에 쓰여 있는 문자의 순서를 바꿔도 되기 때문이다. 이때, 원래 단어의 위치와 다른 위치에 있는 문자의 개수 만큼이 그 순서를 바꾼 단어를 만드는 비용이다. 예를 들어, abc란 단어가 있을 때, abc는 비용 0으로 만들 수 있고, acb, cba, bac는 비용 2로 바꿀 수 있고, bca, cab는 비용 3으로 바꿀 수 있다.

따라서, 한 문장을 여러 가지 방법으로 해석할 수 있다. 이때 비용의 최솟값을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 문장이 주어진다. 문장의 길이는 최대 50이다. 둘째 줄에 단어의 개수 N이 주어지며, N은 50보다 작거나 같은 자연수이다. 셋째 줄부터 N개의 줄에 각 단어가 주어진다. 단어의 길이는 최대 50이다. 문장과 단어는 알파벳 소문자로만 이루어져 있다.

## 출력

첫째 줄에 문제의 정답을 출력한다. 만약 문장을 해석할 수 없다면 -1을 출력한다.

## 해결방법

단어 내에서는 문자의 순서가 바뀌어도 되지만 단어간 문자 이동은 안된다.

단어 내부에 들어간 알파벳의 개수가 같은지 확인하기 위해서는 정렬을 이용하면 된다.

그리고 string 간 같은지 확인하는 것은 <string> 헤더를 추가하고 변수들처럼 == 기호를 사용하면

문자열 내부의 문자 하나하나를 비교하면서 같은지 확인한다(strcmp와 같음)

베이스가 될 문장의 단어 하나하나씩 확인하는 게 아니라

입력받은 문자들을 현재 상태에서 만들 수 있는지 체크한다.

dp[i]에는 문장의 0번부터 i-1까지의 문자열에서 바꿀 수 있는 최소한의 비용을 저장한다.

단어로 바꿀 수 없는 경우에는 무한대값으로 초기화한다.

예를 들어 문장을 "neotowheret" 로 입력받은 경우

단어들이 one, two, three,there 일때,

dp[0]은 아무런 입력을 받지 않은 상태이다.

여기서 단어를 one,two,three,there을 넣어본 다음, 0에서 각 단어의 길이만큼 문장의 부분문자열을 확인한다.

그러면 neo, neo, neoto,neoto 인데 각 단어를 정렬하고, 부분문자열을 정렬한다음 비교하면 

해당 단어의 순서의 재배치로 만들 수 있는 단어인지 아닌지 판단할 수 있다.

이 경우 one을 만들 수 있으므로 최소비용인 3을 dp[3]에 저장한다. 최소비용이므로 min으로 비교후 저장한다.

그리고 만들 수 없는 단어들인 dp[1], dp[2]는 어떠한 단어도 만들어진 상태가 아니므로 생각할 필요가 없다.(만약 on,ne,no 단어가 있다면 있을 것이다)

dp[3]은 문장에서 neo 까지 입력받은 문자열인데 여기서 또 단어들을 확인해서 neo뒤에 단어를 추가할 수 있는지 확인하는 식으로 반복하면 된다.

## 복잡도

각 단어의 길이가 k라면 정렬하므로 k log k,  단어의 개수 n, 문자열의 길이 l

시간 복잡도 o(n*l *k log k)

공간복잡도 o(n + l)