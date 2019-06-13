#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "imput.h"
#include "Employee.h"

#define HORA_TRABAJO 100


Employee* employee_new()
{
   return (Employee*)malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee *this = employee_new();
    int flag = 0;
    if(this != NULL)
    {
       if(!employee_setId(this,atoi(idStr)))
       {
           if(!employee_setNombre(this,nombreStr))
           {
               if(!employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)))
               {
                   if(!employee_setSueldo(this,atof(sueldo)))
                   {
                       flag = 1;
                   }
               }
           }
       }

    }
    else
    {
        printf("\nNo hay memoria disponible");
    }
    if(!flag)
    {
        printf("\nDatos incorrecto");
        free(this);
        return NULL;

    }
    return this;

}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
//------------------------------------------------------------------------------------------------
    if(id > 0)
    {
       this->id = id;
       retorno = 0;
    }

    return retorno;

}
int employee_getId(Employee* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->id;
    }
    return returnAux;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
//--------------------------------------------------
    if(isValidName(nombre))
    {
        strlwr(nombre);
        nombre[0] = toupper(nombre[0]);
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}
char* employee_getNombre(Employee* this)
{
    if(this != NULL)
    {
        return this->nombre;
    }
    return NULL;
}

/**
  *\brief indica con un TRUE cuando los datos son solo LETRAS.
  *\param el string a validad.
  *\return 0 cuando los datos son incorrectos y 1 cuando son correctos.
**/
int isValidName(char str[])
{
    int retorno = 1;
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            retorno = 0;
        }
        i++;
    }
    return retorno;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this)
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = this->horasTrabajadas;
    }
    return returnAux;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = -1;
    if(sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

float employee_getSueldo(Employee* this)
{
    float returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->sueldo;
    }
    return returnAux;
}

int preguntar_datos(char* msg,int minimo,int maximo,char *resultado)
{
    int retorno = -1;
    char buffer[4096];

    printf(msg);
    if(minimo<maximo && resultado != NULL)
        {
          fgets(buffer,sizeof(buffer),stdin);
          fflush(stdin);
          buffer[strlen(buffer)-1] = '\0';
          if(strlen(buffer) >= minimo && strlen(buffer) < maximo)
          {
              strncpy(resultado,buffer,maximo);
              retorno = 0;
          }

        }
        return retorno;
}

int menuPrincipal(void)
{
    int retorno;
    printf("\n\t----------------------------MENU-------------------------------\n"
           "\n\t1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
           "\n\t2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
           "\n\t3. Alta de empleado"
           "\n\t4. Modificar datos de empleado"
           "\n\t5. Baja de empleado"
           "\n\t6. Listar empleados"
           "\n\t7. Ordenar empleados"
           "\n\t8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
           "\n\t9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
           "\n\t10. Salir");

    printf("\n\n\tOpcion: ");
    fflush(stdin);
    scanf("%d",&retorno);
    fflush(stdin);
    return retorno;

}

int menuModificacion(void)
{
    int retorno;
    printf("\n\t-------------Que dato desea modificar---------------------\n"
           "\n\t1. Modificar nombre"
           "\n\t2. Modificar horas trabajadas"
           "\n\t3. Modificar sueldo"
           "\n\t4. Salir");
    printf("\n\n\tOpcion: ");
    scanf("%d",&retorno);
    fflush(stdin);
    return retorno;

}

void editar_nombre(Employee *this)
{
    char nombre[51];
    preguntar_datos("\nIngrese el nuevo nombre: ",1,51,nombre);
    if(isValidName(nombre) && this != NULL)
    {
        strlwr(nombre);
        nombre[0] = toupper(nombre[0]);
        strcpy(this->nombre,nombre);
        printf("\nModificacion exitosa");
    }
    else
        printf("\nCaracter incorrecto");
}

void editar_horasTrabajadas(Employee *this)
{
    char aux[51];
    int horasTrabajadas;
    preguntar_datos("\nIngrese las horas trabajadas: ",1,10,aux);
    if(isValidNumber(aux))
    {
        horasTrabajadas = atoi(aux);
        if(horasTrabajadas > 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            printf("\nModificacion exitosa");
        }
    }

}

void editar_sueldo(Employee *this)
{
    char aux[51];
    int sueldo;
    preguntar_datos("\nIngrese el nuevo sueldo: ",1,10,aux);
    if(isValidNumber(aux))
    {
        sueldo = atof(aux);
        if(sueldo > 0)
        {
            this->sueldo = sueldo;
            printf("\nModificacion exitosa");
        }
        else
            printf("\nEl sueldo debe ser mayor a 0");
    }
    else
    {
        printf("\nEl sueldo debe ser numerico");
    }
}

void editar_ID(Employee *this)
{
    if(this != NULL)
    {
        this->id = 0;
        printf("\nBaja exitosa");
    }
    else
    {
        printf("\nError");
    }
}

int isValidNumber(char strNumber[])
{
    int retorno = 1;
    int i = 0;
    while(strNumber[i] != '\0')
    {
        if(strNumber[i] < '0' || strNumber[i] > '9')
        {
            retorno = 0;
        }
        i++;
    }
    return retorno;
}
