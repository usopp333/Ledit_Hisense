//module 	switch_module
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"

//main()
void PSR1310_SSC(LFile file, LCell cell)
{
 /*全局变量声明*/
   double scalefactor,pi;
   double center_x,center_y,taper_input_length,taper_input_width,taper_output_width,taper_taper_width;
   double taper_slab_width,taper_taper1_length,taper_taper2_length;
   double mid_taper_length;
  
   double ac_input1_width,ac_input2_width,ac_gap,ac_output1_width,ac_output2_width,ac_taper_length;
   double ac_radius,ac_theta;

   double after_ac_taper_length,after_ac_taper_width,after_ac_radius,after_ac_theta;

   double device_length,total_length;


  /* Parameter Setting */
  scalefactor=1.0E3;
  pi=3.1415926;
  //total_length=2000*scalefactor;
  device_length=0*scalefactor;
/*初始参数设置*/

 /*bilevel taper参数*/
 taper_input_width=0.4*scalefactor;
 taper_output_width=0.8*scalefactor;
 taper_input_length=5*scalefactor;
 taper_taper_width=0.6*scalefactor;
 taper_slab_width=1.5*scalefactor;
 taper_taper1_length=50*scalefactor;
 taper_taper2_length=30*scalefactor;
 /*中间链接波导taper长度*/
 mid_taper_length=10*scalefactor;
 /*adiabatic coupler参数*/
 ac_input1_width=0.7*scalefactor;
 ac_input2_width=0.2*scalefactor;
 ac_gap=0.2*scalefactor;
 ac_output1_width=0.55*scalefactor;
 ac_output2_width=0.35*scalefactor;
 ac_taper_length=400*scalefactor;
 ac_radius=10*scalefactor;
 ac_theta=30;
 after_ac_taper_length=10*scalefactor;
 after_ac_taper_width=0.4*scalefactor;
 after_ac_radius=30*scalefactor;
 after_ac_theta=45;
 
 total_length=((3000-150)*scalefactor-(320*scalefactor*2+2*taper_input_length+taper_taper1_length+taper_taper2_length+3*mid_taper_length+ac_taper_length+after_ac_taper_length+2*after_ac_radius*sin(after_ac_theta*pi/180)));
 //total_length=3000*scalefactor;
 
 center_x= -(3000-150)*scalefactor/2+320*scalefactor; //设置零点为器件中心
 center_y=0*scalefactor;


 /*左侧SSC*/
 //left_ssc();
 left_ssc(
	 file,
	 cell,
	 scalefactor,
	 center_x,
	 center_y,
	 taper_input_width	
		);
 /*bilevel taper函数*/
 //bilevel_taper();
 bilevel_taper(
	 file,
	 cell,
	 center_x,
	 center_y,
	 taper_input_width,
	 taper_input_length,
	 taper_taper1_length,
	 taper_taper_width,
	 taper_taper2_length,
	 taper_output_width,
	 taper_slab_width
				);
 center_x=center_x+taper_input_length+taper_taper1_length+taper_taper2_length+taper_input_length;
 center_y=center_y;
 device_length=taper_input_length+taper_taper1_length+taper_taper2_length+taper_input_length;
 /*taper改变输出波导的宽度*/
 LPoint       Points [ 1002 ];
 LObject      Torus1;
// LCell        Cell_Draw   = LCell_GetVisible( );
// LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
 LCell        Cell_Draw   = cell;
 LFile        File_Draw   = file;
 LPoint       Translation = LCursor_GetPosition ( ); 
 LTorusParams tParams;
 Points [0].x=center_x;
 Points [0].y=center_y-taper_output_width/2;
 Points [1].x=Points[0].x+mid_taper_length;
 Points [1].y=center_y-ac_input1_width/2;
 Points [2].x=Points [1].x;
 Points [2].y=Points [1].y+ac_input1_width;
 Points [3].x=Points [0].x;
 Points [3].y=center_y+taper_output_width/2;
 LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
 /*adiabatic coupler*/
 center_x=center_x+mid_taper_length;
 device_length=device_length+mid_taper_length;

 //adiabatic_coupler();
  adiabatic_coupler(
	  file,
	  cell,
	  center_x,
	  center_y,
	  ac_input1_width,
	  ac_radius,
	  ac_theta,
	  pi,
	  ac_gap,
	  ac_input2_width,
	  ac_taper_length,
	  ac_output1_width,
	  ac_output2_width
				);

 center_x=center_x+2*ac_radius*sin(ac_theta*pi/180)+ac_taper_length+2*ac_radius*sin(ac_theta*pi/180);
 device_length=device_length+2*ac_radius*sin(ac_theta*pi/180)+ac_taper_length+2*ac_radius*sin(ac_theta*pi/180);
 center_y=center_y;

 /*输出taper*/
 /*上端*/
 Points [0].x=center_x;
 Points [0].y=center_y-ac_input1_width/2;
 Points [1].x=Points[0].x+after_ac_taper_length;
 Points [1].y=Points[0].y;
 Points [2].x=Points [1].x;
 Points [2].y=Points [1].y+after_ac_taper_width;//0.35变换到0.4
 Points [3].x=Points [0].x;
 Points [3].y=Points[0].y+ac_output2_width;
 LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
 /*下端*///0.35变换到0.4
 Points [0].x=center_x;
 Points [0].y=center_y-ac_input1_width/2-ac_gap-ac_output2_width/2-ac_radius+2*ac_radius*cos(ac_theta*pi/180)-ac_radius-ac_output2_width/2;
 Points [1].x=Points[0].x+after_ac_taper_length;
 Points [1].y=center_y-ac_input1_width/2-ac_gap-ac_output2_width/2-ac_radius+2*ac_radius*cos(ac_theta*pi/180)-ac_radius-after_ac_taper_width/2;
 Points [2].x=Points [1].x;
 Points [2].y=Points [1].y+after_ac_taper_width;
 Points [3].x=Points [0].x;
 Points [3].y=Points[0].y+ac_output2_width;
 LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);

 center_x=center_x+after_ac_taper_length;
 device_length=device_length+after_ac_taper_length;
 /*上端弯曲波导*/
 tParams.ptCenter.x =center_x;
 tParams.ptCenter.y =center_y-ac_input1_width/2+after_ac_taper_width/2+after_ac_radius;	
 tParams.nInnerRadius = after_ac_radius-after_ac_taper_width/2;
 tParams.nOuterRadius = after_ac_radius+after_ac_taper_width/2;
 tParams.dStartAngle =270;
 tParams.dStopAngle =270+after_ac_theta;
 LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams); 
 
 tParams.ptCenter.x =center_x+2*after_ac_radius*sin(after_ac_theta*pi/180);
 tParams.ptCenter.y =center_y-ac_input1_width/2+after_ac_taper_width/2+after_ac_radius-2*after_ac_radius*cos(after_ac_theta*pi/180);	
 tParams.nInnerRadius = after_ac_radius-after_ac_taper_width/2;
 tParams.nOuterRadius = after_ac_radius+after_ac_taper_width/2;
 tParams.dStartAngle =90;
 tParams.dStopAngle =90+after_ac_theta;
 LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams);
 
 /*下端弯曲波导*/
 tParams.ptCenter.x =center_x;
 tParams.ptCenter.y =center_y-ac_input1_width/2-ac_gap-ac_output2_width/2-ac_radius+2*ac_radius*cos(ac_theta*pi/180)-ac_radius-after_ac_radius;
 tParams.nInnerRadius = after_ac_radius-after_ac_taper_width/2;
 tParams.nOuterRadius = after_ac_radius+after_ac_taper_width/2;
 tParams.dStartAngle =90-after_ac_theta;
 tParams.dStopAngle =90;
 LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams); 
 
 tParams.ptCenter.x =center_x+2*after_ac_radius*sin(after_ac_theta*pi/180);
 tParams.ptCenter.y =center_y-ac_input1_width/2-ac_gap-ac_output2_width/2-2*ac_radius+2*ac_radius*cos(ac_theta*pi/180)-after_ac_radius+2*after_ac_radius*cos(after_ac_theta*pi/180);	
 tParams.nInnerRadius = after_ac_radius-after_ac_taper_width/2;
 tParams.nOuterRadius = after_ac_radius+after_ac_taper_width/2;
 tParams.dStartAngle =270-after_ac_theta;
 tParams.dStopAngle =270;
 LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams);

 double up_y,down_y;
 up_y=center_y-ac_input1_width/2+after_ac_taper_width/2+2*after_ac_radius-2*after_ac_radius*cos(after_ac_theta*pi/180);
 down_y=center_y-ac_input1_width/2-ac_gap-ac_output2_width/2-2*ac_radius+2*ac_radius*cos(ac_theta*pi/180)-2*after_ac_radius+2*after_ac_radius*cos(after_ac_theta*pi/180);
 
 center_x=center_x+2*after_ac_radius*sin(after_ac_theta*pi/180);
 device_length=device_length+2*after_ac_radius*sin(after_ac_theta*pi/180);
 double left_length;
 left_length=total_length;//-center_x; // edit by LuZequan
 /*上端直波导*/
 Points [0].x=center_x;
 Points [0].y=up_y-after_ac_taper_width/2;
 Points [1].x=Points[0].x+left_length;
 Points [1].y=Points[0].y;
 Points [2].x=Points [1].x;
 Points [2].y=Points [1].y+after_ac_taper_width;
 Points [3].x=Points [0].x;
 Points [3].y=Points[0].y+after_ac_taper_width;
 LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
 /*下端直波导*/
 Points [0].x=center_x;
 Points [0].y=down_y-after_ac_taper_width/2;
 Points [1].x=Points[0].x+left_length;
 Points [1].y=Points[0].y;
 Points [2].x=Points [1].x;
 Points [2].y=Points [1].y+after_ac_taper_width;
 Points [3].x=Points [0].x;
 Points [3].y=Points[0].y+after_ac_taper_width;
 LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);

 center_x=center_x+left_length;
 device_length=device_length+left_length;
 /*上端ssc*/
 center_y=up_y;
 //right_ssc();
 right_ssc(
	 file,
	 cell,
	 scalefactor,
	 center_x,
	 center_y,
	 taper_input_width	
		);
 /*下端ssc*/
 center_y=down_y;
 //right_ssc();
 right_ssc(
	 file,
	 cell,
	 scalefactor,
	 center_x,
	 center_y,
	 taper_input_width	
		);
}

 adiabatic_coupler(
	 LFile file,
	 LCell cell,
	 double center_x,
	 double center_y,
	 double ac_input1_width,
	 double ac_radius,
	 double ac_theta,
	 double pi,
	 double ac_gap,
	 double ac_input2_width,
	 double ac_taper_length,
	 double ac_output1_width,
	 double ac_output2_width
				)
	{
	 double ac_x,ac_y;
	 ac_x=center_x;
	 ac_y=center_y;
     LPoint       Points [ 1002 ];
     LObject      Torus1;
     //LCell        Cell_Draw   = LCell_GetVisible( );
    // LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	 LCell        Cell_Draw   = cell;
     LFile        File_Draw   = file;
     LPoint       Translation = LCursor_GetPosition ( ); 
     LTorusParams tParams;
	 //下面波导弯曲部分对应于上部波导的部分（画成条波导）
     Points [0].x=ac_x;
     Points [0].y=ac_y-ac_input1_width/2;
     Points [1].x=Points[0].x+2*ac_radius*sin(ac_theta*pi/180);
     Points [1].y=Points [0].y;
     Points [2].x=Points [1].x;
     Points [2].y=Points [1].y+ac_input1_width;
     Points [3].x=Points [0].x;
     Points [3].y=ac_y+ac_input1_width/2;
     LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	 //下部第二个弯（凸）
	 ac_x=ac_x+2*ac_radius*sin(ac_theta*pi/180);
	 ac_y=ac_y;
     tParams.ptCenter.x =ac_x;
	 tParams.ptCenter.y =ac_y-ac_input1_width/2-ac_gap-ac_input2_width/2-ac_radius;	
     tParams.nInnerRadius = ac_radius-ac_input2_width/2;
     tParams.nOuterRadius = ac_radius+ac_input2_width/2;
     tParams.dStartAngle =90;
     tParams.dStopAngle =90+ac_theta;
     LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams); 
	 //下部第一个弯（凹）
     tParams.ptCenter.x =center_x;
     tParams.ptCenter.y =ac_y-ac_input1_width/2-ac_gap-ac_input2_width/2-ac_radius+2*ac_radius*cos(ac_theta*pi/180);	
     tParams.nInnerRadius = ac_radius-ac_input2_width/2;
     tParams.nOuterRadius = ac_radius+ac_input2_width/2;
     tParams.dStartAngle =270;
     tParams.dStopAngle = 270+ac_theta;
     LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams);
	 //耦合区域上波导
     Points [0].x=ac_x;
     Points [0].y=ac_y-ac_input1_width/2;
     Points [1].x=Points[0].x+ac_taper_length;
     Points [1].y=ac_y-ac_input1_width/2;
     Points [2].x=Points [1].x;
     Points [2].y=Points [1].y+ac_output1_width;
     Points [3].x=Points [0].x;
     Points [3].y=ac_y+ac_input1_width/2;
     LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	 //耦合区域下波导
     Points [0].x=ac_x;
     Points [0].y=ac_y-ac_input1_width/2-ac_gap-ac_input2_width;
     Points [1].x=Points[0].x+ac_taper_length;
     Points [1].y=ac_y-ac_input1_width/2-ac_gap-ac_output2_width;
     Points [2].x=Points [1].x;
     Points [2].y=ac_y-ac_input1_width/2-ac_gap;
     Points [3].x=Points [0].x;
     Points [3].y=ac_y-ac_input1_width/2-ac_gap;
     LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	 
     ac_x=ac_x+ac_taper_length;
	 ac_y=ac_y;
	 //耦合区域后波导宽度变换taper
     Points [0].x=ac_x;
     Points [0].y=ac_y-ac_input1_width/2;

     Points [1].x=Points[0].x+2*ac_radius*sin(ac_theta*pi/180);
     Points [1].y=ac_y-ac_input1_width/2;

     Points [2].x=Points [1].x;
     Points [2].y=Points [1].y+ac_output2_width;

     Points [3].x=Points [0].x;
     Points [3].y=Points[0].y+ac_output1_width;
     LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	 //耦合下波导输出端弯曲波导（凸）
     tParams.ptCenter.x =ac_x;
	 tParams.ptCenter.y =ac_y-ac_input1_width/2-ac_gap-ac_output2_width/2-ac_radius;	
     tParams.nInnerRadius = ac_radius-ac_output2_width/2;
     tParams.nOuterRadius = ac_radius+ac_output2_width/2;
     tParams.dStartAngle =90-ac_theta;
     tParams.dStopAngle =90;
     LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams); 
	 //耦合下波导输出端弯曲波导（凸）
     tParams.ptCenter.x =ac_x+2*ac_radius*sin(ac_theta*pi/180);
     tParams.ptCenter.y =ac_y-ac_input1_width/2-ac_gap-ac_output2_width/2-ac_radius+2*ac_radius*cos(ac_theta*pi/180);	
     tParams.nInnerRadius = ac_radius-ac_output2_width/2;
     tParams.nOuterRadius = ac_radius+ac_output2_width/2;
     tParams.dStartAngle =270-ac_theta;
     tParams.dStopAngle = 270;
     LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams);
	}

