// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int y, x, k;
vector<vector<bool> > visited(101, vector<bool>(101, false));

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

void init()
{
    FAST
}

void input()
{
    cin >> y >> x >> k;

    for(int i=0; i<k; i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;    
        for(int _y=sy; _y<ey; _y++){
            for(int _x=sx; _x<ex; _x++){
                visited[_y][_x] = true;
            }
        }

    }
}

void solve()
{
    queue<pair<int, int> > q;
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            if(!visited[i][j]) q.push({i, j});
        }
    }

    int answer = 0;
    multiset<int> areas;

    while(!q.empty()){
        int _y = q.front().first;
        int _x = q.front().second;
        q.pop();

        if(!visited[_y][_x]){
            answer++;
            visited[_y][_x] = true;
            int area = 1;
            stack<pair<int, int> > stk;
            stk.push({_y, _x});

            while(!stk.empty()){
                int tmpY = stk.top().first;
                int tmpX = stk.top().second;
                stk.pop();

                for(int i=0; i<4; i++){
                    int ny = tmpY + dy[i];
                    int nx = tmpX + dx[i];
                    if(0 <= ny && ny < y && 0 <= nx && nx < x){
                        if(!visited[ny][nx]){
                            visited[ny][nx] = true;
                            area++;
                            stk.push({ny, nx});
                        }
                    }
                }
            }
            areas.insert(area);
        }
    }
    cout << answer << endl;
    for(auto iter = areas.begin(); iter != areas.end(); iter++) cout << *iter << ' ';
}

int main()
{
    init();
    input();
    solve();
    return 0;
}