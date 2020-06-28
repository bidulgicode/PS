#include <bits/stdc++.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto T = 0, a = 0, b = 0;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << '\n';
    }

    return 0;
}