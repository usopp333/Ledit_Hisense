 // edit by LuZequan
 // 2016-01-19
#include <stdlib.h>
#include <math.h>
#include "ldata.h"

  double scalefactor,pi;
  double center_x,center_y,width,w_in,w_l1,w_l2,w_l3,r;
  double L_f,theta,d_in,d_out,L_t,L_t1,io_y,i_x,o_x,l_d;
  double p_gr,a_gr;


  double T[200],P[200],D[200],To[100];

  double taper_x,taper_y,w,l_s,l_s1,l_s2,l_s_dis,l_s_w1,l_s_w2,l_s_w3,l_s_w4,l_s_w,w_tip;
  double taper_L,taper_w,G_L,gc_dis,G_x,G_y;

  int	  N,N1,N2,N_out,n_gr,gc_n;
  int    i,j,k,v;

  double width_shallow,l_a_shallow,l_out_shallow,w_shallow,l_a_staper,l_out_staper;

  double period,gc_a;
  
  /* Parameter Setting */


void edg_edit(LFile file, LCell cell)
{
	
	
	
scalefactor=1.0E3;
pi=3.1415926;
  
center_x=0+47.255*2*scalefactor; //需要将零点调整到器件的中心
center_y=0-5*scalefactor; //需要将零点调整到器件的中心
width=500;
r=20*scalefactor;
L_f= 93.3381*scalefactor;
theta=pi/4;
N=4;
N1=19;
N2=29;
d_in=1.85*scalefactor;
d_out=1.85*scalefactor;


L_t=12*scalefactor;
io_y=center_y+L_f-(L_f*cos(theta)+L_t)*sin(theta)-50*scalefactor;
i_x=center_x-150*scalefactor;
o_x=center_x-50*scalefactor;
l_d=20*scalefactor;


w_in=2*scalefactor;
w_l1=2*scalefactor;
w_l2=6*scalefactor;
w_l3=0.4*scalefactor;


p_gr=0.6*scalefactor;
a_gr=0.5;
n_gr=20;




taper_L=400*scalefactor;
taper_w=12*scalefactor;
G_L=5*scalefactor;
gc_dis=200;
period=490;
gc_a=0.5;
gc_n=26;


T[1]=-0.58169;
T[2]=-0.53999;
T[3]=-0.50209;
T[4]=-0.4667;
T[5]=-0.43309;
T[6]=-0.40081;
T[7]=-0.36954;
T[8]=-0.33908;
T[9]=-0.30924;
T[10]=-0.27992;
T[11]=-0.25101;
T[12]=-0.22244;
T[13]=-0.19413;
T[14]=-0.16605;
T[15]=-0.13814;
T[16]=-0.11036;
T[17]=-0.082691;
T[18]=-0.055089;
T[19]=-0.027534;
T[20]=0;
T[21]=0.027534;
T[22]=0.055087;
T[23]=0.08268;
T[24]=0.11033;
T[25]=0.13805;
T[26]=0.16586;
T[27]=0.19378;
T[28]=0.22182;
T[29]=0.25;
T[30]=0.27832;
T[31]=0.30682;
T[32]=0.3355;
T[33]=0.36437;
T[34]=0.39347;
T[35]=0.42279;
T[36]=0.45236;
T[37]=0.4822;
T[38]=0.51233;
T[39]=0.54277;
T[40]=0.57353;
T[41]=0.60465;
T[42]=0.63614;
T[43]=0.66803;
T[44]=0.70035;
T[45]=0.73313;
T[46]=0.76641;
T[47]=0.80021;
T[48]=0.83459;
T[49]=0.86958;




P[1]=0.1463;
P[2]=0.039485;
P[3]=0.049727;
P[4]=0.12668;
P[5]=0.19453;
P[6]=0.25535;
P[7]=0.31057;
P[8]=0.36121;
P[9]=0.40807;
P[10]=0.45175;
P[11]=0.49272;
P[12]=0.53136;
P[13]=0.56799;
P[14]=0.60287;
P[15]=0.63621;
P[16]=0.6682;
P[17]=0.69898;
P[18]=0.7287;
P[19]=0.75747;
P[20]=0.7854;
P[21]=0.81256;
P[22]=0.83905;
P[23]=0.86492;
P[24]=0.89025;
P[25]=0.91509;
P[26]=0.93948;
P[27]=0.96349;
P[28]=0.98714;
P[29]=1.0105;
P[30]=1.0335;
P[31]=1.0564;
P[32]=1.079;
P[33]=1.1014;
P[34]=1.1237;
P[35]=1.1458;
P[36]=1.1679;
P[37]=1.1899;
P[38]=1.2118;
P[39]=1.2337;
P[40]=1.2556;
P[41]=1.2775;
P[42]=1.2994;
P[43]=1.3215;
P[44]=1.3436;
P[45]=1.3658;
P[46]=1.3882;
P[47]=1.4107;
P[48]=1.4335;
P[49]=1.4565;




D[1]=3.0661*scalefactor;
D[2]=3.0764*scalefactor;
D[3]=2.8944*scalefactor;
D[4]=2.6593*scalefactor;
D[5]=2.4816*scalefactor;
D[6]=2.3454*scalefactor;
D[7]=2.2361*scalefactor;
D[8]=2.1497*scalefactor;
D[9]=2.0781*scalefactor;
D[10]=2.0209*scalefactor;
D[11]=1.9727*scalefactor;
D[12]=1.9346*scalefactor;
D[13]=1.9023*scalefactor;
D[14]=1.8776*scalefactor;
D[15]=1.8568*scalefactor;
D[16]=1.842*scalefactor;
D[17]=1.83*scalefactor;
D[18]=1.823*scalefactor;
D[19]=1.8179*scalefactor;
D[20]=1.8172*scalefactor;
D[21]=1.8178*scalefactor;
D[22]=1.8224*scalefactor;
D[23]=1.828*scalefactor;
D[24]=1.8372*scalefactor;
D[25]=1.8472*scalefactor;
D[26]=1.8607*scalefactor;
D[27]=1.8747*scalefactor;
D[28]=1.892*scalefactor;
D[29]=1.9098*scalefactor;
D[30]=1.9309*scalefactor;
D[31]=1.9524*scalefactor;
D[32]=1.9772*scalefactor;
D[33]=2.0025*scalefactor;
D[34]=2.0311*scalefactor;
D[35]=2.0602*scalefactor;
D[36]=2.0928*scalefactor;
D[37]=2.1259*scalefactor;
D[38]=2.1627*scalefactor;
D[39]=2.2002*scalefactor;
D[40]=2.2416*scalefactor;
D[41]=2.284*scalefactor;
D[42]=2.3306*scalefactor;
D[43]=2.3784*scalefactor;
D[44]=2.4308*scalefactor;
D[45]=2.485*scalefactor;
D[46]=2.5443*scalefactor;
D[47]=2.6058*scalefactor;
D[48]=2.6732*scalefactor;
D[49]=2.7437*scalefactor;




To[1]=0.7551;
To[2]=0.72567;
To[3]=0.69703;
To[4]=0.66908; 	




EDG_gratings_bragg(file, cell);


InOut(file, cell);



}


