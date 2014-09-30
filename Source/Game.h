#include <SDL.h>

class CGame
{
public:
	bool Start();
	static CGame instanceGame;


	CGame();
	void Finalize();

	

	enum Estado{
		ESTADO_INICIADO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO,
	};

private:
<<<<<<< HEAD
	void Iniciando();
	SDL_Surface *screen;
	SDL_Surface *nave;
	Estado estado;
=======
	int estado;//ACT2: Mal, El estado ya no debe ser int, si no tipo Estado, como el enum que agregaste.
>>>>>>> origin/master
};