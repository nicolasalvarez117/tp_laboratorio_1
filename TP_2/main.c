#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "imput.h"
#include "ArrayEmployees.h"
#define ERROR "\nCaracter incorrecto"
#define CANTIDAD_EMPLOYEES 5

int main()
{
    Employee arrayEmployees[CANTIDAD_EMPLOYEES];

    initEmployees(arrayEmployees,CANTIDAD_EMPLOYEES);
    hardcode(arrayEmployees,5);
    int idIncrement = 1;
    int option;
    char auxValid[51];

    do
    {
        getNumber("\n\n\n1:ALTA\n2:BAJA\n3:MODIFICACION\n4:INFORMAR\n5:SALIR: ",
                  "\nOpcion incorrecta",1,5,1,2,auxValid);
        option = atoi(auxValid);
        switch(option)
        {
        case 1:
            addEmployee(arrayEmployees,CANTIDAD_EMPLOYEES,idIncrement);
            idIncrement++;
            break;
        case 2:
            removeEmployee(arrayEmployees,CANTIDAD_EMPLOYEES);
            break;
        case 3:
            modifyEmployee(arrayEmployees,CANTIDAD_EMPLOYEES);
            break;
        case 4:
            information(arrayEmployees,CANTIDAD_EMPLOYEES);
            break;
        }
    }while(option != 5);

    return 0;
}
