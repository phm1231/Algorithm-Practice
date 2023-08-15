// based problem:
#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
set<int> s;

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
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for(auto iter=s.begin(); iter != s.end(); iter++) cout << *iter << ' ';
}


int main()
{
    init();
    input();
    solve();
    return 0;
}