// Author��LuZequan
// ���� �� 2016-02-17
// ���Լ���Ƶ�ģ�������ΪLedit�İ�ͼ
// mmiģ��
module cascade_mmi_f_layout
{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"
#include "mmi_f.c"

void main()
{
	double factor, pi;
	double wg_l, wg_w, mmi_l, gap, theta, wg_r;
	factor = 1000;
	pi = 3.1415926;
	wg_l = 2 *factor;
	wg_w = 0.41*factor;
	mmi_l = 1.73658*factor;
	gap = 0.1*factor;
	wg_r = 20*factor;
	theta = 45;
	LPoint			mmi_trans1,mmi_repeat_cnt1,mmi_delta1,
					mmi_trans2,mmi_repeat_cnt2,mmi_delta2,
					mmi_trans3,mmi_repeat_cnt3,mmi_delta3;
	LObject     	mmi,in_wg,arc_wg_up1,arc_wg_up2,arc_wg_down1,arc_wg_down2,out_wg;
	LFile  			cascade_mmi_file = LFile_GetVisible(); // Ĭ�ϵĵ�ǰ�򿪵��ļ�
	LFile_SetAuthor( cascade_mmi_file, "LuZequan" );
	LCell			cascade_mmi_cell =  LCell_New( cascade_mmi_file, "cascade_mmi_cell");
	LCell			mmicell =  LCell_New( cascade_mmi_file, "mmicell");
	LPoint       	Translation = LCursor_GetPosition ( ); 
	LTorusParams 	arc_up1,arc_up2,arc_down1,arc_down2; 
	
	mmi_trans1.x = wg_l;
	mmi_trans1.y = 0;
	mmi_repeat_cnt1.x = 1;
	mmi_repeat_cnt1.y = 1; 
	mmi_delta1.x = 0*factor;
	mmi_delta1.y = 0*factor;		
	
	LMagnification mmi_mag; // �Ŵ�ı���
	mmi_mag.num = 1;  // ����
	mmi_mag.denom = 1; // ��ĸ
	LTransform_Ex99 mmi_trans1form;	//�������ƶ�����ת
	mmi_trans1form.translation = mmi_trans1; //�������ƶ�λ��
	mmi_trans1form.orientation = LRotate0; // ��������ת��ʽ
	mmi_trans1form.magnification = mmi_mag;  // ������Ŵ���
	
	mmi_trans2.x = wg_l+mmi_l+2*wg_r*sin(theta*pi/180)+wg_l/2-wg_l/2;
	mmi_trans2.y = -(gap/2+wg_w/2+wg_r-2*wg_r*cos(theta*pi/180)+wg_r);
	mmi_repeat_cnt2.x = 1;
	mmi_repeat_cnt2.y = 1; 
	mmi_delta2.x = 0*factor;
	mmi_delta2.y = 0*factor;		
	

	LTransform_Ex99 mmi_trans2form;	//�������ƶ�����ת
	mmi_trans2form.translation = mmi_trans2; //�������ƶ�λ��
	mmi_trans2form.orientation = LRotate0; // ��������ת��ʽ
	mmi_trans2form.magnification = mmi_mag;  // ������Ŵ���
	
	mmi_trans3.x = mmi_trans2.x ;
	mmi_trans3.y = -mmi_trans2.y;
	mmi_repeat_cnt3.x = 1;
	mmi_repeat_cnt3.y = 1; 
	mmi_delta3.x = 0*factor;
	mmi_delta3.y = 0*factor;		
	

	LTransform_Ex99 mmi_trans3form;	//�������ƶ�����ת
	mmi_trans3form.translation = mmi_trans3; //�������ƶ�λ��
	mmi_trans3form.orientation = LRotate0; // ��������ת��ʽ
	mmi_trans3form.magnification = mmi_mag;  // ������Ŵ���

	
	if( Assigned(cascade_mmi_file ) )
	{
		if(mmicell)
		{
			mmi_f(cascade_mmi_file, mmicell);
		}
		if(cascade_mmi_cell)
		{
			LInstance_New_Ex99(cascade_mmi_cell,mmicell,mmi_trans1form,mmi_repeat_cnt1,mmi_delta1);
			LInstance_New_Ex99(cascade_mmi_cell,mmicell,mmi_trans2form,mmi_repeat_cnt2,mmi_delta2);
			LInstance_New_Ex99(cascade_mmi_cell,mmicell,mmi_trans3form,mmi_repeat_cnt3,mmi_delta3);
		}
		
	}
}

	void cascade_mmi_f_layout_register(void)
{
	LMacro_Register("cascade_mmi_f_layout","main");
}

}
	
	cascade_mmi_f_layout_register();	