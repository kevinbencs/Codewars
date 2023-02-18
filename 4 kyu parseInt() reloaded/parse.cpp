#include <string>

long parse_int(std::string number) {
  std::map<std::string, long> m { {"one", 1},
                                {"two", 2}, 
                                {"three", 3},
                                {"four", 4}, 
                                {"five", 5},
                                {"six", 6}, 
                                {"seven", 7},
                                {"eight", 8},
                                {"nine", 9},
                                {"ten", 10},
                                {"eleven", 11},
                                {"twelve", 12},
                                {"thirteen", 13},
                                {"fourteen", 14},
                                {"fifteen", 15},
                                {"sixteen", 16},
                                {"seventeen", 17},
                                {"eighteen", 18},
                                {"nineteen", 19},
                                {"twenty", 20},
                                {"thirty", 30},
                                {"forty", 40},
                                {"fifty", 50},
                                {"sixty", 60},
                                {"seventy", 70},
                                {"eighty", 80},
                                {"ninety", 90},
                                {"hundred", 100},
                                {"thousand", 1000},
                                {"million", 1000000}};
  
  
  std::string s;
  long n=0;
  unsigned int i=0,j=0;
  std::vector<long> k;
  
  while(i<number.length()){
    for(i=j;i<number.length();i++){
      if (number[i]!=' ' && number[i]!='-') s.push_back(number[i]);
      else {i++;break;}
    }
    j=i;
    if (s!="and"){
      n=m[s];
      k.push_back(n);
     // std::cout<<n<<std::endl;
    }
    
    s.clear();
  }
  n=0;
  j=0;
  
  for(i=0;i<k.size();i++){
    if (k[i]==1000000) {n=n+k[i]*k[i-1]; j=i+1;}
    else if (k[i]==100 && k[i+1]==1000) {n=n+k[i-1]*k[i]*k[i+1]; j=i+2;}
         else if(k[i]==100 && k[i+2]==1000) {n=n+k[i-1]*k[i]*k[i+2]; j=i+3;}
              else if(k[i]==100 && k[i+3]==1000) {n=n+k[i-1]*k[i]*k[i+3]; j=i+4;}
                   else if (k[i]==1000 && i>=2 && (k[i-2]!=100 && k[i-2]!=1000000 && k[i-1]!=100)) {n=n+k[i]*(k[i-1]+k[i-2]); j=i+1;}
                        else if (k[i]==1000 && k[i-1]!=100) {n=n+k[i]*k[i-1]; j=i+1;}
                             else if (k[i]==100) {n=n+k[i]*k[i-1]; j=i+1;}
                   
  }
  
  for(i=j;i<k.size();i++){
     n=n+k[i];
  }
  
  return n;
}