/*
* EECS 348 Lab 5 Task 1
* Score Possibility Calculator
* Input: NFL score (int)
* Output: Possible scoring combinations
* Collaborators: None
* Sources: None
* Author: John Vitha
* KU ID: 3158626
* Creation date: 10/21/2025
*/

#include <stdio.h>

const int VALUES[] = {8, 7, 6, 3, 2};

int main(){
    int score;
    while(1){
        while(1){
            printf("Enter the NFL score (Enter 1 to stop): ");
            scanf("%d", &score);
            if(score < 0){
                printf("Invalid score. Please try again.\n");
            } else {
                break;
            }
        }

        if (score == 1){
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        for (int a = 0; a <= score/VALUES[0]; a++){
            int rem_a = score - a*VALUES[0];
            for (int b = 0; b <= rem_a/VALUES[1]; b++){
                    int rem_b = rem_a - b*VALUES[1];
                for (int c = 0; c <= rem_b/VALUES[2]; c++){
                    int rem_c = rem_b - c*VALUES[2];
                    for (int d = 0; d <= rem_c/VALUES[3]; d++){
                        int rem_d = rem_c - d*VALUES[3];
                        if (rem_d % 2 == 0){
                            int e = rem_d / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
}




