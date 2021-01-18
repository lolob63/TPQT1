#include "fenetre.h"
#include <QPainter>


Fenetre::Fenetre(QWidget *parent)
    : QWidget(parent)
{

}

Fenetre::~Fenetre()
{

}

void Fenetre::setImage(int pos, QImage image){
    if (!image.isNull() && pos>=0 && pos<4)
                this->image[pos] = image;
    repaint();
}


void Fenetre::paintEvent(QPaintEvent *evt){
    QPainter painter(this);

    for (int i=0 ; i<2 ; i++){
                if (image[i].isNull()) continue;

                QRect r((i%2)*width()/2, i/2*height()/2, width()/2, height());        // dans le bon cadran toute l'image
                painter.drawImage(r,  image[i]);
                painter.drawRect(r);
                }

}

