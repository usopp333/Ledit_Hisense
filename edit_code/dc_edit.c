// edit by LuZequan
// 使用函数调用
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"


	/* TODO: Put local functions here. */
void dc_edit(LFile file, LCell cell)
	{
		
	
		const char* 	layer_WG;
		const char*     layer_grating;
		double      	center_x,center_y,theta,period,FF,link_length,taper_length,taper_width;
	    double      	WG_width,gap,radius,couple_length,space_pro;
		double          factor,x_0,y_0,pi;
		factor=1000;
		pi=3.1415926;
		layer_grating="Grating70";
		layer_WG="Rib130";
		WG_width=0.41*factor;
		gap=0.2*factor;
		radius=15*factor;
		couple_length=2*factor;
		space_pro=2*factor;
		period=0.49*factor;
		FF=0.5;
		link_length=5*factor;//连接波导长度
		taper_length=400*factor;
		taper_width=12*factor;
	    theta=90;
		center_x=0;
		center_y=0-15*factor;	//需要将零点调整到器件的中心	
				
		x_0=center_x;
		y_0=center_y;
		

		DC_single_arc_grating(
								file, cell,
								 x_0,
								 y_0,
								 taper_length,
								 taper_width,
								 couple_length,
								 WG_width,
								 gap,
								 radius,
								 theta,
								 space_pro,
								 period,
								 FF,
								 link_length,
								 layer_grating,
								 layer_WG
								)	;
		

	
		
		
	}//主函数结束
	
void DC_single_arc_grating(
								LFile file, LCell cell,
								double x,
								double y,
								double taper_length,
								double taper_width,
								double couple_length,
								double WG_width,
								double gap,
								double radius,
								double theta,
								double space_pro,
								double period,
								double FF,
								double link_length,
								const char* layer_grating,
								const char* layer_WG
								)	
	{

		
		//----------------------------------
	double arc_port_x,arc_port_y,pi,x_0,y_0;	
		
		x_0=x;
		y_0=y;
		
		
		/* TODO: Begin custom generator code.*/
	DC_single_arc_NEG(
							file, cell,
							x_0,
							y_0,
							couple_length,
							WG_width,
							gap,
							radius,
							theta,
							space_pro,
							layer_WG);

		/* End custom generator code.*/
		
	
	
	pi=3.1415926;
	
	
	
	 
	arc_port_x=2*radius*sin(pi*theta/180);
	
	arc_port_y=2*radius*(1-cos(pi*theta/180));
	
	//------------------------------------------------
	x=x_0+link_length/2+couple_length/2+arc_port_x;
	y=y_0+WG_width/2+gap/2+arc_port_y;
	
	link_WG_single_dc(file, cell,x,y,link_length,WG_width,space_pro,layer_WG);	
	
	x=x_0+link_length+couple_length/2+arc_port_x;
	
	parabolic_grating_uniform_NG_right(
									 file, cell,
									 x,
									 y,
									 space_pro,
									 WG_width,
									 taper_length,
									 taper_width,
									 period,
									 FF,
									layer_grating,
									layer_WG);		
		
		
	//------------------------------------------------
	x=x_0+link_length/2+couple_length/2+arc_port_x;
	y=y_0-WG_width/2-gap/2;
	
	link_WG_single_dc(file, cell,x,y,link_length,WG_width,space_pro,layer_WG);	
	
	x=x_0+link_length+couple_length/2+arc_port_x;
	
	parabolic_grating_uniform_NG_right(
									 file, cell,
									 x,
									 y,
									 space_pro,
									 WG_width,
									 taper_length,
									 taper_width,
									 period,
									 FF,
									 layer_grating,
									 layer_WG
									 );			
		
	//------------------------------------------------
	x=x_0-link_length/2-couple_length/2-arc_port_x;
	y=y_0-WG_width/2-gap/2;
	
	link_WG_single_dc(file, cell,
	x,y,link_length,WG_width,space_pro,layer_WG);	
	
	x=x_0-link_length-couple_length/2-arc_port_x;
	
	parabolic_grating_uniform_NG_left(
									 file, cell,
									 x,
									 y,
									 space_pro,
									 WG_width,
									 taper_length,
									 taper_width,
									 period,
									 FF,
									 layer_grating,
									 layer_WG
									 );			
		
	//------------------------------------------------
	x=x_0-link_length/2-couple_length/2-arc_port_x;
	y=y_0+WG_width/2+gap/2+arc_port_y;
	
	link_WG_single_dc(file, cell,
	x,y,link_length,WG_width,space_pro,layer_WG);	
	
	x=x_0-link_length-couple_length/2-arc_port_x;
	
	parabolic_grating_uniform_NG_left(
									 file, cell,
									 x,
									 y,
									 space_pro,
									 WG_width,
									 taper_length,
									 taper_width,
									 period,
									 FF,
									 layer_grating,
									 layer_WG
									 );	
	
	
	
	
	
	
	
	
	}
	
	
