/**
 * BOJ_11656_접미사배열
 * https://www.acmicpc.net/problem/11656
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> a;
    for (int i = 0; i < n; i++)
        a.push_back(i);

    sort(a.begin(), a.end(), [&s](int u, int v) {
        // strcmp (https://blockdmask.tistory.com/391)
        // s.c_str() + u, s.c_str() + v
        // 위 두개의 문자열을 비교하다가 서로 다른문자가 나오는 시점에서
        // 그 문자의 아스키 코드 값을 비교, 반환값이 정해짐
        // ex) hello vs ello, hello vs llo, ello vs llo 등등..
        // s.c_str() + u < s.c_str() + v 이면 -1
        // s.c_str() + u > s.c_str() + v 이면 1
        // 마지막으로 동일한 경우에는 0
       
        // 각 문자를 아스키 코드로 비교하기 때문에
        // 1. 대소문자 구분, 2. 각 문자별 숫자로 대소 비교 가능
        // EX) D, F, A의 경우 D < F 이므로 -1, D > A 이므로 1 반환
        // 이 람다 함수의 경우 -1인 경우에만 true를 리턴함.

        // u, v는 백터 a에 포함된 원소들
        // 이 원소들의 우선순위를 문자열 s와 조합하여 만들기 때문에
        // 스트링에 + u or v 했을때 여기 해당하는 문자의 아스키값의
        // 크기를 비교해서 sort 하는거임
        // 2 0 1 3 4 5 이런식의 sort 결과가 나옴

        // u,v 출력하면 모든 경우의 수를 따지지는 않고 있음
        // 대략 O(logn)?
        cout << u << ',' << v << '\n';
        cout << s.c_str() + u << ',' << s.c_str() + v << '\n';
        
        // strcmp는 두번째 인자가 크면 음수 반환
        // comp는 첫번째 인자가 더 작으면 true 리턴해야함
        // 두번째 인자가 커서 음수 반환 -> 첫번째 인자가 더 작다.
        // 음수 < 0 은 true 이므로 comp 조건에 맞음.
        // 위의 반대로 정렬하고 싶으면 (내림차순)
        // 첫번째 인자가 더 클때 true 반환
        // strcmp에서 첫번째 인자가 더 크면 1 반환함
        // 그러므로 부등호를 바꿔서 '>' 으로
        return strcmp(s.c_str() + u, s.c_str() + v) < 0; // 왼쪽이 크면 false 오른쪽이 크면 ture가 된다.
    });
    
    for(auto &x : a){
        cout << s.substr(x) << '\n';
    }
    return 0;
}
