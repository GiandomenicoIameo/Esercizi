#include <stdio.h>

int isAtomic( int n );

int main( void ) {

  int n, res;

  do {
      printf( "Inserisci un numero : " );
      scanf( "%d", &n );
  } while( n < 0 );

  res = isAtomic( n );

  if( res )
    puts( "Il numero e' primo" );
  else
    puts( "Il numero non e' primo" );

  return 0;
}

int isAtomic( int n ) {

  // La funzione verifica se n è un numero primo
  // appartenente all'insieme dei numeri naturali oppure no.
  // Complessità algoritmo in termini di tempo : O( n/6 ).
  // Complessità algoritmo in termini di spazio : Θ( 1 ).

  if( n == 2 ) {
      return 1;
  }
  else if( n % 2 == 0 ) {
      return 0;
  }
  if( n == 1 ) {
      return 0;
  }
  int rest;
  int div = 3;

  while( div <= n / 3 ) {
      rest = n % div;
      if( !rest ) {
          return 0;
      }
      div = div + 2;
  }
  return 1;
}
