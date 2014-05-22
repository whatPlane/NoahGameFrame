// -------------------------------------------------------------------------
//    @FileName      :    NFCLoginNet_ServerModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCLoginNet_ServerModule
//    @Desc             :
// -------------------------------------------------------------------------

#ifndef _NFC_LOGINNET_CLIENT_MODULE_H_
#define _NFC_LOGINNET_CLIENT_MODULE_H_

//  the cause of sock'libariy, thenfore "NFCNet.h" much be included first.

#include "NFComm/NFPluginModule/NFIEventProcessModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFILoginLogicModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFILogicClassModule.h"
#include "NFComm/NFPluginModule/NFIElementInfoModule.h"
#include "NFComm/NFPluginModule/NFINetModule.h"
#include "NFComm/NFPluginModule/NFILoginNet_ServerModule.h"

class NFCLoginNet_ClientModule
    : public NFINetModule
{
public:
    NFCLoginNet_ClientModule(NFIPluginManager* p)
    {
		mnSocketFD = 0;
        pPluginManager = p;
    }


    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute(const float fLasFrametime, const float fStartedTime);

    virtual bool AfterInit();
	virtual bool BeforeShut();

	virtual void LogRecive(const char* str){}
	virtual void LogSend(const char* str){}

protected:
	int OnRecivePack(const NFIPacket& msg);
    int OnSocketEvent(const uint16_t nSockIndex, const NF_NET_EVENT eEvent);


protected:

    //////////////////////////////////////////////////////////////////////////
    int OnSelectServerEvent(const NFIDENTID& object, const int nEventID, const NFIValueList& var);

    int OnExitServerEvent(const NFIDENTID& object, const int nEventID, const NFIValueList& var);

    //////////////////////////////////////////////////////////////////////////

    int OnSelectServerResultProcess(const NFIPacket& msg);


	//////////////////////////////////////////////////////////////////////////

	int OnWorldInfoProcess(const NFIPacket& msg);

    //////////////////////////////////////////////////////////////////////////
    void Register();
    void UnRegister();

private:
	int mnSocketFD;

private:
    //world server container:-2
    int mnWorldContainerID;

	NFILoginLogicModule* m_pLoginLogicModule;
	NFILoginNet_ServerModule* m_pLoginNet_ServerModule;
	NFIEventProcessModule* m_pEventProcessModule;
    NFIElementInfoModule* m_pElementInfoModule;
	NFIKernelModule* m_pKernelModule;
    NFILogicClassModule* m_pLogicClassModule;
    NFILogModule* m_pLogModule;
};

#endif