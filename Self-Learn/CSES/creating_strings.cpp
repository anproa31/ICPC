#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define ll MAX 1e9 + 7
set<string> perms;
// set<string> permutationGenerate(string s) {
//     int N = s.length();
//     sort(s.begin(), s.end());
//     set<string> uniqueStrings;

//     do
//     {
//         uniqueStrings.insert(s);
//     } while (next_permutation(s.begin(), s.end()));

//     return uniqueStrings;
    
// }

void solve(string prefix, string suffix) {
    if(suffix.length() == 0) {
        perms.insert(prefix);
        return;
    }
    for(int i = 0; i < suffix.length(); i++) {
        solve(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    string s;
    cin >> s;

    // set<string> uniqueStrings = permutationGenerate(s);
    // int N = uniqueStrings.size();

    // cout << N << endl;
    // for(string str : uniqueStrings) {
    //     cout << str << "\n";
    // }
    // cout << endl;
    solve("", s);
    cout <<perms.size() << endl;
    for(string str : perms) {
        cout << str << "\n";
    }
    

    return 0;
}
