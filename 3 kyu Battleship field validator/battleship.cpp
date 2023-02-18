#include <vector>

class ship_number{
  public:
  
  void get_one_number(int x){
    one_number+=x;
  }
  void get_two_number(int y){
    two_number+=y;
  }
  void get_three_number(int z){
    three_number+=z;
  }
  void get_four_number(int k){
    four_number+=k;
  }
  
  int give_one_number(){
    return one_number;
  }
  
  int give_two_number(){
    return two_number;
  }
  
  int give_three_number(){
    return three_number;
  }
  
  int give_four_number(){
    return four_number;
  }
  
  private:
  int one_number=0, two_number=0, three_number=0, four_number=0;
};

bool validate_battlefield(std::vector< std::vector<int> > field) {
  ship_number ship;
  
  
  
  for(unsigned int i=0;i<field.size();i++){
    for(unsigned int j=0;j<field[i].size();j++){
      if (field[i][j]==1) {
        if (j!=0) if (field[i+1][j+1]==1 || field[i+1][j-1]==1) return false;
        else if (field[i+1][j+1]==1) return false;
        
        if (field[i][j+1]==1){
          if(field[i+1][j]==1 || field[i+1][j+2]==1) return false;
          
          if (field[i][j+2]==1){
            if (field[i+1][j+3]==1) return false;
              
            if (field[i][j+3]==1) {
              if (field[i+1][j+4]==1 || field[i][j+4]==1) return false;
              ship.get_four_number(1);
              field[i][j]=0;
              field[i][j+1]=0;
              field[i][j+2]=0;
              field[i][j+3]=0;
            }
            else{
              ship.get_three_number(1);
              field[i][j]=0;
              field[i][j+1]=0;
              field[i][j+2]=0;
            }
          }
          else {
            ship.get_two_number(1);
            field[i][j]=0;
            field[i][j+1]=0;
          }
        }
        else if (field[i+1][j]==1){
          if (j!=0) if (field[i+2][j+1]==1 || field[i+2][j-1]==1 ) return false;
          else if (field[i+2][j+1]==1) return false;
            
          if (field[i+2][j]==1){
            if (j!=0) if ( field[i+3][j+1]==1 ||field[i+3][j-1]==1 ) return false;
            else if (field[i+3][j+1]==1 ) return false;
              
            if (field[i+3][j]==1) {
              if (j!=0) if (field[i+4][j+1]==1 || field[i+4][j-1]==1 || field[i+4][j]==1) return false;
              else if (field[i+4][j+1]==1 || field[i+4][j]==1) return false;
                
              ship.get_four_number(1);
              field[i][j]=0;
              field[i+1][j]=0;
              field[i+2][j]=0;
              field[i+3][j]=0;
            }
            else {
              ship.get_three_number(1);
              field[i][j]=0;
              field[i+1][j]=0;
              field[i+2][j]=0;
            }
          }
          else {
            ship.get_two_number(1);
            field[i][j]=0;
            field[i+1][j]=0;
          }
        }
        else {
          ship.get_one_number(1);
          field[i][j]=0;
        }
      }

    }
  }
  
  return ship.give_four_number()==1 && ship.give_three_number()==2 && ship.give_two_number()==3 && ship.give_one_number()==4;
}