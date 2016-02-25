// Ѱ��single_PD��cell��һ����ɾ��й�դ��PD�������

#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void single_pd_gr(LFile file,LCell cell, LCell gr_link_cell)
{
	double factor = 1000;	//���Ӳ���
	LPoint  gr_link_trans, gr_link_repeat_cnt, gr_link_delta,
			single_pd_trans, single_pd_repeat_cnt, single_pd_delta;
	
	
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
	
	// ����single_pd�������λ�ø���������
	single_pd_trans.x = 0*factor;
	single_pd_trans.y = 0*factor;
	single_pd_repeat_cnt.x = 1;
	single_pd_repeat_cnt.y = 1; // single_pd ����1
	single_pd_delta.x = 0*factor;
	single_pd_delta.y = 0*factor;	//���е�ϵ��	
	
	LMagnification single_pd_mag; // �Ŵ�ı���
	single_pd_mag.num = 1;  // ����
	single_pd_mag.denom = 1; // ��ĸ
	LTransform_Ex99 single_pd_transform;	//�������ƶ�����ת
	single_pd_transform.translation = single_pd_trans; //�������ƶ�λ��
	single_pd_transform.orientation = LRotate0; // ��������ת��ʽ
	single_pd_transform.magnification = single_pd_mag;  // ������Ŵ���
	
	LCell single_pd_gr_ell = LCell_Find( file, "single PD_W4L5_01" );
	if ( single_pd_gr_ell )
	{
		LDialog_AlertBox( "single PD Cell found ����" );
		LInstance_New_Ex99( cell, gr_link_cell, gr_link_transform, gr_link_repeat_cnt, gr_link_delta);
		LInstance_New_Ex99( cell, single_pd_gr_ell, single_pd_transform, single_pd_repeat_cnt, single_pd_delta);
	}
	else 
	{
		LDialog_AlertBox( "single PD Cell can not found ����" );
	}
}