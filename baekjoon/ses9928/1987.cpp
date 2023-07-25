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
void dfs(int, int, int, vector<bool>& );
int n, m, answer;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<string> bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        bd.push_back(str);
    }
}

void solve()
{
    vector<bool> isVisited(26, false);
    answer = 1;
    isVisited[bd[0][0] - 'A'] = true;
    dfs(0, 0, 1, isVisited);    
    cout << answer;
}

void dfs(int y, int x, int cnt, vector<bool>& isVisited){
    answer = max(answer, cnt);
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0<=ny && ny<n && 0<=nx && nx<m){
            char alphabet = bd[ny][nx];
            if(!isVisited[alphabet - 'A']){
                isVisited[alphabet - 'A'] = true;
                dfs(ny, nx, cnt + 1, isVisited);
                isVisited[alphabet - 'A'] = false;
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