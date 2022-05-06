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
#define MAX 1000001
using namespace std;

void init();
void input();
void solve();

int tree_number, need_length;
int heights[MAX];

void init()
{
    memset(heights, 0, sizeof(heights));
}

void input()
{
    scanf("%d %d", &tree_number, &need_length);
    for(int i=0; i<tree_number; i++){
        scanf("%d", &heights[i]);
    }
}

void solve()
{
    int left = 0, right = INT_MAX - 1;
    ll ans = INT_MIN;

    while(left <= right){
        int mid = (left + right) / 2; // mid가 자를 높이.
        ll get_length = 0;

        for(int i=0; i<tree_number; i++){
            if(heights[i] > mid) get_length += heights[i] - mid;
        }   

        if(get_length >= need_length){ // 과하게 많이 자른 경우, 나무의 높이를 높여주어야 한다.
            left = mid + 1;
            if(ans < mid) ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%lld", ans);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}