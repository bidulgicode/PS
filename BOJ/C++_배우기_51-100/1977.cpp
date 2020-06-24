#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N, sum = 0, min = 0, i = 1, now;

    cin >> M >> N;

    while((now = i*i) <= N){
        if(now >= M){
            sum += now;
            if(min == 0) min = now;
        }
        ++i;
    }
    if(sum == 0) cout << "-1" << endl;
    else{
        cout << sum << endl;
        cout << min << endl;
    }

    return 0;
}
