#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define MESSAGE "\n------------------------------bienvenido a la calculadora TP 1----------------------------------\n"
#define MESSAGE_OPTION "\ningrese \n1: Ingresar 1er operando\n2: Ingresar 2do operando\n3: Calcular todas las operaciones\n4: Informar resultados\n5: salir\n"

int main()
{
   int a;
   int b;
   int result_add;
   int result_divide;
   int result_multiply;
   int result_subtract;
   int result_factorial_1;
   int result_factorial_2;
   int flag = 0;
   int flag_2 = 0;
   int flag_3 = 0;
   char answer = 's';
   int option;

   printf(MESSAGE);
   do{


    printf(MESSAGE_OPTION);
    scanf("%d",&option);

    switch(option)
 {
    case 1:
        printf("\nprimer operando: ");
        scanf("%d",&a);
        flag = 1;
        system("cls");
        break;
    case 2:
        printf("\nsegundo operando: ");
        scanf("%d",&b);
        flag_2 = 1;
        break;
    case 3:
        if(flag == 1 && flag_2 == 1)
        {
          result_add = add(a,b);
          result_multiply = multiply(a,b);
          result_divide = (float)divide(a,b);
          result_subtract = subtract(a,b);
          flag_3 = 1;
          if(a >= 0 && b >= 0)
          {
              result_factorial_1 = factorial(a);
              result_factorial_2 = factorial(b);
          }
          else
            printf("\nno se puede sacar factorial de negativos");
        }
        else if(flag == 1 || flag_2 == 1)
        {
           system("cls");
           printf("\nfalta ingresar un operando");
        }
        else
        {
            system("cls");
            printf("\nfalta ingresar los operandos");
        }
        break;

    case 4:

        if(flag_3 == 1)
        {
        system("cls");
        printf("\nresultado de %d mas %d es: %d\nresultado de %d multiplicado %d es: %d\n",a,b,result_add,a,b,result_multiply);
        printf("resultado de %d menos %d es: %d\nresultado de: %d dividido %d es: %.2f\n",a,b,result_subtract,a,b,(float)result_divide);
        printf("factorial de %d es %d\nfactorial de %d es: %d",a,result_factorial_1,b,result_factorial_2);
        flag = 0;
        flag_2 = 0;
        flag_3 = 0;
        }
        else if(flag_3 == 0)
        {
            system("cls");
            printf("\nfalta realizar las operaciones");
        }

        else if(flag ==1 || flag_2 ==1)
        {
          system("cls");
          printf("\nfalta ingresar un operando");
        }

        else
        {
          system("cls");
          printf("\nfalta ingresar los operandos");
        }
        break;
    case 5:
        system("cls");
        answer = 'n';
        printf("\nhasta luego");
        break;
}}while(answer == 's');
}
