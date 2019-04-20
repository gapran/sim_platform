#include "image.h"

#include<vector>
#include<QLabel>
#include<QTextCursor>

Image::Image(QWidget *parent) : QDialog (parent)
{
    label = new QLabel;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

void Image::setImage(QString fileName)
{
    if (!fileName.isEmpty()){

        /** set content to show center in label */
        label->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(fileName)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            label->setPixmap(pix);
            label->setScaledContents(true);
        }
    }
}

void  Image::setBox()
{
    label->setFrameStyle(QFrame::Panel);
}

void Image::setSize(int width, int height)
{
    label->resize(width,height);
}


void Image::setHover(QString text)
{
    label->setToolTip(text);
}

void Image::setAppear()
{
    label->show();
}

void Image::setDisappaer()
{
    label->hide();
}

void  Image::noBorder()
{
    label->setStyleSheet("border: none;");
}
