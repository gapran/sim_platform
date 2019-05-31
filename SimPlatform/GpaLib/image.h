#ifndef IMAGE_H
#define IMAGE_H

#include<iostream>
#include<QDialog>
#include<QLabel>
#include <QHBoxLayout>

using namespace std;
class Qlabel;

class Image: public QDialog
{
    Q_OBJECT
public:
    explicit Image(QWidget *parent = nullptr);

    void setImage(QString fileName);
    void setBox();
    void setSize(int width, int height);
    void setHover(QString text);
    void setAppear();
    void setDisappaer();
    void noBorder();

signals:
   void clicked();

protected:
   void mousePressEvent(QMouseEvent *e) { emit clicked();
                                        std::cout << "Image Clicked - " << e <<endl;}

private:
    QLabel *label;

};

#endif // IMAGE_H
