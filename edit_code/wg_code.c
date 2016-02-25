// only waveguide 
//module wg_code
//{
	#include <stdlib.h>
	#include <math.h>
	#include "ldata.h"
	
	void wg (LFile file, LCell cell)
{
    double factor, center_x, center_y, wg_l, wg_w, theta;	//��ؽṹ�����Ķ��壨ledit����ת�ǰ���ʱ�뷽��

	factor = 1000;	//���Ӳ���
	
	center_x = 0;
	center_y = 0;
	wg_l = 10*factor;
	wg_w = 0.5*factor;
	theta = 45;
	// ���������½�һ��cell���в���
	/*LFile test_File = LFile_GetVisible(); // Ĭ�ϵĵ�ǰ�򿪵��ļ�
	if( Assigned(test_File ) )
	{
		LCell test_Cell = LCell_New( test_File, "wg_test_cell" ); // �½�һ��cell
			if ( test_Cell )
			{
				straight_waveguide(test_File, test_Cell, center_x, center_y, wg_l, wg_w, theta);// ע�⽫file��cell���ݸ����ƺ���
			}
	}//
*/
    straight_waveguide(file, cell, center_x, center_y, wg_l, wg_w, theta);// ע�⽫file��cell���ݸ����ƺ���
	//straight_waveguide(center_x, center_y, wg_l, wg_w, theta);// �ֶ�������cell��ֱ������
} // main end

	void straight_waveguide(LFile file, LCell cell, double x0, double y0, double wg_l, double wg_w, double theta) // ʹ���Զ�������cell
	//void straight_waveguide( double x0, double y0, double wg_l, double wg_w, double theta) // ʹ�õ�ǰ�򿪵�cell
{
	LPoint			Points[4];
	LObject			waveguide;
	//LFile			File_Draw = LFile_GetVisible(); // Ĭ�ϵĵ�ǰ�򿪵��ļ�
	//LCell			Cell_Draw = LCell_GetVisible(); // ʹ�õ�ǰ�򿪵�cell
	//LFile			File_Draw = LCell_GetFile(Cell_Draw); // ʹ�õ�ǰ��cell��file
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
	//waveguide = LPolygon_New(Cell_Draw, LLayer_Find(File_Draw, "Rib130"), Points, 4); // ����ʹ�õ�ǰcell��file
	waveguide = LPolygon_New(cell, LLayer_Find(file, "Rib130"), Points, 4); // �Զ�����һ��cell
	//waveguide = LPolygon_New(waveguide_cell	, LLayer_Find(file, "Rib130"), Points, 4); // �������½���һ��cell��
	//LSelection_AddObject(waveguide); // ��waveguide��ӵ�ѡ��
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