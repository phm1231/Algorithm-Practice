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
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int getAverage(vector<int>);
int getCenter(vector<int>);

vector<int> v;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    int num;
    for(int i=0; i<5; i++){
        cin >> num;
        v.push_back(num);
    }
}

void solve()
{
    cout << getAverage(v) << "\n" << getCenter(v);
    return;
}

int getAverage(vector<int> arr){
    int sum = 0;
    for(int value: arr){
        sum += value;
    }
    return sum / arr.size();
}

int getCenter(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}