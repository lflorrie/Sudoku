#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QLayout>
#include <QKeyEvent>
#include <QPushButton>
#include "ceil.h"

class main_window : public QWidget
{
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

	void	ceil_connection(int x, int y);
// QWidget interface
protected:
	void	keyPressEvent(QKeyEvent *event);
public slots:
	void	select_but(Ceils *obj);
	void	but_exit_clicked();
signals:
	void	but_exit(int a);
private:
	void	add_buts(QGridLayout *lay, int k);

private:
	Ceils* selected_but;
	Ceils **buts;
};
#endif // MAIN_WINDOW_H
