#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "creds.h"

int adminlogin()
{
    int attempts = 3;

    while(attempts>0)
    {
        printf("Enter username: ");
        scanf("%s",&user);

        if(strcmp(user,admin1.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,admin1.password)==0)
            {
                printf("Login successful.\nWelcome, Mary.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }

            
        }
        else if(strcmp(user,admin2.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,admin2.password)==0)
            {
                printf("Login successful.\nWelcome, James.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }

        else if(strcmp(user,admin3.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,admin3.password)==0)
            {
                printf("Login successful.\nWelcome, Momo.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }
        else
        {
            printf("try again\n");
        }
    }
    if(attempts == 0)
    {
        printf("\n\n\n\n");
    }
    return false;
}


int doctorlogin()
{
    int attempts = 3;
    while(attempts>0)
    {
        printf("Enter username: ");
        scanf("%s",&user);

        if(strcmp(user,doc1.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,doc1.password)==0)
            {
                printf("Login successful.\nWelcome, Dr.Parker.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }

            
        }
        else if(strcmp(user,doc2.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,doc2.password)==0)
            {
                printf("Login successful.\nWelcome, Dr.House.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }

        else if(strcmp(user,doc3.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,doc3.password)==0)
            {
                printf("Login successful.\nWelcome, Dr.Who.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }
        else
        {
            printf("try again\n");
        }
    }
    if(attempts == 0)
    {
        printf("Terminating...\n\n\n\n");
        return false;
    }
    return false;
}

int nurselogin()
{
    int attempts = 3;
    while(attempts>0)
    {
        printf("Enter username: ");
        scanf("%s",&user);

        if(strcmp(user,nur1.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);  
            if(strcmp(pass,nur1.password)==0)
            {
                printf("Login successful.\nWelcome, Nurse Joy.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }

            
        }
        else if(strcmp(user,nur2.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,doc2.password)==0)
            {
                printf("Login successful.\nWelcome, Nayeon.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }

        else if(strcmp(user,doc3.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,doc3.password)==0)
            {
                printf("Login successful.\nWelcome, Jamie.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }
        else
        {
            printf("try again\n");
        }
    }
    if(attempts == 0)
    {
        printf("Terminating...\n\n\n\n");
        return false;
    }
    return false;
}


int patientlogin()
{
    int attempts = 3;
    while(attempts>0)
    {
        printf("Enter username: ");
        scanf("%s",&user);

        if(strcmp(user,pat1.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);  
            if(strcmp(pass,pat1.password)==0)
            {
                printf("Login successful.\nWelcome, Jungkook.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }

            
        }
        else if(strcmp(user,pat2.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,pat2.password)==0)
            {
                printf("Login successful.\nWelcome, Harry.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }

        else if(strcmp(user,pat3.username) == 0)
        {
            printf("Enter password: ");
            scanf("%s",&pass);
            if(strcmp(pass,pat3.password)==0)
            {
                printf("Login successful.\nWelcome, Seth.\n");
                return true;
                break;
            }
            else
            {
                attempts = attempts -1;
                printf("Login failed. You have %d attempts left.\n",attempts);
            }
        }
        else
        {
            printf("try again\n");
        }
    }
    if(attempts == 0)
    {
        printf("Terminating...\n\n\n\n");
        return false;
    }
    return false;
}
