#include <stdio.h>
#include <string.h>



struct credentials
{
    char username[30];
    char password[30]; 
};


int login(struct credentials *credentials)
{
    char enteruser[50];
    char enterpass[50];

    printf("Enter username: ");
    scanf("%s",&enteruser);
    printf("Enter password: ");
    scanf("%s",&enterpass);
   
        if (strcmp(enteruser, credentials[0].username) == 0 &&
            strcmp(enterpass, credentials[0].password) == 0) {
            printf("Login successful! \n");}
    
    


}


int main()
{
    int choice;
    printf("\n\n\n\n\n\nHospital Management System\n--------------------------\nWho's logging in?\n1. Admin\n2. Doctor\n3. Nurse\n4. Patient\n\n");
    scanf("%d",&choice);

    if(choice == 1)
    {
        struct credentials admins[] = 
        {
            {"maryjane","janemary30"},
            {"Jamespotter","harry"},
            {"momochan","whatislove"}
        
        };
    }

    else if(choice == 2)
    {
        struct credentials doctors[] = 
        {
            {"drparker","parking@4"},
            {"drhouse","houseattheER"},
            {"drwho","angels"}
        
        };
    }

    else if(choice == 3)
    {
        struct credentials nurse[] = 
        {
            {"nursejoy","pikachu"},
            {"Kimnayeon","poppoppop"},
            {"oliverjam","cooking"}
        
        };
    }

    else if(choice == 4)
    {
        struct credentials patient[] = 
        {
            {"Jungkook","seven7"},
            {"Harrystyles","goodnight"},
            {"Macfarlane","Logic"}
        
        };
    }
}
