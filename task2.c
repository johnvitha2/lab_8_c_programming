/*
* EECS 348 Lab 5 Task 2
* Performs temperature conversions between Fahrenheit, Celsius, and Kelvin. Categorize the temperature into predefined ranges based on 
* its value and provide a weather advisory.
* Input: Temperature (double), scale (char), scale to convert to (char)
* Output: New temperature, temperature category, advisory
* Collaborators: None
* Sources: None
* Author: John Vitha
* KU ID: 3158626
* Creation date: 10/21/2025
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool is_valid_scale(char scale){
    scale = toupper(scale);
    return scale == 'C' || scale == 'F' || scale == 'K';
}

int main(){
    double temp;

    char scale;
    char scale_to_convert;

    double c_temp;
    double f_temp;
    double k_temp;

    double new_temp;

    const char* category = "No categorization"; 
    const char *advisory = "No advisory available";

    while(1){
        printf("Enter the temperature value: ");
        if(scanf("%lf", &temp) == 1){
            break;
        } else {
            printf("Please enter a number.\n");
            while (getchar() != '\n');
        }
    }

    while(1){
        printf("Enter the original scale (C, F, K): ");
        scanf(" %c", &scale);
 
        printf("Enter the scale to convert to (C, F, K): ");
        scanf(" %c", &scale_to_convert);
        if(is_valid_scale(scale) && is_valid_scale(scale_to_convert)){
            break;
        } else {
            printf("Invalid temperature scales. Please try again.\n");
        }
    }

    if(toupper(scale) == 'C'){
        c_temp = temp;
        k_temp = temp + 273.15;
        f_temp = (9.0/5.0)*temp + 32.0;
    } else if(toupper(scale) == 'F'){
        f_temp = temp;
        k_temp = (5.0/9.0)*(temp-32)+273.15;
        c_temp = (5.0/9.0)*(temp-32);
    } else if(toupper(scale) == 'K'){
        k_temp = temp;
        c_temp = temp - 273.15;
        f_temp = (9.0/5.0)*(temp-273.15)+32.0;
    } 

    if(toupper(scale_to_convert) == 'C'){
        new_temp = c_temp;
    } else if(toupper(scale_to_convert) == 'F'){
        new_temp = f_temp;
    } else if(toupper(scale_to_convert) == 'K'){
        new_temp = k_temp;
    } 

    if (c_temp < 0){
        category = "Freezing";
        advisory = "Wear a hat and gloves";
    } else if (c_temp >= 0 && c_temp < 10){
        category= "Cold";
        advisory = "Wear a jacket";
    } else if (c_temp >= 10 && c_temp < 25){
        category = "Comfortable";
        advisory = "No advisory at this time";
    } else if (c_temp >= 25 && c_temp < 35){
        category= "Hot";
        advisory = "Wear short sleeves and drink water";
    } else if(c_temp >= 35){
        category = "Extreme Heat";
        advisory = "Stay indoors";
    }

    printf("Converted temperature: %.2lf %c\nTemperature category: %s\nWeather advisory: %s", new_temp, scale_to_convert, category, advisory);
    return 0;
}
    




