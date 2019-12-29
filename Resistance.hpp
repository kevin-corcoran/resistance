//
//  Resistance.hpp
//  MapResistances
//
//  Created by Kevin Corcoran on 4/28/17.
//  Copyright © 2017 Kevin. All rights reserved.
//

#ifndef Resistance_hpp
#define Resistance_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include "Fraction.hpp"

using namespace std;


class Resistance
{
public:
   Resistance();
   void EquivalentR(int n);
   
   /*
   struct Fraction {
      int num;
      int den;
      bool inverted;
      
      vector<int> path;
      vector<Fraction> path_;
      friend Fraction operator+(Fraction f1, Fraction f2);
      friend ostream& operator<<(ostream& out, const Fraction &f);
      friend bool operator==(const Fraction &f1, const Fraction &f2);
      friend void operator++(Fraction f);
      
      void AddFraction(int num1, int den1, int num2, int den2, int &num3,
                       int &den3);
      void Lowest(int &den3, int &num3);
      int Gcd(int a, int b);
   };
   */
   
private:
   void Output(int row);
   void OutputFile(int row);
   void OutputPath(Fraction f);
   void AddRow(int row_a, int row_b, int curr_row);
   void File(int row_a, int row_b, int curr_row);
//   void RemoveDuplicates(int row);
   
   Fraction f;
   ofstream fout;
   ofstream fout_a;
   ifstream fin_a;
   ofstream fout_b;
   ifstream fin_b;
   vector<map<string,Fraction> > r_fract_arr_;
   int numerator_;
   string s_num_;
   int denominator_;
   string s_den_;
   int count_;
   string file_;
   string file_a;
   string file_b;
   string num_a;
   string den_a;
   string num_b;
   string den_b;

};

#endif /* Resistance_hpp */

