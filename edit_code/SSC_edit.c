//module 	SSC_module
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"


//void main()
void SSC(LFile file,LCell cell)
{
	 double factor;
	 double length_taper,width_WG,length_front,width_SSC,width_trench,theta,width_trench_front,width_tip;

	factor=1e3;	
	
	length_taper=300*factor;
	width_WG=0.410*factor;
	length_front=1*factor;
	width_SSC=11*factor;
	width_trench=15*factor;
	width_trench_front=100*factor;
	
	width_tip=0.14*factor;
	
	//中心连接的长度

	 double length_link,radius;
	length_link=(3000-150)*factor - 2*length_taper-2*length_front-2*width_trench_front;


	
	
	double x0,y0;
	x0 = -length_link/2; // 将零点调整到坐标中心
	y0=0;
		
	char* ch_WG="Rib130";
	char* etch220="etch 220";	
	char* trench="Trench";	

	

	

	
//-----------------
SSC_left(
			file,
			cell,
			 x0,
		     y0,
				length_taper,
				width_tip,
				width_WG,
				length_front,
				width_trench,
				width_SSC,
				width_trench_front,
			ch_WG,
			etch220,
		    trench
			);
				
srtight_WG(
				file,
				cell,
				x0,
				y0,

				width_WG,
				length_link,
				ch_WG
				);		
				
SSC_right(
			file,
			cell,
			 x0+length_link,
		     y0,
			 length_taper,
			 width_tip,
			 width_WG,
			 length_front,
			 width_trench,
			 width_SSC,
			 width_trench_front,	
			ch_WG,
			etch220,
		    trench
			);				

}	



//子函数
				
void srtight_WG(
				LFile File_Draw,
				LCell Cell_Draw,
				double x,
				double y,
				double width_WG,
				double length_link,
				char* ch_WG
				)

		{
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  
					
	Points [0].x=x+0;
	Points [0].y=y+width_WG/2;
	Points [1].x=x+length_link;
	Points [1].y=y+width_WG/2;
	Points [2].x=x+length_link;
	Points [2].y=y-width_WG/2;
	Points [3].x=x+0;
	Points [3].y=y-width_WG/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, ch_WG  ), Points, 4);							
		}


void SSC_left(
LFile File_Draw,
				LCell Cell_Draw,
				double x,
				double y,

				double length_taper,
				double width_tip,
				double width_WG,
				double length_front,
				double width_trench,
				double width_SSC,
				double width_trench_front,

				char* ch_WG,
				char* etch220,
				char* trench
				)
	{
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  	
		
	//直波导层	
	Points [0].x=x-length_taper;
	Points [0].y=y+width_tip/2;
	Points [1].x=x+0;
	Points [1].y=y+width_WG/2;
	Points [2].x=x+0;
	Points [2].y=y-width_WG/2;
	Points [3].x=x-length_taper;
	Points [3].y=y-width_tip;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, ch_WG ), Points, 4);		
		

		
	//两边的trench

	//上	
	Points [0].x=x-length_taper-length_front;
	Points [0].y=y+width_SSC/2+width_trench;
	Points [1].x=x+0;
	Points [1].y=y+width_SSC/2+width_trench;
	Points [2].x=x+0;
	Points [2].y=y+width_SSC/2;
	Points [3].x=x-length_taper-length_front;
	Points [3].y=y+width_SSC/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, trench ), Points, 4);	

	//下
	Points [0].x=x-length_taper-length_front;
	Points [0].y=y-width_SSC/2-width_trench;
	Points [1].x=x+0;
	Points [1].y=y-width_SSC/2-width_trench;
	Points [2].x=x+0;
	Points [2].y=y-width_SSC/2;
	Points [3].x=x-length_taper-length_front;
	Points [3].y=y-width_SSC/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, trench ), Points, 4);	

	//前端的trench

	//	
	Points [0].x=x-length_taper-length_front-width_trench_front;
	Points [0].y=y+width_SSC/2+width_trench;
	Points [1].x=x-length_taper-length_front;
	Points [1].y=y+width_SSC/2+width_trench;
	Points [2].x=x-length_taper-length_front;
	Points [2].y=y-width_SSC/2-width_trench;
	Points [3].x=x-length_taper-length_front-width_trench_front;
	Points [3].y=y-width_SSC/2-width_trench;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, trench ), Points, 4);		
		
		
	}

void SSC_right(
				LFile File_Draw,
				LCell Cell_Draw,
				double x,
				double y,
				
				double length_taper,
				double width_tip,
				double width_WG,
				double length_front,
				double width_trench,
				double width_SSC,
				double width_trench_front,

				char* ch_WG,
				char* etch220,
				char* trench
				)
	{
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  	
		
	//直波导层	
	Points [0].x=x+length_taper;
	Points [0].y=y+width_tip/2;
	Points [1].x=x+0;
	Points [1].y=y+width_WG/2;
	Points [2].x=x+0;
	Points [2].y=y-width_WG/2;
	Points [3].x=x+length_taper;
	Points [3].y=y-width_tip;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, ch_WG ), Points, 4);	
		
	//两边的trench

	//上	
	Points [0].x=x+length_taper+length_front;
	Points [0].y=y+width_SSC/2+width_trench;
	Points [1].x=x-0;
	Points [1].y=y+width_SSC/2+width_trench;
	Points [2].x=x-0;
	Points [2].y=y+width_SSC/2;
	Points [3].x=x+length_taper+length_front;
	Points [3].y=y+width_SSC/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, trench ), Points, 4);	

	//下
	Points [0].x=x+length_taper+length_front;
	Points [0].y=y-width_SSC/2-width_trench;
	Points [1].x=x-0;
	Points [1].y=y-width_SSC/2-width_trench;
	Points [2].x=x-0;
	Points [2].y=y-width_SSC/2;
	Points [3].x=x+length_taper+length_front;
	Points [3].y=y-width_SSC/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, trench ), Points, 4);	

	//前端的trench

	//	
	Points [0].x=x+length_taper+length_front+width_trench_front;
	Points [0].y=y+width_SSC/2+width_trench;
	Points [1].x=x+length_taper+length_front;
	Points [1].y=y+width_SSC/2+width_trench;
	Points [2].x=x+length_taper+length_front;
	Points [2].y=y-width_SSC/2-width_trench;
	Points [3].x=x+length_taper+length_front+width_trench_front;
	Points [3].y=y-width_SSC/2-width_trench;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, trench ), Points, 4);		
		
		
	}



/*	void  SSC_macro_register (void)
	{
		LMacro_Register("SSC", "main");
	}

}
/* End of Module */
//SSC_macro_register();