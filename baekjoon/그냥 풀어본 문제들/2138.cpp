// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void go(int, int, string, string);
void change(string&, int);

int n, answer;
string src, dst;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> src >> dst;
}

void solve()
{
    answer = 987654321;

    // 0번을 누르지 않고 시작함.
    go(0, 1, src, dst);

    // 0번을 누르고 시작함
    change(src, 0);
    go(1, 1, src, dst);

    answer = (answer == 987654321 ? -1 : answer);
    cout << answer;
}

void change(string& s, int idx){
    for(int i=idx-1; i<=idx+1; i++){
        if(0 <= i && i < n){
            s[i] = (s[i] == '1' ? '0' : '1');
        }
    }
}


void go(int cnt, int idx, string from, string to){
    for(int i=idx; i<n; i++){
        if(from[i-1] != to[i-1]){
            change(from, i);
            cnt++;
        }
    }
    if(from == to) answer = min(answer, cnt);
}



int main()
{
    init();
    input();
    solve();
    return 0;
}