#include <bits/stdc++.h>
using namespace std;

int n, k, s, v1, v2, x[100001], a[100001], m;
priority_queue<int> q;
int64_t t, d = 0;
double ans = 0;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> v1 >> v2 >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> a[i];
    }
    if(s == 0) {
        cout << 0;
        return 0;
    }

    if(v1 >= v2) {
        cout << "inf";
        return 0;
    }

    m = n;
    for(int i = 0; i < n; i++) {
        if(x[i] >= s) {
            m = i;
            break;
        }
    }

    while(k > 0) {
        for(int i = m; i < n; i++) {
            if((double) (x[i] - s)/v1 >= (double) (x[i] + d)/v2) break;
            ++m;
            q.push(a[i]);
        }
        --k;
        if(!q.empty()) t = q.top();
        else break;
        d+=t*v2;
        q.pop();
    }

    ans = (double) (s+d)/(v2 - v1);
    cout << fixed << setprecision(6) << ans;
    
}