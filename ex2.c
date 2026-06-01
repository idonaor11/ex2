/******************
Name: ido naor

Assignment: ex2
*******************/


#include <stdio.h>
// Dividing a number by 10 removes its rightmost digit.
#define DIVISOR 10
//used for extracting a single digit from a number
#define GET_DIGIT_VALUE 10
//used if the number goes into an infinite loop
#define INFINITY_LOOP 4
//for the "Exit" option in the menu (option 7)
#define EXIT 7
//smallest positive number (1)
#define MIN_POS_NUM 1
//the smallest even number (2)
#define MIN_EVEN 2
// Defines the constant used for the middle position
#define MID_NUM 2
// Defines the constant for "True" as 2, used in specific conditions in the program
#define TRUE 2
//starting value for checking if a number is prime (used as the starting divisor)
#define START_PRIME_CHECK 2


int main() {
    int choice = 0;
    do {
        //magic number//
        // Display the menu options
        printf("Choose an option:\n");
        printf("   1. Happy Face\n");
        printf("   2. Balanced Number\n");
        printf("   3. Generous Number\n");
        printf("   4. Circle Of Joy\n");
        printf("   5. Happy Numbers\n");
        printf("   6. Festival Of Laughter\n");
        printf("   7. Exit\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Prints a happy face with user-defined eyes, nose, and mouth symbols and a face size.
                char eyes, nose, mouth;
                int faceSize;
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyes, &nose, &mouth);
                printf("Enter face size:\n");
                scanf("%d", &faceSize);
                // Validate that the face size is a positive, odd number
                while ((faceSize < MIN_POS_NUM) || (faceSize % MIN_EVEN) == 0) {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%d", &faceSize);
                }
                // print the eyes
                printf("%c ", eyes);
                for (int i = MIN_POS_NUM; i <= faceSize; i++) {
                    printf(" ");
                }
                printf("%c\n", eyes);
                for (int i = MIN_POS_NUM; i <= ((faceSize / MID_NUM) + MIN_POS_NUM); i++) {
                    printf(" ");
                }
                //print the nose
                printf("%c\n", nose);
                //print the mouth
                printf("\\");
                for (int i = MIN_POS_NUM; i <= faceSize; i++) {
                    printf("%c", mouth);
                }
                printf("/\n");
                break;
            }
            case 2: {
                // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
                // and the sum of all digits to the right of the middle digit(s) are equal
                // Checks if the sum of digits on the left side of the middle digit(s) is equal to the sum on the right side
                // Example: Balanced: 1533, 450810, 99; Not balanced: 1552, 34
                int num = 0, numDigits = 0, equal = 0, mid=0, rightSum=0, leftSum=0;
                printf("Enter a number:\n");
                scanf(" %d", &num);
                while (num < MIN_POS_NUM) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &num);
                }
                equal = num;
                //Calculates how many digits a number has
                while (equal > 0) {
                    // Count the number of digits in the number
                    numDigits++;
                    equal /= DIVISOR;
                }
                // Find the middle point
                mid = numDigits / MID_NUM;
                // Calculate the sum of digits to the left and right of the middle
                if (numDigits % MIN_EVEN == 0) {
                    for (int i = MIN_POS_NUM; i <= mid; i++) {
                        rightSum += num % GET_DIGIT_VALUE;
                        num = num / DIVISOR;
                    }
                    for (int i = MIN_POS_NUM; i <= mid; i++) {
                        leftSum += num % GET_DIGIT_VALUE;
                        num = num / DIVISOR;
                    }
                } else {
                    for (int i = MIN_POS_NUM; i <= mid; i++) {
                        rightSum += num % GET_DIGIT_VALUE;
                        num = num / DIVISOR;
                    }
                    // Skip the middle digit
                    num = num / DIVISOR;
                    for (int i = MIN_POS_NUM; i <= mid; i++) {
                        leftSum += num % GET_DIGIT_VALUE;
                        num = num / DIVISOR;
                    }
                }
                // Check if the number is balanced
                if (leftSum == rightSum)
                    printf("This number is balanced and brings harmony!\n");
                else
                    printf("This number isn't balanced and destroys harmony.\n");

                break;
            }
            case 3: {
                // Case 3: Check if a number is "generous", meaning the sum of its divisors is greater than the number itself
                int num1 = 0, sum = 0;
                printf("Enter a number:\n");
                scanf(" %d", &num1);
                while (num1 < MIN_POS_NUM) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &num1);
                }
                // Find the sum of divisors of the number
                for (int i = MIN_POS_NUM; i <= num1 / MID_NUM; i++) {
                    if (num1 % i == 0)
                        sum += i;
                }
                // Check if the number is generous
                if (sum > num1)
                    printf("This number is generous!\n");
                else
                    printf("This number does not share.\n");
                break;
            }
            case 4: {
                // Checks if the reversed number is prime, if so it completes the Circle of Joy.
                // A prime number is one that is divisible only by 1 and itself.
                int num2 = 0, sum1 = 0, num4 = 0, reversedNum = 0, rest = 0;
                printf("Enter a number:\n");
                scanf(" %d", &num2);
                while (num2 < MIN_POS_NUM) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &num2);
                }
                if (num2 == MIN_POS_NUM) {
                    printf("The circle remains incomplete.\n");
                    break;
                }
                num4 = num2;
                // Reverse the number
                while (num4 != 0) {
                    rest = num4 % GET_DIGIT_VALUE;
                    reversedNum = reversedNum * DIVISOR + rest;
                    num4 = num4 / DIVISOR;
                }
                // Check if the reversed number is prime
                for (int i = START_PRIME_CHECK; i < reversedNum; i++) {
                    // If a divisor is found, it's not prime
                    if (reversedNum % i == 0)
                        sum1 += i;
                }
                // If the reversed number is prime
                if (sum1 >= MIN_POS_NUM)
                    printf("The circle remains incomplete.\n");
                else
                    printf("This number completes the circle of joy!\n");
                break;
            }
            case 5: {
                // Happy numbers: Print all the happy numbers between 1 to the given number.
                // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit

                int num2 = 0, sum2 = 0, num3 = 0, digit = 0;
                printf("Enter a number:\n");
                scanf(" %d", &num2);
                while (num2 < MIN_POS_NUM) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &num2);
                }
                printf("Between 1 and %d only these numbers bring happiness:", num2);
                for (int i = MIN_POS_NUM; i <= num2; i++) {
                    num3 = i;
                    // Identifies happy numbers by repeatedly replacing the number with the sum of the squares of its digits
                    // until it reaches 1 or enters a loop (infinity loop).
                    while (num3 != MIN_POS_NUM && num3 != INFINITY_LOOP) {
                        sum2 = 0;
                        while (num3 > 0) {
                            digit = num3 % GET_DIGIT_VALUE;
                            sum2 += digit * digit;
                            num3 /= DIVISOR;
                        }
                        num3 = sum2;
                    }
                    // If the number is happy, print it
                    if (num3 == MIN_POS_NUM) {
                        printf(" %d", i);
                    }
                }
                printf("\n");

                break;
            }
            case 6: {
                // Festival of Laughter: Prints all the numbers between 1 the given number:
                // and replace with "Smile!" every number that divided by the given smile number
                // and replace with "Cheer!" every number that divided by the given cheer number
                // and replace with "Festival!" every number that divided by both of them

                int smile = 0, cheer = 0, check = 0, max = 0;
                printf("Enter a smile and cheer number:\n");
                check = (scanf(" smile: %d, cheer: %d", &smile, &cheer));
                // Ensure that the input consists of two different positive numbers
                while (check != TRUE || smile < MIN_POS_NUM || cheer < MIN_POS_NUM) {
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    // Clear the input buffer
                    scanf("%*[^\n]");
                    check = (scanf(" smile: %d, cheer: %d", &smile, &cheer));
                }
                printf("Enter maximum number for the festival:\n");
                scanf("%d", &max);
                while (max < MIN_POS_NUM) {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf("%d", &max);
                }
                // Replaces numbers divisible by the 'smile' number with "Smile!",
                // numbers divisible by the 'cheer' number with "Cheer!",
                // and numbers divisible by both with "Festival!".
                for (int i = MIN_POS_NUM; i <= max; i++) {
                    if (i % smile == 0 && i % cheer == 0)
                        printf("Festival!\n");
                    else if (i % cheer == 0)
                        printf("Cheer!\n");
                    else if (i % smile == 0)
                        printf("Smile!\n");
                    else
                        printf("%i\n", i);
                }
                break;
            }
            case 7: {
                // Exit the program
                printf("Thank you for your journey through Numeria!\n");
                break;
            }
            default:
                printf("This option is not available, please try again.\n");
        }
    } // Continue the loop until the user chooses to exit
      while (choice != EXIT) ;
    return 0;
}
