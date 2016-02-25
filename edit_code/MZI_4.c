//2014/1/20
//edit by sun
//for mmi and mzi
//MMI相对自己原点的四个输出坐标是（200，1500），（200，500），（200，-500），（200，-1500）
//调制器的原点就是输入波导的始端。
	#include <stdlib.h>
	#include <math.h>
	#include "ldata.h"
	#include "PIC_mmi.c" //引用外部的cascade-mmi-edit.c文件
	#include "PIC_MOD.c"	
	void pic_mzi (LFile file, LCell pic_cell)
{
	double factor = 1000;	//因子参数
	double x0,y0;
	x0=-(4800/2-450);
	y0=0;
	LPoint mmi_trans,mmi_repeat_cnt, mmi_delta;  // trans:移动的位置； repeat_cnt：组成的阵； delta：阵的间距
	LPoint mod_trans,mod_repeat_cnt, mod_delta;
/**********************************************************/
/*mmi*/
/**********************************************************/

	mmi_trans.x = 0*factor;
	mmi_trans.y = 0*factor;
	mmi_repeat_cnt.x = 1;
	mmi_repeat_cnt.y = 1;
	mmi_delta.x = 0;
	mmi_delta.y = 0*factor;

	LMagnification mmi_mag; // mmi放大的倍数
	mmi_mag.num = 1;  // 分子
	mmi_mag.denom = 1; // 分母
	LTransform_Ex99 mmi_transform;	//例化体移动和旋转
	mmi_transform.translation = mmi_trans; //例化体移动位置
	mmi_transform.orientation = LRotate0; // 例化体旋转方式
	mmi_transform.magnification = mmi_mag;  // 例化体放大倍数
/**********************************************************/
/*mod*/
/**********************************************************/
	mod_trans.x = 200*factor;
	mod_trans.y = 1500*factor;
	mod_repeat_cnt.x = 1;
	mod_repeat_cnt.y = 4;
	mod_delta.x = 0;
	mod_delta.y = -1000*factor;
	
	
	LMagnification mod_mag; // mmi放大的倍数
	mod_mag.num = 1;  // 分子
	mod_mag.denom = 1; // 分母
	LTransform_Ex99 mod_transform;	//例化体移动和旋转
	mod_transform.translation = mod_trans; //例化体移动位置
	mod_transform.orientation = LRotate0; // 例化体旋转方式
	mod_transform.magnification = mod_mag;  // 例化体放大倍数

	/*例化*/
	if( Assigned(file ) )
	{
		LCell PIC_MOD_cell = LCell_New( file, "PIC_MOD_cell");
		if(PIC_MOD_cell)
		{
			PIC_MOD(file,PIC_MOD_cell,x0,y0);
		}
		
		LCell PIC_mmi_cell = LCell_New( file, "PIC_mmi_cell" ); // 新建PIC_mmi
		if ( PIC_mmi_cell )
		{
			PIC_mmi(file, PIC_mmi_cell, x0,y0);// 注意将file和cell传递给绘制函数
		}

		//LCell PIC_cell=LCell_New(file,"PIC_cell");
		if(pic_cell)
		{
			LInstance_New_Ex99( pic_cell, PIC_mmi_cell, mmi_transform, mmi_repeat_cnt, mmi_delta);
			LInstance_New_Ex99( pic_cell, PIC_MOD_cell,mod_transform,mod_repeat_cnt,mod_delta);
		}

		//PIC_mmi(file, cell,x0,y0);// 注意将file和cell传递给绘制函数
	}
}


	