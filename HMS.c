#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "login.c"


// Joshann's part (Staff Nurse)
Doctor doctors[MAX_DOCTORS]; // Array to store doctor data
int num_doctors = 0; // Keeps track of the number of doctors registered
void save_doctors() {
  FILE *fp = fopen("docsched.txt", "w");
  if (fp == NULL) {
    printf("Error saving doctor data file.\n");
    return;
  }

  for (int i = 0; i < num_doctors; i++) {
    fprintf(fp, "%s", doctors[i].name);
    for (int j = 0; j < 7; j++) {
      fprintf(fp, "%s %s %s", doctors[i].days[i], doctors[i].timings[j], doctors[i].availability[j]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}
void load_doctorsinfo() {
  FILE *fp = fopen("docsched.txt", "r");
  if (fp == NULL) {
    printf("Error opening doctor data file.\n");
    return;
  }

  // Read doctor data line by line
  while (fscanf(fp, "%s", doctors[num_doctors].name) != EOF) {
    for (int i = 0; i < 7; i++) {
      fscanf(fp, "%s %s %s", doctors[num_doctors].days[i], doctors[num_doctors].timings[i], doctors[num_doctors].availability[i]);
    }
    num_doctors++;
    if (num_doctors >= MAX_DOCTORS) {
      break;
    }
  }

  fclose(fp);
}
void view_doctor_schedule(char *doctor_name) {
    int discovered = 0;
    for (int i = 0; i < num_doctors; i++) {
        if (strcmp(doctor_name, doctors[i].name) == 0) {
        printf("\nDoctor: %s\n\n", doctors[i].name);
        printf("Doctor's Schedule & Availability\n");
        printf("--------------------------------\n");
        printf("*N/A = Not Available*\n\n");
        printf("Day\tWork Timings\tAvailability(AM/PM)\n");
        printf("---\t------------\t-------------------\n");
        for (int j = 0; j < 7; j++) {
            if (strcmp(doctors[i].days[j], "N/A") != 0) {
            printf("%s\t%s\t\t%s\n\n", doctors[i].days[j], doctors[i].timings[j], doctors[i].availability[j]);
            }
        }
        discovered = 1;
        break;
        }
    }
    if (!discovered) {
        printf("Doctor not found\n");
    }
}

//WenBin's part (Doctor & Login)
void readSchedule(DoctorSchedule schedules[], int *doctorCount) {
    FILE *file = fopen("docsched.txt", "r");
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
void readEHR(char thisfile[50])
{
    
    FILE *file = fopen(thisfile,"r");
    
    char EHR;
    while ((EHR = fgetc(file)) != EOF)
    {
        putchar(EHR);
    }
    fclose(file);
}

//Chiaxin's Part (Admin)
int isValidGender(char gender)
{
    return gender == 'F' || gender == 'M';
}

int validateDOB(int day, int month, int year)
{
    if (year < 1900 || year > 2024)
    {
        return 0;
    }
    if (month < 1 || month > 12)
    {
        return 0;
    }
    if (day < 1 || day > 31)
    {
        return 0;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
    {
        return 0;
    }
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
            {
                return 0;
            }
        } else
        {
            if (day > 28)
            {
                return 0;
            }
        }
    }
    return 1;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void saveToFile(const char* record)
{
    FILE *file = fopen("records.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s\n", record);
        fclose(file);
    } else
    {
        printf("Error saving record to file.\n");
    }
}

void registerUser(const char* role, void* user, size_t size, const char* format)
{
     struct Date dob;

    char ageStr[100];

    printf("Enter username:");
    fgets(((struct newPatient*)user)->username, sizeof(((struct newPatient*)user)->username), stdin);
    ((struct newPatient*)user)->username[strcspn(((struct newPatient*)user)->username, "\n")] = '\0';

    printf("Enter password:");
    fgets(((struct newPatient*)user)->password, sizeof(((struct newPatient*)user)->password), stdin);
    ((struct newPatient*)user)->password[strcspn(((struct newPatient*)user)->password, "\n")] = '\0';

    printf("Enter full name:");
    fgets(((struct newPatient*)user)->fullName, sizeof(((struct newPatient*)user)->fullName), stdin);
    ((struct newPatient*)user)->fullName[strcspn(((struct newPatient*)user)->fullName, "\n")] = '\0';

    printf("Enter your age:");
    fgets(ageStr, sizeof(ageStr), stdin);
    ((struct newPatient*)user)->age = atoi(ageStr);

    do {
        printf("Enter your gender (F/M):");
        scanf(" %c", &((struct newPatient*)user)->gender);
        getchar();
        if (!isValidGender(((struct newPatient*)user)->gender))
        {
            printf("Invalid gender. Please enter 'F' for Female or 'M' for Male.\n");
        }
    } while (!isValidGender(((struct newPatient*)user)->gender));



    int day, month, year;
    int valid = 0;

    do {
        printf("Enter your date of birth (DD MM YYYY):");
        if (scanf("%d %d %d", &day, &month, &year) != 3)
        {
            printf("Invalid input. Please enter numbers only.\n");
            clearInputBuffer();
            continue;
        }

        if (validateDOB(day, month, year))
        {
            valid = 1;
            ((struct newPatient*)user)->dob.day = day;
            ((struct newPatient*)user)->dob.month = month;
            ((struct newPatient*)user)->dob.year = year;
            printf("Date of birth is valid.\n");
        } else
        {
            printf("Invalid date of birth. Please try again.\n");
        }
        clearInputBuffer();
    } while (!valid);


    printf("Enter your IC:");
    fgets(((struct newPatient*)user)->ic, sizeof(((struct newPatient*)user)->ic), stdin);
    ((struct newPatient*)user)->ic[strcspn(((struct newPatient*)user)->ic, "\n")] = '\0';

    char record[500];
    snprintf(record, sizeof(record), format,
             ((struct newPatient*)user)->username,
             ((struct newPatient*)user)->password,
             ((struct newPatient*)user)->fullName,
             ((struct newPatient*)user)->age,
             ((struct newPatient*)user)->gender,
             ((struct newPatient*)user)->dob.day,
             ((struct newPatient*)user)->dob.month,
             ((struct newPatient*)user)->dob.year,
             ((struct newPatient*)user)->ic);

    saveToFile(record);

    printf("%s registered successfully!\n", role);
}

void registerPatient()
{
    struct newPatient patient;
    registerUser("Patient", &patient, sizeof(patient), "Patient: %s, %s, %s, %d, %c, %02d-%02d-%04d, %s");
}

void registerDoctor()
{
    struct newDoctor doctor;
    registerUser("Doctor", &doctor, sizeof(doctor), "Doctor: %s, %s, %s, %d, %c, %02d-%02d-%04d, %s");
}

void registerNurse()
{
    struct newNurse nurse;
    registerUser("Nurse", &nurse, sizeof(nurse), "Nurse: %s, %s, %s, %d, %c, %02d-%02d-%04d, %s");
}


void registerNewUser()
{
    int choice;

    do {
        printf("\n====== Registration Menu ======\n");
        printf("|   1. Register as Patient   |\n");
        printf("|   2. Register as Doctor    |\n");
        printf("|   3. Register as Nurse     |\n");
        printf("|   4. Exit                  |\n");
        printf("===============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                registerNurse();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }while (choice != 4);
}



int timeToIndex(int day, int hour)
{
    return (day * HOURS_IN_DAY) + (hour / 100);
}

void collectAppointmentData(int appointmentData[DAYS_IN_WEEK][HOURS_IN_DAY], const char *filename)
{
    FILE *file;
    char ch;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Contents of the file:\n");
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(file);
}

void countAvailability(int availability[])
{
    for (int i = 0; i < HOURS_IN_DAY * DAYS_IN_WEEK; i++)
    {
        availability[i] = 0;
    }

    // Dr. Parker's schedule
    for (int h = 8; h < 12; h++)
    {
        availability[timeToIndex(1, h)]++;
        availability[timeToIndex(3, h)]++;
        availability[timeToIndex(4, h)]++;
        availability[timeToIndex(5, h)]++;
        availability[timeToIndex(7, h)]++;
    }

    for (int h = 13; h < 18; h++)
    {
        availability[timeToIndex(1, h)]++;
        availability[timeToIndex(3, h)]++;
        availability[timeToIndex(4, h)]++;
        availability[timeToIndex(5, h)]++;
    }

    // Dr. House's schedule
    for (int h = 1; h < 4; h++)
    {
        availability[timeToIndex(1, h)]++;
        availability[timeToIndex(2, h)]++;
    }
    for (int h = 1; h < 5; h++)
    {
        availability[timeToIndex(3, h)]++;
        availability[timeToIndex(6, h)]++;
    }
    for (int h = 18; h < 24; h++)
    {
        availability[timeToIndex(1, h)]++;
        availability[timeToIndex(2, h)]++;
        availability[timeToIndex(3, h)]++;
        availability[timeToIndex(4, h)]++;
        availability[timeToIndex(5, h)]++;
        availability[timeToIndex(7, h)]++;
    }

    // Dr. Who's schedule
    for (int h = 4; h < 8; h++)
    {
        availability[timeToIndex(1, h)]++;
        availability[timeToIndex(3, h)]++;
    }
    for (int h = 24; h < 330; h++)
    {
        availability[timeToIndex(2, h)]++;
    }
    for (int h = 18; h < 24; h++)
    {
        availability[timeToIndex(1, h)]++;
        availability[timeToIndex(5, h)]++;
    }
    for (int h = 17; h < 23; h++)
    {
        availability[timeToIndex(6, h)]++;
    }
    for (int h = 24; h < 3; h++)
    {
        availability[timeToIndex(7, h)]++;
    }
    for (int h = 13; h < 18; h++)
    {
        availability[timeToIndex(4, h)]++;
    }
}

void displayAppointmentTimes(int appointmentData[DAYS_IN_WEEK][HOURS_IN_DAY], int availability[])
{
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    printf("Choose an appointment time (day hour): ");

    char chosenDay[10];
    int chosenHour;

    scanf("%s %d", chosenDay, &chosenHour);

    int dayIndex = -1;

    for (int i = 0; i < DAYS_IN_WEEK; i++)
    {
        if (strcmp(chosenDay, days[i]) == 0)
        {
            dayIndex = i;
            break;
        }
    }

     if (dayIndex != -1 && chosenHour >= 0 && chosenHour < HOURS_IN_DAY)
    {
        printf("You chose: %s\n", chosenDay);
        printf("Hour: %04d\n", chosenHour);

        int index = timeToIndex(dayIndex + 1, chosenHour);

        if (availability[index] > 0)
        {
            printf("There are appointments available for this time.\n");
            if (availability[index] > 1)
            {
                printf("It's a peak hour!\n");
            } else
            {
                printf("It's not a peak hour.\n");
            }
        } else
        {
            printf("There are no appointments available for this time.\n");
        }
    } else
    {
        printf("Invalid day or hour.\n");
    }
}

void viewAppointmentTrends()
{
    int availability[HOURS_IN_DAY * DAYS_IN_WEEK];
    int appointmentData[DAYS_IN_WEEK][HOURS_IN_DAY] = {0};

    const char *filename = "docsched.txt";
    collectAppointmentData(appointmentData, filename);

    printf("\n=======Appointment Trends=======\n");
    printf("|       ~Choose a doctor:~     |\n");
    printf("|        1. Dr. Parker         |\n");
    printf("|        2. Dr. House          |\n");
    printf("|        3. Dr. Who            |\n");
    printf("|        4. Exit               |\n");
    printf("================================\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Doctor: Dr. Parker\n");
        break;
    case 2:
        printf("Doctor: Dr. House\n");
        break;
    case 3:
        printf("Doctor: Dr. Who\n");
        break;

    case 4:
        printf("Exiting...\n");
        break;

    default:
        printf("Invalid choice\n");
        return 1;
    }

    countAvailability(availability);
    displayAppointmentTimes(appointmentData, availability);

}


struct Inventory inventory[MAX_ITEMS];
int itemCount = 0;


void viewInventoryFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
}

// Search inventory
void searchInventory(const char *filename, const char *itemName)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char line[200];
    char medicinename[50];
    char description[100];
    int quantity;
    int found = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%[^;];%[^;];%d", medicinename, description, &quantity) == 3)
        {
            if (strcmp(medicinename, itemName) == 0)
            {
                printf("===Search Inventory===\n");
                printf("Item: %s\n", medicinename);
                printf("Description: %s\n", description);
                printf("Quantity: %d\n", quantity);

                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("Item not found in inventory.\n");
    }

    fclose(file);
}


// Add item to inventory file
void addItemToFile(const char *filename, const char *itemName, const char *description, int quantity)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s;%s;%d\n", itemName, description, quantity);
    printf("===Add Item===\n");
    printf("Added new item: %s\n",itemName);
    printf("Description: %s\n",description);
    printf("Quantity: %d\n",quantity);

    fclose(file);
}


// Check and restock inventory
void checkAndRestock(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    itemCount = 0;
    char line[200];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%[^;];%*[^;];%d", inventory[itemCount].medicinename, &inventory[itemCount].quantity) == 2) {
            itemCount++;
        }
    }
    fclose(file);

    int restocked = 0;
    for (int i = 0; i < itemCount; i++)
    {
        if (inventory[i].quantity < LAST_STOCK)
        {
            printf("!!!Warning!!! %s is low stock with only %d left. Restocking to %d.\n", inventory[i].medicinename, inventory[i].quantity, RESTOCK_LEVEL);
            inventory[i].quantity = RESTOCK_LEVEL;
            restocked = 1;
        }
    }

    if (!restocked)
    {
        printf("No items needed restocking.\n");
    }

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++)
    {
        fprintf(file, "%s;%s;%d\n", inventory[i].medicinename, "Description", inventory[i].quantity);
    }

    fclose(file);
}

