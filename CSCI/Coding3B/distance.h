/*
 * Name        : distance.h
 * Author      : Luke Sathrum / Vince Rothenberg
 * Description : Distance Header file declarations
 * Sources     : CSCI 020
 */

// Opening Header Guards
#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
using std::cout;
using std::endl;

/*
 * Class Distance
 * A class that converts distances. It will always internally store in meters.
 */
class Distance {
 public:
  /*
   * Constructor #1
   * Sets meters_ to 0
   */
  Distance();

  /*
   * Constructor #2
   * Sets meters_ to the supplied value
   * HINT: You may just want to call the set_meters() mutator function.
   * @param double meters - The value to set the internal meters_ to. If the
   *                        distance is negative, set to 0.
   */
  Distance(double meters);

  /*
   * Constructor #3.
   * Converts the supplied distance to meters and internally stores it.
   * The distance's unit will be provided in the second parameter.
   * If the second parameter is not valid (i.e. not 'K', 'C', etc) assume the
   * distance is in meters.
   * HINT: You may want to just call the SetDistance() Function
   * @param double length - The value to set the internal meters_ to once
   *                        converted. If the distance is negative, set to 0.
   * @param char unit - The type of unit length is. Will be one of the following
   *                    case-insensitive:
   *                    'E' - Meters
   *                    'K' - Kilometers
   *                    'C' - Centimeters
   *                    'M' - Miles
   *                    'F' - Feet
   *                    'I' - Inches
   *                    'A' - Fathoms
   */
  Distance(double length, char unit);

  /*
   * Mutator
   * The distance will come in as meters and this function will set the
   * internal length to this value
   * @param double meters - The value to set the internal meters_ to. If the
   *                        distance is negative, set to 0.
   */
  void set_meters(double meters);

  /*
   * Accessor
   * Gets the internal distance in Meters.
   * @return double - The distance in Meters.
   */
  double meters();

  /*
   * Converts the supplied distance to meters and internally stores it.
   * The distance's unit will be provided in the second parameter.
   * If the second parameter is not valid (i.e. not 'K', 'C', etc) assume the
   * distance is in meters.
   * @param double length - The value to set the internal meters_ to once
   *                        converted. If the distance is negative, set to 0.
   * @param char unit - The type of unit length is. Will be one of the following
   *                    case-insensitive:
   *                    'E' - Meters
   *                    'K' - Kilometers
   *                    'C' - Centimeters
   *                    'M' - Miles
   *                    'F' - Feet
   *                    'I' - Inches
   *                    'A' - Fathoms
   */
  void SetDistance(double length, char unit);

  /*
   * Returns the internal distance converted based on the unit specified.
   * For example if the unit is 'K' it will convert meters -> kilometers and
   * return that value.
   * The distance's unit will be provided in the first parameter.
   * If the second parameter is not valid (i.e. not 'K', 'C', etc) assume they
   * want the distance in meters.
   * HINT: You may want to call the GetDistance() Function for the conversion
   * @param char unit - The type of unit length is. Will be one of the following
   *                    case-insensitive:
   *                    'E' - Meters
   *                    'K' - Kilometers
   *                    'C' - Centimeters
   *                    'M' - Miles
   *                    'F' - Feet
   *                    'I' - Inches
   *                    'A' - Fathoms
   * @return double - The converted distance.
   */
  double GetDistance(char unit);

  /*
   * Outputs a representation of the distance.
   * NOTE: There is NO newline character at the end of output.
   * The output will be formatted as:
   * "DISTANCE UNIT"
   * where DISTANCE is the distance to 2 decimal places and UNIT is one of the
   * following: "Meters", "Kilometers", "Centimeters", "Miles", "Feet",
   *            "Inches", or "Fathoms".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, output: "Invalid Unit"
   * @param char unit - The conversion to perform. Will be one of the following
   *                    case-insensitive:
   *                    'E' - Meters
   *                    'K' - Kilometers
   *                    'C' - Centimeters
   *                    'M' - Miles
   *                    'F' - Feet
   *                    'I' - Inches
   *                    'A' - Fathoms
   */
  void Output(char unit = 'E');

 private:
  double meters_;
};


// Closing Header Guards
#endif /* DISTANCE_H */
