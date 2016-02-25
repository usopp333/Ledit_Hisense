//module ring
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"
 double center_x,center_y,x,y,pi,CR;
 double WG_W,L,R,Etch_W,space,start,end,gap,n,A,a,Radius,hole_psgc_R,hole_psgc_P,T_width,T_length,x2,y2,hole_psgc_D,shift; 
 
 int i,j;
//    main()
void PSGC(LFile file,LCell cell)
 {
	
    pi=3.1415926;//圆周率
	WG_W=500;//波导宽度
    Radius=20000;//弯曲半径

//编辑下面调用的子函数的参数
 hole_psgc_P=480;//光子晶体周期
 hole_psgc_D=360;//光子晶体直径
 shift=100*1000;//X方向和Y方向位移量
 center_x=shift;//X方向和Y方向位移量
 center_y=shift;//X方向和Y方向位移量
 T_width=12*1000;//光子晶体区域边长
 T_length=300*1000;//Taper长度
//调用子函数
 //WG_X_circle();//调用子函数
     WG_X_circle(
		 file,
		 cell,
		 center_x,
		 center_y,
		 space,
		 T_width,
		 T_length,
		 x,
		 y,
		 hole_psgc_P,
		 hole_psgc_D,
		 shift
	);
//旋转45度后，画45度弯曲波导
  center_x=shift+Radius;
  center_y=shift+T_length+T_width/2;
  y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
  start=225;
  end=270;
//  bend_psgc();
  bend_psgc(
		file,
		cell,
		 center_x,
		 center_y,
		 Radius,
		 start,
		 end,
		 space
		);



//旋转45度后，画45度弯曲波导
  center_x=shift+T_length+T_width/2;
  center_y=shift+Radius;
  y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
  start=90;
  end=135;
 // bend_psgc();
  bend_psgc(
		file,
	  cell,
		 center_x,
		 center_y,
		 Radius,
		 start,
		 end,
		 space
		);
  
//旋转45度后，画单偏振光栅
  center_x=shift+Radius*(1-sqrt(2)/2);
  center_y=shift+T_width/2+T_length+Radius*sqrt(2)/2;
    y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
//  right49005_psgc();
	 right49005_psgc(
		 file,
		 cell,
		 center_x,
		 center_y,
		 space
		);

//旋转45度后，画单偏振光栅
  center_x=shift+T_width/2+T_length+Radius*sqrt(2)/2;
  center_y=shift+Radius*(1-sqrt(2)/2);
    y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
//  right49005_psgc();
  right49005_psgc(
		file,
		cell,
		 center_x,
		 center_y,
		 space
		);
}
 
 
 
 
 

