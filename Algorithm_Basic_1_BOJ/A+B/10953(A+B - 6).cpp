#include <bits/stdc++.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 0, a = 0, b = 0;
    char c;

// 콤마는 받아놓고 안쓰기
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a >> c >> b;
        cout << a+b << endl;
    }

    return 0;
}