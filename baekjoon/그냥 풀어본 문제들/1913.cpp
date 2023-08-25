// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, target;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<vector<int> > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> target;
    bd.resize(n, vector<int>(n, 0));
}

void solve()
{
    int y = n / 2;
    int x = n / 2;

    int cnt = 1;
    int dir = 0;
    int number = 1;
    int spin = 0;

    while(1){
        for(int i=0; i<cnt; i++){
            bd[y][x] = number;
            if(y == 0 && x == 0) break;

            number++;
            y = y + dy[dir];
            x = x + dx[dir];
        }
        spin++;

        if(spin == 2){
            spin = 0;
            cnt++;
        }
        if(y == 0 && x == 0) break;
        dir++;
        dir %= 4;
    }

    int Y, X;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << bd[i][j] << ' ';
            if(bd[i][j] == target){
                Y = i + 1;
                X = j + 1;
            }
        }
        cout << "\n";
    }
    cout << Y << " " << X;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}