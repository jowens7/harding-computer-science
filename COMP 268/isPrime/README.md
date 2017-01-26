Write a TINY program that is equivalent to the following C++ program. Submit your ".tny" source code file using EASEL.
 
// isPrime.cpp
//   This program accepts an integer and determines if it is prime.
 
#include <iostream.h>
void main ()
{
   int x,p,d,r;
 
   cout << “Enter an integer greater than 1: “;
   cin  >> x;
   p = 1;
   d = 2;
 
   while (d <= (x-1))
   {
      r =  x - (d * (x / d));    // (Same as r = x % d;)
      if (r == 0)
      {
         p = 0;
      }
      d++;
   }
 
   if (p == 1)
      cout << “Yes” << endl;
   else
      cout << “No” << endl;
}
 
