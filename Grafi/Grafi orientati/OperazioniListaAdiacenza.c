#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListAdiacenza {
  int key;
  struct ListAdiacenza* next;
};

struct Grafo {
  int numeroVertici;
  struct ListAdiacenza** summit;
};

typedef struct Grafo Grafo;
typedef struct ListAdiacenza ListAdiacenza;

Grafo* creaLista( int vertici, int lati );
void insert( Grafo** graph , int key, int vertice );
void stampaLista( Grafo* graph );
ListAdiacenza* creaNodo( int key );
int visualizzaGrado( Grafo* graph, int vertice );
int verificaAdiacenzaVertici( Grafo* graph, int verticeSrc, int verticeDst );
void aggiuntiVertice( Grafo** graph );
int aggiungiLato( Grafo* graph, int verticeSrc, int verticeDst );
void rimuoviVertice( Grafo** graph, int vertice );

int main( void ) {

  Grafo* graph = NULL;
  int vertice, lato, nodoDestinazione, randomVertice, grado;

  printf( "Inserisci numero vertici : " );
  scanf( "%d", &vertice );
  printf( "Inserisci numero lati : " );
  scanf( "%d", &lato );

  graph = creaLista( vertice, lato );
  srand( time( NULL ) );

  for( int indice = 0; indice < lato; indice++ ) {

    nodoDestinazione = rand() % vertice;
    randomVertice = rand() % vertice;

    insert( &graph , nodoDestinazione, randomVertice );
  }

    puts( "" );
    stampaLista( graph );
    puts( "" );

    printf( "Inserisci  vertice : " );
    scanf( "%d", &vertice );

    rimuoviVertice( &graph, vertice );

    puts( "" );
    stampaLista( graph );
    puts( "" );


  return 0;
}

ListAdiacenza* creaNodo( int key ) {

  ListAdiacenza* newPtr = ( ListAdiacenza* )malloc( sizeof( ListAdiacenza ) );
  newPtr->key = key;
  newPtr->next = NULL;

  return newPtr;
}

Grafo* creaLista( int vertici, int lati ) {

  Grafo* graph = ( Grafo* )malloc( sizeof( Grafo ) );

  graph->numeroVertici = vertici;
  graph->summit = ( ListAdiacenza** )calloc( vertici, sizeof( ListAdiacenza* ) );

  for( int indice = 0; indice < vertici; indice++ ) {
       graph->summit[ indice ] = NULL;
  }

  return graph;
}

void insert( Grafo** graph, int key, int vertice ) {

  ListAdiacenza** list = ( *graph )->summit;
  ListAdiacenza* tempTesta = NULL;
  ListAdiacenza* newPtr = NULL;

  if( list[ vertice ] == NULL ) {
      if( vertice == key ) return;
      list[ vertice ] = creaNodo( key );
  }
  else {
    tempTesta = list[ vertice ];

    while( tempTesta != NULL ) {
      if( tempTesta->key == key || vertice == key ) {
          return;
      }
      tempTesta = tempTesta->next;
    }

    newPtr = creaNodo( key );
    newPtr->next = list[ vertice ];
    list[ vertice ] = newPtr;
  }
}

void stampaLista( Grafo* graph ) {

  ListAdiacenza* vertice = NULL;

  for( int indiceVertice = 0; indiceVertice < graph->numeroVertici; indiceVertice++ ) {
       if( graph->summit[ indiceVertice ] == NULL )
           printf( "Vertice [ %d ] : \n", indiceVertice );
       else {
            vertice = graph->summit[ indiceVertice ];
            printf( "Vertice [ %d ] : ", indiceVertice );
            while( vertice != NULL ) {
                  printf( "%d ", vertice->key );
                  vertice = vertice->next;
            }
            puts( "" );
      }
  }
}

int visualizzaGrado( Grafo* graph, int vertice ) {

  ListAdiacenza* verticeNodo = graph->summit[ vertice ];
  int count = 0;

  while( verticeNodo != NULL ) {
    count = count + 1;
    verticeNodo = verticeNodo->next;
  }
  return count;
}

int verificaAdiacenzaVertici( Grafo* graph, int verticeSrc, int verticeDst ) {

  ListAdiacenza* verticeS = graph->summit[ verticeSrc ];

  while( verticeS != NULL ) {
    if( verticeS->key == verticeDst ) return 1;
    verticeS = verticeS->next;
  }
  return 0;
}

void aggiuntiVertice( Grafo** graph ) {

    ListAdiacenza** grafo = ( *graph )->summit;

    ( *graph )->numeroVertici++;
    grafo = ( ListAdiacenza** )realloc( grafo, ( *graph )->numeroVertici * sizeof( ListAdiacenza* ) );

}

int aggiungiLato( Grafo* graph, int verticeSrc, int verticeDst ) {

    ListAdiacenza* verticeS = graph->summit[ verticeSrc ];
    ListAdiacenza* newPtr = NULL;

    while( verticeS != NULL ) {
      if( verticeS->key == verticeDst ) return 0;
      verticeS = verticeS->next;
    }

    newPtr = creaNodo( verticeDst );
    newPtr->next = graph->summit[ verticeSrc ];
    graph->summit[ verticeSrc ] = newPtr;

    return 1;

}

void rimuoviVertice( Grafo** graph, int vertice ) {

     ( *graph )->summit[ vertice ] = NULL;
     ( *graph )->summit[ vertice ];
     free( ( *graph )->summit[ vertice ] );
}
