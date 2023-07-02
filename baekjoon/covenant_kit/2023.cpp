// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int, int);
bool isPrime(int);

int n;

vector<int> answer;

bool isPrime(int number){
    if(number == 1) return false;
    for(int i=2; i*i<=number; i++){
        if(number % i == 0) return false;
    }
    return true;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{

    for(int num: {2, 3, 5, 7}){
        dfs(num, 1);
    }

    sort(answer.begin(), answer.end());
    for(int num: answer){
        cout << num << "\n";
    }
}

void dfs(int number, int len){
    if(len == n){
        answer.push_back(number);
        return;
    }
    else{
        for(int i=0; i<10; i++){
            int next = number * 10 + i;
            if(isPrime(next)){
                dfs(next, len + 1);
            }
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