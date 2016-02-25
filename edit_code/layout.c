// author : LuZequan
// 测试一下使用#include“.c”的效果
// 2016-01-18 引用一个.c完成一个wg_cell，再将这个wg_cell作为例化体，在total_cell中引用出；
// 2016-01-18 引用一个cascade——mmi ，现将一个mmi例化到一个pic_mzi——cell中，组合好pic_mzi后，再将pic_mzi例化到total_cell 中；
module Hisense_layout
{
	#include <stdlib.h>
	#include <math.h>
	#include "ldata.h"
	#include "group.c"
	#include "SSC_edit.c"
	#include "PSR1310_SSC_edit.c"
	#include "MOD_1310nm_edit.c"
	//#include "MOD_1310nm_edit_lu.c"
	#include "GR1310_edit.c"
	#include "PSGC_edit.c"
	#include "MZI_4.c"
	#include "Grating_link.c"
	#include "Single_PD_GR.c"
	#include "Double_PD_GR.c"
	#include "PSGC_GR.c"
	#include "Double_PD_PSGC.c"
	#include "grating_link_line.c"
	#include "F:\\work\\task\\task5_GDS\\Hisense\\project\\Lu_projects\\mmi_f.c"
	void main (void)
{
	double factor = 1000;	//因子参数
	
	LPoint  group_trans,group_repeat_cnt,group_delta,
			ssc_trans,ssc_repeat_cnt,ssc_delta,
	        psr_trans,psr_repeat_cnt,psr_delta,
			mod_trans,mod_repeat_cnt,mod_delta,
			gr_trans,gr_repeat_cnt,gr_delta,
			psgc_trans,psgc_repeat_cnt,psgc_delta,
			pic_mzi_trans,pic_mzi_repeat_cnt,pic_mzi_delta,
			pic_in_trans,pic_in_repeat_cnt,pic_in_delta,
			single_pd_trans,single_pd_repeat_cnt,single_pd_delta,
			double_pd_trans,double_pd_repeat_cnt,double_pd_delta,
			pic_pd_trans,pic_pd_repeat_cnt,pic_pd_delta,
			double_pd_psgc_trans,double_pd_psgc_repeat_cnt,double_pd_psgc_delta,
			pic_pd_psgc_trans,pic_pd_psgc_repeat_cnt,pic_pd_psgc_delta;
			
    //流片的轮廓
	LCoord width = 100*factor;				
			
		   // 移动的位置； 组成的阵；阵的间距
		   
	double PIC_length, PTC_width, MZI_length, MZI_width, group_length, group_width, MOD_length, MOD_width, GR_length, 
			GR_width, PSGC_length, PSGC_width, single_pd_length, single_pd_width, double_pd_length, double_pd_width;
	MZI_length = 4800;
	MZI_width = 3850;
	PIC_length = MZI_length;
	GR_length = 1850;
	GR_width = 50;
	PSGC_length = 680;
	PSGC_width = 500;
	group_length = 1000;
	group_width = 440;
	single_pd_length = 1270;
	single_pd_width = 350;
	double_pd_length = 1000;
	double_pd_width = 640;
	
	
	// 设置1-4group的组件的位置个数等属性
	//group_trans.x = (11180+130*2)*factor;
	group_trans.x = (MZI_length*2+group_width/2)*factor+width;
	group_trans.y = -(MZI_length+group_length/2+10)*factor-width;
	group_repeat_cnt.x = 1;
	group_repeat_cnt.y = 9; // group 制作9组
	group_delta.x = 0*factor;
	group_delta.y = -group_width*factor;		
	
	LMagnification group_mag; // group放大的倍数
	group_mag.num = 1;  // 分子
	group_mag.denom = 1; // 分母
	LTransform_Ex99 group_transform;	//例化体移动和旋转
	group_transform.translation = group_trans; //例化体移动位置
	group_transform.orientation = LRotate90; // 例化体旋转方式
	group_transform.magnification = group_mag;  // 例化体放大倍数
	
	// 设置ssc的组件的位置个数等属性
	ssc_trans.x = (16000-50/2)*factor-width;
	ssc_trans.y = -(3000+3000+100/2+(3000-100-100/2)/2)*factor;
	ssc_repeat_cnt.x = 1;
	ssc_repeat_cnt.y = 6; // ssc 制作9组
	ssc_delta.x = 0*factor;
	ssc_delta.y = 50*factor;	//阵列的系数	
	
	LMagnification ssc_mag; // 放大的倍数
	ssc_mag.num = 1;  // 分子
	ssc_mag.denom = 1; // 分母
	LTransform_Ex99 ssc_transform;	//例化体移动和旋转
	ssc_transform.translation = ssc_trans; //例化体移动位置
	ssc_transform.orientation = LRotate90; // 例化体旋转方式
	ssc_transform.magnification = ssc_mag;  // 例化体放大倍数
	
	// 设置psr的组件的位置个数等属性
	psr_trans.x = (16000-50*6-68/2)*factor-width;
	psr_trans.y = -(3000+3000+100/2+(3000-100-100/2)/2)*factor;
	psr_repeat_cnt.x = 1;
	psr_repeat_cnt.y = 6; // ssc 制作9组
	psr_delta.x = 0*factor;
	psr_delta.y = 68*factor;	//阵列的系数	
	
	LMagnification psr_mag; // 放大的倍数
	psr_mag.num = 1;  // 分子
	psr_mag.denom = 1; // 分母
	LTransform_Ex99 psr_transform;	//例化体移动和旋转
	psr_transform.translation = psr_trans; //例化体移动位置
	psr_transform.orientation = LRotate90; // 例化体旋转方式
	psr_transform.magnification = psr_mag;  // 例化体放大倍数
	
	// 设置mod的组件的位置个数等属性
	mod_trans.x = 2000*factor+width;
	mod_trans.y = -6500*factor-width/2;
	mod_repeat_cnt.x = 2;
	mod_repeat_cnt.y = 3; // mod 制作2*3
	mod_delta.x = 4100*factor; // 调整间隙增加100um
	mod_delta.y = -920*factor+50*factor;	//阵列的系数 	
	
	LMagnification mod_mag; // 放大的倍数
	mod_mag.num = 1;  // 分子
	mod_mag.denom = 1; // 分母
	LTransform_Ex99 mod_transform;	//例化体移动和旋转
	mod_transform.translation = mod_trans; //例化体移动位置
	mod_transform.orientation = LRotate0; // 例化体旋转方式
	mod_transform.magnification = mod_mag;  // 例化体放大倍数
	
	// 设置gr的组件的位置个数等属性
	//gr_trans.x = (4600*2+4000+1850/2+130*2)*factor;
	gr_trans.x = (MZI_length*2+MZI_width+(GR_length)/2)*factor+width;
	gr_trans.y = -GR_width/2*factor-width;
	gr_repeat_cnt.x = 1;
	gr_repeat_cnt.y = 10; // gr 制作10
	gr_delta.x = 0*factor;
	gr_delta.y = -50*factor;	//阵列的系数	
	
	LMagnification gr_mag; // 放大的倍数
	gr_mag.num = 1;  // 分子
	gr_mag.denom = 1; // 分母
	LTransform_Ex99 gr_transform;	//例化体移动和旋转
	gr_transform.translation = gr_trans; //例化体移动位置
	gr_transform.orientation = LRotate0; // 例化体旋转方式
	gr_transform.magnification = gr_mag;  // 例化体放大倍数
	
	// 设置psgc的组件的位置个数等属性
	//psgc_trans.x = (4600*2+4000+1850+680/2 + 20 - (130+680/2)+130*2)*factor; 
	psgc_trans.x = (MZI_length*2+MZI_width+single_pd_length+PSGC_length/2 + 20 - (130+PSGC_length/2))*factor+width; 
	psgc_trans.y = (-PSGC_width/2-GR_width*10)*factor-width;
	psgc_repeat_cnt.x = 1;
	psgc_repeat_cnt.y = 6; // psgc 制作6组
	psgc_delta.x = 0*factor;
	psgc_delta.y = -PSGC_width*factor;	//阵列的系数	
	
	LMagnification psgc_mag; // 放大的倍数
	psgc_mag.num = 1;  // 分子
	psgc_mag.denom = 1; // 分母
	LTransform_Ex99 psgc_transform;	//例化体移动和旋转
	psgc_transform.translation = psgc_trans; //例化体移动位置
	psgc_transform.orientation = LRotate0; // 例化体旋转方式
	psgc_transform.magnification = psgc_mag;  // 例化体放大倍数
	
	// 设置pic_mzi的组件的位置个数等属性
	//pic_mzi_trans.x = (9200+4000/2+130*2+20)*factor;
	pic_mzi_trans.x = (MZI_length*2+MZI_width/2+20)*factor+width;
	pic_mzi_trans.y = (-MZI_length/2)*factor-width;
	pic_mzi_repeat_cnt.x = 1;
	pic_mzi_repeat_cnt.y = 1; // pic_mzi 制作2
	pic_mzi_delta.x = 0*factor;
	pic_mzi_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification pic_mzi_mag; // 放大的倍数
	pic_mzi_mag.num = 1;  // 分子
	pic_mzi_mag.denom = 1; // 分母
	LTransform_Ex99 pic_mzi_transform;	//例化体移动和旋转
	pic_mzi_transform.translation = pic_mzi_trans; //例化体移动位置
	pic_mzi_transform.orientation = LRotate90; // 例化体旋转方式
	pic_mzi_transform.magnification = pic_mzi_mag;  // 例化体放大倍数
	
	// 设置pic_in的组件的位置个数等属性
	pic_in_trans.x = (MZI_length/2)*factor+width;
	pic_in_trans.y = (-MZI_width/2)*factor-width;
	pic_in_repeat_cnt.x = 2;
	pic_in_repeat_cnt.y = 1; // pic_in 制作2
	pic_in_delta.x = MZI_length*factor;
	pic_in_delta.y = 0*factor;	//阵列的系数	
	
	LMagnification pic_in_mag; // 放大的倍数
	pic_in_mag.num = 1;  // 分子
	pic_in_mag.denom = 1; // 分母
	LTransform_Ex99 pic_in_transform;	//例化体移动和旋转
	pic_in_transform.translation = pic_in_trans; //例化体移动位置
	pic_in_transform.orientation = LRotate0; // 例化体旋转方式
	pic_in_transform.magnification = pic_in_mag;  // 例化体放大倍数
	
	// 设置single_pd的组件的位置个数等属性
	//single_pd_trans.x = (4600*2+4000+130*2+1270/2-180)*factor;
	single_pd_trans.x = (MZI_length*2+MZI_width+single_pd_length/2-180)*factor+width;
	single_pd_trans.y = (-GR_width*10-single_pd_width/2)*factor-width;
	single_pd_repeat_cnt.x = 1;
	single_pd_repeat_cnt.y = 10; // single_pd 制作2
	single_pd_delta.x = 0*factor;
	single_pd_delta.y = -single_pd_width*factor;	//阵列的系数	
	
	LMagnification single_pd_mag; // 放大的倍数
	single_pd_mag.num = 1;  // 分子
	single_pd_mag.denom = 1; // 分母
	LTransform_Ex99 single_pd_transform;	//例化体移动和旋转
	single_pd_transform.translation = single_pd_trans; //例化体移动位置
	single_pd_transform.orientation = LRotate0; // 例化体旋转方式
	single_pd_transform.magnification = single_pd_mag;  // 例化体放大倍数
	
	// 设置double_pd的组件的位置个数等属性
	//double_pd_trans.x = (4600*2+4000+130*2+2000/2-550)*factor;
	double_pd_trans.x = (MZI_length*2+MZI_width+2000/2-550)*factor;
	double_pd_trans.y = (-6000+single_pd_width/2+130)*factor;
	double_pd_repeat_cnt.x = 1;
	double_pd_repeat_cnt.y = 6; // double_pd 制作2
	double_pd_delta.x = 0*factor;
	double_pd_delta.y = single_pd_width*factor;	//阵列的系数	
	
	LMagnification double_pd_mag; // 放大的倍数
	double_pd_mag.num = 1;  // 分子
	double_pd_mag.denom = 1; // 分母
	LTransform_Ex99 double_pd_transform;	//例化体移动和旋转
	double_pd_transform.translation = double_pd_trans; //例化体移动位置
	double_pd_transform.orientation = LRotate0; // 例化体旋转方式
	double_pd_transform.magnification = double_pd_mag;  // 例化体放大倍数
	
	// 设置pic_pd的组件的位置个数等属性
	pic_pd_trans.x = (4800/2)*factor;
	pic_pd_trans.y = (-4000-300/2)*factor;
	pic_pd_repeat_cnt.x = 2;
	pic_pd_repeat_cnt.y = 4; // pic_pd 制作2
	pic_pd_delta.x = 4730*factor;
	pic_pd_delta.y = -300*factor;	//阵列的系数	
	
	LMagnification pic_pd_mag; // 放大的倍数
	pic_pd_mag.num = 1;  // 分子
	pic_pd_mag.denom = 1; // 分母
	LTransform_Ex99 pic_pd_transform;	//例化体移动和旋转
	pic_pd_transform.translation = pic_pd_trans; //例化体移动位置
	pic_pd_transform.orientation = LRotate0; // 例化体旋转方式
	pic_pd_transform.magnification = pic_pd_mag;  // 例化体放大倍数
	
	// 设置double_pd_psgc的组件的位置个数等属性
	double_pd_psgc_trans.x = (MZI_length*2+9*group_width+640+10)*factor+width;
	double_pd_psgc_trans.y = ((-6000+10+630))*factor+width/2;
	double_pd_psgc_repeat_cnt.x = 2;
	double_pd_psgc_repeat_cnt.y = 3; // double_pd_psgc 制作2
	double_pd_psgc_delta.x = double_pd_length*factor;
	double_pd_psgc_delta.y = (double_pd_width+10)*factor;	//阵列的系数	
	
	LMagnification double_pd_psgc_mag; // 放大的倍数
	double_pd_psgc_mag.num = 1;  // 分子
	double_pd_psgc_mag.denom = 1; // 分母
	LTransform_Ex99 double_pd_psgc_transform;	//例化体移动和旋转
	double_pd_psgc_transform.translation = double_pd_psgc_trans; //例化体移动位置
	double_pd_psgc_transform.orientation = LRotate0; // 例化体旋转方式
	double_pd_psgc_transform.magnification = double_pd_psgc_mag;  // 例化体放大倍数
	
	// 设置pic_pd_psgc的组件的位置个数等属性
	pic_pd_psgc_trans.x = (4800/2)*factor;
	pic_pd_psgc_trans.y = (-4000-300/2)*factor;
	pic_pd_psgc_repeat_cnt.x = 2;
	pic_pd_psgc_repeat_cnt.y = 4; // pic_pd_psgc 制作2
	pic_pd_psgc_delta.x = 4730*factor;
	pic_pd_psgc_delta.y = -300*factor;	//阵列的系数	
	
	LMagnification pic_pd_psgc_mag; // 放大的倍数
	pic_pd_psgc_mag.num = 1;  // 分子
	pic_pd_psgc_mag.denom = 1; // 分母
	LTransform_Ex99 pic_pd_psgc_transform;	//例化体移动和旋转
	pic_pd_psgc_transform.translation = pic_pd_psgc_trans; //例化体移动位置
	pic_pd_psgc_transform.orientation = LRotate0; // 例化体旋转方式
	pic_pd_psgc_transform.magnification = pic_pd_psgc_mag;  // 例化体放大倍数
	
	// 绘制 流片的轮廓线 设置参数
	LObject wire_rule, wire_rule_half, wire_rule_half_1;
	LPoint wire_point[5], wire_point_half[2], wire_point_half_1[2];
	LPoint Translation = LCursor_GetPosition();
	
	
	//LJoinType ruler_join = LJoinRound;
	//LWireConfig *ruler_wire;
	//ruler_wire->width = width;
	//ruler_wire->join = ruler_join;
	//ruler_wire->cap = LCapRound;
	//ruler_wire->miter_angle = NULL;
	
	double x0, y0, block_length, block_width;
	x0 = 0;
	y0 = 0;
	block_length = 16000*factor;
	block_width = 3000*factor;
	wire_point[0].x = y0+width/2;
	wire_point[0].y = x0-width/2;
	wire_point[1].x = block_length-width/2;
	wire_point[1].y = y0-width/2;
	wire_point[2].x = block_length-width/2;
	wire_point[2].y = -block_width*3+width/2;
	wire_point[3].x = x0+width/2;
	wire_point[3].y = -block_width*3+width/2;
	wire_point[4].x = x0+width/2;
	wire_point[4].y = y0-width/2;
	
	wire_point_half[0].x = x0+width/2;
	wire_point_half[0].y = -block_width*2;
	wire_point_half[1].x = block_length-width/2;
	wire_point_half[1].y = -block_width*2;
	
	wire_point_half_1[0].x = x0+width/2;
	wire_point_half_1[0].y = -block_width;
	wire_point_half_1[1].x = block_length-width/2;
	wire_point_half_1[1].y = -block_width;
	
	
	
	LFile layout_file = LFile_GetVisible(); // 默认的当前打开的文件
	LFile_SetAuthor( layout_file, "LuZequan" );
	/* Get the current grid setting for layout_file */ //设置manufacturing_grid_size = 0.001um
	LGrid_v10_00 Grid;
	LFile_GetGrid_v10_00( layout_file, &Grid );
	/* Specify new grid settings */
	Grid.manufacturing_grid_size = 0.001*Grid.displayed_grid_size;
	Grid.display_curves_using_manufacturing_grid = LTRUE;
	/* Apply the new grid structure to layout_file */
	LFile_SetGrid_v10_00(layout_file, &Grid);
	
	if( Assigned(layout_file ) )
	{

		LCell layout_cell = LCell_New( layout_file, "layout_cell"); // 创建一个总的cell
		LCell group_cell = LCell_New( layout_file, "group_cell" ); // 新建cascade_mmi_cell
		LCell ssc_cell = LCell_New( layout_file, "ssc_cell" ); // 新建ssc_cell
		LCell psr_cell = LCell_New( layout_file, "psr_cell" ); // 新建psr_cell
		LCell mod_cell = LCell_New( layout_file, "mod_cell" ); // 新建mod_cell
		LCell gr_cell = LCell_New( layout_file, "gr_cell" ); // 新建gr_cell
		LCell psgc_cell = LCell_New( layout_file, "psgc_cell" ); // 新建psgc_cell
		LCell pic_mzi_cell = LCell_New( layout_file, "pic_mzi_cell" ); // 新建pic_mzi_cell
		LCell gr_link_cell = LCell_New( layout_file, "gr_link_cell" ); // 新建pgr_link_cell
		LCell single_pd_gr_cell = LCell_New( layout_file, "single_pd_gr_cell" ); // 新建single_pd_gr_cell
		LCell double_pd_gr_cell = LCell_New( layout_file, "double_pd_gr_cell" ); // 新建double_pd_gr_cell
		LCell psgc_gr_cell = LCell_New( layout_file, "psgc_gr_cell" ); // 新建psgc_gr_cell
		LCell double_pd_psgc_cell = LCell_New( layout_file, "double_pd_psgc_cell" ); // 新建double_pd_psgc_cell
		LCell lu_mmi_f_cell = LCell_New( layout_file, "lu_mmi_f_cell" ); 
		LCell gr_link_line_cell = LCell_New( layout_file, "gr_link_line_cell" ); // 新建pgr_link_cell
			if ( group_cell )
			{
				group_edit(layout_file, group_cell);// 注意将file和cell传递给绘制函数
			}
			if ( ssc_cell )
			{
				SSC(layout_file, ssc_cell);// 注意将file和cell传递给绘制函数
			}
			if ( psr_cell )
			{
				PSR1310_SSC(layout_file, psr_cell);// 注意将file和cell传递给绘制函数
			}
			if ( mod_cell )
			{
				MOD_1310nm(layout_file, mod_cell);// 注意将file和cell传递给绘制函数
			}
			if ( gr_cell )
			{
				GR1310(layout_file, gr_cell);// 注意将file和cell传递给绘制函数
			}
			if ( psgc_cell )
			{
				PSGC(layout_file, psgc_cell);// 注意将file和cell传递给绘制函数
			}
			if ( pic_mzi_cell )
			{
				pic_mzi(layout_file, pic_mzi_cell);// 注意将file和cell传递给绘制函数
			}
			// 给PD加上输入光栅
			if ( gr_link_cell )
			{
				grating_link(layout_file, gr_link_cell);// 注意将file和cell传递给绘制函数
			}
			
			if ( single_pd_gr_cell )
			{
				single_pd_gr(layout_file, single_pd_gr_cell,gr_link_cell);// 注意将file和cell传递给绘制函数
			}
			if ( double_pd_gr_cell )
			{
				double_pd_gr(layout_file, double_pd_gr_cell,gr_link_cell);// 注意将file和cell传递给绘制函数
			}
			if ( psgc_gr_cell )
			{
				PSGC_GR(layout_file, psgc_gr_cell);// 注意将file和cell传递给绘制函数
			}
			if ( double_pd_psgc_cell )
			{
				double_pd_pic_psgc(layout_file, double_pd_psgc_cell, psgc_gr_cell);// 注意将file和cell传递给绘制函数
			}
			if ( gr_link_line_cell )
			{
				grating_link_line(layout_file, gr_link_line_cell);// 注意将file和cell传递给绘制函数
			}
			if ( lu_mmi_f_cell )
			{
				mmi_f(layout_file, lu_mmi_f_cell,gr_link_line_cell);// 注意将file和cell传递给绘制函数
			}
			
		//group_edit(layout_file);
			if( layout_cell )
			{ 
				//LInstance LInstance_New_Ex99( LCell cell, LCell instance_cell, LTransform_Ex99 transform, LPoint repeat_cnt, LPoint delta );
				//函数解释：创建新的例化体（实例化，例化体，例化体移动和旋转，例化体组成的矩阵最小是（1,1），矩阵有序偏移间距）

				LInstance_New_Ex99( layout_cell, group_cell, group_transform, group_repeat_cnt, group_delta); //1_4 组件放置
 				LInstance_New_Ex99( layout_cell, ssc_cell, ssc_transform, ssc_repeat_cnt, ssc_delta);
				LInstance_New_Ex99( layout_cell, psr_cell, psr_transform, psr_repeat_cnt, psr_delta);
				LInstance_New_Ex99( layout_cell, mod_cell, mod_transform, mod_repeat_cnt, mod_delta);
				LInstance_New_Ex99( layout_cell, gr_cell, gr_transform, gr_repeat_cnt, gr_delta);
				LInstance_New_Ex99( layout_cell, psgc_cell, psgc_transform, psgc_repeat_cnt, psgc_delta);
				LInstance_New_Ex99( layout_cell, pic_mzi_cell, pic_mzi_transform, pic_mzi_repeat_cnt, pic_mzi_delta);
				LInstance_New_Ex99( layout_cell, pic_mzi_cell, pic_in_transform, pic_in_repeat_cnt, pic_in_delta);
				LInstance_New_Ex99( layout_cell, single_pd_gr_cell, single_pd_transform, single_pd_repeat_cnt, single_pd_delta);
				//LInstance_New_Ex99( layout_cell, double_pd_gr_cell, double_pd_transform, double_pd_repeat_cnt, double_pd_delta);				
				LInstance_New_Ex99( layout_cell, double_pd_psgc_cell, double_pd_psgc_transform, double_pd_psgc_repeat_cnt, double_pd_psgc_delta);
				//LInstance_New_Ex99( layout_cell, single_pd_gr_cell, pic_pd_transform, pic_pd_repeat_cnt, pic_pd_delta);
				// 绘制流片的范围
				wire_rule = LWire_New(layout_cell, LLayer_Find(layout_file, "Grid Layer"), NULL, 0, wire_point, 5);
				LWire_SetWidth( layout_cell, wire_rule, width );
				wire_rule_half = LWire_New(layout_cell, LLayer_Find(layout_file, "Grid Layer"), NULL, 0, wire_point_half, 2); 
				LWire_SetWidth( layout_cell, wire_rule_half, width );
				wire_rule_half_1 = LWire_New(layout_cell, LLayer_Find(layout_file, "Grid Layer"), NULL, 0, wire_point_half_1, 2); 
				LWire_SetWidth( layout_cell, wire_rule_half_1, width );
				LDialog_AlertBox( "Layout is created successfully!!" );
			}
			
		
	}
}





	void Hisense_layout_register(void)
{
	LMacro_Register("Hisense_layout","main");
}

}
	
	Hisense_layout_register();	
	