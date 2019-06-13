#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int cantidadLeidos;
    char idStr[20];
    char nombreStr[51];
    char horasTrabajadasStr[20];
    char sueldoStr[20];

    FILE *pFile = fopen(path,"r");
    if(pFile == NULL)
    {
        printf("\nError al abrir el archivo");
        retorno = 0;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
    while(!feof(pFile))
    {
       cantidadLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
       if(cantidadLeidos == 0)
       {
           break;
       }
       Employee *datosFile = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
       if(datosFile == NULL)
       {
           continue;
       }
        ll_add(pArrayListEmployee,datosFile);


    }
    if(fclose(pFile))
    {
        printf("\nNo se pudo cerrar el archivo correctamente");
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int cantidadLeidos;

    FILE *pFile = fopen(path,"rb");
    if(pFile == NULL)
    {
        printf("\nError al abrir el archivo");
        retorno = 0;
    }
    while(!feof(pFile) && retorno)
    {
        Employee *empleadosBinario = employee_new();
        if(empleadosBinario == NULL)
        {
            printf("\nNo hay memoria disponible");
            retorno = 0;
        }
        cantidadLeidos = fread(empleadosBinario,sizeof(Employee),1,pFile);
        if(cantidadLeidos == 0)
        {
            break;
        }
        ll_add(pArrayListEmployee,empleadosBinario);
    }
    if(fclose(pFile))
    {
        printf("\nNo se pudo cerrar el archivo correctamente");
    }
    return retorno;
}
