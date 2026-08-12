#include <stdio.h>
#include <string.h>

#define MAX 20
#define PLATFORM 3



struct Train
{
    int trainNo;
    char name[50];
    char destination[50];
};



struct Train queue[MAX];

int front = -1;
int rear = -1;



   

struct Train platform[PLATFORM];

int occupied[PLATFORM] = {0};



void addTrain()
{
    struct Train t;

    if (rear == MAX - 1)
    {
        printf("\nQueue is full!\n");
        return;
    }

    printf("\n========== ADD TRAIN ==========\n");

    printf("Enter Train Number: ");
    scanf("%d", &t.trainNo);

    printf("Enter Train Name: ");
    scanf(" %[^\n]", t.name);

    printf("Enter Destination: ");
    scanf(" %[^\n]", t.destination);

    if (front == -1)
    {
        front = 0;
    }

    rear++;

    queue[rear] = t;

    printf("\nTrain added to waiting queue successfully!\n");
}




void viewQueue()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\nNo waiting trains.\n");
        return;
    }

    printf("\n========== WAITING TRAINS ==========\n");

    for (i = front; i <= rear; i++)
    {
        printf("\nTrain Number : %d\n", queue[i].trainNo);
        printf("Train Name   : %s\n", queue[i].name);
        printf("Destination  : %s\n",
               queue[i].destination);

        printf("-----------------------------\n");
    }
}



void assignPlatform()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\nNo train is waiting.\n");
        return;
    }


    for (i = 0; i < PLATFORM; i++)
    {
        if (occupied[i] == 0)
        {
            platform[i] = queue[front];

            occupied[i] = 1;

            printf("\nTrain %d assigned to Platform %d.\n",
                   queue[front].trainNo,
                   i + 1);

           

            front++;

            return;
        }
    }

    printf("\nAll platforms are occupied!\n");
}




void viewPlatforms()
{
    int i;

    printf("\n========== PLATFORM STATUS ==========\n");

    for (i = 0; i < PLATFORM; i++)
    {
        printf("\nPlatform %d : ", i + 1);

        if (occupied[i] == 1)
        {
            printf("OCCUPIED\n");

            printf("Train Number : %d\n",
                   platform[i].trainNo);

            printf("Train Name   : %s\n",
                   platform[i].name);

            printf("Destination  : %s\n",
                   platform[i].destination);
        }
        else
        {
            printf("AVAILABLE\n");
        }

        printf("-----------------------------\n");
    }
}



void departTrain()
{
    int trainNo;
    int i;

    printf("\nEnter Train Number to depart: ");
    scanf("%d", &trainNo);

    for (i = 0; i < PLATFORM; i++)
    {
        if (occupied[i] == 1 &&
            platform[i].trainNo == trainNo)
        {
            printf("\nTrain %d has departed from Platform %d.\n",
                   trainNo,
                   i + 1);

            occupied[i] = 0;

            return;
        }
    }

    printf("\nTrain not found on any platform.\n");
}



void searchTrain()
{
    int trainNo;
    int i;
    int found = 0;

    printf("\nEnter Train Number to search: ");
    scanf("%d", &trainNo);

    /* Search waiting queue */

    if (front != -1)
    {
        for (i = front; i <= rear; i++)
        {
            if (queue[i].trainNo == trainNo)
            {
                printf("\nTrain found in WAITING QUEUE.\n");

                printf("Train Number : %d\n",
                       queue[i].trainNo);

                printf("Train Name   : %s\n",
                       queue[i].name);

                printf("Destination  : %s\n",
                       queue[i].destination);

                found = 1;
            }
        }
    }

   

    for (i = 0; i < PLATFORM; i++)
    {
        if (occupied[i] == 1 &&
            platform[i].trainNo == trainNo)
        {
            printf("\nTrain found at PLATFORM %d.\n",
                   i + 1);

            printf("Train Number : %d\n",
                   platform[i].trainNo);

            printf("Train Name   : %s\n",
                   platform[i].name);

            printf("Destination  : %s\n",
                   platform[i].destination);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nTrain not found.\n");
    }
}



int main()
{
    int choice;

    do
    {
        printf("\n\n");
        printf("========================================\n");
        printf("       RAILWAY PLATFORM MANAGER\n");
        printf("========================================\n");

        printf("1. Add Train\n");
        printf("2. View Waiting Trains\n");
        printf("3. Assign Train to Platform\n");
        printf("4. View Platform Status\n");
        printf("5. Depart Train\n");
        printf("6. Search Train\n");
        printf("0. Exit\n");

        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTrain();
                break;

            case 2:
                viewQueue();
                break;

            case 3:
                assignPlatform();
                break;

            case 4:
                viewPlatforms();
                break;

            case 5:
                departTrain();
                break;

            case 6:
                searchTrain();
                break;

            case 0:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}