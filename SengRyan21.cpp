#include <iostream>
#define PI 3.1415926
using namespace std;

/**
 * Program has a base class named Circle with data members and functions related to circles and a derived class named Cylinder with data members and functions related to cylinders.
 *
 * @author Seng, Ryan
 * @assignment ICS 212 Assignment 21
 * @date 06 December 2022
 */

/**
 * Circle ADT.
 * Base class for Cylinder class.
 * Stores the radius and calculates the area of a circle.
 */
class Circle {

public:
  /**
   * Default constructor. Sets radius of circle to 1.
   */
  Circle() {
    setRadius(1);
  }

  /**
   * Overloaded constructor.
   * Sets radius of circle to desired value.
   *
   * @param newRadius Value of radius passed in.
   */
  Circle(double newRadius) {
    setRadius(newRadius);
  }

  /**
   * Accessor function.
   * Returns the radius of the circle. Does not change any values.
   * 
   * @return radius The radius of the circle.
   */
  double getRadius() const {
    return radius;
  }

  /**
   * Mutator function.
   * Sets the radius of the circle according to the desired value.
   * 
   * @param newRadius The specified value for the radius.
   */
  void setRadius(double newRadius) {
    // Error checking of the newRadius in order to create a proper circle with positive natural values.
    if (newRadius < 0) {
      radius = -newRadius;
    }
    else if (newRadius == 0) {
      radius = 1;
    }
    else {
      radius = newRadius;
    }
  }

  /**
   * Member function: area.
   * Calculates and returns the area of the circle.
   *
   * @return area the area of the circle.
   */
  double area() const {
    return PI * radius * radius;
  }

protected: 
  // Attributes of a circle.
  double radius;
};

/**
 * Cylinder ADT.
 * Derived from Circle class.
 * A cylinder is a circle with a height.
 */
class Cylinder: public Circle {
public:
  /**
   * Specified Constructor.
   * Creates a cylinder with a radius using functions from the Circle ADT and adds a height.
   */
  Cylinder(double newRadius, double newHeight){
    Circle::setRadius(newRadius);
    setHeight(newHeight);
  }

  /** 
   * Accessor function.
   * Retrieves the value of the height of the cylinder. Does not change value.
   *
   * @return height The height of the cylinder.
   */
  double getHeight() const {
    return height;
  } 

  /**
   * Mutator function.
   * Sets the height value for the cylinder.
   *
   * @param newHeight Specified height to be added in.
   */
  void setHeight(double newHeight) {
    // Error checking.
    if (newHeight < 0) {
      height = -newHeight;
    }
    else if (newHeight == 0) {
      height = 1;
    }
    else {
      height = newHeight;
    }
  }

  /**
   * Member function: area.
   * Calculates and returns the area of the cylinder.
   *
   * @return area The area of the cylinder.
   */
  double area() const {
    return 2 * PI * radius * height + 2 * PI * radius * radius;
  }

  /**
   * Member function: volume
   * Calculates and returns the volume of the cylinder.
   *
   * @return volume The volume of the cylinder.
   */
  double volume() const {
    return PI*radius*radius*height;
  }

private:
  // Attributes of a cylinder.
  double height;
};

/**
 * Main function given by the professor.
 */
int main() {

  // Test the default constructor.
  // The radius should be 1.
  cout << "Test Circle class default constructor and area() function:" << endl;
  Circle circle1;
  
  // With radius 1, the expected output is:
  // Circle circle1: radius = 1
  // area = 3.14159
  cout << "Circle circle1: radius = " << circle1.getRadius() << endl;
  cout << "area = " << circle1.area() << endl;
  
  cout << "\n";
  
  // Test the overloaded constructor that makes a circle given a radius.
  // Attempt to create a circle with an invalid, negative radius.
  // The constructor should make it positive instead -10 --> 10
  cout << "Test Circle class constructor with radius (-10):" << endl;
  Circle circle2(-10);
  
  // With the radius changed to positive 10, the expected output is:
  // Test Circle class constructor with radius:
  // Circle circle2: radius = 10
  cout << "Circle circle2: radius = " << circle2.getRadius() << endl;
  
  // Further test that the class compensates for invalid radius.
  // Attempt to modify the circle with a negative radius.
  // Again, it should change -5 to positive 5.
  cout << "Test set method, set circle2 to radius -5..." << endl;
  circle2.setRadius(-5);
  // Expected output:
  // radius = 5
  // area = 78.5398
  cout << "radius = " << circle2.getRadius() << endl;
  cout << "area = " << circle2.area() << endl;
  
  cout << "\n";
  
  // For Cylinder, there is no default constructor, only a
  // constructor that takes in a given radius and height.
  // The same error corrections found in Circle should be
  // implemented in the Cylinder class as well.
  // The -30 height should be changed to positive 30.
  cout << "Test Cylinder class given radius (20) and height (-30):" << endl;
  Cylinder cylinder1(20, -30);
  
  // Expected output:
  // Cylinder cylinder1: radius = 20; height = 30
  // surface area = 6283.19
  // volume = 37699.1
  cout << "Cylinder cylinder1: radius = " << cylinder1.getRadius();
  cout << "; height = " << cylinder1.getHeight() << endl;
  cout << "surface area = " << cylinder1.area() << endl;
  cout << "volume = " << cylinder1.volume() << endl;
  
  cout << "\n";
  
  // Test error correction of the mutator methods.
  // The 0 should be changed to a 1.
  // Expected output:
  // Test set method, set cylinder1 to radius 0 and height 0...
  // radius = 1; height = 1
  // surface area = 12.5664
  // volume = 3.14159
  cout << "Test set method, set cylinder1 to radius (0) and height (0)..." << endl;
  cylinder1.setRadius(0);
  cylinder1.setHeight(0);
  cout << "radius = " << cylinder1.getRadius() << "; height = " << cylinder1.getHeight() << endl;
  cout << "surface area = " << cylinder1.area() << endl;
  cout << "volume = " << cylinder1.volume() << endl;

  return 0;
}

