// 设置PD的对接光栅
// 实现的形式是将Ledit的零点建立在光栅输入或者是输出波导的端口处
// 
#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void grating_link_line(LFile file,LCell cell)
{
	double WG_width_gr_link_line,MMI_length,MMI_width,taper_width,taper_length,radius,space_pro;
	double space_link,taper_length_grating_line,taper_width_grating_line,period,FF,grating_width;
	double pi,center_x,center_y,center_x0,center_y0;
	double factor;
	factor = 1000;
	pi = 3.1415926;
	
	WG_width_gr_link_line = 0.41*factor;//波导宽度
	MMI_length = 4.55*factor;
	MMI_width = 2*factor;
	radius = 20*factor;
	space_pro = 2*factor;
	taper_length = 4.35*factor;
	taper_width = 0.81*factor;
	space_link = 2*factor;//连接波导长度
	taper_length_grating_line = 400*factor;
	taper_width_grating_line = 12*factor;
	FF = 0.5;//占空比
	period = 0.5*factor;//光栅周期
	grating_width = 14*factor;
	center_x = 0;
	center_y = 0; 
	
	grating_left_link_line( file, cell, center_x, center_y, space_pro, WG_width_gr_link_line, taper_length_grating_line, 
	                   taper_width_grating_line, grating_width, period, FF );	
	
	
}

void grating_left_link_line( LFile file, LCell cell,  double x, double y, double space_pro, double WG_width_gr_link_line, 
                        double taper_length, double taper_width, double grating_width, double period,
						double FF)
{
		double scalefactor;   //中间变量
		double taper_x,taper_y,w;  //转移变量
		double G_x,G_y,G_L; 	//光栅变量
		double space_front;
		double line_wg_width;
		/* TODO: Begin custom generator code.*/

		//光栅的相关参数--均匀光栅
		scalefactor = 1000.0;
				
		space_front = 5*scalefactor; //光栅区前端预留的长度
		G_L = 30*scalefactor; //光栅区长度
		grating_width = taper_width;

		taper_x = x-space_front;
		taper_y = y;
		line_wg_width = 0.41*scalefactor;
	   
		w = space_pro;
	
		int i,j;
	
	
		LPoint       Points [ 2002 ];
		LObject      Torus1;
		 
		LPoint       Translation  =  LCursor_GetPosition ( ); 
		LTorusParams tParams;  
	
		
		//--------抛物线型taper的数据
		Points [0].x = taper_x-taper_length;
	    Points [0].y = taper_y+taper_width/2;
	    Points [1].x = taper_x-taper_length;
	    Points [1].y = taper_y-taper_width/2;
        Points [2].x = taper_x;
	    Points [2].y = taper_y-WG_width_gr_link_line/2;
	    Points [3].x = taper_x;
	    Points [3].y = taper_y+WG_width_gr_link_line/2;
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);			
		
		
		
		Points [0].x = taper_x;
	    Points [0].y = taper_y+WG_width_gr_link_line/2;
	    Points [1].x = taper_x;
	    Points [1].y = taper_y-WG_width_gr_link_line/2;
        Points [2].x = taper_x+space_front;
	    Points [2].y = taper_y-line_wg_width/2;
	    Points [3].x = taper_x+space_front;
	    Points [3].y = taper_y+line_wg_width/2;
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);	
		
		//--------直波导区域
		Points [0].x = taper_x-taper_length;
	    Points [0].y = taper_y+taper_width/2;
	    Points [1].x = taper_x-taper_length;
	    Points [1].y = taper_y-taper_width/2;
        Points [2].x = taper_x;
	    Points [2].y = taper_y-WG_width_gr_link_line/2;
	    Points [3].x = taper_x;
	    Points [3].y = taper_y+WG_width_gr_link_line/2;
				
		LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);	
		
	Points [0].x = taper_x-taper_length;
	Points [0].y = taper_y+taper_width/2;
	Points [1].x = taper_x-taper_length-space_front;
	Points [1].y = taper_y+taper_width/2;
    Points [2].x = taper_x-taper_length-space_front;
	Points [2].y = taper_y-taper_width/2;
	Points [3].x = taper_x-taper_length;
	Points [3].y = taper_y-taper_width/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x = taper_x-taper_length-G_L;
	Points [0].y = taper_y+taper_width/2;
	Points [1].x = taper_x-taper_length-space_front-30*period;
	Points [1].y = taper_y+taper_width/2;
	Points [2].x = taper_x-taper_length-space_front-30*period;
	Points [2].y = taper_y-taper_width/2;
	Points [3].x = taper_x-taper_length-G_L;
	Points [3].y = taper_y-taper_width/2;
	LPolygon_New ( cell, LLayer_Find( file, "Rib130" ), Points, 4);

	Points [0].x = taper_x-taper_length-space_front-30.5*period;
	Points [0].y = taper_y+taper_width/2+1*scalefactor;
	Points [1].x = taper_x-taper_length-space_front;
	Points [1].y = taper_y+taper_width/2+1*scalefactor;
	Points [2].x = taper_x-taper_length-space_front;
	Points [2].y = taper_y-taper_width/2-1*scalefactor;
	Points [3].x = taper_x-taper_length-space_front-30.5*period;
	Points [3].y = taper_y-taper_width/2-1*scalefactor;
	LPolygon_New ( cell, LLayer_Find( file, "Grating70" ), Points, 4);
	LPolygon_New ( cell, LLayer_Find( file, "Slab90" ), Points, 4);
		
		
		G_x = x-taper_length-space_front-space_front;
		G_y = y;
		
			
		for(j = 0;j<30;j++)//画30根均匀光栅
			{
			LBox_New ( cell, LLayer_Find( file, "Rib130" ) ,G_x, G_y+grating_width/2, G_x-period*(1-FF), G_y-grating_width/2);	//画第一根光栅
			G_x = G_x-period;	//将光栅的左x坐标平移
			}	//	
	Points [0].x = taper_x+(-taper_length-1.1*G_L);
	Points [0].y = taper_y+space_pro+12*scalefactor;
	Points [1].x = taper_x+(-taper_length+0.1*G_L);
	Points [1].y = taper_y+space_pro+12*scalefactor;
	Points [2].x = taper_x+(-taper_length+0.1*G_L);
	Points [2].y = taper_y-space_pro-12*scalefactor;
	Points [3].x = taper_x+(-taper_length-1.1*G_L);
	Points [3].y = taper_y-space_pro-12*scalefactor;//上
	LPolygon_New ( cell, LLayer_Find( file, "Electrode pad" ), Points, 4);
			
}//子函数结束	