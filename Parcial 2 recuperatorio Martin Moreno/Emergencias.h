#ifndef EMERGENCIAS_H_INCLUDED
#define EMERGENCIAS_H_INCLUDED
#include "Rubro.h"
typedef struct
{
    int id;
    char descripcion[128];
    char domicilio[128];
    int recursos;
    int rubroId;
}eEmergencia;


void mostrarEmergencia(eEmergencia* emergencia, eRubro rubros[], int tam);

int emergencia_setId(eEmergencia* this,int id);
int emergencia_getId(eEmergencia* this,int* id);

int emergencia_setDescripcion(eEmergencia* this,char* descripcion);
int emergencia_getDescripcion(eEmergencia* this,char* descripcion);

int emergencia_setDomicilio(eEmergencia* this,char* domicilio);
int emergencia_getDomicilio(eEmergencia* this,char* domicilio);

int emergencia_setRecursos(eEmergencia* this,int recursos);
int emergencia_getRecursos(eEmergencia* this,int* recursos);

int emergencia_setRubroId(eEmergencia* this,int rubroId);
int emergencia_getRubroId(eEmergencia* this,int* rubroId);



int emergenciaSortByDescripcion(void* emergA, void* emergB);

int filterRecursos(void* e);
int filterRubros(void* e);

eEmergencia* newEmergencia();
eEmergencia* newEmergenciaParam(int id, char* descripcion, char* domicilio, int recursos, int rubroId);

#endif // EMERGENCIAS_H_INCLUDED
