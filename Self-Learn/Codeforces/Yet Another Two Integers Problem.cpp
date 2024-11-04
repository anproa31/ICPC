#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    vector<long long> v;
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        long long sub = abs(a - b);
        long long count;
        if (sub % 10 == 0)
        {
            count = sub / 10;
        }
        else
            count = sub / 10 + 1;

        v.push_back(count);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
