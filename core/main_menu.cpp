#include "main_menu.h"
#include "ui_main_menu.h"
#include <QApplication>
#include "main_window.h"

main_menu::main_menu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::main_menu)
{
	ui->setupUi(this);
}

main_menu::~main_menu()
{
	delete ui;
}

void main_menu::on_but_play_clicked()
{
	main_window *w = new main_window(this);
	this->setVisible(false);
	w->show();
}

void main_menu::on_but_exit_clicked()
{
	this->close();
}
