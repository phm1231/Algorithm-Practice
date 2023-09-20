#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
pair<int, int> GetSeat(const int student);
int GetLikeCount(const int student, const int y, const int x);
int GetEmptyCount(const int y, const int x);
int GetSatisfaction();

int n;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > likes;
vector<vector<int> > board;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n;
    likes.resize(n*n+1, vector<int>(4, -1));
    board.resize(n+1, vector<int>(n+1, -1));
}

void Solve()
{
    for(int i=0; i<n*n; i++){
        int student;
        cin >> student;

        for(int j=0; j<4; j++){
            cin >> likes[student][j];
        }

        pair<int, int> seat = GetSeat(student);
        board[seat.first][seat.second] = student;
    }
        
    cout << GetSatisfaction();
}

pair<int, int> GetSeat(const int student){

    int max_like_cnt = -1; // 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸
    int max_empty_cnt = -1; // 인접한 칸 중에 비어있는 칸이 가장 많은 칸
    int selectedY = n+1; // 행의 번호가 가장 작은 칸
    int selectedX = n+1; // 열의 번호가 가장 작은 칸

    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            // 이미 다른 사람이 앉아있다면
            if(board[y][x] != -1) continue;

            int like_cnt = GetLikeCount(student, y, x);
            int empty_cnt = GetEmptyCount(y, x);
           
            // 이미 선택한 자리의 우선순위가 더 높음
            if(max_like_cnt > like_cnt) continue;

            // 첫 번째 우선 순위가 동일함
            if(max_like_cnt == like_cnt){
                // 이미 선택한 자리의 우선순위가 더 높음
                if(max_empty_cnt >= empty_cnt) continue;

                // 자리를 변경함.
                max_empty_cnt = empty_cnt;
                selectedY = y;
                selectedX = x;
            }
            // 첫 번째 우선 순위에서 결정됨.
            else{
                max_like_cnt = like_cnt;
                max_empty_cnt = empty_cnt;
                selectedY = y;
                selectedX = x;
            }
        }
    }

    return make_pair(selectedY, selectedX);
}

int GetLikeCount(const int student, const int y, const int x){
    int like_cnt = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(1 <= ny && ny <= n && 1 <= nx && nx <= n){
            if(board[ny][nx] == -1) continue;

            // student가 좋아하는 학생인지 검사
            bool isLike = false;
            for(int j=0; j<4; j++){
                if(likes[student][j] == board[ny][nx]){
                    isLike = true;
                    break;
                }
            }
            if(isLike) like_cnt++;
        }
    }
    return like_cnt;
}

int GetEmptyCount(const int y, const int x){
    int empty_cnt = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(1 <= ny && ny <= n && 1 <= nx && nx <= n){
            if(board[ny][nx] == -1) empty_cnt++;
        }
    }
    return empty_cnt;
}

int GetSatisfaction(){
    int satisfaction_sum = 0;

    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            int like_cnt = GetLikeCount(board[y][x], y, x);

            if(like_cnt == 0) satisfaction_sum += 0;
            else if(like_cnt == 1) satisfaction_sum += 1;
            else if(like_cnt == 2) satisfaction_sum += 10;
            else if(like_cnt == 3) satisfaction_sum += 100;
            else if(like_cnt == 4) satisfaction_sum += 1000;
        }
    }

    return satisfaction_sum;
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}