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

int n, q;
vector<int> T, Q;
vector<int> sum;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> q;
    T.resize(n, 0);
    Q.resize(q, 0);
    sum.resize(n, 0);

    for(int i=0; i<n; i++) cin >> T[i];
    for(int i=0; i<q; i++) cin >> Q[i];
}

void solve()
{
    sum[0] = T[0];
    for(int i=1; i<n; i++){
        sum[i] = sum[i-1] + T[i];
    }

    for(int i=0; i<q; i++){
        // Q[i] 초에 몇 번 악보를 연주하고 있었는가?
        cout << (upper_bound(sum.begin(), sum.end(), Q[i]) - sum.begin()) + 1 << "\n";
    }


}


int main()
{
    init();
    input();
    solve();
    return 0;
}