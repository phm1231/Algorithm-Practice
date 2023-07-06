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
const int startY[] = {0, 0, 1, 1};
const int startX[] = {0, 1, 0, 1};
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

    // 3개를 뽑으면서 완전탐색, 중복은 불가.
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
    for(int i=0; i<4; i++){ // a번째 판 회전
        for(int j=0; j<4; j++){ // b번째 판 회전
            for(int k=0; k<4; k++){ // c번째 판 회전
                // number[a][i], number[b][j], number[c][k] 번째를 사용하는거야 ^^7
                calcul(a, i, b, j, c, k);
            }
        }
    }
}

void calcul(int a, int an, int b, int bn, int c, int cn){
    int n_board[5][5];
    char c_board[5][5];

    for(int i=0; i<4; i++){ // a의 시작 위치
        for(int j=0; j<4; j++){ // b의 시작 위치
            for(int k=0; k<4; k++){ // c의 시작 위치
                // 가마 초기화
                for(int p=0; p<5; p++){
                    for(int q=0; q<5; q++){
                        n_board[p][q] = 0;
                        c_board[p][q] = 'W';
                    }
                }

                for(int t=0; t<3; t++){
                    int sy, sx;
                    int board_number, rot_number;
                    if(t == 0){
                        sy = startY[i];
                        sx = startX[i];
                        board_number = a;
                        rot_number = an;
                    }
                    else if(t == 1){
                        sy = startY[j];
                        sx = startX[j];
                        board_number = b;
                        rot_number = bn;
                    }
                    else{
                        sy = startY[k];
                        sx = startX[k];
                        board_number = c;
                        rot_number = cn;
                    }

                    for(int y=0; y<4; y++){
                        for(int x=0; x<4; x++){
                            n_board[sy+y][sx+x] += number[board_number][rot_number][y][x];

                            if(n_board[sy+y][sx+x] > 9) n_board[sy+y][sx+x] = 9;
                            else if(n_board[sy+y][sx+x] < 0) n_board[sy+y][sx+x] = 0;

                            if(color[board_number][rot_number][y][x] != 'W'){
                                c_board[sy+y][sx+x] = color[board_number][rot_number][y][x];
                            }
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