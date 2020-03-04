#ifndef CEIL_H
#define CEIL_H

#include <QWidget>
#include <QLabel>
#include <QChar>

class Ceils : public QWidget
{
    Q_OBJECT
public:
	explicit	Ceils(QWidget *parent = nullptr);
	~Ceils();
	void		set_label(int num, bool removable = false);
	int			get_label() const;
	bool		right_place() const { return right;}
	void		set_place(bool a) { right = a;}

	bool		get_unremovable() const { return unremovable; }
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
	QLabel		*str;
	bool		selected;
	QPalette	pal;
	bool		unremovable;
	bool		right;
};

#endif // CEIL_H
