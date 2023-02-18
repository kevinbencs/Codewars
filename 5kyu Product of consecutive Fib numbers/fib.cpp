#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod){
    std::vector<ull> v;
    unsigned long long f_1, f_2,c;
    f_1=0;
    f_2=1;
    
    while(f_1*f_2<prod){
      c=f_1;
      f_1=f_2;
      f_2=f_1+c;
    }
      
    if (f_1*f_2==prod) return {f_1, f_2, true};
    else return {f_1, f_2, false};
     
  }
};