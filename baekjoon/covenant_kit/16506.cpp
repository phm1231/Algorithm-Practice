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
string toBinary(int, int);

string cmd;
int d, a, b;
vector<string> cmds;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cmds.push_back("ADD");
    cmds.push_back("ADDC");
    cmds.push_back("SUB");
    cmds.push_back("SUBC");
    cmds.push_back("MOV");
    cmds.push_back("MOVC");
    cmds.push_back("AND");
    cmds.push_back("ANDC");
    cmds.push_back("OR");
    cmds.push_back("ORC");
    cmds.push_back("NOT");
    cmds.push_back("MULT");
    cmds.push_back("MULTC");
    cmds.push_back("LSFTL");
    cmds.push_back("LSFTLC");
    cmds.push_back("LSFTR");
    cmds.push_back("LSFTRC");
    cmds.push_back("ASFTR");
    cmds.push_back("ASFTRC");
    cmds.push_back("RL");
    cmds.push_back("RLC");
    cmds.push_back("RR");
    cmds.push_back("RRC");
}

void input()
{
    cin >> cmd >> d >> a >> b;
}

void solve()
{
    string output = "";
    for(int i=0; i<cmds.size(); i++){
        if(cmd == cmds[i]){
            // 0~3번
            if(i < 10) output += toBinary(i/2, 4);
            else if(i == 10) output += toBinary(5, 4);
            else output += toBinary((i+1)/2, 4);


            // 4번
            if(cmd[cmd.size() - 1] == 'C') output += to_string(1);
            else output += to_string(0);
            // 5번
            output += to_string(0);

            break;
        }
    }
    // 6~8번
    output += toBinary(d, 3);


    // 9~11번
    if(cmd == "MOV" || cmd == "MOVC" || cmd == "NOT") output += "000";
    else output += toBinary(a, 3);

    // 12~14번
    if(cmd[cmd.size() - 1] == 'C') output += toBinary(b, 4);
    else{
        output += toBinary(b, 3) + "0";
    }
    
    cout << output << "\n";
}

string toBinary(int number, int len){
    stack<int> stk;
    string ret = "";
    while(number != 0){
        stk.push(number % 2);
        number /= 2;
    }
    while(!stk.empty()){
        ret += to_string(stk.top());
        stk.pop();
    }
    while(ret.size() < len){
        ret = "0" + ret;
    }
    return ret;
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}