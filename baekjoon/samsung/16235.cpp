// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct wood{
    int y, x, age;
    wood(int y, int x, int age): y(y), x(x), age(age) {}
}wood;

void init();
void input();
void solve();
void spring();
void summer();
void autumn();
void winter();

int n, m, k;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, 1, 0, -1};
vector<vector<int> > board; // 나무판
vector<vector<int> > food; // 양분
vector<vector<vector<int> > > woods;
queue<wood> pregnantQ; // 번식이 가능한 나무 
queue<wood> deathQ; // 죽은 나무 정보

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;
    food.resize(n+1, vector<int>(n+1, 0));
    board.resize(n+1, vector<int>(n+1, 5));
    woods.resize(n+1, vector<vector<int> >(n+1, vector<int>()));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> food[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int y, x, z;
        cin >> y >> x >> z;
        woods[y][x].push_back(z);
    }
}

void solve()
{
    for(int i=0; i<k; i++){
        spring();
        summer();
        autumn();
        winter();
    }
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            answer += woods[i][j].size();
        }
    }
    cout << answer;
}

void spring(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vector<int> v;
            sort(woods[i][j].begin(), woods[i][j].end());
            for(int age: woods[i][j]){
                if(board[i][j] >= age){
                    board[i][j] -= age;
                    v.push_back(age + 1);
                    if((age + 1) % 5 == 0) pregnantQ.push(wood(i, j, age + 1));
                }
                else{
                    deathQ.push(wood(i, j, age));
                }
            }
            woods[i][j] = v;
        }
    }
}

void summer(){
    // 봄에 죽은 나무가 양분으로 변한다.
    while(!deathQ.empty()){
        wood w = deathQ.front();
        deathQ.pop();
        board[w.y][w.x] += w.age / 2;
    }
}

void autumn(){
    // 나무가 번식한다.
    while(!pregnantQ.empty()){
        int y = pregnantQ.front().y;
        int x = pregnantQ.front().x;
        pregnantQ.pop();

        for(int i=0; i<8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(1 <= ny && ny <= n && 1 <= nx && nx <= n){
                woods[ny][nx].push_back(1);
            }
        }
    }
}

void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            board[i][j] += food[i][j];
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