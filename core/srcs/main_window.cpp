#include "includes/main_window.h"
#include <QLayout>
#include <QMessageBox>
#include "includes/get_map.h"


main_window::main_window(QWidget *parent, int diffic)
	: QWidget(parent)
	, selected_but (NULL)
{
	buts = new Ceils*[9];
		for(int i = 0; i < 9; ++i)
			buts[i] = new Ceils[9];

	QGridLayout *mainlay = new QGridLayout();
	//layouts + buttons
	for (int i = 0; i < 9; ++i)
		mainlay->addLayout(lays(i), i / 3 + 1, i % 3);

	int **a = get_map(diffic);
	//connect all buttons
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			ceil_connection(i, j);
			connect(&buts[i][j], SIGNAL(i_am_selected(Ceils *)), this, SLOT(select_but(Ceils *)));
			if (a[i][j] != 0)
				buts[i][j].set_label(a[i][j], true);
		}
	}

	//but_menu
	QPushButton *but_menu;
	but_menu = new QPushButton(this);
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

QGridLayout *main_window::lays(int k)
{
	QGridLayout *lay = new QGridLayout;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			lay->addWidget(&buts[i + k / 3 * 3][j + k % 3 * 3], i, j);
		}
	}
	lay->setMargin(7);
	return lay;
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
			pal.setColor(this->backgroundRole(),QColor(230,30,30));
			buts[row][col].set_place(false);
		}
		else
		{
			pal.setColor(this->backgroundRole(),QColor(30,200,30));
			buts[row][col].set_place(true);
		}
		selected_but->setPalette(pal);
		this->selected_but->set_label(ev->key() - 48);
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (!(buts[i][j].right_place()))
					return ;
		QMessageBox::question(this,"Поздравляем!", "вы решили судоку",QMessageBox::Ok);
		but_exit_clicked();
	}
	if ((ev->key() == Qt::Key_Delete || ev->key() == Qt::Key_Backspace)&& !selected_but->get_unremovable())
	{
		buts[row][col].set_label(0);
		buts[row][col].set_place(false);
	}
	QMouseEvent m(QEvent::MouseButtonPress, QPointF(1,1), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
	if (ev->key() == Qt::Key_W || ev->key() == 1062)
	{
		if (row != 0)
			buts[row - 1][col].ceil_is_clicked(&m);
	}
	if (ev->key() == Qt::Key_S || ev->key() == 1067)
	{
		if (row != 8)
			buts[row + 1][col].ceil_is_clicked(&m);
	}
	if (ev->key() == Qt::Key_A || ev->key() == 1060)
	{
		if (col != 0)
			buts[row][col - 1].ceil_is_clicked(&m);
	}
	if (ev->key() == Qt::Key_D || ev->key() == 1042)
	{
		if (col != 8)
			buts[row][col + 1].ceil_is_clicked(&m);
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
