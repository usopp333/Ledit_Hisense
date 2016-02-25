// edit by LuZeqaun
// 2016-01-19
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"



	/* TODO: Put local functions here. */
	void cross_edit(LFile file, LCell cell)
	{
		double WG_width_cross,MMI_length_cross,MMI_width_cross,taper_width_cross,taper_length_cross,radius_cross,space_pro,t_length_cross;
		double space_link_cross,theta,taper_length_cross_grating,taper_width_cross_grating,period,FF,grating_width;
		double pi,center_x0,center_y0;
		double factor,space_arc_x,space_arc_y;
		double radius_cross_1;
		double space_arc_x_1,space_arc_y_1;
		double x,y;
		int i;
		
		factor=1000;
		pi=3.1415926;
		MMI_width_cross=1.4*factor;
		MMI_length_cross=7*factor;
		taper_width_cross=1.4*factor;
		taper_length_cross=2*factor;
		WG_width_cross=0.41*factor;
		space_link_cross=5*factor;//连接波导长度
		t_length_cross=10*factor;
		space_pro=2*factor;
		radius_cross=15*factor;
		
		taper_length_cross_grating=400*factor;
		taper_width_cross_grating=12*factor;
		center_x0=0;
		center_y0=(0+10)*factor; ////需要将零点调整到器件的中心
		x=center_x0;
		y=center_y0;
		
		/* TODO: Begin custom generator code.*/
		MMI_cross_neg_para(file, cell,
							x,
							y,
				         MMI_length_cross,
							MMI_width_cross,
							WG_width_cross,
							taper_width_cross,
							taper_length_cross,
							space_pro
							);

		y=center_y0+MMI_length_cross/2+taper_length_cross;		
		
		terminal_WG_up_cross(file, cell,
							x,
							y,
							WG_width_cross,
							t_length_cross,
							space_pro
							);
//--------------------------------------------------	
		x=-MMI_length_cross/2-taper_length_cross-space_link_cross/2;
		y=center_y0+0;		
							
		link_WG_single_cross(file, cell,
							x,
							y,
							space_link_cross,
							WG_width_cross
							
							);

		x=MMI_length_cross/2+taper_length_cross+space_link_cross/2;
		y=center_y0+0;		
							
		link_WG_single_cross(file, cell,
							x,
							y,
							space_link_cross,
							WG_width_cross
							
							);
//-----------------------------------
		
		x=center_x0-MMI_length_cross/2-taper_length_cross-space_link_cross;
							
		parabolic_grating_left_NG_cross(file, cell,
											x,
											y,
											space_pro,
											WG_width_cross,
											taper_length_cross_grating,
											taper_width_cross_grating
										
											);							
														
		x=center_x0+MMI_length_cross/2+taper_length_cross+space_link_cross;
							
		parabolic_grating_right_NG_cross(file, cell,
											x,
											y,
											space_pro,
											WG_width_cross,
											taper_length_cross_grating,
											taper_width_cross_grating
											
											);	
//----------------------------------------------------




//------------------------------------------		
		x=center_x0+radius_cross;
		y=center_y0-MMI_length_cross/2-taper_length_cross-radius_cross;
							
		parabolic_grating_right_NG_cross(file, cell,
											x,
											y,
											space_pro,
											WG_width_cross,
											taper_length_cross_grating,
											taper_width_cross_grating
											
											);			
		
		
//----------------------------------------------------
		LPoint       Points [ 1002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 

		tParams.ptCenter.x=center_x0+radius_cross;
		tParams.ptCenter.y=center_y0+-MMI_length_cross/2-taper_length_cross;
		
		tParams.nInnerRadius=radius_cross-WG_width_cross/2;
		tParams.nOuterRadius=radius_cross+WG_width_cross/2;
		tParams.dStartAngle = 180;
		tParams.dStopAngle = 270;
		LTorus_CreateNew(cell, LLayer_Find( file, "Rib130" ), &tParams); 

//------------------------------------------		
		x=center_x0+radius_cross;
		y=center_y0-MMI_length_cross/2-taper_length_cross-radius_cross;
							
		parabolic_grating_right_NG_cross(file, cell,
											x,
											y,
											space_pro,
											WG_width_cross,
											taper_length_cross_grating,
											taper_width_cross_grating
											
											);		
		
																		
		/* End custom generator code.*/
	}//---------------------------------------------------------------主函数结束
	
	
void MMI_cross_neg_para(
						LFile file, LCell cell,
						double x,
						double y,
						double Length_MMI_cross,
						double Width_MMI,
						double Width_WG,
						double Width_taper_cross,
						double Length_taper_cross,
						double Pro_space
					
						)

	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		// 左 taper
		Points [0].x=x-Length_MMI_cross/2;		
		Points [0].y=y+Width_taper_cross/2;
	
	
		Points [1].x=x-Length_MMI_cross/2;	
		Points [1].y=y-Width_taper_cross/2;
		
		Points [2].x=x-Length_MMI_cross/2-Length_taper_cross;
		Points [2].y=y-Width_WG/2;
		
		Points [3].x=x-Length_MMI_cross/2-Length_taper_cross;	
		Points [3].y=y+Width_WG/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);		
		
		
		
		// MMI
		Points [0].x=x-Length_MMI_cross/2;		
		Points [0].y=y+Width_MMI/2;
	
	
		Points [1].x=x-Length_MMI_cross/2;	
		Points [1].y=y-Width_MMI/2;
		
		Points [2].x=x+Length_MMI_cross/2;
		Points [2].y=y-Width_MMI/2;
		
		Points [3].x=x+Length_MMI_cross/2;	
		Points [3].y=y+Width_MMI/2;		

		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);
		
		//mmi
		Points [0].x=x-Width_MMI/2;		
		Points [0].y=y+Length_MMI_cross/2;
	
	
		Points [1].x=x-Width_MMI/2;		
		Points [1].y=y-Length_MMI_cross/2;
		
		Points [2].x=x+Width_MMI/2;	
		Points [2].y=y-Length_MMI_cross/2;
		
		Points [3].x=x+Width_MMI/2;		
		Points [3].y=y+Length_MMI_cross/2;	

		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);
		
		//绘制抛物线taper
		

		
		
	//右上四段---------------------------------------------------------------------------------------
		//绘制抛物线taper
		Points [0].x=x+Length_MMI_cross/2;		
		Points [0].y=y+Width_taper_cross/2;
	
	
		Points [1].x=x+Length_MMI_cross/2;	
		Points [1].y=y-Width_taper_cross/2;
		
		Points [2].x=x+Length_MMI_cross/2+Length_taper_cross;
		Points [2].y=y-Width_WG/2;
		
		Points [3].x=x+Length_MMI_cross/2+Length_taper_cross;	
		Points [3].y=y+Width_WG/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);	
	//左下四段----------------------------------------------------------------------------------------
		//绘制抛物线taper
		
		Points [0].y=y-Length_MMI_cross/2;		
		Points [0].x=x+Width_taper_cross/2;
	
	
		Points [1].y=y-Length_MMI_cross/2;	
		Points [1].x=x-Width_taper_cross/2;
		
		Points [2].y=y-Length_MMI_cross/2-Length_taper_cross;
		Points [2].x=x-Width_WG/2;
		
		Points [3].y=y-Length_MMI_cross/2-Length_taper_cross;	
		Points [3].x=x+Width_WG/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);	

		
		Points [0].y=y+Length_MMI_cross/2;		
		Points [0].x=x+Width_taper_cross/2;
	
	
		Points [1].y=y+Length_MMI_cross/2;	
		Points [1].x=x-Width_taper_cross/2;
		
		Points [2].y=y+Length_MMI_cross/2+Length_taper_cross;
		Points [2].x=x-Width_WG/2;
		
		Points [3].y=y+Length_MMI_cross/2+Length_taper_cross;	
		Points [3].x=x+Width_WG/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);
		

	}//子程序结束
	
	
