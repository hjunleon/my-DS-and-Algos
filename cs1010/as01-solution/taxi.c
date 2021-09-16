/**
 * CS1010 Semester 1 AY18/19
 * Assignment 1: Taxi
 *
 * Read in four positive integer corresponding to the day of the week,
 * the hour and minute of boarding, and the distance travelled.  Print
 * to the standard output, the fare of the taxi.
 * height, and length of a box from the standard input, and
 * print the total surface area and the length of the diagonal
 * to the standard output.
 *
 * @file: taxi.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"
#include <stdbool.h>

/**
 * Check if a given day is a week day.
 *
 * @param[in] day The day of the week (1 for Monday, 7 for Sunday).
 * @return true if day is a weekday, false otherwise.
 */
bool is_weekday(long day) 
{
    return (day >= 1 && day <= 5);
}

/**
 * Check if a given time falls under morning peak hour (6am to 9:29am)
 *
 * @param[in] hour The given hour.
 * @param[in] minute The given minute.
 * @return true if the given time falls under morning peak hour.  
 *         false otherwise.
 */
bool is_morning_peak(long hour, long minute) 
{
    return (hour >= 6 && hour < 9) || (hour == 9 && minute <= 29);
}

/**
 * Check if a given time falls under evening peak hour (6pm to 11:59pm).
 *
 * @param[in] hour The given hour.
 * @return true if the given time falls under morning peak hour.  
 *         false otherwise.
 */
bool is_evening_peak(long hour) 
{
    return (hour >= 18 && hour <= 23);
}

/**
 * Check if a given time falls under midnight peak hour (0:00 to 5:59am).
 *
 * @param[in] hour The given hour.
 * @return true if the given time falls under midnight peak hour.  
 *         false otherwise.
 */
bool is_midnight_peak(long hour) 
{
    return (hour >= 0 && hour < 6);
}

/**
 * Check if surchange should be applied given day and time.
 *
 * @param[in] day Day of the taxi trip
 * @param[in] hour Hour of boarding time.
 * @param[in] minute Minute of boarding time
 * @return The surchage applied (1.0 if no surcharge)).
 */
double surcharge(long day, long hour, long minute) {
    if (is_weekday(day) && is_morning_peak(hour, minute)) {
        return 1.25;
    } 
    if (is_evening_peak(hour)) {
        return 1.25;
    } 
    if (is_midnight_peak(hour)) {
        return 1.5;
    } 
    return 1.0;
}

/**
 * Calculate the metered fare for a taxi trip (before surcharge).
 *
 * @param[in] distance The distance travelled.
 */
double metered_fare(long distance)
{
    double fare = 3.70;

    // The first 1 km or less
    if (distance <= 1000) {
        return fare;
    }

    distance -= 1000;
    if (distance <= 9000) {
        fare += 0.22 * (distance / 400);
        if (distance % 400 > 0) {
            fare += 0.22;
        }
        return fare;
    } 
    // more than 10km
    // 0.22 * ceil(9000 / 400) = 0.22*23 = 5.06
    fare += 5.06;

    distance -= 9000;
    fare += 0.22 * (distance / 350);
    if (distance % 350 > 0) {
        fare += 0.22;
    }

    return fare;
}

/**
 * Calculate the fare for a taxi trip (including surcharge).
 *
 * @param[in] day Day of the taxi trip
 * @param[in] hour Hour of boarding time
 * @param[in] minute Minute of boarding time
 * @param[in] distance The distance travelled
 */
double fare(long day, long hour, long minute, long distance)
{
    return metered_fare(distance) * surcharge(day, hour, minute);
}


int main()
{
    long day = cs1010_read_long();
    long start_hour = cs1010_read_long();
    long start_minute = cs1010_read_long();
    long distance = cs1010_read_long();

    cs1010_println_double(fare(day, start_hour, start_minute, distance));
}
