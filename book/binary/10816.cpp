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
#define MAX 500001
#define THOUSAND 10000000
using namespace std;

void init();
void input();
void solve();

int n, m;
vector<int> v;

void init()
{

}

void input()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
}

void solve()
{
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int target;
        scanf("%d", &target);
        printf("%d\n", upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target));
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}