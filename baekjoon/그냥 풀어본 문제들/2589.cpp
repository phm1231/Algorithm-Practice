// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n, m;
vector<string> board;

void init()
{
    FAST
}

void input()
{
    cin >> n >> m;
    string str = "";
    for(int i=0; i<n; i++){
        cin >> str;
        board.push_back(str);
    }
}

void solve()
{
    queue<pair<int, int> > q;
    int answer = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'W') continue;

            int visited[51][51];
            fill(&visited[0][0], &visited[50][50], 987654321);

            int dy[] = {-1, 0, 0, 1};
            int dx[] = {0, 1, -1, 0};

            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            visited[i][j] = 0;

            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(0 <= ny && ny < n && 0 <= nx && nx < m){
                        if(board[ny][nx] == 'L' && visited[ny][nx] > visited[y][x] + 1){
                            visited[ny][nx] = visited[y][x] + 1;
                            answer = max(answer, visited[ny][nx]);
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
        }
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