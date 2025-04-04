#ifndef _DTI_STATISTIC_H
#define _DTI_STATISTIC_H
/******************************************************************************

         Copyright (c) 2016 - 2019 Intel Corporation
         Copyright (c) 2015 - 2016 Lantiq Beteiligungs-GmbH & Co. KG
         Copyright (c) 2012 - 2014 Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#include "dti_agent_interface.h"
#include "dti_statistic_if.h"

#ifdef __cplusplus
   extern "C" {
#endif

/* for testing */
/* #define DTI_INCLUDE_CORE_STATISTICS		1 */

#ifndef DTI_INCLUDE_CORE_STATISTICS
#	define DTI_INCLUDE_CORE_STATISTICS	0
#endif


/* DTI Statistic - new Connection Request Increment */
#if (DTI_INCLUDE_CORE_STATISTICS == 1)

#	define DTI_LISTEN_THR_PID_SET(P_AGT_CTX, PID) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_agent.pid = (int)(PID);} while (0)
#	define DTI_LISTEN_THR_TID_SET(P_AGT_CTX, TID) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_agent.tid = (int)(TID);} while (0)
#	define DTI_LISTEN_THR_OP_RUN_INC(P_AGT_CTX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_agent.op_run_count++;} while (0)

#	define DTI_CONN_REQ_LISTEN_REQ_INC(P_AGT_CTX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_agent.conn_req_listen_req_cnt++;} while (0)
#	define DTI_CONN_REQ_LISTEN_REQ_DONE_INC(P_AGT_CTX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_agent.conn_req_listen_req_done_cnt++;} while (0)
#	define DTI_CONN_REQ_LISTEN_REQ_FAIL_INC(P_AGT_CTX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_agent.conn_req_listen_req_fail_cnt++;} while (0)

#	define DTI_WORKER_THR_PID_SET(P_AGT_CTX, WORKER_IDX, PID) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].pid = (int)(PID);} while (0)
#	define DTI_WORKER_THR_TID_SET(P_AGT_CTX, WORKER_IDX, TID) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].tid = (int)(TID);} while (0)
#	define DTI_WORKER_THR_OP_RUN_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].op_run_count++;} while (0)
#	define DTI_WORKER_THR_OP_IDLE_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].op_idle_count++;} while (0)

#	define DTI_WORKER_THR_START_REQ_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].start_req_cnt++;} while (0)
#	define DTI_WORKER_THR_START_DONE_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].start_done_cnt++;} while (0)
#	define DTI_WORKER_THR_START_FAIL_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].start_fail_cnt++;} while (0)
#	define DTI_WORKER_THR_CLOSE_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_worker_thr[WORKER_IDX].close_cnt++;} while (0)

#	define DTI_CONN_PACKET_IN_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_in_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_ERR_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_err_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_DISC_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_discard_cnt++;} while (0)

#	define DTI_CONN_PACKET_IN_CNTRL_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_in_cntrl_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_CNTRL_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_cntrl_cnt++;} while (0)
#	define DTI_CONN_PACKET_IN_UNKNOWN_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_in_unknown_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_UNKNOWN_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_unknown_cnt++;} while (0)
#	define DTI_CONN_PACKET_IN_CLI_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_in_cli_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_CLI_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_cli_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_CLI_EVT_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_cli_evt_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_CLI_EVT_DISC_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_cli_evt_discard_cnt++;} while (0)
#	define DTI_CONN_PACKET_IN_CLI_CNTRL_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_in_cli_cntrl_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_CLI_CNTRL_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_cli_cntrl_cnt++;} while (0)
#	define DTI_CONN_PACKET_IN_DEV_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_in_dev_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_DEV_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_dev_cnt++;} while (0)
#	define DTI_CONN_PACKET_OUT_DEV_EVT_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].packet_out_dev_evt_cnt++;} while (0)

#	define DTI_CONN_RESYNC_TRIGGER_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].conn_resync_cnt++;} while (0)
#	define DTI_CONN_RESYNC_TRIGGER_DONE_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].conn_resync_done_cnt++;} while (0)

#	define DTI_CONN_CLOSE_TRIGGER_INC(P_AGT_CTX, WORKER_IDX) \
		/*lint -e{717}*/ \
		do{(P_AGT_CTX)->stat_conn[WORKER_IDX].conn_close_cnt++;} while (0)

#else

#	define DTI_LISTEN_THR_PID_SET(P_AGT_CTX, PID)
#	define DTI_LISTEN_THR_TID_SET(P_AGT_CTX, TID)
#	define DTI_LISTEN_THR_OP_RUN_INC(P_AGT_CTX)

#	define DTI_CONN_REQ_LISTEN_REQ_INC(P_AGT_CTX)
#	define DTI_CONN_REQ_LISTEN_REQ_DONE_INC(P_AGT_CTX)
#	define DTI_CONN_REQ_LISTEN_REQ_FAIL_INC(P_AGT_CTX)

#	define DTI_WORKER_THR_PID_SET(P_AGT_CTX, WORKER_IDX, PID)
#	define DTI_WORKER_THR_TID_SET(P_AGT_CTX, WORKER_IDX, TID)
#	define DTI_WORKER_THR_OP_RUN_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_WORKER_THR_OP_IDLE_INC(P_AGT_CTX, WORKER_IDX)

#	define DTI_WORKER_THR_START_REQ_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_WORKER_THR_START_DONE_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_WORKER_THR_START_FAIL_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_WORKER_THR_CLOSE_INC(P_AGT_CTX, WORKER_IDX)

#	define DTI_CONN_PACKET_IN_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_ERR_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_DISC_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_IN_CNTRL_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_CNTRL_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_IN_UNKNOWN_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_UNKNOWN_INC(P_AGT_CTX, WORKER_IDX)

#	define DTI_CONN_PACKET_IN_CLI_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_CLI_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_CLI_EVT_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_CLI_EVT_DISC_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_IN_CLI_CNTRL_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_CLI_CNTRL_INC(P_AGT_CTX, WORKER_IDX)

#	define DTI_CONN_PACKET_IN_DEV_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_DEV_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_PACKET_OUT_DEV_EVT_INC(P_AGT_CTX, WORKER_IDX)

#	define DTI_CONN_RESYNC_TRIGGER_INC(P_AGT_CTX, WORKER_IDX)
#	define DTI_CONN_CLOSE_TRIGGER_INC(P_AGT_CTX, WORKER_IDX)

#endif


#ifdef __cplusplus
}
#endif

#endif /* _DTI_STATISTIC_H */



