// Author：LuZequan
// 日期 ： 2016-02-17
// 将自己设计的模型整理成为Ledit的版图
// mmi模型
//module mmi_f_layout
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"
double factor, pi;
double wg_l, wg_w, mmi_l, gap, theta, wg_r,wg_l_out;
double z_mmi_f[200] = {0.000000,0.017541,0.035082,0.052624,0.070165,0.087706,0.105247,0.122788,0.140330,0.157871,0.175412,0.192953,0.210495,0.228036,0.245577,0.263118,0.280659,0.298201,0.315742,0.333283,0.350824,0.368365,0.385907,0.403448,0.420989,0.438530,0.456072,0.473613,0.491154,0.508695,0.526236,0.543778,0.561319,0.578860,0.596401,0.613942,0.631484,0.649025,0.666566,0.684107,0.701648,0.719190,0.736731,0.754272,0.771813,0.789355,0.806896,0.824437,0.841978,0.859519,0.877061,0.894602,0.912143,0.929684,0.947225,0.964767,0.982308,0.999849,1.017390,1.034932,1.052473,1.070014,1.087555,1.105096,1.122638,1.140179,1.157720,1.175261,1.192802,1.210344,1.227885,1.245426,1.262967,1.280508,1.298050,1.315591,1.333132,1.350673,1.368215,1.385756,1.403297,1.420838,1.438379,1.455921,1.473462,1.491003,1.508544,1.526085,1.543627,1.561168,1.578709,1.596250,1.613792,1.631333,1.648874,1.666415,1.683956,1.701498,1.719039,1.736580,1.736580,1.719039,1.701498,1.683956,1.666415,1.648874,1.631333,1.613792,1.596250,1.578709,1.561168,1.543627,1.526085,1.508544,1.491003,1.473462,1.455921,1.438379,1.420838,1.403297,1.385756,1.368215,1.350673,1.333132,1.315591,1.298050,1.280508,1.262967,1.245426,1.227885,1.210344,1.192802,1.175261,1.157720,1.140179,1.122638,1.105096,1.087555,1.070014,1.052473,1.034932,1.017390,0.999849,0.982308,0.964767,0.947225,0.929684,0.912143,0.894602,0.877061,0.859519,0.841978,0.824437,0.806896,0.789355,0.771813,0.754272,0.736731,0.719190,0.701648,0.684107,0.666566,0.649025,0.631484,0.613942,0.596401,0.578860,0.561319,0.543778,0.526236,0.508695,0.491154,0.473613,0.456072,0.438530,0.420989,0.403448,0.385907,0.368365,0.350824,0.333283,0.315742,0.298201,0.280659,0.263118,0.245577,0.228036,0.210495,0.192953,0.175412,0.157871,0.140330,0.122788,0.105247,0.087706,0.070165,0.052624,0.035082,0.017541,0.000000};
double x_mmi_f[200] = {0.205000,0.208204,0.211463,0.214779,0.218152,0.221585,0.225079,0.228636,0.232257,0.235945,0.239701,0.243528,0.247428,0.251403,0.255455,0.259589,0.263805,0.268109,0.272501,0.276986,0.281568,0.286250,0.291035,0.295929,0.300934,0.306055,0.311297,0.316665,0.322162,0.327794,0.333564,0.339479,0.345541,0.351756,0.358126,0.364656,0.371348,0.378203,0.385223,0.392406,0.399751,0.407253,0.414907,0.422704,0.430631,0.438675,0.446815,0.455031,0.463293,0.471572,0.479830,0.488026,0.496116,0.504048,0.511771,0.519227,0.526360,0.533110,0.539421,0.545238,0.550512,0.555196,0.559256,0.562663,0.565398,0.567453,0.568830,0.569543,0.569612,0.569068,0.567950,0.566300,0.564166,0.561600,0.558652,0.555373,0.551815,0.548025,0.544049,0.539927,0.535697,0.531393,0.527045,0.522678,0.518315,0.513973,0.509669,0.505414,0.501218,0.497090,0.493033,0.489052,0.485150,0.481326,0.477582,0.473916,0.470328,0.466814,0.463372,0.460000,-0.460000,-0.463372,-0.466814,-0.470328,-0.473916,-0.477582,-0.481326,-0.485150,-0.489052,-0.493033,-0.497090,-0.501218,-0.505414,-0.509669,-0.513973,-0.518315,-0.522678,-0.527045,-0.531393,-0.535697,-0.539927,-0.544049,-0.548025,-0.551815,-0.555373,-0.558652,-0.561600,-0.564166,-0.566300,-0.567950,-0.569068,-0.569612,-0.569543,-0.568830,-0.567453,-0.565398,-0.562663,-0.559256,-0.555196,-0.550512,-0.545238,-0.539421,-0.533110,-0.526360,-0.519227,-0.511771,-0.504048,-0.496116,-0.488026,-0.479830,-0.471572,-0.463293,-0.455031,-0.446815,-0.438675,-0.430631,-0.422704,-0.414907,-0.407253,-0.399751,-0.392406,-0.385223,-0.378203,-0.371348,-0.364656,-0.358126,-0.351756,-0.345541,-0.339479,-0.333564,-0.327794,-0.322162,-0.316665,-0.311297,-0.306055,-0.300934,-0.295929,-0.291035,-0.286250,-0.281568,-0.276986,-0.272501,-0.268109,-0.263805,-0.259589,-0.255455,-0.251403,-0.247428,-0.243528,-0.239701,-0.235945,-0.232257,-0.228636,-0.225079,-0.221585,-0.218152,-0.214779,-0.211463,-0.208204,-0.205000};
//void main()
void mmi_f(LFile mmi_file, LCell mmicell,LCell gr_link_line_cell)
{
	
	double x_0, y_0;
	factor = 1000;
	pi = 3.1415926;
	wg_l = 2 *factor;
	wg_l_out = 2 *factor;
	wg_w = 0.41*factor;
	mmi_l = 1.73658*factor;
	gap = 0.1*factor;
	wg_r = 20*factor;
	theta = 45;
	x_0 = -(3*wg_l+3*mmi_l+2*2*wg_r*sin(theta)+2*wg_r*sin(theta))/2;
	y_0 = 0;
	// corner的点坐标

	
	LPoint			mmi_trans,mmi_repeat_cnt,mmi_delta;
	LPoint  		mmigr1_trans,mmigr1_repeat_cnt,mmigr1_delta,
					mmigr2_trans,mmigr2_repeat_cnt,mmigr2_delta,
					mmigr3_trans,mmigr3_repeat_cnt,mmigr3_delta,
					mmigr4_trans,mmigr4_repeat_cnt,mmigr4_delta,
					mmigr5_trans,mmigr5_repeat_cnt,mmigr5_delta;
	
	//LFile  			mmi_file = LFile_GetVisible(); // 默认的当前打开的文件
	LFile_SetAuthor( mmi_file, "LuZequan" );
	//LCell			mmicell =  LCell_New( mmi_file, "mmicell");
	LPoint       	Translation = LCursor_GetPosition ( ); 
	
	
	x_0 = x_0+wg_l;
	wg_r = 2*wg_r;
	wg_l_out = 0;
	cascade_mmi_f(mmi_file,mmicell,x_0,y_0,wg_r,wg_l_out);

	mmigr1_trans.x = x_0;
	mmigr1_trans.y = y_0;
	mmigr1_repeat_cnt.x = 1;
	mmigr1_repeat_cnt.y = 1; // mmigr1 制作9组
	mmigr1_delta.x = 0*factor;
	mmigr1_delta.y = 0*factor;		
	
	LMagnification mmigr1_mag; // mmigr1放大的倍数
	mmigr1_mag.num = 1;  // 分子
	mmigr1_mag.denom = 1; // 分母
	LTransform_Ex99 mmigr1_transform;	//例化体移动和旋转
	mmigr1_transform.translation = mmigr1_trans; //例化体移动位置
	mmigr1_transform.orientation = LRotate0; // 例化体旋转方式
	mmigr1_transform.magnification = mmigr1_mag;  // 例化体放大倍数
	LInstance_New_Ex99( mmicell, gr_link_line_cell, mmigr1_transform, mmigr1_repeat_cnt, mmigr1_delta); //1_4 组件放置
	
	x_0 = x_0+wg_l+mmi_l+2*wg_r*sin(theta*pi/180)+wg_l/2-wg_l/2;
	y_0 = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r);
	wg_r = wg_r/2;
	wg_l_out = 2 *factor;
	cascade_mmi_f(mmi_file,mmicell,x_0,y_0,wg_r,wg_l_out);
	y_0 = -y_0;
	wg_l_out = 2 *factor;
	cascade_mmi_f(mmi_file,mmicell,x_0,y_0,wg_r,wg_l_out);
	
	mmigr2_trans.x = mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2+wg_l_out/2+x_0;
	mmigr2_trans.y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r)-y_0;
	mmigr2_repeat_cnt.x = 1;
	mmigr2_repeat_cnt.y = 1; // mmigr2 制作9组
	mmigr2_delta.x = 0*factor;
	mmigr2_delta.y = 0*factor;		
	
	LMagnification mmigr2_mag; // mmigr2放大的倍数
	mmigr2_mag.num = 1;  // 分子
	mmigr2_mag.denom = 1; // 分母
	LTransform_Ex99 mmigr2_transform;	//例化体移动和旋转
	mmigr2_transform.translation = mmigr2_trans; //例化体移动位置
	mmigr2_transform.orientation = LRotate180; // 例化体旋转方式
	mmigr2_transform.magnification = mmigr2_mag;  // 例化体放大倍数
	LInstance_New_Ex99( mmicell, gr_link_line_cell, mmigr2_transform, mmigr2_repeat_cnt, mmigr2_delta); //1_4 组件放置
	
	mmigr3_trans.x =  mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2+wg_l_out/2+x_0;
	mmigr3_trans.y = -mmigr2_trans.y;
	mmigr3_repeat_cnt.x = 1;
	mmigr3_repeat_cnt.y = 1; // mmigr3 制作9组
	mmigr3_delta.x = 0*factor;
	mmigr3_delta.y = 0*factor;		
	
	LMagnification mmigr3_mag; // mmigr3放大的倍数
	mmigr3_mag.num = 1;  // 分子
	mmigr3_mag.denom = 1; // 分母
	LTransform_Ex99 mmigr3_transform;	//例化体移动和旋转
	mmigr3_transform.translation = mmigr3_trans; //例化体移动位置
	mmigr3_transform.orientation = LRotate180; // 例化体旋转方式
	mmigr3_transform.magnification = mmigr3_mag;  // 例化体放大倍数
	LInstance_New_Ex99( mmicell, gr_link_line_cell, mmigr3_transform, mmigr3_repeat_cnt, mmigr3_delta); //1_4 组件放置
	

	
	mmigr4_trans.x =  mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2+wg_l_out/2+x_0;
	mmigr4_trans.y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r)+y_0;
	mmigr4_repeat_cnt.x = 1;
	mmigr4_repeat_cnt.y = 1; // mmigr4 制作9组
	mmigr4_delta.x = 0*factor;
	mmigr4_delta.y = 0*factor;		
	
	LMagnification mmigr4_mag; // mmigr4放大的倍数
	mmigr4_mag.num = 1;  // 分子
	mmigr4_mag.denom = 1; // 分母
	LTransform_Ex99 mmigr4_transform;	//例化体移动和旋转
	mmigr4_transform.translation = mmigr4_trans; //例化体移动位置
	mmigr4_transform.orientation = LRotate180; // 例化体旋转方式
	mmigr4_transform.magnification = mmigr4_mag;  // 例化体放大倍数
	LInstance_New_Ex99( mmicell, gr_link_line_cell, mmigr4_transform, mmigr4_repeat_cnt, mmigr4_delta); //1_4 组件放置
	
	mmigr5_trans.x =  mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2+wg_l_out/2+x_0;
	mmigr5_trans.y = -mmigr4_trans.y;
	mmigr5_repeat_cnt.x = 1;
	mmigr5_repeat_cnt.y = 1; // mmigr5 制作9组
	mmigr5_delta.x = 0*factor;
	mmigr5_delta.y = 0*factor;		
	
	LMagnification mmigr5_mag; // mmigr5放大的倍数
	mmigr5_mag.num = 1;  // 分子
	mmigr5_mag.denom = 1; // 分母
	LTransform_Ex99 mmigr5_transform;	//例化体移动和旋转
	mmigr5_transform.translation = mmigr5_trans; //例化体移动位置
	mmigr5_transform.orientation = LRotate180; // 例化体旋转方式
	mmigr5_transform.magnification = mmigr5_mag;  // 例化体放大倍数
	LInstance_New_Ex99( mmicell, gr_link_line_cell, mmigr5_transform, mmigr5_repeat_cnt, mmigr5_delta); //1_4 组件放置
	
}

	void cascade_mmi_f(LFile mmi_file,LCell mmicell,double x_0,double y_0,double wg_r,double wg_l_out)
	{
		LPoint 			mmi_point[200], in_wg_point[4],out_wg_point[4];
		LObject     	mmi,in_wg,arc_wg_up1,arc_wg_up2,arc_wg_down1,arc_wg_down2,out_wg;
		LTorusParams 	arc_up1,arc_up2,arc_down1,arc_down2; 
		int nz = 200;
		int n;
	for (n=0; n<nz; n++)
	{
		mmi_point[n].x = z_mmi_f[n]*factor+x_0;
		mmi_point[n].y = x_mmi_f[n]*factor+y_0;
	}
	in_wg_point[0].x = -wg_l/2-wg_l/2+x_0;
	in_wg_point[0].y = wg_w/2+y_0;
	in_wg_point[1].x = -wg_l/2+wg_l/2+x_0;
	in_wg_point[1].y = wg_w/2+y_0;
	in_wg_point[2].x = -wg_l/2+wg_l/2+x_0;
	in_wg_point[2].y = -wg_w/2+y_0;
	in_wg_point[3].x = -wg_l/2-wg_l/2+x_0;
	in_wg_point[3].y = -wg_w/2+y_0;
	
	out_wg_point[0].x = mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2-wg_l_out/2+x_0;
	out_wg_point[0].y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r)+wg_w/2+y_0;
	out_wg_point[1].x = mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2+wg_l_out/2+x_0;
	out_wg_point[1].y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r)+wg_w/2+y_0;
	out_wg_point[2].x = mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2+wg_l_out/2+x_0;
	out_wg_point[2].y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r)-wg_w/2+y_0;
	out_wg_point[3].x = mmi_l+2*wg_r*sin(theta*pi/180)+wg_l_out/2-wg_l_out/2+x_0;
	out_wg_point[3].y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r)-wg_w/2+y_0;
	
	arc_up1.ptCenter.x = mmi_l+x_0;
	arc_up1.ptCenter.y = gap/2+wg_w/2+wg_r+y_0;
	arc_up1.nInnerRadius = wg_r-wg_w/2;
	arc_up1.nOuterRadius = wg_r+wg_w/2;
	arc_up1.dStartAngle = 270;
	arc_up1.dStopAngle = 315;
	
	arc_up2.ptCenter.x = mmi_l+2*wg_r*sin(theta*pi/180)+x_0;
	arc_up2.ptCenter.y = gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+y_0;
	arc_up2.nInnerRadius = wg_r-wg_w/2;
	arc_up2.nOuterRadius = wg_r+wg_w/2;
	arc_up2.dStartAngle = 90;
	arc_up2.dStopAngle = 135;
	
	arc_down1.ptCenter.x = mmi_l+x_0;
	arc_down1.ptCenter.y = -(gap/2+wg_w/2+wg_r)+y_0;
	arc_down1.nInnerRadius = wg_r-wg_w/2;
	arc_down1.nOuterRadius = wg_r+wg_w/2;
	arc_down1.dStartAngle = 45;
	arc_down1.dStopAngle = 90;
	
	arc_down2.ptCenter.x = mmi_l+2*wg_r*sin(theta*pi/180)+x_0;
	arc_down2.ptCenter.y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180))+y_0;
	arc_down2.nInnerRadius = wg_r-wg_w/2;
	arc_down2.nOuterRadius = wg_r+wg_w/2;
	arc_down2.dStartAngle = 225;
	arc_down2.dStopAngle = 270;
	
	if( Assigned(mmi_file ) )
	{

		if(mmicell)
		{
			mmi = LPolygon_New(mmicell, LLayer_Find(mmi_file, "Rib130"),mmi_point,200);
			in_wg = LPolygon_New(mmicell, LLayer_Find(mmi_file, "Rib130"),in_wg_point,4);
			arc_wg_up1 = LTorus_CreateNew(mmicell, LLayer_Find(mmi_file, "Rib130"),&arc_up1);
			arc_wg_up2 = LTorus_CreateNew(mmicell, LLayer_Find(mmi_file, "Rib130"),&arc_up2);
			arc_wg_down1 = LTorus_CreateNew(mmicell, LLayer_Find(mmi_file, "Rib130"),&arc_down1);
			arc_wg_down2 = LTorus_CreateNew(mmicell, LLayer_Find(mmi_file, "Rib130"),&arc_down2);
			out_wg = LPolygon_New(mmicell, LLayer_Find(mmi_file, "Rib130"),out_wg_point,4);
			
			out_wg_point[0].y = -out_wg_point[0].y;
			out_wg_point[1].y = -out_wg_point[1].y;
			out_wg_point[2].y = -out_wg_point[2].y;
			out_wg_point[3].y = -out_wg_point[3].y;
			out_wg = LPolygon_New(mmicell, LLayer_Find(mmi_file, "Rib130"),out_wg_point,4);
		}
		
	}
}

	/*void mmi_f_layout_register(void)
{
	LMacro_Register("mmi_f_layout","main");
}

}*/
	
	//mmi_f_layout_register();	