// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int check(ll);

int n, m;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    // v에서 정확히 m개의 구간을 선택해서 구간에 속한 수들의 총 합이 최대가 되도록 한다.
    ll left = 0;
    ll right = 0;
    for(int i=0; i<n; i++){
        if(v[i] > 0) right += v[i];
    }
    ll answer = right;

    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(mid)){

        }
        else{

        }
    }
}

int check(ll num){
    int cnt = 0; // num이 넘지 않는 구간의 합
    
}


int main()
{
    init();
    input();
    solve();
    return 0;
}