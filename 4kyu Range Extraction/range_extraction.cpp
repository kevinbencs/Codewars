#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string res;
  int d=-1;
  
  for(unsigned long i=0;i<args.size();i++){
    if (args[i+1]-1==args[i]) { if (d==-1) {d=i;}
                              }
    else {if (d!=-1){ 
                     if (i==args.size()-1) {if (i-d>=2) {res+=std::to_string(args[d])+'-'+std::to_string(args[i]); d=-1;}
                                            else {res+=std::to_string(args[d])+','+std::to_string(args[i]); d=-1;}
                                           }
                     else{ if (i-d>=2) {res+=std::to_string(args[d])+'-'+std::to_string(args[i])+','; d=-1;}
                           else {res+=std::to_string(args[d])+','+std::to_string(args[i])+','; d=-1;}
                         }
                    }
      
          else {if (i==args.size()-1) {res+=std::to_string(args[i]);}
                else  {res+=std::to_string(args[i])+',';}
               }
         }
  }
  
  return res;
}