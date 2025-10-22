#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50

void printMainMenu();
void cityManagement();
void distanceManagement();
void addNewCity();
void removeCity();
void renameCity();
void inputDistanceBetweenCities();
void displayDistanceTable();
void vehicleManagement();
void calculations(int index);
void generateReport();


int main()
{
   int choice;
   while(1){
    printMainMenu();
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
case 1:
    cityManagement();
    break;
case 2:
    distanceManagement();
    break;
case 3:
    vehicleManagement();
    break;
case 4:
    generateReport();
    break;
case 5:
    printf("Exiting Program!!!\n");
    break;
default:
    printf("Invalid choice...Try a valid choice!!!");
    }
   }
    return 0;
}

void printMainMenu(){
printf("\n==== Logistics Management System ====\n");
printf("1.City Management\n");
printf("2.Distance Management\n");
printf("3.Delivery Management\n");
printf("4.Performance Reports\n");
printf("5.Exit\n");

}
