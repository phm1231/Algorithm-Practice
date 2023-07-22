// based problem:
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void spinBelt();
void move();
void up();
bool check(); 

int n, k; // 내구도가 0인 칸의 개수가 k개 이상이면 종료.
deque<int> belt;
deque<bool> robot;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    for(int i=0; i<n*2; i++){
        int tmp;
        cin >> tmp;
        belt.push_back(tmp); // 내구도
        robot.push_back(false);
    }
}

void solve()
{
    for(int stage=1; ; stage++){
        spinBelt();
        move();
        up();

        if(check()){
            cout << stage;
            break;
        }
    }
}

void spinBelt(){
    belt.push_front(belt.back());
    belt.pop_back();

    robot.push_front(robot.back());
    robot.pop_back();
    // n-1에 도착한 로봇은 내림.
    robot[n-1] = false;
}

void move(){
    for(int i=n-2; i>=0; i--){
        if(robot[i]){
            if(!robot[i+1] && belt[i+1] > 0){
                robot[i] = false;

                belt[i+1]--;
                robot[i+1] = true;

                robot[n-1] = false;
            }
        }
    }
}

void up(){
    if(belt[0] > 0){
        belt[0]--;
        robot[0] = true;
    }
}

bool check(){
    int cnt = 0;
    for(int i=0; i<belt.size(); i++){
        if(belt[i] == 0) cnt++;
    }
    return cnt >= k;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}