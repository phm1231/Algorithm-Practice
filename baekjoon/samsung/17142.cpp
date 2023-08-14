// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<vector<int> > bd;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    // 비활성 바이러스 중에 m개를 선택해서 활성 바이러스로 바꾼다.
    
}


int main()
{
    init();
    input();
    solve();
    return 0;
}