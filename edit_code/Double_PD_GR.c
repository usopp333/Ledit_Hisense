// // Ѱ��double_PD��cell��һ����ɾ��й�դ��PD�������
// Ѱ��double_PD��cell��һ����ɾ��й�դ��PD�������

#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void double_pd_gr(LFile file,LCell cell, LCell gr_link_cell)
{
	double factor = 1000;	//���Ӳ���
	LPoint  gr_link_trans, gr_link_repeat_cnt, gr_link_delta,
			gr_link_r_trans, gr_link_r_repeat_cnt, gr_link_r_delta,
			double_pd_trans, double_pd_repeat_cnt, double_pd_delta;
	
	
	// ����gr_link�������λ�ø���������
	gr_link_trans.x = 0*factor;
	gr_link_trans.y = 0*factor;
	gr_link_repeat_cnt.x = 1;
	gr_link_repeat_cnt.y = 1; // gr_link ����1
	gr_link_delta.x = 0*factor;
	gr_link_delta.y = 0*factor;	//���е�ϵ��	
	
	LMagnification gr_link_mag; // �Ŵ�ı���
	gr_link_mag.num = 1;  // ����
	gr_link_mag.denom = 1; // ��ĸ
	LTransform_Ex99 gr_link_transform;	//�������ƶ�����ת
	gr_link_transform.translation = gr_link_trans; //�������ƶ�λ��
	gr_link_transform.orientation = LRotate0; // ��������ת��ʽ
	gr_link_transform.magnification = gr_link_mag;  // ������Ŵ���
	
	// ����gr_link_r�������λ�ø���������
	gr_link_r_trans.x = 1076.05*factor; // ˫PD�ĳ���
	gr_link_r_trans.y = 0*factor;
	gr_link_r_repeat_cnt.x = 1;
	gr_link_r_repeat_cnt.y = 1; // gr_link_r ����1
	gr_link_r_delta.x = 0*factor;
	gr_link_r_delta.y = 0*factor;	//���е�ϵ��	
	
	LMagnification gr_link_r_mag; // �Ŵ�ı���
	gr_link_r_mag.num = 1;  // ����
	gr_link_r_mag.denom = 1; // ��ĸ
	LTransform_Ex99 gr_link_r_transform;	//�������ƶ�����ת
	gr_link_r_transform.translation = gr_link_r_trans; //�������ƶ�λ��
	gr_link_r_transform.orientation = LRotate180; // ��������ת��ʽ
	gr_link_r_transform.magnification = gr_link_r_mag;  // ������Ŵ���
	
	// ����double_pd�������λ�ø���������
	double_pd_trans.x = 0*factor;
	double_pd_trans.y = 0*factor;
	double_pd_repeat_cnt.x = 1;
	double_pd_repeat_cnt.y = 1; // double_pd ����1
	double_pd_delta.x = 0*factor;
	double_pd_delta.y = 0*factor;	//���е�ϵ��	
	
	LMagnification double_pd_mag; // �Ŵ�ı���
	double_pd_mag.num = 1;  // ����
	double_pd_mag.denom = 1; // ��ĸ
	LTransform_Ex99 double_pd_transform;	//�������ƶ�����ת
	double_pd_transform.translation = double_pd_trans; //�������ƶ�λ��
	double_pd_transform.orientation = LRotate0; // ��������ת��ʽ
	double_pd_transform.magnification = double_pd_mag;  // ������Ŵ���
	
	LCell double_pd_gr_ell = LCell_Find( file, "double_PD_W5L8_02" );
	if ( double_pd_gr_ell )
	{
		LDialog_AlertBox( "Double PD Cell found ����" );
		LInstance_New_Ex99( cell, gr_link_cell, gr_link_transform, gr_link_repeat_cnt, gr_link_delta);
		LInstance_New_Ex99( cell, double_pd_gr_ell, double_pd_transform, double_pd_repeat_cnt, double_pd_delta);
		LInstance_New_Ex99( cell, gr_link_cell, gr_link_r_transform, gr_link_r_repeat_cnt, gr_link_r_delta);
	}
	else 
	{
		LDialog_AlertBox( "double PD Cell can not found ����" );
	}
}