#include "carbosensor_service.h"

namespace aidl::devtitans::carbosensor {
    ndk::ScopedAStatus CarboSensorService::connect(int32_t* _aidl_return) {
        *_aidl_return = this->carbosensor.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus CarboSensorService::getSensor(int32_t* _aidl_return) {
        *_aidl_return = this->carbosensor.getSensor();
        LOG(INFO) << "getSensor(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }
}
