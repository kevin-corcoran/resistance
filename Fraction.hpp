//
//  Fraction.hpp
//  MapResistances
//
//  Created by Kevin Corcoran on 4/28/17.
//  Copyright © 2017 Kevin. All rights reserved.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;


void AddFraction(int num1, int den1, int num2, int den2, int &num3,
                 int &den3);
void Lowest(int &den3, int &num3);
int Gcd(int a, int b);

class Fraction
{
public:
   friend Fraction operator+(Fraction f1, Fraction f2);
   friend ostream& operator<<(ostream& out, const Fraction &f);
   friend bool operator==(const Fraction &f1, const Fraction &f2);
//   friend void operator=(const Fraction &f1);

   friend void operator++(Fraction f);

//   Fraction f;
   int num;
   int den;
   bool inverted;
   vector<int> path;
   vector<Fraction> path_;
};



#endif /* Fraction_hpp */
