#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>

namespace Ui {
class main_menu;
}

class main_menu : public QWidget
{
	Q_OBJECT

public:
	explicit main_menu(QWidget *parent = nullptr);
	~main_menu();

private slots:
	void on_but_play_clicked();

	void on_but_exit_clicked();

private:
	Ui::main_menu *ui;
};

#endif // MAIN_MENU_H
