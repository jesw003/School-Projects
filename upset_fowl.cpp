#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const double pi = 3.14159265;
const double grav = 9.8; // Earth gravity (m/s^2)

// Given time, angle, velocity, and gravity
// Update x and y values
void Trajectory(double t, double a, double v,
                double& x, double& y) {
   x = v * t * cos(a);
   y = v * t * sin(a) - 0.5 * grav * t * t;
   return;
}

// convert degree value to radians
double DegToRad(double deg) {
    return ((deg * pi) / 180.0);
}

// print time, x, and y values
void PrintUpdate(double t, double x, double y) {
    cout << "Time " << fixed << setprecision(0)
         << setw(3) << t << "   x = " << setw(3)
         << x << "   y = " << setw(3) << y << endl;
    return;
}

// Prints game's intro message
void PrintIntro() {
   cout << "Welcome to Upset Fowl!\n";
    cout << "The objective is to hit the Mean Swine.\n";// FIXME Add code that outputs intro message
   return;
}

// Given swine's current horiz. position
// Get user's desired launch angle and velocity for fowl
void GetUsrInpt(double swineX, double &fowlAngle, double &fowlVel) {
   cout << "\nThe Mean Swine is " << swineX << " meters away.\n";
   cout << "Enter launch angle (deg): ";
   cin >> fowlAngle;
   cout << endl;
   fowlAngle = DegToRad(fowlAngle); // convert to radians

   cout << "Enter launch velocity (m/s): ";
   cin >> fowlVel;
   cout << endl;
   return;
}


// Given fowl launch angle and velocity
// Return horiz. landing position of fowl
double LaunchFowl(double fowlAngle, double fowlVel) {
   double t = 1.0; // time (s)
   double fowlY = 0.0; // object's height above ground (m)
   double fowlX = 0.0;
   do {
       PrintUpdate(t, fowlX, fowlY);
       Trajectory(t, fowlAngle, fowlVel, fowlX, fowlY);
       t=t+1.0;
   } while ( fowlY > 0.0 ); // while above ground
   PrintUpdate(t, fowlX, fowlY);

   return fowlX;
}


// Given fowl's horiz. landing position and swine's horiz. position
bool DtrmnIfHit(double fowlLandingX, double swineX) {
   double beforeSwineX = 0.0; // distance before swine that is acceptable as a hit (m)
    bool didHitSwine = true;// did hit the swine?
   beforeSwineX = swineX - 30;
   if ((fowlLandingX <= swineX) && (fowlLandingX >= beforeSwineX)) {
     
      
       didHitSwine=true;
   } else{
       
       
       didHitSwine=false;
   }
       
   
   return didHitSwine;
}



int main() {
    // time (s)
    // object's height above ground (m)
    double fowlAngle = 0.0; // angle of launch (rad)
    double fowlVel = 0.0; // velocity (m/s)
    bool didHitSwine= true;
    double fowlLandingX = 0.0; // object's horiz. dist. from start (m)
    double swineX = 40.0; // distance to swine (m)
   // distance before swine that is acceptable as a hit (m)
    // did hit the swine?
    int tries = 4;

   srand(20); //to ensure the correct output for grading
   swineX = (rand() % 201) + 50;

  do{ PrintIntro();
    
   GetUsrInpt(swineX, fowlAngle, fowlVel);

   fowlLandingX = LaunchFowl(fowlAngle, fowlVel);

   didHitSwine =DtrmnIfHit(fowlLandingX, swineX);
   
   if (didHitSwine==true)
        {
            cout<<"Hit'em!!!"<<endl;
            break;
        }
        else if(didHitSwine==false)
        {
            cout<<"Missed'em..."<<endl;
        }
        tries++;
        cout<<endl;
        
  } while(didHitSwine==false && tries<4);
    return 0;
}