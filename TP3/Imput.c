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

/**
  *\brief toma un string del usuario y valida que sea solo letras.
  *\param mensaje al usuario, mensaje en caso de error de datos.
  *\param minimo y maximo de caracteres y una ubicacion en donde guardar el dato.
  */
int getName(char *msg,char *msgError,int minimo,int maximo,char *resultado)
{
    char buffer[4096];
    int retorno = 1;
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       resultado != NULL)
    {
        printf(msg);
        if(!getString(minimo,maximo,buffer))
        {
            if(isValidName(buffer))
            {
                strlwr(buffer);
                buffer[0] = toupper(buffer[0]);
                strncpy(resultado,buffer,maximo);
                break;
            }
            else
            {
                printf(msgError);
                retorno = 0;
            }
        }
        else
        {
            printf(msgError);
            retorno = 0;
        }

    }
    else
    {
        printf(msgError);
        retorno = 0;
    }
    return retorno;
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
int getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,char *resultado)
{

    char buffer[4096];
    int bufferInt;
    int retorno = 1;
    if(msg != NULL &&
       msgError != NULL &&
       desde < hasta &&
       minimo < maximo)
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
                }
                else
                {
                    retorno = 0;
                    printf("\nNo esta en el rango");
                }

            }
            else
            {
                retorno = 0;
                printf("\nNo es numerico");
            }
        }
        else
        {
            retorno = 0;
            printf(msgError);
        }

    }
    return retorno;

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
        fflush(stdin);
        auxSexo = getchar();
        auxSexo = toupper(auxSexo);

        if(auxSexo == 'M' || auxSexo == 'F')
        {
            sexoCorrecto = 1;
            *resultado = auxSexo;
        }
    }

}
/**
  *\brief Toma una DNI como caracteres numericos ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo cantidad de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
int getDni(    char* msg,
                char* msgError,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    int flag = 1;
    char bufferStr[4096];
    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {
      do
      {
        printf(msg);
        if(!getString(minimo,maximo,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                if(isValidDni(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    flag = 0;
                    retorno = 0;
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
        }
        else
        {
            printf(msgError);
        }
    }while(flag);
    }
    return retorno;
}
/**
  *\brief Valida si el array de DNI es completo.
  *\param Recibe el array con la cadena de numerica.
  *\return TRUE o FALSE.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidDni(char str[])
{
    int retorno = FALSE;
    if(!(str[7] == '\0' || str[7] == NULL))
    {
        retorno = TRUE;
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////////
int getCuit(    char* msg,
                char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if( msg != NULL &&
        msgError != NULL &&
        msgError2 != NULL &&
        msgError3 != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {
        printf("%s",msg);
        if(!getString(minimo,maximo,bufferStr))
        {
            if(isValidCuitA(bufferStr))
            {
                if(isValidCuitB(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                }
                else
                {
                    printf("%s",msgError2);
                }
            }
            else
            {
                printf("%s",msgError);
            }
        }else
        {
            printf("%s",msgError3);
        }
    }
    return retorno;
}
////////////////////////////////////////////////
int isValidCuitA(char str[])
{

    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') &&  (str[i] != '-'))
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}
//////////////////////////////////////////////////
int isValidCuitB(char str[])
{
    int retorno = FALSE;
    if(!(str[12] == '\0' || str[12] == NULL))
    {
        if(str[2] =='-' && str[11]=='-')
        {
            retorno = TRUE;
        }
    }
    return retorno;
}
/**
  *\brief Valida los caracteres de un eMail.
  *\param El dato string a validar.
  *\return TRUE si todo los datos son correctos y FALSE si encontro un error.
**/
int isValidEmail(char str[])
{
    int retorno = TRUE;
    int i=0;
    int contadorArroba = 0;
    int contadorGuinBajo = 0;
    int contadorGuionAlto = 0;
    int contadorPuntos = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
           str[i] != '_' && str[i] != '-' && str[i] != '@' &&
           str[i] != '.' && (str[i] < '0' || str[i] > '9'))
        {
            retorno = FALSE;
        }
        if(str[i] == '@' && contadorArroba == 0)
        {
            contadorArroba++;
        }
        if(str[i] == '_' && contadorGuinBajo == 0 && contadorGuionAlto == 0)
        {
            contadorGuinBajo++;
            contadorGuionAlto++;
        }
        if(str[i] == '.')
        {
            contadorPuntos++;
        }
        if(contadorArroba == 2 || contadorGuinBajo == 2 || contadorGuionAlto == 2 || contadorPuntos == 2)
        {
            retorno = FALSE;
        }
        i++;
    }
    if(contadorArroba != 1 && contadorPuntos != 1)
    {
        printf("\nfaltan campos obligatorios");
        retorno = FALSE;
    }
    return retorno;

}
/**
  *\brief Pide un dato eMail al usuario, validando los datos.
  *\param Un mensaje al usuario, un mensaje en caso de error.
  *\param Un minimo y un maximo de caracteres y el puntero donde guardar el dato.
**/
void getEmail(char *msg,char *msgError,int minimo,int maximo,char *resultado)
{
    int flag = 1;
    char buffer[4096];
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       resultado != NULL)
    {
        do {
            printf("\n(solo puedes ingresar un @(obligatorio) un _ o - y un punto(obligatorio))\n %s",msg);
            if(!getString(minimo,maximo,buffer))
                {
                    if(isValidEmail(buffer))
                    {
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






