#include"SetGame.h"
#include"UI.h"

void main() {
	UI ui;
	ui.makeUI();
	Game* game = new Game();
	while (!game->isOverGame()) {
		delete game;
		game = new Game();
		game->playGame();
		game->gameOver();
	}
}