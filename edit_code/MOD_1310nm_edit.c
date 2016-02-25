
//module rib_module
//{
#include <stdlib.h>
#include <math.h>
#include "ldata.h"

//	main()
	void MOD_1310nm(LFile file,LCell cell)
	{
		double	Scalefactor;
		long		P,i,j,m,n,k;
		double	device_center_x, device_center_y, device_L, device_interval, dicing_space;	

		double	MMI_L,taper_L, MMI_W, taper_W;
		double	WG_W,WG_short_L, WG_vertical_L, WG_MZI_L,WG_below_MZI_L, WG_asy1_L;
		double	WG_connect_L1,WG_connect_L2,WG_connect_L3,WG_connect_L4,WG_connect_L5,WG_connect_L6,WG_connect_L7,WG_connect_L8;

		double	big_taper_pic_L, big_taper_pic_W, big_WG_L, big_WG_W;
		double	grating_L,grating_P;
		double	doping_L, doping_W, doping_D, doping_delta_D, doping_heavy_D, doping_P, doping_rate, i_W;
		double   slab_radius, slab_W;

		double	via_length, via2_length, via_TiN_length;

		double	WG_start_x, WG_start_y, WG_stop_x, WG_stop_y,taper_start_x,taper_start_y,taper_stop_x,taper_stop_y;
		double	MMI_start_x, MMI_start_y, MMI_stop_x, MMI_stop_y;
		double	winding_center_x, winding_center_y, winding_R, winding_asy_R, angle_start, angle_stop;

		double	WG_outside_L;

		double	metal_signal_W, metal_gap, metal_ground_W,metal_ground_sub, metal_pad_L,metal_pad_W,metal_taper_L;
		double   theta, pi;
		double 	pad_contact_W;
	    double	TiN_L, TiN_W, TiN_pad_contact_L, TiN_pad_contact_W;

	
	/* Parameter Setting */
		 Scalefactor=1.0E3;
		
		// device_center_x=0.0E0*Scalefactor;
		// device_center_y=0.0E0*Scalefactor;	
		 device_center_x=(-2000+400)*Scalefactor; // 设置原点为器件的中心
		 //device_center_x=0*Scalefactor; // 设置原点为器件的中心
		 device_center_y=0.0E0-50*Scalefactor;	// 设置原点为器件的中心
 
	/*	 device_L = 1000.0E0*Scalefactor;    */

         MMI_L=4.40E0*Scalefactor;               
         MMI_W=2.0E0*Scalefactor;               
	     taper_L=4.5E0*Scalefactor;            
         taper_W=0.8E0*Scalefactor;             

		 WG_W = 0.425E0*Scalefactor;             
	     WG_short_L=2E0*Scalefactor;         
         WG_MZI_L=3150.0E0*Scalefactor;        
         WG_below_MZI_L=3080.0E0*Scalefactor;   
         winding_R=20.0E0*Scalefactor;       


         winding_asy_R=15.0E0*Scalefactor;       
         WG_asy1_L=7.876E0*Scalefactor;        

	     big_taper_pic_L=300.0E0*Scalefactor;      
         big_taper_pic_W=12E0*Scalefactor;         
	     big_WG_L=10.0E0*Scalefactor;        
         big_WG_W=12E0*Scalefactor;          
		 grating_L=12.0E0*Scalefactor;       
		 grating_P=0.49E0*Scalefactor;       

         WG_connect_L1=1.0E0*Scalefactor;             
         //WG_connect_L2=150.0E0*Scalefactor;          
		 WG_connect_L2=130.0E0*Scalefactor;            		 
         WG_connect_L3=350.0E0*Scalefactor;              
         WG_connect_L4=10.0E0*Scalefactor;             
         WG_connect_L5=1.0E0*Scalefactor;              
         //WG_connect_L6=150.0E0*Scalefactor; 
		 WG_connect_L6=130.0E0*Scalefactor; 		 
         WG_connect_L7=350.0E0*Scalefactor;              
         WG_connect_L8=10.0E0*Scalefactor;            

         slab_radius=50.0E0*Scalefactor;     
         slab_W=30.0E0*Scalefactor;         

		 doping_L=3000.0E0*Scalefactor;        
		 doping_W=14.0E0*Scalefactor;        
		 doping_D=50.0E0*Scalefactor;        
		 doping_delta_D=0.00E0*Scalefactor;        
		 doping_heavy_D=0.7E0*Scalefactor;       
		 i_W=0.0E0*Scalefactor;               
		 doping_P=12.0E0*Scalefactor;       
		 doping_rate=0.917;        

		 via_length=3.0E0*Scalefactor;        
		 via2_length=5.0E0*Scalefactor;        

		 pi=3.1415926;                        

        metal_signal_W=10E0*Scalefactor;       
        metal_gap=5E0*Scalefactor;               
        metal_ground_W=190E0*Scalefactor;       
        metal_ground_sub=90E0*Scalefactor;        
        metal_taper_L=150E0*Scalefactor;       
		metal_pad_L=100E0*Scalefactor;           
		metal_pad_W=100E0*Scalefactor;           

		pad_contact_W=90E0*Scalefactor;        

        WG_vertical_L=(300.0E0*Scalefactor-4*winding_R-2*WG_vertical_L-0.5*MMI_W-metal_gap-metal_signal_W)/2;       

		TiN_W=10.6*Scalefactor;              
		TiN_pad_contact_L=7E0*Scalefactor;        
		TiN_pad_contact_W=TiN_W-3*Scalefactor;       




		LPoint       Points [ 1002 ];
		LObject      Torus1;
	//	LCell        Cell_Draw   = LCell_GetVisible( );
//		LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LCell		 Cell_Draw=cell;
		LFile		 File_Draw=file;
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

	    /********************************************************************/
	/*if(LLayer_Find (File_Draw, "Rib130") == NULL)
         {	LDialog_AlertBox("There is no Rib130 layer.\nMake sure Rib130 is in the layer map!");
			return;
		 }*/
	
 		
   /* positive MMI*/

        /* MMI 多模干涉区*/
			MMI_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L;
			MMI_start_y=device_center_y-winding_R+MMI_W/4;				
			MMI_stop_x=device_center_x-winding_R-WG_short_L-taper_L;
			//MMI_Waveguide();
			MMI_Waveguide(
						file,
						cell,
						 MMI_start_x,
						 MMI_start_y,
						 MMI_stop_x,
						 MMI_W
							);

        /* input taper */
			taper_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L;
			taper_start_y=device_center_y-winding_R-MMI_W/4+WG_W/2;				
			taper_stop_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L; 
			taper_stop_y=device_center_y-winding_R-MMI_W/4+taper_W/2;    
            //input_taper();
			input_taper(
							file,
							cell,
							 taper_start_x,
							 taper_start_y,
							 taper_stop_x,
							 taper_stop_y,
							 WG_W,
							 taper_W
							);

        /* input waveguide */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L;
			WG_start_y=device_center_y-winding_R-MMI_W/4+WG_W/2;				
			WG_stop_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L;   
			//Straight_Waveguide();
			Straight_Waveguide(
							file,
							cell,								
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

        /* output taper*/
			taper_start_x=device_center_x-winding_R-WG_short_L-taper_L;
			taper_start_y=device_center_y-winding_R+taper_W/2;				
			taper_stop_x=device_center_x-winding_R-WG_short_L; 
			taper_stop_y=device_center_y-winding_R+WG_W/2;    
            //output_taper();	
			output_taper(
						file,
							cell,
							taper_start_x,
							taper_start_y,
							taper_stop_x,
							taper_stop_y,
							WG_W,
							taper_W
							);
			
			taper_start_y=device_center_y-winding_R-MMI_W/2+taper_W/2;				 
			taper_stop_y=device_center_y-winding_R-MMI_W/2+WG_W/2;    
            //output_taper();
			output_taper(
						file,
							cell,
							taper_start_x,
							taper_start_y,
							taper_stop_x,
							taper_stop_y,
							WG_W,
							taper_W
							);

        /* output waveguide  */
			WG_start_x=device_center_x-winding_R-WG_short_L;
			WG_start_y=device_center_y-winding_R+WG_W/2;				
			WG_stop_x=device_center_x-winding_R;     
			//Straight_Waveguide();
				Straight_Waveguide(
							file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

			WG_start_y=device_center_y-winding_R-MMI_W/2+WG_W/2;				    				
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

        /* top winding */
			winding_center_x=device_center_x-winding_R;
			winding_center_y=device_center_y;
            angle_start=270;
            angle_stop=360;
            //winding();
			 winding(
				 		file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

			WG_start_x=device_center_x-WG_W/2;
			WG_start_y=device_center_y;				
			WG_stop_y=device_center_y+WG_vertical_L;     
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								 WG_start_x,
								 WG_start_y,
								 WG_stop_y,
								 WG_W
									);

			winding_center_x=device_center_x+winding_R;
			winding_center_y=device_center_y+WG_vertical_L;
            angle_start=90;
            angle_stop=180;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* below winding */
			winding_center_x=device_center_x-winding_R;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R;
            angle_start=0;
            angle_stop=90;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

			WG_start_x=device_center_x-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L;				
			WG_stop_y=device_center_y-winding_R-MMI_W/2-winding_R;     
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

			winding_center_x=device_center_x+winding_R;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L;
            angle_start=180;
            angle_stop=270;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

       /* top MZI  waveguide  */
			WG_start_x=device_center_x+winding_R;
			WG_start_y=device_center_y+WG_vertical_L+winding_R+WG_W/2;				
			WG_stop_x=device_center_x+winding_R+WG_MZI_L;     
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

       /* below MZI  waveguide  */
			WG_start_x=device_center_x+winding_R;
			WG_start_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+WG_W/2;				
			WG_stop_x=device_center_x+winding_R+WG_below_MZI_L;     
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

       /* Asymettric MZI part */
			winding_center_x=device_center_x+winding_R+WG_below_MZI_L;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+winding_asy_R;
            angle_start=270;
            angle_stop=360;
            //winding_asy();
			 winding_asy(
				 		file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_asy_R,
						WG_W,
						angle_start,
						angle_stop
							);

			WG_start_x=device_center_x+winding_R+WG_below_MZI_L+winding_asy_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+winding_asy_R;				
			WG_stop_y=WG_start_y+WG_asy1_L;     
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

			winding_center_x=device_center_x+winding_R+WG_below_MZI_L+winding_asy_R*2;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+winding_asy_R+WG_asy1_L;
            angle_start=0;
            angle_stop=180;
            //winding_asy();
			winding_asy(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_asy_R,
						WG_W,
						angle_start,
						angle_stop
							);

			WG_start_x=device_center_x+winding_R+WG_below_MZI_L+3*winding_asy_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+winding_asy_R;				
			WG_stop_y=WG_start_y+WG_asy1_L;     
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

			winding_center_x=device_center_x+winding_R+WG_below_MZI_L+4*winding_asy_R;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+winding_asy_R;
            angle_start=180;
            angle_stop=270;
            //winding_asy();
			winding_asy(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_asy_R,
						WG_W,
						angle_start,
						angle_stop
							);

			WG_start_x=device_center_x+winding_R+WG_below_MZI_L+4*winding_asy_R;
			WG_start_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+WG_W/2;					
			WG_stop_x=device_center_x+winding_R+WG_MZI_L;     
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

    /* output MMI*/
        /* top winding */
			winding_center_x=device_center_x+winding_R+WG_MZI_L;
			winding_center_y=device_center_y+WG_vertical_L;
            angle_start=0;
            angle_stop=90;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R-WG_W/2;
			WG_start_y=device_center_y;				
			WG_stop_y=device_center_y+WG_vertical_L;    
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

			winding_center_x=device_center_x+winding_R+WG_MZI_L+winding_R*2;
			winding_center_y=device_center_y;
            angle_start=180;
            angle_stop=270;
            //winding();
			 winding(
				 		file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* below winding */

			winding_center_x=device_center_x+winding_R+WG_MZI_L;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L;
            angle_start=270;
            angle_stop=360;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L;				
			WG_stop_y=device_center_y-winding_R-MMI_W/2-winding_R;     
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

			winding_center_x=device_center_x+winding_R+WG_MZI_L+winding_R*2;
			winding_center_y=device_center_y-winding_R-MMI_W/2-winding_R;
            angle_start=90;
            angle_stop=180;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* input waveguide  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2;
			WG_start_y=device_center_y-winding_R+WG_W/2;				
			WG_stop_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L;    
			//Straight_Waveguide();	
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);
			

			WG_start_y=device_center_y-winding_R-MMI_W/2+WG_W/2;				    				
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

        /* input taper*/
			taper_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L;  
			taper_start_y=device_center_y-winding_R+WG_W/2;				
			taper_stop_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L;  
			taper_stop_y=device_center_y-winding_R+taper_W/2;    
            //input_taper();		
			input_taper(
						file,
							cell,
							 taper_start_x,
							 taper_start_y,
							 taper_stop_x,
							 taper_stop_y,
							 WG_W,
							 taper_W
							);
			
			taper_start_y=device_center_y-winding_R-MMI_W/2+WG_W/2;				 
			taper_stop_y=device_center_y-winding_R-MMI_W/2+taper_W/2;    
            //input_taper();	
			input_taper(
						file,
							cell,
							 taper_start_x,
							 taper_start_y,
							 taper_stop_x,
							 taper_stop_y,
							 WG_W,
							 taper_W
							);

        /* MMI*/
			MMI_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L; 
			MMI_start_y=device_center_y-winding_R+MMI_W/4;				
			MMI_stop_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L; 
			//MMI_Waveguide();
			MMI_Waveguide(
						file,
							cell,
						 MMI_start_x,
						 MMI_start_y,
						 MMI_stop_x,
						 MMI_W
							);

        /* output taper*/
			taper_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L;
			taper_start_y=device_center_y-winding_R-MMI_W/4+taper_W/2;				
			taper_stop_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L;
			taper_stop_y=device_center_y-winding_R-MMI_W/4+WG_W/2;	  
            //output_taper();	
			output_taper(
						file,
							cell,
							taper_start_x,
							taper_start_y,
							taper_stop_x,
							taper_stop_y,
							WG_W,
							taper_W
							);
			
        /* output waveguide  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L;
			WG_start_y=device_center_y-winding_R-MMI_W/4+WG_W/2;				
			WG_stop_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L;  
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);
			

    /* input grating and taper */
        /* 第一段连接直波导  */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1;
			WG_start_y=device_center_y-winding_R-MMI_W/4+WG_W/2;				
			WG_stop_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L;   
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

        /* 第一段弯曲波导 */
			winding_center_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1;
			winding_center_y=device_center_y-winding_R-MMI_W/4+winding_R;
            angle_start=180;
            angle_stop=270;
           //winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);
        /* 第二段连接直波导  */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1-winding_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2;						
			WG_stop_y=WG_start_y-WG_connect_L2;    
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

        /* 第二段弯曲波导  */
			winding_center_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1;
			winding_center_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2;
            angle_start=90;
            angle_stop=180;
          //  winding();
		   winding(
			   		file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);
        /* 第三段连接直波导  */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1;
			WG_start_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+winding_R+WG_W/2;				
			WG_stop_x=WG_start_x+WG_connect_L3;   
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

        /* 第三段弯曲波导  */
			winding_center_x= device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3;
			winding_center_y= device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R;
            angle_start=270;
            angle_stop=360;
          //  winding();
		   winding(
			   		file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* 第四段连接直波导  */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R;						
			WG_stop_y=WG_start_y+WG_connect_L4;    
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

        /*left big  taper */
			taper_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-big_taper_pic_W/2;
			taper_start_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L;				
			taper_stop_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R+WG_W/2;
			taper_stop_y=taper_start_y-big_taper_pic_L;    
           // big_taper_pic();
		   big_taper_pic(
			   		file,
							cell,
						taper_start_x,
						taper_start_y,
						big_taper_pic_W,
						taper_stop_x,
						taper_stop_y,
						 WG_W
						);

        /* left big waveguide  (和taper链接的部分)  */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-big_WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L+big_WG_L;		
			//big_Waveguide();
			big_Waveguide(
						file,
							cell,
						WG_start_x,
						WG_start_y,
						big_WG_W,
						big_WG_L
							);

		 /*   left Grating  */
		   for(i=1;i<=30;i++)
		   {
		   LPoint       Points [1002];
		   LObject      Torus1;
	//	   LCell        Cell_Draw   = LCell_GetVisible( );
	//	   LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		   LPoint       Translation = LCursor_GetPosition ( ); 
		   LTorusParams tParams;  	
			
		   Points [0].x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-grating_L/2;
		   Points [0].y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L+big_WG_L+i*grating_P;	
		   Points [1].x=Points [0].x+grating_L;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-grating_P/2;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);     
		  }

        /* left big waveguide  (最外围)  */
			WG_start_x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-big_WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L+big_WG_L+30.5*grating_P+big_WG_L;		
			//big_Waveguide();
			big_Waveguide(
						file,
							cell,
						WG_start_x,
						WG_start_y,
						big_WG_W,
						big_WG_L
							);

   /* output grating and taper */

        /* 第一段连接直波导  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L;
			WG_start_y=device_center_y-winding_R-MMI_W/4+WG_W/2;				
			WG_stop_x=WG_start_x+WG_connect_L5;  
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

		/* 第一段弯曲波导  */
			winding_center_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5;
			winding_center_y=device_center_y-winding_R-MMI_W/4-winding_R;
            angle_start=0;
            angle_stop=90;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* 第二段连接直波导  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5+winding_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4-winding_R;						
			WG_stop_y=WG_start_y-WG_connect_L6;    
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

		/* 第二段弯曲波导  */
			winding_center_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5;
			winding_center_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6;
            angle_start=270;
            angle_stop=360;
           // winding();
		    winding(
						file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* 第三段连接直波导  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7;
			WG_start_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-winding_R+WG_W/2;				
			WG_stop_x=WG_start_x+WG_connect_L7;  
			//Straight_Waveguide();
			Straight_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_x,
								WG_W
									);

		/* 第三段弯曲波导  */
			winding_center_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7;
			winding_center_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-winding_R-winding_R;	
            angle_start=90;
            angle_stop=180;
            //winding();
			 winding(
				 		file,
							cell,
						winding_center_x,
						winding_center_y,
						winding_R,
						WG_W,
						angle_start,
						angle_stop
						);

        /* 第四段连接直波导  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-winding_R-winding_R;					
			WG_stop_y=WG_start_y-WG_connect_L8;    
			//vertical_Waveguide();
			vertical_Waveguide(
						file,
							cell,
								WG_start_x,
								WG_start_y,
								WG_stop_y,
								WG_W
									);

        /*right big  taper */
			taper_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-WG_W/2;
			taper_start_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8;				
			taper_stop_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R+big_WG_W/2;
			taper_stop_y=taper_start_y-big_taper_pic_L;    
           // big_taper_pic2();
		   big_taper_pic2(
			   		file,
							cell,
						taper_start_x,
						taper_start_y,
						big_taper_pic_W,
						taper_stop_x,
						taper_stop_y,
						WG_W
							);

        /* right big waveguide  (和taper链接的部分)  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-big_WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8-big_taper_pic_L;	
			//big_Waveguide();
			big_Waveguide(
						file,
							cell,
						WG_start_x,
						WG_start_y,
						big_WG_W,
						big_WG_L
							);

		/*   right Grating  */
		   for(i=1;i<=30;i++)
		   {
		   LPoint       Points [1002];
		   LObject      Torus1;
	//	   LCell        Cell_Draw   = LCell_GetVisible( );
	//	   LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		   LPoint       Translation = LCursor_GetPosition ( ); 
		   LTorusParams tParams;  	
			
		   Points [0].x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-grating_L/2;
		   Points [0].y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8-big_taper_pic_L-big_WG_L-(i-0.5)*grating_P;	
		   Points [1].x=Points [0].x+grating_L;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-grating_P/2;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);     
		  }

        /* right big waveguide  (最外围)  */
			WG_start_x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-big_WG_W/2;
			WG_start_y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8-big_taper_pic_L-big_WG_L-(30+0.5)*grating_P;		
			//big_Waveguide();
			big_Waveguide(
						file,
							cell,
						WG_start_x,
						WG_start_y,
						big_WG_W,
						big_WG_L
							);


   /*  光栅保护层 Grating70层*/
     /*   left Grating  */
			
	 	   Points [0].x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-grating_L/2-0.2*Scalefactor;
		   Points [0].y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L+big_WG_L+30.5*grating_P+1*Scalefactor;	
		   Points [1].x=Points [0].x+grating_L+0.4*Scalefactor;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-30.5*grating_P-2*Scalefactor;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4); 

     /*   right Grating  */
		   Points [0].x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-grating_L/2-0.2*Scalefactor;
		   Points [0].y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8-big_taper_pic_L-big_WG_L+1*Scalefactor;	
		   Points [1].x=Points [0].x+grating_L+0.4*Scalefactor;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-30.5*grating_P-2*Scalefactor;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Grating70" ), Points, 4);  

  /*  光栅保护层   slab层 , 其尺寸和Grating70层的尺寸一样*/
     /*   左光栅上的slab层  */
	 	   Points [0].x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-grating_L/2-0.2*Scalefactor;
		   Points [0].y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L+big_WG_L+30.5*grating_P+1*Scalefactor;		
		   Points [1].x=Points [0].x+grating_L+0.4*Scalefactor;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-30.5*grating_P-2*Scalefactor;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4); 

     /*   右光栅上的slab层 */
		   Points [0].x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-grating_L/2-0.2*Scalefactor;
		   Points [0].y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8-big_taper_pic_L-big_WG_L+1*Scalefactor;	
		   Points [1].x=Points [0].x+grating_L+0.4*Scalefactor;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-30.5*grating_P-2*Scalefactor;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4); 

  /*  pad层， 盖在光栅上面, 尺寸需要大些 */
     /*   左光栅上的pad层  */
	 	   Points [0].x=device_center_x-winding_R-WG_short_L-taper_L-MMI_L-taper_L-WG_short_L-WG_connect_L1+WG_connect_L3+winding_R-grating_L/2-10*Scalefactor;
		   Points [0].y=device_center_y-winding_R-MMI_W/4+winding_R+WG_connect_L2+2*winding_R+WG_connect_L4+big_taper_pic_L+big_WG_L+30.5*grating_P+10*Scalefactor;	
		   Points [1].x=Points [0].x+grating_L+20*Scalefactor;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-30.5*grating_P-20*Scalefactor;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4); 

     /*   右光栅上的pad层 */
		   Points [0].x=device_center_x+winding_R+WG_MZI_L+winding_R*2+WG_short_L+taper_L+MMI_L+taper_L+WG_short_L+WG_connect_L5-WG_connect_L7-winding_R-grating_L/2-10*Scalefactor;
		   Points [0].y=device_center_y-winding_R-MMI_W/4-winding_R-WG_connect_L6-2*winding_R-WG_connect_L8-big_taper_pic_L-big_WG_L+10*Scalefactor;	
		   Points [1].x=Points [0].x+grating_L+20*Scalefactor;
		   Points [1].y=Points [0].y;
		   Points [2].x=Points [1].x;
		   Points [2].y= Points [1].y-30.5*grating_P-20*Scalefactor;
		   Points [3].x=Points [0].x;
		   Points [3].y=Points [2].y;
		   LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);   



 /*  平板区  */
	  /*  平板区 MZI 上臂  */
		for(i=0;i<=79;i++)
			{
			theta=pi/3+pi/6/79*i;
			Points [i].x=device_center_x+winding_R+doping_D-2*Scalefactor-slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y+WG_vertical_L+winding_R-0.1*Scalefactor-slab_radius+slab_radius*sin(theta);
			}
		for(i=80;i<=159;i++)
			{
			theta=pi*3/2+pi/6/79*(i-80);
			Points [i].x=device_center_x+winding_R+doping_D-2*Scalefactor-slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y+WG_vertical_L+winding_R+0.1*Scalefactor+slab_radius+slab_radius*sin(theta);
			}
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 160);
	
		Points [0].x = device_center_x+winding_R+doping_D-2*Scalefactor;
		Points [0].y = device_center_y+WG_vertical_L+winding_R+slab_W/2;
		Points [1].x = device_center_x+winding_R+doping_D+doping_L+2*Scalefactor;
		Points [1].y = Points [0].y;
		Points [2].x = Points [1].x;
		Points [2].y = Points [1].y -slab_W;	
		Points [3].x = Points [0].x;
		Points [3].y = Points [0].y -slab_W;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);

		for(i=0;i<=79;i++)
			{
			theta=pi*4/3+pi/6/79*i;
			Points [i].x=device_center_x+winding_R+doping_D+doping_L+2*Scalefactor+slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y+WG_vertical_L+winding_R+0.1*Scalefactor+slab_radius+slab_radius*sin(theta);
			}
		for(i=80;i<=159;i++)
			{
			theta=pi/2+pi/6/79*(i-80);
			Points [i].x=device_center_x+winding_R+doping_D+doping_L+2*Scalefactor+slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y+WG_vertical_L+winding_R-0.1*Scalefactor-slab_radius+slab_radius*sin(theta);
			}
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 160);

	  /*  平板区 MZI 下臂  */
		for(i=0;i<=79;i++)
			{
			theta=pi/3+pi/6/79*i;
			Points [i].x=device_center_x+winding_R+doping_D-2*Scalefactor-slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-0.1*Scalefactor-slab_radius+slab_radius*sin(theta);
			}
		for(i=80;i<=159;i++)
			{
			theta=pi*3/2+pi/6/79*(i-80);
			Points [i].x=device_center_x+winding_R+doping_D-2*Scalefactor-slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+0.1*Scalefactor+slab_radius+slab_radius*sin(theta);
			}
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 160);
	
		Points [0].x = device_center_x+winding_R+doping_D-2*Scalefactor;
		Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+slab_W/2;
		Points [1].x = device_center_x+winding_R+doping_D+doping_L+2*Scalefactor;
		Points [1].y = Points [0].y;
		Points [2].x = Points [1].x;
		Points [2].y = Points [1].y -slab_W;	
		Points [3].x = Points [0].x;
		Points [3].y = Points [0].y -slab_W;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 4);

		for(i=0;i<=79;i++)
			{
			theta=pi*4/3+pi/6/79*i;
			Points [i].x=device_center_x+winding_R+doping_D+doping_L+2*Scalefactor+slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+0.1*Scalefactor+slab_radius+slab_radius*sin(theta);
			}
		for(i=80;i<=159;i++)
			{
			theta=pi/2+pi/6/79*(i-80);
			Points [i].x=device_center_x+winding_R+doping_D+doping_L+2*Scalefactor+slab_radius/2+slab_radius*cos(theta);
			Points [i].y= device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-0.1*Scalefactor-slab_radius+slab_radius*sin(theta);
			}
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Slab90" ), Points, 160);


	/*   doping  */ 
			n=doping_L/doping_P;
			for(j=1;j<=n;j++)
			{
		 /*   P doping of top MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+doping_delta_D-i_W/2;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - doping_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "P-type doping" ), Points, 4);

		 /*   P++ doping of top MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y+WG_vertical_L+winding_R-WG_W/2-doping_heavy_D;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W+doping_heavy_D;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "P++ doping" ), Points, 4);

		 /*   N doping of top MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+doping_delta_D+i_W/2+doping_W;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - doping_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "N-type doping" ), Points, 4);

		 /*   N++ doping of top MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+WG_W/2+doping_W;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W+doping_heavy_D;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "N++ doping" ), Points, 4);

		 /*   P doping of below MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-doping_delta_D+i_W/2+doping_W;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - doping_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "P-type doping" ), Points, 4);

		 /*   P++ doping of below MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+WG_W/2+doping_W;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W+doping_heavy_D;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "P++ doping" ), Points, 4);

		 /*   N doping of below MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-doping_delta_D-i_W/2;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - doping_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "N-type doping" ), Points, 4);

		 /*   N++ doping of below MZI  */ 
			Points [0].x = device_center_x+winding_R+doping_D+(j-1)*doping_P;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-WG_W/2-doping_heavy_D;
			Points [1].x = Points [0].x+doping_P*doping_rate;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - doping_W+doping_heavy_D;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "N++ doping" ), Points, 4);
			}


	   /*   via hole  */ 
		   for(i=1;i<=2;i++)
			{
			n=doping_L/via_length/2;
			for(j=1;j<=n;j++)
			{

		 /*  via hole of P , top MZI  */
			Points [0].x = device_center_x+winding_R+doping_D+1.0*Scalefactor+(j-1)*2*via_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R-metal_gap/2- 0.4*Scalefactor-(i-1)*2.0*via_length;
			Points [1].x = Points [0].x+via_length;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - via_length;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole" ), Points, 4);

		/*  via hole of N , top MZI  */
			Points [0].x = device_center_x+winding_R+doping_D+1.0*Scalefactor+(j-1)*2*via_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+0.4*Scalefactor+via_length+(i-1)*2.0*via_length;
			Points [1].x = Points [0].x+via_length;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - via_length;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole" ), Points, 4);

		 /*  via hole of P , below  MZI  */
			Points [0].x = device_center_x+winding_R+doping_D+1.0*Scalefactor+(j-1)*2*via_length;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+metal_gap/2+0.4*Scalefactor+via_length+(i-1)*2.0*via_length;
			Points [1].x = Points [0].x+via_length;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - via_length;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole" ), Points, 4);

		 /*  via hole of N , below  MZI  */
			Points [0].x = device_center_x+winding_R+doping_D+1.0*Scalefactor+(j-1)*2*via_length;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-0.4*Scalefactor-(i-1)*2.0*via_length;
			Points [1].x = Points [0].x+via_length;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - via_length;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole" ), Points, 4);
		   }
		   }


 /*   metal1    */ 
		 /*   metal1  上臂  信号线  */ 
			Points [0].x = device_center_x+winding_R;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W;
			Points [1].x = device_center_x+winding_R+WG_MZI_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_signal_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_signal_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  信号线细条  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_signal_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  信号线左边taper  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  信号线左边pad  */ 

			Points [0].x =  device_center_x+winding_R+WG_MZI_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_signal_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  信号线右边taper  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  信号线右边pad  */ 

	/*   metal1  上臂  外部地线  */ 
			Points [0].x = device_center_x+winding_R;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W-metal_ground_sub;
			Points [1].x = device_center_x+winding_R+WG_MZI_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - (metal_ground_W-metal_ground_sub);	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  地线（调制部分）  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = Points [0].y-metal_ground_sub;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - (metal_ground_W-metal_ground_sub);	
			Points [3].x = Points [0].x;
			Points [3].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W); 
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  外地线左边taper  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W;   
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);   
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  外地线左边pad  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L-1.5*metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W;   
			Points [1].x =  Points [0].x+1.5*metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);   
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  外地线左边pad延长部分（用于共地）  */ 

			Points [0].x =  device_center_x+winding_R+WG_MZI_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W-metal_ground_sub;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = Points [0].y+metal_ground_sub;
			Points [2].x = Points [1].x;
			Points [2].y =device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W); 
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - (metal_ground_W-metal_ground_sub);
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  外地线右边taper  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W); 
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  外地线右边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W+metal_gap+metal_ground_W;
			Points [1].x =  Points [0].x+1.5*metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W); 
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂  外地线右边pad延长部分 （用于共地） */ 


	/*   metal1  下臂  信号线  */ 
			Points [0].x = device_center_x+winding_R;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2;
			Points [1].x = device_center_x+winding_R+WG_MZI_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_signal_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_signal_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  信号线细条  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_signal_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  信号线左边taper  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  信号线左边pad  */ 

			Points [0].x =  device_center_x+winding_R+WG_MZI_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_signal_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  信号线右边taper  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  信号线右边pad  */

		 /*   metal1  下臂  外部地线  */ 
			Points [0].x = device_center_x+winding_R;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap;
			Points [1].x = device_center_x+winding_R+WG_MZI_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - (metal_ground_W-metal_ground_sub);	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  地线（调制部分）  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - (metal_ground_W-metal_ground_sub);	
			Points [3].x = Points [0].x;
			Points [3].y = Points [1].y- metal_ground_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  外地线左边taper  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap-metal_ground_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  外地线左边pad  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L-1.5*metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+1.5*metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap-metal_ground_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  外地线左边pad延长部分（共地用）  */ 

			Points [0].x =  device_center_x+winding_R+WG_MZI_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap;
			Points [1].x = Points [0].x+metal_taper_L;
			Points [1].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap-metal_ground_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y+metal_ground_sub;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  外地线右边taper  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap-metal_ground_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  外地线右边pad  */

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+1.5*metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W-metal_gap-metal_ground_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  外地线右边pad延长部分 共地用  */

		 /*   metal1  里面的地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x = Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x+metal_taper_L;
			Points [2].y = device_center_y+WG_vertical_L+winding_R-metal_gap/2;
			Points [3].x = Points [2].x+WG_MZI_L;
			Points [3].y =Points [2].y;
			Points [4].x =Points [3].x+metal_taper_L;
			Points [4].y =Points [1].y;
			Points [5].x =Points [4].x+metal_pad_L;
			Points [5].y =Points [0].y;
			Points [6].x =Points [5].x;
			Points [6].y =device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);
			Points [7].x =Points [4].x;
			Points [7].y =Points [6].y;
			Points [8].x =Points [3].x;
			Points [8].y =device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R+metal_gap/2;
			Points [9].x =Points [2].x;
			Points [9].y =Points [8].y;
			Points [10].x =Points [1].x;
			Points [10].y =Points [6].y;
			Points [11].x =Points [0].x;
			Points [11].y =Points [6].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 12);  

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L-1.5*metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+1.5*metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  里面地线左边pad延长部分（共地用）  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+1.5*metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂  里面线右边pad延长部分 共地用  */

		 /*   metal1  共地的连接线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L-1.5*metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);   
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);  
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂外地线与里面地线  左边  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+1.5*metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);   
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);  
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  上臂外地线与里面地线  右边  */ 

			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L-1.5*metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);  
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);  
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂外地线与里面地线  左边  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+1.5*metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W); 
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Al" ), Points, 4);  /*   metal1  下臂外地线与里面地线  右边  */ 


 /*   Via hole 2层   上层电极与下层电极之间的通孔，比电极pad略小   */ 
		 m=(metal_pad_L-20*Scalefactor)/via2_length/2;
		  for(i=1;i<=m;i++)
			{

			n=(metal_pad_W-20*Scalefactor)/via2_length/2;
			/*    上臂  信号线左边pad  */ 
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2-10*Scalefactor-(j-1)*2*via2_length;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}
			/*    上臂  外地线左边pad  */ 
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+metal_pad_W-10*Scalefactor-(j-1)*2*via2_length;   
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}
			/*    下臂  信号线左边pad  */ 
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2-10*Scalefactor-(j-1)*2*via2_length;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}
			/*    下臂  外地线左边pad  */
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-10*Scalefactor-(j-1)*2*via2_length;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);   
			}
			/*   里面的地线左边pad  */
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-10*Scalefactor-(j-1)*2*via2_length;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}


			n=(metal_pad_W-40*Scalefactor)/via2_length/2;
			/*    上臂  信号线右边pad  */ 
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2-20*Scalefactor-(j-1)*2*via2_length;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}
			/*   上臂  外地线右边pad  */ 
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+metal_pad_W-20*Scalefactor-(j-1)*2*via2_length;  
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}

			/*    下臂  信号线右边pad  */
	    	for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2-20*Scalefactor-(j-1)*2*via2_length;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4);  
			}	
			
			/*     下臂  外地线右边pad  */
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-(j-1)*2*via2_length-20*Scalefactor;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4); 
			}
			/*     里面的地线右边pad  */
			for(j=1;j<=n;j++)
			{
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+10*Scalefactor+(i-1)*2*via2_length;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-(j-1)*2*via2_length-20*Scalefactor;
			Points [1].x=Points [0].x+via2_length;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-via2_length;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole 2" ), Points, 4); 
			}
			}





