#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    vector<int> mindp(3, 0);
    vector<int> maxdp(3, 0);
    vector<int> values(3, 0);

    cin >> mindp[0] >> mindp[1] >> mindp[2];
    maxdp[0] = mindp[0];
    maxdp[1] = mindp[1];
    maxdp[2] = mindp[2];

    for(int i=1; i<n; i++){
        cin >> values[0] >> values[1] >> values[2];
        int tmp0 = mindp[0];
        int tmp2 = mindp[2];

        mindp[0] = values[0] + min(mindp[0], mindp[1]);
        mindp[2] = values[2] + min(mindp[1], mindp[2]);
        mindp[1] = values[1] + min(tmp0, min(mindp[1], tmp2));

        tmp0 = maxdp[0];
        tmp2 = maxdp[2];

        maxdp[0] = values[0] + max(maxdp[0], maxdp[1]);
        maxdp[2] = values[2] + max(maxdp[1], maxdp[2]);
        maxdp[1] = values[1] + max(tmp0, max(maxdp[1], tmp2));
    }

    int maxValue = -1, minValue = 987654321;
    for(int i=0; i<3; i++){
        minValue = min(minValue, mindp[i]);
        maxValue = max(maxValue, maxdp[i]);
    }
    cout << maxValue << ' ' << minValue;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}