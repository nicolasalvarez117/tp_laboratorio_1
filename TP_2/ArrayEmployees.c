#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "ArrayEmployees.h"

#define TRUE 1
#define FALSE 0
#define ERROR "\nCaracter incorrecto"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array * \param list Employee* Pointer to array of employees
* \param len int Array length *
*\return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(Employee str[], int len)
{
    int i;
    for(i=0;i<len;i++)
        {
          str[i].isEmpty = TRUE;
        }

    return 0;
}
/**
  *\brief Find the value entered by parameters,and if it finds it,
  *       return the position.
  *\param Array employee, len and value the place Free
  *\return the position of the free place (i) or -1 if there is no place.
**/
int findFreePlace(Employee str[],int len,int placeFree)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(str[i].isEmpty == placeFree)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
  *\brief find an Employee by Id en returns the index position in array.
  *\param list Employee* * \param len int
  *\param id int
  *\return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(Employee str[], int len,int id)
{
    int index;
    for(index=0;index<len;index++)
    {
        if(str[index].id == id)
        {
            return index;
            break;
        }
    }
    return -1;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* * \param list Employee*
*   \param len int * \param id int
*   \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
* */
int removeEmployee(Employee str[],int len)
{
    int index;
    int flag = findFreePlace(str,len,0);
    char id[20];
if(flag != -1)
{
    printEmployees(str,len);
    getNumber("\nID a dar de baja: ",ERROR,1,len+1,1,3,id);
    index = findEmployeeById(str,len,atoi(id));
    if(index != -1)
    {
        str[index].isEmpty = TRUE;
        printf("\nBaja exitosa");
        return 0;
    }
    else
    {
        printf("\nEl dato no existe");
        return -1;
    }
}
else
{
    printf("\nNo hay datos cargados");
    return -1;
}
}
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* * \param list Employee
* * \param len int
* * \param order int  [1] indicate UP - [0] indicate DOWN
* *\return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */
int sortEmployees(Employee str[],int len, int order)
{
    Employee aux;
    int i,j;

    if(order)
    {
        for(i=0;i<len-1;i++)
        {
            if(!str[i].isEmpty)
            {
                for(j=i+1;j<len;j++)
                {
                    if(!str[j].isEmpty)
                    {
                        if(strcmp(str[i].lastName,str[j].lastName)>0)
                        {
                            aux = str[i];
                            str[i] = str[j];
                            str[j] = aux;
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(i=0;i<len-1;i++)
        {
            if(!str[i].isEmpty)
            {
                for(j=i+1;j<len;j++)
                {
                    if(!str[j].isEmpty)
                    {
                        if(strcmp(str[i].lastName,str[j].lastName)<0)
                        {
                            aux = str[i];
                            str[i] = str[j];
                            str[j] = aux;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/** \brief print the content of employees array
* * \param list Employee* * \param length int
* * \return int
* */
int printEmployees(Employee str[], int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(!str[i].isEmpty)
        {
            printf("\n%d\n%s\n%s\n%2.f\n%d",str[i].id,str[i].name,str[i].lastName,str[i].salary,str[i].sector);
        }
    }
    return 0;
}

void totalAndAverageSalaries(Employee str[],int len)
{
    float accumulate = 0;
    int timesSalary = 0;
    int times = 0;
    int i;
    int flag = findFreePlace(str,len,0);
    float promedy;
if(flag != -1)
{
    for(i=0;i<len;i++)
    {
        if(!str[i].isEmpty)
        {
            accumulate += str[i].salary;
            timesSalary++;
        }
    }
    for(i=0;i<len;i++)
    {
        if(accumulate < str[i].salary)
        {
            times++;
        }
    }
    promedy = accumulate / timesSalary;
    printf("\nTotal de salarios es: %0.2f\nPromedio de salarios es: %0.2f\n",accumulate,promedy);
    printf("La cantidad de empleados que superan el promedio es %d",times);

}
else
{
    printf("\nNo hay datos cargados");
}
}

void addEmployee(Employee str[],int len,int id)
{
    int index = findFreePlace(str,len,1);
    char salary[20];
    char sector[5];
    int i;

    if(index != -1)
    {
        getName("\nNombre: ",ERROR,1,52,str[index].name);
        getName("\nApellido: ",ERROR,1,52,str[index].lastName);
        getNumber("\nSalario: ",ERROR,1,1000000,1,8,salary);
        for(i=0;i<5;i++)
        {
            printf("\n%d %s",str[i].arraySector.id,str[i].arraySector.descripcion);
        }
        getNumber("\nSector: ",ERROR,1,10,1,3,sector);
        str[index].id = id;
        str[index].salary = atof(salary);
        str[index].sector = atoi(sector);
        str[index].isEmpty = FALSE;
        printf("\nALTA EXITOSA");
    }
    else
    {
        printf("\nNo hay lugar disponible");
    }
}

void modifyEmployee(Employee str[],int len)
{
    char id[20];
    int index;
    char auxValid[20];
    int option;
    int flag = findFreePlace(str,len,0);
if(flag != -1)
{
    printEmployees(str,len);
    getNumber("\nSeleccione la ID a modificar: ",ERROR,1,len,1,len,id);
    index = findEmployeeById(str,len,atoi(id));
    if(index != -1)
    {
        printf("\nQue dato desea modificar?");
        getNumber("\n1:NOMBRE Y APELLIDO\n2:SALARIO\n3:SECTOR\n4:SALIR",ERROR,1,4,1,2,auxValid);
        option = atoi(auxValid);
        switch(option)
        {
        case 1:
            getName("\nIngrese el nuevo nombre: ",ERROR,1,51,str[index].name);
            getName("\nIngrese el nuevo apellido: ",ERROR,1,51,str[index].lastName);
            printf("\nDatos modificados con exito");
            break;
        case 2:
            getNumber("\nIngrese el nuevo salario: ",ERROR,1,1000000,1,10,auxValid);
            str[index].salary = atof(auxValid);
            printf("\nDatos modificados con exito");
            break;
        case 3:
            getNumber("\nIngrese el nuevo sector",ERROR,1,10,1,2,auxValid);
            str[index].sector = atoi(auxValid);
            printf("\nDatos modificados con exito");
            break;
        }
    }
    else
    {
        printf("\nID inexistente");
    }
}
else
{
    printf("\nNo hay datos cargados");
}
}

void information(Employee str[],int len)
{
    int optionTwo;
    int flag = findFreePlace(str,len,0);
    char auxValid[51];
    if(flag != -1)
    {
    system("cls");
            printf("\n1:Lista ordenada por apellido ascendente");
            printf("\n2:Lista ordenada por apellido descendente");
            printf("\n3:Total y promedio de los salarios y cantidad de empleaados que no superan el promedio");
            getNumber("\n4:Salir",ERROR,1,4,1,2,auxValid);
            optionTwo = atoi(auxValid);
            switch(optionTwo)
            {
            case 1:
                sortEmployees(str,len,optionTwo);
                printEmployees(str,len);
                break;
            case 2:
                sortEmployees(str,len,optionTwo-2);
                printEmployees(str,len);
                break;
            case 3:
                totalAndAverageSalaries(str,len);
                break;
            }
    }
    else
    {
        printf("\nNo hay datos cargados");
    }

}

void hardcode(Employee str[],int len)
{
    int i;
    int id[] ={1,2,3,4,5};
    char descripcion[][51] = {"RRHH","CONTABILIDAD","ADMINISTRACION","LIMPIEZA","LOGISTICA"};
    for(i=0;i<len;i++)
    {
        strcpy(str[i].arraySector.descripcion,descripcion[i]);
        str[i].arraySector.id = id[i];
    }
}
