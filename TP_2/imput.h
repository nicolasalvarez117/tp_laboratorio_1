int getString(int minimo,int maximo,char *resultado);
void getName(char *msg,char *msgError,int minimo,int maximo,char *resultado);
int isValidName(char str[]);
void getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,char *resultado);
int isValidNumber(char strNumber[]);
int isValidRange(int desde,int hasta,int numero);
void getSexo(char *msg,char *msgError,char* resultado);
int getDni(char* msg,char* msgError,int minimo,int maximo,char* resultado);
int isValidDni(char str[]);
int getCuit(    char* msg,
                char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado);
int isValidCuitA(char str[]);
int isValidCuitB(char str[]);





