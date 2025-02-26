#include "chessboard.h"
#include<qpainter.h>
#include<qmouseevent>
#include<qdebug>


square::square(QWidget* parent): QWidget(parent)
{}

//properties of qt object
void square::setProperties(Qt::GlobalColor colour, int side,int x ,int y) {
	this->colour = colour;
	this->side = side;
	this->x = x;
	this->y = y;
	setFixedSize(side, side);
	update();
}


//how the program should deal with the object when it gets displayed.
void square::paintEvent(QPaintEvent* paint)
{
	 
	QPainter painter(this);
	painter.setBrush(colour);
	painter.setPen(colour);
	painter.drawRect(0, 0, side, side);



}


//defines what happens when this tile is clicked on.
void square::mousePressEvent(QMouseEvent* click)
{
	this->colour = Qt::GlobalColor::red;
	update();
}
