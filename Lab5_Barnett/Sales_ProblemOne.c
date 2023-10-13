//Read from file and seperate each line into 12 seperate numbers in an array
//Create a matching array of the months
//Use a counter for all methods, so If I need the 6th number and month I can find both from each array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 128 
#define RSIZ 10 

int main(void) 
{
    char line[RSIZ][LSIZ];
    float numbers[] = {};
	char fname[20];
    char months[12][50] = {"Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    FILE *fptr = NULL; 
    int i = 0;
	//printf(" Input the filename to be opened : ");
	//scanf("%s",fname);	

    fptr = fopen("sales", "r");
    while(fgets(line[i], LSIZ, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
	printf("\n Monthly sales report for 2023:");   
    printf("\n Month\tSales"); 
    for(i = 0; i < 12; ++i)
    {
        printf("\n%s", months[i]);
        printf("\t%s", line[i]);
    }
   
    for(i = 0; i < 12; ++i)
    {
        float float_value = atof(line[i]);
        numbers[i] = float_value;
    }
    char monthz[12][50] = {"Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    i = 0;
    int mond = 0;
    double min = numbers[0];
    for(i = 0; i < 12; ++i){
        if (numbers[i] < min){
            min = numbers[i];
            mond = i;

        }
    }
    double max = numbers[0];
    for(i = 0; i < 12; ++i){
        if (numbers[i] > max){
            max = numbers[i];
            mond = i;

        }
    }
    double avg = 0;
    double sum = 0;
    for(i = 0; i < 12; ++i){
        sum += numbers[i];
       

        }
    avg = sum/12;
    printf("\n");
    printf("\nSales summary: ");
    printf("\n");
    printf("\nMinimum sales: $%.2f (%s)", min, monthz[mond]);
    printf("\nMaximum sales: $%.2f (%s)", max, monthz[mond]);
    printf("\nAverage sales: $%.2f", avg);

    double avg1 = 0;
    for(i = 0; i < 6; ++i){
    avg1 += numbers[i];
    

    }
    avg1 = avg1/6; 
    double avg2 = 0;
    for(i = 1; i < 7; ++i){
    avg2 += numbers[i];
    

    }
    avg2 = avg2/6; 
    double avg3 = 0;
    for(i = 2; i < 8; ++i){
    avg3 += numbers[i];
    

    }
    avg3 = avg3/6; 
    double avg4 = 0;
    for(i = 3; i < 9; ++i){
    avg4 += numbers[i];
    

    }
    avg4 = avg4/6; 
    double avg5 = 0;
    for(i = 4; i < 10; ++i){
    avg5 += numbers[i];
    

    }
    avg5 = avg5/6; 
    double avg6 = 0;
    for(i = 5; i < 11; ++i){
    avg6 += numbers[i];
    

    }
    avg6 = avg6/6; 
    double avg7 = 0;
    for(i = 6; i < 12; ++i){
    avg7 += numbers[i];
    

    }
    avg7 = avg7/6; 
    printf("\n");
    printf("\n Six-Month Moving Average Report:");
    printf("\n January - June    $%.2f", avg1);
    printf("\n Febuary - July    $%.2f", avg2);
    printf("\n March - August    $%.2f", avg3);
    printf("\n April - September    $%.2f", avg4);
    printf("\n May - October    $%.2f", avg5);
    printf("\n June - November    $%.2f", avg6);
    printf("\n July - December    $%.2f", avg7);
    printf("\n");
    double temp = 0;
    int monda;
    int j;
    printf("\n Sales Report(Highest to Lowest): ");
    printf("\nMonth\tSales");
    for (i = 0; i < 12; i++){
        temp = 0;
        monda = 0;
        for (j = 0; j < 12; j++){
            if (numbers[j] > temp){
                monda = j;
                temp = numbers[j];
            }
        }
        printf("\n %s  %.2f", monthz[monda], temp);
        numbers[monda] = 0;
    }
    printf("\n");
   return 0;
}