void DC_single_arc_NEG(
								LFile file, LCell cell,
								double x,
								double y,
								double couple_length,
								double WG_width,
								double gap,
								double radius,
								double theta,
								double pro_space,
								const char* layer_WG)
	{
		double A_x[103],A_y[103],alpha,pi;
		int i;
		int n;
		n=100;
		pi=3.1415926;
		alpha=acos((radius+WG_width/2+gap/2-pro_space)/(radius+WG_width/2+pro_space));
		
		for (i=0;i<n;i++)
			{
			A_x[i]=(radius+WG_width/2)*sin(i*(alpha)/(n-1));
			A_y[i]=(radius+WG_width/2)*(1-cos(i*(alpha)/(n-1)));
			}
	
			A_x[100]=(radius+WG_width/2+pro_space)*sin(alpha);
			A_y[100]=radius+WG_width/2-(radius+WG_width/2+pro_space)*cos(alpha);	
	
			A_x[101]=(radius+WG_width/2+pro_space)*sin(alpha);
			A_y[101]=-gap;		
	
			A_x[102]=0;
			A_y[102]=-gap;
			
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		//----------------------------------------------------------第一象限

			
			
		tParams.ptCenter.x=x+couple_length/2;
		tParams.ptCenter.y=y+radius+gap/2+WG_width/2;
		
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 270;
		tParams.dStopAngle = 360;
		LTorus_CreateNew(cell, LLayer_Find( file, layer_WG ), &tParams); 

	
		tParams.ptCenter.x=x+couple_length/2+2*radius*sin(pi*theta/180);
		tParams.ptCenter.y=y+radius+gap/2+WG_width/2-2*radius*cos(pi*theta/180);
	
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 90;
		tParams.dStopAngle = 180;
		LTorus_CreateNew(cell, LLayer_Find( file, layer_WG ), &tParams); 
	
		

		//----------------------------------------------------------第二象限
		Points [0].x=x-couple_length/2;		
		Points [0].y=y+gap/2;
		Points [1].x=x-couple_length/2;		
		Points [1].y=y+gap/2+WG_width;	
		Points [2].x=x+couple_length/2;		
		Points [2].y=y+gap/2+WG_width;	
		Points [3].x=x+couple_length/2;		
		Points [3].y=y+gap/2;
		
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);		
        ////up  up /////////////
	
		Points [0].x=x+couple_length/2+2*radius;		
		Points [0].y=y-gap/2;
		Points [1].x=x+couple_length/2+2*radius;		
		Points [1].y=y-gap/2-WG_width;	
		Points [2].x=x-couple_length/2-2*radius;	
		Points [2].y=y-gap/2-WG_width;	
		Points [3].x=x-couple_length/2-2*radius;	
		Points [3].y=y-gap/2;
		
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);		
        ////down down/////////////	
		
			
			
		tParams.ptCenter.x=x-couple_length/2;
		tParams.ptCenter.y=y+radius+gap/2+WG_width/2;
		
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 180;
		tParams.dStopAngle = 270;
		LTorus_CreateNew(cell, LLayer_Find( file, layer_WG ), &tParams); 
 
	
		tParams.ptCenter.x=x-couple_length/2-2*radius*sin(pi*theta/180);
		tParams.ptCenter.y=y+radius+gap/2+WG_width/2-2*radius*cos(pi*theta/180);
	
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 0;
		tParams.dStopAngle = 90;
		LTorus_CreateNew(cell, LLayer_Find( file, layer_WG ), &tParams); 


	
	}	//子函数结束
	
