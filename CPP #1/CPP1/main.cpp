// Assignment C++: 1


#include "Menu.h"

#include <iostream>
using namespace std;

int main() {
    //simply creating a menu instance, then calling mainMenu(). the rest is inside mainMenu().
    Menu a;
    a.mainMenu();
    return 0;
}
/**
// Test Example
#include <iostream>
#include "VendingMachine.h"
#include "DispenserType.h"
#include "CashRegister.h"
#include "Stack.h"

using namespace std;

void TestIfEqual(int x, int y) {
    cout << (x == y ? "pass" : "fail") << endl;
}
void TestIfTrue(bool t) {
    cout << (t ? "pass" : "fail") << endl;
}

void test_stack1(void)
{
    Stack s;
    TestIfTrue(s.isEmpty());
}
void test_stack3(void)
{
    Stack s;
    s.push(5);
    TestIfEqual(s.peek(), 5);
}

int main() {
    test_stack1();
    test_stack3();
    return 0;
}
**/