void terminal_WG_up_cross(LFile file, LCell cell,
						double x,
						double y,
						double Width_WG,
						double Length,
						double Pro_space
						 )
								
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		Points [0].x=x;
		Points [0].y=y+Length;
		Points [1].x=x-Width_WG/2;
		Points [1].y=y;
		
		Points [2].x=x+Width_WG/2;
		Points [2].y=y+0;
	
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 3);
		

		
	}//子函数结束
	
void terminal_WG_down(LFile file, LCell cell,
						double x,
						double y,
						double Width_WG,
						double Length,
						double Pro_space
						)
								
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		Points [0].x=x;
		Points [0].y=y-Length;
		Points [1].x=x-Width_WG/2;
		Points [1].y=y;
		
		Points [2].x=x+Width_WG/2;
		Points [2].y=y+0;
	
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 3);		
		
	}//子函数结束

void link_WG_single_cross(LFile file, LCell cell,
							double x,
							double y,
							double space_link_cross,
							double WG_width_cross
						
							)	
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams; 
		
		Points [0].x=x-space_link_cross/2;		
		Points [0].y=y+WG_width_cross/2;
	
	
		Points [1].x=x-space_link_cross/2;	
		Points [1].y=y-WG_width_cross/2;
	
		Points [2].x=x+space_link_cross/2;
		Points [2].y=y-WG_width_cross/2;
	
	
		Points [3].x=x+space_link_cross/2;
		Points [3].y=y+WG_width_cross/2;	
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);	
		
		
		
	}//子函数结束	
	
