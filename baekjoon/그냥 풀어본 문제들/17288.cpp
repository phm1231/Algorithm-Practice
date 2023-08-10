// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

string str;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> str;
}

void solve()
{
    int n = str.size();
    int answer = 0;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=i+1; j<n; j++){
            if(str[j-1] + 1 == str[j]) cnt++;
            else break;
        }
        if(cnt == 2) answer++;
        i += cnt;
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