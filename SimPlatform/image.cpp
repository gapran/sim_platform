#include "imageelement.h"

#include<iostream>
#include<vector>
#include<QLabel>
#include<QTextCursor>

using namespace std;


ImageElement::ImageElement(QWidget *parent) : QDialog (parent)
{

    label = new QLabel;

    setImage("C:/Users/hasee/Documents/Qt/Testing/Images/Capture.png");


}

void ImageElement::setImage(QString fileName)
{
    //QString filename = "C:/Users/hasee/Documents/Qt/Testing/Images/Capture.png";

    if (!fileName.isEmpty()){

        /** set content to show center in label */
        label->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(fileName)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            //pix = pix.scaled(lbl->size());
            label->setPixmap(pix);
            label->setScaledContents(true);
            //ui->ImageButton->setText("");
        }
    }
}

void  ImageElement::ImageStyle()
{
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
}

void ImageElement::setSize(int width, int height)
{

    label->resize(width,height);

}

void ImageElement::setClickable()
{


}

void ImageElement::setHover()
{


}

void ImageElement::setAppear()
{

    label->show();
}

void ImageElement::setDisappaer()
{

    label->hide();
}

