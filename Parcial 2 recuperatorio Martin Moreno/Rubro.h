#ifndef RUBRO_H_INCLUDED
#define RUBRO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eRubro;

int cargarDescripcionRubro(eRubro rubro[], int tam, int idEmergencia, char descripcion[]);
#endif // RUBRO_H_INCLUDED