/*End of main*/




void InOut(LFile file, LCell cell)
{




LPoint       Points [ 1002 ];
LObject      Torus1;
 
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  


	Points [0].x=center_x-L_f*cos(theta+(d_in/2/cos(theta)/L_f))*sin(theta+(d_in/2/cos(theta)/L_f));
	Points [0].y=center_y+L_f*sin(theta+(d_in/2/cos(theta)/L_f))*sin(theta+(d_in/2/cos(theta)/L_f));
	Points [1].x=center_x-(L_f*cos(theta)+L_t)*sin(theta)-width/2*cos(theta);
	Points [1].y=center_y+L_f-(L_f*cos(theta)+L_t)*cos(theta)+width/2*sin(theta);
	Points [3].x=center_x-L_f*cos(theta-(d_in/2/cos(theta)/L_f))*sin(theta-(d_in/2/cos(theta)/L_f));
	Points [3].y=center_y+L_f*sin(theta-(d_in/2/cos(theta)/L_f))*sin(theta-(d_in/2/cos(theta)/L_f));
	Points [2].x=center_x-(L_f*cos(theta)+L_t)*sin(theta)+width/2*cos(theta);
	Points [2].y=center_y+L_f-(L_f*cos(theta)+L_t)*cos(theta)-width/2*sin(theta);
	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);