bilevel_taper(
	LFile file,
	LCell cell,
	double center_x,
	double center_y,
	double taper_input_width,
	double taper_input_length,
	double taper_taper1_length,
	double taper_taper_width,
	double taper_taper2_length,
	double taper_output_width,
	double taper_slab_width
				)
	{
	double bilevel_taper_x,bilevel_taper_y;
	bilevel_taper_x=center_x;
	bilevel_taper_y=center_y;

	LPoint       Points [ 1002 ];
    LObject      Torus1;
    //LCell        Cell_Draw   = LCell_GetVisible( );
    //LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
     LFile        File_Draw   = file;
    LPoint       Translation = LCursor_GetPosition ( ); 
    LTorusParams tParams;  
   
    Points [0].x=bilevel_taper_x;
    Points [0].y=bilevel_taper_y-taper_input_width/2;
    Points [1].x=Points[0].x+taper_input_length;
    Points [1].y=Points[0].y;
    Points [2].x=Points [1].x;
    Points [2].y=Points [1].y+taper_input_width;
    Points [3].x=Points [0].x;
    Points [3].y=Points [2].y;
    LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
   
    Points [0].x=bilevel_taper_x+taper_input_length;
    Points [0].y=bilevel_taper_y-taper_input_width/2;
    Points [1].x=Points[0].x+taper_taper1_length;
    Points [1].y=bilevel_taper_y-taper_taper_width/2;
    Points [2].x=Points [1].x;
    Points [2].y=Points [1].y+taper_taper_width;
    Points [3].x=Points [0].x;
    Points [3].y=bilevel_taper_y+taper_input_width/2;
    LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	
    Points [0].x=bilevel_taper_x+taper_input_length+taper_taper1_length;
    Points [0].y=bilevel_taper_y-taper_taper_width/2;
    Points [1].x=Points[0].x+taper_taper2_length;
    Points [1].y=bilevel_taper_y-taper_output_width/2;
    Points [2].x=Points [1].x;
    Points [2].y=Points [1].y+taper_output_width;
    Points [3].x=Points [0].x;
    Points [3].y=bilevel_taper_y+taper_taper_width/2;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	
    Points [0].x=bilevel_taper_x+taper_input_length+taper_taper1_length+taper_taper2_length;
    Points [0].y=bilevel_taper_y-taper_output_width/2;
    Points [1].x=Points[0].x+taper_input_length;
    Points [1].y=Points[0].y;
    Points [2].x=Points [1].x;
    Points [2].y=Points [1].y+taper_output_width;
    Points [3].x=Points [0].x;
    Points [3].y=Points [2].y;
    LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	
    Points [0].x=bilevel_taper_x+taper_input_length;
    Points [0].y=bilevel_taper_y-taper_input_width/2;
    Points [1].x=Points[0].x+taper_taper1_length;
    Points [1].y=bilevel_taper_y-taper_slab_width/2;
    Points [2].x=Points [1].x;
    Points [2].y=Points [1].y+taper_slab_width;
    Points [3].x=Points [0].x;
    Points [3].y=bilevel_taper_y+taper_input_width/2;
    LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);
	
    Points [0].x=bilevel_taper_x+taper_input_length+taper_taper1_length;
    Points [0].y=bilevel_taper_y-taper_slab_width/2;
    Points [1].x=Points[0].x+taper_taper2_length;
    Points [1].y=bilevel_taper_y-taper_output_width/2;
    Points [2].x=Points [1].x;
    Points [2].y=Points [1].y+taper_output_width;
    Points [3].x=Points [0].x;
    Points [3].y=bilevel_taper_y+taper_slab_width/2;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);
	}


