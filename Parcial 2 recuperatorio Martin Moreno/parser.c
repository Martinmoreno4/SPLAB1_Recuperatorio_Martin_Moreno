#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Emergencias.h"

int parser_EmergenciaDeTexto(FILE* pFile , LinkedList* arrayListEmergencia)
{
    char buffer[5][128];
    int len;
    eEmergencia* auxEmerg;
    int i;
    len = ll_len(arrayListEmergencia);
    int cant;
    int todoOk=-1;

    if(pFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

        if(cant == 5)
        {
            auxEmerg = newEmergenciaParam(atoi(buffer[0]),buffer[1],buffer[2],atoi(buffer[3]),atoi(buffer[4]));
            ll_add(arrayListEmergencia, auxEmerg);
            i++;
            todoOk=1;
        }
        else
        {
            break;
        }

    }while( !feof(pFile) && i>len);

    fclose(pFile);

    printf("\n%d ",ll_len(arrayListEmergencia));

    return todoOk;
}