width_shallow=3*scalefactor;
w_shallow=1*scalefactor;
l_a_staper=L_t*0.6;

	Points [0].x=center_x-L_f*cos(theta+(width_shallow/2/cos(theta)/L_f))*sin(theta+(width_shallow/2/cos(theta)/L_f));
	Points [0].y=center_y+L_f*sin(theta+(width_shallow/2/cos(theta)/L_f))*sin(theta+(width_shallow/2/cos(theta)/L_f));
	Points [1].x=center_x-(L_f*cos(theta)+l_a_staper)*sin(theta)-w_shallow/2*cos(theta);
	Points [1].y=center_y+L_f-(L_f*cos(theta)+l_a_staper)*cos(theta)+w_shallow/2*sin(theta);
	Points [3].x=center_x-L_f*cos(theta-(width_shallow/2/cos(theta)/L_f))*sin(theta-(width_shallow/2/cos(theta)/L_f));
	Points [3].y=center_y+L_f*sin(theta-(width_shallow/2/cos(theta)/L_f))*sin(theta-(width_shallow/2/cos(theta)/L_f));
	Points [2].x=center_x-(L_f*cos(theta)+l_a_staper)*sin(theta)+w_shallow/2*cos(theta);
	Points [2].y=center_y+L_f-(L_f*cos(theta)+l_a_staper)*cos(theta)-w_shallow/2*sin(theta);

	LPolygon_New ( cell, LLayer_Find( file, "Grating70"  ), Points, 4);

