/**
 * 에라토스테네스의 체
 * 기존 방식은 각각의 수에 대해 소수인지 아닌지 검사
 * O(N루트N), 만약 숫자가 100만개라고 치면 10억케이스 = 10초가 걸림
 * 에라토스테네스의 체를 사용
 * 1. 2~N까지 모든 수를 써놓는다
 * 2. 아직 지워지지 않은 수 중에서 가장 작은 수를 찾자
 * 3. 그 수는 소수이다.
 * 4. 이제 그 수의 배수를 모두 제거.
 * 이것도 역시 루트N까지만 체크해보면 됨
 * O(NlogN) 걸린다고 함
 * 그래프 보면 log쪽이 더 빠름
 * https://www.bigocheatsheet.com/
 */
#include <bits/stdc++.h>

int main(){
    int prime[100];
    int pn = 0;
    bool check[101];
    int n = 100;
    for (int i = 2; i <= n; i++){
        if(check[i] == false){
            prime[pn++] = i;
            for (int j = i * 2; i <= n; j+=i){
                // j는 N의 크기에 따라서 i*i or i*2로 취사선택
                // i가 백만인 경우에는 i*i는 범위를 넘어가기 때문
                check[j] = true;
            }
        }
    }

    return 0;
}