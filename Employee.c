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

