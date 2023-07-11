// based problem:
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
map<string, int> m;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        m[tmp]++;
    }
}

void solve()
{
    string ans_title = "";
    int max_cnt = 0;
    for(auto iter=m.begin(); iter!=m.end(); iter++){
        string title = iter->first;
        int cnt = iter->second;
        if(max_cnt < cnt){
            max_cnt = cnt;
            ans_title = title;
        }
    }
    cout << ans_title;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}