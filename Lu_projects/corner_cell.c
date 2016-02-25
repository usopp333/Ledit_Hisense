// Author：LuZequan
// 日期 ： 2016-02-16
// 将自己设计的模型整理成为Ledit的版图
// corner模型
module corner_layout
{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"
typedef float LOrientation_Ex99; //额外定义一个旋转角度
	#define LRotate315 315
	#define LRotate135 135

void main()
{
	double factor, pi;
	double x0,y0;
	double wg_l, wg_w, a, b, theta;
	factor = 1000;
	pi = 3.1415926;
	wg_l = 2 *factor;
	wg_w = 0.41*factor;
	a = 1.42928*factor;
	b = 1.3636*factor;
	theta = 45;
	x0 = -(-wg_l/2-wg_l/2);
	y0 = wg_w/2;
	// corner的点坐标
	int nz = 102;
	float z_up[102] = {0.000000,0.020417,0.040835,0.061252,0.081669,0.102086,0.122504,0.142921,0.163338,0.183755,0.204173,0.224590,0.245007,0.265424,0.285842,0.306259,0.326676,0.347093,0.367511,0.387928,0.408345,0.428762,0.449180,0.469597,0.490014,0.510431,0.530849,0.551266,0.571683,0.592100,0.612518,0.632935,0.653352,0.673770,0.694187,0.714604,0.735021,0.755439,0.775856,0.796273,0.816690,0.837108,0.857525,0.877942,0.898359,0.918777,0.939194,0.959611,0.980028,1.000446,1.020863,1.041280,1.061697,1.082115,1.102532,1.122949,1.143366,1.163784,1.184201,1.204618,1.225035,1.245453,1.265870,1.286287,1.306704,1.327122,1.347539,1.367956,1.388374,1.408791,1.429208,1.449625,1.470043,1.490460,1.510877,1.531294,1.551712,1.572129,1.592546,1.612963,1.633381,1.653798,1.674215,1.694632,1.715050,1.735467,1.755884,1.776301,1.796719,1.817136,1.837553,1.857970,1.878388,1.898805,1.919222,1.939639,1.960057,1.980474,2.000891,2.021309,1.876352,0.144957};
	float x_up[102] = {0.000000,0.012490,0.024646,0.036472,0.047976,0.059162,0.070035,0.080601,0.090866,0.100835,0.110511,0.119901,0.129008,0.137837,0.146392,0.154677,0.162696,0.170452,0.177948,0.185187,0.192173,0.198908,0.205394,0.211634,0.217629,0.223383,0.228896,0.234170,0.239207,0.244009,0.248575,0.252908,0.257008,0.260877,0.264514,0.267922,0.271100,0.274049,0.276770,0.279262,0.281527,0.283565,0.285376,0.286960,0.288317,0.289448,0.290352,0.291031,0.291483,0.291709,0.291709,0.291483,0.291031,0.290352,0.289448,0.288317,0.286960,0.285376,0.283565,0.281527,0.279262,0.276770,0.274049,0.271100,0.267922,0.264514,0.260877,0.257008,0.252908,0.248575,0.244009,0.239207,0.234170,0.228896,0.223383,0.217629,0.211634,0.205394,0.198908,0.192173,0.185187,0.177948,0.170452,0.162696,0.154677,0.146392,0.137837,0.129008,0.119901,0.110511,0.100835,0.090866,0.080601,0.070035,0.059162,0.047976,0.036472,0.024646,0.012490,0.000000,-0.144957,-0.144957};
	float z_down[102] = {0.000000,0.019479,0.038958,0.058437,0.077916,0.097395,0.116874,0.136353,0.155832,0.175311,0.194790,0.214269,0.233748,0.253227,0.272706,0.292185,0.311664,0.331143,0.350622,0.370101,0.389580,0.409059,0.428538,0.448017,0.467496,0.486975,0.506454,0.525934,0.545413,0.564892,0.584371,0.603850,0.623329,0.642808,0.662287,0.681766,0.701245,0.720724,0.740203,0.759682,0.779161,0.798640,0.818119,0.837598,0.857077,0.876556,0.896035,0.915514,0.934993,0.954472,0.973951,0.993430,1.012909,1.032388,1.051867,1.071346,1.090825,1.110304,1.129783,1.149262,1.168741,1.188220,1.207699,1.227178,1.246657,1.266136,1.285615,1.305094,1.324573,1.344052,1.363531,1.383010,1.402489,1.421968,1.441447,1.460926,1.480405,1.499884,1.519363,1.538843,1.558322,1.577801,1.597280,1.616759,1.636238,1.655717,1.675196,1.694675,1.714154,1.733633,1.753112,1.772591,1.792070,1.811549,1.831028,1.850507,1.869986,1.889465,1.908944,1.928423,2.073380,-0.144957};
	float x_down[102] = {0.000000,-0.006177,-0.012155,-0.017938,-0.023532,-0.028941,-0.034170,-0.039222,-0.044103,-0.048816,-0.053365,-0.057754,-0.061987,-0.066068,-0.069999,-0.073784,-0.077427,-0.080930,-0.084296,-0.087529,-0.090631,-0.093605,-0.096453,-0.099178,-0.101782,-0.104268,-0.106638,-0.108893,-0.111036,-0.113069,-0.114993,-0.116811,-0.118523,-0.120132,-0.121639,-0.123045,-0.124352,-0.125560,-0.126671,-0.127686,-0.128606,-0.129431,-0.130163,-0.130801,-0.131348,-0.131802,-0.132166,-0.132438,-0.132619,-0.132710,-0.132710,-0.132619,-0.132438,-0.132166,-0.131802,-0.131348,-0.130801,-0.130163,-0.129431,-0.128606,-0.127686,-0.126671,-0.125560,-0.124352,-0.123045,-0.121639,-0.120132,-0.118523,-0.116811,-0.114993,-0.113069,-0.111036,-0.108893,-0.106638,-0.104268,-0.101782,-0.099178,-0.096453,-0.093605,-0.090631,-0.087529,-0.084296,-0.080930,-0.077427,-0.073784,-0.069999,-0.066068,-0.061987,-0.057754,-0.053365,-0.048816,-0.044103,-0.039222,-0.034170,-0.028941,-0.023532,-0.017938,-0.012155,-0.006177,0.000000,-0.144957,-0.144957};
	float z_add[4] = {-0.344320,0.000000,1.224280,1.224280};
	float x_add[4] = {-0.205000,-0.205000,-1.429280,-1.773600};
	LPoint 			corner_up_point[102], corner_down_point[102], corner_add_point[4], 
					corner_wga_point[4], corner_wgb_point[4], corner_wgc_point[4], corner_wgd_point[4];
	LPoint			corner_up_trans,corner_up_repeat_cnt,corner_up_delta,
					corner_down_trans,corner_down_repeat_cnt,corner_down_delta,
					corner_add_trans,corner_add_repeat_cnt,corner_add_delta;;
	LObject     	corner_up,corner_down,corner_add,corner_wga,corner_wgb,corner_wgc,corner_wgd;
	LFile  			corner_file = LFile_GetVisible(); // 默认的当前打开的文件
	LFile_SetAuthor( corner_file, "LuZequan" );
	LCell			corner_cell =  LCell_New( corner_file, "corner_cell");
	LCell			corner_upcell =  LCell_New( corner_file, "corner_upcell");
	LCell			corner_downcell =  LCell_New( corner_file, "corner_downcell");
	LCell			corner_addcell =  LCell_New( corner_file, "corner_addcell");
	LPoint       	Translation = LCursor_GetPosition ( ); 
	LTorusParams 	tParams; 
	
	corner_up_trans.x = 0+x0;
	corner_up_trans.y = 0+y0;
	corner_up_repeat_cnt.x = 1;
	corner_up_repeat_cnt.y = 1; 
	corner_up_delta.x = 0*factor;
	corner_up_delta.y = 0*factor;		
	
	LMagnification corner_up_mag; // 放大的倍数
	corner_up_mag.num = 1;  // 分子
	corner_up_mag.denom = factor*10; // 分母
	LTransform_Ex99 corner_up_transform;	//例化体移动和旋转
	corner_up_transform.translation = corner_up_trans; //例化体移动位置
	corner_up_transform.orientation = LRotate315; // 例化体旋转方式
	corner_up_transform.magnification = corner_up_mag;  // 例化体放大倍数

	corner_down_trans.x = (a-wg_w)+x0;
	corner_down_trans.y = (-b-wg_w)+y0;
	corner_down_repeat_cnt.x = 1;
	corner_down_repeat_cnt.y = 1; 
	corner_down_delta.x = 0*factor;
	corner_down_delta.y = 0*factor;		
	
	LMagnification corner_down_mag; // 放大的倍数
	corner_down_mag.num = 1;  // 分子
	corner_down_mag.denom = factor*10; // 分母
	LTransform_Ex99 corner_down_transform;	//例化体移动和旋转
	corner_down_transform.translation = corner_down_trans; //例化体移动位置
	corner_down_transform.orientation = LRotate135; // 例化体旋转方式
	corner_down_transform.magnification = corner_down_mag;  // 例化体放大倍数
	
	corner_add_trans.x = 0+x0;
	corner_add_trans.y = 0+y0;
	corner_add_repeat_cnt.x = 1;
	corner_add_repeat_cnt.y = 1; 
	corner_add_delta.x = 0*factor;
	corner_add_delta.y = 0*factor;		
	
	LMagnification corner_add_mag; // 放大的倍数
	corner_add_mag.num = 1;  // 分子
	corner_add_mag.denom = factor*10; // 分母
	LTransform_Ex99 corner_add_transform;	//例化体移动和旋转
	corner_add_transform.translation = corner_add_trans; //例化体移动位置
	corner_add_transform.orientation = LRotate0; // 例化体旋转方式
	corner_add_transform.magnification = corner_add_mag;  // 例化体放大倍数
	
	int n;
	for (n=0; n<nz; n++)
	{
		corner_up_point[n].x = z_up[n]*factor*factor*10+x0;
		corner_up_point[n].y = x_up[n]*factor*factor*10+y0;
		corner_down_point[n].x = z_down[n]*factor*factor*10+x0;
		corner_down_point[n].y = x_down[n]*factor*factor*10+y0;
	}
	for (n=0; n<4; n++)
	{
		corner_add_point[n].x = z_add[n]*factor*factor*10+x0;
		corner_add_point[n].y = x_add[n]*factor*factor*10+y0;
	}
	
	corner_wga_point[0].x = -wg_l/2-wg_l/2+x0;
	corner_wga_point[0].y = -wg_w/4+wg_w/2/2+y0;
	corner_wga_point[1].x = -wg_l/2+wg_l/2+x0;
	corner_wga_point[1].y = -wg_w/4+wg_w/2/2+y0;
	corner_wga_point[2].x = -wg_l/2+wg_l/2+x0;
	corner_wga_point[2].y = -wg_w/4-wg_w/2/2+y0;
	corner_wga_point[3].x = -wg_l/2-wg_l/2+x0;
	corner_wga_point[3].y = -wg_w/4-wg_w/2/2+y0;
	
	corner_wgb_point[0].x = -(wg_l-(b-(a-wg_w)))/2-(b-a+wg_w)-(wg_l-(b-(a-wg_w)))/2+x0;
	corner_wgb_point[0].y = -3*wg_w/4+(wg_w/2)/2+y0;
	corner_wgb_point[1].x = -(wg_l-(b-(a-wg_w)))/2-(b-a+wg_w)+(wg_l-(b-(a-wg_w)))/2+x0;
	corner_wgb_point[1].y = -3*wg_w/4+(wg_w/2)/2+y0;
	corner_wgb_point[2].x = -(wg_l-(b-(a-wg_w)))/2-(b-a+wg_w)+(wg_l-(b-(a-wg_w)))/2+x0;
	corner_wgb_point[2].y = -3*wg_w/4-(wg_w/2)/2+y0;
	corner_wgb_point[3].x = -(wg_l-(b-(a-wg_w)))/2-(b-a+wg_w)-(wg_l-(b-(a-wg_w)))/2+x0;
	corner_wgb_point[3].y = -3*wg_w/4-(wg_w/2)/2+y0;
	
	corner_wgc_point[0].x = a-wg_w/4-(wg_w/2)/2+x0;
	corner_wgc_point[0].y = -a-wg_l/2+wg_l/2+y0;
	corner_wgc_point[1].x = a-wg_w/4+(wg_w/2)/2+x0;
	corner_wgc_point[1].y = -a-wg_l/2+wg_l/2+y0;
	corner_wgc_point[2].x = a-wg_w/4+(wg_w/2)/2+x0;
	corner_wgc_point[2].y = -a-wg_l/2-wg_l/2+y0;
	corner_wgc_point[3].x = a-wg_w/4-(wg_w/2)/2+x0;
	corner_wgc_point[3].y = -a-wg_l/2-wg_l/2+y0;
	
	corner_wgd_point[0].x = a-3*wg_w/4-(wg_w/2)/2+x0;
	corner_wgd_point[0].y = -(wg_l-(b-(a-wg_w)))/2-wg_w-b+(wg_l-(b-(a-wg_w)))/2+y0;
	corner_wgd_point[1].x = a-3*wg_w/4+(wg_w/2)/2+x0;
	corner_wgd_point[1].y = -(wg_l-(b-(a-wg_w)))/2-wg_w-b+(wg_l-(b-(a-wg_w)))/2+y0;
	corner_wgd_point[2].x = a-3*wg_w/4+(wg_w/2)/2+x0;
	corner_wgd_point[2].y = -(wg_l-(b-(a-wg_w)))/2-wg_w-b-(wg_l-(b-(a-wg_w)))/2+y0;
	corner_wgd_point[3].x = a-3*wg_w/4-(wg_w/2)/2+x0;
	corner_wgd_point[3].y = -(wg_l-(b-(a-wg_w)))/2-wg_w-b-(wg_l-(b-(a-wg_w)))/2+y0;
	
	if( Assigned(corner_file ) )
	{
		if(corner_upcell)
		{
			corner_up = LPolygon_New(corner_upcell, LLayer_Find(corner_file, "Rib130"), corner_up_point, 102);
		}
		if(corner_downcell)
		{
			corner_down = LPolygon_New(corner_downcell, LLayer_Find(corner_file, "Rib130"), corner_down_point, 102);	
		}
		if(corner_addcell)
		{
			corner_add = LPolygon_New(corner_addcell, LLayer_Find(corner_file, "Rib130"), corner_add_point, 4);	
		}
		if(corner_cell)
		{
			LInstance_New_Ex99(corner_cell,corner_upcell,corner_up_transform,corner_up_repeat_cnt,corner_up_delta);
			LInstance_New_Ex99(corner_cell,corner_downcell,corner_down_transform,corner_down_repeat_cnt,corner_down_delta);
			LInstance_New_Ex99(corner_cell,corner_addcell,corner_add_transform,corner_add_repeat_cnt,corner_add_delta);
			//corner_add = LPolygon_New(corner_cell, LLayer_Find(corner_file, "Rib130"), corner_add_point, 4);
			corner_wga = LPolygon_New(corner_cell, LLayer_Find(corner_file, "Rib130"),corner_wga_point,4);
			corner_wgb = LPolygon_New(corner_cell, LLayer_Find(corner_file, "Rib130"),corner_wgb_point,4);
			corner_wgc = LPolygon_New(corner_cell, LLayer_Find(corner_file, "Rib130"),corner_wgc_point,4);
			corner_wgd = LPolygon_New(corner_cell, LLayer_Find(corner_file, "Rib130"),corner_wgd_point,4);
		}
		
	}
}

	void corner_layout_register(void)
{
	LMacro_Register("corner_layout","main");
}

}
	
	corner_layout_register();	