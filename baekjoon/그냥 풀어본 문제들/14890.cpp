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
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

void init();
void input();
void solve();
bool check(const vector<int>& );
void print_vector(const vector<int>&);

int n, l;
vector<vector<int> > board;
vector<bool> row;
vector<bool> col;

bool check(const vector<int>& line){
    int current = line[0];
    int same = 1;
    // 3 2 2 2 3 3, l=3
    // 1 1 1 2 2 2, l=2

    for(int i=1; i<n; i++){
        if(current + 1 < line[i] || current - 1 > line[i]) return false;

        if(current == line[i]){
            same++;
            continue;
        }
        // 나보다 낮은 것
        if(current == line[i] + 1){
            // 앞에 l개 만큼의 낮은 블록이 있나 확인
            for(int j=0; j<l; j++){
                if(i+j < n && line[i+j] + 1 == current) continue;
                else return false;
            }
            current--;
            same = 0;
            i += (l-1);
        }
        // 나보다 높은 것
        else if(current == line[i] - 1){
            if(same >= l){
                current++;
                same = 1;
            }
            else return false;
        }
    }
    return true;
}

void print_vector(const vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

void init()
{
    FAST
}

void input()
{
    cin >> n >> l;
    board.resize(n, vector<int>(n, 0));
    row.resize(n, true);
    col.resize(n, true);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    // 좌에서 우로 확인
    for(int i=0; i<n; i++){
        row[i] = check(board[i]);
    }

    // 상에서 하로 확인
    for(int x=0; x<n; x++){
        vector<int> tmp;
        for(int y=0; y<n; y++){
            tmp.push_back(board[y][x]);
        }
        col[x] = check(tmp);
    }

    
    int answer = 0;
    for(int i=0; i<n; i++){
        if(row[i]) answer++;
        if(col[i]) answer++;
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