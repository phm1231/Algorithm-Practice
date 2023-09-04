#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 1000001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, k;
int maxRight = -1;
ll accum[MAX] = {0, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        maxRight = max(maxRight, b);
        accum[a]++;
        accum[b]--;
    }
}

void solve()
{
    for(int i=1; i<=maxRight; i++){
        accum[i] += accum[i-1];
    }
    for(int i=1; i<=maxRight; i++){
        accum[i] += accum[i-1];
    }
    cout << "2283, ACCUM\n";
    for(int i=0; i<=maxRight; i++){
        cout << accum[i] << ' ';
    }
    cout << "\n";

    int left = 0;
    int right = 0;
    ll sum = 0;

    while (right <= maxRight) {
        sum += accum[right];

        while (sum > k) {
            sum -= accum[left];
            left++;
        }

        if (sum == k) {
            cout << left << ' ' << right + 1;
            return;
        }

        else {
            right++;
        }
    }

    cout << "0 0";
}


int main()
{
    init();
    input();
    solve();
    return 0;
}