/*  metal 2 层  电极pad与第一层电极pad大小一致 */
		 /*  上臂  信号线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*   信号线左边pad  */  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  信号线右边pad  */ 

		/*    上臂  外部地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+metal_pad_W;      
			Points [1].x = Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);   
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  外地线左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+metal_pad_W;
			Points [1].x = Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W); 
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  外地线右边pad  */ 

	/*  下臂  信号线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*   信号线左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2;
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - metal_pad_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - metal_pad_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  信号线右边pad  */

	/*  下臂  外地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [0].y-metal_pad_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  外地线左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [0].y-metal_pad_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  外地线右边pad  */

		 /*   metal1  里面的地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*   左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W);
			Points [1].x =  Points [0].x+metal_pad_L;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W);
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Metal 2" ), Points, 4);  /*  右边pad  */

 /*   pad层    */ 
		 /*  上臂  信号线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y -pad_contact_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - pad_contact_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*   信号线左边pad  */  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - pad_contact_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y - pad_contact_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  信号线右边pad  */ 

		/*    上臂  外部地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+metal_pad_W/2+pad_contact_W/2;  
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - pad_contact_W;  
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  外地线左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+metal_pad_W/2+pad_contact_W/2;  
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - pad_contact_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  外地线右边pad  */ 

		/*  下臂  信号线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y - pad_contact_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y -pad_contact_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*   信号线左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y -pad_contact_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [0].y -pad_contact_W;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  信号线右边pad  */

		/*  下臂  外地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-metal_pad_L/2+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y -pad_contact_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  外地线左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-metal_pad_L/2+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y -pad_contact_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  外地线右边pad  */

		 /*   metal1  里面的地线  */ 
			Points [0].x = device_center_x+winding_R-metal_taper_L-metal_pad_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/4+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y -pad_contact_W;	
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*   左边pad  */ 

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/4+pad_contact_W/2;
			Points [1].x =  Points [0].x+pad_contact_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = Points [1].y -pad_contact_W;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y ;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Electrode pad" ), Points, 4);  /*  右边pad  */

	 /*  TiN层  负载电阻 */
		  /*  上臂  TiN  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+10*Scalefactor; 
			Points [1].x =  Points [0].x+TiN_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2-10*Scalefactor;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "TiN" ), Points, 4);  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2+10*Scalefactor; 
			Points [1].x =  Points [0].x+TiN_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-10*Scalefactor;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "TiN" ), Points, 4);  

		  /*  下臂  TiN  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+10*Scalefactor; 
			Points [1].x =  Points [0].x+TiN_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2-10*Scalefactor;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "TiN" ), Points, 4);  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2+10*Scalefactor; 
			Points [1].x =  Points [0].x+TiN_W;
			Points [1].y = Points [0].y;
			Points [2].x = Points [1].x;
			Points [2].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-10*Scalefactor;
			Points [3].x = Points [0].x;
			Points [3].y = Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "TiN" ), Points, 4);  

	   /*   Via hole_TiN  负载电阻的通孔 */ 

		 /*   Via hole_TiN   上臂  地线pad  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+8.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  

		 /*   Via hole_TiN   上臂  信号线pad  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2+metal_pad_W/2-1.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2+8.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  

		 /*   Via hole_TiN   中间地线pad  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y+WG_vertical_L+winding_R+metal_gap/2+metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-1.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2+(metal_gap/metal_signal_W*metal_pad_W)+8.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  

		 /*   Via hole_TiN   下臂信号线pad  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2+metal_pad_W/2-1.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  

			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2+8.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4); 

		 /*   Via hole_TiN   下臂外地线pad  */
			Points [0].x = device_center_x+winding_R+WG_MZI_L+metal_taper_L+metal_pad_L/2-TiN_pad_contact_W/2;
			Points [0].y = device_center_y-winding_R-MMI_W/2-winding_R-WG_vertical_L-winding_R-metal_gap/2-metal_signal_W/2-metal_pad_W/2-(metal_gap/metal_signal_W*metal_pad_W)-1.5*Scalefactor;
			Points [1].x=Points [0].x+TiN_pad_contact_W;
			Points [1].y=Points [0].y;
			Points [2].x=Points [1].x;
			Points [2].y=Points [1].y-TiN_pad_contact_L;
			Points [3].x=Points [0].x;
			Points [3].y=Points [2].y;
			LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Via hole_TiN" ), Points, 4);  












  




	}