width_shallow=5*scalefactor;
w_shallow=0.4*scalefactor;
l_a_staper=L_t*1.2;


	Points [0].x=center_x-L_f*cos(theta+(width_shallow/2/cos(theta)/L_f))*sin(theta+(width_shallow/2/cos(theta)/L_f));
	Points [0].y=center_y+L_f*sin(theta+(width_shallow/2/cos(theta)/L_f))*sin(theta+(width_shallow/2/cos(theta)/L_f));
	Points [1].x=center_x-(L_f*cos(theta)+l_a_staper)*sin(theta)-w_shallow/2*cos(theta);
	Points [1].y=center_y+L_f-(L_f*cos(theta)+l_a_staper)*cos(theta)+w_shallow/2*sin(theta);
	Points [3].x=center_x-L_f*cos(theta-(width_shallow/2/cos(theta)/L_f))*sin(theta-(width_shallow/2/cos(theta)/L_f));
	Points [3].y=center_y+L_f*sin(theta-(width_shallow/2/cos(theta)/L_f))*sin(theta-(width_shallow/2/cos(theta)/L_f));
	Points [2].x=center_x-(L_f*cos(theta)+l_a_staper)*sin(theta)+w_shallow/2*cos(theta);
	Points [2].y=center_y+L_f-(L_f*cos(theta)+l_a_staper)*cos(theta)-w_shallow/2*sin(theta);

	LPolygon_New ( cell, LLayer_Find( file, "Slab90"  ), Points, 4);


	L_t1=(center_y+L_f-(L_f*cos(theta)+L_t)*cos(theta)-io_y)/cos(theta);

	Points [0].x=center_x-(L_f*cos(theta)+L_t)*sin(theta)+width/2*cos(theta);
	Points [0].y=center_y+L_f-(L_f*cos(theta)+L_t)*cos(theta)-width/2*sin(theta);
	Points [1].x=center_x-(L_f*cos(theta)+L_t+L_t1)*sin(theta)+width/2*cos(theta);
	Points [1].y=io_y-width/2*sin(theta);
	Points [3].x=center_x-(L_f*cos(theta)+L_t)*sin(theta)-width/2*cos(theta);
	Points [3].y=center_y+L_f-(L_f*cos(theta)+L_t)*cos(theta)+width/2*sin(theta);
	Points [2].x=center_x-(L_f*cos(theta)+L_t+L_t1)*sin(theta)-width/2*cos(theta);
	Points [2].y=io_y+width/2*sin(theta);

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);


	tParams.ptCenter.x = center_x-(L_f*cos(theta)+L_t+L_t1)*sin(theta)-r*cos(theta);
	tParams.ptCenter.y = io_y+r*sin(theta);	
	tParams.nInnerRadius = r-width/2;
	tParams.nOuterRadius = r+width/2;
	tParams.dStartAngle =-90;
	tParams.dStopAngle = 180*(-theta/pi);

	LTorus_CreateNew(cell, LLayer_Find( file, "Rib130"  ), &tParams); 

	Points [0].x=center_x-(L_f*cos(theta)+L_t+L_t1)*sin(theta)-r*cos(theta);
	Points [0].y=io_y+r*sin(theta)-r-width/2;
	Points [1].x=center_x-(L_f*cos(theta)+L_t+L_t1)*sin(theta)-r*cos(theta);
	Points [1].y=io_y+r*sin(theta)-r+width/2;
	Points [2].x=i_x;
	Points [2].y=io_y+r*sin(theta)-r+width/2;
	Points [3].x=i_x;
	Points [3].y=io_y+r*sin(theta)-r-width/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);

	
	taper_x=i_x;
	taper_y=io_y+r*sin(theta)-r;

	left_GC(file, cell);




	for (j=1;j<=N ;j++ )
	{
	Points [0].x=center_x-L_f*cos(To[j]-(d_out/2/cos(To[j])/L_f))*sin(To[j]-(d_out/2/cos(To[j])/L_f));
	Points [0].y=center_y+L_f*sin(To[j]-(d_out/2/cos(To[j])/L_f))*sin(To[j]-(d_out/2/cos(To[j])/L_f));
	Points [1].x=center_x-(L_f*cos(To[j])+L_t)*sin(To[j])+width/2*cos(To[j]);
	Points [1].y=center_y+L_f-(L_f*cos(To[j])+L_t)*cos(To[j])-width/2*sin(To[j]);
	Points [2].x=center_x-(L_f*cos(To[j])+L_t)*sin(To[j])-width/2*cos(To[j]);
	Points [2].y=center_y+L_f-(L_f*cos(To[j])+L_t)*cos(To[j])+width/2*sin(To[j]);
	Points [3].x=center_x-L_f*cos(To[j]+(d_out/2/cos(To[j])/L_f))*sin(To[j]+(d_out/2/cos(To[j])/L_f));
	Points [3].y=center_y+L_f*sin(To[j]+(d_out/2/cos(To[j])/L_f))*sin(To[j]+(d_out/2/cos(To[j])/L_f));

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);



