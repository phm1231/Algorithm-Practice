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
#define MAX 1001
using namespace std;

void init();
void input();
void solve();
int recursion(const char *, int, int);
int isPalindrome(const char *);

int n;
int ans;
char* str[MAX];

int recursion(const char *s, int l, int r){
    ans++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<MAX; i++){
        str[i] = (char *)malloc(sizeof(char) * MAX);
    }
}

void input()
{
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }
}

void solve()
{
    for(int i=0; i<n; i++){
        ans = 0;
        printf("%d %d\n",isPalindrome(str[i]), ans);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}