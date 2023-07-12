// based problem:
#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void spin(int,int);

int k;
deque<char> dq[4];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            char ch;
            cin >> ch;
            dq[i].push_back(ch);
        }
    }
    cin >> k;
}

void solve()
{
    // dp[2] = 우측, dp[6] = 좌측
    while(k--){
        int target, dir;
        cin >> target >> dir;
        // dq[target]을 dir 방향으로 회전시킬 것임.
        queue<pair<int, int> > spinQ;
        target--;
        spinQ.push(make_pair(target, dir));
        // dq[target]을 dir 방향으로 회전시켜야 할 때, 검사.
        char left = dq[target][6];
        char right = dq[target][2];

        // target의 좌측 톱니들에 대하여
        int leftdir = -dir;
        for(int i=target-1; i>=0; i--){
            // 좌측 톱니의 우측이 Left와 동일한지 확인
            // 동일하면 반대방향으로 회전시킬것임.
            if(dq[i][2] != left){
                spinQ.push(make_pair(i, leftdir));
                left = dq[i][6];
                leftdir = -leftdir;
            }
            else break;
        }
        // target의 우측 톱니들에 대하여.
        int rightdir = -dir;
        for(int i=target+1; i<4; i++){
            if(dq[i][6] != right){
                spinQ.push(make_pair(i, rightdir));
                right = dq[i][2];
                rightdir = -rightdir;
            }
            else break;
        }
        // 회전
        while(!spinQ.empty()){
            int spined = spinQ.front().first;
            int direction = spinQ.front().second;
            spinQ.pop();
            spin(spined, direction);
        }

    }
    // 점수 계산
    int answer = 0;
    int score = 1;
    for(int i=0; i<4; i++){
        if(dq[i].front() == '1') answer += score;
        score *= 2;
    }
    cout << answer;
}

void spin(int target, int dir){
    // 시계방향 회전
    if(dir == 1){
        int tmp = dq[target].back();
        dq[target].pop_back();
        dq[target].push_front(tmp);
    }
    else{
        int tmp = dq[target].front();
        dq[target].pop_front();
        dq[target].push_back(tmp);
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}