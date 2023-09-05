#include<iostream>
#include<string>
using namespace std;
 
int main(void) {
    int result1 = 1;
    int result2 = 2;
    int result3 = 3;
    int result4 = 4;
 
    // 일부 복사
    cout << "1. 특정변수 복사" << endl;
    [result1, result2](int a, int b) { 
        cout << "result1, result2 : " << result1 << ", " << result2 << endl;
        cout << "result1 + a + b : " << result1 + a + b << endl;
 
        // 복사한 변수에는 대입 불가능
        // result1 = a + b; 
        // result2 = 99999;
    }(10, 20);
 
 
 
    // 일부 참조
    cout << "2. 특정변수 참조" << endl;
    [&result3, &result4](int a, int b) {
        result3 = 22222;
        cout << "(내부) result3 : " << result3 << endl;
        result4 = a + b;
    }(10, 20);
 
    cout << "(외부) result3, result4 : " << result3 << ", " << result4 << endl;
 
    return 0;
}
 