//
//  body-mass-index-lab.c
//  body-mass-index-lab
//
//  Created by Shana Moore on 9/26/17.
//  Copyright © 2017 Shana Moore. All rights reserved.
/*  Construct a C program which includes a function, calculateBMI(), that prompts the user to input a weight, in pounds, and height, in inchese, and then calculates and displays the body mass index and classification. */

#include <stdio.h>
FILE *fp;

int calculateBMI(void); // function prototype

int main(void) {
    // Declare variables with appropriate data types
    int i = 0;
    
    fp = NULL;
    
    // Open file and call function, that will output to file
    fp = fopen("csis.txt", "w");
    for (i = 1; i <= 4; ++i){
        calculateBMI();
    }
    
    // Close file
    fclose(fp);
    return 0;
}

int calculateBMI(void){
    // Declare variables with appropriate data types
    double BMI = 0, weightInPounds = 0, heightInInches = 0;

    // Get height and weight from user
    printf("Enter your weight (in pounds): ");
    scanf("%lf", &weightInPounds);
    
    printf("Enter your height (in inches): ");
    scanf("%lf", &heightInInches);

    // Compute BMI per user's input
    BMI = (weightInPounds * 703) / (heightInInches * heightInInches);
    
    // Display output of user's BMI value and classification and output to file
    if(BMI >= 30.0){
        printf("Your BMI is %.1f and you are obese.\n", BMI);
        fprintf(fp, "Your BMI is %.1f and you are obese.\n", BMI);
    }
    else if (BMI >= 25.0){
        printf("Your BMI is %.1f and you are overweight.\n", BMI);
        fprintf(fp, "Your BMI is %.1f and you are overweight.\n", BMI);
    }
    else if (BMI >= 18.5){
        printf("Your BMI is %.1f and you are normal.\n", BMI);
        fprintf(fp, "Your BMI is %.1f and you are normal.\n", BMI);
    }
    else {
        printf("Your BMI is %.1f and you are underweight.\n", BMI);
        fprintf(fp, "Your BMI is %.1f and you are underweight.\n", BMI);
    }
    return 0;
}
