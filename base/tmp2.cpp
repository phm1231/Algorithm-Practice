#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct node{
    int y1, x1, y2, x2, dir;
    node(int y1, int x1, int y2, int x2, int d): y1(y1), x1(x1), y2(y2), x2(x2), dir(d) {};
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    bool visited[100][100][2] = {false, }; // 0은 가로, 1은 세로
    queue<node> q;
    q.push({0, 0, 0, 1, 0});
    
    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            node here = q.front();
            q.pop();
            
            int y1 = here.y1;
            int x1 = here.x2;
            int y2 = here.y2;
            int x2 = here.x2;
            int dir = here.dir;
            
            if(y2 == n-1 && x2 == n-1) return answer;
            if(visited[y2][x2][dir]) continue;
            visited[y2][x2][dir] = true;
            
            // 상
            node next = {y1-1, x1, y2-1, x2, dir};
            if(0 <= y1-1 && !visited[y2-1][x2][dir] && board[y1-1][x1] == 0 && board[y2-1][x2] == 0){
                q.push(next);
                // 위로 이동했는데 현재 상태가 가로였을경우, 기존 위치에서 세로로 회전할 수 있음이 보장된다.
                if(dir == 0){  
                    q.push({y1-1, x1, y1, x1, 1});
                    q.push({y2-1, x2, y2, x2, 1});
                }
            }
            // 하
            next = {y1+1, x1, y2+1, x2, dir};
            if(y2+1 < n && !visited[y2+1][x2][dir] && board[y1+1][x1] == 0 && board[y2+1][x2] == 0){
                q.push(next);
                if(dir == 0){
                    q.push({y1, x1, y1+1, x1, 1});
                    q.push({y2, x2, y2+1, x2, 1});
                }
            }
            // 좌
            next = {y1, x1-1, y2, x2-1, dir};
            if(0 <= x1-1 && !visited[y2][x2-1][dir] && board[y1][x1-1] == 0 && board[y2][x2-1] == 0){
                q.push(next);
                // 좌측으로 이동했는데 현재 상태가 세로였을경우, 가로로 회전할 수 있음이 보장된다.
                if(dir == 1){
                    q.push({y1, x1-1, y1, x1, 0});
                    q.push({y2, x2-1, y2, x2, 0});
                }
            }
            // 우
            next = {y1, x1+1, y2, x2+1, dir};
            if(x2+1 < n && !visited[y2][x2+1][dir] && board[y1][x1+1] == 0 && board[y2][x2+1] == 0){
                q.push(next);
                if(dir == 1){
                    q.push({y1, x1, y1, x1+1, 0});
                    q.push({y2, x2, y2, x2+1, 0});
                }
            }
        }
        answer++;
    }
}