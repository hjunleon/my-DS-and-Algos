/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Pyramid
 *
 * Read in three positive integer corresponding to the width,
 * height, and length of a box from the standard input, and
 * print the total surface area and the length of the diagonal
 * to the standard output.
 *
 * @file: pyramid.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"
#include <math.h>

/**
 * Calculate the hypotenuse of a triangle.
 *
 * @param[in] base The base of the triangle.
 * @param[in] height The height of the tringle.
 * @return The hypotenuse of the triangle.
 */
double hypotenuse_of(double base, double height) 
{
  return sqrt((base * base) + (height * height));
}

/**
 * Calculate the area of a rectangle.
 *
 * @param[in] width The width of the rectangle.
 * @param[in] height The height of the rectangle.
 * @return The surface area of the rectangle.
 */
long area_of_rectangle(long width, long height) {
	return width * height;
}

/**
 * Calculate the area of a triangle.
 *
 * @param[in] a The side of the triangle.
 * @param[in] b The side of the triangle.
 * @param[in] c The side of the triangle.
 * @return The surface area of the triangle.
 */
double area_of_triangle(double a, double b, double c) {
	double s = (a / 2.0) + (b / 2.0) + (c / 2.0);
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double surface_area_of_pyramid(long w, long l, long h) {
  double base_diagonal = hypotenuse_of(w, l);
  double side = hypotenuse_of(h, base_diagonal / 2);
  return area_of_rectangle(w, l) + 2 * area_of_triangle(side, side, l) + 
    2 * area_of_triangle(side, side, w);
}

int main() 
{
  long width = cs1010_read_long();
  long length = cs1010_read_long();
  long height = cs1010_read_long();

  double surface_area = surface_area_of_pyramid(width, length, height);
  cs1010_println_double(surface_area);
}
