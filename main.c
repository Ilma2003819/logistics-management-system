#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define MAX_VEHICLES 3


char cities[MAX_CITIES][50];
int cityCount = 0;

int distance[MAX_CITIES][MAX_CITIES]= {0};

char vehicleType[MAX_VEHICLES][20]= {"van","Truck","Lorry"};
int vehicleCapacity[MAX_VEHICLES]= {1000,5000,10000}; // kg
int vehicleRate[MAX_VEHICLES]= {30,40,80}; // LKR
int vehicleAvgSpeed[MAX_VEHICLES]= {60,50,45}; // km/h
int vehicleFualEfficiency[MAX_VEHICLES]= {12,6,4}; // km/l

int deliverySource[MAX_DELIVERIES];
int deliveryDestination[MAX_DELIVERIES];
int deliveryWeight[MAX_DELIVERIES];
int deliveryVehicleType[MAX_DELIVERIES];
double deliverCost[MAX_DELIVERIES];
double estimatedDeliveryTime[MAX_DELIVERIES];
double fuelUsed[MAX_DELIVERIES];
double fuelCost[MAX_DELIVERIES];
double totalOperationalCost[MAX_DELIVERIES];
double profit[MAX_DELIVERIES];
double customerCharge[MAX_DELIVERIES];
int deliveryCount=0;

void printMainMenu();
void cityManagement();
void distanceManagement();
void addNewCity();
void removeCity();
void renameCity();
void inputDistanceBetweenTwoCities();
void displayDistanceTable();
void vehicleManagement();
void calculations(int index);
void generateReport();


int main()
{
    int choice;
    while(1)
    {
        printMainMenu();
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
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

void printMainMenu()
{
    printf("\n==== Logistics Management System ====\n");
    printf("1.City Management\n");
    printf("2.Distance Management\n");
    printf("3.Delivery Management\n");
    printf("4.Performance Reports\n");
    printf("5.Exit\n");
}

void cityManagement()
{
    int choice;
    while(1)
    {
        printf("\n----City Management Menu----\n");
        printf("1.Add City\n");
        printf("2.Rename City\n");
        printf("3.Remove City\n");
        printf("4.Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addCity();
            break;
        case 2:
            renameCity();
            break;
        case 3:
            removeCity();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice!!!");
        }
    }
}

void distanceManagement()
{

    int choice;
    while(1)
    {
        printf("\n----Distance Management----\n");
        printf("1.Input distances between two cities\n");
        printf("2.Display distance table\n");
        printf("3.Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            inputDistanceBetweenTwoCities();
            break;
        case 2:
            displayDistanceTable();
            break;
        case 3:
            return;
        default:
            printf("Invalid choice!!\n");
        }
    }
}
void addNewCity()
{
    if(cityCount>=MAX_CITIES)
    {
        printf("Invalid input.Try 1 to 50\n");
        return;
    }
    printf("Enter City name: ");
    scanf("%[^\n]s",cities[cityCount]);
    cityCount++;
    printf("City added successfully!!\n");
}

void renameCity()
{
    if(cityCount==0)
    {
        printf("No cities to rename!!\n");
        return;
    }
    int cityIndex;
    printf("Enter city index to rename(0-%d):",cityCount-1);
    scanf("%d",&cityIndex);

    if(cityIndex<0 || cityIndex>=cityCount)
    {
        printf("Invalid index!!\n");
        return;
    }
    printf("Enter new city name: ");
    scanf("%[^\n]s",cities[cityIndex]);
    printf("City renamed successfully!!\n");
}

void removeCity()
{
    if(cityCount==0)
    {
        printf("No cities to remove!!\n");
    }
    int cityIndex;
    printf("Enter city index to remove(0-%d: ",cityCount-1);
    scand("%d",&cityIndex);

    if(cityIndex<0 || cityIndex>=cityCount)
    {
        printf("Invalid index!!\n");
        return;
    }
    for(int i=0; i<cityCount-1; i++)
    {
        strcpy(cities[i],cities[i+1]);
    }

    for(int i=0; i<MAX_CITIES; i++)
    {
        for(int j; cityIndex<cityCount-1; j++)
        {
            distance[i][j]=distance[i][j+1];
            distance[i][cityCount-1]=0;
        }
        for(int i=cityIndex; i<cityCount-1; i++)
        {
            for(int j=0; MAX_CITIES; j++)
            {
                distance[i][j]=distance[i+1][j];
                cityCount--;
                printf("City removed successfully!!\n");
            }
        }
    }



}

