 /*******************************************************************************
    edit by LuZequan
 
 *******************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"


void PIC_mmi (LFile file, LCell cell,double x,double y)
	{
		
		const char* layer_grating;
		const char* layer_WG;
		double WG_width,MMI_length,MMI_width,taper_width,taper_length,radius,space_pro;
		double space_link,theta,taper_length_grating,taper_width_grating,period,FF,grating_width;
		double pi,center_x,center_y,center_x0,center_y0;
		double factor,space_arc_x,space_arc_y;
		double radius_1;
		double space_arc_x_1,space_arc_y_1;
		int i;
		
		factor=1000;
		pi=3.1415926;
		
		center_x0=x*factor;
		center_y0=y*factor;
	    center_x=center_x0;
		center_y=center_y0;
		WG_width=0.41*factor;//波导宽度
		MMI_length=4.55*factor;
		MMI_width=2*factor;
		radius=20*factor;
		space_pro=2*factor;
		taper_length=4.35*factor;
		taper_width=0.81*factor;
		space_link=2*factor;//连接波导长度
		taper_length_grating=400*factor;
		taper_width_grating=12*factor;
		FF=0.5;//占空比
		period=0.5*factor;//光栅周期
		grating_width=14*factor;
		layer_grating="Grating70";
		layer_WG="Rib130";
        theta=45;//弯曲角度
//		theta_out=90;
		
		radius_1=2*radius;
		
		space_arc_x=2*radius*sin(theta*pi/180);
		space_arc_y=2*radius*(1-cos(theta*pi/180))+MMI_width/4;
		
		space_arc_x_1=2*radius_1*sin(theta*pi/180);
		space_arc_y_1=2*radius_1*(1-cos(theta*pi/180))+MMI_width/4;
	
//----基本器件
		//第一个MMI
		MMI_1_2_left1_pic(
							file, cell,
							center_x,center_y,
							WG_width,
							MMI_length,
							MMI_width,
							radius_1,
							theta,
							space_pro,
							taper_length,
							taper_width,
							layer_WG);		


	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link;
	//center_y=center_y0-space_arc_y_1; 
	center_y=center_y0+space_arc_y_1;	// edit by LuZequan
	
	
		//第二个MMI（上）
		MMI_1_2_left1_pic(
							file, cell,
							center_x,
							center_y,
							WG_width,
							MMI_length,
							MMI_width,
							radius,
							theta,
							space_pro,
							taper_length,
							taper_width,
							layer_WG);

	
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link;
	//center_y=center_y0-space_arc_y_1; 
	center_y=center_y0-space_arc_y_1;	// edit by LuZequan

		//第二MMI（下）	
		MMI_1_2_left1_pic(
							file, cell,
							center_x,
							center_y,
							WG_width,
							MMI_length,
							MMI_width,
							radius,
							theta,
							space_pro,
							taper_length,
							taper_width,
							layer_WG);
										
		
		//连接波导
		center_x=center_x0-MMI_length/2-taper_length-space_link/2;
		center_y=center_y0;	// edit by LuZequan
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);	
		//center_x=center_x0-MMI_length/2-taper_length-space_link/2;
		center_x=center_x0+MMI_length/2+taper_length+space_link/2+space_arc_x_1;
		center_y=center_y0+space_arc_y_1;	// edit by LuZequan
		
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);		
	
		center_x=center_x+space_arc_x+MMI_length+2*taper_length+space_link;
		center_y=center_y+space_arc_y;	
		
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);		
		
		center_y=center_y-2*space_arc_y;	
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);				
//------------------------------------------
		center_x=center_x0+MMI_length/2+taper_length+space_link/2+space_arc_x_1;
		center_y=center_y0-space_arc_y_1;	// edit by LuZequan
				
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);
								
		center_x=center_x+space_arc_x+MMI_length+2*taper_length+space_link;
		center_y=center_y+space_arc_y;	
		
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);				

	//--------			
		
		center_y=center_y-2*space_arc_y;
		

		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);
		/*						
		link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								space_link,
								WG_width,
								space_pro,
								layer_WG);		
		*/
								
		
		/*//-----------光栅
		
		center_x=center_x0+MMI_length/2+taper_length+space_arc_x_1+space_link+space_arc_x+MMI_length+2*taper_length+space_link;
		center_y=center_y0-space_arc_y_1-space_arc_y;

	
		parabolic_grating_right_NG1(
											    file, cell,
												center_x,
												center_y,
												space_pro,
												WG_width,
												taper_length_grating,
												taper_width_grating,
												grating_width,
												period,
												FF,
												layer_grating,
												layer_WG);
												
		parabolic_grating_right_NG1(
												file, cell,
												center_x,
												-center_y,
												space_pro,
												WG_width,
												taper_length_grating,
												taper_width_grating,
												grating_width,
												period,
												FF,
												layer_grating,
												layer_WG);
												
	
			
			center_y=center_y0-space_arc_y_1+space_arc_y;
			parabolic_grating_right_NG1(
												file, cell,
												center_x,
												center_y,
												space_pro,
												WG_width,
												taper_length_grating,
												taper_width_grating,
												grating_width,
												period,
												FF,
												layer_grating,
												layer_WG
												);
												
			parabolic_grating_right_NG1(
												file, cell,
												center_x,
												-center_y,
												space_pro,
												WG_width,
												taper_length_grating,
												taper_width_grating,
												grating_width,
												period,
												FF,
												layer_grating,
												layer_WG
												);	
		*/
		//--------------------------------------左光栅
		
			center_x=center_x0-MMI_length/2-taper_length-space_link;
			center_y=center_y0+0;			
			parabolic_grating_left_NG1_pic(
												file, cell,
												center_x,
												center_y,
												space_pro,
												WG_width,
												taper_length_grating,
												taper_width_grating,
												grating_width,
												period,
												FF,
												layer_grating,
												layer_WG
												);		
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（上）的输出弯曲波导
/**********************************************************************************************************/
///up
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link;
	center_y=center_y0+space_arc_y_1+space_arc_y;
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y+radius,
							 WG_width,
							 radius,
							 6*theta,
							 0*theta,
							 layer_grating,
							 layer_WG
							);

	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link/2;//下弯曲波导改变稍稍长出一点
	center_y=center_y0+space_arc_y_1-space_arc_y;
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								5*space_link,
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link;
	center_y=center_y0+space_arc_y_1-space_arc_y;
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y+radius,
							 WG_width,
							 radius,
							 6*theta,
							 0*theta,
							 layer_grating,
							 layer_WG
							);

