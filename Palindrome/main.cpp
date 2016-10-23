#include <iostream>
#include <cstring>
#include "palindrome.h"

using namespace std;

// Tests
int main()
{
    char a[] = "abcdcba";
    char b[] = "1221";
    char c[] = "ablab";

    if (palindrome(a, 0, strlen(a)-1))
        cout << a << " is a palindrome" << endl;

    if (palindrome(b, 0, strlen(b)-1))
        cout << b << " is a palindrome" << endl;

    if (palindrome(c, 0, strlen(c)-1))
        cout << c << " is a palindrome" << endl;

    return 0;
}
