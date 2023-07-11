// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

typedef struct loc{
    int y, x;
    loc(int y, int x): y(y), x(x) {};
}loc;

int n;
int dy[] = {0, 1, 0, -1}; // 오른쪽+1, 왼쪽 -1
int dx[] = {1, 0, -1, 0};
priority_queue<pair<int, char> > pq;
deque<loc> dq;
vector<vector<int> > board;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    board.resize(n+1, vector<int>(n+1, 0));

    int apple;
    cin >> apple;
    for(int i=0; i<apple; i++){
        int y, x;
        cin >> y >> x;
        board[y][x] = 2; // 사과
    }

    int cmd;
    cin >> cmd;
    for(int i=0; i<cmd; i++){
        int time;
        char dir;
        cin >> time >> dir;
        pq.push(make_pair(-time, dir));
    }
}

void solve()
{
    int current = 0;
    int dir = 0;
    dq.push_back(loc(1, 1));
    board[1][1] = 1;

    // 벽에 부딪힐때까지.
    while(1){
        // 명령 확인
        if(!pq.empty() && -pq.top().first == current){
            char cmd = pq.top().second;
            pq.pop();
            if(cmd == 'L'){
                dir--;
                if(dir < 0) dir = 3;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }
        // 몸을 늘려 머리를 다음 칸에 위치시키기.
        loc next = dq.back();
        next.y += dy[dir];
        next.x += dx[dir];
        dq.push_back(next);
        // 죽음 체크
        // 범위를 벗어났는가?
        if(next.y < 1 || next.y > n || next.x < 1 || next.x > n){
            cout << current + 1;
            break;
        }
        // 몸통인가?
        else if(board[next.y][next.x] == 1){
            cout << current + 1;
            break;
        }
        // 사과라면 꼬리를 제거하지 않음
        if(board[next.y][next.x] == 2){
            board[next.y][next.x] = 1;
        }
        // 꼬리를 제거한다.
        else{
            loc tail = dq.front();
            board[next.y][next.x] = 1;
            board[tail.y][tail.x] = 0;
            dq.pop_front();
        }
        current++;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}