// based problem:
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void rotate();
void check(int, int, int);
void calcul(int ,int ,int ,int ,int, int);

int n, answer;
int startY[] = {0, 0, 1, 1};
int startX[] = {0, 1, 0, 1};
// i번째, 회전
int number[10][4][4][4];
char color[10][4][4][4];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    answer = 0;
    memset(number, 0, sizeof(number));
    memset(color, 0, sizeof(color));
}

void input()
{
    cin >> n;
    // 갯수
    for(int i=0; i<n; i++){
        // 숫자
        for(int a=0; a<4; a++){
            for(int b=0; b<4; b++){
                cin >> number[i][0][a][b];
            }
        }
        // 색깔
        for(int a=0; a<4; a++){
            for(int b=0; b<4; b++){
                cin >> color[i][0][a][b];
            }
        }
    }

}

void solve()
{
    // 회전시켜 저장함.
    rotate();
    // 3개를 뽑으면서 완전탐색, 하지만 순서가 중요한데요?
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i == j || j == k || k == i) continue;
                check(i, j, k);
            }
        }
    }
    cout << answer;
}

void check(int a, int b, int c){
    // a, b, c번을 뽑아서 검사.
    // 각기 회전
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                // number[a][i], number[b][j], number[c][k] 번째를 사용하는거야 ^^7
                calcul(a, i, b, j, c, k);
            }
        }
    }
}

void calcul(int a, int an, int b, int bn, int c, int cn){
    int n_board[5][5];
    char c_board[5][5];

    memset(n_board, 0, sizeof(n_board));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            c_board[i][j] = 'W';
        }
    }
   
    for(int i=0; i<4; i++){ // a의 시작 위치
        for(int j=0; j<4; j++){ // b의 시작 위치
            for(int k=0; k<4; k++){ // c의 시작 위치
                int ay = startY[i];
                int ax = startX[i];
                int by = startY[j];
                int bx = startX[j];
                int cy = startY[k];
                int cx = startX[k];

                for(int y=0; y<4; y++){
                    for(int x=0; x<4; x++){
                        n_board[ay+y][ax+x] += number[a][an][y][x];
                        n_board[by+y][bx+x] += number[b][bn][y][x];
                        n_board[cy+y][cx+x] += number[c][cn][y][x];

                        if(n_board[ay+y][ax+x] > 9) n_board[ay+y][ax+x] = 9;
                        if(n_board[by+y][bx+x] > 9) n_board[by+y][bx+x] = 9;
                        if(n_board[cy+y][cx+x] > 9) n_board[cy+y][cx+x] = 9;

                        if(n_board[ay+y][ax+x] < 0) n_board[ay+y][ax+x] = 0;
                        if(n_board[by+y][bx+x] < 0) n_board[by+y][bx+x] = 0;
                        if(n_board[cy+y][cx+x] < 0) n_board[cy+y][cx+x] = 0;

                        if(color[a][an][y][x] != 'W'){
                            c_board[ay+y][ax+x] = color[a][an][y][x];
                        }
                        if(color[b][bn][y][x] != 'W'){
                            c_board[by+y][bx+x] = color[b][bn][y][x];
                        }
                        if(color[c][cn][y][x] != 'W'){
                            c_board[cy+y][cx+x] = color[c][cn][y][x];
                        }
                    }
                }
                int quality = 0;
                for(int p=0; p<5; p++){
                    for(int q=0; q<5; q++){
                        if(c_board[p][q] == 'R'){
                            quality += n_board[p][q] * 7;
                        }
                        else if(c_board[p][q] == 'B'){
                            quality += n_board[p][q] * 5;
                        }
                        else if(c_board[p][q] == 'G'){
                            quality += n_board[p][q] * 3;
                        }
                        else if(c_board[p][q] == 'Y'){
                            quality += n_board[p][q] * 2;
                        }
                    }
                }
                answer = max(quality, answer);
                
                memset(n_board, 0, sizeof(n_board));
                for(int p=0; p<5; p++){
                    for(int q=0; q<5; q++){
                        c_board[p][q] = 'W';
                    }
                }
            }
        }
    }

}

void rotate(){
    // i번째 재료
    for(int i=0; i<n; i++){
        // j번째 회전
        for(int j=1; j<4; j++){

            for(int a=0; a<4; a++){
                for(int b=0; b<4; b++){
                    number[i][j][a][b] = number[i][j-1][b][4-a-1];
                    color[i][j][a][b] = color[i][j-1][b][4-a-1];
                }
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