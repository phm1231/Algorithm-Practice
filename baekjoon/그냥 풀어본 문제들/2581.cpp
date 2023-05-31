// based problem:
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

int n, m;
int arr[10001];

void init()
{
    FAST
}

void input()
{
    cin >> n >> m;
}

void solve()
{
    // 에라토스테네스의 체
    arr[0] = arr[1] = 0;
    for(int i=2; i<10001; i++) arr[i] = i;

    for(int i=2; i<=sqrt(10000); i++){
        if(arr[i] == 0) continue;
        for(int j=i*i; j<=10000; j+=i) arr[j] = 0;
    }
    
    int mini = 987654321;
    long long sum = 0;
    for(int i=n; i<=m; i++){
        sum += arr[i];
        if(arr[i] != 0 && mini > arr[i]) mini = arr[i];
    }

    if(sum == 0){
        cout << -1 << endl;
        return;
    }

    cout << sum << endl;
    cout << mini << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}