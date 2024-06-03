#define MAX_LINE_LENGTH 100
#define MAX_SCHEDULES 100
#define MAX_DOCTORS 10
#define MAX_NAME_LENGTH 50
#define HOURS_IN_DAY 24
#define DAYS_IN_WEEK 7
#define MAX_ITEMS 50
#define RESTOCK_LEVEL 20
#define LAST_STOCK 50

//structs for admin section

struct Inventory
{
    char medicinename[50];
    int quantity;
};
struct Date
{
    int day;
    int month;
    int year;
};

struct newPatient
{
    char username[100];
    char password[100];
    char fullName[100];
    int age;
    char gender;
    struct Date dob;
    char ic[20];
};

struct newDoctor
{
    char username[100];
    char password[100];
    char fullName[100];
    int age;
    char gender;
    struct Date dob;
    char ic[20];
};

struct newNurse
{
    char username[100];
    char password[100];
    char fullName[100];
    int age;
    char gender;
    struct Date dob;
    char ic[20];
};


typedef struct {
  char name[MAX_NAME_LENGTH];
  char days[7][10]; // Array to store schedule for each day (exp., "Mon", "Tue")
  char timings[7][20]; // Array to store timings for each day (exp., "9:00AM - 12:00PM")
  char availability[7][20]; // Array to store doctor availability for each day (exp., "14:00PM - 17:00PM")
} Doctor;


//user login details
typedef struct 
{
    char ID[20];
    char name[30];
    char username[40];
    char password[40];
}creds;

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
