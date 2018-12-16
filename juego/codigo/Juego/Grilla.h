#ifndef Grilla
#define Grilla

#include <SDL2/SDL.h>
#include "Interfaz.h"
#include "Dinamica.h"


const int TAMAÑO_TABLERO        =25; 
const int TAMAÑO_VENTANA      =600;
const int TAMAÑO_CELULAS        = TAMAÑO_VENTANA/TAMAÑO_TABLERO;
int  contar_vecinos_vivos ( int grid[][TAMAÑO_TABLERO], int size, int x, int y );
void actualizar_celula             ( int grid[][TAMAÑO_TABLERO], int size, int x, int y,
                              int num_vecinos );
void set_celula                ( int grid[][TAMAÑO_TABLERO], int size, int x, int y,
                              int val );

void set_celula( int grid[][TAMAÑO_TABLERO], int size, int x, int y, int val ) {

    if ( x >= 0 && x < size && y>=0 && y< size ) {

        grid[y][x] = val;
    }
}


void step( int grid[][TAMAÑO_TABLERO], int size ) {
    int x, y;
    int counts[TAMAÑO_TABLERO][TAMAÑO_TABLERO];
    

    for(y=0; y<size; y++) {
        for(x=0; x<size; x++) {
            counts[y][x] = contar_vecinos_vivos(grid, size, x,y);
        }
    }
    
    for(y=0; y<TAMAÑO_TABLERO; y++) {
        for(x=0; x<TAMAÑO_TABLERO; x++) {
            actualizar_celula(grid, size, x, y, counts[y][x]);
        }
    }
}

#endif


