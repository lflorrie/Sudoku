#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <ceil.h>
#include <QLayout>
#include <QKeyEvent>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

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
private:
	void	add_buts(QGridLayout *lay, int k);

private:
	Ceils* selected_but;
	Ceils **buts;
    Ui::main_window *ui;
	QWidget* parent_window;
};
#endif // MAIN_WINDOW_H
