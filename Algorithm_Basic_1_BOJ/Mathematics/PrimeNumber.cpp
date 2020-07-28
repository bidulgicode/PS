#include <iostream>

bool prime(int n){
    if(n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5;

    cout << prime(n) << '\n';

    return 0;
}
