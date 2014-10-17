#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

CGame::CGame(){
	estado = ESTADO_INICIADO;//ACT2: Mal, Aqui iba tu estado inicial

	SDL_Surface *nave;

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);

	}
	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);

	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	//Asignar texto a la pantalla
	//SDL_Flip(screen);
	SDL_WM_SetCaption("Mi Primer Juego", NULL);
	atexit(SDL_Quit);
}

void CGame::Iniciando(){
	SDL_Init(SDL_INIT_VIDEO);
}
// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;

	while (salirJuego == false){

		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIADO:
			Iniciando();
			{
				/*Sintaxis imagenes formato .bmp*/
				/*nave = SDL_LoadBMP(".../Data/minave.bmp");*/

				/*Ejemplo con imagenes formato .jpg*/
				/*nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/tools.jpg", "rb"));*/

				/*Ejemplo con imagenes formato .PNG*/
				nave = IMG_LoadBMP_RW(SDL_RWFromFile("../Data/minave.bmp", "rb"));

				/*Mostrar una seccion especifica de una imagen*/
				/*SDL_Rect fuente;
				fuente.x = 90;
				fuente.y = 152;
				fuente.w = 242;
				fuente.h = 76;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = 100;
				destino.h = 100;
				SDL_BlitSurface(nave, &fuente, screen, &destino);*/

				/*nave = fuente y screen = destino*/
				SDL_BlitSurface(nave, NULL, screen, NULL);
				/*Eliminar una superficie que no es utilizada*/
				SDL_FreeSurface(nave);
			}
			estado = Estado::ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:
			break;
		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_TERMINADO:
			salirJuego = true;
			break;
		case Estado::ESTADO_FINALIZADO:
			salirJuego = true;
			break;
		};
		SDL_Flip(screen);
	}
	return true;
}
