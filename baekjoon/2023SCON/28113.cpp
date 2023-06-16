// based problem:
#include <iostream>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();
// a분뒤에 버스도착, b 열차도착
int n, a, b;

void init()
{
    FAST
}

void input()
{
    cin >> n >> a >> b;
}

void solve()
{
    // 버스에 더 먼저 탑승할 수 있는 경우
    if(a < b) cout << "Bus";
    // 지하철에 더 먼저 탑승할 수 있는 경우
    else if(a > b && n <= b) cout << "Subway";
    else cout << "Anything";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}