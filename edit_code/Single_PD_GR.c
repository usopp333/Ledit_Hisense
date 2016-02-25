// 寻找single_PD的cell，一起组成具有光栅的PD整体组件

#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void single_pd_gr(LFile file,LCell cell, LCell gr_link_cell)
{
	double factor = 1000;	//因子参数
	LPoint  gr_link_trans, gr_link_repeat_cnt, gr_link_delta,
			single_pd_trans, single_pd_repeat_cnt, single_pd_delta;
	
	
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
	
	// 设置single_pd的组件的位置个数等属性
	single_pd_trans.x = 0*factor;
	single_pd_trans.y = 0*factor;
	single_pd_repeat_cnt.x = 1;
	single_pd_repeat_cnt.y = 1; // single_pd 制作1
	single_pd_delta.x = 0*factor;
	single_pd_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification single_pd_mag; // 放大的倍数
	single_pd_mag.num = 1;  // 分子
	single_pd_mag.denom = 1; // 分母
	LTransform_Ex99 single_pd_transform;	//例化体移动和旋转
	single_pd_transform.translation = single_pd_trans; //例化体移动位置
	single_pd_transform.orientation = LRotate0; // 例化体旋转方式
	single_pd_transform.magnification = single_pd_mag;  // 例化体放大倍数
	
	LCell single_pd_gr_ell = LCell_Find( file, "single PD_W4L5_01" );
	if ( single_pd_gr_ell )
	{
		LDialog_AlertBox( "single PD Cell found ！！" );
		LInstance_New_Ex99( cell, gr_link_cell, gr_link_transform, gr_link_repeat_cnt, gr_link_delta);
		LInstance_New_Ex99( cell, single_pd_gr_ell, single_pd_transform, single_pd_repeat_cnt, single_pd_delta);
	}
	else 
	{
		LDialog_AlertBox( "single PD Cell can not found ！！" );
	}
}