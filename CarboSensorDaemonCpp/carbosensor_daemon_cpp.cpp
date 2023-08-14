#include "carbosensor_daemon_cpp.h"

using namespace std;                    // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::carbosensor {            // Entra no pacote devtitans::hello

void CarboSensorDaemonCpp::startDaemon() {    // Implementa o método printHello da classe HelloCpp
    ALOG(LOG_INFO, "DevTITANS", "Daemon CarboSensor iniciando ...");

    int count = 1;
    while (true) {

        // Implemente aqui o serviço

        ALOG(LOG_INFO, "DevTITANS", "Daemon CarboSensor World loop %d", count++);
        sleep(5);
    }

    // Nunca deve chegar aqui ...
}

} // namespace


using namespace devtitans::carbosensor;       // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main() {
    CarboSensorDaemonCpp daemon;              // Variável carbo, da classe HelloCpp, do pacote devtitans::hello
    daemon.startDaemon();               // Executa o método printHello
    // Nunca deve chegar aqui ...
    return 0;
}