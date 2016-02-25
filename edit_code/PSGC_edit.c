//module ring
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"
 double center_x,center_y,x,y,pi,CR;
 double WG_W,L,R,Etch_W,space,start,end,gap,n,A,a,Radius,hole_psgc_R,hole_psgc_P,T_width,T_length,x2,y2,hole_psgc_D,shift; 
 
 int i,j;
//    main()
void PSGC(LFile file,LCell cell)
 {
	
    pi=3.1415926;//Բ����
	WG_W=500;//�������
    Radius=20000;//�����뾶

//�༭������õ��Ӻ����Ĳ���
 hole_psgc_P=480;//���Ӿ�������
 hole_psgc_D=360;//���Ӿ���ֱ��
 shift=100*1000;//X�����Y����λ����
 center_x=shift;//X�����Y����λ����
 center_y=shift;//X�����Y����λ����
 T_width=12*1000;//���Ӿ�������߳�
 T_length=300*1000;//Taper����
//�����Ӻ���
 //WG_X_circle();//�����Ӻ���
     WG_X_circle(
		 file,
		 cell,
		 center_x,
		 center_y,
		 space,
		 T_width,
		 T_length,
		 x,
		 y,
		 hole_psgc_P,
		 hole_psgc_D,
		 shift
	);
//��ת45�Ⱥ󣬻�45����������
  center_x=shift+Radius;
  center_y=shift+T_length+T_width/2;
  y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
  start=225;
  end=270;
//  bend_psgc();
  bend_psgc(
		file,
		cell,
		 center_x,
		 center_y,
		 Radius,
		 start,
		 end,
		 space
		);



//��ת45�Ⱥ󣬻�45����������
  center_x=shift+T_length+T_width/2;
  center_y=shift+Radius;
  y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
  start=90;
  end=135;
 // bend_psgc();
  bend_psgc(
		file,
	  cell,
		 center_x,
		 center_y,
		 Radius,
		 start,
		 end,
		 space
		);
  
//��ת45�Ⱥ󣬻���ƫ���դ
  center_x=shift+Radius*(1-sqrt(2)/2);
  center_y=shift+T_width/2+T_length+Radius*sqrt(2)/2;
    y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
//  right49005_psgc();
	 right49005_psgc(
		 file,
		 cell,
		 center_x,
		 center_y,
		 space
		);

//��ת45�Ⱥ󣬻���ƫ���դ
  center_x=shift+T_width/2+T_length+Radius*sqrt(2)/2;
  center_y=shift+Radius*(1-sqrt(2)/2);
    y2=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
  x2=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
  center_y=y2;
  center_x=x2;
//  right49005_psgc();
  right49005_psgc(
		file,
		cell,
		 center_x,
		 center_y,
		 space
		);
}
 
 
 
 
 

