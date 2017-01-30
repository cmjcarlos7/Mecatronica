/** Practica uno de la asignatura Tiempo Real para Sistemas Mecatronicos
**  Enunciado en una imagen llamada "Enunciado.JPG"
**  Autor: Juan Carlos Contreras Márquez
**  Fecha: 27-Eneno-2017
**  Estandar: C90
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Para comparar caracteres */
#include <time.h> /* Para medir tiempos */
#include <math.h> /* Funciones matematicas */

/* -------------------- Definicion de constantes -------------------- */
 #define NUM_ELEM 100 /* Numero de elementos para medir el Jitter */

/* -------------------- Definicion de tipos --------------------*/
typedef struct {
    long codigo;
    char fabricante [32];
    float precio;
    int disponibilidad;
} Componente;

/* Elemento contiene un Componente y una direcion que apunta a la direcion de memoria siguiente */
typedef struct Elemento{
    Componente componente;
    struct Elemento *sig;
} Elemento;

/* Defino Lista como un puntero que apunta a un elemento componente */
typedef Elemento* Lista;

/* -------------------- Prototipos -------------------- */
Lista lista_Crear (void);
int Menu(void);
void lista_Agregar (Lista *l, const Componente *c);
Componente* lista_Valor(const Lista *l, unsigned pos);
Componente tomar_Datos_Componente (void);
void lista_Extraer (Lista *l);
void lista_vaciar(Lista *l);

/* -------------------- Main -------------------- */
int main() {
    /* Variables */
    Lista lista;
    int opcion_menu = 0, salir_menu = 0, posicion_mostrar = 0, i;
    Componente componente;
    Componente *componente_posicion_x;
    double ListaElem[NUM_ELEM], jitter;
    clock_t start, end; /* Variables para medir el tiempo */

    /* Inicio la lista vacia */
    lista = lista_Crear();  /* lista es un puntero al primer elemento de la lista */
    /* Creo el menu */
	while (salir_menu==0)
	{
		opcion_menu	= Menu();
		printf("Tu opcion es %d\n", opcion_menu);
		switch (opcion_menu)
		{
            /* Agregar un componente*/
			case 1: {
                /* Pido componente a agregar */
                printf("Introduce el codigo del componente \n");
                scanf("%ld", &componente.codigo);
                printf("Introduce el fabricante: \n");
                scanf("%s",&componente.fabricante);
                printf("Introduce el precio: \n");
                scanf("%f",&componente.precio);
                printf("Introduce disponibilidad: \n");
                scanf("%d",&componente.disponibilidad);
                lista_Agregar(&lista, &componente);
				break;
			}
            /* Borrar el ultimo componente de la lista */
			case 2: {
                lista_Extraer(&lista);
				break;
			}
            /* Imprime por pantalla el componente enesimo */
			case 3: {
                printf("Que posicion quieres mostrar\n");
                scanf("%d", &posicion_mostrar);
                componente_posicion_x = lista_Valor(&lista, posicion_mostrar);
                /* Compruebo si he obtenido el componente */
                if (componente_posicion_x==NULL) {
                        printf("No se dispone de ningun componente en dicha posicion\n");
                }else{

                    /* Pregunto si quieren cambiarlo o mostrarlo */
                    printf("Pulse 0 para cambiarlo o otro numero para mostrarlo\n");
                    scanf("%d", &posicion_mostrar);
                    if (posicion_mostrar == 0) {
                        /* Modificar el componente */
                        printf("Introduce el nuevo codigo del componente \n");
                        scanf("%ld", &componente_posicion_x->codigo);
                        printf("Introduce el nuevo fabricante: \n");
                        scanf("%s",&componente_posicion_x->fabricante);
                        printf("Introduce el nuevo precio: \n");
                        scanf("%f",&componente_posicion_x->precio);
                        printf("Introduce la nueva disponibilidad: \n");
                        scanf("%d",&componente_posicion_x->disponibilidad);
                    }else{
                        /* Mostrar el componente */
                        printf("Codigo= %ld \n",componente_posicion_x->codigo);
                        printf("Fabricante= %s \n",componente_posicion_x->fabricante);
                        printf("Precio= %f \n",componente_posicion_x->precio);
                        printf("Disponibilidad= %d \n",componente_posicion_x->disponibilidad);
                    }
                }

				break;
			}
            /* Vaciar completamente la lista */
			case 4: {
                lista_vaciar(&lista);
                printf("Lista vaciada \n");
				break;
			}
            /* Rellenar la lista con 100 elementos y medir el jitter */
			case 5: {
                for (i=0;i<NUM_ELEM;i++){
                    start = clock(); /* Se guarda el tiempo en el que empieza a introducir el Componente */
                    /* Se crea un Componente con cualquier contenido */
                    componente.codigo=12345;
                    strcpy(componente.fabricante, "fabricante");
                    componente.precio=20.5;
                    componente.disponibilidad=1;
                    //Se agrega el componenete nuevo
                    lista_Agregar(&lista,&componente);
                    end = clock(); /* Se guarda el tiempo en el que termina de introducir el Componente */
                    /* Se calcula la diferencia de tiempo entre el final y el principio (en milisegundos) y lo introduce en un vector */
                    ListaElem[i] = ((double) (end-start))/CLOCKS_PER_SEC * 1000;
                }
                //jitter = stdev(ListaElem, NUM_ELEM); /* Se realiza la desviacion estandar de todos los tiempos, con lo que se obtiene el Jitter */
                printf("\n%d elementos anadidos\n",NUM_ELEM);
                printf("El Jitter es de %f (ms)\n", jitter);
				break;
			}
			case 6: {
                salir_menu = 1;	/* Se sale del bucle y, por tanto, del programa */
                printf("Fin del programa\n");
            break;
				break;
			}
			default:
			{
				printf("El valor introducido no es correcto.\n\n");
			}
	}
}
    return 0;
}

