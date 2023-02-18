#include <cmath>


long countDivisors(const long& n) {
  long divisor=0;
  
  long Sqrt=static_cast<int>(sqrt(n));
  
  //int i;
  /*for(i=1;i<Sqrt;i++){
    if (n%i==0) divisor++;
    
  }
  
  divisor*=2;
  if (i==Sqrt) {divisor++;}
  
  if (n==1) {return 1;}
  else {return countDivisors(n-1)+divisor;}*/
  
    
  
  for(long i=1;i<Sqrt+1;i++){
   divisor+=n/i;
  }
  
  divisor*=2;
   return divisor-Sqrt*Sqrt; 
}