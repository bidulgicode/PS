#include <iostream>
#include <string.h>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[3] = "Hi";
    
    /**
     * strlen 함수의 시간 복잡도는 O(N)이니깐
     * 아래처럼 작성하면 O(N^2)임
     */
    for (int i = 0; i < strlen(s); i++){
        // ㅇㅇㅇㅁㄴㅇㅁㄴㅇ
    }
    // 따라서 아래와 같이 작성
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        // 이러면 for돌때마다 strlen 호출 안하니깐 O(N)임
    }

    return 0;
}
