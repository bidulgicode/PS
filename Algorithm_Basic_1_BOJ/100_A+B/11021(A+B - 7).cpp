#include <bits/stdc++.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 0, a=0, b=0;

    cin >> T;

// endl은 cin 받고 바로 cout
// 개행문자 \n은 cin 끝까지 받고 마지막에 cout
    for(int i = 1; i <= T; i++){
        cin >> a >> b;
        cout << "Case #"<< i << ": " << a+b << '\n';
    }

    return 0;
}