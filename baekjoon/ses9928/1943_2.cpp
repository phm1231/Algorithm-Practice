#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    for (int k = 0; k < 3; ++k) {
        int n;
        cin >> n;
        vector<int> coinTypes, coinValues;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            coinTypes.push_back(a);
            coinValues.push_back(b);
            sum += a * b;
        }

        if (sum % 2 == 1) {
            cout << 0 << endl;
            continue;
        }

        sum /= 2;

        vector<int> filteredCoinTypes;
        for (int coinType : coinTypes) {
            if (coinType <= sum)
                filteredCoinTypes.push_back(coinType);
        }

        sort(filteredCoinTypes.begin(), filteredCoinTypes.end());

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int coinIdx = 0; coinIdx < filteredCoinTypes.size(); ++coinIdx) {
            vector<bool> tmp = dp;
            int coinType = filteredCoinTypes[coinIdx];
            for (int amount = 0; amount <= sum; ++amount) {
                if (dp[amount]) {
                    for (int cnt = 1; cnt <= coinValues[coinIdx]; ++cnt) {
                        if (amount + coinType * cnt <= sum) {
                            tmp[amount + coinType * cnt] = true;
                        }
                    }
                }
            }
            dp = tmp;
        }

        if (dp[sum]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}