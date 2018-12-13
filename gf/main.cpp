//
//  main.cpp
//  homework1
//
//  Created by Holub Katerina on 08.09.2018.
#include <iostream>

using namespace std;

class Parquet{
public:
    void setParquet(){
        length = 1 + rand()%100;
        width = 1 + rand()%100;
    }
    
    void getParquet() {
        cout<<"\n Parquet's length: "<<length<<", width: "<<width;
    }
private:
    double length;
    double width;
};


class Window {
public:
    void setWindow(){
        width= 1 + rand()%100;
        height= 1 + rand()%100;
    }
    
    void getWindow() {
        cout<<"\n Window's width: "<<width<<", height: "<<height;
    }
    
private:
    double width;
    double height;
};



class Room {
public:
    
    int colorPaint[4] = {0, 0, 0, 0};
    string colorsList[4] = {"white", "yellow", "green", "grey"};
    
    void setRoom() {
        length=1 + rand()%100;
        width=1 + rand()%100;
        height=1 + rand()%100;
        int index = rand()%4;
        color = colorsList[index];
        litresM2 = 1 + rand()%100;
        countOfPaint(index, litresM2);
        parquet.setParquet();
        windowsNumber = 1+ rand()%4;
        for (int i=0; i<windowsNumber; ++i) {
            windows[i].setWindow();
        }
        
    }
    
    void getRoom() {
        cout<<" Length: "<<length<<", width: "<<width<<", height: "<<height<<"\n Color: " << color << "\n Litres per m2: " << litresM2 << windowsNumber;
        parquet.getParquet();
        for (int i=0; i<windowsNumber; ++i) {
            windows[i].getWindow();
        }
    }
    
    void countOfPaint(int index, int lM2) {
        for (int i = 0; i < sizeof(colorPaint); ++i) {
            if (i == index) {
                colorPaint[i] += lM2;
            }
        }
    }
    
    void getPaint() {
        cout << "\n\n\n";
        for (int i = 0; i < sizeof(colorPaint); ++i) {
            cout<<colorsList[i]<<" - "<<colorPaint[i];
        }
    }
    
private:
    double length;
    double width;
    double height;
    string color;
    double litresM2;
    Parquet parquet;
    int windowsNumber;
    Window windows[10];
};



class Flat {
public:
    void setFlat() {
        cout<<"Enter number of rooms: ";
        cin>>roomsNumber;
        rooms = new Room[roomsNumber];
        for (int i=0; i<roomsNumber; ++i) {
            rooms[i].setRoom();
        }
        delete [] rooms;
    }
    void getFlat(){
        cout<<"\nNumber of rooms "<<roomsNumber<<"\n";
        for (int i=0; i<roomsNumber; ++i) {
            cout<<"\nRoom #" << i+1;
            rooms[i].getRoom();
        }
    }
private:
    int roomsNumber;
    Room *rooms;
};

class House {
public:
    void setHouse() {
        cout<<"Enter number of floors: ";
        cin>>floors;
        cout<< "Enter nubmer of flats per floor: ";
        cin>>flatsOnFloor;
        flats = new Flat[flatsOnFloor*floors];
        for (int i=0; i<flatsOnFloor*floors; ++i) {
            cout<<"\n\nFlat #"<< i+1 <<"\n";
            flats[i].setFlat();
        }
        delete [] flats;
    }
    void getHouse(){
        cout<<"\n\nNumber of flats "<<flatsOnFloor*floors<<"\n";
        for (int i=0; i< flatsOnFloor*floors; ++i) {
            cout<<"\nFlat #" << i+1;
            flats[i].getFlat();
        }
    }
    
    
private:
    int floors;
    int flatsOnFloor;
    Flat *flats;
    
};

int main(int argc, const char * argv[]) {
    
    House house;
    house.setHouse();
    house.getHouse();
    
    return 0;
}