//PSGC�Ӻ���
    WG_X_circle(
		LFile file,
		LCell cell,
		double center_x,
		double center_y,
		double space,
		double T_width,
		double T_length,
		double x,
		double y,
		double hole_psgc_P,
		double hole_psgc_D,
		double shift
	)
	{   
	double taper_x,taper_y,w,scalefactor,grating_width_2,x1,y1;              
	double G_x,G_y,WG_width;                         
	taper_x=center_x;
	taper_y=center_y;
	w=space;
	scalefactor=1000;
	WG_width=400;

	int i,j;


	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  


	//�������Ӿ����դ��������ߵ�taper
	Points [0].x=taper_x-T_width/2;
	Points [0].y=taper_y-T_width/2;
	Points [1].x=taper_x-T_width/2;
	Points [1].y=taper_y+T_width/2;
	Points [2].x=taper_x-WG_width/2;
	Points [2].y=taper_y+T_width/2+T_length;
	Points [3].x=taper_x+WG_width/2;
	Points [3].y=taper_y+T_width/2+T_length;
    Points [4].x=taper_x+T_width/2;
	Points [4].y=taper_x+T_width/2;
	Points [5].x=taper_x+T_width/2+T_length;
	Points [5].y=taper_y+WG_width/2;
    Points [6].x=taper_x+T_width/2+T_length;
	Points [6].y=taper_y-WG_width/2;
	Points [7].x=taper_x+T_width/2;
	Points [7].y=taper_y-T_width/2;
	//����任��������ת
    for (i=0;i<=7;i++)
    {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

    }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 8);

   //////////////////////////////
   //�ȹ��Ӿ��������Դ�һ�㣨ÿ�ߴ�1um��������������
	Points [0].x=taper_x-T_width/2-1000;
	Points [0].y=taper_y-T_width/2-1000;
	Points [1].x=taper_x-T_width/2-1000;
	Points [1].y=taper_y+T_width/2+1000;
	
    Points [2].x=taper_x+T_width/2+1000;
	Points [2].y=taper_x+T_width/2+1000;

	Points [3].x=taper_x+T_width/2+1000;
	Points [3].y=taper_y-T_width/2-1000;
	//����仯����ת��
        for (i=0;i<=3;i++)
   {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

   }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);
   ///////////////////////////////
   //�ȹ��Ӿ��������Դ�ÿ�ߴ�1um��
	Points [0].x=taper_x-T_width/2-1000;
	Points [0].y=taper_y-T_width/2-1000;
	Points [1].x=taper_x-T_width/2-1000;
	Points [1].y=taper_y+T_width/2+1000;
	
    Points [2].x=taper_x+T_width/2+1000;
	Points [2].y=taper_x+T_width/2+1000;

	Points [3].x=taper_x+T_width/2+1000;
	Points [3].y=taper_y-T_width/2-1000;
	//����任��ѡ��)
        for (i=0;i<=3;i++)
   {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

   }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);
   //////////////////
   //�ȹ��Ӿ����������һ�㣨2um���� pad
   	Points [0].x=taper_x-T_width/2-2000;
	Points [0].y=taper_y-T_width/2-2000;
	Points [1].x=taper_x-T_width/2-2000;
	Points [1].y=taper_y+T_width/2+2000;
	
    Points [2].x=taper_x+T_width/2+2000;
	Points [2].y=taper_x+T_width/2+2000;

	Points [3].x=taper_x+T_width/2+2000;
	Points [3].y=taper_y-T_width/2-2000;
	//����任����ת��
        for (i=0;i<=3;i++)
   {

    y1=Points [i].x*sqrt(2)/2-Points [i].y*sqrt(2)/2;
	x1=Points [i].x*sqrt(2)/2+Points [i].y*sqrt(2)/2;
	
	Points [i].y=y1+y;
	Points [i].x=x1+x;

   }
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);
	/////////////////////////hole_psgcs
	//�����Ӿ���(���У����У�
   for(i=-floor(T_width/2/hole_psgc_P)+1;i<=floor(T_width/2/hole_psgc_P)-1;i++)
   for(j=-floor(T_width/2/hole_psgc_P)+1;j<=floor(T_width/2/hole_psgc_P)-1;j++)

	  {center_x=i*hole_psgc_P+shift;
		center_y=j*hole_psgc_P+shift;

   {

    y1=center_x*sqrt(2)/2-center_y*sqrt(2)/2;
	x1=center_x*sqrt(2)/2+center_y*sqrt(2)/2;
	
    center_y=y1;
    center_x=x1;

   }
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  

    tParams.ptCenter.x=center_x;
	tParams.ptCenter.y=center_y;

	tParams.nInnerRadius=0;
	tParams.nOuterRadius=hole_psgc_D/2;
	tParams.dStartAngle = 0;
	tParams.dStopAngle = 360;
	LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "PhC" ), &tParams); 

	  }	
	}
