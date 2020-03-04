#include "includes/sudoku.h"

Sudoku::Sudoku(QWidget *parent) : QWidget(parent),
									stack(new QStackedLayout)
{
	w_menu = new main_menu();

	w_diff = new Difficulty();

	w_game = new main_window();

	stack->addWidget(w_menu);
	stack->addWidget(w_diff);
	stack->addWidget(w_game);

				//CONNECTION
	//MENU
	connect(w_menu, SIGNAL(menu_play_clicked(int)), stack, SLOT(setCurrentIndex(int)));
	connect(w_menu, SIGNAL(menu_exit_clicked(int)), this, SLOT(close()));
	//Diff
	connect(w_diff, SIGNAL(dif_but_back(int)), stack, SLOT(setCurrentIndex(int)));
	connect(w_diff, SIGNAL(dif_but_easy(int)), stack, SLOT(setCurrentIndex(int)));
	//GAME
	connect(w_game, SIGNAL(but_exit(int)), stack, SLOT(setCurrentIndex(int)));
	this->setLayout(stack);
}
