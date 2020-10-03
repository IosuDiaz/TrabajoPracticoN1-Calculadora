/** \brief shows the menu
 *
 * \return int Return the selected option
 *
 */
int Menu();

/** \brief generates an Id automatically
 *
 * \param void
 * \return int
 *
 */
int CalculateEmployeeId(void);


void getString(char [],char input[]);
float getFloat(char* );
int getInt(char* mensaje);



int isOnlyLetters(char str[]);
int isNumericFloat(char str[]);
int isNumeric(char *str);

int getStringNumericFloat(char message[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