//��ƫ���դ�Ӻ���
    right49005_psgc(
		LFile file,
		LCell cell,
		double center_x,
		double center_y,
		double space
		)
	{
	double taper_x,taper_y,w,scalefactor,grating_width_2;              
	double G_x,G_y,WG_width,G_L;                         
	taper_x=center_x;
	taper_y=center_y;
	w=space;
	scalefactor=1000;
	WG_width=400;
	G_L=2000;
	grating_width_2=10000;

	int i,j;


	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  


	//��դ���taper+����
	Points [0].x=taper_x;
	Points [0].y=taper_y+WG_width/2;
	Points [1].x=taper_x;
	Points [1].y=taper_y-WG_width/2;
	Points [2].x=taper_x+400*scalefactor;
	Points [2].y=taper_y-5*scalefactor;
	Points [3].x=taper_x+400*scalefactor+G_L;
	Points [3].y=taper_y-5*scalefactor;//��
    Points [4].x=taper_x+400*scalefactor+G_L;
	Points [4].y=taper_y+5*scalefactor;
	Points [5].x=taper_x+400*scalefactor;
	Points [5].y=taper_y+5*scalefactor;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 6);


	Points [0].x=taper_x+400*scalefactor;		
	Points [0].y=taper_y+5*scalefactor+2000;
	Points [1].x=taper_x+400*scalefactor+16000;
	Points [1].y=taper_y+5*scalefactor+2000;
	Points [2].x=taper_x+400*scalefactor+16000;
	Points [2].y=taper_y-5*scalefactor-2000;
	Points [3].x=taper_x+400*scalefactor;		
	Points [3].y=taper_y-5*scalefactor-2000;


	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);

	G_x=taper_x+400*scalefactor+G_L;//����դ25��
	G_y=taper_y;
	for(j=0;j<25;j++)//����դ
	{
	LBox_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ) ,G_x, G_y+grating_width_2/2, G_x+0.49*0.5*scalefactor, G_y-grating_width_2/2);	//����һ����դ
	G_x+=0.49*scalefactor;	//����դ����x����ƽ��
	}	//ѭ����21����դ
		

	//��դ�Ҷ˿���
	Points [0].x=taper_x+400*scalefactor+25*490+2000;
	Points [0].y=taper_y-5*scalefactor;
	Points [1].x=taper_x+400*scalefactor+25*490+5000+2000;
	Points [1].y=taper_y-5*scalefactor;//��
    Points [2].x=taper_x+400*scalefactor+25*490+5000+2000;
	Points [2].y=taper_y+5*scalefactor;
	Points [3].x=taper_x+400*scalefactor+25*490+2000;
	Points [3].y=taper_y+5*scalefactor;
	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);

	Points [0].x=taper_x+400*scalefactor+1000;		
	Points [0].y=taper_y+5*scalefactor+2000-1000;
	Points [1].x=taper_x+400*scalefactor+16000-1000;
	Points [1].y=taper_y+5*scalefactor+2000-1000;
	Points [2].x=taper_x+400*scalefactor+16000-1000;
	Points [2].y=taper_y-5*scalefactor-2000+1000;
	Points [3].x=taper_x+400*scalefactor+1000;		
	Points [3].y=taper_y-5*scalefactor-2000+1000;


	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);


	Points [0].x=taper_x+400*scalefactor+1000;		
	Points [0].y=taper_y+5*scalefactor+2000-1000;
	Points [1].x=taper_x+400*scalefactor+16000-1000;
	Points [1].y=taper_y+5*scalefactor+2000-1000;
	Points [2].x=taper_x+400*scalefactor+16000-1000;
	Points [2].y=taper_y-5*scalefactor-2000+1000;
	Points [3].x=taper_x+400*scalefactor+1000;		
	Points [3].y=taper_y-5*scalefactor-2000+1000;


	LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);
	}	
//���������Ӻ���
    bend_psgc(
		LFile file,
		LCell cell,
		double center_x,
		double center_y,
		double Radius,
		double start,
		double end,
		double space
		)
    {
	double taper_x,taper_y,w,scalefactor,grating_width_2;              
	double G_x,G_y,WG_width,G_L;                         


	w=space;
	scalefactor=1000;
	WG_width=400;
	

	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  

    tParams.ptCenter.x=center_x;
	tParams.ptCenter.y=center_y;

	tParams.nInnerRadius=Radius-WG_width/2;
	tParams.nOuterRadius=Radius+WG_width/2;
	tParams.dStartAngle = start;
	tParams.dStopAngle = end;
	LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams); 
    }


hole_psgc(
	LFile file,
	LCell cell,
	double space,
	double center_x,
	double center_y,
	double Radius,
	double start,
	double end
	)
    {
	double taper_x,taper_y,w,scalefactor,grating_width_2;              
	double G_x,G_y,WG_width,G_L;                         


	w=space;
	scalefactor=1000;
	WG_width=500;
	

	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  

    tParams.ptCenter.x=center_x;
	tParams.ptCenter.y=center_y;

	tParams.nInnerRadius=0;
	tParams.nOuterRadius=Radius;
	tParams.dStartAngle = start;
	tParams.dStopAngle = end;
	LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), &tParams); 
    }

straight_psgc(
		LFile file,
		LCell cell,
		double space,
		double center_x,
		double center_y,
		double WG_W
		)
    {
	LPoint       Points [ 1002 ];
	LObject      Torus1;
//	LCell        Cell_Draw   = LCell_GetVisible( );
//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LCell        Cell_Draw   = cell;
	LFile        File_Draw   = file;
	LPoint       Translation = LCursor_GetPosition ( ); 
	LTorusParams tParams;  
	LBox_New ( Cell_Draw, LLayer_Find( File_Draw, "Bar220" ) ,center_x-5*1000,center_y+WG_W/2+space,center_x+5*1000,center_y+WG_W/2);	
    LBox_New ( Cell_Draw, LLayer_Find( File_Draw, "Bar220" ) ,center_x-5*1000,center_y-(WG_W/2+space),center_x+5*1000,center_y-WG_W/2);	
    }



/*void  ring (void)
	{
		LMacro_Register("ring", "main");
	}
}
ring();*/