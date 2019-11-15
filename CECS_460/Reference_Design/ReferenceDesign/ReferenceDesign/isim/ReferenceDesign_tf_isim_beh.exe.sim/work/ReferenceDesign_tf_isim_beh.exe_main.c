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
    xilinxcorelib_ver_m_00000000001358910285_3260388640_init();
    xilinxcorelib_ver_m_00000000001687936702_4083328711_init();
    xilinxcorelib_ver_m_00000000000277421008_4140168884_init();
    xilinxcorelib_ver_m_00000000001603977570_2989137351_init();
    work_m_00000000000403262735_2334805521_init();
    xilinxcorelib_ver_m_00000000001358910285_3845704976_init();
    xilinxcorelib_ver_m_00000000001687936702_0598770285_init();
    xilinxcorelib_ver_m_00000000000277421008_1981495916_init();
    xilinxcorelib_ver_m_00000000001603977570_2002810209_init();
    work_m_00000000000403262735_0148772410_init();
    work_m_00000000001847894695_0171423316_init();
    work_m_00000000003119859839_0233107250_init();
    work_m_00000000003873964078_2648976750_init();
    work_m_00000000001923676098_2423134424_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001923676098_2423134424");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
