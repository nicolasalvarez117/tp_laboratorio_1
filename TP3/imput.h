/**----------------TOMAR UN STRING----------------------------------------**/
int getString(int minimo,int maximo,char *resultado);
void getName(char *msg,char *msgError,int minimo,int maximo,char *resultado);
void getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,char *resultado);
int getDni(char* msg,char* msgError,int minimo,int maximo,char* resultado);
int getCuit(    char* msg,
                char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado);
void getSexo(char *msg,char *msgError,char* resultado);
void getEmail(char *msg,char *msgError,int minimo,int maximo,char *resultado);

/**----------------VALIDACIONES DE DATOS----------------------------------**/
int isValidNumber(char strNumber[]);
int isValidRange(int desde,int hasta,int numero);
int isValidDni(char str[]);
int isValidName(char str[]);
int isValidCuitA(char str[]);
int isValidCuitB(char str[]);
int isValidEmail(char str[]);





