#include <stdio.h>
#include <string.h>

int main() {
    char num[12], *countryName; // Use a string to store the phone number
    int code, tele[99];

    printf("Enter a 12-digit telephone number:\n");
    scanf("%s", num);

    // Ensure the input is exactly 12 digits
    if (strlen(num) != 12) {
        printf("Error: Please enter exactly 12 digits.\n");
        return 1; // error
    }

    // country code
    code = (num[0] - '0') * 10 + (num[1] - '0');
    // 0 --> 48
    // 1 --> 49
    // 2 --> 50
    // 3 --> 51
    // therefore, 2 = '50' - '48'

    printf("Country code: %d\n", code);

    // Check for matching country code
    switch (code) {
        case 1: countryName = "United States"; break;
        case 91: countryName = "India"; break;
        case 44: countryName = "United Kingdom"; break;
        case 81: countryName = "Japan"; break;
        case 49: countryName = "Germany"; break;
        case 33: countryName = "France"; break;
        case 39: countryName = "Italy"; break;
        case 86: countryName = "China"; break;
        case 61: countryName = "Australia"; break;
        case 7: countryName = "Russia"; break;
        case 55: countryName = "Brazil"; break;
        default: countryName = "Unknown Country"; break;
    }
    
    printf("The country the number is from: %s", countryName);

    return 0;
}