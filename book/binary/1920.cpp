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
bool my_binary_search(int *, int, int);
int n, m;
int arr[MAX];

bool my_binary_search(int *arr, int arr_size, int target){
    int left = 0, right = arr_size - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] < target) left = mid + 1;
        else if(arr[mid] > target) right = mid - 1;
        else return true;
    }
    return false;
}

void init()
{
    memset(arr, 0, sizeof(arr));
}

void input()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
}

void solve()
{
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int target;
        scanf("%d", &target);
        my_binary_search(arr, n, target) ? printf("1\n") : printf("0\n");
            
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}