#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countSeatingArrangements(int n, int p, int c) {
    // Initialize dp array to store arrangements
    vector<vector<int>> dp(p + 1, vector<int>(n, 0));

    // For 0 people, there is only 1 way - empty room
    dp[0][0] = 1;

    for (int people = 1; people <= p; ++people) {
        for (int chairs = 0; chairs < n; ++chairs) {
            if (people == 1) {
                dp[people][chairs] = 1;
            } else {
                // For more than one person
                for (int gap = 1; gap <= c + 1; ++gap) {
                    dp[people][chairs] += dp[people - 1][(chairs + gap) % n];
                    dp[people][chairs] %= MOD;
                }
            }
        }
    }

    return dp[p][0];
}

int main() {
    int n = 4, p = 2, c = 1;

    int arrangements = countSeatingArrangements(n, p, c);
    cout << "Total seating arrangements satisfying the criteria: " << arrangements << endl;

    return 0;
}
