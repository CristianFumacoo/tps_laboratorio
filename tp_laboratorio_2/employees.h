struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef eEmployee;

void initEmployees(eEmployee[],int);

void hardcoreEmployees(eEmployee[],int);

int addEmployees(eEmployee[],int,int);

void printEmployees(eEmployee[],int);

void modifyEmployees(eEmployee[],int);

void deleteEmployees(eEmployee[],int);

void orderEmployees(eEmployee[],int);

void calculoSalario(eEmployee[],int);
