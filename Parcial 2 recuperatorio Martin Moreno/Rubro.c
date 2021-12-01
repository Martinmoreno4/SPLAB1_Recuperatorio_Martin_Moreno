#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rubro.h"

int cargarDescripcionRubro(eRubro rubro[], int tam, int idEmergencia, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(rubro != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(rubro[i].id == idEmergencia)
            {
                strcpy(descripcion, rubro[i].descripcion);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
