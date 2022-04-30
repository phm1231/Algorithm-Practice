// based problem: String
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
#define MAX 100001

using namespace std;

void init();
void input();
void solve();

char tmp[MAX];
char str[MAX];
int m, cursor;
// cursor-1의 index를 삭제, 추가 ...

void init()
{

    memset(str, 0, sizeof(str));
    memset(tmp, 0, sizeof(tmp));
}

void input()
{
    scanf("%s", str);
    getchar();
    scanf("%d", &m);
    getchar();
}

void solve()
{
    cursor = strlen(str);
    for(int i=0; i<m; i++)
    {
        char command, ch;
        scanf("%c", &command);
        getchar();
        printf("cursor: %d\n", cursor);
        switch(command)
        {
            case 'L':
                if(cursor != 0) cursor--;
                break;

            case 'D':
                if(cursor != strlen(str)) cursor++;
                break;

            case 'B':
                if(cursor != 0)
                {
                    str[cursor-1] = '\0';
                    memcpy(str + cursor - 1, str + cursor + 1, strlen(str + cursor + 1));
                    cursor--;
                    // strcat(str, &str[cursor]);
                }
                break;

            case 'P':
                scanf("%c", &ch);
                getchar();
                memcpy(tmp, str, cursor);
//                printf("1. tmp is %s\n", tmp);
                memcpy(tmp + cursor, &ch, 1);
//                printf("2. tmp is %s\n", tmp);
                strcat(tmp + cursor + 1, str + cursor);
//                printf("3. tmp is %s\n", tmp);
                memcpy(str, tmp, strlen(tmp));
                memset(tmp, 0, sizeof(tmp));
                cursor++;
                break;

            default:
                break;
        }
        printf("%s\n", str);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}