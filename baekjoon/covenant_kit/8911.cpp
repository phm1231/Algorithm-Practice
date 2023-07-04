// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int dy[] = {-1, 0, 1, 0}; // direction = 0 -> 북쪽, 1이면 서쪽
int dx[] = {0, -1, 0, 1};
string str;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    str = "";
    cin >> str;
}

void solve()
{
    // tuple y, x direction
    int ly, lx, ry, rx;
    ly = lx = ry = rx = 0;

    int y = 0;
    int x = 0;
    int dir = 0;

    for(int i=0; i<str.size(); i++){
        if(str[i] == 'F'){
            y = y + dy[dir];
            x = x + dx[dir];
        }
        else if(str[i] == 'B'){
            y = y - dy[dir];
            x = x - dx[dir];
        }
        else if(str[i] == 'L'){
            dir = (dir + 1) % 4;
        }
        else if(str[i] == 'R'){
            dir--;
            if(dir < 0) dir = 3;
        }
        ly = min(ly, y);
        lx = min(lx, x);
        ry = max(ry, y);
        rx = max(rx, x);
    }
    cout << abs(ry - ly) * abs(rx - lx) << "\n";
}

int main()
{
    init();
    int tc;
    cin >> tc;
    while(tc--){
        input();
        solve();
    }
    return 0;
}