//---------------------------------------------

void link_WG_single_dc(LFile file, LCell cell,
					double x,double y,double space_link,double WG_width,double space_pro,const char* layer_WG)	
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		Points [0].x=x-space_link/2;		
		Points [0].y=y+WG_width/2;
	
	
		Points [1].x=x-space_link/2;	
		Points [1].y=y-WG_width/2;
	
		Points [2].x=x+space_link/2;
		Points [2].y=y-WG_width/2;
	
	
		Points [3].x=x+space_link/2;
		Points [3].y=y+WG_width/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);	
		
		
		
	}//子函数结束		


	
void parabolic_grating_uniform_NG_left(
														LFile file, LCell cell,
														double x,
														double y,
														double space_pro,
														double WG_width,
														double taper_length,
														double taper_width,
														double period,
														double FF,
														const char* layer_grating,
														const char* layer_WG)
		{
		double scalefactor;   //中间变量
		double taper_x,taper_y,w;               //转移变量
		double G_x,G_y,G_L; 	//光栅变量
		
		double space_front,grating_width;
		
		
		
		/* TODO: Begin custom generator code.*/

		//光栅的相关参数--均匀光栅
		scalefactor=1000.0;
		
		
		space_front=5*	scalefactor;//光栅区前端预留的长度
		G_L=30*scalefactor;//光栅区长度
		grating_width=taper_width;

		taper_x=x;
		taper_y=y;
	   
		w=space_pro;
	
		int i,j;
	
	
		LPoint       Points [ 2002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  
	
		
		//--------抛物线型taper的数据
		Points [0].x=taper_x-taper_length;
	    Points [0].y=taper_y+taper_width/2;
	    Points [1].x=taper_x-taper_length;
	    Points [1].y=taper_y-taper_width/2;
        Points [2].x=x;
	    Points [2].y=taper_y-WG_width/2;
	    Points [3].x=x;
	    Points [3].y=taper_y+WG_width/2;
				
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);			
		
		
		
			
		//--------直波导区域
		
	Points [0].x=taper_x-taper_length;
	Points [0].y=taper_y+taper_width/2;
	Points [1].x=x-taper_length-space_front;
	Points [1].y=taper_y+taper_width/2;
    Points [2].x=x-taper_length-space_front;
	Points [2].y=taper_y-taper_width/2;
	Points [3].x=taper_x-taper_length;
	Points [3].y=taper_y-taper_width/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=taper_x-taper_length-G_L;
	Points [0].y=taper_y+taper_width/2;
	Points [1].x=x-taper_length-space_front-30*period;
	Points [1].y=taper_y+taper_width/2;
	Points [2].x=x-taper_length-space_front-30*period;
	Points [2].y=taper_y-taper_width/2;
	Points [3].x=taper_x-taper_length-G_L;
	Points [3].y=taper_y-taper_width/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=x-taper_length-space_front-30.5*period;
	Points [0].y=taper_y+taper_width/2+1*scalefactor;
	Points [1].x=x-taper_length-space_front;
	Points [1].y=taper_y+taper_width/2+1*scalefactor;
	Points [2].x=x-taper_length-space_front;
	Points [2].y=taper_y-taper_width/2-1*scalefactor;
	Points [3].x=x-taper_length-space_front-30.5*period;
	Points [3].y=taper_y-taper_width/2-1*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);
		
		
		G_x=x-taper_length-space_front;
		G_y=y;
		
			
		for(j=0;j<30;j++)//画30根均匀光栅
			{
			LBox_New ( cell, LLayer_Find( file, layer_WG) ,G_x, G_y+grating_width/2, G_x-period*(1-FF), G_y-grating_width/2);	//画第一根光栅
			G_x=G_x-period;	//将光栅的左x坐标平移
			}	//	
	Points [0].x=taper_x+(-taper_length-1.1*G_L);
	Points [0].y=taper_y+space_pro+12*scalefactor;
	Points [1].x=taper_x+(-taper_length+0.1*G_L);
	Points [1].y=taper_y+space_pro+12*scalefactor;
	Points [2].x=taper_x+(-taper_length+0.1*G_L);
	Points [2].y=taper_y-space_pro-12*scalefactor;
	Points [3].x=taper_x+(-taper_length-1.1*G_L);
	Points [3].y=taper_y-space_pro-12*scalefactor;//上
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);
			
		}//子函数结束	
	
	
	
