// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> v[4];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<4; i++) v[i].resize(n, 0);

    for(int i=0; i<n; i++){
        cin >> v[0][i] >> v[1][i] >> v[2][i] >> v[3][i];
    }
}

void solve()
{
    vector<ll> ab, cd;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ab.push_back(v[0][i] + v[1][j]);
            cd.push_back(v[2][i] + v[3][j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    ll answer = 0;
    for(int i=0; i<ab.size(); i++){
        int start = lower_bound(ab.begin(), ab.end(), -cd[i]) - ab.begin(); // 이상
        int end = upper_bound(ab.begin(), ab.end(), -cd[i]) - ab.begin(); // 초과
        answer += (end - start);
    }
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}

// A[a] + B[b] + C[c] + D[d] = 0;
// 4000 * 4000 = 16 000 000