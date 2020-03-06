#include <QMouseEvent>
#include "includes/ceil.h"
#include "includes/get_map.h"

Ceils::Ceils(QWidget *parent) : QWidget(parent),
								str(new QLabel(this)),
								selected(false),
								unremovable(false)

{
	this->setFixedSize(50,50);
	pal.setBrush(this->backgroundRole(), QBrush(QPixmap(pict_ceil)));
	this->setAutoFillBackground(true);
	this->setPalette(pal);

	str->setText(" ");
	str->setFont(QFont("Calibri", 25));
	this->str->setGeometry(this->x() + 15, this->y() / 8, width(), height());
	this->str->show();
	connect(this, SIGNAL(clicked(QMouseEvent *)), this, SLOT(ceil_is_clicked(QMouseEvent *)));
}

Ceils::~Ceils()
{
	delete str;
}

void Ceils::set_label(int num, bool removable /*= false*/)
{
	this->unremovable = removable;
	if (removable == true)
	{
		this->right = true;
		this->pal.setBrush(this->backgroundRole(), QBrush(QPixmap(pict_def_ceil)));
		this->setPalette(pal);
		this->update();
	}
	if (num == 0)
		str->setText(" ");
	else
		this->str->setText(QString(num + '0'));
}

int Ceils::get_label() const
{

	return this->str->text() == " " ? 0 : str->text().toInt();
}

void Ceils::unselect_ceil()
{
	if (selected == true)
	{
		selected = false;
		if (!this->unremovable)
//			if (this->right || this->get_label()== 0)
				pal.setBrush(this->backgroundRole(), QBrush(QPixmap(pict_ceil)));
			//else
				//pal.setColor(this->backgroundRole(), QColor(Qt::red));
		else
			this->pal.setBrush(this->backgroundRole(), QBrush(QPixmap(pict_def_ceil)));
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
			this->pal.setBrush(this->backgroundRole(), QBrush(QPixmap(pict_select)));
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
