#define MAX_VEHICLE 100

struct Vehicle
{
    int vehicleID;
    char vehicleName[50];
    char manufacturerName[50];
    int date, month, year;
};

struct sign_in
{
    char usr[31];
    char key[20];

};

struct Vehicle vehicleRecords[MAX_VEHICLE];
struct sign_in user;

// prototypes

void head_Message();
void print_Message_in_Center(char *message);
void welcome_Message();
int login_pannel();
int is_Name_Valid( char *name);
int is_Date_Valid(int date, int month, int year);
void addVehiclesInDataBase(int *totalVehicles);
void searchVehicles( int totalVehicles);
void viewVehicles( int totalVehicles);
void deleteVehicles( int *totalVehicles);
void updateCredential();
void menu();

int main()
{

    int totalVehicles = 0;


    // function call

    head_Message();
    print_Message_in_Center("CSE103 Project");
    welcome_Message();
    head_Message();
    print_Message_in_Center("Login");

    // User Input for Login

    int a = login_pannel();
    if(a == 1)
    {
        menu();
    }

    head_Message();
    print_Message_in_Center("MAIN MENU");

    int choice;
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            head_Message();
            addVehiclesInDataBase(&totalVehicles);
            head_Message();
            print_Message_in_Center("MAIN MENU");
            break;

        case 2:
            head_Message();
            searchVehicles(totalVehicles);
            printf("\n");
            printf("\n");
            printf("\t\t\tPress any key to go to main menu.....");
            getche();
            head_Message();
            print_Message_in_Center("MAIN MENU");
            break;

        case 3:
            head_Message();
            viewVehicles(totalVehicles);
            printf("\n");
            printf("\n");
            printf("\t\t\tPress any key to go to main menu.....");
            getche();
            head_Message();
            print_Message_in_Center("MAIN MENU");
            break;

        case 4:
            head_Message();
            deleteVehicles(&totalVehicles);
            printf("\n");
            printf("\n");
            printf("\t\t\tPress any key to go to main menu.....");
            getche();
            head_Message();
            print_Message_in_Center("MAIN MENU");
            break;

        case 5:
            head_Message();
            updateCredential();
            head_Message();
            print_Message_in_Center("MAIN MENU");
            break;

        case 6:
            printf("\n\n\t\t\t\t\t\t\tThank you!!!\n");
            break;

        default:
            printf("\t\t\tInvalid choice. Please select a valid option.\n");
            head_Message();
            print_Message_in_Center("MAIN MENU");
        }
    }
    while (choice != 6);

    return 0;
}

void head_Message(void)
{
    system("cls");
    system("COLOR 06");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("\t\t\t<~><~><~><~> \t\t\t\t\t\t       <~><~><~><~>\n");
    printf("\t\t\t<~><~><~><~> \t\tVehicle Management System  \t       <~><~><~><~>\n");
    printf("\t\t\t<~><~><~><~> \t\t\t\t\t\t       <~><~><~><~>\n");
    printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
}

