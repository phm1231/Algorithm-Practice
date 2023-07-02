// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<vector<int> > tree;
vector<bool> isEarly;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    tree.resize(n+1, vector<int>());
    isEarly.resize(n+1, false);

    int a, b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b; // a와 b는 친구임
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void solve()
{

}

int main()
{
    init();
    input();
    solve();
    return 0;
}