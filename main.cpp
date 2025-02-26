#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "chessboard.h"

int main(int argc, char* argv[]) {

    //initialises the window that everything will be displayed in
    QApplication app(argc, argv);
    QWidget window; 
    window.setWindowTitle("antichess"); 
    window.resize(800,800); 

    //creates a grid layout given by qt
    QGridLayout* layout = new QGridLayout; 
    layout->setSpacing(0); 
    layout->setContentsMargins(0, 0, 0, 0); 



    //makes tiles using square object defined in chessboard.h and loops to make multiple of them
    square* tiles[8][8];
    for (int i = 0; i <8; i++) {
        for (int j = 0; j <8; j++) {
            Qt::GlobalColor col;
            if ((i+j)%2> 0) {
                col= Qt::white;
            }
            else {
                col = Qt::darkGreen;
            }
            tiles[i][j] = new square(); 
            tiles[i][j]->setProperties(col,100, i, j);
            layout->addWidget(tiles[i][j],i,j);
        }

    }





    //nessecary lines to display window
    window.setLayout(layout); 
    window.show(); 

    return app.exec(); 
}




/*import QtQuick 2.2
import QtQuick.Window 2.2
import CustomWidgets 1.0

Window{
    visible: true
    width : 640
    height : 480
    title : "antichess"
    squaretile{
        id: squaretile
        anchors.centerIn : parent
        Component.onCompleted : setProperties(Qt.gray,100,0,0)
    }
}
*/