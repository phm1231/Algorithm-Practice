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
#define MAX 1000001
using namespace std;

void init();
void input();
void solve();
int divide_sum(char* );

char numbers[10];
int answers[MAX]; // answers[i]는 i의 분해합

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(numbers, 0, sizeof(numbers));
    memset(answers, 0, sizeof(answers));
}

void input()
{
   scanf("%s", numbers);
}

void solve()
{
    string string_tmp;
    char* char_tmp = (char *)malloc(sizeof(char)*100);
    int input_number = atoi(numbers);
    int target_index = -1;
    for(int i=1; i<input_number; i++)
    {
        string_tmp = to_string(i);
        strcpy(char_tmp, string_tmp.c_str());
        answers[i] = divide_sum(char_tmp);
        if(answers[i] == input_number)
        {
            target_index = i;
            break;
        }
    }
    if(target_index == -1) printf("0");
    else printf("%d", target_index);
}

int divide_sum(char* num)
{
    int res = atoi(num);
    int len = strlen(num);
    for(int i=0; i<len; i++)
    {
        res += (num[i] - '0');
    }
    return res;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}