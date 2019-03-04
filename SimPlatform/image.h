#ifndef IMAGE_H
#define IMAGE_H

#include<QDialog>
#include<QLabel>
#include <QHBoxLayout>

class Qlabel;

class ImageElement: public QDialog
{
    Q_OBJECT
public:
    explicit ImageElement(QWidget *parent = 0);

    void setImage(QString fileName);
    void ImageStyle();
    void setSize(int width, int height);
    void setClickable();
    void setHover();
    void setAppear();
    void setDisappaer();


private:
    QLabel *label;

};

#endif // IMAGE_H
