// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
int max_value = -1000000001;
int min_value = max_value * -1;

vector<int> numbers;
vector<int> operators;

void dfs(int result, int next_idx){
    if(next_idx == n){
        max_value = max(result, max_value);
        min_value = min(result, min_value);
        return;
    }
    for(int i=0; i<4; i++){
        if(operators[i] > 0){
            operators[i]--;
            if(i == 0) dfs(result + numbers[next_idx], next_idx + 1);
            else if(i == 1) dfs(result - numbers[next_idx], next_idx + 1);
            else if(i == 2) dfs(result * numbers[next_idx], next_idx + 1);
            else if(i == 3) dfs(result / numbers[next_idx], next_idx + 1);
            operators[i]++;
        }
    }
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    numbers.resize(n, 0);
    operators.resize(4, 0);
    for(int i=0; i<n; i++) cin >> numbers[i];
    for(int i=0; i<4; i++) cin >> operators[i];
}

void solve()
{
    dfs(numbers[0], 1);
    cout << max_value << "\n" << min_value << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}