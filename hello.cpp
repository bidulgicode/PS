#include <bits/stdc++.h>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = '9' - '0';
    int a = 1, b = 2, c = 2;

    string s = "";

    char buf[10];
    sprintf(buf, "%d", b);
    string h = to_string(a);
    const char* cArr = h.c_str();
    char cArr2[10];
    strcpy(cArr2, h.c_str());

    if(a<=b<c)
        cout << n << '\n';



    return 0;
}
