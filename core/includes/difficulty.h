#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QWidget>

namespace Ui {
class Difficulty;
}
enum e_diff {Easy,
			Medium,
			Hard};

class Difficulty : public QWidget
{
	Q_OBJECT

public:
	explicit Difficulty(QWidget *parent = nullptr);
	~Difficulty();

signals:
	void dif_but_back(int a);

	void dif_but_start(int a);

	void difficult(e_diff d);
private slots:
	void on_but_back_clicked();

	void on_but_easy_clicked();

	void on_but_medium_clicked();

	void on_but_hard_clicked();

private:
	Ui::Difficulty *ui;
};

#endif // DIFFICULTY_H
