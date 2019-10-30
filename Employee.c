#include "Employee.h"

Employee* employee_new()
{
    Employee* oneEmployee;

    oneEmployee=(void*)malloc(sizeof(Employee));

    return oneEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* p=employee_new();

    if(p!=NULL)
    {
        employee_setId(p,atoi(idStr));
        employee_setNombre(p,nombreStr);
        employee_setHorasTrabajadas(p,atoi(horasTrabajadasStr));
        employee_setSueldo(p,atof(sueldoStr));

    }
    return  p;
}
void employee_delete(Employee* this)
{
    free(this);
    this=NULL;
}

int employee_setId(Employee* this,int id)
{
    int state=-1;
    if(this!=NULL)
    {
        this->id=id;
        state=0;
    }
    return state;
}

int employee_getId(Employee* this,int* id)
{
    int state=-1;
    if(this!=NULL && *id>0)
    {
        *id=this->id;
        state=0;
    }
    return state;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int state=-1;
    if(this!=NULL && nombre[0]!='\0')
    {
        strcpy(this->nombre,nombre);
        state=0;
    }
    return state;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int state=-1;
    if(this!=NULL && nombre[0]!='\0')
    {
        strcpy(nombre,this->nombre);
        state=0;
    }
    return state;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int state=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        state=0;
    }
    return state;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int state=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        state=0;
    }
    return state;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int state=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        state=0;
    }
    return state;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int state=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        state=0;
    }
    return state;
}
void employee_ShowOneEmployee(Employee* this)
{
    if(this!=NULL)
    {
        printf("%5d %15s %15d %15.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
}

int employee_ModifyEmployee(Employee* this)
{
    int state=1;
    Employee auxEmployee;
    int option;
    if(this!=NULL)
    {
        auxEmployee=*this;//Obtengo una copia del Empleado
        borrar();
        do
        {
            printf("%30s\n","MODIFICAR");
            employee_showEmployee(auxEmployee);//Muestro el Empleado
            getValidInt("1. Nombre\n2. Horas Trabajadas\n3. Sueldo\n4. Salir\nElija una opcion: ","Error, solo numeros",1,4,&option);
            switch(option)
            {
            case 1:
                getValidString("Ingrese el nuevo Nombre: ","Error, solo letras",0,50,auxEmployee.nombre);
                break;
            case 2:
                getValidInt("Ingrese nuevas Horas Trabajadas: ","Error, solo Numeros",0,100,&auxEmployee.horasTrabajadas);
                break;
            case 3:
                getValidFloat("Ingrese nuevo salario: ","Error, solo Numeros",0,100000,&auxEmployee.sueldo);
                break;
            case 4:
                borrar();
                employee_showEmployee(auxEmployee);
                if(verifyConformity("Esta seguro de guardar los cambios?[Si/No]: ","Error, [Si/No]")==1)//pregunto si la modificacion es correcta
                {
                    state=2;// retorno 2 si lo modifico
                    *this=auxEmployee;
                }
                break;
            }
            borrar();
        }
        while(option!=4);
    }
    return state;
}

void employee_showEmployee(Employee oneEmployee)
{
    printf("****************************************************\n");
    printf("%5s %15s %15s %15s\n","ID","NOMBRE","HORAS","SUELDO");
    printf("%5d %15s %15d %15.2f\n",oneEmployee.id,oneEmployee.nombre,oneEmployee.horasTrabajadas,oneEmployee.sueldo);
    printf("****************************************************\n");
}
/*
int option;
    Employee* this=NULL;
    Employee oneEmployee;

    if(pArrayListEmployee!=NULL)
    {
        //len=ll_len(pArrayListEmployee);
        state=0;
        controller_ListEmployee(pArrayListEmployee);
        getValidInt("Elija un Empleado: ","Error, Solo ID de Empleados",0,100000,&option);
        this=(Employee*)ll_get(pArrayListEmployee,option-1);
        if(this!=NULL)
        {
            borrar();
            option=0;
            state=1;
            do
            {
                printf("%30s\n","MODIFICAR");
                printf("***********************************************************************\n");
                controller_ShowOneEmployee(this);
                printf("***********************************************************************\n");
                getValidInt("1. Nombre\n2. Horas Trabajadas\n3. Sueldo\n4. Salir\nElija una opcion: ","Error, solo numeros",1,4,&option);

                switch(option)
                {
                case 1:
                    getValidString("Ingrese el nuevo Nombre: ","Error, solo letras",0,50,this->nombre);
                    break;
                case 2:
                    getValidInt("Ingrese nuevas Horas Trabajadas: ","Error, solo Numeros",0,100,&this->horasTrabajadas);
                    break;
                case 3:
                    getValidFloat("Ingrese nuevo salario: ","Error, solo Numeros",0,100000,&this->sueldo);
                    break;
                case 4:

                    break;
                }
            borrar();
            }
            while(option!=4);
        }

    }
*/



