#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

enum CoachType{firstClass=1,secondClass=2,economy=3};
int passengerCount=0;
int ticketCount=-1;

struct passanger
{
    char passangerName[30];
    int aadharNum;
};



struct ticket
{
    int ticketNum;
    int ticketAadhar;
    int trainNum;
    int coachNum;
    int seatNum;
};

struct ticket ticketList[500];

struct passanger passangerList[500];

struct seat
{
    int seatNum;
    bool vacancy;
    int ticketNum;

};


struct coach
{
    int coachNum;
    struct seat seatList[30];
    enum CoachType coachType;
};



struct train
{
    int trainNum;
    struct coach coachList[20];
};

struct train trains[10];


void initAllTrains()
{

    for(int i=0;i<10;i++)
    {
          trains[i].trainNum=i;
          for(int j=0;j<5;j++)
          {
            trains[i].coachList[j].coachType = firstClass;
            trains[i].coachList[j+5].coachType = secondClass;
            trains[i].coachList[j+10].coachType = economy;
            trains[i].coachList[j+15].coachType = economy;
             for(int k=0;k<30;k++)
             {
                 trains[i].coachList[j].seatList[k].vacancy=true;
                 trains[i].coachList[j+5].seatList[k].vacancy=true;
                 trains[i].coachList[j+10].seatList[k].vacancy=true;
                 trains[i].coachList[j+15].seatList[k].vacancy=true;
             }
          }



    }

}


bool  addPassenger()
{
    int aadhar;
    char name[30];

    if(passengerCount<500)
    {
        struct passanger  new;


    printf("enter passengersn name\n ");
    scanf("%s",&new.passangerName);

    printf("enter passangers aadhar number\n");
    scanf("%d",&new.aadharNum);

    passangerList[passengerCount]=new;
    passengerCount++;

    printf("\npassanger has been added succesfully\n");
    return true;
    }
    else
    {
        printf("passanger list is full");
        return false;

    }
}


struct ticket*  makeBooking(int trainNum , int class, int aadharNo)
{
        for(int i=0;i<20;i++)
        {
            if(trains[trainNum].coachList[i].coachType==class)
            {
            int seatIndx=0;
            for(int seatIndx=0;seatIndx<30;seatIndx++)
            {
                if(trains[trainNum].coachList[i].seatList[seatIndx].vacancy==true)
                {
                    // now let make booking.

                    trains[trainNum].coachList[i].seatList[seatIndx].vacancy=false;
                    ticketList[++ticketCount].coachNum=i;
                    ticketList[ticketCount].seatNum=seatIndx;
                    ticketList[ticketCount].trainNum=trainNum;
                    ticketList[ticketCount].ticketAadhar=aadharNo;
                    ticketList[ticketCount].ticketNum=ticketCount;
                    return &(ticketList[ticketCount]);
                    //return true;

                }
            }
            }

        }

       return NULL;

}


bool bookTicket()
{
    int num2=1;
    int num,num1,class;
    printf("\nare you registrerd as a passenger ,press '1' for yes and '2' for no\n ");
    scanf("%d",&num1);

    if(num1!=num2)
    {
        printf("\nplease register as a passenger to book your tickets \n");
        return false;

    }
    else
    {
        struct ticket *issuedTicket;
        int aadharNo;
        int trainNum;
        enum CoachType cType;
        printf("\nenter your aadhar number to generate your ticket\n ");
        scanf("%d",&aadharNo);

        printf("enter your desired train number\n ");
        scanf("%d",&trainNum);

        printf("what is your preferred mode \n press '1' for first class\npress'2' for sencond class\npress'3' for economy \n");
        scanf("%d",&cType);
            issuedTicket=NULL;
          issuedTicket=makeBooking(trainNum,cType, aadharNo);
        if(issuedTicket != NULL)
       {

        printf("your ticket has been registerd succesfully \n ticket details are \n");
        ticketCount++;
        printf("your ticket number is %d",issuedTicket->ticketNum);
        printf("\n");
        printf("your aadhar number is %d",issuedTicket->ticketAadhar);
        printf("\n");
        printf("your train number is %d",issuedTicket->trainNum);
        printf("\n");
        printf("your coach number is %d",issuedTicket->coachNum);
        printf("\n");
        printf("your seat number is %d",issuedTicket->seatNum);
        printf("\n");
        printf("ENJOY YOUR JOURNEY IN COMFORT");
        printf("\n");

        return true;

       }
       else
       {
        printf("ticket could not be booked");
       }


    }
}


void getMyDetails()
{
    int num;
    printf("Enter your Aadhar number to fetch your details: \n");
    scanf("%d", &num);

    for (int i = 0; i < 500; i++)
    {
        if (ticketList[i].ticketAadhar == num)
        {
            printf("Your details are:\n");
            printf("Your ticket number is %d\n", ticketList[i].ticketNum);
            printf("Your train number is %d\n", ticketList[i].trainNum);
            printf("Your coach number is %d\n", ticketList[i].coachNum);
            printf("Your seat number is %d\n", ticketList[i].seatNum);
            return;
        }
    }

    printf("Passenger with Aadhar number %d not found.\n", num);
}




int findName(int aadharNum)
{
    for(int i=0 ;i<passengerCount ;i++)
    {
        for(int l=0 ;l<ticketCount;l++)
        {
            if(passangerList[i].aadharNum==ticketList[i].ticketAadhar)
            {
                return i;
            }
        }
    }
    return 0;

}


void printTrainPassengerList(int trainNum)
{
    int passenger = 1;
    for (int y = 0; y < ticketCount; y++)
    {
        if (ticketList[y].trainNum == trainNum)
        {
            int found = findName(ticketList[y].ticketAadhar);
            printf("Passenger %d:\n", passenger);
            printf("Passenger name: %s\n", passangerList[found].passangerName);
            printf("Ticket number: %d\n", ticketList[y].ticketNum);
            printf("Aadhar number: %d\n", ticketList[y].ticketAadhar);
            printf("\n");
            passenger++;
        }
    }
}


bool cleanUpTrainPassengerList(int trainNum)
{

}


bool cancelMyTicket()
{


}


int main()
{
    int choice,xyz;
    int x, y;
    initAllTrains();

    while (1)
    {
        printf(" press 1 to add a passenger \n press 2 to book a ticket \n press 3 to get your details \n press 4 print train passengers\npress 5 to exit\n ");
        scanf(" %d", &choice);


        if (choice == 5 )
        {
            exit(0);
        }

        switch (choice)
        {
          case 1:
             addPassenger();
              break;

          case 2:
              bookTicket();
              break;

          case 3:
              getMyDetails();
              break;

          case 4:
              printf("enter train number");
              scanf("%d",&xyz);
            printTrainPassengerList(xyz);

            break;

          default:
              printf("Invalid Choice");
        }
    }
return -1;
}
