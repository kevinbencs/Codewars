#include <utility>
#include <vector>
#include <math.h>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n){
      std::vector<std::pair<long long, long long>> v;
      std::vector<long long> seged;
  
      for(long long i=m;i<=n;i++){
        long long sum=0;
        seged.clear();
        
        for(long long j=1;j<=sqrt(i);j++){
          if (i%j==0) {seged.push_back(j); sum+=j*j;}
        }
        
        for(long long j=0;j<seged.size()-1;j++){
          sum+=i/seged[j]*i/seged[j];
        }
        
        if (i/seged[seged.size()-1]!=seged[seged.size()-1]) sum+=i/seged[seged.size()-1]*i/seged[seged.size()-1];
        
        if (int(sqrt(sum))*int(sqrt(sum))==sum) v.push_back({i, sum});
        }
      return v;
      }
};