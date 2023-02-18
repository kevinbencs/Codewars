#include <string>
#include <utility>



std::pair<std::string, int> encode(const std::string &s) {
  if (s.empty()) return {"", 0};
  std::vector<std::string> matrix;
  std::string k,l;
  l=s;
  matrix.push_back(l);
  int number;
  
  
  for(unsigned int i=0;i<s.size()-1;i++){
    k.push_back(l[l.size()-1]);
    for(unsigned int j=0;j<s.size()-1;j++){
      k.push_back(l[j]);
    }
    matrix.push_back(k);
    l=k;
    k.clear();
    
  }
  l.clear();
  std::sort(matrix.begin(),matrix.end());
  
  for(unsigned int i=0;i<matrix.size();i++){
    if (matrix[i]==s) number=i;
    l.push_back(matrix[i][s.size()-1]);
    std::cout<<matrix[i]<<std::endl;
  }
 
  return {l, number};
}



std::string decode(const std::string &s, int n) {
  if (s.empty()) return "";
  std::string k,result,l;
  k=s;
  l=s;
  std::sort(k.begin(),k.end());
  char c;
  int hely,m;
  result.push_back(k[n]);
  c=k[n];
  
  
  for(unsigned int t=1;t<l.size();t++){
    
    hely=0;
    for(int j=0;j<k.size();j++){
      if (c==k[j]){hely++;}
      if (j==n) {k[j]='-';break;} 
    }
    
    m=0;
    for(unsigned int i=0;i<l.size();i++){
      if (c==l[i]) {m++;}
      if (hely==m) {n=i;break;}
    }
    
    
    c=k[n];
    l[n]='-';
    result.push_back(c);
    }
  

  return result;
}