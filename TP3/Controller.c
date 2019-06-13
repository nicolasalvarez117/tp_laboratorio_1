#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    if(parser_EmployeeFromText(path,pArrayListEmployee))
    {
        printf("\nDatos cargados con exito");
        retorno = 0;
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(parser_EmployeeFromBinary(path,pArrayListEmployee))
    {
        printf("\nDatos cargados con exito");
        retorno = 0;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char idStr[20] = "13";
    char nombre[51];
    char horasTrabajadas[20];
    char sueldo[20];

    preguntar_datos("\nIngrese el nombre: ",1,51,nombre);
    preguntar_datos("\nIngrese las horas trabajadas: ",1,20,horasTrabajadas);
    preguntar_datos("\nIngrese el sueldo: ",1,20,sueldo);
    if(isValidName(nombre) && isValidNumber(horasTrabajadas) && isValidNumber(sueldo))
    {
        Employee *altaEmpleado = employee_newParametros(idStr,nombre,horasTrabajadas,sueldo);
        if(altaEmpleado != NULL)
        {
            altaEmpleado->id = pArrayListEmployee->size + 1;
            ll_add(pArrayListEmployee,altaEmpleado);
            printf("\n\tEl alta a sido exitosa");
            retorno = 0;
        }
    }
    else
        printf("\nDatos incorrectos");

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return -1 en caso de error, y 0 si todo es correcto.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *empleado;
    char index[51];
    int opcion;
    int retorno = 0;
    if(ll_len(pArrayListEmployee) > 0)
    {
        preguntar_datos("\nQue ID desea modificar?\nOpcion: ",1,10,index);
        empleado = ll_get(pArrayListEmployee,(atoi(index)-1));
        if(empleado != NULL)
        {
            switch(opcion = menuModificacion())
            {
                case 1:
                    editar_nombre(empleado);
                    break;
                case 2:
                    editar_horasTrabajadas(empleado);
                    break;
                case 3:
                    editar_sueldo(empleado);
                    break;
                default:
                    break;
            }
        }
        else
        {
            printf("\nNo se encontro la ID");
            retorno = -1;
        }
    }
    else
    {
        printf("\nNo hay datos cargados");
        retorno = -1;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee *empleado;
    char index[51];
    int retorno = 0;
    if(ll_len(pArrayListEmployee) > 0)
    {
        preguntar_datos("\nQue ID desea remover?",1,10,index);
        if((empleado = ll_get(pArrayListEmployee,(atoi(index)-1))) != NULL)
        {
            ll_remove(pArrayListEmployee,(atoi(index)-1));
            printf("\nBaja exitosa");
        }
        else
        {
            printf("\nNo se encontro la ID");
            retorno = -1;
        }
    }
    else
    {
        printf("\nNo hay datos cargados");
        retorno = -1;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    int cantidadElementos = ll_len(pArrayListEmployee);
    if(cantidadElementos > 0)
    {
        printf("ID      NOMBRE          HORAS TRABAJADAS        SUELDO\n");
        for(i=0;i<cantidadElementos;i++)
        {
            Employee *p = ll_get(pArrayListEmployee,i);
            if(p->id > 0 && p != NULL)
            {
                printf("\n%d",employee_getId(p));
                printf("\t%s",employee_getNombre(p));
                printf("\t\t%d",employee_getHorasTrabajadas(p));
                printf("\t\t\t%.2f",employee_getSueldo(p));
            }
        }
    }
    else
    {
        printf("\nNo hay datos cargados");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int i , j;
    Employee *pI;
    Employee *pJ;
    Employee *aux;
    int cantidadElementos = pArrayListEmployee->size;
    if(cantidadElementos > 0)
    {
        for(i=0;i<cantidadElementos-1;i++)
        {
            pI = ll_get(pArrayListEmployee,i);
            for(j=i+1;j<cantidadElementos;j++)
            {
                pJ = ll_get(pArrayListEmployee,j);
                if(strcmp(pI->nombre,pJ->nombre) < 0)
                {
                    aux = pI;
                    pI = pJ;
                    pJ = aux;
                }
            }
        }
    }
    else
    {
        printf("\nNo hay datos cargados");
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"w");
    int cantidadLetras;
    int cantidadLista = ll_len(pArrayListEmployee);
    if(pFile == NULL)
    {
        printf("\nError al abrir el archivo");
        return 0;
    }
    int i = 0;
    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    while(i <= cantidadLista)
    {
        Employee *p = ll_get(pArrayListEmployee,i);
        if(p != NULL)
        {
            cantidadLetras=fprintf(pFile,"%d,%s,%d,%f\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
        }
        if(cantidadLetras == 0)
        {
            break;
        }
        i++;

    }
    fclose(pFile);
    ll_clear(pArrayListEmployee);
    printf("\nSe han guardado los datos");

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"wb");
    if(pFile == NULL)
    {
        printf("\nError al abrir el archivo");
        return 0;
    }
    int i;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        if(!feof(pFile))
        {
            fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,pFile);
        }

    }
    printf("\nLos datos han sido guardados en modo binario.");
    ll_deleteLinkedList(pArrayListEmployee);
    fclose(pFile);
    ll_clear(pArrayListEmployee);

    return 1;
}

