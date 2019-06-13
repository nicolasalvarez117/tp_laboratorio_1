#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

/**
  *\brief Pide memoria dinamica del tipo Employee.
  *\return La ubicacion de memoria  o NULL si no encontro memoria disponible.
**/
Employee* employee_new();
/**
  *\brief Crea un elemento del tipo Employe validando y cargando los campos dentro del mismo.
  *\param Los datos que debemos cargar en los campos.
  *\return El puntero al elemento con los datos cargados o NULL si algun dato es incorrecto
**/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();
/**
  *\brief Setea el dato y si es correcto lo guarda en un campo del elemento de tipo employee.
  *\param El dato a guardar y el elemento del tipo employee.
  *\return -1 en caso de error y 0 si todo es correcto.
**/
int employee_setId(Employee* this,int id);
int employee_setNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setSueldo(Employee* this,float sueldo);
/**
  *\brief Retorna un dato del elemento del tipo empleado que se pasa por parametro.
  *\param El elemento de donde obtenemos el dato.
  *\return El dato si todo es correcto.
**/
int employee_getId(Employee* this);
char* employee_getNombre(Employee* this);
int employee_getHorasTrabajadas(Employee* this);
float employee_getSueldo(Employee* this);

/**
  *\brief Edita un campo de la estructura employee.
  *\param El elemento a editar.
**/
void editar_nombre(Employee *this);
void editar_horasTrabajadas(Employee *this);
void editar_sueldo(Employee *this);
void editar_ID(Employee *this);
/**
  *\brief Toma datos desde el teclado guardandolo en una variable del tipo array char.
  *\param El mensaje , el minimo y maximo de caracteres y la ubicacion donde se guarda la cadena.
  *\return -1 en caso de error y 0 si todo es correcto.
**/
int preguntar_datos(char* msg,int minimo,int maximo,char *resultado);
/**
  *\brief Valida una cadena de caracteres.
  *\param La cadena de tipo array char a validar.
  *\return 1 si todo es correcto y 0 si un caracter no es correcto.
**/
int isValidName(char str[]);
int isValidNumber(char strNumber[]);
/**
  *\brief Muestra un Menu  tomando por teclado una opcion ingresada.
  *\return La opcion ingresada si es correcta, -1 si la opcion no existe.
**/
int menuPrincipal(void);
int menuModificacion(void);

#endif // employee_H_INCLUDED
