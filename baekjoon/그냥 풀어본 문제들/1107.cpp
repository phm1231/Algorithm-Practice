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
void dfs(string);

int channel;
unsigned long answer = 987654321;
string channel_str;
bool isBroken[10];

void init()
{
    FAST
    memset(isBroken, false, sizeof(isBroken));
}

void input()
{
    cin >> channel;
    channel_str = to_string(channel);

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        isBroken[tmp] = true;
    }
}

void dfs(string s){

    if(s != "") answer = min(answer, s.size() + abs(channel - stoi(s)));

    if(s.size() <= 5){
        for(int i=0; i<10; i++){
            // 0으로 시작하는 채널은 없음.
            if(s.size() == 0 && i == 0) continue;
        
            if(!isBroken[i]){
                dfs(s + to_string(i));
            }
        }
    }
}

void solve()
{
    answer = abs(channel - 100); // + 나 - 버튼 만으로 이동할 수 있음.
    if(!isBroken[0]) answer = min(answer, (unsigned long)(1 + abs(channel))); // 0번을 입력했을 때,

    dfs("");
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}