void welcome_Message()
{

    printf("\n\t\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("\n\t\t\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t\t\t<~>\t\t  WELCOME \t\t  <~>");
    printf("\n\t\t\t\t\t<~>\t\t    TO\t\t\t  <~>");
    printf("\n\t\t\t\t\t<~>\t\t  VEHICLE \t\t  <~>");
    printf("\n\t\t\t\t\t<~>\t\t MANAGEMENT \t\t  <~>");
    printf("\n\t\t\t\t\t<~>\t\t   SYSTEM\t\t  <~>");
    printf("\n\t\t\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("\n\t\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");

    printf("\n\t\t\tEnter any key to continue...... ");
    getche();
}

void print_Message_in_Center(char *message)
{

    int width = 122;
    int len = strlen(message);
    int center = (width - len) / 2;
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n");
    for (int i = 0; i < center; i++)
    {
        printf(" ");
    }
    printf("%s\n", message);
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n");
}

int login_pannel()
{

    char username[101];
    char password[20];
    char pas;
    char lol[50]="cse103";
    int a,i=0;
    printf("\n\t\t\t\tUsername: ");
    scanf("%s",&username);
    if(strcmp(username,lol)==0)
    {
        printf("\n\t\t\t\tPassword: ");
        while((pas = getch())!=13)
        {
            password[i]=pas;
            i++;
            printf("*");
        }
        password[i]='\0';

        if(strcmp(password,lol)==0)
        {
            a = 1 ;
        }
        else
        {
            printf("\a\n\n\n\t\t\t\t\tWrong password!Try again");
            printf("\n\n\n\t\t\tEnter any key to continue...... ");
            a=0;
            getch();
            head_Message();
            print_Message_in_Center("Login");
            login_pannel();
        }
    }
    else
    {
        head_Message();
        print_Message_in_Center("Login");
        printf("\a\n\n\n\t\t\t\t\t\t     User is unknown!");
        printf("\n\n\n\t\t\tEnter any key to continue...... ");
        a=0;
        getch();
        head_Message();
        print_Message_in_Center("Login");
        login_pannel();
    }
    return a;
}

void menu()
{
    printf("\t\t\t1.Add Vehicle\n");
    printf("\t\t\t2.Search Vehicles\n");
    printf("\t\t\t3.View Vehicles\n");
    printf("\t\t\t4.Delete Vehicle\n");
    printf("\t\t\t5.Update Password\n");
    printf("\t\t\t6.Exit\n ");
    printf("\n\n\t\t\tEnter your choice: ");
}

void addVehiclesInDataBase(int *totalVehicles)
{
    print_Message_in_Center("ADD NEW VEHICLE");
    struct Vehicle newVehicle;
    printf("\n\t\t\tENTER VEHICLE DETAILS BELOW:\n");
    printf("\t\t\t-------------------------------------------------------------\n");

    // Input validation for Vehicle Name

    if (*totalVehicles >= MAX_VEHICLE)
    {
        printf("Record limit reached. Cannot add more vehicles.\n");
        return;
    }

    printf("\n\t\t\tEnter Vehicle ID: ");
    scanf("%d", &newVehicle.vehicleID);
    getchar();

    do
    {
        printf("\n\t\t\tEnter Vehicle Name: ");
        gets(newVehicle.vehicleName);

        if (!(is_Name_Valid(newVehicle.vehicleName)))
        {
            printf("\n\t\t\t\t\t\t\t Invalid Vehicle Name \n\n");
        }

    }
    while (!is_Name_Valid(newVehicle.vehicleName));

    do
    {
        printf("\n\t\t\tEnter Manufacturer Name: ");
        gets(newVehicle.manufacturerName);

        if (!(is_Name_Valid(newVehicle.manufacturerName)))
        {
            printf("\n\t\t\t\t\t\t\t Invalid manufacturer Name \n\n");
        }

    }
    while (!is_Name_Valid(newVehicle.manufacturerName));

    do
    {

        printf("\n\t\t\tVehicle issued date by Manufacturer (day/month/year) : ");
        scanf("%d/%d/%d", &newVehicle.date, &newVehicle.month, &newVehicle.year);

        if (!(is_Date_Valid(newVehicle.date, newVehicle.month, newVehicle.year)))
        {
            printf("\n\t\t\t\t\t\t\t Invalid Date Format \n\n");
        }

    }
    while (!(is_Date_Valid(newVehicle.date, newVehicle.month, newVehicle.year)));


    vehicleRecords[(*totalVehicles)++] = newVehicle;

    printf("\n\t\t\t\t\t\t\t Vehicle Added Successfully \n\n");
}
void searchVehicles( int totalVehicles )
{
    print_Message_in_Center("Search Vehicle");

    char searchName[50];
    int found = 0;

    printf("\t\t\tEnter Vehicle Name to search: ");
    gets(searchName);

    for (int i = 0; i < totalVehicles; i++)
    {
        if (strcmp(vehicleRecords[i].vehicleName, searchName) == 0)
        {

            printf("\t\t\tVehicle ID: %d\n", vehicleRecords[i].vehicleID);
            printf("\t\t\tVehicle Name: %s\n", vehicleRecords[i].vehicleName);
            printf("\t\t\tManufacturer Name: %s\n", vehicleRecords[i].manufacturerName);
            printf("\t\t\tVehicle issued date by Manufacturer (day/month/year): %d/%d/%d\n", vehicleRecords[i].date, vehicleRecords[i].month, vehicleRecords[i].year);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\t\t\tVehicle not found in records.\n");
    }
}

void viewVehicles( int totalVehicles)
{
    print_Message_in_Center("VIEW VEHICLE DETAILS");

    if (totalVehicles == 0)
    {
        printf("\t\t\tNo vehicle records found.\n");
        return;
    }

    for (int i = 0; i < totalVehicles; i++)
    {
        printf("\t\t\tVehicle count = %d:\n\n", i + 1);
        printf("\t\t\tVehicle ID: %d\n", vehicleRecords[i].vehicleID);
        printf("\t\t\tVehicle Name: %s\n", vehicleRecords[i].vehicleName);
        printf("\t\t\tManufacturer Name: %s\n", vehicleRecords[i].manufacturerName);
        printf("\t\t\tVehicle issued date by Manufacturer (day/month/year): %d/%d/%d\n", vehicleRecords[i].date, vehicleRecords[i].month, vehicleRecords[i].year);
        printf("\n");
    }
}

void deleteVehicles( int *totalVehicles)
{
    print_Message_in_Center("Delete Vehicle");

    int idToDelete;
    int found = 0;

    printf("\t\t\tEnter Vehicle ID to delete: ");
    scanf("%d", &idToDelete);

    for (int i = 0; i < *totalVehicles; i++)
    {
        if (vehicleRecords[i].vehicleID == idToDelete)
        {
            found = 1;
            for (int j = i; j < *(totalVehicles - 1); j++)
            {
                vehicleRecords[j] = vehicleRecords[j + 1];
            }
            (*totalVehicles)--;
            printf("\t\t\tRecord deleted successfully.\n");
            break;
        }

    }


    if (!found)
    {
        printf("\t\t\tRecord not found.\n");
    }
}

int is_Name_Valid(char *name)
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (!((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90) || name[i] == 32 || (name[i] >= 48 && name[i] <= 57)))
        {
            return 0;
            break;
        }
    }
    return 1;
}

int is_Date_Valid(int date, int month, int year)
{
    if (year >= 1800 && year <= 2030)
    {
        if (month >= 1 && month <= 12)
        {
            if ((date >= 1 && date <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
                return 1;

            else if ((date >= 1 && date <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
                return 1;

            else if ((date >= 1 && date <= 28) && (month == 2))
            {
                return 1;
            }
            else if ((year % 4 == 0) && (date = 29) && (month == 2))
            {
                return 1;
            }
        }
    }
    return 0;
}




void updateCredential() 
{

    int a, i = 0;
    char newUsername[100];
    char newPassword[100];
    
    print_Message_in_Center("Change Password");
    
    printf("\t\t\t\tEnter new username: ");
    scanf("%s", newUsername);

    printf("\n\t\t\t\tEnter new password: ");
    scanf("%s", newPassword);
    system("cls");

    do {
        
        
        head_Message();
        print_Message_in_Center("Login");

        printf("\t\t\t\tUsername: ");
        scanf("%s", user.usr);
        

        printf("\n\t\t\t\tPassword: ");
        i = 0;

        while ((user.key[i] = getch()) != 13) 
        {
                printf("*");
                i++;
            
        }
        user.key[i] = '\0';

        if (strcmp(user.usr, newUsername) == 0 && strcmp(user.key, newPassword) == 0) 
        {
            a = 1;
            printf("\n\t\t\t\tSuccessfully Login");

        } 
        
        else 
        {
            a = 0;
            printf("\n\t\t\t\tFailed to Login");
            getch();
            
        }

    } while (!(strcmp(user.usr, newUsername) == 0 && strcmp(user.key, newPassword) == 0));

}

