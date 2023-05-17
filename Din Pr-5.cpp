#include <iostream> 
#include <math.h>
#include <conio.h>
 using namespace std;
 main ()
{ 
    setlocale(LC_ALL, "rus");//
    int m=8,n=7,put1=0,put21=0,put22=0,p,put3=0,cel,ras=0,x,y,k;
   //int g[n][m]; // int v[m][n-2]; 
    cout<<"\nEnter horizontal spacing values m(х)=";cin>>m;//horizontal- g[n][m] т=7  м=8  
    cout<<"\nEnter vertical spacing values    n(у)=";cin>>n;//  vertical-v[m][n] characterize the elemental matrix and parameters according to VENICEL
    /* for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {g[i][j]=0;v[i][j]=0;cout<< "\n"<<i<<j<<g[i][j];};*/
    
 int g[7][8]={{12,11,10,9,13,14,17,20},{11,9,8,7,9,13,14,18},{10,8,8,8,10,12,13,15},{12,13,12,10,11,13,15,20},
 {14,13,12,10,9,8,11,15},{10,14,13,10,11,13,14,17},{20,18,16,15,14,12,15,17}};
       /*for(int i=0;i<=n;i++)// data printout
       for(int j=0;j<=m-1;j++)
       cout<< "\n"<<"g["<<i<<"]["<<j<<"]="<<g[i][j];//ishlagi*/
    
 int v[9][6]={{11,10,8,7,9,10},{9,8,7,6,8,12},{10,10,8,9,9,13},
      {12,11,9,7,10,13},{13,10,9,8,11,14},{14,11,10,10,12,15},
      {14,12,11,11,13,14,},{12,10,8,10,12,13},{10,9,7,9,12,14}};
         /*for(int i=0;i<=m;i++)// data printout
         for(int j=0;j<n;j++)
         cout<< "\n"<<"v["<<i<<"]["<<j<<"]="<<v[i][j];*/

     // data entry on 0 line - correct
  /* for(int j=0;j<=1;j++)
   for(int i=0;i<m;i++)
   cin>>g[j][i];*/
  cout<<"\nEnter state coordinate values X,Y";
 cout<<"\nEnter values X="; cin>>x;
 cout<<"\nEnter values Y=";cin>>y;// у must satisfy the condition y<=n-1;
 k=x+y;// number of steps to the goal
 cout<<"\nOptimal route";// CONTROL
  if(x==0 ) for(int i=0;i<=k-1;i++)
   {ras=ras+v[x][i];cout<<"\n"  << i+1  <<"-step"<<"Chosen pathChosen path-put3--- top step flow="<< v[x][i] <<" total consumption="<<ras;}//work
  if(y==0 ) for(int i=0;i<k-1;i++)
  { ras=ras+g[y][i];cout<<"\n"  << i+1  <<"-step"<<"Chosen path put1--- on the right step consumption=" <<g[y][i]<<" total consumption="<<ras;}//work
  if(x==1) for(int i=k-1;i>=0;i--)
  { if(x==0){for(int d=y;d>0;d--)
    {ras=ras+v[0][d-1];cout<<"\n"  << d  <<"-step"<<" Chosen path-put3---  top step flow="<< v[0][d-1]<<"      total consumption="<<ras;}goto A;}
    if(y==0){for(int d=x;d>0;d--)
    { ras=ras+g[0][d-1];cout<<"\n"  << d  <<"-step"<<" Chosen path put1--- on the right step consumption=" <<g[0][d-1]<<" total consumption="<<ras;}goto A;}
  if (g[y][x-1]+v[x-1][y-1] < v[x][y-1]+g[y-1][x-1])
      {x=x-1; ras=ras+g[y][0];cout<<"\n"<<i+1<<"-step"<<" Chosen path-put21--- on the right step consumption="<<g[y][0]<<"  total consumption=" <<ras;}
   else{y=y-1;ras=ras+v[1][y];cout<<"\n"<<i+1<<"-step "<<"Chosen path-put22--- to the top"<<"  step rate="<<v[1][y]<<"   total consumption=" <<ras;}
 }if(y==1) for(int i=k-1;i>=0;i--)
  {if(x==0){for(int d=y;d>0;d--)
     {ras=ras+v[0][d-1];cout<<"\n"  << d  <<"-step"<<" Chosen path-put3---  top step flow="<< v[0][d-1]<<"      total consumption="<<ras;}goto A;}
   if(y==0){for(int d=x;d>0;d--)
     { ras=ras+g[0][d-1];cout<<"\n"  << d  <<"-step"<<"Chosen path put1--- on the right step consumption=" <<g[0][d-1]<<" total consumption="<<ras;}goto A;}
 if (g[y][x-1]+v[x-1][y-1] < v[x][y-1]+g[y-1][x-1])
      {x=x-1; ras=ras+g[y][x];cout<<"\n"<<i+1<<"-step"<<"Chosen path-put21--- on the right step consumption="<<g[y][x]<<" total consumption=" <<ras;}
   else{y=y-1;ras=ras+v[x][y];cout<<"\n"<<i+1<<"-step"<<"Chosen path-put22--- на верх"<<"  step rate="<<v[x][y]<<"   total consumption=" <<ras;}
 } 
 cout<<"\nChoosing a strategic path(put1,put2,put21,put22)";
     put1=  g[y][x-1]+ g[y][x-2];cout <<"\nput1="<<put1;
     put21= g[y][x-1]+ v[x-1][y-1];cout <<"\nput21="<<put21;
     put22= v[x][y-1]+ g[y-1][x-1];cout <<"\nput22="<<put22; 
     put3=  v[x][y-1]+ v[x][y-2]; cout <<"\nput3="<<put3; 
  if(put1<put3)  if(put1<put21)cel=1;
  if(put1<put3)  if(put1<put22)cel=1; 
  if(put21<put3) if(put21<put1)cel=21; else cel=22;
  if(put3<put1)  if(put3<put21)cel=3;
  if(put3<put1)  if(put3<put22)cel=3; 
  cout<<"\ncel="<<cel;
        switch (cel) //sel-selector
      {
    case 1:{ras=ras+put1;cout<<"\n"  << x+y <<"--step on the right step flow=\n" <<g[y][x-1]
         <<x+y-1<<"  --step on the right step flow=" <<g[y][x-2] <<"  total consumption="<<ras;x=x-2;y=y;break;}//ras-consumption
    case 21:{ras=g[y][x-1]; cout<<"\n"<< x+y <<"--step on the right step flow=\n"<<g[y][x-1]<< "\n"
         << x+y-1<<" --step up step flow="<<v[x-1][y-1]<<"  total consumption="<<put21;x=x-1;y=y-1;break;}
    case 22:ras=ras+put22;cout<<"\n"<< x+y <<"--step to the top \n "  <<x+y-1<<"  --step on the right " <<"  total consumption="<<ras;x=x-1;y=y-1;break;
    case 3:{ras=ras+put3;cout<<"\n"  << x+y  <<"--step up step flow="<<v[x][y-1]<< "\n"
    <<x+y-1<<"--step up step flow="  <<v[x][y-2]<<"    total consumption="<<ras;x=x;y=y-2;break;}     
    default:cout<<"Incorrect code";} 
     k=x+y;// number of steps to the goal after choosing a strategy
     for(int i=k-1;i>=0;i--)
      {if (g[y][x-1]+v[x-1][y-1] < v[x][y-1]+g[y-1][x-1])
     {ras=ras+g[y][x-1];cout<<"\n"<<i+1<<"-step"<<" Chosen path-put21--- on the right step consumption="<<g[y][x-1]<<"  total consumption=" <<ras;x=x-1;}
      else {ras=ras+v[x][y-1];cout<<"\n"<<i+1<<"-step "<<"Chosen path-put22--- to the top"<<"  step rate="<<v[x][y-1]<<"   total consumption=" <<ras;y=y-1;}}
A:  getch();
 return (0);                       
}
