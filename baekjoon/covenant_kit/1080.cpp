// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<string> answer_board;
vector<string> current_board;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        answer_board.push_back(tmp);
    }
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        current_board.push_back(tmp);
    }
}

void solve()
{
    vector<vector<bool> > isSame(n, vector<bool>(m, true));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            isSame[i][j] = (answer_board[i][j] == current_board[i][j]);
        }
    }

    // board가 너무 작아서 뒤집기가 불가한 경우
    if(n < 3 || m < 3){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!isSame[i][j]){
                    cout << -1;
                    return;
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(isSame[i][j]) continue;

            // 같지 않음.
            // 뒤집을 수 있는 경우
            if(i < n-2 && j < m-2){
                // 뒤집는다
                for(int y=i; y<i+3; y++){
                    for(int x=j; x<j+3; x++){
                        isSame[y][x] = !isSame[y][x];
                    }
                }
                answer++;
            }
            else{
                cout << -1;
                return;
            }
        }
    }
    // 뒤집기 끝나고 확인
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!isSame[i][j]){
                cout << -1;
                return;
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