#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    string num = "NZQR";
    int t_minus[4] = {1, 1, 2, 3};
    int t_div[4] = {2, 2, 2, 3};
    char c1, c2, c3, ans;

    cin >> c1 >> c2 >> c3;
    int t1 = num.find(c1);
    int t2 = num.find(c2);
    int tm = max(t1, t2);
    int t;

    switch (c2)
    {
    case '+':
        t = tm;
        break;
    case '*':
        t = tm;
        break;

    case '-':
        t = t_minus[tm];
        break;

    case '/':
        t = t_div[tm];
    }

    cout << num[t];
}