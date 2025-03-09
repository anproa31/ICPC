#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;


int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int d1 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    int d2 = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);
    int d3 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);

    int maxD = max(max(d1, d2), d3);
    int maxDis = max({d1, d2, d3});
    

    if(maxD == d1) {
        cout << x1 << " " << y1 <<" "<< x2 << " " << y2;
    } else if (maxD == d2) { 
        cout << x1 << " " << y1 << " " << x3 << " " << y3;
    } else {
        cout << x2 << " " << y2 << " " << x3 << " " << y3;
    }

    cout << "Hello World";

    return 0;
}
