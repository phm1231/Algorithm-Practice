#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void dfs(vector<int>& v, int idx);
void check();

int n, answer;
int dy[] = {-1, -1, 1, 1};
int dx[] = {-1, 1, -1, 1};
char board[10][10];
bool canTogether[101][101];
vector<int> cand;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    memset(board, 0, sizeof(board));
    memset(canTogether, true, sizeof(canTogether));
    
    for(int i=0; i<n*n; i++){
        int y = i / n;
        int x = i % n;
        cin >> board[y][x];
        if(board[y][x] == '1') cand.push_back(i);
    }

    // i랑 j가 같이 공존할 수 있는지 검사
    check();
}

void solve()
{
    vector<int> v;
    dfs(v, 0);
    cout << answer;
}

void check(){
    for(int num: cand){
        int y = num / n;
        int x = num % n;

        for(int d=0; d<4; d++){
            // 끝까지
            for(int i=1; ; i++){
                int ny = y + dy[d] * i;
                int nx = x + dx[d] * i;

                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(board[ny][nx] == '1'){
                        int targetNum = ny * n + nx;
                        canTogether[targetNum][num] = canTogether[num][targetNum] = false;
                    }
                }
                else{
                    break;
                }
            }
        }
    }
}

void dfs(vector<int>& v, int idx){
    answer = max((int)v.size(), answer);
    if(answer >= n*2-2) return;

    for(int i=idx; i<cand.size(); i++){
        int num = cand[i]; // 추가할 비숍 번호
        bool canGo = true;

        // 이미 추가한 비숍들과 검사
        for(int targetNum: v){
            if(!canTogether[num][targetNum]){
                canGo = false;
                break;
            }
        }

        if(canGo){
            v.push_back(num);
            dfs(v, i + 1);
            v.pop_back();
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