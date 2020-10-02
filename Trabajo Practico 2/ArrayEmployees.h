#define TRUE 1
#define FALSE 0

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee listOfEmployees[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoutfree space] - (0) if Ok
*/
int addEmployee(Employee listOfEmployees[], int len, int id, char name[],char lastName[],float salary,int sector);

void CreateAnEmployee(Employee [], int len);
int SearchForAvailableSpace(Employee [], int);
void ModifyAnEmployeeById(Employee [], int);
void ShowListOfEmployees(Employee [], int);
void ShowAnEmployee(Employee);



/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee listOfEmployees[], int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee listOfEmployees[], int len, int id);

void SelectEmployeeToRemove(Employee listOfEmployees[], int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee listOfEmployees[], int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee listOfEmployees[], int len);

float averageSalary(Employee listOfEmployees[], int len);
int sumOfSalaries(Employee listOfEmployees[], int len);
int amountOfPaychecks(Employee listOfEmployees[], int len);
int amountOfPayChecksAboveTheAverage(Employee listOfEmployees[], int len);
void informDataOfPaychecks(Employee listOfEmployees[], int len);