left_ssc(
	LFile file,
	LCell cell,
	double scalefactor,
	double center_x,
	double center_y,
	double taper_input_width	
		)
	{
  //ssc参数
  double w_taper,l_taper,w_SiO2_1,w_SiO2_2,w_Trench,l_buttfacet,ssc_total_length;//SSC的尺寸
  ssc_total_length=320*scalefactor;
  w_taper = 0.18 * scalefactor;//taper尖端宽度
  w_SiO2_1 = 6 * scalefactor;//SiO2波导的前端宽度
  w_SiO2_2 = 4 * scalefactor;//SiO2波导的后端宽度
  w_Trench = 10 * scalefactor;//SiO2波导两边沟槽的宽度
  l_buttfacet = 1* scalefactor;//Si波导的尖端到端面的距离
  l_taper = ssc_total_length-l_buttfacet;//taper长度
    LPoint       Points [ 1002 ];
    LObject      Torus1;
   // LCell        Cell_Draw   = LCell_GetVisible( );
   // LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
   LCell        Cell_Draw   = cell;
     LFile        File_Draw   = file;
    LPoint       Translation = LCursor_GetPosition ( ); 
    LTorusParams tParams;  	
    Points [0].x = center_x - l_taper;
	Points [0].y = center_y - w_taper/2;
	Points [1].x = center_x - l_taper;
	Points [1].y = center_y + w_taper/2;
	Points [2].x = center_x;
	Points [2].y = center_y + taper_input_width/2;
	Points [3].x = center_x;
	Points [3].y = center_y - taper_input_width/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
     
	Points [0].x = center_x - l_taper - l_buttfacet;
	Points [0].y = center_y - w_SiO2_1/2;
	Points [1].x = center_x - l_taper - l_buttfacet;
	Points [1].y = center_y - w_SiO2_1/2 - w_Trench;
	Points [2].x = center_x ;
	Points [2].y = center_y - w_SiO2_2/2 - w_Trench;
	Points [3].x = center_x ;
	Points [3].y = center_y - w_SiO2_2/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Trench" ), Points, 4);

	Points [0].x = center_x - l_taper - l_buttfacet;
	Points [0].y = center_y + w_SiO2_1/2;
	Points [1].x = center_x - l_taper - l_buttfacet;
	Points [1].y = center_y + w_SiO2_1/2 + w_Trench;
	Points [2].x = center_x;
	Points [2].y = center_y + w_SiO2_2/2 + w_Trench;
	Points [3].x = center_x;
	Points [3].y = center_y + w_SiO2_2/2;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Trench" ), Points, 4);
	}

