// // 寻找double_pd_pic的cell，一起组成具有光栅的PD整体组件
// 寻找double_pd_pic的cell，一起组成具有光栅的PD整体组件

#include <stdlib.h>
#include <math.h>
#include "ldata.h"

double double_PD_width;
double psgc_gr_length;
void double_pd_pic_psgc(LFile file,LCell cell, LCell psgc_gr_cell)
{
	double factor = 1000;	//因子参数
	double_PD_width = 616.05;
	psgc_gr_length = 336.309;
	LPoint  psgc_gr_trans, psgc_gr_repeat_cnt, psgc_gr_delta,
			psgc_gr_r_trans, psgc_gr_r_repeat_cnt, psgc_gr_r_delta,
			double_pd_pic_trans, double_pd_pic_repeat_cnt, double_pd_pic_delta;
	
	
	// 设置psgc_gr的组件的位置个数等属性
	psgc_gr_trans.x = psgc_gr_length*factor;
	psgc_gr_trans.y = -double_PD_width/2*factor;
	psgc_gr_repeat_cnt.x = 1;
	psgc_gr_repeat_cnt.y = 1; // psgc_gr 制作1
	psgc_gr_delta.x = 0*factor;
	psgc_gr_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification psgc_gr_mag; // 放大的倍数
	psgc_gr_mag.num = 1;  // 分子
	psgc_gr_mag.denom = 1; // 分母
	LTransform_Ex99 psgc_gr_transform;	//例化体移动和旋转
	psgc_gr_transform.translation = psgc_gr_trans; //例化体移动位置
	psgc_gr_transform.orientation = LRotate0MirrorX; // 例化体旋转方式
	psgc_gr_transform.magnification = psgc_gr_mag;  // 例化体放大倍数
	
	
	// 设置double_pd_pic的组件的位置个数等属性
	double_pd_pic_trans.x = 0*factor;
	double_pd_pic_trans.y = 0*factor;
	double_pd_pic_repeat_cnt.x = 1;
	double_pd_pic_repeat_cnt.y = 1; // double_pd_pic 制作1
	double_pd_pic_delta.x = 0*factor;
	double_pd_pic_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification double_pd_pic_mag; // 放大的倍数
	double_pd_pic_mag.num = 1;  // 分子
	double_pd_pic_mag.denom = 1; // 分母
	LTransform_Ex99 double_pd_pic_transform;	//例化体移动和旋转
	double_pd_pic_transform.translation = double_pd_pic_trans; //例化体移动位置
	double_pd_pic_transform.orientation = LRotate0; // 例化体旋转方式
	double_pd_pic_transform.magnification = double_pd_pic_mag;  // 例化体放大倍数
	
	LCell double_pd_pic_gr_ell = LCell_Find( file, "double_pd_pic_W5L8_02" );
	if ( double_pd_pic_gr_ell )
	{
		LDialog_AlertBox( "Double PD Cell found ！！" );
		LInstance_New_Ex99( cell, psgc_gr_cell, psgc_gr_transform, psgc_gr_repeat_cnt, psgc_gr_delta);
		LInstance_New_Ex99( cell, double_pd_pic_gr_ell, double_pd_pic_transform, double_pd_pic_repeat_cnt, double_pd_pic_delta);
	}
	else 
	{
		LDialog_AlertBox( "double PD Cell can not found ！！" );
	}
}