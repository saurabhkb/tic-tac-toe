#include <iostream>
#include "game.h"

void draw_board(Game& g) {
	for(int i = 0; i < 9; i++) {
		if(i > 0) {
			if(i % 3 == 0) {
				std::cout << "\n---+---+---\n";
			} else {
				std::cout << " |";
			}
		}
		switch(g.board[i]) {
			case BLANK:
				std::cout << "  ";
				break;
			case HUMAN:
				std::cout << " X";
				break;
			case COMPUTER:
				std::cout << " O";
				break;
		}
	}
	std::cout << "\n";
}

int main() {
	Game g;
	draw_board(g);
	int num_moves = 0;
	while(num_moves < 9) {
		/* human makes a valid move */
		int human_move = -1;
		while(!g.is_valid_move(human_move)) {
			std::cout << "enter valid move (0-9)\n";
			std::cin >> human_move;
		}

		g.make_move(HUMAN, human_move);
		draw_board(g);

		if(g.is_game_won() == HUMAN) {
			std::cout << "you won!\n";
			break;
		}

		/* computer makes a move */
		int computer_move = g.find_best_move(COMPUTER);
		if(computer_move >= 0) {
			std::cout << "Computer plays:\n";
			g.make_move(COMPUTER, computer_move);
		} else {
			/* no move was possible */
			std::cout << "draw!\n";
			break;
		}
		draw_board(g);

		if(g.is_game_won() == COMPUTER) {
			std::cout << "computer won!\n";
			break;
		}

		num_moves += 2;
	}
	std::cout << "game over!\n";
	return 0;
}

