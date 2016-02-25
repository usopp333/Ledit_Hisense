//2014/1/20
//edit by sun
//for mmi and mzi
//MMI����Լ�ԭ����ĸ���������ǣ�200��1500������200��500������200��-500������200��-1500��
//��������ԭ��������벨����ʼ�ˡ�
	#include <stdlib.h>
	#include <math.h>
	#include "ldata.h"
	#include "PIC_mmi.c" //�����ⲿ��cascade-mmi-edit.c�ļ�
	#include "PIC_MOD.c"	
	void pic_mzi (LFile file, LCell pic_cell)
{
	double factor = 1000;	//���Ӳ���
	double x0,y0;
	x0=-(4800/2-450);
	y0=0;
	LPoint mmi_trans,mmi_repeat_cnt, mmi_delta;  // trans:�ƶ���λ�ã� repeat_cnt����ɵ��� delta����ļ��
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

	LMagnification mmi_mag; // mmi�Ŵ�ı���
	mmi_mag.num = 1;  // ����
	mmi_mag.denom = 1; // ��ĸ
	LTransform_Ex99 mmi_transform;	//�������ƶ�����ת
	mmi_transform.translation = mmi_trans; //�������ƶ�λ��
	mmi_transform.orientation = LRotate0; // ��������ת��ʽ
	mmi_transform.magnification = mmi_mag;  // ������Ŵ���
/**********************************************************/
/*mod*/
/**********************************************************/
	mod_trans.x = 200*factor;
	mod_trans.y = 1500*factor;
	mod_repeat_cnt.x = 1;
	mod_repeat_cnt.y = 4;
	mod_delta.x = 0;
	mod_delta.y = -1000*factor;
	
	
	LMagnification mod_mag; // mmi�Ŵ�ı���
	mod_mag.num = 1;  // ����
	mod_mag.denom = 1; // ��ĸ
	LTransform_Ex99 mod_transform;	//�������ƶ�����ת
	mod_transform.translation = mod_trans; //�������ƶ�λ��
	mod_transform.orientation = LRotate0; // ��������ת��ʽ
	mod_transform.magnification = mod_mag;  // ������Ŵ���

	/*����*/
	if( Assigned(file ) )
	{
		LCell PIC_MOD_cell = LCell_New( file, "PIC_MOD_cell");
		if(PIC_MOD_cell)
		{
			PIC_MOD(file,PIC_MOD_cell,x0,y0);
		}
		
		LCell PIC_mmi_cell = LCell_New( file, "PIC_mmi_cell" ); // �½�PIC_mmi
		if ( PIC_mmi_cell )
		{
			PIC_mmi(file, PIC_mmi_cell, x0,y0);// ע�⽫file��cell���ݸ����ƺ���
		}

		//LCell PIC_cell=LCell_New(file,"PIC_cell");
		if(pic_cell)
		{
			LInstance_New_Ex99( pic_cell, PIC_mmi_cell, mmi_transform, mmi_repeat_cnt, mmi_delta);
			LInstance_New_Ex99( pic_cell, PIC_MOD_cell,mod_transform,mod_repeat_cnt,mod_delta);
		}

		//PIC_mmi(file, cell,x0,y0);// ע�⽫file��cell���ݸ����ƺ���
	}
}


	