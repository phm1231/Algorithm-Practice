// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int w[21][21][21];
int getW(int, int, int);

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(w, 0, sizeof(w));
}

void input()
{

}

void solve()
{
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        else cout << "w(" << a << ", " << b << ", " << c << ") = " << getW(a, b, c) << "\n";
    }
}

int getW(int x, int y, int z){
    if(x <= 0 || y <= 0 || z <= 0) return 1;
    if(x > 20 || y > 20 || z > 20) return 1048576;

    if(x < y && y < z){
        int sum = 0;
        if(w[x][y][z-1] == 0) w[x][y][z-1] = getW(x, y, z-1);
        if(w[x][y-1][z-1] == 0) w[x][y-1][z-1] = getW(x, y-1, z-1);
        if(w[x][y-1][z] == 0) w[x][y-1][z] = getW(x, y-1, z);

        return w[x][y][z-1] + w[x][y-1][z-1] - w[x][y-1][z];
    }

    else{
        if(w[x-1][y][z] == 0) w[x-1][y][z] = getW(x-1, y, z);
        if(w[x-1][y-1][z] == 0) w[x-1][y-1][z] = getW(x-1, y-1, z);
        if(w[x-1][y][z-1] == 0) w[x-1][y][z-1] = getW(x-1, y, z-1);
        if(w[x-1][y-1][z-1] == 0) w[x-1][y-1][z-1] = getW(x-1, y-1, z-1);

        return w[x-1][y][z] + w[x-1][y-1][z] + w[x-1][y][z-1] - w[x-1][y-1][z-1];
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}