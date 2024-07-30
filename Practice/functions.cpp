//pass by function
#include <iostream>
using namespace std;
int add(int a, int b)
{
    return a + b;
}
int main()
{
    int a = 10, b = 20;
    cout << "Sum is " << add(a, b);
    return 0;
}