void parabolic_grating_uniform_NG_right(
														LFile file, LCell cell,
														double x,
														double y,
														double space_pro,
														double WG_width,
														double taper_length,
														double taper_width,
														double period,
														double FF,
														const char* layer_grating,
														const char* layer_WG
														)
		{
		
		double scalefactor,taper_x,taper_y,w;               //转移变量
		double G_x,G_y,G_L; 	//光栅变量
		
		double space_front,grating_width;
		
		
		
		/* TODO: Begin custom generator code.*/

		//光栅的相关参数--均匀光栅
		scalefactor=1000.0;
		
		
		space_front=5*scalefactor;//光栅区前端预留的长度
		G_L=30*scalefactor;//光栅区长度
		grating_width=taper_width;
		
		taper_x=x;
		taper_y=y;
	   
		w=space_pro;
	
		int i,j;
	
	
		LPoint       Points [ 2002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  
	
		
		//--------抛物线型taper的数据
		Points [0].x=taper_x+taper_length;
	    Points [0].y=taper_y+taper_width/2;
	    Points [1].x=taper_x+taper_length;
	    Points [1].y=taper_y-taper_width/2;
        Points [2].x=x;
	    Points [2].y=taper_y-WG_width/2;
	    Points [3].x=x;
	    Points [3].y=taper_y+WG_width/2;
				
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);	
		
		
			
		
		
		
			
		//--------直波导区域
		
		
		
	
	Points [0].x=taper_x+taper_length;
	Points [0].y=taper_y+taper_width/2;
	Points [1].x=x+taper_length+space_front;
	Points [1].y=taper_y+taper_width/2;
    Points [2].x=x+taper_length+space_front;
	Points [2].y=taper_y-taper_width/2;
	Points [3].x=taper_x+taper_length;
	Points [3].y=taper_y-taper_width/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=taper_x+taper_length+G_L;
	Points [0].y=taper_y+taper_width/2;
	Points [1].x=x+taper_length+space_front+30*period;
	Points [1].y=taper_y+taper_width/2;
	Points [2].x=x+taper_length+space_front+30*period;
	Points [2].y=taper_y-taper_width/2;
	Points [3].x=taper_x+taper_length+G_L;
	Points [3].y=taper_y-taper_width/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=x-(-taper_length-space_front-30.5*period);
	Points [0].y=taper_y+taper_width/2+1*scalefactor;
	Points [1].x=x-(-taper_length-space_front);
	Points [1].y=taper_y+taper_width/2+1*scalefactor;
	Points [2].x=x-(-taper_length-space_front);
	Points [2].y=taper_y-taper_width/2-1*scalefactor;
	Points [3].x=x-(-taper_length-space_front-30.5*period);
	Points [3].y=taper_y-taper_width/2-1*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);
		
		
		G_x=x+taper_length+space_front;
		G_y=y;
		
			
		for(j=0;j<30;j++)//画30根均匀光栅
			{
			LBox_New ( cell, LLayer_Find( file, layer_WG ) ,G_x, G_y+grating_width/2, G_x+period*(1-FF), G_y-grating_width/2);	//画第一根光栅
			G_x=G_x+period;	//将光栅的左x坐标平移
			}	//	

	Points [0].x=taper_x-(-taper_length-1.1*G_L);
	Points [0].y=taper_y+space_pro+12*scalefactor;
	Points [1].x=taper_x-(-taper_length+0.1*G_L);
	Points [1].y=taper_y+space_pro+12*scalefactor;
	Points [2].x=taper_x-(-taper_length+0.1*G_L);
	Points [2].y=taper_y-space_pro-12*scalefactor;
	Points [3].x=taper_x-(-taper_length-1.1*G_L);
	Points [3].y=taper_y-space_pro-12*scalefactor;//上
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);
			
		}//子函数结束		
	
	
