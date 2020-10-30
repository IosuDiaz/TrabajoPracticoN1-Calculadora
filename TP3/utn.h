#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void getString(char [],char input[]);
float getFloat(char* );
int getInt(char* mensaje);

char getChar(char* mensaje);

int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);
int esNumerico(char *str);

int getStringNumericFloat(char message[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

int CalculateId(int);
#endif // UTN_H_INCLUDED
