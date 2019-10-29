#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        getValidInt("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n Elija una opcion: ","Error",1,10,&option);

        switch(option)
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados)==0)
            {
                printf("Cargado exitosamente en Texto\n");
            }

            break;
        case 2:
            if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
            {
                printf("Cargado exitosamente en Binario\n");
            }
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:

            break;
        case 5:
            break;
        case 6:
            if(controller_ListEmployee(listaEmpleados)==0)
            {
                printf("Listado realizado con Exito\n");
            }
            break;
        case 7:
            break;
        case 8:
            if(controller_saveAsText("data.csv",listaEmpleados)==0)
            {
                printf("Ha sido guardado Exitosamente");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data.bin",listaEmpleados)==0)
            {
                printf("Ha sido guardado Exitosamente");
            }
            break;
        case 10:
            break;

        }

    }
    while(option != 10);
    return 0;
}
