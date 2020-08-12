/**
 * 유클리드 호제법
 * a를 b로 나눈 나머지를 r이라고 했을 때
 * GCD(a,b) = GCD(b,r) 과 같다.
 * r이 0이면 그 때 b가 최대 공약수이다.
 */

// 재귀함수 이용
int gcd(int a, int b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// 재귀함수 X
int gcd2(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}