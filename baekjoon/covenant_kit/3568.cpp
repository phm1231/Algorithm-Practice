// based problem:
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

string str;
stack<char> stk;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    getline(cin, str);
}

void solve()
{
    // 공통 부분
    string same = "";
    int i;
    for(i=0; i<str.size(); i++){
        if(str[i] == ' ') break;
        else same += str[i];
    }

    // i는 띄어쓰기임.
    i++;
    string name = "";
    for(; i<str.size(); i++){
        if(str[i] == ';' || str[i] == ','){
            cout << same;
            while(!stk.empty()){
                char ch = stk.top();
                stk.pop();
                if(ch == '[') cout << "[]";
                else cout << ch;
            }
            cout << ' ' << name << ";\n";

            name = "";

        }
        else if(str[i] == '[' || str[i] == '&' || str[i] == '*'){
            stk.push(str[i]);
        }
        else if(str[i] == ' ') continue;
        else if(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')){
            name += str[i];
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