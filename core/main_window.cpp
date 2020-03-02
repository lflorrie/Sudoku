#include "main_window.h"
#include "ui_main_window.h"
#include <QLayout>

main_window::main_window(QWidget *parent)
	: QWidget(NULL)
    , ui(new Ui::main_window)
	, parent_window(parent)
{
	ui->setupUi(this);
	selected_but = NULL;
	QGridLayout *lays = new QGridLayout[9];
	QGridLayout *mainlay = new QGridLayout(this);
	//layouts + buttons
	for (int k = 0; k < 9; ++k)
	{
		lays[k].setMargin(5);
		add_buts(lays, k);
		mainlay->addLayout(&(lays[k]), k / 3 + 1, k % 3);
	}
	//connect all buttons
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			ceil_connection(i, j);
			connect(&this->buts[i][j], SIGNAL(i_am_selected(Ceils *)), this, SLOT(select_but(Ceils *)));
		}
	}
	QPushButton *but_menu;
	but_menu = new QPushButton();
	but_menu->setText("Выход");
	but_menu->setFixedSize(100,30);
	mainlay->addWidget(but_menu,0,0);
	connect (but_menu, SIGNAL(clicked()), this, SLOT(but_exit_clicked()));
	this->setFixedSize(550,550);
	this->setLayout(mainlay);
}

main_window::~main_window()
{
	delete ui;
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
	if (selected_but)
		if (ev->key() > Qt::Key_0 && ev->key() <= Qt::Key_9)
			this->selected_but->set_label(ev->key() - 48);
}

void main_window::select_but(Ceils *obj)
{
	if (obj)
		this->selected_but = obj;
}

void main_window::but_exit_clicked()
{
	parent_window->setVisible(true);
	this->close();
}
