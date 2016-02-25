//module 	Grating_module
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"

///main()
void GR1310(LFile file,LCell cell)
{
 double scalefactor,pi;
 double center_x_gr,center_y_gr,width;


 double W[200],P[200],Dl,Dl1;

 double taper_x,taper_y,w,l_s,l_s1,l_s2,l_s_dis,l_s_w1,l_s_w2,l_s_w3,l_s_w4,l_s_w,w_tip;
 double taper_L,taper_w,G_L,gc_dis,G_x,G_y;

 int	  N,N1,N2,N_out,gc_n,gc_n1;
 int    i,j,k,v;

 double period,gc_a;





/* Parameter Setting */
scalefactor=1.0E3;
pi=3.1415926;




LPoint       Points [ 1002 ];
LObject      Torus1;
//LCell        Cell_Draw   = LCell_GetVisible( );
//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
LCell        Cell_Draw   = cell;
LFile        File_Draw   = file;
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  

/*******************************************************/


center_x_gr=-500*scalefactor;  //  调整零点到器件的坐标原点
center_y_gr=0;	//输入波导端口位置
width=500;





taper_L=400*scalefactor;//taper长度
taper_w=14*scalefactor;//taper结束端宽度，即光栅区宽度
G_L=5*scalefactor;//光栅区长度
gc_dis=200;
period=630;
gc_a=0.5;
gc_n=20;
gc_n1=11;



W	[	1	]	=200	;
W	[	2	]	=200	;
W	[	3	]	=200	;
W	[	4	]	=200	;
W	[	5	]	=200	;
W	[	6	]	=220	;
W	[	7	]	=200	;
W	[	8	]	=200	;
W	[	9	]	=200	;
W	[	10	]	=200	;
W	[	11	]	=200	;
W	[	12	]	=240	;
W	[	13	]	=200	;
W	[	14	]	=220	;
W	[	15	]	=220	;
W	[	16	]	=200	;
W	[	17	]	=240	;
W	[	18	]	=220	;
W	[	19	]	=200	;
W	[	20	]	=200	;
P	[	1	]	=510	;
P	[	2	]	=490	;
P	[	3	]	=510	;
P	[	4	]	=490	;
P	[	5	]	=500	;
P	[	6	]	=500	;
P	[	7	]	=510	;
P	[	8	]	=500	;
P	[	9	]	=500	;
P	[	10	]	=500	;
P	[	11	]	=500	;
P	[	12	]	=550	;
P	[	13	]	=550	;
P	[	14	]	=540	;
P	[	15	]	=540	;
P	[	16	]	=520	;
P	[	17	]	=560	;
P	[	18	]	=540	;
P	[	19	]	=530	;
P	[	20	]	=530	;









l_s1=1000*scalefactor;//
//l_s_dis=30*scalefactor;
l_s_dis=0*scalefactor; // edit by Lu

for (i=1;i<=1 ;i=i+1 )
{
l_s=l_s1*i;

taper_x=center_x_gr;
taper_y=center_y_gr-i*l_s_dis;

//left_GC_gr();
left_GC_gr(
	file,
	cell,
	 taper_x,
	 j,
	 taper_y,
	 width,
	 taper_L,
	 taper_w,
	 G_L,
	 gc_n1,
	 gc_n,
	 W,
	 P,
	 Dl1,
	 Dl,
	 gc_dis,
	 scalefactor,
	 v
	);

	Points [0].x=taper_x;
	Points [0].y=taper_y-width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y+width/2;
	Points [2].x=taper_x+l_s;
	Points [2].y=taper_y+width/2;
	Points [3].x=taper_x+l_s;
	Points [3].y=taper_y-width/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130"  ), Points, 4);



	taper_x=center_x_gr+l_s;
	taper_y=center_y_gr-i*l_s_dis;
//	right_GC_gr();
right_GC_gr(
	file,
	cell,
	 taper_x,
	 j,
	 taper_y,
	 width,
	 taper_L,
	 taper_w,
	 G_L,
	 gc_n1,
	 gc_n,
	 W,
	 P,
	 Dl1,
	 Dl,
	 gc_dis,
	 scalefactor,
	 v
		);


}






}


/*End of main*/











