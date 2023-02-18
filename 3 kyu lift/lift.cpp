#include <vector>


void enter_up(std::vector<int> &floor, std::vector<int> &seged, const int j,int &k, const int capacity,std::vector<int> &v){
  int l=k;
  //the lift stop
  int f=l;
  for(unsigned int i=0;i<floor.size();i++){
    if (floor[i]>j){
      f++;
    }  
  }
  //capacity is ok
  for(unsigned int i=0;i<floor.size() && k<capacity;i++){
    if (floor[i]>j){
      k++;
      seged.push_back(floor[i]);
      floor[i]=-1;
    }  
  }
  
  if (f>l && j!=v[v.size()-1]) v.push_back(j);
}  


void enter_down(std::vector<int> &floor, std::vector<int> &seged, const int j,int &k, const int capacity,std::vector<int> &v){
  int l=k;
  //the lift stop
  int f=l;
  for(unsigned int i=0;i<floor.size();i++){
    if (floor[i]<j && floor[i]>-1){
      f++;
    }  
  }
  //capacity is ok
  for(unsigned int i=0;i<floor.size() && k<capacity;i++){
    if (floor[i]<j && floor[i]>-1){
      k++;
      seged.push_back(floor[i]);
      floor[i]=-1;
    }  
  }
  
  
  
  if (f>l && j!=v[v.size()-1]) v.push_back(j);
}



void up(std::vector<std::vector<int>> &queues,const int capacity, std::vector<int>&v, std::vector<int> &seged, int &k){
  for(int i=0;i<int(queues.size());i++){
    for(int j=0;j<int(seged.size());j++){
      if (seged[j]==i){
        if (i!=v[v.size()-1]) {v.push_back(i);}  
        seged[j]=-1; 
        k--;}}
    if (!queues[i].empty()) {enter_up(queues[i],seged,  i,k, capacity,v);}
  }
}




void down(std::vector<std::vector<int>> &queues,const int capacity, std::vector<int>&v, std::vector<int> &seged, int &k){
  for(int i=int(queues.size())-1;i>-1;i--){
    for(int j=0;j<int(seged.size());j++){
      if (seged[j]==i){
        if (i!=v[v.size()-1]) {v.push_back(i);}  
        seged[j]=-1; 
        k--;}}
    if (!queues[i].empty()) {enter_down(queues[i],seged,  i,k, capacity,v);}
  }
}


std::vector<int> the_lift(const std::vector<std::vector<int>> &queues, int capacity) {
  std::vector<std::vector<int>> kell=queues;
  std::vector<int> v,seged;
  int k=0;
  v.push_back(0);
  int l=0;
  
  do{
    l=0;
    up(kell,capacity,v,seged,k);
    down(kell,capacity,v,seged,k);
    
    
    for(int i=0;i<int(kell.size());i++){
      if (!kell[i].empty()){
        for(int j=0;j<int(kell[i].size());j++){
          if (kell[i][j]>-1) l=1; 
        }
      }
    } 
  }while(l==1);
  
  
  if (v[v.size()-1]!=0) v.push_back(0);
  
  return v;
}