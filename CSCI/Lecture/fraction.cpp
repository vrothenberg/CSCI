/*
 * Name        : fraction.cpp
 * Author      : Luke Sathrum / Vince Rothenberg / Andrew Gutierrez
 * Description : Main file for Lab #12
 */

#include <iostream>
using std::cout;
using std::endl;

class Fraction {
 public:
  /*
   * Construcor
   * Assigns numerator parameter to numerator_ and
   * assigns denominator parameter to denominator_
   */
  Fraction(int numerator, int denominator);

  /*
   * Mutator for numerator_
   * Assigns the numerator parameter to numerator_
   */
  void set_numerator(int numerator);

  /*
   * Mutator for denominator_
   * Assigns the denominator parameter to denominator_
   */
  void set_denominator(int denominator);

  /*
   * Returns a double representation of the fraction, i.e num / denom.
   * Watch out for integer division!
   */
  double GetFraction();

  /*
   * Outputs the fraction as a fraction, i.e. "num/denom".
   */
  void Output();

  /*
   * Outputs the fraction as a reduced fraction, i.e. 20/60 -> 1/3.
   * Need to use the GCD function to get the reduced fraction.
   */
  void OutputReduced();
 private:
  int numerator_;
  int denominator_;

  /*
   * Calcualtes the GCD. Use the pseudocode provided in the instructions
   */
  int GCD(int small, int large);
};

int main() {
  Fraction my_fraction(3, 33);
  my_fraction.Output();
  my_fraction.OutputReduced();
  cout << "In decimal form: " << my_fraction.GetFraction() << endl;
  my_fraction.set_numerator(33);
  my_fraction.set_denominator(3);
  my_fraction.Output();
  my_fraction.OutputReduced();
  cout << "In decimal form: " << my_fraction.GetFraction() << endl;

  return 0;
}

// Write Function Definitions Here

Fraction::Fraction(int numerator, int denominator) {
  numerator_ = numerator;
  denominator_ = denominator;
}

/*
 * Mutator for numerator_
 * Assigns the numerator parameter to numerator_
 */
void Fraction::set_numerator(int numerator) {
  numerator_ = numerator;
}

/*
 * Mutator for denominator_
 * Assigns the denominator parameter to denominator_
 */
void Fraction::set_denominator(int denominator) {
  denominator_ = denominator;
}

/*
 * Returns a double representation of the fraction, i.e num / denom.
 * Watch out for integer division!
 */
double Fraction::GetFraction() {
  return numerator_ / (denominator_ + 0.0);
}

/*
 * Outputs the fraction as a fraction, i.e. "num/denom".
 */
void Fraction::Output() {
  cout << numerator_ << "/" << denominator_ << endl;
}

/*
 * Outputs the fraction as a reduced fraction, i.e. 20/60 -> 1/3.
 * Need to use the GCD function to get the reduced fraction.
 */
void Fraction::OutputReduced() {
  int gcd = GCD(numerator_, denominator_);
  cout << numerator_/gcd << "/" << denominator_/gcd << endl;
}

int Fraction::GCD(int small, int large) {
  int temp;
  if (large < small) {
    temp = small;
    small = large;
    large = temp;
  }
  while (large != 0) {
    temp = small % large;
    small = large;
    large = temp;
  }
  return small;
}