left_GC_gr(
	LFile file,
	LCell cell,
	double taper_x,
	int j,
	double taper_y,
	double width,
	double taper_L,
	double taper_w,
	double G_L,
	int gc_n1,
	int gc_n,
	double W[],
	double P[],
	double Dl1,
	double Dl,
	double gc_dis,
	double scalefactor,
	int v
	)
{




LPoint       Points [ 1002 ];
LObject      Torus1;
//LCell        Cell_Draw   = LCell_GetVisible( );
//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
LCell        Cell_Draw   = cell;
LFile        File_Draw   = file;
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  

v=j;

	Points [0].x=taper_x;
	Points [0].y=taper_y-width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y+width/2;
	Points [2].x=taper_x-taper_L;
	Points [2].y=taper_y+taper_w/2;
	Points [3].x=taper_x-taper_L-G_L;
	Points [3].y=taper_y+taper_w/2;
	Points [4].x=taper_x-taper_L-G_L;
	Points [4].y=taper_y-taper_w/2;
	Points [5].x=taper_x-taper_L;
	Points [5].y=taper_y-taper_w/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 6);//上部taper和平直区域

	Dl=taper_x-taper_L-G_L;
	Dl1=Dl;

	for (j=1;j<=gc_n;j=j+1)
	{
	Points [0].x=Dl-W[j];
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=Dl-W[j];
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=Dl-P[j];
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=Dl-P[j];
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);

	Dl=Dl-P[j];

	if (j<=gc_n1)
	{
		Dl1=Dl1-P[j];
	}
	}//光栅

	Dl1=Dl1+(P[gc_n1]-W[gc_n1])/2;

	Points [0].x=Dl;
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=Dl;
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=Dl-G_L;
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=Dl-G_L;
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);//下部平直区域

	Points [0].x=taper_x-taper_L-G_L/2;
	Points [0].y=taper_y+taper_w/2+gc_dis;
	Points [1].x=taper_x-taper_L-G_L/2;
	Points [1].y=taper_y-taper_w/2-gc_dis;
	Points [2].x=Dl1;
	Points [2].y=taper_y-taper_w/2-gc_dis;
	Points [3].x=Dl1;
	Points [3].y=taper_y+taper_w/2+gc_dis;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);

	Points [0].x=taper_x-taper_L-G_L/2;
	Points [0].y=taper_y+taper_w/2+gc_dis;
	Points [1].x=taper_x-taper_L-G_L/2;
	Points [1].y=taper_y-taper_w/2-gc_dis;
	Points [2].x=Dl-G_L/2;
	Points [2].y=taper_y-taper_w/2-gc_dis;
	Points [3].x=Dl-G_L/2;
	Points [3].y=taper_y+taper_w/2+gc_dis;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);

	Points [0].x=taper_x-taper_L-G_L/2+5*scalefactor;
	Points [0].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	Points [1].x=taper_x-taper_L-G_L/2+5*scalefactor;
	Points [1].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [2].x=Dl-G_L/2-5*scalefactor;
	Points [2].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [3].x=Dl-G_L/2-5*scalefactor;
	Points [3].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);	

	j=v;
}

right_GC_gr(
	LFile file,
	LCell cell,
	double taper_x,
	int j,
	double taper_y,
	double width,
	double taper_L,
	double taper_w,
	double G_L,
	int gc_n1,
	int gc_n,
	double W[],
	double P[],
	double Dl1,
	double Dl,
	double gc_dis,
	double scalefactor,
	int v
		)
{




LPoint       Points [ 1002 ];
LObject      Torus1;
//LCell        Cell_Draw   = LCell_GetVisible( );
//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
LCell        Cell_Draw   = cell;
LFile        File_Draw   = file;
LPoint       Translation = LCursor_GetPosition ( ); 
LTorusParams tParams;  


v=j;

	Points [0].x=taper_x;
	Points [0].y=taper_y-width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y+width/2;
	Points [2].x=taper_x+taper_L;
	Points [2].y=taper_y+taper_w/2;
	Points [3].x=taper_x+taper_L+G_L;
	Points [3].y=taper_y+taper_w/2;
	Points [4].x=taper_x+taper_L+G_L;
	Points [4].y=taper_y-taper_w/2;
	Points [5].x=taper_x+taper_L;
	Points [5].y=taper_y-taper_w/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 6);//上部taper和平直区域

	Dl=taper_x+taper_L+G_L;

	Dl1=Dl;
	for (j=1;j<=gc_n;j=j+1)
	{
	Points [0].x=Dl+W[j];
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=Dl+W[j];
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=Dl+P[j];
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=Dl+P[j];
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);

	Dl=Dl+P[j];

	if (j<=gc_n1)
	{
		Dl1=Dl1+P[j];
	}
	}//光栅

		Dl1=Dl1-(P[gc_n1]-W[gc_n1])/2;

	Points [0].x=Dl;
	Points [0].y=taper_y+taper_w/2;
	Points [1].x=Dl;
	Points [1].y=taper_y-taper_w/2;
	Points [2].x=Dl+G_L;
	Points [2].y=taper_y-taper_w/2;
	Points [3].x=Dl+G_L;
	Points [3].y=taper_y+taper_w/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);//下部平直区域

	Points [0].x=taper_x+taper_L+G_L/2;
	Points [0].y=taper_y+taper_w/2+gc_dis;
	Points [1].x=taper_x+taper_L+G_L/2;
	Points [1].y=taper_y-taper_w/2-gc_dis;
	Points [2].x=Dl1;
	Points [2].y=taper_y-taper_w/2-gc_dis;
	Points [3].x=Dl1;
	Points [3].y=taper_y+taper_w/2+gc_dis;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);

	Points [0].x=taper_x+taper_L+G_L/2;
	Points [0].y=taper_y+taper_w/2+gc_dis;
	Points [1].x=taper_x+taper_L+G_L/2;
	Points [1].y=taper_y-taper_w/2-gc_dis;
	Points [2].x=Dl+G_L/2;
	Points [2].y=taper_y-taper_w/2-gc_dis;
	Points [3].x=Dl+G_L/2;
	Points [3].y=taper_y+taper_w/2+gc_dis;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);

	Points [0].x=taper_x+taper_L+G_L/2-5*scalefactor;
	Points [0].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	Points [1].x=taper_x+taper_L+G_L/2-5*scalefactor;
	Points [1].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [2].x=Dl+G_L/2+5*scalefactor;
	Points [2].y=taper_y-taper_w/2-gc_dis-5*scalefactor;
	Points [3].x=Dl+G_L/2+5*scalefactor;
	Points [3].y=taper_y+taper_w/2+gc_dis+5*scalefactor;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);	

	j=v;

}



/*	void  Grating_macro_register (void)
	{
		LMacro_Register("Grating", "main");
	}

}
/* End of Module */
/*Grating_macro_register();*/