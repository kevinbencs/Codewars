#include <vector>


class Decomp
{
  public:
  static std::vector<long long> decompose(long long n){
    std::vector<long long> result;
    long long number=0;

    for(long long i=n-1;i>0;i--){
     
      number=i*i;
      long long l=i-1;
      
      while(l>0){
        result.push_back(i);
        for(long long j=l;j>0;j--){
          if (number+j*j<=n*n) {number+=j*j; result.push_back(j); std::cout<<j<<std::endl;}
        }
        std::cout<<std::endl;
        if (number!=n*n) {l=result[1]-1; result.clear(); number=i*i;}
        else break;
      }
      
      if (number==n*n) break;
    }
    
    std::sort(result.begin(),result.end());
    return result;
    
  }
};