void manageInventory()
{
    {
    int choice;
    char itemName[50];
    char description[100];
    int quantity;
    const char *filename = "inventory.txt";

    do {
        printf("\n========== ~Inventory Management~ ==========\n");
        printf("|           1. View Inventory             |\n");
        printf("|           2. Search Inventory           |\n");
        printf("|           3. Add Inventory              |\n");
        printf("|           4. Check And Restock Inventory|\n");
        printf("|           5. Exit                       |\n");
        printf("============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                viewInventoryFromFile(filename);
                break;

            case 2:
                printf("Enter item name to search: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = '\0';
                searchInventory(filename, itemName);
                break;

            case 3:
                printf("Enter inventory name: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = '\0';
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                getchar();
                addItemToFile(filename, itemName, description, quantity);
                break;

            case 4:
                checkAndRestock(filename);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);


    return 0;
    }
}

void exitProgram()
{
    printf("Exiting program.....\n");
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
                    int adminchoice;
                    while (true)
                    {
                        printf("============================================\n");
                        printf("           Hospital Administrator Menu       \n");
                        printf("============================================\n");
                        printf("|         1. Register New User             |\n");
                        printf("|         2. View Appointment Trends       |\n");
                        printf("|         3. Manage Inventory              |\n");
                        printf("|         4. Exit                          |\n");
                        printf("============================================\n");
                        printf("Enter your choice: ");

                        scanf("%d", &adminchoice);
                        getchar();

                        switch (adminchoice)
                        {
                            case 1:
                                registerNewUser();
                                break;
                            case 2:
                                viewAppointmentTrends();
                                break;
                            case 3:
                                manageInventory();
                                break;
                            case 4:
                                break;
                            default:
                                printf("Invalid choice, please try again.\n");
                        }
                        break;
                    }                   
                }
                else
                {
                    printf("\n\nTerminating...\n\n\n\n");
                    break;
                }   
                        
        
            case 2:
        
                if(doctorlogin())
                {
                    while (true)
                    {                       
                        int c;
                        printf("\n\n\t%s's Menu.\n------------------------\n1. View Schedule\n2. View Electronic Health Records ",currentdoc->name);
                        scanf("%d",&c);
                        if(c == 1)
                        {
                            readSchedule(schedules, &doctorCount);
                            printSchedule(schedules, doctorCount, currentdoc->name); 
                        }
                        else if (c == 2)
                        {
                            
                            char choice[20]; 
                            printf("\n\n\nEHR Viewer\n");
                            printf("Please Enter Patient ID: ");
                            scanf("%s",choice); //doctor checks each patient EHR by entering patient ID
                            if(strcmp(choice,pat1.ID)==0)
                            {
                                readEHR("EHR1.txt");
                            }
                            else if(strcmp(choice,pat2.ID)==0)
                            {
                                readEHR("EHR2.txt");
                            }
                            else if(strcmp(choice,pat3.ID)==0)
                            {
                                readEHR("EHR3.txt");
                            }
                            
                        }
                         
                        else if(c == 3)
                        {
                            printf("Going back to previous menu....\n\n");
                            break;                            
                        }                       
                    }
                }
                else{
                    printf("\n\nTerminating...\n\n\n\n");
                    break;
                }
                
        
            case 3:
                if (nurselogin())
                {
                    load_doctorsinfo();
                    char doctor_name[MAX_NAME_LENGTH];
                    while(true)
                    {
                        printf("-----------------------------------------------------------\n");
                        printf("|                   STAFF NURSE HOMEPAGE                  |\n");
                        printf("-----------------------------------------------------------\n\n");
                        printf("Welcome back! What should we do today?\n\n");
                        printf("1. Doctor Scheduler\n");
                        printf("2. Inventory Management\n");
                        printf("3. Reporting and Analytics\n");
                        printf("4. Exit\n\n");

                        int choice;
                        printf("Please enter a choice (1-4) only: ");
                        scanf("%d", &choice);

                        switch (choice) 
                        {
                        case 1:
                            printf("Doctor Scheduler selected!\n\n");
                            printf("-----------------------------------------------\n");
                            printf("|              Doctor Scheduler               |\n");
                            printf("-----------------------------------------------\n\n");
                            printf("1. View Doctor Schedule and Availability\n");
                            printf("2. Exit\n\n");

                            int docsche_choice;
                            printf("Please enter a choice (1 or 2) only: ");
                            scanf("%d", &docsche_choice);


                            switch (docsche_choice){
                                case 1:
                                printf("Please enter the doctor's name (Exp; Dr.ABCDE): ");
                                scanf(" %s", doctor_name); // Read name with space to handle spaces
                                view_doctor_schedule(doctor_name);
                                break;

                                case 2:
                                save_doctors(); // Save doctor data before exiting
                                printf("Exiting Doctor Scheduler, you will be redirected to the Staff Nurse Homepage\n\n");
                                break; // Returns back to the staff nurse homepage for user to input again
                                return 0;
                                default:
                                printf("Invalid choice, please try again\n");
                                }
                                break;

                        case 2:
                            printf("Inventory Management is not yet implemented.\n");
                            break;
                        case 3:
                            printf("Reporting and Analytics is not yet implemented.\n");
                            break;
                        case 4:
                            save_doctors(); // Save doctor data before exiting
                            printf("Exiting Staff Nurse Homepage, returning to HMS Login Page\n");
                            return 0;
                        default:
                            printf("Invalid choice, please try again\n");
                        }
                    }
                }
                          
            case 4:
                if (patientlogin())
                {
                    int e;
                    printf("press 1 if successful, 2 to go back");
                    scanf("%d",&e);
                    if(e == 1)
                    {
                        printf("nice");
                    }
                    else if(e ==2)
                    {
                        printf("Going back to previous menu....\n\n");
                        break;
                    }
                }
                else
                {
                    printf("\n\nTerminating...\n\n\n\n");
                    break;
                }               
            case 5:
                printf("exiting...");
                break;
        
        }
    }
    return 0;   
}
