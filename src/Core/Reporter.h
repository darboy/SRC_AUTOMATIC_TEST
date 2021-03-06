#ifndef _FW_REPORTER_H_
#define _FW_REPORTER_H_

#include "Task.h"
#include <stdint.h>
#include "Communication.h"
#include "Timer.h"
#include "socket.h"
#include "singleton.h"
#include <string.h>

class CReporter_base
{
public:
	CReporter_base(){}
	enum {TRANS_BUFF_LEN = 300};
	inline void setTimestampe()
	{
		BaseTimer::Instance()->getTime_ns(&timestamp_nsec_);
	}
	
	int upload(uint32_t len, uint8_t* ip, uint16_t port);
	int uploadRbk(uint32_t len);
//	int reply(uint32_t len);
	
protected:
	uint64_t timestamp_nsec_;
	static uint8_t transBuff_[TRANS_BUFF_LEN];

private: 
	static bool isInitialized_;
};


#endif
