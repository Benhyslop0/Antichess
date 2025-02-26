#pragma once
#include <qwidget>
#include<qpainter>
#include<qmouseevent>

/*class board {

	int boardvec[8][8] = { 
	{1,2,3,4,5,3,2,1},
	{6,6,6,6,6,6,6,6},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{7,7,7,7,7,7,7,7},
	{8,9,10,11,12,10,9,8} //top is white (1-6),bottom is black (7-12),no mans land is defined by 0s
	};
};
*/

//this is the class used for tiles it is a child class of what qt defines as objects that it can displays. 
// by defining as an object it gets attributes like size,location,displayable commands and interactions with user.
class square: public QWidget {
	Q_OBJECT
public:
	explicit square(QWidget* parent = nullptr);
	Q_INVOKABLE void setProperties(Qt::GlobalColor colour, int side, int x, int y);
protected:
	void paintEvent(QPaintEvent* paint) override;
	void mousePressEvent(QMouseEvent* click) override;

private:
	Qt::GlobalColor colour;
	int side;
	int x;
	int y;

};




