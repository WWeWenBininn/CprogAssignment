#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "login.c"


int main()
{
    int choice;
    printf("\n\n\n\n\n\nHospital Management System\n--------------------------\nWho's logging in?\n1. Admin\n2. Doctor\n3. Nurse\n4. Patient\n\n");
    printf("Please enter department: ");
    scanf("%d",&choice);
    if(choice == 1)
    { 
        if(adminlogin())
        {
            int e;
            printf("press 1 if successful");
            scanf("%d",&e);
            if(e == 1)
            {
                printf("nice");
            }
            else{
                printf("wtf");
            }
        }
        else {
            printf("Terminating...\n\n\n\n\n\n\n");
        }
    }
    else if (choice ==2)
    {
        if(doctorlogin())
        {
            printf("yes2");
        }
        else{
            printf("cant");
        }
    }
    else if (choice == 3)
    {
        if (nurselogin())
        {
            printf("nice3");
        }
        else
        {
            printf("nope");
        }
    }
    else if (choice == 4)
    {
        if (patientlogin())
        {
            printf("nice4");
        }
        else
        {
            printf("eh");
        }
    }   
}
