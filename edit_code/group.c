// author : LuZequan
// 测试一下使用#include“.c”的效果
// 将1-4个器件组成一个cell
// 完成1——4 的例化  //(1) cascade1X2 mmi
					//(2) dc
					//(3) EDG
					//(4) cross

//
//module test_c_code
//{

	#include <stdlib.h>
	#include <math.h>
	#include "ldata.h"
	#include "cascade-mmi-edit.c" //引用外部的cascade-mmi-edit.c文件
	#include "dc_edit.c"
	#include "EDG_edit.c";
	#include "cross_edit.c"
	
	void group_edit (LFile group_file, LCell group_cell)
	//void main ()
{
	double factor = 1000;	//因子参数
	
	double mmi_width = 100;
	double dc_width = 70;
	double edg_width = 220;
	double cross_width = 50;
	double width = mmi_width + dc_width + edg_width + cross_width;
	double group_width = -width*9/2 + width;
	
	LPoint mmi_trans,mmi_repeat_cnt,mmi_delta, 
		   dc_trans,dc_repeat_cnt,dc_delta, 
		   edg_trans,edg_repeat_cnt,edg_delta, 
		   cross_trans,cross_repeat_cnt,cross_delta; 
		   // 移动的位置, 组成的阵的形式, 阵的间距 ;
		   	
	mmi_trans.x = 0*factor;
	//mmi_trans.y = group_width*factor-(mmi_width/2)*factor; //mmi 竖直位置
	mmi_trans.y = (-width/2+mmi_width/2)*factor; //mmi 竖直位置
	mmi_repeat_cnt.x = 1;
	mmi_repeat_cnt.y = 1;
	mmi_delta.x = 0;
	mmi_delta.y = 0;

	dc_trans.x = 0*factor;
	//dc_trans.y = group_width*factor-(mmi_width+dc_width/2)*factor;//-15*factor; //dc 竖直位置 //需要将零点调整到器件的中心
	dc_trans.y = (-width/2+mmi_width+dc_width/2)*factor;//-15*factor; //dc 竖直位置 //需要将零点调整到器件的中心
	dc_repeat_cnt.x = 1;
	dc_repeat_cnt.y = 1;
	dc_delta.x = 0;
	dc_delta.y = 0;		
	
	edg_trans.x = 0*factor;
	//edg_trans.y = group_width*factor-(mmi_width+dc_width+edg_width/2)*factor;//-5*factor;	 //edg 竖直位置
	edg_trans.y = (-width/2+mmi_width+dc_width+edg_width/2)*factor;//-5*factor;	 //edg 竖直位置
	edg_repeat_cnt.x = 1;
	edg_repeat_cnt.y = 1;
	edg_delta.x = 0;
	edg_delta.y = 0;
	
	cross_trans.x = 0*factor;
	//cross_trans.y = group_width*factor-(mmi_width+dc_width+edg_width+cross_width/2)*factor;	//cross 竖直位置
	cross_trans.y = (-width/2+mmi_width+dc_width+edg_width+cross_width/2)*factor;	//cross 竖直位置
	cross_repeat_cnt.x = 1;
	cross_repeat_cnt.y = 1;
	cross_delta.x = 0;
	cross_delta.y = 0;	 
	
	
	LMagnification mmi_mag; // mmi放大的倍数
	mmi_mag.num = 1;  // 分子
	mmi_mag.denom = 1; // 分母
	LTransform_Ex99 mmi_transform;	//例化体移动和旋转
	mmi_transform.translation = mmi_trans; //例化体移动位置
	mmi_transform.orientation = LRotate0; // 例化体旋转方式
	mmi_transform.magnification = mmi_mag;  // 例化体放大倍数
	
	LMagnification dc_mag; // dc放大的倍数
	dc_mag.num = 1;  // 分子
	dc_mag.denom = 1; // 分母
	LTransform_Ex99 dc_transform;	//例化体移动和旋转
	dc_transform.translation = dc_trans; //例化体移动位置
	dc_transform.orientation = LRotate0; // 例化体旋转方式
	dc_transform.magnification = dc_mag;  // 例化体放大倍数
	
	LMagnification edg_mag; // edg放大的倍数
	edg_mag.num = 1;  // 分子
	edg_mag.denom = 1; // 分母
	LTransform_Ex99 edg_transform;	//例化体移动和旋转
	edg_transform.translation = edg_trans; //例化体移动位置
	edg_transform.orientation = LRotate0; // 例化体旋转方式
	edg_transform.magnification = edg_mag;  // 例化体放大倍数
	
	LMagnification cross_mag; // cross放大的倍数
	cross_mag.num = 1;  // 分子
	cross_mag.denom = 1; // 分母
	LTransform_Ex99 cross_transform;	//例化体移动和旋转
	cross_transform.translation = cross_trans; //例化体移动位置
	cross_transform.orientation = LRotate0; // 例化体旋转方式
	cross_transform.magnification = cross_mag;  // 例化体放大倍数
	
	//LFile group_file = LFile_GetVisible(); // 默认的当前打开的文件
	//LFile_SetAuthor( group_file, "LuZequan" );
	
	if( Assigned(group_file ) )
	{

		LCell cascade_mmi_cell = LCell_New( group_file, "cascade_mmi_cell" ); // 新建cascade_mmi_cell
			if ( cascade_mmi_cell )
			{
				cascade_mmi(group_file, cascade_mmi_cell);// 注意将file和cell传递给绘制函数
			}
		LCell dc_edit_cell = LCell_New( group_file, "dc_edit_cell" ); // 新建dc_cell
			if ( dc_edit_cell )
			{
				dc_edit(group_file, dc_edit_cell);// 注意将file和cell传递给绘制函数
			}
		LCell edg_edit_cell = LCell_New( group_file, "edg_edit_cell" ); // 新建dc_cell
			if ( edg_edit_cell )
			{
				edg_edit(group_file, edg_edit_cell);// 注意将file和cell传递给绘制函数
			}
		LCell cross_edit_cell = LCell_New( group_file, "cross_edit_cell" ); // 新建dc_cell
			if ( cross_edit_cell )
			{
				cross_edit(group_file, cross_edit_cell);// 注意将file和cell传递给绘制函数
			}
		//LCell group_cell = LCell_New(group_file,"group_cell_cell"); // 创建1_4 cell
			if( group_cell )
			{
				LInstance_New_Ex99( group_cell, cascade_mmi_cell, mmi_transform, mmi_repeat_cnt, mmi_delta);  //(1) cascade1X2 mmi
				LInstance_New_Ex99( group_cell, dc_edit_cell, dc_transform, dc_repeat_cnt, dc_delta); 			//(2) dc
				LInstance_New_Ex99( group_cell, edg_edit_cell, edg_transform, edg_repeat_cnt, edg_delta);  //(3) EDG
				LInstance_New_Ex99( group_cell, cross_edit_cell, cross_transform, cross_repeat_cnt, cross_delta);	//(4) cross
			}	
		/*LCell PIC_cell = LCell_New(group_file,"PIC_cell"); // 创建PIC cell
			if( PIC_cell )
			{
				LInstance_New_Ex99( PIC_cell, cascade_mmi_cell, mmi_transform, mmi_repeat_cnt, mmi_delta);
			}
		*/	
		
	}
}
/*
		void test_c_code_register(void)
{
	LMacro_Register("test_c_code_register","main");
}

}
	
	test_c_code_register();	
	*/