// based problem:
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int dfs(int idx);

string str;
vector<bool> visited(51, false);

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
    cout << dfs(0);    
}

int dfs(int idx){
    int cnt = 0;
    for(int i=idx; i<str.size(); i++){
        if(visited[i]) continue;

        if(str[i] == '('){
            visited[i] = true;
            cnt--;
            cnt += (str[i-1] - '0') * dfs(i+1);
        }
        else if(str[i] == ')'){
            visited[i] = true;
            return cnt;
        }
        else{
            visited[i] = true;
            cnt++;
        }
    }
    return cnt;
}



int main()
{
    init();
    input();
    solve();
    return 0;
}