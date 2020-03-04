#include <QLayout>
#include "includes/main_menu.h"
#include "ui_main_menu.h"
#include "includes/main_window.h"
#include "includes/difficulty.h"

main_menu::main_menu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::main_menu)
{
	ui->setupUi(this);
	this->setWindowTitle("SUDOKU");
}

main_menu::~main_menu()
{
	delete ui;
}

void main_menu::on_but_play_clicked()
{
	emit menu_play_clicked(1);
}

void main_menu::on_but_exit_clicked()
{
	emit menu_exit_clicked(0);
}