/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（上）的输出弯曲波导
/**********************************************************************************************************/
///down
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link;
	center_y=center_y0-space_arc_y_1-space_arc_y;
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y-radius,
							 WG_width,
							 radius,
							 0*theta,
							 2*theta,
							 layer_grating,
							 layer_WG
							);

	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link/2;
	center_y=center_y0-space_arc_y_1+space_arc_y;
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								5*space_link,
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link;
	center_y=center_y0-space_arc_y_1+space_arc_y;
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y-radius,
							 WG_width,
							 radius,
							 0*theta,
							 2*theta,
							 layer_grating,
							 layer_WG
							);
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（上）的垂直链接波导
/**********************************************************************************************************/
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius;
	center_y=center_y0+space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius)/2;
	link_WG_vertical(
								file, cell,
								center_x,
								center_y,
								(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius),
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link+radius;
	center_y=center_y0+space_arc_y_1-space_arc_y+radius+(500*factor-(space_arc_y_1-space_arc_y+radius)-radius)/2;
	link_WG_vertical(
								file, cell,
								center_x,
								center_y,
								(500*factor-(space_arc_y_1-space_arc_y+radius)-radius),
								WG_width,
								space_pro,
								layer_WG);
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（下）的垂直链接波导
/**********************************************************************************************************/
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius;
	center_y=center_y0-(space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius)/2);
	link_WG_vertical(
								file, cell,
								center_x,
								center_y,
								(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius),
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link+radius;
	center_y=center_y0-(space_arc_y_1-space_arc_y+radius+(500*factor-(space_arc_y_1-space_arc_y+radius)-radius)/2);
	link_WG_vertical(
								file, cell,
								center_x,
								center_y,
								(500*factor-(space_arc_y_1-space_arc_y+radius)-radius),
								WG_width,
								space_pro,
								layer_WG);
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（上）的输出弯曲波导
/**********************************************************************************************************/
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius;
	center_y=center_y0+space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius);
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y,
							 WG_width,
							 radius,
							 2*theta,
							 4*theta,
							 layer_grating,
							 layer_WG
							);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link/2;
	center_y=center_y0+space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius)+radius;
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								5*space_link,
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link+radius+radius;
	center_y=center_y0+space_arc_y_1-space_arc_y+radius+(500*factor-(space_arc_y_1-space_arc_y+radius)-radius);
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y,
							 WG_width,
							 radius,
							 2*theta,
							 4*theta,
							 layer_grating,
							 layer_WG
							);
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（下）的输出弯曲波导
/**********************************************************************************************************/
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius;
	center_y=center_y0-(space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius));
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y,
							 WG_width,
							 radius,
							 4*theta,
							 6*theta,
							 layer_grating,
							 layer_WG
							);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link/2;
	center_y=center_y0-(space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius)+radius);
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								5*space_link,
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link+radius+radius;
	center_y=center_y0-(space_arc_y_1-space_arc_y+radius+(500*factor-(space_arc_y_1-space_arc_y+radius)-radius));
	MMI_link_bending_up_pic(
							 file,
							 cell,
							 center_x,
							 center_y,
							 WG_width,
							 radius,
							 4*theta,
							 6*theta,
							 layer_grating,
							 layer_WG
							);
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（上）的输出波导，输出位置标准（200，1500），（200，500）
/**********************************************************************************************************/
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link+(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link))/2;
	center_y=center_y0+space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius)+radius;
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link)),
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link+radius+radius+(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link))/2;
	center_y=center_y0+space_arc_y_1-space_arc_y+radius+(500*factor-(space_arc_y_1-space_arc_y+radius)-radius)+radius;
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link)),
								WG_width,
								space_pro,
								layer_WG);
