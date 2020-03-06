#include "includes/sudoku.h"

Sudoku::Sudoku(QWidget *parent) : QWidget(parent),
									stack(new QStackedLayout)
{
	w_menu = new main_menu();

	w_diff = new Difficulty();

	w_game = NULL;
	stack->addWidget(w_menu);
	stack->addWidget(w_diff);

				//CONNECTION
	//MENU
	connect(w_menu, SIGNAL(menu_play_clicked(int)), stack, SLOT(setCurrentIndex(int)));
	connect(w_menu, SIGNAL(menu_exit_clicked(int)), this, SLOT(close()));
	//Diff
	connect(w_diff, SIGNAL(dif_but_back(int)), stack, SLOT(setCurrentIndex(int)));
	connect(w_diff, SIGNAL(dif_but_start(int)), this, SLOT(create_map(int)));

	//GAME
	this->setLayout(stack);
	this->setMinimumSize(550,550);
}

void Sudoku::create_map(int diff)
{
	if (w_game)
	{
		stack->removeWidget(w_game);
		delete w_game;
	}
	w_game = new main_window(this, diff);
	connect(w_game, SIGNAL(but_exit(int)), stack, SLOT(setCurrentIndex(int)));
	stack->addWidget(w_game);
	stack->setCurrentIndex(2);
}
