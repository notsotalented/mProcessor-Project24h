/*
    NguyenQuocAnh-1852238
    Programmed & Compiled on Online C Compiler
    https://www.onlinegdb.com/online_c_compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Conversion function - the focus point
const char* suffixWithUnit(double number) {
    //INIT buffer
    static char buf[128];
    //INIT suffix table
    char suffix[8][10] = {" Kilo"," Mega"," Giga", " Tera", " Peta", " Exa", " Zetta", " Yotta"};
    //Intermediate to calculate number of power 10^unit = number
    double numberdiv = number;
    int unit = 0;
    while (numberdiv > 999) {
        numberdiv/=1000;
        unit++;
    }
    //Add suffix
    if (unit > 0) {
        if (unit < 9) {
            //Double to char array, %g copy without trailing zeros
            sprintf(buf, "%g", numberdiv);
            //Add suffix
            strncat(buf, suffix[unit - 1], 10);
        }
        else {
            //find 10^x 'tenx'
            int tenx = 0;
            double numberdiv10 = numberdiv;
            while (numberdiv10 > 9) {
            numberdiv10/=10;
            tenx++;
            }
            tenx+=unit*3;
            //Double to char array, %g copy without trailing zeros
            sprintf(buf, "%g", numberdiv10);
            //Add 'e+tenx'
            char esuffix[10];
            sprintf(esuffix, "%d", tenx - 24);
            strncat(buf, "e+", 3);
            strncat(buf, esuffix, 10);
            //Add suffix
            strncat(buf, suffix[7], 10);
        }
    }
    else {
        //Double to char array, %g copy without trailing zeros
        sprintf(buf, "%g", numberdiv);
    }
    return buf;
}

//Main function for testing
int main()
{
    //INIT number here
    double number = 100e24;
    //Print result
    printf("INPUT : %g\n",number);
    printf("RESULT: ");
    puts(suffixWithUnit(number));
    return 0;
}