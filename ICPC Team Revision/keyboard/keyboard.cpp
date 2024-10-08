#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> s >> n;

    // Create a map to store the special keys and their respective "xi" values
    unordered_map<char, int> key_map;
    for (int i = 0; i < n; ++i)
    {
        char c;
        int x;
        cin >> x >> c;
        key_map[c] = x;
    }

    unordered_map<char, int> char_count;
    int total_key_presses = 0;
    int count = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (key_map.find(s[i]) == key_map.end())
        {
            count++;
        }
        else
        {
            char_count[s[i]]++;
        }
    }

    for (auto &it : char_count)
    {
        total_key_presses += ((it.second / key_map[it.first] + 1) + it.second);
    }

    cout << count + total_key_presses << endl;
    return 0;
}
