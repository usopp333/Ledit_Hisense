// Author：LuZequan
// 日期 ： 2016-02-17
// 将自己设计的模型整理成为Ledit的版图
// mmi模型
module lu_cross_layout
{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"
double factor, pi;
double x_0, y_0;
double wg_l, wg_w, core_l, theta, a, b;
int cross_length;
double up_link;
double lu_cross_gr_width,lu_cross_gr_gl;
double x_lu_cross[] = {-1.857753,-1.849236,-1.840718,-1.832201,-1.823684,-1.815167,-1.806649,-1.798132,-1.789615,-1.781098,-1.772580,-1.764063,-1.755546,-1.747029,-1.738511,-1.729994,-1.721477,-1.712960,-1.704442,-1.695925,-1.687408,-1.678891,-1.670373,-1.661856,-1.653339,-1.644822,-1.636304,-1.627787,-1.619270,-1.610753,-1.602235,-1.593718,-1.585201,-1.576684,-1.568166,-1.559649,-1.551132,-1.542615,-1.534097,-1.525580,-1.517063,-1.508546,-1.500028,-1.491511,-1.482994,-1.474477,-1.465959,-1.457442,-1.448925,-1.440408,-1.431890,-1.423373,-1.414856,-1.406339,-1.397821,-1.389304,-1.380787,-1.372270,-1.363752,-1.355235,-1.346718,-1.338201,-1.329683,-1.321166,-1.312649,-1.304132,-1.295614,-1.287097,-1.278580,-1.270063,-1.261545,-1.253028,-1.244511,-1.235994,-1.227476,-1.218959,-1.210442,-1.201925,-1.193407,-1.184890,-1.176373,-1.167856,-1.159338,-1.150821,-1.142304,-1.133787,-1.125269,-1.116752,-1.108235,-1.099718,-1.091200,-1.082683,-1.074166,-1.065649,-1.057131,-1.048614,-1.040097,-1.031580,-1.023062,-1.014545,-1.014545,-1.023062,-1.031580,-1.040097,-1.048614,-1.057131,-1.065649,-1.074166,-1.082683,-1.091200,-1.099718,-1.108235,-1.116752,-1.125269,-1.133787,-1.142304,-1.150821,-1.159338,-1.167856,-1.176373,-1.184890,-1.193407,-1.201925,-1.210442,-1.218959,-1.227476,-1.235994,-1.244511,-1.253028,-1.261545,-1.270063,-1.278580,-1.287097,-1.295614,-1.304132,-1.312649,-1.321166,-1.329683,-1.338201,-1.346718,-1.355235,-1.363752,-1.372270,-1.380787,-1.389304,-1.397821,-1.406339,-1.414856,-1.423373,-1.431890,-1.440408,-1.448925,-1.457442,-1.465959,-1.474477,-1.482994,-1.491511,-1.500028,-1.508546,-1.517063,-1.525580,-1.534097,-1.542615,-1.551132,-1.559649,-1.568166,-1.576684,-1.585201,-1.593718,-1.602235,-1.610753,-1.619270,-1.627787,-1.636304,-1.644822,-1.653339,-1.661856,-1.670373,-1.678891,-1.687408,-1.695925,-1.704442,-1.712960,-1.721477,-1.729994,-1.738511,-1.747029,-1.755546,-1.764063,-1.772580,-1.781098,-1.789615,-1.798132,-1.806649,-1.815167,-1.823684,-1.832201,-1.840718,-1.849236,-1.857753};
double y_lu_cross[] = {0.250000,0.259839,0.269420,0.278746,0.287819,0.296643,0.305222,0.313558,0.321655,0.329518,0.337150,0.344555,0.351737,0.358701,0.365451,0.371991,0.378326,0.384460,0.390398,0.396144,0.401702,0.407078,0.412275,0.417299,0.422152,0.426841,0.431369,0.435740,0.439959,0.444030,0.447957,0.451745,0.455396,0.458916,0.462307,0.465574,0.468720,0.471749,0.474664,0.477469,0.480166,0.482760,0.485253,0.487648,0.489948,0.492156,0.494274,0.496305,0.498251,0.500115,0.501899,0.503605,0.505235,0.506791,0.508275,0.509688,0.511032,0.512309,0.513520,0.514666,0.515748,0.516768,0.517726,0.518624,0.519462,0.520240,0.520960,0.521622,0.522226,0.522773,0.523263,0.523696,0.524072,0.524392,0.524654,0.524859,0.525007,0.525097,0.525129,0.525103,0.525017,0.524872,0.524667,0.524400,0.524072,0.523681,0.523227,0.522708,0.522124,0.521473,0.520755,0.519968,0.519111,0.518183,0.517182,0.516108,0.514960,0.513734,0.512432,0.511050,-0.511050,-0.512432,-0.513734,-0.514960,-0.516108,-0.517182,-0.518183,-0.519111,-0.519968,-0.520755,-0.521473,-0.522124,-0.522708,-0.523227,-0.523681,-0.524072,-0.524400,-0.524667,-0.524872,-0.525017,-0.525103,-0.525129,-0.525097,-0.525007,-0.524859,-0.524654,-0.524392,-0.524072,-0.523696,-0.523263,-0.522773,-0.522226,-0.521622,-0.520960,-0.520240,-0.519462,-0.518624,-0.517726,-0.516768,-0.515748,-0.514666,-0.513520,-0.512309,-0.511032,-0.509688,-0.508275,-0.506791,-0.505235,-0.503605,-0.501899,-0.500115,-0.498251,-0.496305,-0.494274,-0.492156,-0.489948,-0.487648,-0.485253,-0.482760,-0.480166,-0.477469,-0.474664,-0.471749,-0.468720,-0.465574,-0.462307,-0.458916,-0.455396,-0.451745,-0.447957,-0.444030,-0.439959,-0.435740,-0.431369,-0.426841,-0.422152,-0.417299,-0.412275,-0.407078,-0.401702,-0.396144,-0.390398,-0.384460,-0.378326,-0.371991,-0.365451,-0.358701,-0.351737,-0.344555,-0.337150,-0.329518,-0.321655,-0.313558,-0.305222,-0.296643,-0.287819,-0.278746,-0.269420,-0.259839,-0.250000};
void main()
{
	
	
	factor = 1000;
	pi = 3.1415926;
	wg_l = 2 *factor;
	wg_w = 0.50*factor;
	core_l = 2.02909*factor;
	theta = 90;
	x_0 = 0;
	y_0 = 0;
	a = 0.843208*factor;
	b = 1.0221*factor;
	up_link = 10*factor;
	cross_length = sizeof(x_lu_cross)/sizeof(x_lu_cross[0]);
	LFile  			lu_cross_file = LFile_GetVisible(); // 默认的当前打开的文件
	LFile_SetAuthor( lu_cross_file, "LuZequan" );
	LCell			lu_cross =  LCell_New( lu_cross_file, "lu_cross");
	LCell 			lu_cross_taper_f = LCell_New(lu_cross_file,"lu_cross_taper_f");
	LPoint 			lu_cross0_trans,lu_cross0_repeat_cnt,lu_cross0_delta,
					lu_cross1_trans,lu_cross1_repeat_cnt,lu_cross1_delta,
					lu_cross2_trans,lu_cross2_repeat_cnt,lu_cross2_delta,
					lu_cross3_trans,lu_cross3_repeat_cnt,lu_cross3_delta;
	lu_cross_taper(lu_cross_file,lu_cross_taper_f,x_0,y_0);
	
	lu_cross0_trans.x = x_0;
	lu_cross0_trans.y = y_0;
	lu_cross0_repeat_cnt.x = 1;
	lu_cross0_repeat_cnt.y = 1;  
	lu_cross0_delta.x = 0*factor;
	lu_cross0_delta.y = 0*factor;		
	
	LMagnification lu_cross0_mag; // lu_cross1放大的倍数
	lu_cross0_mag.num = 1;  // 分子
	lu_cross0_mag.denom = 1; // 分母
	LTransform_Ex99 lu_cross0_transform;	//例化体移动和旋转
	lu_cross0_transform.translation = lu_cross0_trans; //例化体移动位置
	lu_cross0_transform.orientation = LRotate0; // 例化体旋转方式
	lu_cross0_transform.magnification = lu_cross0_mag;  // 例化体放大倍数
	LInstance_New_Ex99( lu_cross, lu_cross_taper_f, lu_cross0_transform, lu_cross0_repeat_cnt, lu_cross0_delta); //1_4 组件放置
	
	lu_cross1_trans.x = x_0;
	lu_cross1_trans.y = y_0;
	lu_cross1_repeat_cnt.x = 1;
	lu_cross1_repeat_cnt.y = 1;  
	lu_cross1_delta.x = 0*factor;
	lu_cross1_delta.y = 0*factor;		
	
	LMagnification lu_cross1_mag; // lu_cross1放大的倍数
	lu_cross1_mag.num = 1;  // 分子
	lu_cross1_mag.denom = 1; // 分母
	LTransform_Ex99 lu_cross1_transform;	//例化体移动和旋转
	lu_cross1_transform.translation = lu_cross1_trans; //例化体移动位置
	lu_cross1_transform.orientation = LRotate90; // 例化体旋转方式
	lu_cross1_transform.magnification = lu_cross1_mag;  // 例化体放大倍数
	LInstance_New_Ex99( lu_cross, lu_cross_taper_f, lu_cross1_transform, lu_cross1_repeat_cnt, lu_cross1_delta); //1_4 组件放置
	
	lu_cross2_trans.x = x_0;
	lu_cross2_trans.y = y_0;
	lu_cross2_repeat_cnt.x = 1;
	lu_cross2_repeat_cnt.y = 1;  
	lu_cross2_delta.x = 0*factor;
	lu_cross2_delta.y = 0*factor;		
	
	LMagnification lu_cross2_mag; // lu_cross1放大的倍数
	lu_cross2_mag.num = 1;  // 分子
	lu_cross2_mag.denom = 1; // 分母
	LTransform_Ex99 lu_cross2_transform;	//例化体移动和旋转
	lu_cross2_transform.translation = lu_cross2_trans; //例化体移动位置
	lu_cross2_transform.orientation = LRotate180; // 例化体旋转方式
	lu_cross2_transform.magnification = lu_cross2_mag;  // 例化体放大倍数
	LInstance_New_Ex99( lu_cross, lu_cross_taper_f, lu_cross2_transform, lu_cross2_repeat_cnt, lu_cross2_delta); //1_4 组件放置
	
	lu_cross3_trans.x = x_0;
	lu_cross3_trans.y = y_0;
	lu_cross3_repeat_cnt.x = 1;
	lu_cross3_repeat_cnt.y = 1;  
	lu_cross3_delta.x = 0*factor;
	lu_cross3_delta.y = 0*factor;		
	
	LMagnification lu_cross3_mag; // lu_cross1放大的倍数
	lu_cross3_mag.num = 1;  // 分子
	lu_cross3_mag.denom = 1; // 分母
	LTransform_Ex99 lu_cross3_transform;	//例化体移动和旋转
	lu_cross3_transform.translation = lu_cross3_trans; //例化体移动位置
	lu_cross3_transform.orientation = LRotate270; // 例化体旋转方式
	lu_cross3_transform.magnification = lu_cross3_mag;  // 例化体放大倍数
	LInstance_New_Ex99( lu_cross, lu_cross_taper_f, lu_cross3_transform, lu_cross3_repeat_cnt, lu_cross3_delta); //1_4 组件放置
	
	Lu_cross_core(lu_cross_file,lu_cross,x_0,y_0);
	Lu_cross_line(lu_cross_file,lu_cross,x_0,y_0);
	

}
void lu_cross_taper(LFile file, LCell cell, double x0,double y0)
{
	LObject 		cross_taper;
	LPoint			cross_taper_point[cross_length];
	int i ;
	for (i=0; i<cross_length; i++)
	{
		cross_taper_point[i].x = factor*x_lu_cross[i];
		cross_taper_point[i].y = factor*y_lu_cross[i];
	}
	cross_taper = LPolygon_New(cell, LLayer_Find(file,"Rib130"),cross_taper_point,cross_length);
}
void Lu_cross_core(LFile file, LCell cell, double x0, double y0)
{
	LObject  		cross_core;
	cross_core = LBox_New(cell,LLayer_Find(file, "Rib130"),-core_l/2,-b/2,core_l/2,b/2);
	cross_core = LBox_New(cell,LLayer_Find(file, "Rib130"),-b/2,-core_l/2,b/2,core_l/2);
}
void Lu_cross_line(LFile file, LCell cell, double x0, double y0)
{
	LObject  		cross_line;
	LPoint  		up_link_point[3];
	cross_line = LBox_New(cell,LLayer_Find(file, "Rib130"),x0+-wg_l/2-a-core_l/2-wg_l/2,y0+-wg_w/2,x0+-wg_l/2-a-core_l/2+wg_l/2,y0+wg_w/2);
	cross_line = LBox_New(cell,LLayer_Find(file, "Rib130"),x0+wg_l/2+a+core_l/2-wg_l/2,y0+-wg_w/2,x0+wg_l/2+a+core_l/2+wg_l/2,y0+wg_w/2);
	cross_line = LBox_New(cell,LLayer_Find(file, "Rib130"),x0+-wg_w/2,y0+-wg_l/2-a-core_l/2-wg_l/2,x0+wg_w/2,y0+-wg_l/2-a-core_l/2+wg_l/2);
	//cross_line = LBox_New(cell,LLayer_Find(file, "Rib130"),x0+-wg_w/2,y0+wg_l/2+a+core_l/2-wg_l/2,x0+wg_w/2,y0+wg_l/2+a+core_l/2+wg_l/2);
	up_link_point [0].x=x0+-wg_w/2;
	up_link_point [0].y=y0+wg_l/2+a+core_l/2-wg_l/2;
	up_link_point [1].x=x0+wg_w/2;
	up_link_point [1].y=y0+wg_l/2+a+core_l/2-wg_l/2;	
	up_link_point [2].x=x0;
	up_link_point [2].y=y0+up_link;
	cross_line = LPolygon_New(cell,LLayer_Find(file,"Rib130"),up_link_point,3);
	double life_gr_x0, life_gr_y0;
	life_gr_x0 = x0+-wg_l/2-a-core_l/2-wg_l/2;
	life_gr_y0 = y0;
	//lu_cross_gr(file, cell, x0, y0,life_gr_x0,life_gr_y0);
}

	void lu_cross_layout_register(void)
{
	LMacro_Register("lu_cross_layout","main");
}

}
	
	lu_cross_layout_register();	