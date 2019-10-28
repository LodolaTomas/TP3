#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int state=1;//1 sino pudo abrir el archivo
    FILE* pArchive=fopen(path,"r");

    if(pArchive!=NULL)
    {
        state=parser_EmployeeFromText(pArchive,pArrayListEmployee);//=-1 si pArrayList es NULL
        //=0 si fue exitoso
    }
    return state;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int state=-1;
    FILE* pArchivo=fopen(path,"rb");

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        state=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    }

    return state;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int state=-1;
    Employee* this=employee_new();

    int id;
    char nombre[50];
    int horasTrabajadas;
    int salario;

    if(pArrayListEmployee!=NULL && this!=NULL)
    {
        getValidInt("Ingrese ID: ","Error, solo Numeros",0,10000,&id);
        employee_setId(this,id);
        getValidName("Ingrese Nombre: ","Error, Solo Letras",0,49,nombre);
        employee_setNombre(this,nombre);
        getValidInt("Ingrese Horas Trabajadas: ","Error, Solo Numeros",0,100,&horasTrabajadas);
        employee_setHorasTrabajadas(this,horasTrabajadas);
        getValidInt("Ingrese Salario: ","Error, Solo Numeros",0,10000,&salario);
        employee_setSueldo(this,salario);
        printf("**************************************************************************************\n");
        controller_ShowOneEmployee(this);
        printf("**************************************************************************************\n");
        state=1;
        if(verifyConformity("Esta seguro de guardar este Empleado?[Si/No]","Error, [Si/No]")==1)
        {
            ll_add(pArrayListEmployee,this);
            state=0;
        }
    }
    return state;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int state=-1;
    int i;
    Employee* this;

    if(pArrayListEmployee!=NULL)
    {
        printf("%5s %15s %15s %15s\n","ID","NOMBRE","HORAS","SUELDO");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this=ll_get(pArrayListEmployee,i);//Obtengo un Empleado segun id y lo muestro
            controller_ShowOneEmployee(this);
        }
        state=0;
    }
    return state;
}

void controller_ShowOneEmployee(Employee* this)
{
    printf("%5d %15s %15d %15d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int state=-1;
    int i;
    Employee* this=NULL;
    FILE* pArchivo=fopen(path,"w");

    int id;
    char nombre[50];
    int horasTrabajadas;
    int salario;

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        fprintf(pArchivo,"id,nombre,horasTrabajadas,Salario\n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this=ll_get(pArrayListEmployee,i);
            employee_getId(this,&id);
            employee_getNombre(this,nombre);
            employee_getHorasTrabajadas(this,&horasTrabajadas);
            employee_getSueldo(this,&salario);
            fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,salario);
        }
        state=0;
        fclose(pArchivo);
    }
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int state=-1;
    int i;
    Employee* this=NULL;
    FILE* pArchivo=fopen(path,"wb");//abro el archivo en modo write binary

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)//Verifico que nada sea NULL
    {

        for(i=0; i<ll_len(pArrayListEmployee); i++) //Recorro el Array de empleados
        {
            this=ll_get(pArrayListEmployee,i);//obtengo el empleado en la posicion i
            fwrite(this,sizeof(Employee),1,pArchivo);//y lo escribo en el archivo
        }
        state=0;
        fclose(pArchivo);//Cierro el archivo
    }

    return state;
}

