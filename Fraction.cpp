//
//  Fraction.cpp
//  MapResistances
//
//  Created by Kevin Corcoran on 4/28/17.
//  Copyright © 2017 Kevin. All rights reserved.
//

#include "Fraction.hpp"

//Fraction::Fraction(int n, int d) {
//   num = n;
//   den = d;
//}

bool operator==(const Fraction &f1, const Fraction &f2)
{
   if (f1.num == f2.num && f1.den == f2.den)
      return true;
   else
      return false;
}

Fraction operator+(Fraction f1, Fraction f2)
{
   int n;
   int d;
   AddFraction(f1.num, f1.den, f2.num, f2.den, n, d);
   Fraction f;
   f.num = n;
   f.den = d;
   return f;
}

void operator++(Fraction f) {
   int *temp = nullptr;
   *temp = f.num;
   delete temp;
}

ostream& operator<<(ostream& out, const Fraction &f)
{
   out << f.num << "/" << f.den;
   return out;
}


void AddFraction(int num1, int den1, int num2, int den2, int &num3,
                 int &den3)
{
   // Finding gcd of den1 and den2
   den3 = Gcd(den1,den2);
   
   // Denominator of final fraction obtained
   // finding LCM of den1 and den2
   // LCM * GCD = a * b
   den3 = (den1*den2) / den3;
   
   // Changing the fractions to have same denominator
   // Numerator of the final fraction obtained
   num3 = (num1)*(den3/den1) + (num2)*(den3/den2);
   
   // Calling function to convert final fraction
   // into it's simplest form
   Lowest(den3,num3);
}

void Lowest(int &den3, int &num3)
{
   // Finding gcd of both terms
   int common_factor = Gcd(num3,den3);
   
   // Converting both terms into simpler
   // terms by dividing them by common factor
   den3 = den3/common_factor;
   num3 = num3/common_factor;
}

int Gcd(int a, int b)
{
   if (a == 0)
      return b;
   return Gcd(b%a, a);
}
