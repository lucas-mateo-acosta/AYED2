#include <stdio.h>
#include "array_helpers.h"
#include "weather_utils.h"

int hist_temp_min(WeatherTable a){
    int temp = a[0][0][0]._min_temp;

    for (unsigned int year=0u; year<YEARS; year++){
        for (unsigned int month=0u; month<MONTHS; month++){
            for(unsigned int day=0u; day<DAYS; day++){
                if (a[year][month][day]._min_temp<=temp){
                    temp = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return temp;
}

void max_temp_of_year(WeatherTable a, int output[YEARS]){
    int temp = a[0][0][0]._max_temp;

    for (unsigned int year=0u; year<YEARS; year++){
        for (unsigned int month=0u; month<MONTHS; month++){
            for(unsigned int day=0u; day<DAYS; day++){
                if (a[year][month][day]._max_temp>=temp){
                    temp = a[year][month][day]._max_temp;
                }
            }
        }
        output[year+FST_YEAR] = temp;
    }    
}

void max_rainfall_mounth(WeatherTable a, month_t outpout[YEARS]){
    unsigned int prec = 0u;
    unsigned int max_prec = 0u;
    month_t max_month = january;
    unsigned int b[MONTHS];

    for (unsigned int year=0u; year<YEARS; year++){
        for (month_t month=january; month<=december; month++){
            for(unsigned int day=0u; day<DAYS; day++){
                prec = prec + a[year][month][day]._rainfall;
            }
            b[month] = prec;
        }
        for (month_t month=january; month<=december; month++){
            if (max_prec<=b[month]){
                max_prec = b[month];
                max_month = month;
            }
        }
        outpout[year+FST_YEAR] = max_month;
    }
}