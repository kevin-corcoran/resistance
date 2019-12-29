//
//  Resistance.cpp
//  MapResistances
//
//  Created by Kevin Corcoran on 4/28/17.
//  Copyright © 2017 Kevin. All rights reserved.
//

#include "Resistance.hpp"


Resistance::Resistance() {
   count_ = 0;
   numerator_ = 1;
   s_num_ = to_string(numerator_);
   denominator_ = 1;
   s_den_ = to_string(denominator_);
   f.num = numerator_;
   f.den = denominator_;
   fout.open("n 1.txt");
   fout << f << "\n";
   fout << "\n" << "n: 1" << "\n" << "size: 1" << "\n" << "\n";
   fout.close();
}

void Resistance::EquivalentR(int n) {

   r_fract_arr_.resize(n);
   r_fract_arr_[0][s_num_+s_den_] = f; //.push_back(f);

   for (int i = 1; i < n; i++)
   {
      count_ = 0;
      while (count_ <= (i - (count_+1))) {
         AddRow(count_, i - (count_+1), i);
         File(count_, i - (count_+1), i);
         count_++;
      }
//      count_ = 0;
      
//      RemoveDuplicates(i);


      OutputFile(i);
      Output(i);
   }
}

void Resistance::File(int row_a, int row_b, int curr_row) {
//   Fraction a;
   file_a = "n " + to_string(row_a+1) + ".txt";
   file_b ="n " + to_string(row_b+1) + ".txt";
   fin_a.open(file_a.c_str());
   fin_b.open(file_b.c_str());
   
//   while(fin_a.good())
//      num_a = fin_a.get();
//   
//   cout << num_a << endl;
   //   cout << a << endl;
   
   fin_a.close();
   fin_b.close();
}

void Resistance::AddRow(int row_a, int row_b, int curr_row) {
   
//   int num = 0;
   
   for (auto a : r_fract_arr_[row_a]) {
      for (auto b : r_fract_arr_[row_b]) {
     
         f = a.second + b.second;

         s_num_ = to_string(f.num);
         s_den_ = to_string(f.den);
         // add if key doesnt exist
         if (r_fract_arr_[curr_row].count(s_num_+"/"+s_den_) == 0)
            r_fract_arr_[curr_row][s_num_+"/"+s_den_] = f; //.push_back(f);
         
         // invert
         numerator_ = f.num;
         denominator_ = f.den;
         f.num = denominator_;
         f.den = numerator_;
         // if it doesnt it exist
         if (r_fract_arr_[curr_row].count(s_den_+"/"+s_num_) == 0)
            r_fract_arr_[curr_row][s_den_+"/"+s_num_] = f; //.push_back(f);
      }
   }
   

   /*
   for (int j = 0; j < r_fract_arr_[row_a].size(); j+=1)
   {
      if (row_a == row_b)
         num = j;
      for (int k = num; k < r_fract_arr_[row_b].size(); k+=1)
      {
         //            cout << "index j: " << j  << "    " << "index k: " << k << endl;
         //            cout << resistance_array_[row_a][j] << "/" << resistance_array_[row_a][j+1] << " + " <<
         //                        resistance_array_[row_b][k] << "/" << resistance_array_[row_b][k+1] << " = " << endl;
         
         f = r_fract_arr_[row_a][j] + r_fract_arr_[row_b][k];
         numerator_ = f.num;
         denominator_ = f.den;
         // Add 1 in series
         f.inverted = false;
         
         f.path_.push_back(r_fract_arr_[row_a][j]);
         f.path_.push_back(r_fract_arr_[row_b][k]);
         
         r_fract_arr_[curr_row].push_back(f);
         
         // Invert because it works
         f.den = numerator_;
         f.num = denominator_;
         f.inverted = true;
         r_fract_arr_[curr_row].push_back(f);
      }
   }
 */
}
void Resistance::OutputPath(Fraction f) {
   /*
   cout <<"   f: " << f << ": ";
   for (int i = 0; i < f.path_.size(); i+=1) {
      cout  << " " << f.path_[i] << " (" << f.inverted << ")";
      if (i == 1) {
         if (!(f.path_[i-1] == r_fract_arr_[0][0]))
            OutputPath(f.path_[i-1]);
         if (!(f.path_[i] == r_fract_arr_[0][0]))
            OutputPath(f.path_[i]);
      }
   }
   */
}
void Resistance::OutputFile(int row) {
   file_ = "n " + to_string(row+1) + ".txt";
   fout.open(file_.c_str());
   
//   if (r_fract_arr_[row].size() == 2) {
//      fout << r_fract_arr_[0]["11"] << endl << endl;
//      fout << "n: 1" << endl << "size: 1" << endl << endl;
//   }
      // Output resistances
      for (auto a : r_fract_arr_[row])
      {
         fout << a.second << "\n";
   
      }
   // Number of resistors and size (number of) eq resistances
   fout << "\n" << "n: " << row + 1 << "\n" << "size: " << r_fract_arr_[row].size() << "\n" << "\n";
   fout.close();
}
void Resistance::Output(int row) {
   // One resistor
   if (r_fract_arr_[row].size() == 2) {
//      cout << r_fract_arr_[0]["11"] << endl << endl;
      cout << "n: 1" << endl << "size: 1" << endl << endl;
   }

//   // Output resistances
//   for (auto a : r_fract_arr_[row])
//   {
//      cout << a.second << endl;
//      
//   }
   // Number of resistors and size (number of) eq resistances
   cout << endl << "n: " << row + 1 << endl << "size: " << r_fract_arr_[row].size() << endl << endl;
   
/*
   if (row == 1) { // Output Row 1.. before Row 2...
      cout << "1/1" << endl << endl << "n: 1" << endl << "size: 1" << endl << endl << "--------------" << endl << endl;
   }
   
   if (row == 1) { // Output Row 1.. before Row 2...
      cout << "1/1" << endl << endl << "n: 1" << endl << "size: 1" << endl << endl << "--------------" << endl << endl;
   }
   for (int k = 0; k < r_fract_arr_[row].size(); k+=1) {
      cout << r_fract_arr_[row][k];// << endl;
      OutputPath(r_fract_arr_[row][k]);
      cout << " " << r_fract_arr_[row][k].inverted << endl;
   }
   
   cout << endl << "n: " << row + 1 << endl;
   cout << "size: " << r_fract_arr_[row].size() << endl;// << endl;
   cout << endl << "--------------" << endl << endl;
   
   
      vector<int>::iterator it;
      // Finding the largest element
      it = max_element(resistance_array_[row].begin(), resistance_array_[row].end());
      cout << "max: " << *it << endl << endl << "--------------" << endl << endl;
      //   auto index = std::distance(resistance_array_[row].begin(), it);
      //   cout << index << endl << endl;
*/
}

//void Resistance::RemoveDuplicates(int row) {
//   for (int j = 1; j < r_fract_arr_[row].size(); j+=1) {
//      for (int k = 0; k < j; k+=1) {
//         if (r_fract_arr_[row][j] == r_fract_arr_[row][k]) {
//            
//            r_fract_arr_[row].erase(r_fract_arr_[row].begin() + j);
//            j-=1;
//            
//         }
//      }
//   }
//}
