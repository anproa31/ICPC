#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000
using namespace std;

// Function to find the minimum number of coins to make 
// sum X
ll solve(ll N, ll X, vector<ll>& coins)
{
    // dp[] array such that dp[i] stores the minimum number
    // of coins to make sum = i
    vector<ll> dp(X + 1, INF);
    dp[0] = 0;

    // Iterate over all possible sums from 1 to X
    for (int i = 1; i <= X; i++) {
        // Iterate over all coins
        for (int j = 0; j < N; j++) {
            if (coins[j] > i || dp[i - coins[j]] == INF)
                continue;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    // If it is possible to make sum = X, return dp[X]
    if (dp[X] != INF)
        return dp[X];

    // If it is impossible to make sum = X, return -1
    return -1;
}

int main()
{
    // Sample Input
    ll N, X;
    cin >> N >> X;
    vector<ll> coins(N);
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    
    cout << solve(N, X, coins) << "\n";
}