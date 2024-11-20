#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include <stdio.h>
#include "weather.h"

int hist_temp_min(WeatherTable a);
/*Returns the minimun historical temperature.*/

void max_temp_of_year(WeatherTable a, int output[YEARS]);
/*Calculates the maximun temperature of every year.*/

void max_rainfall_mounth(WeatherTable a, month_t outpout[YEARS]);
/*Shows the mounth of every year with the maximun monthly rainfall.*/

#endif