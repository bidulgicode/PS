#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;
int fibonacci(int n){
    if(n <= 1){
        return n;
    } else if (memo[n] != 0){
        return memo[n];
    }else{
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    memo.resize(n + 1);
    cout << fibonacci(n) << '\n';

    return 0;
}
