/* Declaration Of Header Files */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int  No2 = 0;
int  Scan(int a[100]);
void BubbleS(int a[100],int);
void InsertionS(int a[100],int);
void SelectionS(int a[100],int);
void ShellS(int a[100],int);

/* Start Of Main Program */
void main()
{
    int No1 = 0;
    int a[100];
    clrscr();
    printf("\n\t\t :: Welcome To 'Sorting' Program ::");
    do                                                                        // Displaying 'Menu' On Screen.
    {
        printf("\nPlease Select One Of The Following Options ::");
        printf("\n1. Bubble Sorting");
        printf("\n2. Insertion Sorting");
        printf("\n3. Selection Sorting");
        printf("\n4. Shell Sorting");
        printf("\n5. Exit From Menu");
        printf("\nPlease Enter Your Choice Here ::\t");     // Accepting User's Choice For Sorting.
        scanf("%d",&No1);
        switch(No1)
        {
            case 1: No2 = (Scan(a));
                        // Call To Function 'Bubble' Sort.
                        BubbleS(a , No2);
                        break;
            case 2: No2 = (Scan(a));
                        // Call To Function 'Insertion' Sort.
                        InsertionS(a , No2);
                        break;
            case 3: No2 = (Scan(a));
                        // Call To Function 'Slection' Sort.
                        SelectionS(a , No2);
                        break;
            case 4: No2 = (Scan(a));
                        // Call To Function 'Shell' Sort.
                       ShellS(a , No2);
                       break;
            case 5: exit (0);
                break;
            default:printf("\nSorry!!! Invalid Choice");
        }
    }
    while(No1 <= 5);     // End Of 'do...while' Loop.
    getch();
}
int Scan(int a[100])
{
    int i;
    printf("\nPlease Enter The Limit Of Array A ::\t");
    scanf("%d",&No2);
    printf("\nPlease Enter The Elements For Array A ::\n");
    for(i=0;i<No2;i++)
    {
        scanf("%d",&a[i]);
    }
    return (No2);
}
void BubbleS(int a[100], int No2)
{
    int i , Ptr , Temp = 0;
    for(i=1;i<No2;i++)
    {
        Ptr = 0;
        while(Ptr < (No2 - i))
        {
            if(a[Ptr] > a[Ptr+1])
            {
                Temp = a[Ptr];
                a[Ptr] = a[Ptr+1];
                a[Ptr+1] = Temp;
            }
            Ptr++;
        }
    }
    printf("\nBubble Sorted Array A Is As Follows ::\n");
    for(i=0;i<No2;i++)
    {
        printf("%d \n",a[i]);
    }
}
void InsertionS(int a[100],int No2)
{
    int i , j , Temp = 0;
    for(i=1;i<No2;i++)
    {
        Temp = a[i];
        for(j=(i-1); j>=0 && Temp<a[j] ; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = Temp;
    }
    printf("\nInsertion Sorted Array A Is As Follows ::\n");
    for(i=0;i<No2;i++)
    {
        printf("%d \n",a[i]);
    }
}
void SelectionS(int a[100],int No2)
{
    int i , j , k , Temp = 0;

    for(i=0;i<(No2-1);i++)
    {
        k = i;
        for(j=(i+1);j<No2;j++)
        {
            if(a[j] < a[k])
            {
                k = j;
            }
        }
        if(k != i)
        {
            Temp = a[i];
            a[i] = a[k];
            a[k] = Temp;
        }
    }
    printf("\nSelection Sorted Array A Is As Follows ::\n");
    for(i=0;i<No2;i++)
    {
        printf("%d \n",a[i]);
    }
}
void ShellS(int a[100],int No2)
{
    int i, k, Stop, Swap, Limit, Temp;
    int x = (int)(No2/2)-1;
    while(x > 0)
    {
        Stop  = 0;
        Limit = (No2 - x);
        while(Stop == 0)
        {
            Swap = 0;
            for(k=0;k<Limit;k++)
            {
                if(a[k] > a[k+x])
                {
                    Temp   = a[k];
                    a[k]   = a[k+x];
                    a[k+x] = Temp;
                    Swap   = k;
                }
            }
        Limit = (Swap - x);
        if(Swap == 0)
            Stop = 1;
        }
        x=(int)(x/2);
    }
    printf("\nShell Sorted Array A Is As Follows ::\n");
    for(i=0;i<No2;i++)
    {
        printf("%d \n",a[i]);
    }
}
