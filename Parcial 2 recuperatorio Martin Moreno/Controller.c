#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controller.h"

int loadFromText(char* path , LinkedList* pArrayListEmergencia)
{
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmergencia != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_EmergenciaDeTexto(pFile, pArrayListEmergencia))
            {
                todoOk = 1;
            }
            fclose(pFile);
        }
    }

    return todoOk;
}




int ListEmergencias(LinkedList* pArrayListEmergencia, eRubro rubros[] ,int tam)
{
    int todoOk=0;
    int tamL = ll_len(pArrayListEmergencia);
    eEmergencia* auxEmerg=NULL;
    if(pArrayListEmergencia != NULL)
    {

        printf("  id                   Descripcion                Domicilio   Recursos        Rubro\n");
        for(int i=0; i<tamL; i++)
        {
            auxEmerg = (eEmergencia*) ll_get(pArrayListEmergencia, i);
            if(auxEmerg!= NULL)
            {
                todoOk=1;
                mostrarEmergencia(auxEmerg, rubros, tam);
            }
        }
    }
    return todoOk;
}

int sortEmergencia(LinkedList* pArrayListEmergencia)
{
    int todoOk=0;
    int tam = ll_len(pArrayListEmergencia);
    eEmergencia* auxEmerg=NULL;
    if(pArrayListEmergencia != NULL)
    {
        todoOk=1;
        printf("  id     Descripcion   Domicilio   Recursos  Rubro\n");
        for(int i=0; i<tam; i++)
        {
            auxEmerg=(eEmergencia*) ll_get(pArrayListEmergencia, i);
            if(auxEmerg!= NULL)
            {
                //mostrarEmergencia(auxEmerg);
            }
        }
    }
    return todoOk;
}

int saveAsText(char* path , LinkedList* pArrayListEmergencia)
{
    int len = ll_len(pArrayListEmergencia);
    int error = 0;
    if(path != NULL && pArrayListEmergencia != NULL)
    {
        FILE* fp = fopen(path,"w");
        eEmergencia* auxEmerg;
        if(fp!=NULL)
        {
            for(int i=0; i<len; i++)
            {
                auxEmerg = (eEmergencia*) ll_get(pArrayListEmergencia,i);
                if(auxEmerg!=NULL)
                {
                    fprintf(fp,"%d,%s,%s,%d,%d\n", auxEmerg->id, auxEmerg->descripcion, auxEmerg->domicilio, auxEmerg->recursos, auxEmerg->rubroId);
                }
            }
            error =1;
        }
        else
        {
            printf("no se pudo leer el archivo\n");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    }


    return error;
}

void* bajaRecursosBomberos(void* elemento)
{
    eEmergencia* e=(eEmergencia*) elemento;

    if(e->rubroId==1 && e->recursos>=15)
    {
        int i = e->recursos-2;
        e->recursos=i;
    }

    return elemento;
}

void* aleatorioRating(void* elemento)
{
    eEmergencia* e=(eEmergencia*) elemento;
    if(e->rubroId==4 && e->recursos<=20)
    {
        int i = e->recursos-1;
        e->recursos=i;
    }

    return elemento;
}
