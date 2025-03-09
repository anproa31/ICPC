#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
int n;
int chosen[MAX_N + 1];
vector<int> permutation;

void search() {
    if(permutation.size() == n) {
        for (int i = 0; i < permutation.size(); i++)
        {
            cout << permutation[i] << " ";
        } 
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++)
        {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }

}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> n;
        memset(chosen, 0, sizeof(chosen));
        permutation.clear();

        cout << "#" << i << ": " << endl;
        search();
    }
    
    

    return 0;
}