width_shallow=3*scalefactor;
w_shallow=1*scalefactor;
l_a_staper=L_t*0.6;


	Points [0].x=center_x-L_f*cos(To[j]-(width_shallow/2/cos(To[j])/L_f))*sin(To[j]-(width_shallow/2/cos(To[j])/L_f));
	Points [0].y=center_y+L_f*sin(To[j]-(width_shallow/2/cos(To[j])/L_f))*sin(To[j]-(width_shallow/2/cos(To[j])/L_f));
	Points [1].x=center_x-(L_f*cos(To[j])+l_a_staper)*sin(To[j])+w_shallow/2*cos(To[j]);
	Points [1].y=center_y+L_f-(L_f*cos(To[j])+l_a_staper)*cos(To[j])-w_shallow/2*sin(To[j]);
	Points [2].x=center_x-(L_f*cos(To[j])+l_a_staper)*sin(To[j])-w_shallow/2*cos(To[j]);
	Points [2].y=center_y+L_f-(L_f*cos(To[j])+l_a_staper)*cos(To[j])+w_shallow/2*sin(To[j]);
	Points [3].x=center_x-L_f*cos(To[j]+(width_shallow/2/cos(To[j])/L_f))*sin(To[j]+(width_shallow/2/cos(To[j])/L_f));
	Points [3].y=center_y+L_f*sin(To[j]+(width_shallow/2/cos(To[j])/L_f))*sin(To[j]+(width_shallow/2/cos(To[j])/L_f));

	LPolygon_New ( cell, LLayer_Find( file, "Grating70"  ), Points, 4);


width_shallow=5*scalefactor;
w_shallow=0.4*scalefactor;
l_a_staper=L_t*1.2;


	Points [0].x=center_x-L_f*cos(To[j]-(width_shallow/2/cos(To[j])/L_f))*sin(To[j]-(width_shallow/2/cos(To[j])/L_f));
	Points [0].y=center_y+L_f*sin(To[j]-(width_shallow/2/cos(To[j])/L_f))*sin(To[j]-(width_shallow/2/cos(To[j])/L_f));
	Points [1].x=center_x-(L_f*cos(To[j])+l_a_staper)*sin(To[j])+w_shallow/2*cos(To[j]);
	Points [1].y=center_y+L_f-(L_f*cos(To[j])+l_a_staper)*cos(To[j])-w_shallow/2*sin(To[j]);
	Points [2].x=center_x-(L_f*cos(To[j])+l_a_staper)*sin(To[j])-w_shallow/2*cos(To[j]);
	Points [2].y=center_y+L_f-(L_f*cos(To[j])+l_a_staper)*cos(To[j])+w_shallow/2*sin(To[j]);
	Points [3].x=center_x-L_f*cos(To[j]+(width_shallow/2/cos(To[j])/L_f))*sin(To[j]+(width_shallow/2/cos(To[j])/L_f));
	Points [3].y=center_y+L_f*sin(To[j]+(width_shallow/2/cos(To[j])/L_f))*sin(To[j]+(width_shallow/2/cos(To[j])/L_f));

	LPolygon_New ( cell, LLayer_Find( file, "Slab90"  ), Points, 4);



	L_t1=(center_y+L_f-(L_f*cos(To[j])+L_t)*cos(To[j])-io_y-r*sin(To[j]))/cos(To[j]);


	Points [0].x=center_x-(L_f*cos(To[j])+L_t)*sin(To[j])+width/2*cos(To[j]);
	Points [0].y=center_y+L_f-(L_f*cos(To[j])+L_t)*cos(To[j])-width/2*sin(To[j]);
	Points [1].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+width/2*cos(To[j]);
	Points [1].y=center_y+L_f-(L_f*cos(To[j])+L_t+L_t1)*cos(To[j])-width/2*sin(To[j]);
	Points [3].x=center_x-(L_f*cos(To[j])+L_t)*sin(To[j])-width/2*cos(To[j]);
	Points [3].y=center_y+L_f-(L_f*cos(To[j])+L_t)*cos(To[j])+width/2*sin(To[j]);
	Points [2].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])-width/2*cos(To[j]);
	Points [2].y=center_y+L_f-(L_f*cos(To[j])+L_t+L_t1)*cos(To[j])+width/2*sin(To[j]);

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);

	tParams.ptCenter.x = center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j]);
	tParams.ptCenter.y = io_y;	
	tParams.nInnerRadius = r-width/2;
	tParams.nOuterRadius = r+width/2;
	tParams.dStartAngle =180*(1-To[j]/pi);
	tParams.dStopAngle = 180;

	LTorus_CreateNew(cell, LLayer_Find( file, "Rib130"  ), &tParams); 


	Points [0].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j])-r-width/2;
	Points [0].y=io_y;
	Points [1].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j])-r-width/2;
	Points [1].y=io_y-l_d*(N-j);
	Points [2].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j])-r+width/2;
	Points [2].y=io_y-l_d*(N-j);
	Points [3].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j])-r+width/2;
	Points [3].y=io_y;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);



	tParams.ptCenter.x = center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j]);
	tParams.ptCenter.y = io_y-l_d*(N-j);	
	tParams.nInnerRadius = r-width/2;
	tParams.nOuterRadius = r+width/2;
	tParams.dStartAngle =180;
	tParams.dStopAngle = 270;

	LTorus_CreateNew(cell, LLayer_Find( file, "Rib130"  ), &tParams); 


	Points [0].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j]);
	Points [0].y=io_y-l_d*(N-j)-r+width/2;
	Points [1].x=center_x-(L_f*cos(To[j])+L_t+L_t1)*sin(To[j])+r*cos(To[j]);
	Points [1].y=io_y-l_d*(N-j)-r-width/2;
	Points [2].x=o_x;
	Points [2].y=io_y-l_d*(N-j)-r-width/2;
	Points [3].x=o_x;
	Points [3].y=io_y-l_d*(N-j)-r+width/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);


	taper_x=o_x;
	taper_y=io_y-l_d*(N-j)-r;

	right_GC(file,cell);


	}



}





