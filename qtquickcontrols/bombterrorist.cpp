#include "bombterrorist.h"

//Konstruktor
BombTerrorist::BombTerrorist (QObject *parent) : QObject(parent){
    // Anfangsposition
    x = (int) qrand() % (int) 3; // Zufallszahl bis 2
    if(x==0){x=0;y = 150;bewegungsform=0;}         // Hinter Holzdeckung auftauchen
    else if(x==1){x=240;y = 250;bewegungsform=(int) qrand() % (int) 2;}// Hinter Mauerdeckung auftauchen BEWEGUNGSRICHTUNG
    else if(x==2){x=480;y = 150;bewegungsform=1;}// Hinter Steindeckung auftauchen
    // Weitere Anfangszusände
    liveLevel= 1;
    visibel = true;
    bombTime = 100;
    visableTime = 2;
    bombTime = 100;

    //Bewegungen
    speed=1;    // Geschwindikeit der Bewegung
}

void BombTerrorist::timerSlot(){
// BEWGUNGEN
    // nach rechts gehen
    if (bewegungsform == 0)     // Bewegt sich aus der Deckung
    {
        x=x+speed;
        if((x>150&&x<170)||(x>340&&x<360))
        {
            bewegungsform = 2;  // Bewegung  nach vorne wechseln
        }
    }
    //nach links gehen
    if (bewegungsform == 1)     // Bewegt sich aus der Deckung
    {
        x=x-speed;
        if((x>150&&x<170)||(x>340&&x<410))
        {
            bewegungsform = 2;  // Bewegung  nach vorne wechseln
        }
    }
    //nach vorne gehen
    else if (bewegungsform == 2)
    {
        y=y+speed;
        if(y>400)
        {
            bewegungsform = 3;  //Bewegung gestoppt
        }
    }
    emit PosChanged();


    //strobo bei tot
    if((liveLevel == 0)&&(visableTime != 0)){
        visableTime--;         //Timer für den strobo
        visibel = !visibel;     //strobo
        }
    else if((liveLevel == 0)&&(visableTime == 0)){  // strob beenden und Objekt vernichten
        visibel= false; // strobo beende

        // Objekt vernichten!!!
        emit deathMan(this);

        }
    //Timer zur Selbstexplosion
    if((y>400)&&(liveLevel==true)){
        if(bombTime>0){
            bombTime--;
        }
        if((bombTime==0)){
            liveLevel = 0;
            emit detonates();
            qDebug()<<"detonated";
        }
    }

}

void BombTerrorist::shotedCheck(double PosX, double PosY){

    if(((PosX==x)&&(PosY==y))&&(liveLevel!=0)){
       qDebug() << this << "wurde getroffen";
       liveLevel = 0;       // Tot einstellen
       visibel = false;
       visableTime = 100; // 1 sek strobo. bei Timer 10ms
       bewegungsform = 3;   // nicht mehr weiterlaufen
    }

}

double BombTerrorist::getX(){
    return x;
}

double BombTerrorist::getY(){
    return y;

}

bool BombTerrorist::getVisibel(){
    return visibel;
}

bool BombTerrorist::getTerroristDetonates(){
    //Funktion gibt zurück, ob Terrorist gerade am schiessen ist.
    bool State;
    return true;
}

BombTerrorist::~BombTerrorist()
{
    //qDebug() << "Terrorist dead!!!";
}
