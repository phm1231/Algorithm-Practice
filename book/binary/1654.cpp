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
#define MAX 10001
using namespace std;

void init();
void input();
void solve();

int k, n;
int length[MAX];

void init()
{
    memset(length, 0, sizeof(length));
}

void input()
{
    scanf("%d %d", &k, &n);
    for(int i=0; i<k; i++){
        scanf("%d", &length[i]);
    }
}

void solve()
{
    int left = 1, right = INT_MAX - 1;
    int ans = INT_MIN;
    while(left <= right){
        int mid = (left + right) / 2;
        int count = 0;
        for(int i=0; i<k; i++){
            count += length[i] / mid;
        }
        if(count >= n){ // 너무 짧게 자름
            left = mid + 1;
            if(ans < mid) ans = mid;
        }
        else{ // 너무 길게 자름
            right = mid - 1;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}