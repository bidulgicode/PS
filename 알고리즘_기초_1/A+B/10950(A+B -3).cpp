#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 0, a = 0, b = 0;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}

