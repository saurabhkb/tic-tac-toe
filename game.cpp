#include "game.h"

Game::Game() {
	for(int i = 0; i < 9; i++) {
		board[i] = BLANK;
	}
}

bool Game::is_valid_move(int move) {
	if((0 <= move) && (move <= 9) && (board[move] == BLANK)) {
		return true;
	}
	return false;
}

void Game::make_move(int player, int move) {
	board[move] = player;
}

int Game::is_game_won() {
	/* check all possible winning orders (horizontal, vertical, diagonal) */
	int win_orders[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {6, 4, 2}};
	int pos1, pos2, pos3;

	for(int i = 0; i < 8; i++) {
		pos1 = win_orders[i][0];
		pos2 = win_orders[i][1];
		pos3 = win_orders[i][2];

		if(board[pos1] != BLANK && (board[pos1] == board[pos2]) && (board[pos2] == board[pos3])) {
			return board[pos1];
		}
	}
	return 0;
}

int Game::get_minimax_score(int player) {
	/* check if the game has already been won by a player */
	int win = is_game_won();

	if(win == player) {
		/* player won */
		return MAX_SCORE;
	} else if(win == -player) {
		/* opposing player won */
		return -MAX_SCORE;
	}

	/* For player, make a move on every possible empty position and play the rest of 
	the game optimally. The move with the highest score will be the one finally chosen */

	int highest_score = -MAX_SCORE, best_move = -1;

	for(int i = 0; i < 9; i++) {
		/* check if position i is empty */
		if(board[i] != BLANK) {
			continue;
		}

		/* make the move */
		board[i] = player;

		/* choose move that minimizes the maximum score move for the opponent */
		int temp_score = -get_minimax_score(-player);
		if(temp_score > highest_score) {
			highest_score = temp_score;
			best_move = i;
		}

		/* undo the move */
		board[i] = BLANK;
	}

	/* return the best score possible assuming that a legal move could be made (otherwise return 0) */
	if(best_move == -1) {
		return 0;
	} else {
		return highest_score;
	}
}

int Game::find_best_move(int player) {
	int highest_score = -MAX_SCORE, best_move = -1;
	for(int i = 0; i < 9; i++) {
		if(board[i] != BLANK) {
			continue;
		}

		/* make the move */
		board[i] = player;

		/* calculate score of the move */
		int score = -get_minimax_score(-player);
		if(score >= highest_score) {
			highest_score = score;
			best_move = i;
		}

		/* undo move */
		board[i] = BLANK;
	}

	/* return the highest scoring move (if exists) */
	return best_move;
}
