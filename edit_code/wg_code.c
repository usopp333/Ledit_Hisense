// only waveguide 
//module wg_code
//{
	#include <stdlib.h>
	#include <math.h>
	#include "ldata.h"
	
	void wg (LFile file, LCell cell)
{
    double factor, center_x, center_y, wg_l, wg_w, theta;	//相关结构参数的定义（ledit的旋转是按逆时针方向）

	factor = 1000;	//因子参数
	
	center_x = 0;
	center_y = 0;
	wg_l = 10*factor;
	wg_w = 0.5*factor;
	theta = 45;
	// 可以这样新建一个cell进行操作
	/*LFile test_File = LFile_GetVisible(); // 默认的当前打开的文件
	if( Assigned(test_File ) )
	{
		LCell test_Cell = LCell_New( test_File, "wg_test_cell" ); // 新建一个cell
			if ( test_Cell )
			{
				straight_waveguide(test_File, test_Cell, center_x, center_y, wg_l, wg_w, theta);// 注意将file和cell传递给绘制函数
			}
	}//
*/
    straight_waveguide(file, cell, center_x, center_y, wg_l, wg_w, theta);// 注意将file和cell传递给绘制函数
	//straight_waveguide(center_x, center_y, wg_l, wg_w, theta);// 手动创建好cell后直接运行
} // main end

	void straight_waveguide(LFile file, LCell cell, double x0, double y0, double wg_l, double wg_w, double theta) // 使用自动创建的cell
	//void straight_waveguide( double x0, double y0, double wg_l, double wg_w, double theta) // 使用当前打开的cell
{
	LPoint			Points[4];
	LObject			waveguide;
	//LFile			File_Draw = LFile_GetVisible(); // 默认的当前打开的文件
	//LCell			Cell_Draw = LCell_GetVisible(); // 使用当前打开的cell
	//LFile			File_Draw = LCell_GetFile(Cell_Draw); // 使用当前打开cell的file
	//LCell			waveguide_cell = LCell_New(file,"wg_cell_2");
	LPoint			Translation = LCursor_GetPosition();
	LCoord r_x = 0, r_y = 0;
	
	Points[0].x = x0;
	Points[0].y = y0;
	Points[1].x = wg_l;
	Points[1].y = y0;
	Points[2].x = wg_l;
	Points[2].y = -wg_w;
	Points[3].x = x0;
	Points[3].y = -wg_w;
	//waveguide = LPolygon_New(Cell_Draw, LLayer_Find(File_Draw, "Rib130"), Points, 4); // 都是使用当前cell和file
	waveguide = LPolygon_New(cell, LLayer_Find(file, "Rib130"), Points, 4); // 自动创建一个cell
	//waveguide = LPolygon_New(waveguide_cell	, LLayer_Find(file, "Rib130"), Points, 4); // 绘制在新建的一个cell上
	//LSelection_AddObject(waveguide); // 将waveguide添加到选择
	//LSelection_Group("wg_cell");
	//LSelection_Group(Cell_Draw);
	//LSelection_AddObject(waveguide_cell);
	//LCell_Delete();
	//LSelection_Move( 2, 2 );
	//LSelection_Rotate();
	//LSelection_RotateAroundPoint(10, r_x, r_y, LFALSE); 
	
	
}
/*
	void wg_register(void)
{
	LMacro_Register("wg_register","main");
}

//}
	
	wg_register();	
	*/