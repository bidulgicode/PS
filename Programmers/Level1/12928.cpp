/**
 *  약수의 합
 *  https://programmers.co.kr/learn/courses/30/lessons/12928
 *  그냥 for문 돌려서 풀었는데
 *  벡터 사용하는 방법 없나 찾아봤더니 좋은게 있어서 이것으로 기록
 *  i가 n의 제곱근이 아닌 경우
 *  n을 약수인 i로 나눠서 탐색범위를 root n 으로 줄여버린다.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> divisor;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            divisor.push_back(i);
            // ex) n=4, i=2 -> 1,2,4 // n은 2까지만
            
            if (i * i != n) // 제곱근이 아니면 약수의 짝을 찾아서 그것도 더함
                divisor.push_back(n/i);
        }

    for (int i : divisor)
        answer += i;

    return answer;
}

int main() {
    int n;
    cin >> n;
    solution(n);
}