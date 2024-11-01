#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MAX 1e9 + 7

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    string ans;

    unordered_map<char, int> freq;
    for (char c : str)
    {
        freq[c]++;
    }

    int odd_count = 0;
    char odd_char = '\0';

    for (auto &p : freq)
    {
        if (p.second % 2 != 0)
        {
            odd_count++;
            odd_char = p.first;
        }
    }

    if (odd_count > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string half_palindrome = "";
    for (auto &p : freq)
    {
        half_palindrome += string(p.second / 2, p.first); // print p.second / 2 times character p.first
    }

    string palindrome = half_palindrome;
    if (odd_count == 1)
    {
        palindrome += odd_char;
    }

    reverse(half_palindrome.begin(), half_palindrome.end());

    palindrome += half_palindrome;
    cout << palindrome;

    return 0;
}
