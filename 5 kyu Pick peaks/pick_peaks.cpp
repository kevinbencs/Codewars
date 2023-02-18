PeakData pick_peaks(const std::vector<int> &v) {
  std::vector <int> pos, peaks;
  
  for(int i=1;i<int(v.size()-1);i++){
    if(v[i-1]<v[i] && v[i]>v[i+1]) {pos.push_back(i);peaks.push_back(v[i]);}
    if (v[i-1]<v[i] && v[i]==v[i+1]) 
    {int k=i;
      while(v[i]==v[i+1] && i<int(v.size()-2)) {i++;}
      if (v[i+1]<v[i]) {pos.push_back(k);peaks.push_back(v[i]);}
    }
    
  }
  

  PeakData result;
  result={pos,peaks};
  
  return result;
}