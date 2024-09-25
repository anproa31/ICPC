#include <bits/stdc++.h>
using namespace std;

#define fastInp                  \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);                   \
   cout.tie(0);
int main()
{
   freopen("../input.txt", "r", stdin);
   freopen("../output.txt", "w", stdout);
   fastInp;

   int64_t n, t1, t2, t3, t_pair, t_all, ans;
   cin >> n;
   cin >> t1 >> t2 >> t3;
   t_pair = t1 + max(t1, t2);
   if (t2 >= 2 * t1)
   {
      cout << t1 + t2 + t3 + (n - 1) * max(t2, t3);
      exit(0);
   }
   if(t1 == t2 && (t3 >= 2 * t1)) {
      cout << 2 * t1 + n * t3;
      exit(0);
   }
   if(t1 == t2 && (t3 <= t1)) {
      cout << 2 * n * t1 + t3; 
      exit(0);
   }
   if(t3 >= t_pair) {
      cout << t_pair + n * t3;
      exit(0);
   }
   if(t1 == 2 && (t2 == 1)) {
      cout << t3 + 4*n;
      exit(0);
   }
   if(t1 ==2 && (t2 == 3)) cout << t3 + 1 + 4*n;
}