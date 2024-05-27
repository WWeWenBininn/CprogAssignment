#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "login.c"

void readSchedule(DoctorSchedule schedules[], int *doctorCount) {
    FILE *file = fopen("C:/Users/wenbi/OneDrive/Desktop/C programming/.vscode/HMS/docsched.txt", "r");
    if (!file) {
        perror("Failed to open file");
    }

    char line[MAX_LINE_LENGTH];
    DoctorSchedule *currentDoctor = NULL;
    *doctorCount = 0;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        if (strncmp(line, "Dr", 2) == 0) {
            currentDoctor = &schedules[(*doctorCount)++];
            strcpy(currentDoctor->doctorName, line);
            currentDoctor->scheduleCount = 0;
        } else if (currentDoctor) {
            strcpy(currentDoctor->schedule[currentDoctor->scheduleCount++], line);
        }
    }

    fclose(file);
}

void printSchedule(DoctorSchedule schedules[], int doctorCount,char *doctorName) {
    for (int i = 0; i < doctorCount; i++) {
        if (strstr(schedules[i].doctorName, doctorName)) 
        {
            printf("Schedule for %s:\n", schedules[i].doctorName);
            for (int j = 0; j < schedules[i].scheduleCount; j++)
            {
                printf("%s\n", schedules[i].schedule[j]);
            }
            return;
        }
    }
    printf("No schedule found for Dr %s\n", doctorName);
}
int main()
{
    DoctorSchedule schedules[MAX_SCHEDULES];
    int doctorCount;
    int choice;

    while (true)
    {
        printf("\n\n\n\n\n\nHospital Management System\n--------------------------\nWho's logging in?\n1. Admin\n2. Doctor\n3. Nurse\n4. Patient\n\n");
        printf("Please enter department: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
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
                break;
        
            case 2:
        
                if(doctorlogin())
                {
                    int c;
                    printf("\t%s's Menu.\n------------------------\n1. View Schedule\n ",currentdoc->name);
                    scanf("%d",&c);
                    switch (c)
                    {
                    case 1:
                        readSchedule(schedules, &doctorCount);
                        printSchedule(schedules, doctorCount, currentdoc->name);
                        break;
                    
                    default:
                        break;
                    }
                }
                else{
                    printf("cant");
                }
                break;
        
            case 3:
                if (nurselogin())
                {
                    printf("nice3");
                }
                else
                {
                    printf("nope");
                }
                break;
            case 4:
                if (patientlogin())
                {
                    printf("nice4");
                }
                else
                {
                    printf("eh");
                }
                break;
            default:
                printf("try again");
                break;
        }
        return 0;
    }
    return false;    
}
