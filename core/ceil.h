#ifndef CEIL_H
#define CEIL_H

#include <QWidget>
#include <QLabel>
class Ceils : public QWidget
{
    Q_OBJECT
public:
	explicit	Ceils(QWidget *parent = nullptr);
	void		set_label(int num);
signals:
	void	clicked(QMouseEvent *event);
	void	unselect();
	void	i_am_selected(Ceils *obj);
// QWidget interface
protected:
	void	mousePressEvent(QMouseEvent *event);
public slots:
	void	unselect_ceil();
	void	ceil_is_clicked(QMouseEvent *event);
private:
	bool		selected;
	QPalette	pal;
	int			num;
	QLabel		*str;
};

#endif // CEIL_H