void parabolic_grating_left_NG_cross(LFile file, LCell cell,
									double x,
									double y,
									double space_pro,
									double WG_width_cross,
									double taper_length_cross,
									double taper_width_cross
								
									)
		{
		double grating_width,grating_width_2,scalefactor;   //中间变量
		double taper_x,taper_y,w;               //转移变量
		double G_x,G_y,G_L,dx,neff; 	//光栅变量
		double lamda,space_front;
		
		/* TODO: Begin custom generator code.*/

		//光栅的相关参数--均匀光栅
		scalefactor=1000.0;
			space_front=5*	scalefactor;
		
			
		G_L=30*scalefactor;//光栅区长度
		dx = 0.05*scalefactor;//曲线的精度
		lamda = 1.55*scalefactor;//波长
		neff = 3.1;//波导的有效折射率
		taper_x=x;
		taper_y=y;
	   
		w=space_pro;
	
		int i,j;
	
	
		LPoint       Points [ 2002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  
	
		grating_width=12*scalefactor;
		grating_width_2=12*scalefactor;
		
		//--------抛物线型taper的数据
		Points [0].x=taper_x-taper_length_cross;
	    Points [0].y=taper_y+taper_width_cross/2;
	    Points [1].x=taper_x-taper_length_cross;
	    Points [1].y=taper_y-taper_width_cross/2;
        Points [2].x=x;
	    Points [2].y=taper_y-WG_width_cross/2;
	    Points [3].x=x;
	    Points [3].y=taper_y+WG_width_cross/2;
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);	
		
		
		
		
		
			
		//--------
		
		
		
	


		//--------直波导区域
		
	Points [0].x=taper_x-taper_length_cross;
	Points [0].y=taper_y+taper_width_cross/2;
	Points [1].x=x-taper_length_cross-space_front;
	Points [1].y=taper_y+taper_width_cross/2;
    Points [2].x=x-taper_length_cross-space_front;
	Points [2].y=taper_y-taper_width_cross/2;
	Points [3].x=taper_x-taper_length_cross;
	Points [3].y=taper_y-taper_width_cross/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=taper_x-taper_length_cross-G_L;
	Points [0].y=taper_y+taper_width_cross/2;
	Points [1].x=x-taper_length_cross-space_front-30*490;
	Points [1].y=taper_y+taper_width_cross/2;
	Points [2].x=x-taper_length_cross-space_front-30*490;
	Points [2].y=taper_y-taper_width_cross/2;
	Points [3].x=taper_x-taper_length_cross-G_L;
	Points [3].y=taper_y-taper_width_cross/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=x-taper_length_cross-space_front-30.5*490;
	Points [0].y=taper_y+taper_width_cross/2+1*scalefactor;
	Points [1].x=x-taper_length_cross-space_front;
	Points [1].y=taper_y+taper_width_cross/2+1*scalefactor;
	Points [2].x=x-taper_length_cross-space_front;
	Points [2].y=taper_y-taper_width_cross/2-1*scalefactor;
	Points [3].x=x-taper_length_cross-space_front-30.5*490;
	Points [3].y=taper_y-taper_width_cross/2-1*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);
		
		
		G_x=x-taper_length_cross-space_front;
		G_y=y;
		
			
		for(j=0;j<30;j++)//画30根均匀光栅
			{
			LBox_New ( cell, LLayer_Find( file, "Rib130" ) ,G_x, G_y+grating_width/2, G_x-490*(0.5), G_y-grating_width/2);	//画第一根光栅
			G_x=G_x-490;	//将光栅的左x坐标平移
			}	//	
	Points [0].x=taper_x+(-taper_length_cross-1.1*G_L);
	Points [0].y=taper_y+space_pro+12*scalefactor;
	Points [1].x=taper_x+(-taper_length_cross+0.1*G_L);
	Points [1].y=taper_y+space_pro+12*scalefactor;
	Points [2].x=taper_x+(-taper_length_cross+0.1*G_L);
	Points [2].y=taper_y-space_pro-12*scalefactor;
	Points [3].x=taper_x+(-taper_length_cross-1.1*G_L);
	Points [3].y=taper_y-space_pro-12*scalefactor;//上
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);
	
		
		}//子函数结束	