void EDG_gratings_bragg(LFile file, LCell cell)
{
	
LPoint       Points [ 1002 ];
LObject      Torus1;
 
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  	


for (i=1;i<=1+N1+N2 ;i++ )
{
	D[i]=D[i]+60;
	for (j=1;j<=n_gr ;j++ )
	{
	
	Points [0].x=center_x+L_f*sin(T[i])+p_gr*(j)*sin(P[i])-D[i]/2*cos(P[i]);
	Points [0].y=center_y+L_f*cos(T[i])+p_gr*(j)*cos(P[i])+D[i]/2*sin(P[i]);
	Points [1].x=center_x+L_f*sin(T[i])+p_gr*(j)*sin(P[i])+D[i]/2*cos(P[i]);
	Points [1].y=center_y+L_f*cos(T[i])+p_gr*(j)*cos(P[i])-D[i]/2*sin(P[i]);
	Points [2].x=center_x+L_f*sin(T[i])+(p_gr*(j-1)+p_gr*(1-a_gr))*sin(P[i])+D[i]/2*cos(P[i]);
	Points [2].y=center_y+L_f*cos(T[i])+(p_gr*(j-1)+p_gr*(1-a_gr))*cos(P[i])-D[i]/2*sin(P[i]);
	Points [3].x=center_x+L_f*sin(T[i])+(p_gr*(j-1)+p_gr*(1-a_gr))*sin(P[i])-D[i]/2*cos(P[i]);
	Points [3].y=center_y+L_f*cos(T[i])+(p_gr*(j-1)+p_gr*(1-a_gr))*cos(P[i])+D[i]/2*sin(P[i]);

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 4);
	}

}

