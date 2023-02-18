int persistence(long long n){
  if (n<10) {return 0;}
  int k=1, l=10,a,num=0;
  while(n>9){
   while(n*10>l){
     a=n%l;
     n=n-a;
     a=a/(l/10);
     l=l*10;
     k=k*a;
   }
    num++;
    n=k;
    k=1;
    l=10;
  }
  
  
  return num;
}