#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include <QStackedLayout>
#include "main_menu.h"
#include "difficulty.h"
#include "main_window.h"

class Sudoku : public QWidget
{
	Q_OBJECT
public:
	explicit	Sudoku(QWidget *parent = nullptr);
public slots:
	void		create_map(int diff);
signals:
private:
	QStackedLayout	*stack;
	main_menu		*w_menu;
	Difficulty		*w_diff;
	main_window		*w_game;
};

#endif // SUDOKU_H
