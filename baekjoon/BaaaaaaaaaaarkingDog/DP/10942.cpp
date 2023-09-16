#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void go();

int n, m;
vector<int> v;
bool isPalindrome[2001][2001] = {false, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin>> v[i];
    cin >> m;
}

void solve()
{
    go();
    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        cout << isPalindrome[from][to] << endl;
    }
}

void go(){
    // 홀수개 팰린드롬
    for(int i=1; i<=n; i++){
        isPalindrome[i][i] = true;
        for(int j=1; ; j++){
            int from = i - j;
            int to = i + j;
            if(1 <= from && to <= n){
                if(v[from] == v[to]) isPalindrome[from][to] = true;
                else break;
            }
            // 범위 초과
            else break;
        }
    }
    // 짝수개 팰린드롬
    for(int i=1; i<=n-1; i++){
        if(v[i] == v[i+1]){
            isPalindrome[i][i+1] = true;
            for(int j=1; ; j++){
                int from = i - j;
                int to = i + 1 + j;
                if(1 <= from && to <= n){
                    if(v[from] == v[to]) isPalindrome[from][to] = true;
                    else break;
                }
                // 범위 초과
                else break;
            }
        }
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}