for (i=1;i<=N1+N2+1 ;i++ )
{
	Points [2*(i-1)].x=center_x+L_f*sin(T[i])-D[i]/2*cos(P[i]);
	Points [2*(i-1)].y=center_y+L_f*cos(T[i])+D[i]/2*sin(P[i]);
	Points [2*(i-1)+1].x=center_x+L_f*sin(T[i])+D[i]/2*cos(P[i]);
	Points [2*(i-1)+1].y=center_y+L_f*cos(T[i])-D[i]/2*sin(P[i]);
}

	Points [2*(N1+N2)+2*(1)].x=  center_x-L_f*cos(To[N]-(d_out*2/cos(To[N])/L_f))*sin(To[N]-(d_out*2/cos(To[N])/L_f));
	Points [2*(N1+N2)+2*(1)].y=  center_y+L_f*sin(To[N]-(d_out*2/cos(To[N])/L_f))*sin(To[N]-(d_out*2/cos(To[N])/L_f));

	for (j=N;j>=1 ;j-- )
	{
	Points [2*(N1+N2)+2*(N+1-j)+2].x=center_x-L_f*cos(To[j]+(d_out/2/cos(To[j])/L_f))*sin(To[j]+(d_out/2/cos(To[j])/L_f));
	Points [2*(N1+N2)+2*(N+1-j)+2].y=center_y+L_f*sin(To[j]+(d_out/2/cos(To[j])/L_f))*sin(To[j]+(d_out/2/cos(To[j])/L_f));
	Points [2*(N1+N2)+2*(N+1-j)+1].x=  center_x-L_f*cos(To[j]-(d_out/2/cos(To[j])/L_f))*sin(To[j]-(d_out/2/cos(To[j])/L_f));
	Points [2*(N1+N2)+2*(N+1-j)+1].y=  center_y+L_f*sin(To[j]-(d_out/2/cos(To[j])/L_f))*sin(To[j]-(d_out/2/cos(To[j])/L_f));
	}

	Points [2*(N1+N2)+2*N+4].x=center_x-L_f*cos(theta+(d_in/2/cos(theta)/L_f))*sin(theta+(d_in/2/cos(theta)/L_f));
	Points [2*(N1+N2)+2*N+4].y=center_y+L_f*sin(theta+(d_in/2/cos(theta)/L_f))*sin(theta+(d_in/2/cos(theta)/L_f));
	Points [2*(N1+N2)+2*N+3].x=center_x-L_f*cos(theta-(d_in/2/cos(theta)/L_f))*sin(theta-(d_in/2/cos(theta)/L_f));
	Points [2*(N1+N2)+2*N+3].y=center_y+L_f*sin(theta-(d_in/2/cos(theta)/L_f))*sin(theta-(d_in/2/cos(theta)/L_f));

	Points [2*(N1+N2)+2*N+5].x=center_x-L_f*cos(theta+(d_in*2/cos(theta)/L_f))*sin(theta+(d_in*2/cos(theta)/L_f));
	Points [2*(N1+N2)+2*N+5].y=center_y+L_f*sin(theta+(d_in*2/cos(theta)/L_f))*sin(theta+(d_in*2/cos(theta)/L_f));

	LPolygon_New ( cell, LLayer_Find( file, "Rib130"  ), Points, 2*(N1+N2)+2*N+6);


}


