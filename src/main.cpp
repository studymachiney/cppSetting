#include <iostream>
using namespace std;

#include <string>
#include <vector>

#include "print.h"

int main(int, char**) {
    struct student {
        string name;
        int age;
        int score;
    };
    student s = { "张三", 18, 88};
    int a = 5;
    string str = "nihao";
    char charlist[] = "list";
    cout << sizeof(long) << endl;
    int b[] = {1,2,3,4,52};
    vector<int> aa = {1,2,3};
    a++;
    cout << a << endl;
    cout << "name: " << s.name << " age: " << s.age << " score " << s.score << endl;
    cout << "Hello, world!\n";
    printAll();
    system("pause");
    return 0;
}
