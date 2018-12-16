#include <iostream>
#include <SDL2/SDL.h>
#include "Interfaz.h"

using namespace std;




const int ANIMATION_RATE   = 300;



int main() {
    Uint32 ticks;
    

    int grid[TAMAÑO_TABLERO][TAMAÑO_TABLERO];
    
    if(!inicializar_pantalla()) {
        return 1;
    }
    
    init_grid( grid, TAMAÑO_TABLERO );
    

    ticks = SDL_GetTicks();
    
    while(!g_user_quit) {
        manejar_eventos( grid, TAMAÑO_TABLERO );
        
        mostrar_tablero( grid, TAMAÑO_TABLERO );
        
        if(g_animating && (SDL_GetTicks() - ticks) > ANIMATION_RATE ) {
            step( grid, TAMAÑO_TABLERO );
            ticks = SDL_GetTicks();
        }
        
    }
    
    cerrar_pantalla();
    return 0;
}




