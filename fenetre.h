#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QString>
#include <QImage>
#include <QPaintEvent>


class Fenetre : public QWidget
{
    Q_OBJECT
public:
    Fenetre(QWidget *parent = 0);
    ~Fenetre();
    void setImage(int pos, QImage);

private:
    QImage image[2];

private slots:
      void paintEvent(QPaintEvent *evt);


};

#endif // MAFENETRE_H
