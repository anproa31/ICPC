#include <bits/stdc++.h>
using namespace std;

int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
    }
    if(n != 1)
    {
        cnt++;
    }
    return cnt;
}

int main()
{

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (countDivisors(a) % 2 == 0)
        {
            cout << "1 ";
        }
        else
        {
            cout << "2 ";
        }
        
    }
    
}