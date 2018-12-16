#ifndef Dinamica
#define Dinamica

#include <SDL2/SDL.h>
#include "Interfaz.h"
#include "Grilla.h"

const int CELULA_VIVA        = 1;
const int CELULA_MUERTA       = 0;
const int NUM_REPRODUCCION    = 3;
const int NUM_SOBREPOBLACION = 3;
const int NUM_SOLEDAD   = 2;




void init_grid( int grid[][TAMAÑO_TABLERO], int size ) {
    int x,y;
    
  
    for( y=0; y<size; y++ ) {
        for( x=0; x<size; x++ ) {
            grid[y][x] = CELULA_MUERTA;
        }
    }
}


int contar_vecinos_vivos( int grid[][TAMAÑO_TABLERO], int size, int x, int y ) {
    int i,j;
    int count;
    
 
    count = 0;
    for(i=y-1; i<=y+1; i++) {
        for(j=x-1; j<=x+1; j++) {
    
            if( i >= 0 && j >= 0 && i < size && j < size) {
                
                if( grid[i][j] == CELULA_VIVA ) {
                    count++;
                }
            }
        }
    }
    

    if( grid[y][x] != CELULA_MUERTA) {
        count--;
    }
    
    return count;
}


void actualizar_celula(int grid[][TAMAÑO_TABLERO], int size, int x, int y,
                 int num_vecinos) {
    if( num_vecinos == NUM_REPRODUCCION ) {

        grid[y][x] = CELULA_VIVA;
    } else if (num_vecinos > NUM_SOBREPOBLACION
               || num_vecinos < NUM_SOLEDAD) {

        grid[y][x] = CELULA_MUERTA;
    }
}

#endif
