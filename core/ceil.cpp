#include "ceil.h"
#include <QMouseEvent>

Ceils::Ceils(QWidget *parent) : QWidget(parent),
								str(new QLabel(this)),
								selected(false),
								unremovable(false)

{
	QPixmap pict("..//..//Resources//ceils.svg");
	this->setFixedSize(50,50);
	pal.setBrush(this->backgroundRole(), QBrush(QPixmap(pict)));
	this->setAutoFillBackground(true);
	this->setPalette(pal);


	str->setText(" ");
	str->setFont(QFont("Calibri", 25));
	this->str->setGeometry(this->x() + 15, this->y() / 8, width(), height());
	this->str->show();
	connect(this, SIGNAL(clicked(QMouseEvent *)), this, SLOT(ceil_is_clicked(QMouseEvent *)));
}

void Ceils::set_label(int num, bool removable /*= false*/)
{
	this->unremovable = removable;
	this->str->setNum(num);
}

void Ceils::unselect_ceil()
{
	if (selected == true)
	{
		selected = false;
		pal.setBrush(this->backgroundRole(), QBrush(QPixmap("..//..//Resources//ceils.svg")));
		this->setPalette(pal);
		this->update();
	}
}

void Ceils::mousePressEvent(QMouseEvent *event)
{
	emit clicked(event);
}


void Ceils::ceil_is_clicked(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit unselect();
		if (selected == false){
			emit i_am_selected(this);
			selected = true;
			this->pal.setBrush(this->backgroundRole(), QBrush(QPixmap("..//..//Resources//select1.jpg")));
			this->setPalette(pal);
			this->update();
		}
	}
	if (event->button() == Qt::RightButton)
	{
		if (!this->unremovable)
			this->str->clear();
	}
}
