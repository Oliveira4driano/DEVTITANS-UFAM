#include "carbosensor_service.h"

using namespace aidl::devtitans::carbosensor;                // SmartlampService (smartlamp_service.cpp)
using namespace std;                                       // std::shared_ptr
using namespace ndk;                                       // ndk::SharedRefBase

int main() {
    LOG(INFO) << "Iniciando Carbosensor AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<CarboSensorService> carbosensor_service = SharedRefBase::make<CarboSensorService>();

    const string instance = std::string() + ICarbosensor::descriptor + "/default";   // devtitans.carbosensor.ICarbosensor/default
    binder_status_t status = AServiceManager_addService(carbosensor_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "Carbosensor AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;                                   // Não deve chegar nunca aqui
}