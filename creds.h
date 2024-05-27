#define MAX_LINE_LENGTH 100
#define MAX_SCHEDULES 100

typedef struct 
{
    char ID[20];
    char name[30];
    char username[40];
    char password[40];
}creds;


//user login details


    char user[40];
    char pass[40];
    creds admin1 = {"ad01","Mary","maryjane","janemary30"};
    creds admin2 = {"ad02","James","Jamespotter","harry"};
    creds admin3 = {"ad03","Momo","momochan","whatislove"};

    creds doc1 = {"dr01","Parker","drparker","parking@4"};
    creds doc2 = {"dr02","House","drhouse","houseattheER"};
    creds doc3 ={"dr03","Who","drwho","angels"};

    creds nur1 = {"nur01","Nurse Joy","nursejoy","pikachu"};
    creds nur2 = {"nur02","Nurse Kim","Kimnayeon","poppoppop"};
    creds nur3 = {"nur03","Nurse Oliver","oliverjam","cooking"};

    creds pat1 = {"p01","Jungkook","jungkook","seven7"};
    creds pat2 = {"p02","Harry","Harrystyles","goodnight"};
    creds pat3 = {"p03","Seth","Macfarlane","Logic"};

typedef struct {
    char doctorName[MAX_LINE_LENGTH];
    char schedule[MAX_SCHEDULES][MAX_LINE_LENGTH];
    int scheduleCount;
} DoctorSchedule;

creds *currentdoc;
