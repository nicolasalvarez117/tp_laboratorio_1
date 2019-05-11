struct
{
  int id;
  char descripcion[51];

}typedef t_Sector;

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
    t_Sector arraySector;

}typedef Employee;

int initEmployees(Employee str[] , int len);
int findFreePlace(Employee str[],int len,int placeFree);
int findEmployeeById(Employee str[], int len,int id);
int removeEmployee(Employee str[],int len);
int sortEmployees(Employee str[],int len, int order);
int printEmployees(Employee str[], int length);
void totalAndAverageSalaries(Employee str[],int len);
void addEmployee(Employee str[],int len,int id);
void modifyEmployee(Employee str[],int len);
void information(Employee str[],int len);
void hardcode(Employee str[],int len);
