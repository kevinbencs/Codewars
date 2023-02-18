#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::string res;
  res.push_back('(');
  for(int i=0;i<3;i++)
  {
    res+=std::to_string(arr[i]);
  }
  res.push_back(')');
  res.push_back(' ');
  for(int i=3;i<6;i++)
  {
    res+=std::to_string(arr[i]);
  }
  res.push_back('-');
  for(int i=6;i<10;i++)
  {
    res+=std::to_string(arr[i]);
  }
  return res;
}