//PSGC子函数
    WG_X_circle(
		LFile file,
		LCell cell,
		double center_x,
		double center_y,
		double space,
		double T_width,
		double T_length,
		double x,
		double y,
		double hole_psgc_P,
		double hole_psgc_D,
		double shift
	)
	{   
	double taper_x,taper_y,w,scalefactor,grating_width_2,x1,y1;              
	double G_x,G_y,WG_width;                         
	taper_x=center_x;
	taper_y=center_y;
	w=space;
	scalefactor=1000;
	WG_width=400;

	int i,j;


	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  


	//画出光子晶体光栅区域和两边的taper
	Points [0].x=taper_x-T_width/2;
	Points [0].y=taper_y-T_width/2;
	Points [1].x=taper_x-T_width/2;
	Points [1].y=taper_y+T_width/2;
	Points [2].x=taper_x-WG_width/2;
	Points [2].y=taper_y+T_width/2+T_length;
	Points [3].x=taper_x+WG_width/2;
	Points [3].y=taper_y+T_width/2+T_length;
    Points [4].x=taper_x+T_width/2;
	Points [4].y=taper_x+T_width/2;
	Points [5].x=taper_x+T_width/2+T_length;
	Points [5].y=taper_y+WG_width/2;
    Points [6].x=taper_x+T_width/2+T_length;
	Points [6].y=taper_y-WG_width/2;
	Points [7].x=taper_x+T_width/2;
	Points [7].y=taper_y-T_width/2;
	//坐标变换，进行旋转
    for (i=0;i<=7;i++)
    {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

    }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 8);

   //////////////////////////////
   //比光子晶体区域稍大一点（每边大1um）的正方形区域
	Points [0].x=taper_x-T_width/2-1000;
	Points [0].y=taper_y-T_width/2-1000;
	Points [1].x=taper_x-T_width/2-1000;
	Points [1].y=taper_y+T_width/2+1000;
	
    Points [2].x=taper_x+T_width/2+1000;
	Points [2].y=taper_x+T_width/2+1000;

	Points [3].x=taper_x+T_width/2+1000;
	Points [3].y=taper_y-T_width/2-1000;
	//坐标变化（旋转）
        for (i=0;i<=3;i++)
   {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

   }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);
   ///////////////////////////////
   //比光子晶体区域稍大（每边大1um）
	Points [0].x=taper_x-T_width/2-1000;
	Points [0].y=taper_y-T_width/2-1000;
	Points [1].x=taper_x-T_width/2-1000;
	Points [1].y=taper_y+T_width/2+1000;
	
    Points [2].x=taper_x+T_width/2+1000;
	Points [2].y=taper_x+T_width/2+1000;

	Points [3].x=taper_x+T_width/2+1000;
	Points [3].y=taper_y-T_width/2-1000;
	//坐标变换（选择)
        for (i=0;i<=3;i++)
   {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

   }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);
   //////////////////
   //比光子晶体区域更大一点（2um）画 pad
   	Points [0].x=taper_x-T_width/2-2000;
	Points [0].y=taper_y-T_width/2-2000;
	Points [1].x=taper_x-T_width/2-2000;
	Points [1].y=taper_y+T_width/2+2000;
	
    Points [2].x=taper_x+T_width/2+2000;
	Points [2].y=taper_x+T_width/2+2000;

	Points [3].x=taper_x+T_width/2+2000;
	Points [3].y=taper_y-T_width/2-2000;
	//坐标变换（旋转）
        for (i=0;i<=3;i++)
   {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

   }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);
	/////////////////////////hole_psgcs
	//画光子晶体(逐行，逐列）
   for(i=-floor(T_width/2/hole_psgc_P)+1;i<=floor(T_width/2/hole_psgc_P)-1;i++)
   for(j=-floor(T_width/2/hole_psgc_P)+1;j<=floor(T_width/2/hole_psgc_P)-1;j++)

	  {center_x=i*hole_psgc_P+shift;
		center_y=j*hole_psgc_P+shift;

   {

    y1=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
	x1=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
    center_y=y1;
    center_x=x1;

   }
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  

    tParams.ptCenter.x=center_x;
	tParams.ptCenter.y=center_y;

	tParams.nInnerRadius=0;
	tParams.nOuterRadius=hole_psgc_D/2;
	tParams.dStartAngle = 0;
	tParams.dStopAngle = 360;
	LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "PhC" ), &tParams); 

	  }	
	}
