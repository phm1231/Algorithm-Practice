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
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

deque<string> numQ;
queue<char> operQ;

string str;

void init()
{
    FAST
}

void input()
{
    cin >> str;
}

void solve()
{
    string tmp = "";
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if('0' <= ch && ch <= '9'){
            tmp += ch;
        }
        else if(ch == '+'){
            numQ.push_back(tmp);
            tmp = "";
            operQ.push(ch);
        }
        else if(ch == '-'){
            numQ.push_back(tmp);
            tmp = "";
            operQ.push(ch);
        }

        if(i == str.size() - 1){
            numQ.push_back(tmp);
        }
    }


    int siz = operQ.size();
    for(int i=0; i<siz; i++){
        // +면 숫자 두 개 꺼내서 더해주고 결과를 숫자 앞에 넣어준다.
        if(operQ.front() == '+'){
            int num1 = stoi(numQ.front());
            numQ.pop_front();
            num1 += stoi(numQ.front());
            numQ.pop_front();
            numQ.push_front(to_string(num1));
        }
        // -면 숫자 1개 꺼내서 뒤로 넣어준다. (계산 미룸)
        else{
            numQ.push_back(numQ.front());
            numQ.pop_front();
            operQ.push('-');
        }
        operQ.pop();
    }
    // +가 끝난 결과를 뒤로 보내주기
    numQ.push_back(numQ.front());
    numQ.pop_front();

    siz = operQ.size();
    int answer = stoi(numQ.front());
    numQ.pop_front();
    for(int i=0; i<siz; i++){
        answer -= stoi(numQ.front());
        numQ.pop_front();
    }
    cout <<  answer << endl;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}