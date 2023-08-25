#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/carbosensor/BnCarbosensor.h>            // Criado pelo AIDL automaticamente

#include "carbosensor_lib.h"                                   // Classe carbosensor (biblioteca)

using namespace devtitans::carbosensor;

namespace aidl::devtitans::carbosensor {

class CarboSensorService : public BnCarbosensor {
    public:
        ndk::ScopedAStatus connect(int32_t* _aidl_return) override;
        ndk::ScopedAStatus getSensor(int32_t* _aidl_return) override;

    private:
        Carbosensor carbosensor;                                 // Biblioteca implementada pelo Adriano
};

}

