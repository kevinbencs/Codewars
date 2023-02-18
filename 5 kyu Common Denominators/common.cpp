#include <string>
#include <iostream>
#include <cmath>

class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst){
      unsigned long long number,j,l=1;
      unsigned int k=0;
      std::string result;
      std::vector<unsigned long long> v;
      
      for(unsigned int i=0;i<lst.size();i++){
        l*=lst[i][1];
      }
      
      unsigned long long seged, kell;
      for(unsigned int i=0;i<lst.size();i++){
        seged=l/lst[i][1];
        lst[i][0]=lst[i][0]*seged;
        lst[i][1]=l;
      }
      
     
      j=1;
     
      while(j<=sqrt(lst[0][1])){
        j++;
        k=1;
        
        for(unsigned int i=0;i<lst.size();i++){
            if (lst[i][0]%j!=0) k=0;
          }
        if (lst[0][1]%j!=0) k=0;
 
        while(k==1){
          for(unsigned int i=0;i<lst.size();i++){
            lst[i][0]=lst[i][0]/j;
            lst[i][1]=lst[i][1]/j;
            
          }
          for(unsigned int i=0;i<lst.size();i++){
            if (lst[i][0]%j!=0) k=0;
          }
          if (lst[0][1]%j!=0) k=0;
        }  
      }
      
      for(unsigned int i=0;i<lst.size();i++){
        number=lst[i][1];
        kell=lst[i][0];
        result.push_back('(');
        result+=std::to_string(kell);
        result.push_back(',');
        result+=std::to_string(number);
        result.push_back(')');
      }
      return result;
    }
};