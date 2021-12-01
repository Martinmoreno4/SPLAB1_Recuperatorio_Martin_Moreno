#include "LinkedList.h"
#include "Emergencias.h"
#include "parser.h"
#include "Rubro.h"

int loadFromText(char* path , LinkedList* pArrayListEmergencia);
int ListEmergencias(LinkedList* pArrayListEmergencia, eRubro rubros[] ,int tam);
int sortEmergencia(LinkedList* pArrayListEmergencia);
int saveAsText(char* path , LinkedList* pArrayListEmergencia);

void* bajaRecursosBomberos(void* elemento);
void* aleatorioRating(void* elemento);
