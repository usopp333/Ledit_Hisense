// // Ѱ��double_pd_pic��cell��һ����ɾ��й�դ��PD�������
// Ѱ��double_pd_pic��cell��һ����ɾ��й�դ��PD�������

#include <stdlib.h>
#include <math.h>
#include "ldata.h"

double double_PD_width;
double psgc_gr_length;
void double_pd_pic_psgc(LFile file,LCell cell, LCell psgc_gr_cell)
{
	double factor = 1000;	//���Ӳ���
	double_PD_width = 616.05;
	psgc_gr_length = 336.309;
	LPoint  psgc_gr_trans, psgc_gr_repeat_cnt, psgc_gr_delta,
			psgc_gr_r_trans, psgc_gr_r_repeat_cnt, psgc_gr_r_delta,
			double_pd_pic_trans, double_pd_pic_repeat_cnt, double_pd_pic_delta;
	
	
	// ����psgc_gr�������λ�ø���������
	psgc_gr_trans.x = psgc_gr_length*factor;
	psgc_gr_trans.y = -double_PD_width/2*factor;
	psgc_gr_repeat_cnt.x = 1;
	psgc_gr_repeat_cnt.y = 1; // psgc_gr ����1
	psgc_gr_delta.x = 0*factor;
	psgc_gr_delta.y = 0*factor;	//���е�ϵ��	
	
	LMagnification psgc_gr_mag; // �Ŵ�ı���
	psgc_gr_mag.num = 1;  // ����
	psgc_gr_mag.denom = 1; // ��ĸ
	LTransform_Ex99 psgc_gr_transform;	//�������ƶ�����ת
	psgc_gr_transform.translation = psgc_gr_trans; //�������ƶ�λ��
	psgc_gr_transform.orientation = LRotate0MirrorX; // ��������ת��ʽ
	psgc_gr_transform.magnification = psgc_gr_mag;  // ������Ŵ���
	
	
	// ����double_pd_pic�������λ�ø���������
	double_pd_pic_trans.x = 0*factor;
	double_pd_pic_trans.y = 0*factor;
	double_pd_pic_repeat_cnt.x = 1;
	double_pd_pic_repeat_cnt.y = 1; // double_pd_pic ����1
	double_pd_pic_delta.x = 0*factor;
	double_pd_pic_delta.y = 0*factor;	//���е�ϵ��	
	
	LMagnification double_pd_pic_mag; // �Ŵ�ı���
	double_pd_pic_mag.num = 1;  // ����
	double_pd_pic_mag.denom = 1; // ��ĸ
	LTransform_Ex99 double_pd_pic_transform;	//�������ƶ�����ת
	double_pd_pic_transform.translation = double_pd_pic_trans; //�������ƶ�λ��
	double_pd_pic_transform.orientation = LRotate0; // ��������ת��ʽ
	double_pd_pic_transform.magnification = double_pd_pic_mag;  // ������Ŵ���
	
	LCell double_pd_pic_gr_ell = LCell_Find( file, "double_pd_pic_W5L8_02" );
	if ( double_pd_pic_gr_ell )
	{
		LDialog_AlertBox( "Double PD Cell found ����" );
		LInstance_New_Ex99( cell, psgc_gr_cell, psgc_gr_transform, psgc_gr_repeat_cnt, psgc_gr_delta);
		LInstance_New_Ex99( cell, double_pd_pic_gr_ell, double_pd_pic_transform, double_pd_pic_repeat_cnt, double_pd_pic_delta);
	}
	else 
	{
		LDialog_AlertBox( "double PD Cell can not found ����" );
	}
}