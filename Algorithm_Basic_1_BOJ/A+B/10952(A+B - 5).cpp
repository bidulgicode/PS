#include <bits/stdc++.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 0;

    // while 조건에 x || y XOR 조건을 넣는 방법도 있음
    while (cin >> a >> b)
    {
        if( a==0 && b==0)
        break;

        cout << a + b << endl;
    }
    

    return 0;
}