/* -------------------- Funciones -------------------- */
/*	Funcion para crear el Menu	*/
int Menu(void)
{
    int opcion;
    printf("\n 1. Agregar componente a la lista\n");
    printf("2. Borrar ultimo componente de la lista\n");
    printf("3. Imprimir en pantalla el componente enesimo (Permite modificar) \n");
    printf("4. Vaciar completamente la lista\n");
    printf("5. Rellenar con 100 elementos\n");
    printf("6. Salir\n");
    printf("Introduce tu opcion: ");
    scanf("%d", &opcion);
    return	(opcion);
}
/* Funcion que inicializa la lista vacia */
Lista lista_Crear (void){
    return (NULL); /* Devuelve NULL para indicar que la lista esta vacia */
}
/* Agrega un componente a la lista */
void lista_Agregar (Lista *l, const Componente *c){
    Elemento *elem, *aux;
    /* Se reserva espacio en la memoria dinamica para el nuevo elemento */
    elem = malloc(sizeof(Elemento));
    elem -> componente.codigo = c->codigo;
    strcpy(elem->componente.fabricante, c->fabricante);
    elem->componente.precio = c->precio;
    elem->componente.disponibilidad = c->disponibilidad;
    elem->sig = NULL; /* Como va a ser el ultimo elemento, apunto a null */
    if(*l == NULL){
        /* Si la lista estaba vacia, l apunta al elemento creado */
        *l=elem;
    }else {
        /* Si la lista no esta vacia, tengo que recorrerla hasta encontrar el ultimo elemento */
        aux = *l;
        while (aux->sig!=NULL) {
            aux = aux->sig;
        }
        /* Una vez encontrado el ultimo elemento, guardo su puntero hacia el nuevo elemento creado */
        aux->sig = elem;
    }
}

/* Funcion que recorre la lista buscando un componente */
Componente* lista_Valor(const Lista *l, unsigned pos){
    int i, encontrado = 0;
    Elemento *a;
    if (*l==NULL) {
        printf("La lista esta vacia ");
        return NULL;
    }else{
        a = *l;
        /* recorro la lista hasta la posicion pos */
        for (i = 0; (i < pos) || (encontrado==1); i++) {
            if (a->sig==NULL) {
                return NULL;
            }else{
                a = a->sig;
            }
        }
        return a;
    }
}

/* Funcion que borra el ultimo elemento de la lista */
void lista_Extraer (Lista *l){
    Elemento *a,*b;
    /* Compruebo si la lista ya esta vacia */
    if (*l==NULL) {
        printf("No se puede borrar, la lista esta vacia \n");
    }else{
        a= *l;
        if (a->sig==NULL) {
            /* Caso de solo tener un componente */
            printf("La lista no esta vacia, solo contiene 1 elemento \n");
            *l=NULL;
            free(a);
            printf("Ultimo componente eliminado\n");
        }else{
            /* Busco el ultimo componente */
            while (a->sig!=NULL) {
                b = a;
                a = a->sig;
            }
            /* Cuando lo encuentro libero la memoria */
            free(a);
            b->sig = NULL;
            printf("Ultimo componente eliminado\n");
        }
    }
}

/* Funcion que borra la lista completa */
void lista_vaciar(Lista *l){
    Elemento *a,*b;
    /* Compruebo si la lista esta vacia */
    if (*l==NULL) {
        printf("La lista ya esta vacia \n");
    }else{
        a=*l;
        b=a->sig;
        free(a);
        while(b!=NULL){
            a=b;
            b=b->sig;
            free(a);
        }
        /* Libero el ultimo componente */
        free(b);

        *l=NULL;
    }
}

/* Funcion que calcula la desviacion estandar (jitter) de un vector
** Se aplica la formula de la desviacion estandar */
double stdev(double data[], int size){
    float sum = 0.0, mean, stdv = 0.0;
    int i;
   for (i=0; i<size; i++){
       sum += data[i]; /* Sumatorio de todos los elementos */
   }
   mean = sum/size; /* Calculo de la media */
   for (i=0; i<size; i++){
       stdv += pow(data[i] - mean, 2); /* Formula de la desviacion estandar */
   }
   return (sqrt(stdv/size));
 }
