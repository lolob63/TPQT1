/*************************
* tp photos numériques
* Lycée La Fayette
* BTS SN1 IR
*************************/
#include <iostream>
using namespace std;

#include <QImage>
#include <QApplication>
#include <fenetre.h>
#include <QRgb>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenetre w;                                                                  //Création de la fenêtre

    w.setWindowTitle("TP Images Numériques Lycée La Fayette - version 1.0");    //titre de la fenêtre
    w.show();
    w.repaint();


    QImage image;                                                               //instantiation des classes Qimage
    QImage image2;
    image.load("c:/temp/img2.png");                                             // Ouverture du fichier image
    image2.load("c:/temp/img2.png");                                            // Ouverture du fichier image
    // l'affichage sera constitué de 2 parties

//  1-   affichage de l'image originale
    w.setImage(0, image);

    // échange rouge et vert
     for (int x=0 ; x<image.width() ; x++)
        for (int y=0 ; y<image.height() ; y++){
            QRgb value = image.pixel(x,y);
            int red = qRed(value);
            int blue = qBlue(value);
            int green = qGreen(value);
            int gray = (red+blue+green)/3;
            image2.setPixel(x,y, qRgb(red,green, blue));                        // Action sur les pixels
            }

// 2-   affichage de l'image échange rouge et vert
    w.setImage(1, image2);
    image2.save("c:/temp/img.png");                                                //Sauvegarde dans un fichier img.png

return a.exec();
}