right_ssc(
	LFile file,
	LCell cell,
	double scalefactor,
	double center_x,
	double center_y,
	double taper_input_width	
		)
	{
    //ssc参数
    double w_taper,l_taper,w_SiO2_1,w_SiO2_2,w_Trench,l_buttfacet,ssc_total_length;//SSC的尺寸
    ssc_total_length=320*scalefactor;
    w_taper = 0.18 * scalefactor;//taper尖端宽度
    w_SiO2_1 = 6 * scalefactor;//SiO2波导的前端宽度
    w_SiO2_2 = 4 * scalefactor;//SiO2波导的后端宽度
    w_Trench = 10 * scalefactor;//SiO2波导两边沟槽的宽度
    l_buttfacet = 1* scalefactor;//Si波导的尖端到端面的距离
    l_taper = ssc_total_length-l_buttfacet;//taper长度
	LPoint       Points [ 1002 ];
    LObject      Torus1;
    //LCell        Cell_Draw   = LCell_GetVisible( );
    //LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
     LFile        File_Draw   = file;
    LPoint       Translation = LCursor_GetPosition ( ); 
    LTorusParams tParams;  
	
	double taper_x, taper_y;
    taper_x = center_x;
    taper_y = center_y;

    Points [0].x = taper_x;
	Points [0].y = taper_y - taper_input_width/2;
	Points [1].x = taper_x;
	Points [1].y = taper_y + taper_input_width/2;
	Points [2].x = taper_x + l_taper;
	Points [2].y = taper_y + w_taper/2;
	Points [3].x = taper_x + l_taper;
	Points [3].y = taper_y - w_taper/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4); //右taper

    Points [0].x = taper_x;
	Points [0].y = taper_y - w_SiO2_2/2;
	Points [1].x = taper_x;
	Points [1].y = taper_y - w_SiO2_2/2 - 10 * scalefactor;
	Points [2].x = taper_x + l_taper + l_buttfacet;
	Points [2].y = taper_y - w_SiO2_1/2 - 10 * scalefactor;
	Points [3].x = taper_x + l_taper + l_buttfacet;
	Points [3].y = taper_y - w_SiO2_1/2;

	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Trench" ), Points, 4); //右taper

	Points [0].x = taper_x ;
	Points [0].y = taper_y + w_SiO2_2/2;
	Points [1].x = taper_x;
	Points [1].y = taper_y + w_SiO2_2/2 + 10 * scalefactor;
	Points [2].x = taper_x + l_taper + l_buttfacet;
	Points [2].y = taper_y + w_SiO2_1/2 + 10 * scalefactor;
	Points [3].x = taper_x + l_taper + l_buttfacet;
	Points [3].y = taper_y + w_SiO2_1/2;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Trench" ), Points, 4); //右taper
	}




//void  switch_macro_register (void)
//	{
//		LMacro_Register("switch", "main");
//	}
//}

/* End of Module */
//switch_macro_register();