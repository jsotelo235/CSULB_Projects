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
    work_m_00000000003832553662_3855036804_init();
    work_m_00000000003832553662_1632440243_init();
    work_m_00000000004063974672_1211724634_init();
    work_m_00000000002966292570_0618795724_init();
    work_m_00000000000388049276_1484779129_init();
    work_m_00000000003808734566_1606674845_init();
    work_m_00000000000143194887_2070724530_init();
    work_m_00000000004102546201_2012416834_init();
    work_m_00000000004252082594_2761901494_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004252082594_2761901494");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}