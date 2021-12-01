#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Emergencias.h"
#define TAM_R 4
int menu();

int main()
{
    srand (time(NULL));
    int seIngresaronDatos = 0;
    int serviciosConMasRecursos=0;
    int serviciosRubroMedica=0;
    char seguir = 's';
    char nombre[128];
    char confirma;

    eRubro rubros[TAM_R]=
    {
       {1, "BOMBEROS"},
       {2, "DEFENSA CIVIL"},
       {3, "POLICIA"},
       {4, "EMERGENCIA MEDICA"}
    };

    LinkedList* listaEmergencias = ll_newLinkedList();
    LinkedList* listaEmergenciasAux = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                printf("Ingrese nombre de archivo a cargar (Datos_LABO1.csv es el nombre standar, el otro es mapeado.csv): ");
                scanf("%s", nombre);
                if(!loadFromText(nombre,listaEmergencias))
                {
                    printf("Problema al cargar las Emergencias\n");
                }
                else
                {
                    printf("Emergencias cargadas correctamente\n");
                    seIngresaronDatos=1;
                }
                break;

            case 2:
                if(seIngresaronDatos==0)
                {
                    printf("ingrese primero los datos\n");
                }
                else
                {
                    ll_sort(listaEmergencias, emergenciaSortByDescripcion, 1);
                }
                break;

            case 3:
                system("cls");
                if(!ListEmergencias(listaEmergencias, rubros, TAM_R))
                {
                    printf("Problema al mostrar las Emergencias\n");
                }
                else
                {
                    printf("\n Emergencias listadas correctamente\n");
                }
                break;

            case 4:
                if(seIngresaronDatos==0)
                {
                    printf("ingrese primero los datos\n");
                }
                else
                {
                    listaEmergenciasAux=ll_map(listaEmergencias, bajaRecursosBomberos);
                    listaEmergenciasAux=ll_map(listaEmergencias, aleatorioRating);
                    if(listaEmergenciasAux!=NULL)
                    {
                        listaEmergencias = listaEmergenciasAux;
                        printf("\n Emergencias mapeadas correctamente\n");
                    }
                    else
                    {
                        printf("\n Error al mapear emergencias\n");
                    }
                }
                break;

            case 5:
                if(saveAsText("mapeado.csv",listaEmergencias))
                {
                    printf("datos cargados al archivo de texto\n");
                }else
                {
                    printf("error al cargar al archivo\n");
                }
                break;

            case 6:
                if(seIngresaronDatos==0 )
                {
                    printf("caragar datos\n");
                }else
                {
                    serviciosConMasRecursos=ll_count(listaEmergencias, filterRecursos);
                    serviciosRubroMedica=ll_count(listaEmergencias, filterRubros);
                    printf("La cantidad de servicios con 12 o mas recursos es: %d\n", serviciosConMasRecursos);
                    printf("La cantidad de servicios con Rubro de emergencia medica es: %d\n",serviciosRubroMedica);
                }
                break;

            case 7:
                printf("Confirma salida?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
            default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("*** Menu ***\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Ordenar lista\n");
    printf("3. Imprimir lista\n");
    printf("4. Realizar baja de recursos\n");
    printf("5. Generar el archivo de salida\n");
    printf("6. Informe de Servicios de Emergencia\n");
    printf("7. Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
