#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Emergencias.h"
#include "biblioteca.h"
#include "Rubro.h"

void mostrarEmergencia(eEmergencia* emergencia, eRubro rubros[], int tam)
{
    char descRubro[20];
    if(cargarDescripcionRubro(rubros, tam, emergencia->rubroId, descRubro) == 1)
    {
        printf("%4d   %30s     %20s     %d  %15s\n", emergencia->id, emergencia->descripcion, emergencia->domicilio, emergencia->recursos, descRubro);
    }

}



int emergencia_setId(eEmergencia* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id > 0)
    {
        this->id= id;
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_getId(eEmergencia* this,int* id)
{
    int todoOk = 0;
    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_setDescripcion(eEmergencia* this,char* descripcion)
{
    int todoOk = 0;
    if(this!=NULL && descripcion != NULL && strlen(descripcion) > 0)
    {
        strcpy(this->descripcion, descripcion);
        todoOk=1;
    }
    return todoOk;
}

int emergencia_getDescripcion(eEmergencia* this,char* descripcion)
{
    int todoOk = 0;
    if(this!=NULL && descripcion != NULL)
    {
        strcpy(descripcion, this->descripcion);
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_setDomicilio(eEmergencia* this,char* domicilio)
{
    int todoOk = 0;
    if(this!=NULL && domicilio != NULL /*&& strlen(domicilio) > 0 && esAlfaNumerico(domicilio)*/)
    {
        strcpy(this->domicilio, domicilio);
        todoOk=1;
    }
    return todoOk;
}

int emergencia_getDomicilio(eEmergencia* this,char* domicilio)
{
    int todoOk = 0;
    if(this!=NULL && domicilio != NULL)
    {
        strcpy(domicilio, this->domicilio);
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_setRecursos(eEmergencia* this,int recursos)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        this->recursos = recursos;
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_getRecursos(eEmergencia* this,int* recursos)
{
    int todoOk = 0;
    if(this!=NULL && recursos != NULL)
    {
        *recursos = this->recursos;
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_setRubroId(eEmergencia* this,int rubroId)
{
    int todoOk = 0;
    if(this!=NULL && rubroId>0 && rubroId<5)
    {
        this->rubroId = rubroId;
        todoOk= 1;
    }
    return todoOk;
}

int emergencia_getRubroId(eEmergencia* this,int* rubroId)
{
    int todoOk = 0;
    if(this!=NULL && rubroId != NULL)
    {
        *rubroId = this->rubroId;
        todoOk= 1;
    }
    return todoOk;
}

int emergenciaSortByDescripcion(void* emergA, void* emergB)
{
    int retorno = 0;
    char descA[200];
    char descB[200];

    if(emergencia_getDescripcion((eEmergencia*)emergA, descA) &&
        emergencia_getDescripcion((eEmergencia*)emergB, descB))
    {
        retorno = strcmp(descA, descB);
    }

    return retorno;
}

int filterRecursos(void* e)
{
    int ok =0;
    eEmergencia* emr = NULL;

    if(e != NULL)
    {
        emr = (eEmergencia*)e;
        if(emr->recursos >12)
        {
            ok=1;
        }
    }
    return ok;
}

int filterRubros(void* e)
{
    int ok =0;
    eEmergencia* emr = NULL;

    if(e != NULL)
    {
        emr = (eEmergencia*)e;
        if(emr->rubroId ==4)
        {
            ok=1;
        }
    }
    return ok;
}

eEmergencia* newEmergencia()
{
    eEmergencia* nuevaEmerg = (eEmergencia*) malloc(sizeof(eEmergencia));
    if(nuevaEmerg!=NULL)
    {
        nuevaEmerg->id = 0;
        strcpy(nuevaEmerg->descripcion, "Descripcion");
        strcpy(nuevaEmerg->domicilio, "Domicilio");
        nuevaEmerg->recursos = 0;
        nuevaEmerg->rubroId = 0;
    }
    return nuevaEmerg;
}



eEmergencia* newEmergenciaParam(int id, char* descripcion, char* domicilio, int recursos, int rubroId)
{
    eEmergencia* nuevaEmerg = newEmergencia();
    if(nuevaEmerg!=NULL)
    {
        if(!(emergencia_setId(nuevaEmerg, id)
        && emergencia_setDescripcion(nuevaEmerg, descripcion)
        && emergencia_setDomicilio(nuevaEmerg, domicilio)
        && emergencia_setRecursos(nuevaEmerg, recursos)
        && emergencia_setRubroId(nuevaEmerg, rubroId)))
        {
            free(nuevaEmerg);
            nuevaEmerg = NULL;

        }
    }
    return nuevaEmerg;
}
