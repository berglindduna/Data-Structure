// 18.02.2016

#include "palindrome.h"

bool palindrome(const char a[], int first, int last)
{
   return (last-first) < 1 || (a[first] == a[last] && palindrome(a, first+1, last-1));
}
