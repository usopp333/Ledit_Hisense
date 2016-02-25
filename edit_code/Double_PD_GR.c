// // 寻找double_PD的cell，一起组成具有光栅的PD整体组件
// 寻找double_PD的cell，一起组成具有光栅的PD整体组件

#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void double_pd_gr(LFile file,LCell cell, LCell gr_link_cell)
{
	double factor = 1000;	//因子参数
	LPoint  gr_link_trans, gr_link_repeat_cnt, gr_link_delta,
			gr_link_r_trans, gr_link_r_repeat_cnt, gr_link_r_delta,
			double_pd_trans, double_pd_repeat_cnt, double_pd_delta;
	
	
	// 设置gr_link的组件的位置个数等属性
	gr_link_trans.x = 0*factor;
	gr_link_trans.y = 0*factor;
	gr_link_repeat_cnt.x = 1;
	gr_link_repeat_cnt.y = 1; // gr_link 制作1
	gr_link_delta.x = 0*factor;
	gr_link_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification gr_link_mag; // 放大的倍数
	gr_link_mag.num = 1;  // 分子
	gr_link_mag.denom = 1; // 分母
	LTransform_Ex99 gr_link_transform;	//例化体移动和旋转
	gr_link_transform.translation = gr_link_trans; //例化体移动位置
	gr_link_transform.orientation = LRotate0; // 例化体旋转方式
	gr_link_transform.magnification = gr_link_mag;  // 例化体放大倍数
	
	// 设置gr_link_r的组件的位置个数等属性
	gr_link_r_trans.x = 1076.05*factor; // 双PD的长度
	gr_link_r_trans.y = 0*factor;
	gr_link_r_repeat_cnt.x = 1;
	gr_link_r_repeat_cnt.y = 1; // gr_link_r 制作1
	gr_link_r_delta.x = 0*factor;
	gr_link_r_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification gr_link_r_mag; // 放大的倍数
	gr_link_r_mag.num = 1;  // 分子
	gr_link_r_mag.denom = 1; // 分母
	LTransform_Ex99 gr_link_r_transform;	//例化体移动和旋转
	gr_link_r_transform.translation = gr_link_r_trans; //例化体移动位置
	gr_link_r_transform.orientation = LRotate180; // 例化体旋转方式
	gr_link_r_transform.magnification = gr_link_r_mag;  // 例化体放大倍数
	
	// 设置double_pd的组件的位置个数等属性
	double_pd_trans.x = 0*factor;
	double_pd_trans.y = 0*factor;
	double_pd_repeat_cnt.x = 1;
	double_pd_repeat_cnt.y = 1; // double_pd 制作1
	double_pd_delta.x = 0*factor;
	double_pd_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification double_pd_mag; // 放大的倍数
	double_pd_mag.num = 1;  // 分子
	double_pd_mag.denom = 1; // 分母
	LTransform_Ex99 double_pd_transform;	//例化体移动和旋转
	double_pd_transform.translation = double_pd_trans; //例化体移动位置
	double_pd_transform.orientation = LRotate0; // 例化体旋转方式
	double_pd_transform.magnification = double_pd_mag;  // 例化体放大倍数
	
	LCell double_pd_gr_ell = LCell_Find( file, "double_PD_W5L8_02" );
	if ( double_pd_gr_ell )
	{
		LDialog_AlertBox( "Double PD Cell found ！！" );
		LInstance_New_Ex99( cell, gr_link_cell, gr_link_transform, gr_link_repeat_cnt, gr_link_delta);
		LInstance_New_Ex99( cell, double_pd_gr_ell, double_pd_transform, double_pd_repeat_cnt, double_pd_delta);
		LInstance_New_Ex99( cell, gr_link_cell, gr_link_r_transform, gr_link_r_repeat_cnt, gr_link_r_delta);
	}
	else 
	{
		LDialog_AlertBox( "double PD Cell can not found ！！" );
	}
}