/**********************************************************************************************************/
//edit by sun
//2016/1/20
//第二组MMI（下）的输出波导，输出位置标准（200，-500），（200，-1500）
/**********************************************************************************************************/
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link+(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link))/2;
	center_y=center_y0-(space_arc_y_1+space_arc_y+radius+(1500*factor-(space_arc_y_1+space_arc_y+radius)-radius)+radius);
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link)),
								WG_width,
								space_pro,
								layer_WG);
	center_x=center_x0+space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+5*space_link+radius+radius+(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link))/2;
	center_y=center_y0-(space_arc_y_1-space_arc_y+radius+(500*factor-(space_arc_y_1-space_arc_y+radius)-radius)+radius);
	link_WG_single1_pic(
								file, cell,
								center_x,
								center_y,
								(200*factor-(space_arc_x_1+MMI_length+2*taper_length+space_link+MMI_length/2+taper_length+space_arc_x+space_link+radius+radius+5*space_link)),
								WG_width,
								space_pro,
								layer_WG);
/*********************************************************************************************/

												
//-----------
		/* End custom generator code.*/
	}//主函数结束
	
void link_WG_single1_pic(LFile file, LCell cell, double x,double y,double space_link,double WG_width,double space_pro,const char* layer_WG)	
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		Points [0].x=x-space_link/2;		
		Points [0].y=y-WG_width/2;
	
	
		Points [1].x=x-space_link/2;	
		Points [1].y=y+WG_width/2;
	
		Points [2].x=x+space_link/2;
		Points [2].y=y+WG_width/2;
	
	
		Points [3].x=x+space_link/2;
		Points [3].y=y-WG_width/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);	
			
	
	}

	/***********************************************/
	void link_WG_vertical(LFile file, LCell cell, double x,double y,double space_link,double WG_width,double space_pro,const char* layer_WG)	
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		Points [0].x=x-WG_width/2;		
		Points [0].y=y-space_link/2;
	
	
		Points [1].x=x-WG_width/2;	
		Points [1].y=y+space_link/2;
	
		Points [2].x=x+WG_width/2;
		Points [2].y=y+space_link/2;
	
	
		Points [3].x=x+WG_width/2;
		Points [3].y=y-space_link/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, layer_WG ), Points, 4);	
			
	
	}
	/***********************************************************************/
	
	
	
