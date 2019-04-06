/*
 * Name        : distance.cpp
 * Author      : Vince Rothenberg
 * Description : Implementation File for Distace Class
 */
// Include our .h file
#include "distance.h"

// Member Function Definitions

//Default constructor
//Sets meters_ to 0
Distance::Distance() {
  meters_ = 0;
}

//Constructor with supplied value
//Sets meters_ to input as meters
Distance::Distance(double meters) {
  set_meters(meters);
}

//Constructor with supplied value and unit
//Converts value to meters and assigns new value to meters_
Distance::Distance(double length, char unit) {
  SetDistance(length, unit);
}

//Default mutator
//Sets meters_ to supplied value if greater than 0
//Negative values are set to 0
void Distance::set_meters(double meters) {
  if (meters<0) {
    meters_ = 0;
  } else {
    meters_ = meters;
  }
}

//Default accessor
//Returns meters_ value as double
double Distance::meters() {
  return meters_;
}

//Mutator with supplied length and unit
//Converts various length to meters and assigns to meters_
void Distance::SetDistance(double length, char unit) {
  if (length<0) length = 0;
  switch(unit) {
    //Kilometers
    case 'K':
      meters_ = length * 1000;
      break;
    //Centimeters
    case 'C':
      meters_ = length / 100;
      break;
    //Miles
    case 'M':
      meters_ = length * 1609.34;
      break;
    //Feet
    case 'F':
      meters_ = length * 0.3048;
      break;
    //Inches
    case 'I':
      meters_ = length * 0.0254;
      break;
    //Fathoms
    case 'A':
      meters_ = length * 1.8288;
      break;
    //If not recognized unit, default meters for units
    default:
      meters_ = length;
      break;
  };
}

//Accessor with supplied unit
//Converts meters_ to unit supplied and returns value as double

double Distance::GetDistance(char unit) {
  switch(unit) {
    //Kilometers
    case 'K':
      return meters_ / 1000;
    //Centimeters
    case 'C':
      return meters_ * 100;
    //Miles
    case 'M':
      return meters_ * 0.000621371;
    //Feet
    case 'F':
      return meters_ * 3.28084;
    //Inches
    case 'I':
      return meters_ * 39.3701;
    //Fathoms
    case 'A':
      return meters_ * 0.546807;
    //If not recognized unit return meters
    default:
      return meters_;
  };
}

//Outputs distance in units with 2 decimal places
//Encapsulates GetDistance(unit)

void Distance::Output(char unit) {
  switch(unit) {
    case 'K':
      printf("%.2f ", GetDistance(unit));
      cout << "Kilometers";
      break;
    case 'C':
      printf("%.2f ", GetDistance(unit));
      cout << "Centimeters";
      break;
    case 'M':
      printf("%.2f ", GetDistance(unit));
      cout << "Miles";
      break;
    case 'F':
      printf("%.2f ", GetDistance(unit));
      cout << "Feet";
      break;
    case 'I':
      printf("%.2f ", GetDistance(unit));
      cout << "Inches";
      break;
    case 'A':
      printf("%.2f ", GetDistance(unit));
      cout << "Fathoms";
      break;
    default:
      cout << "Invalid Unit";
      break;
  };
}
