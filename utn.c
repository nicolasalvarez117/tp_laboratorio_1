#include <stdio.h>
#include <stdlib.h>

/**
  *\brief suma los numeros ingresados y obtiene un resultado.
  *\param los numeros ingresados por el usuario.
  *\return retorna el resultado de la operacion.
  */

int add(int numeroUno, int numeroDos)
{
   return numeroUno + numeroDos;
}

/**
  *\brief  multiplica dos numeros ingresados y obtiene un resultado.
  *\param los numeros ingresados por el usuario.
  *\return retorna el resultado de la operacion.
  */

int multiply(int numeroUno, int numeroDos)
{
  return numeroUno*numeroDos;
}

/**
  *\brief El primer numero lo va a restar por el segundo y va a obtener un resultado.
  *\param los numeros ingresados por el usuario.
  *\return retorna el resultado de la operacion.
  */

int subtract(int numeroUno, int numeroDos)
{
  return numeroUno-numeroDos;
}

/**
  *\brief El primer numero lo va a dividir por el segundo y va a obtener un resultado.
  *\param los numeros ingresados por el usuario.
  *\return retorna el resultado de la operacion.
  */

float divide(float numeroUno, float numeroDos)
{
  if(numeroDos != 0)
  return numeroUno / numeroDos;
  return 0;
}

/**
  *\brief obtiene el factorial del numero ingresado
  *\param el numero para realizar el factorial.
  *\return retorna el resultado.
*/

int factorial(int numeroUno)
{
    int i;
    int resultado = 1;
    for(i=numeroUno;i>1;i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}
