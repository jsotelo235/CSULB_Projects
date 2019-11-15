/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000010388478_1069848932_init();
    work_m_00000000001602512142_1771966286_init();
    work_m_00000000004195451041_1637954243_init();
    work_m_00000000003747724559_2847150690_init();
    work_m_00000000003979396308_3057664381_init();
    work_m_00000000000743586220_0479987476_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000743586220_0479987476");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
