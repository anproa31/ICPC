#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    int length = s.length();
    int n = 0;
    vector<string> words;
    // Find n and extract words
    for (int i = 0; i < length / 2; i++)
    {
        for (int j = i + 1; j <= length / 2; j++)
        {
            string first_half = s.substr(i, j - i);
            string second_half = s.substr(length - j, j - i);

            if (first_half == second_half)
            {
                words.push_back(first_half);
                i = j - 1;
                n++;
                break;
            }
        }
    }
    // Print results
    cout << n << endl;
    for (const string &word : words)
    {
        cout << word << endl;
    }
    return 0;
}
