// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, b, c;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
    cin >> b >> c;
}

void solve()
{
    ll answer = 0;
    // 각 시험장마다 1명의 총감독관 배치
    for(int i=0; i<n; i++){
        v[i] -= b;
        answer++;
    }
    // 각 시험장마다 부감독관 배치
    for(int i=0; i<n; i++){
        if(v[i] < 1) continue;

        // 필요한만큼 부감독관 배치
        answer += v[i] / c;
        v[i] = v[i] % c;
        // 1명 더 필요하면 배치
        if(v[i] > 0) answer++;
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