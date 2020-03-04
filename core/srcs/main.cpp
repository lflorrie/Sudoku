#include "includes/main_window.h"
#include "includes/main_menu.h"
#include "includes/sudoku.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	Sudoku w;
    w.show();
    return a.exec();
}
