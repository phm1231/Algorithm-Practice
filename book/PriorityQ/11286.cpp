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

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) > abs(b)) return true;
        else if(abs(a) == abs(b)){
            return a > b;
        }
        else return false;
    }
};

int n;
priority_queue<int, vector<int>, cmp> pq;

void init()
{

}

void input()
{
    scanf("%d", &n);

}

void solve()
{
    for(int i=0; i<n; i++){
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 0){
            if(!pq.empty()){
                printf("%d\n", pq.top());
                pq.pop();
            }
            else{
                printf("0\n");
            }
        }
        else{
            pq.push(cmd);
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