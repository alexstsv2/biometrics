#ifndef FINGERPRINT_DAEMON_CALLBACK_PROXY_H_
#define FINGERPRINT_DAEMON_CALLBACK_PROXY_H_

#include <hardware/fingerprint.h>
#include "IFingerprintDaemonCallback.h"

namespace android {

class FingerprintDaemonCallbackProxy: public BnFingerprintDaemonCallback {
public:
    virtual status_t onEnrollResult(int64_t devId, int32_t fpId, int32_t gpId, int32_t rem);
    virtual status_t onAcquired(int64_t devId, int32_t acquiredInfo);
    virtual status_t onAuthenticated(int64_t devId, int32_t fingerId, int32_t groupId);
    virtual status_t onError(int64_t devId, int32_t error);
    virtual status_t onRemoved(int64_t devId, int32_t fingerId, int32_t groupId);
    virtual status_t onEnumerate(int64_t devId, const int32_t fpId, const int32_t gpId,
            int32_t rem);
    FingerprintDaemonCallbackProxy();
    virtual ~FingerprintDaemonCallbackProxy();

    static void setDevice(fingerprint_device_t *device) {
        mDevice = device;
    }
private:
    static fingerprint_device_t *mDevice;
};

}

#endif // FINGERPRINT_DAEMON_CALLBACK_PROXY_H_
