using namespace std;
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window){
      if (window>=h || h<=0 || bounce<=0 || bounce>=1) return -1;
      int number=1;
      h=h*bounce;
     while(h>window){
        h=h*bounce;
        number+=2;
      } 
      return number;
    }
};