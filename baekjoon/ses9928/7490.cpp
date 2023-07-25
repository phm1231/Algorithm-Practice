// based problem:
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int, string);
long long cal(string);


int n;

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
    dfs(0, "");
}

void dfs(int depth, string s){
    if(depth == 2*n-1){
        long long res = cal(s);
        if(res == 0) cout << s << "\n";
        return;
    }

    // depth가 짝수일 때는 숫자
    if(depth % 2 == 0){
        dfs(depth + 1, s + to_string(depth / 2 + 1));
    }
    else{
        dfs(depth + 1, s + " ");
        dfs(depth + 1, s + "+");
        dfs(depth + 1, s + "-");
    }
}

long long cal(const string str){
    long long result = 0;
    long long tmp = 0;
    char oper = '0';

    for(int i=0; i<str.size(); i++){
        if('0' <= str[i] && str[i] <= '9'){
            tmp += (str[i] - '0');
            if(i == str.size() - 1){
                if(oper == '0' || oper == '+') result += tmp;
                else if(oper == '-') result -= tmp;
            }
        }
        else if(str[i] == '+' || str[i] == '-'){
            if(oper == '0' || oper == '+') result += tmp;
            else if(oper == '-') result -= tmp;

            oper = str[i];
            tmp = 0;
        }
        else if(str[i] == ' '){
            tmp *= 10;
        }
    }

    return result;
}


int main()
{
    int t;
    cin >> t;
    init();
    while(t--){
        input();
        solve();
        cout << "\n";
    }
    return 0;
}