void MMI_1_2_left1_pic(LFile file, LCell cell, double center_x,double center_y,double WG_width, double MMI_length,double MMI_width,double radius,double theta,double space_pro,double taper_length,double taper_width,const char* Layer_WG)
	{
		double WG_to_WG,WG_y,pi,MMI_gap;
		pi=3.1415926;
		WG_to_WG=MMI_width/2-WG_width;
		
		WG_y=(WG_to_WG+WG_width)/2+2*(radius-radius*cos(pi*theta/180));
		MMI_gap=	MMI_width/2-taper_width;				
	
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		//MMI 左边taper
		Points [0].x=center_x-MMI_length/2;		
		Points [0].y=center_y+taper_width/2;
		Points [1].x=center_x-MMI_length/2;
		Points [1].y=center_y-taper_width/2;
	
		Points [2].x=center_x-MMI_length/2-taper_length;
		Points [2].y=center_y-WG_width/2;
		Points [3].x=center_x-MMI_length/2-taper_length;		
		Points [3].y=center_y+WG_width/2;
	
		LPolygon_New (cell, LLayer_Find( file, Layer_WG ), Points, 4);//in taper
		
		//MMI 右上taper
		Points [0].x=center_x+MMI_length/2;		
		Points [0].y=center_y+MMI_gap/2;
		Points [1].x=center_x+MMI_length/2;
		Points [1].y=center_y+MMI_gap/2+taper_width;
	
		Points [2].x=center_x+MMI_length/2+taper_length;
		Points [2].y=center_y+MMI_gap/2+taper_width/2+WG_width/2;
		Points [3].x=center_x+MMI_length/2+taper_length;		
		Points [3].y=center_y+MMI_gap/2+taper_width/2-WG_width/2;
	
		LPolygon_New ( cell, LLayer_Find( file, Layer_WG ), Points, 4);
		//MMI 右下taper
		Points [0].x=center_x+MMI_length/2;		
		Points [0].y=center_y-MMI_gap/2;
		Points [1].x=center_x+MMI_length/2;
		Points [1].y=center_y-MMI_gap/2-taper_width;
	
		Points [2].x=center_x+MMI_length/2+taper_length;
		Points [2].y=center_y-MMI_gap/2-taper_width/2-WG_width/2;
		Points [3].x=center_x+MMI_length/2+taper_length;		
		Points [3].y=center_y-MMI_gap/2-taper_width/2+WG_width/2;
	
		LPolygon_New (cell, LLayer_Find( file, Layer_WG ), Points, 4);//out taper

		//MMI
		Points [0].x=center_x+MMI_length/2;		
		Points [0].y=center_y+MMI_width/2;
		Points [1].x=center_x+MMI_length/2;	
		Points [1].y=center_y-MMI_width/2;
	
		Points [2].x=center_x-MMI_length/2;	
		Points [2].y=center_y-MMI_width/2;
		Points [3].x=center_x-MMI_length/2;		
		Points [3].y=center_y+MMI_width/2;
	
		LPolygon_New ( cell, LLayer_Find( file, Layer_WG ), Points, 4); //mmi

		
		//-------------------------------------------------------------------------
		
		
		
		//上圆
		tParams.ptCenter.x=center_x+taper_length+MMI_length/2;
		tParams.ptCenter.y=center_y+radius+(WG_to_WG+WG_width)/2;
		
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 270;
		tParams.dStopAngle = 270+theta;
		LTorus_CreateNew(cell, LLayer_Find( file, Layer_WG ), &tParams); 


	
		tParams.ptCenter.x=center_x+taper_length+MMI_length/2+2*radius*sin(pi*theta/180);
		tParams.ptCenter.y=center_y+radius+(WG_to_WG+WG_width)/2-2*radius*cos(pi*theta/180);
	
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 90;
		tParams.dStopAngle = 90+theta;
		LTorus_CreateNew(cell, LLayer_Find( file, Layer_WG ), &tParams); 
	
		////////////
		
		//下圆
		tParams.ptCenter.x=center_x+taper_length+MMI_length/2;
		tParams.ptCenter.y=center_y-radius-(WG_to_WG+WG_width)/2;
		
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 90-theta;
		tParams.dStopAngle = 90;
		LTorus_CreateNew(cell, LLayer_Find( file, Layer_WG ), &tParams); 
	
	

	
		tParams.ptCenter.x=tParams.ptCenter.x+2*radius*sin(pi*theta/180);
		tParams.ptCenter.y=tParams.ptCenter.y+2*radius*cos(pi*theta/180);
	
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = 270-theta;
		tParams.dStopAngle = 270;
		LTorus_CreateNew(cell, LLayer_Find( file, Layer_WG ), &tParams); 
	
		//------------------------------------------		
	
	
	}//子函数结束		

	//edit by sun for PIC 2015/1/20
	void MMI_link_bending_up_pic(
							LFile file,
							LCell cell,
							double center_x,
							double center_y,
							double WG_width,
							double radius,
							double start_theta,
							double stop_theta,
							const char* layer_grating,
							const char* layer_WG
							)
	{

		LPoint       Points [ 2002 ];
		LObject      Torus1;

		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 

		tParams.ptCenter.x=center_x;
		tParams.ptCenter.y=center_y;
		
		tParams.nInnerRadius=radius-WG_width/2;
		tParams.nOuterRadius=radius+WG_width/2;
		tParams.dStartAngle = start_theta;
		tParams.dStopAngle = stop_theta;
		LTorus_CreateNew(cell, LLayer_Find( file, "Rib130" ), &tParams); 


	}//edit end
	
void parabolic_grating_left_NG1_pic(
														LFile file, LCell cell, 
														double x,
														double y,
														double space_pro,
														double WG_width,
														double taper_length,
														double taper_width,
	                                                    double grating_width,
														double period,
														double FF,
														const char* layer_grating,
														const char* layer_WG)
		{
		double scalefactor;   //中间变量
		double taper_x,taper_y,w;               //转移变量
		double G_x,G_y,G_L; 	//光栅变量
		
		double space_front;
		
		
		
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
			LBox_New ( cell, LLayer_Find( file, layer_WG ) ,G_x, G_y+grating_width/2, G_x-period*(1-FF), G_y-grating_width/2);	//画第一根光栅
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
	
	
	//并非是抛物线形的taper（add by LuZequan）
void parabolic_grating_right_NG1(
														LFile file, LCell cell, 
														double x,
														double y,
														double space_pro,
														double WG_width,
														double taper_length,
														double taper_width,
	                                                    double grating_width,
														double period,
														double FF,
														const char* layer_grating,
														const char* layer_WG
														)
		{
		
		double scalefactor,taper_x,taper_y,w;               //转移变量
		double G_x,G_y,G_L; 	//光栅变量
		
		double space_front;
		
		
		
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
	
	