//单偏振光栅子函数
    right49005_psgc(
		LFile file,
		LCell cell,
		double center_x,
		double center_y,
		double space
		)
	{
	double taper_x,taper_y,w,scalefactor,grating_width_2;              
	double G_x,G_y,WG_width,G_L;                         
	taper_x=center_x;
	taper_y=center_y;
	w=space;
	scalefactor=1000;
	WG_width=400;
	G_L=2000;
	grating_width_2=10000;

	int i,j;


	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  


	//光栅左边taper+宽波导
	Points [0].x=taper_x;
	Points [0].y=taper_y+WG_width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y-WG_width/2;
	Points [2].x=taper_x+400*scalefactor;
	Points [2].y=taper_y-5*scalefactor;
	Points [3].x=taper_x+400*scalefactor+G_L;
	Points [3].y=taper_y-5*scalefactor;//上
    Points [4].x=taper_x+400*scalefactor+G_L;
	Points [4].y=taper_y+5*scalefactor;
	Points [5].x=taper_x+400*scalefactor;
	Points [5].y=taper_y+5*scalefactor;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 6);


	Points [0].x=taper_x+400*scalefactor;		
	Points [0].y=taper_y+5*scalefactor+2000;
	Points [1].x=taper_x+400*scalefactor+16000;
	Points [1].y=taper_y+5*scalefactor+2000;
	Points [2].x=taper_x+400*scalefactor+16000;
	Points [2].y=taper_y-5*scalefactor-2000;
	Points [3].x=taper_x+400*scalefactor;		
	Points [3].y=taper_y-5*scalefactor-2000;


	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);

	G_x=taper_x+400*scalefactor+G_L;//画光栅25根
	G_y=taper_y;
	for(j=0;j<25;j++)//画光栅
	{
	LBox_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ) ,G_x, G_y+grating_width_2/2, G_x+0.49*0.5*scalefactor, G_y-grating_width_2/2);	//画第一根光栅
	G_x+=0.49*scalefactor;	//将光栅的左x坐标平移
	}	//循环画21根光栅
		

	//光栅右端宽波导
	Points [0].x=taper_x+400*scalefactor+25*490+2000;
	Points [0].y=taper_y-5*scalefactor;
	Points [1].x=taper_x+400*scalefactor+25*490+5000+2000;
	Points [1].y=taper_y-5*scalefactor;//上
    Points [2].x=taper_x+400*scalefactor+25*490+5000+2000;
	Points [2].y=taper_y+5*scalefactor;
	Points [3].x=taper_x+400*scalefactor+25*490+2000;
	Points [3].y=taper_y+5*scalefactor;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);

	Points [0].x=taper_x+400*scalefactor+1000;		
	Points [0].y=taper_y+5*scalefactor+2000-1000;
	Points [1].x=taper_x+400*scalefactor+16000-1000;
	Points [1].y=taper_y+5*scalefactor+2000-1000;
	Points [2].x=taper_x+400*scalefactor+16000-1000;
	Points [2].y=taper_y-5*scalefactor-2000+1000;
	Points [3].x=taper_x+400*scalefactor+1000;		
	Points [3].y=taper_y-5*scalefactor-2000+1000;


	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);


	Points [0].x=taper_x+400*scalefactor+1000;		
	Points [0].y=taper_y+5*scalefactor+2000-1000;
	Points [1].x=taper_x+400*scalefactor+16000-1000;
	Points [1].y=taper_y+5*scalefactor+2000-1000;
	Points [2].x=taper_x+400*scalefactor+16000-1000;
	Points [2].y=taper_y-5*scalefactor-2000+1000;
	Points [3].x=taper_x+400*scalefactor+1000;		
	Points [3].y=taper_y-5*scalefactor-2000+1000;


	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);
	}	
//弯曲波导子函数
    bend_psgc(
		LFile file,
		LCell cell,
		double center_x,
		double center_y,
		double Radius,
		double start,
		double end,
		double space
		)
    {
	double taper_x,taper_y,w,scalefactor,grating_width_2;              
	double G_x,G_y,WG_width,G_L;                         


	w=space;
	scalefactor=1000;
	WG_width=400;
	

	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  

    tParams.ptCenter.x=center_x;
	tParams.ptCenter.y=center_y;

	tParams.nInnerRadius=Radius-WG_width/2;
	tParams.nOuterRadius=Radius+WG_width/2;
	tParams.dStartAngle = start;
	tParams.dStopAngle = end;
	LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams); 
    }


hole_psgc(
	LFile file,
	LCell cell,
	double space,
	double center_x,
	double center_y,
	double Radius,
	double start,
	double end
	)
    {
	double taper_x,taper_y,w,scalefactor,grating_width_2;              
	double G_x,G_y,WG_width,G_L;                         


	w=space;
	scalefactor=1000;
	WG_width=500;
	

	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  

    tParams.ptCenter.x=center_x;
	tParams.ptCenter.y=center_y;

	tParams.nInnerRadius=0;
	tParams.nOuterRadius=Radius;
	tParams.dStartAngle = start;
	tParams.dStopAngle = end;
	LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), &tParams); 
    }

straight_psgc(
		LFile file,
		LCell cell,
		double space,
		double center_x,
		double center_y,
		double WG_W
		)
    {
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  
	LBox_New ( Cell_Draw, LLayer_Find( File_Draw, "Bar220" ) ,center_x-5*1000,center_y+WG_W/2+space,center_x+5*1000,center_y+WG_W/2);	
    LBox_New ( Cell_Draw, LLayer_Find( File_Draw, "Bar220" ) ,center_x-5*1000,center_y-(WG_W/2+space),center_x+5*1000,center_y-WG_W/2);	
    }



/*void  ring (void)
	{
		LMacro_Register("ring", "main");
	}
}
ring();*/