/* End of main */











   /* start of MMI_Waveguide */
	void MMI_Waveguide(
						LFile File_Draw,
						LCell Cell_Draw,
						double MMI_start_x,
						double MMI_start_y,
						double MMI_stop_x,
						double MMI_W
							)
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = MMI_start_x;
		Points [0].y = MMI_start_y;
		Points [1].x = MMI_stop_x;
		Points [1].y = Points [0].y;
		Points [2].x = Points [1].x;
		Points [2].y = Points [1].y - MMI_W;	
		Points [3].x = Points [0].x;
		Points [3].y = Points [0].y - MMI_W;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	}	
	
	
   /* Start of Straight_Waveguide */
	    void Straight_Waveguide(
								LFile File_Draw,
								LCell Cell_Draw,
								double WG_start_x,
								double WG_start_y,
								double WG_stop_x,
								double WG_W
									)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = WG_start_x;
		Points [0].y = WG_start_y;
		Points [1].x = WG_stop_x;
		Points [1].y = Points [0].y;
		Points [2].x = Points [1].x;
		Points [2].y = Points [1].y - WG_W;	
		Points [3].x = Points [0].x;
		Points [3].y = Points [0].y - WG_W;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	    }	


 /* Start of vertical_Waveguide */
	    void vertical_Waveguide(
								LFile File_Draw,
								LCell Cell_Draw,
								double WG_start_x,
								double WG_start_y,
								double WG_stop_y,
								double WG_W
									)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = WG_start_x;
		Points [0].y = WG_start_y;
		Points [1].x = Points [0].x;
		Points [1].y = WG_stop_y;
		Points [2].x = Points [1].x+WG_W;
		Points [2].y = Points [1].y;	
		Points [3].x = Points [0].x+WG_W;
		Points [3].y = Points [0].y;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	    }	

  /* Start of input_taper*/
        void input_taper(
							LFile File_Draw,
							LCell Cell_Draw,
							double taper_start_x,
							double taper_start_y,
							double taper_stop_x,
							double taper_stop_y,
							double WG_W,
							double taper_W
							)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = taper_start_x;
		Points [0].y = taper_start_y;
		Points [1].x = taper_stop_x;
		Points [1].y = taper_stop_y;
		Points [2].x = Points [1].x;
		Points [2].y = Points [1].y-taper_W;	
		Points [3].x = Points [0].x;
		Points [3].y = Points [0].y-WG_W;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	    }

   /* Start of output_taper*/
        void output_taper(
							LFile File_Draw,
							LCell Cell_Draw,
							double taper_start_x,
							double taper_start_y,
							double taper_stop_x,
							double taper_stop_y,
							double WG_W,
							double taper_W
							)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = taper_start_x;
		Points [0].y = taper_start_y;
		Points [1].x = taper_stop_x;
		Points [1].y = taper_stop_y;
		Points [2].x = Points [1].x;
		Points [2].y = taper_stop_y-WG_W;	
		Points [3].x = Points [0].x;
		Points [3].y = taper_start_y-taper_W;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	    }




   /* Start of winding */
        void winding(
						LFile File_Draw,
						LCell Cell_Draw,
						double winding_center_x,
						double winding_center_y,
						double winding_R,
						double WG_W,
						double angle_start,
						double angle_stop
						)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		tParams.ptCenter.x = winding_center_x;
		tParams.ptCenter.y = winding_center_y;
		tParams.nInnerRadius = winding_R - WG_W/2;
		tParams.nOuterRadius = winding_R + WG_W/2;
		tParams.dStartAngle = angle_start;
		tParams.dStopAngle = angle_stop;
		LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams);    
	    }

	   /* Start of winding_asy */
        void winding_asy(
						LFile File_Draw,
						LCell Cell_Draw,
						double winding_center_x,
						double winding_center_y,
						double winding_asy_R,
						double WG_W,
						double angle_start,
						double angle_stop
							)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		tParams.ptCenter.x = winding_center_x;
		tParams.ptCenter.y = winding_center_y;
		tParams.nInnerRadius = winding_asy_R - WG_W/2;
		tParams.nOuterRadius = winding_asy_R + WG_W/2;
		tParams.dStartAngle = angle_start;
		tParams.dStopAngle = angle_stop;
		LTorus_CreateNew(Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), &tParams);    
	    }

   /* start of left big_taper_pic*/
        void big_taper_pic(
						LFile File_Draw,
						LCell Cell_Draw,
						double taper_start_x,
						double taper_start_y,
						double big_taper_pic_W,
						double taper_stop_x,
						double taper_stop_y,
						double WG_W
						)
	    {
		LPoint       Points [ 1002 ];
		LObject      Torus1;
	//	LCell        Cell_Draw   = LCell_GetVisible( );
	//	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = taper_start_x;
		Points [0].y = taper_start_y;
		Points [1].x = taper_start_x+big_taper_pic_W;
		Points [1].y = Points [0].y;
		Points [2].x = taper_stop_x;
		Points [2].y = taper_stop_y;	
		Points [3].x = taper_stop_x-WG_W;
		Points [3].y = Points [2].y; 
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	    }


   /* start of right  big_taper_pic*/
        void big_taper_pic2(
						LFile File_Draw,
						LCell Cell_Draw,
						double taper_start_x,
						double taper_start_y,
						double big_taper_pic_W,
						double taper_stop_x,
						double taper_stop_y,
						double WG_W
							)
    	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = taper_start_x;
		Points [0].y = taper_start_y;
		Points [1].x = taper_start_x+WG_W;
		Points [1].y = Points [0].y;
		Points [2].x = taper_stop_x;
		Points [2].y = taper_stop_y;	
		Points [3].x = taper_stop_x-big_taper_pic_W;
		Points [3].y = Points [2].y ;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
    	}

   /* start of big_Waveguide */

	void big_Waveguide(
						LFile File_Draw,
						LCell Cell_Draw,
						double WG_start_x,
						double WG_start_y,
						double big_WG_W,
						double big_WG_L
							)
	{
		LPoint       Points [ 1002 ];
		LObject      Torus1;
		//LCell        Cell_Draw   = LCell_GetVisible( );
		//LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
		LPoint       Translation = LCursor_GetPosition ( ); 
		LTorusParams tParams;  

		Points [0].x = WG_start_x;
		Points [0].y = WG_start_y;
		Points [1].x = WG_start_x+big_WG_W;
		Points [1].y = Points [0].y;
		Points [2].x = Points [1].x;
		Points [2].y = Points [1].y - big_WG_L;	
		Points [3].x = Points [0].x;
		Points [3].y = Points [2].y;
		LPolygon_New ( Cell_Draw, LLayer_Find( File_Draw, "Rib130" ), Points, 4);
	}	












	/*void  rib_macro_register (void)
	{
		LMacro_Register("rib", "main");
	}
/* End of rib_macro_register */

//}
/* End of Module */
//rib_macro_register();