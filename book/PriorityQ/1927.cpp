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
        if(a >= b) return true;
        else return false;
    }
};

priority_queue<int, vector<int>, cmp> pq;
int n;

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