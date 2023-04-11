#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
 
using namespace std;
 
int main(void)
{
    vector<int> v;
 
    printf("원래의 vector = ");
 
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
 
        printf("%d ", i);
    }
    printf("\n");
 
    printf("맨 앞 원소 삭제 = ");
    v.erase(v.begin());
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    printf("두 번째 원소 삭제 = ");
    v.erase(v.begin() + 1);
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    printf("끝 원소 삭제 = ");
    v.erase(v.end() - 1);
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    printf("숫자 8 삭제 = ");    
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) == 8)
        {
            v.erase(v.begin() + i);
            break;
        }
    }
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    printf("제일 처음에 숫자 1 삽입 = ");
    v.insert(v.begin(), 1);
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    printf("제일 끝에 숫자 10 삽입 = ");
    v.insert(v.end(), 10);
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    printf("오름차순 되게 숫자 3 삽입 = ");
    v.insert(v.begin() + 2, 3);
    for (auto i : v) printf("%d ", i);
    printf("\n");
 
    return 0;
}