void parabolic_grating_right_NG_cross(LFile file, LCell cell,
									double x,
									double y,
									double space_pro,
									double WG_width_cross,
									double taper_length_cross,
									double taper_width_cross
								
									 )
		{
		double grating_width,grating_width_2,scalefactor;   //中间变量
		double taper_x,taper_y,w;               //转移变量
		double G_x,G_y,G_L,dx,neff; 	//光栅变量
		double lamda,space_front;
		
		/* TODO: Begin custom generator code.*/

		//光栅的相关参数--均匀光栅
		scalefactor=1000.0;
		
		space_front=5*	scalefactor;
			
		G_L=30*scalefactor;//光栅区长度
		dx = 0.05*scalefactor;//曲线的精度
		lamda = 1.55*scalefactor;//波长
		neff = 3.1;//波导的有效折射率
		taper_x=x;
		taper_y=y;
	   
		w=space_pro;
	
		int i,j;
	
	
		LPoint       Points [ 2002 ];
		LObject      Torus1;
	 
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  
	
		grating_width=12*scalefactor;
		grating_width_2=12*scalefactor;
		
		//--------抛物线型taper的数据
		Points [0].x=taper_x+taper_length_cross;
	    Points [0].y=taper_y+taper_width_cross/2;
	    Points [1].x=taper_x+taper_length_cross;
	    Points [1].y=taper_y-taper_width_cross/2;
        Points [2].x=x;
	    Points [2].y=taper_y-WG_width_cross/2;
	    Points [3].x=x;
	    Points [3].y=taper_y+WG_width_cross/2;
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);		
		
		
			
		//--------
		
	Points [0].x=taper_x+taper_length_cross;
	Points [0].y=taper_y+taper_width_cross/2;
	Points [1].x=x+taper_length_cross+space_front;
	Points [1].y=taper_y+taper_width_cross/2;
    Points [2].x=x+taper_length_cross+space_front;
	Points [2].y=taper_y-taper_width_cross/2;
	Points [3].x=taper_x+taper_length_cross;
	Points [3].y=taper_y-taper_width_cross/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=taper_x+taper_length_cross+G_L;
	Points [0].y=taper_y+taper_width_cross/2;
	Points [1].x=x+taper_length_cross+space_front+30*490;
	Points [1].y=taper_y+taper_width_cross/2;
	Points [2].x=x+taper_length_cross+space_front+30*490;
	Points [2].y=taper_y-taper_width_cross/2;
	Points [3].x=taper_x+taper_length_cross+G_L;
	Points [3].y=taper_y-taper_width_cross/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x=x-(-taper_length_cross-space_front-30.5*490);
	Points [0].y=taper_y+taper_width_cross/2+1*scalefactor;
	Points [1].x=x-(-taper_length_cross-space_front);
	Points [1].y=taper_y+taper_width_cross/2+1*scalefactor;
	Points [2].x=x-(-taper_length_cross-space_front);
	Points [2].y=taper_y-taper_width_cross/2-1*scalefactor;
	Points [3].x=x-(-taper_length_cross-space_front-30.5*490);
	Points [3].y=taper_y-taper_width_cross/2-1*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);
		
		
		G_x=x+taper_length_cross+space_front;
		G_y=y;
		
			
		for(j=0;j<30;j++)//画30根均匀光栅
			{
			LBox_New ( cell, LLayer_Find( file, "Rib130" ) ,G_x, G_y+grating_width/2, G_x+490*(0.5), G_y-grating_width/2);	//画第一根光栅
			G_x=G_x+490;	//将光栅的左x坐标平移
			}	//	
	Points [0].x=taper_x-(-taper_length_cross-1.1*G_L);
	Points [0].y=taper_y+space_pro+12*scalefactor;
	Points [1].x=taper_x-(-taper_length_cross+0.1*G_L);
	Points [1].y=taper_y+space_pro+12*scalefactor;
	Points [2].x=taper_x-(-taper_length_cross+0.1*G_L);
	Points [2].y=taper_y-space_pro-12*scalefactor;
	Points [3].x=taper_x-(-taper_length_cross-1.1*G_L);
	Points [3].y=taper_y-space_pro-12*scalefactor;//上
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);

	}//子函数结束			
	

