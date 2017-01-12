#include <iostream>

const int BLANK = 0;
const int HUMAN = 1;
const int COMPUTER = -1;

const int MAX_SCORE = 10;

class Game {
private:
	int board[9];
public:
	/* initialize the board */
	Game();

	/* check if move is legal */
	bool is_valid_move(int move);

	/* public interface to make a move on board */
	void make_move(int player, int move);

	/* is_game_won returns the player that has won the game or zero if neither has */
	int is_game_won();

	/* get_minimax_score exhaustively searches game tree to determine the score for the move 
	made by the player assuming that the opponent plays optimally */
	int get_minimax_score(int player);

	/* find_best_move finds the best move for the given player based on the minimax score */
	int find_best_move(int player);

	/* draw_board draws the board on the screen */
	friend void draw_board(Game&);
};

