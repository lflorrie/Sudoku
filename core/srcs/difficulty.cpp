#include "includes/difficulty.h"
#include "ui_difficulty.h"
#include "includes/main_window.h"

Difficulty::Difficulty(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Difficulty)
{
	ui->setupUi(this);
}

Difficulty::~Difficulty()
{
	delete ui;
}

void Difficulty::on_but_back_clicked()
{
	emit dif_but_back(0);
}

void Difficulty::on_but_easy_clicked()
{
	emit dif_but_easy(2);
}

void Difficulty::on_but_medium_clicked()
{
	emit dif_but_easy(2);
}

void Difficulty::on_but_hard_clicked()
{
	emit dif_but_easy(2);
}