left_GC(LFile file, LCell cell)
{




LPoint       Points [ 1002 ];
LObject      Torus1;
 
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  

v=j;

	Points [0].x=taper_x;
	Points [0].y=taper_y-width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y+width/2;
	Points [2].x=taper_x-taper_L;
	Points [2].y=taper_y+taper_w/2;
	Points [3].x=taper_x-taper_L-G_L+(1-gc_a)*period;
	Points [3].y=taper_y+taper_w/2;
	Points [4].x=taper_x-taper_L-G_L+(1-gc_a)*period;
	Points [4].y=taper_y-taper_w/2;
	Points [5].x=taper_x-taper_L;
	Points [5].y=taper_y-taper_w/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 6);

	for (j=1;j<=gc_n;j=j+1)
	{
	Points [0].x=taper_x-taper_L-G_L-(j-1)*period;
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=taper_x-taper_L-G_L-(j-1)*period;
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=taper_x-taper_L-G_L-(j-1)*period-gc_a*period;
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=taper_x-taper_L-G_L-(j-1)*period-gc_a*period;
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);
	}//光栅

	Points [0].x=taper_x-taper_L-G_L-(gc_n)*period;
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=taper_x-taper_L-G_L-(gc_n)*period;
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=taper_x-taper_L-G_L-(gc_n)*period-G_L;
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=taper_x-taper_L-G_L-(gc_n)*period-G_L;
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=taper_x-taper_L-G_L/2+(1-gc_a)*period;
	Points [0].y=taper_y+taper_w/2+gc_dis;
	Points [1].x=taper_x-taper_L-G_L/2+(1-gc_a)*period;
	Points [1].y=taper_y-taper_w/2-gc_dis;
	Points [2].x=taper_x-taper_L-G_L-(gc_n)*period-G_L/2;
	Points [2].y=taper_y-taper_w/2-gc_dis;
	Points [3].x=taper_x-taper_L-G_L-(gc_n)*period-G_L/2;
	Points [3].y=taper_y+taper_w/2+gc_dis;

	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);

	Points [0].x=taper_x-taper_L-G_L/2+(1-gc_a)*period+5*scalefactor;
	Points [0].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	Points [1].x=taper_x-taper_L-G_L/2+(1-gc_a)*period+5*scalefactor;
	Points [1].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [2].x=taper_x-taper_L-G_L-(gc_n)*period-G_L/2-5*scalefactor;
	Points [2].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [3].x=taper_x-taper_L-G_L-(gc_n)*period-G_L/2-5*scalefactor;
	Points [3].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);	

	j=v;
}

void right_GC(LFile file, LCell cell)
{




LPoint       Points [ 1002 ];
LObject      Torus1;
 
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  


v=j;

	Points [0].x=taper_x;
	Points [0].y=taper_y-width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y+width/2;
	Points [2].x=taper_x+taper_L;
	Points [2].y=taper_y+taper_w/2;
	Points [3].x=taper_x+taper_L+G_L-(1-gc_a)*period;
	Points [3].y=taper_y+taper_w/2;
	Points [4].x=taper_x+taper_L+G_L-(1-gc_a)*period;
	Points [4].y=taper_y-taper_w/2;
	Points [5].x=taper_x+taper_L;
	Points [5].y=taper_y-taper_w/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 6);

	for (j=1;j<=gc_n;j=j+1)
	{
	Points [0].x=taper_x+taper_L+G_L+(j-1)*period;
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=taper_x+taper_L+G_L+(j-1)*period;
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=taper_x+taper_L+G_L+(j-1)*period+gc_a*period;
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=taper_x+taper_L+G_L+(j-1)*period+gc_a*period;
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);
	}//光栅

	Points [0].x=taper_x+taper_L+G_L+(gc_n)*period;
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=taper_x+taper_L+G_L+(gc_n)*period;
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=taper_x+taper_L+G_L+(gc_n)*period+G_L;
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=taper_x+taper_L+G_L+(gc_n)*period+G_L;
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=taper_x+taper_L+G_L/2-(1-gc_a)*period;
	Points [0].y=taper_y+taper_w/2+gc_dis;
	Points [1].x=taper_x+taper_L+G_L/2-(1-gc_a)*period;
	Points [1].y=taper_y-taper_w/2-gc_dis;
	Points [2].x=taper_x+taper_L+G_L+(gc_n)*period+G_L/2;
	Points [2].y=taper_y-taper_w/2-gc_dis;
	Points [3].x=taper_x+taper_L+G_L+(gc_n)*period+G_L/2;
	Points [3].y=taper_y+taper_w/2+gc_dis;

	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);

	Points [0].x=taper_x+taper_L+G_L/2-(1-gc_a)*period-5*scalefactor;
	Points [0].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	Points [1].x=taper_x+taper_L+G_L/2-(1-gc_a)*period-5*scalefactor;
	Points [1].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [2].x=taper_x+taper_L+G_L+(gc_n)*period+G_L/2+5*scalefactor;
	Points [2].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [3].x=taper_x+taper_L+G_L+(gc_n)*period+G_L/2+5*scalefactor;
	Points [3].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);	

	j=v;

}



