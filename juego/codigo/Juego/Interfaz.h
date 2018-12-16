#ifndef Interfaz
#define Interfaz

#include <SDL2/SDL.h>
#include "Dinamica.h"
#include "Grilla.h"




SDL_Renderer *g_renderer = NULL;
SDL_Window   *g_window   = NULL;

bool g_animating = false;
bool g_user_quit = false;


void init_grid               ( int grid[][TAMAÑO_TABLERO], int size );

void step                    ( int grid[][TAMAÑO_TABLERO], int size );

bool inicializar_pantalla     ( );
void mostrar_tablero           ( int grid[][TAMAÑO_TABLERO], int size );
void manejar_eventos           ( int grid[][TAMAÑO_TABLERO], int size );
void cerrar_pantalla       ( );

bool inicializar_pantalla() {
    
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "inicializar_pantalla- SDL_Init: %s\n",
                     SDL_GetError()
                     );
        return false;
    }
    
    
    if( SDL_CreateWindowAndRenderer( TAMAÑO_VENTANA+5, TAMAÑO_VENTANA+5, SDL_WINDOW_RESIZABLE,
                                    &g_window, &g_renderer ) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "inicializar_pantalla- SDL_CreateWindowAndRenderer - %s\n",
                     SDL_GetError()
                     );
        return false;
    }
    
    return true;
}

void mostrar_tablero( int grid[][TAMAÑO_TABLERO], int size ) {
    
    
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    
    SDL_RenderClear(g_renderer);
    
    
    SDL_SetRenderDrawColor(g_renderer, 250, 250, 250, SDL_ALPHA_OPAQUE);
    
    
    for(int i=0; i<=size; i++) {
        SDL_RenderDrawLine(g_renderer,0, TAMAÑO_CELULAS*i,TAMAÑO_VENTANA, TAMAÑO_CELULAS*i);
    }
    
    
    for(int i=0; i<=size; i++) {
        SDL_RenderDrawLine(g_renderer,TAMAÑO_CELULAS*i, 0,TAMAÑO_CELULAS*i,TAMAÑO_VENTANA+1);
        
    }
    
    
    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    
    
    for( int x=0; x<size; x++ ) {
        for( int y=0; y<size; y++) {
            if(grid[y][x] == CELULA_VIVA ) {
                SDL_Rect r={x*TAMAÑO_CELULAS,y*TAMAÑO_CELULAS,TAMAÑO_CELULAS,TAMAÑO_CELULAS};
                SDL_RenderFillRect(g_renderer, &r);
            }
        }
    }
    
    
    SDL_RenderPresent(g_renderer);
}

void manejar_eventos( int grid[][TAMAÑO_TABLERO], int size ) {
    SDL_Event event;
    
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT){//quitar
            g_user_quit = true;
        }
        else if(event.type == SDL_MOUSEMOTION) {
            if ( event.motion.state & (SDL_BUTTON_LMASK | SDL_BUTTON_RMASK) ) {
                set_celula(
                         grid,
                         size,
                         event.motion.x/TAMAÑO_CELULAS,
                         event.motion.y/TAMAÑO_CELULAS,
                         (event.motion.state & SDL_BUTTON_LMASK)?
                         CELULA_VIVA : CELULA_MUERTA);
            }
        }
        else if( event.type == SDL_MOUSEBUTTONDOWN ) {
            set_celula( grid,
                     size,
                     event.button.x/TAMAÑO_CELULAS,
                     event.button.y/TAMAÑO_CELULAS,
                     (event.button.button==SDL_BUTTON_LEFT)?
                     CELULA_VIVA : CELULA_MUERTA);
        }
        else if( event.type == SDL_KEYDOWN ) {
            if (event.key.keysym.sym == SDLK_SPACE) { //iniciar o detener con barra
                
                g_animating = !g_animating;
            } else if (event.key.keysym.sym == SDLK_c ) {//refrescas
                init_grid( grid, size );
                g_animating = false;
            }
        }
    }
}

void cerrar_pantalla() {
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}


#endif
