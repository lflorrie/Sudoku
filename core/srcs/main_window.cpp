#include "includes/main_window.h"
#include <QLayout>
#include <QMessageBox>
#include "includes/get_map.h"

main_window::main_window(QWidget *parent)
	: QWidget(parent)
	, selected_but (NULL)
{
	buts = new Ceils*[9];
		for(int i = 0; i < 9; ++i)
			buts[i] = new Ceils[9];

	QGridLayout *mainlay = new QGridLayout();
	//layouts + buttons
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				mainlay->addWidget(&this->buts[i][j], i + 1, j);
			}
		}
	int **a = get_map(0);
	//connect all buttons
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			ceil_connection(i, j);
			connect(&this->buts[i][j], SIGNAL(i_am_selected(Ceils *)), this, SLOT(select_but(Ceils *)));
			if (a[i][j] != 0)
				buts[i][j].set_label(a[i][j], true);
		}
	}
	//but_menu
	QPushButton *but_menu;
	but_menu = new QPushButton();
	but_menu->setText("Выход");
	but_menu->setFixedSize(50,30);
	mainlay->addWidget(but_menu,0,0);
	connect(but_menu, SIGNAL(clicked()), this, SLOT(but_exit_clicked()));

	this->setFixedSize(550,550);
	this->setLayout(mainlay);
	this->setWindowTitle("SUDOKU");
	for (int i = 0; i < 9; ++i)
		delete[] a[i];
	delete[] a;
}

main_window::~main_window()
{
	for (int i = 0; i < 9; ++i)
		delete[] buts[i];
	delete buts;

}

void main_window::add_buts(QGridLayout *lays, int k)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			lays[k].addWidget(&this->buts[i + k % 3 * 3][j + k / 3 * 3], i, j);
		}
	}
}

void	main_window::ceil_connection(int x, int y)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			connect(&this->buts[x][y], SIGNAL(unselect()), &this->buts[i][j], SLOT(unselect_ceil()));
		}
	}
}

void main_window::keyPressEvent(QKeyEvent *ev)
{
	int row, col;

	if (!selected_but) return ;

	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
			if (&buts[row][col] == selected_but) break;
		if (&buts[row][col] == selected_but) break;
	}
	if (ev->key() > Qt::Key_0 && ev->key() <= Qt::Key_9 && !selected_but->get_unremovable())
	{
		QPalette pal;
		if (!is_right_place(buts,row , col, ev->key() - 48))
		{
			pal.setColor(this->backgroundRole(),Qt::red);
			buts[row][col].set_place(false);
		}
		else
		{
			pal.setColor(this->backgroundRole(),Qt::green);
			buts[row][col].set_place(true);
		}
		selected_but->setPalette(pal);
		this->selected_but->set_label(ev->key() - 48);
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (!(buts[i][j].right_place()))
					return ;
		QMessageBox::question(this,"Ты пидор","поздравляем, вы решили судоку",QMessageBox::Ok);
		but_exit_clicked();
	}
	if ((ev->key() == Qt::Key_Delete || ev->key() == Qt::Key_Backspace)&& !selected_but->get_unremovable())
	{
		buts[row][col].set_label(0);
		buts[row][col].set_place(false);
	}
}

void main_window::select_but(Ceils *obj)
{
	if (obj)
		this->selected_but = obj;
}

void main_window::but_exit_clicked()
{
	emit but_exit(0);
}
