// James Wilson
// C++ Test
// 

#include <iostream>
#include <cstring> 
#include <fstream>


#define input_read 20
#define defrows 6
#define defcols 6
  
using namespace std;

class lot {
      
      public:
             lot(void) {
                       // lot array always 6x6
                       //lotarray = int[6][6];
                       // lot is empty
                       for(int i=0;i<defrows; i++) {
                               for(int j=0; j<defcols; j++) {
                                       lotarray[i][j] = 0;
                               }
                       }
                       rows = defrows;
                       cols = defrows;
             }
             // check for car
             int iscar(int r, int c) {
                  return lotarray[r][c];
             }
             // doesn't check if car is already there
             void addcar(int r, int c) {
                  lotarray[r][c] = 1;
             }
             // no testing if the car is there or not
             void delcar(int r, int c) {
                  lotarray[r][c] = 0;
             }
             int getrows(void) {
                 return rows;
             }        
             int getcols(void) {
                 return cols;
             }
             
             void printlot(void) {
                  for(int i=0; i<rows; i++) {
                          for(int j=0; j<cols; j++) {
                                  if(lotarray[i][j] == 1) {
                                      cout << "*";
                                  } else {
                                      cout << " ";
                                  }
                          }
                          cout << "\n";
                  }
                  cout << "\n\n";
             }
      
      
      private:
              int lotarray[defrows][defcols];
              int rows;
              int cols;
              
}; 

class car {
      public:
             car() {
                       cout << "Latitude:\n";
                       cin >> latitude;
                       cout << "Longitude:\n";
                       cin >> longitude;
                       
             }
             void setloc(int lat, int longi) {
                  latitude = lat;
                  longitude = longi;
             }
             int getlat(void) {
                 return latitude;
             }
             int getlong(void) {
                 return longitude;
             }
             lot up(lot l) {
                 if(l.iscar(latitude+1, longitude) or latitude+1>=l.getrows()) {
                    return l;
                 }
                 else {
                      l.delcar(latitude, longitude);
                      latitude++;
                      l.addcar(latitude, longitude);
                      return l;
                 }
                 
             }
             lot down(lot l) {
                 if(l.iscar(latitude-1, longitude) or latitude-1<0) {
                    return l;
                 }
                 else {
                      l.delcar(latitude, longitude);
                      latitude--;
                      l.addcar(latitude, longitude);
                      return l;
                 }
             }
             lot left(lot l) {
                 if(l.iscar(latitude, longitude-1) or longitude-1<0) {
                    return l;
                 }
                 else {
                      l.delcar(latitude, longitude);
                      longitude--;
                      l.addcar(latitude, longitude);
                      return l;
                 }
             }
             lot right(lot l) {
                 if(l.iscar(latitude, longitude+1) or longitude+1>=l.getcols()) {
                    return l;
                 }
                 else {
                      l.delcar(latitude, longitude);
                      longitude++;
                      l.addcar(latitude, longitude);
                      return l;
                 }
             }
             
                       
                       
                       
                       
      private:
              int latitude; // latitude
              int longitude; // longitude
};

        

int main() {
    
    lot l;
    
    car a;
    l.addcar(a.getlat(), a.getlong());
    car b;
    l.addcar(b.getlat(), b.getlong());
    car c;
    l.addcar(c.getlat(), c.getlong());
    car d;
    l.addcar(d.getlat(), d.getlong());
    
    l.printlot();
    
    l = a.right(l);
    l = a.right(l);
    //while(1) {     
        for(int i=0; i<20; i++) {
                int j = i%4;
                switch(j) {
                    case 1:
                         l = a.down(l);
                         l = b.down(l);
                         l = c.left(l);
                         l = d.right(l);
                         break;
                    case 2:
                         l = a.right(l);
                         l = b.left(l);
                         l = c.up(l);
                         l = d.left(l);
                         break;
                    case 3:
                         l = a.down(l);
                         l = b.down(l);
                         l = c.right(l);
                         l = d.down(l);
                         break;
                    case 4:
                         l = a.up(l);
                         l = b.right(l);
                         l = c.right(l);
                         l = d.left(l);
                         break;
                    }
        } 
    //}
    
    l.printlot();
    
    cout << "Car A: " << a.getlat() << " " << a.getlong() << "\n";
    cout << "Car B: " << b.getlat() << " " << b.getlong() << "\n";
    cout << "Car C: " << c.getlat() << " " << c.getlong() << "\n";
    cout << "Car D: " << d.getlat() << " " << d.getlong() << "\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}
/* OUTPUT
Latitude:
1
Longitude:
1
Latitude:
2
Longitude:
2
Latitude:
3
Longitude:
3
Latitude:
4
Longitude:
4

 *
  *
   *
    *



*  * *




   *

Car A: 0 5
Car B: 0 0
Car C: 5 3
Car D: 0 3
Press any key to continue . . .
*/
