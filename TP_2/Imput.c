#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"

#define FALSE 0
#define TRUE 1


/**
  *\brief toma un string del usuario con un maximo y minimo de caracteres.
  *\param minimo y maximo de caracteres.
  *\param ubicacion de memoria donde se guardara el string.
  *\return el valor 0 si todo es correcto y -1 si los datos son incorrectos.
*/
int getString(int minimo,int maximo,char *resultado)
{
    int retorno = -1;
    char buffer[4096];

    if(minimo<maximo && resultado != NULL)
        {
          fgets(buffer,sizeof(buffer),stdin);
          buffer[strlen(buffer)-1] = '\0';
          if(strlen(buffer) >= minimo && strlen(buffer) < maximo)
          {
              strncpy(resultado,buffer,maximo);
              retorno = 0;
          }

        }
        return retorno;
}

/**
  *\brief toma un string del usuario y valida que sea solo letras.
  *\param mensaje al usuario, mensaje en caso de error de datos.
  *\param minimo y maximo de caracteres y una ubicacion en donde guardar el dato.
  */
void getName(char *msg,char *msgError,int minimo,int maximo,char *resultado)
{
    int flag = 1;
    char buffer[4096];
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       resultado != NULL)
    {
        do {
            printf(msg);
            if(!getString(minimo,maximo,buffer))
                {
                    if(isValidName(buffer))
                    {
                        strlwr(buffer);
                        buffer[0] = toupper(buffer[0]);
                        strncpy(resultado,buffer,maximo);
                        flag = 1;
                        break;
                    }
                    else
                    {
                        printf(msgError);
                    }
                }
            else
                {
                    printf(msgError);
                }
            }while(flag);
    }
}

/**
  *\brief indica con un TRUE cuando los datos son solo LETRAS.
  *\param el string a validad.
  *\return 0 cuando los datos son incorrectos y 1 cuando son correctos.
**/
int isValidName(char str[])
{
    int retorno = TRUE;
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;

}

/**
  *\brief Toma un dato del usuario, valida que sea solo numeros.
  *\param mensaje , mensaje en caso de error.
  *\param un valor maximo y minimo.
  *\param un maximo y minimo de caracteres y una ubicacion donde guardar el dato.
**/
void getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,char *resultado)
{

    char buffer[4096];
    int bufferInt;
    int flag = 1;
    if(msg != NULL &&
       msgError != NULL &&
       desde < hasta &&
       minimo < maximo)
    {
       do
       {
            printf(msg);
            if(!getString(minimo,maximo,buffer))
            {
                if(isValidNumber(buffer))
                {
                    bufferInt = atoi(buffer);
                    if(isValidRange(desde,hasta,bufferInt))
                    {
                        strncpy(resultado,buffer,maximo);
                        flag = 0;
                    }
                    else
                    {
                        printf("\nNo esta en el rango");
                    }

                }
                else
                {
                    printf("\nNo es numerico");
                }
            }
            else
            {
                printf(msgError);
            }
       }while(flag);
    }

}

/**
  *\brief Toma un string y valida que todos los caracteres sean numericos devolviendo un TRUE.
  *\param El string a validar.
  *\return TRUE(1) cuando los datos son correctos y FALSE(0) cuando no son correctos.
**/
int isValidNumber(char strNumber[])
{
    int retorno = TRUE;
    int i = 0;
    while(strNumber[i] != '\0')
    {
        if(strNumber[i] < '0' || strNumber[i] > '9')
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}

/**
  *\brief valida un rango de valores numericos devolviendo TRUE cuando el dato se encuentra en el rango.
  *\param un valor maximo y minimo y el entero que queremos validar.
  *\return TRUE(1) cuando el numero se encuentra en el rango y FALSE(0) en caso contrario.
**/
int isValidRange(int desde,int hasta,int numero)
{
    if(numero >= desde && numero <= hasta)
    {
        return TRUE;
    }
    return FALSE;

}

/**
 *\brief toma el sexo del usuario M para masculino y F para femenino validando los caracteres ingresados.
 *\param un mensaje al usuario, un mensaje en caso de error y una ubicacion donde guardar el dato.
 */
void getSexo(char *msg,char *msgError,char* resultado)
{
    int sexoCorrecto = 2;
    char auxSexo;

    while(sexoCorrecto != 1)
    {
        printf(msg);
        auxSexo = getchar();
        auxSexo = toupper(auxSexo);

        if(auxSexo == 'M' || auxSexo == 'F')
        {
            sexoCorrecto = 1;
            *resultado = auxSexo;
        }
    }

}








