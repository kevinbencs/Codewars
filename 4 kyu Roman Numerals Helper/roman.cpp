#include <string>
#include <map>

class RomanHelper{
  public:
    std::string to_roman(unsigned int n){
      int Number[4];
      std::string RomanNumber;
      
      
      for(int i=3;i>-1;i--){
        Number[i]=n%10;
        n=n/10;
      }
      
      
      for(int i=0;i<Number[0];i++){ //thousand
        RomanNumber.push_back('M');
      }
      
      
      if (Number[1]==9) {RomanNumber+="CM";} //hundred
      
      else if (Number[1]>=5)
        {RomanNumber.push_back('D');
        for(int i=5;i<Number[1];i++){
          RomanNumber.push_back('C');}}
      
           else if (Number[1]==4) {RomanNumber+="CD";}
      
                else
                {for(int i=0;i<Number[1];i++){
                       RomanNumber.push_back('C');}}

          
      
     if (Number[2]==9) {RomanNumber+="XC";} //ten
      
      else if (Number[2]>=5)
        {RomanNumber.push_back('L');
        for(int i=5;i<Number[2];i++){
          RomanNumber.push_back('X');}}
      
           else if (Number[2]==4) {RomanNumber+="XL";}
      
                else
                {for(int i=0;i<Number[2];i++){
                       RomanNumber.push_back('X');}}

      
      if (Number[3]==9) {RomanNumber+="IX";} //one
      
      else if (Number[3]>=5)
        {RomanNumber.push_back('V');
        for(int i=5;i<Number[3];i++){
          RomanNumber.push_back('I');}}
      
           else if (Number[3]==4) {RomanNumber+="IV";}
      
                else
                {for(int i=0;i<Number[3];i++){
                       RomanNumber.push_back('I');}}

      
      return RomanNumber;
    }
  
  
    int from_roman(std::string rn){
      int length,number=0;
      
      length=rn.find("CM");
      if (length!=-1){
        number+=900;
        rn[length]=' ';
        rn[length+1]=' ';
      }
      
      length=rn.find("CD");
      if (length!=-1){
        number+=400;
        rn[length]=' ';
        rn[length+1]=' ';
      }
      
      length=rn.find("XC");
      if (length!=-1){
        number+=90;
        rn[length]=' ';
        rn[length+1]=' ';
      }
      
      length=rn.find("XL");
      if (length!=-1){
        number+=40;
        rn[length]=' ';
        rn[length+1]=' ';
      }
      
      length=rn.find("IX");
      if (length!=-1){
        number+=9;
        rn[length]=' ';
        rn[length+1]=' ';
      }
      
      length=rn.find("IV");
      if (length!=-1){
        number+=4;
        rn[length]=' ';
        rn[length+1]=' ';
      }
      
      length=rn.find('M');
      while (length!=-1){
        number+=1000;
        rn[length]=' ';
        length=rn.find('M');
      }
      
      length=rn.find('D');
      if (length!=-1){
        number+=500;
        rn[length]=' ';
      }
      
      length=rn.find('C');
      while (length!=-1){
        number+=100;
        rn[length]=' ';
        length=rn.find('C');
      }
      
      length=rn.find('L');
      if (length!=-1){
        number+=50;
        rn[length]=' ';
      }
      
      length=rn.find('X');
      while (length!=-1){
        number+=10;
        rn[length]=' ';
        length=rn.find('X');
      }
      
      length=rn.find('V');
      if (length!=-1){
        number+=5;
        rn[length]=' ';
      }
      
      length=rn.find('I');
      while (length!=-1){
        number+=1;
        rn[length]=' ';
        length=rn.find('I');
      }
        
      return number;
    }