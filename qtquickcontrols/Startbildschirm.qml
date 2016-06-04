import QtQuick 2.3
import QtQuick.Controls 1.2
import "BasicLogic.js" as BasicLogic

Rectangle {
    //id: startScreen
    width: 640
    height: 480

    // The background image
    Image {
        id: hingergrund
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source:  "qrc:///Pictures/Menuebild.jpg"
        anchors.fill: parent;


        }

    // The Buttons

        Rectangle {
            id: startButon
            x: 245
            y: 60
            color: "transparent"
            width: 174
            height: 63

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    hingergrund.source = "qrc:///Pictures/MenuebildOnPlay.jpg"
                }
                onExited: {
                    hingergrund.source = "qrc:///Pictures/Menuebild.jpg"
                }

                onClicked: {
                    mainGame.startGame();
                    BasicLogic.showGameScreen();}
            }
        }

        Rectangle {
            id: quitButon
            x: 245
            y: 125
            color: "transparent"
            width: 174
            height: 30
            MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            hingergrund.source = "qrc:///Pictures/MenuebildOnExit.jpg"
                        }
                        onExited: {
                            hingergrund.source = "qrc:///Pictures/Menuebild.jpg"
                        }
                        onClicked: { console.log("Show End Screen!");Qt.quit(); }
            }

        }
        Rectangle {
            id: scoreButon
            x: 245
            y: 165
            color: "transparent"
            width: 174
            height: 30
                MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            hingergrund.source = "qrc:///Pictures/MenuebildOnScore.jpg"
                        }
                        onExited: {
                            hingergrund.source = "qrc:///Pictures/Menuebild.jpg"
                        }
                        onClicked: { console.log("Show Score Screen!"); }
            }

        }
   }



