int hashh[100001];
    int addMinChar(string str){    
       hashh[0]=-1;
      int i=0,j=1;
      while(j<str.size())
      {
          if(str[i]==str[j])
          {
              hashh[j]=i;
              i++;
              j++;
              
          }
          else
          {
              if(i==0)
              {
                  hashh[j]=-1;
              j++;
              
              continue;
              }
              i=i-1;
              while(hashh[i]!=-1)
              {
                  i=hashh[i];
                
                  if(str[i+1]==str[j])
                  break;
                  if(i==-1)
                  break;
                  else
                  continue;
              }
              if(str[i+1]==str[j])
              {hashh[j]=i+1;
              i=i+2;
              }
              else
              {hashh[j]=-1;
              i=0;}
              j++;
              
          }
      }
     
      int n=str.size();
      int p1=0,p2=n-1,ans=0;
      int indx=n;
      while(p2>p1)
      {
         
          if(str[p1]==str[p2])
          {
              p1++;
              p2--;
          }
          else
          {
              if(p1==0)
              {
                  indx=p2;
             
                  p2--;
                  continue;
              }
              int x=p1-1;
              while(true)
              {
                  
                 x=hashh[x];
                
                    if(str[x+1]==str[p2])
                  break;
                    if(x==-1)
                    break;
                  else
                  continue;
              }
              indx=p2+(x+1)+1;
              if(str[x+1]==str[p2])
              p1=x+2;
              else
              {p1=0;
              indx=p2;
              }
              p2--;
              
              continue;
          }
      }
      return n-indx;
        
    }
