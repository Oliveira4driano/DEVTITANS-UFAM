#include "smartcarbosensor_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::smartcarbosenso {      // Entra no pacote devtitans::hello

void SmartcarbosensorClient::start(int argc, char **argv) {
    cout << "Cliente SmartCarboSensor!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-led, set-led, get-sensor, get-threshold, set-threshold" << endl;
        exit(1);
    }

    Smartlamp smartlamp;             // Classe da biblioteca Smartlamp

    // Comandos get-led e set-led
    if (!strcmp(argv[1], "get-led")) {
        cout << "Valor do Led: " << smartlamp.getLed() << endl;
    }
    else if (!strcmp(argv[1], "set-led")) {
        int ledValue = atoi(argv[2]);
        if (smartlamp.setLed(ledValue))
            cout << "Valor do Led setado para " << ledValue << endl;
        else
            cout << "Erro ao setar valor do Led para " << ledValue << endl;
    }

    // Comando get-sensor
    else if (!strcmp(argv[1], "get-sensor")) {
        cout << "Valor Sensor atual: " << smartlamp.getSensor() << endl;
    }

    // Comandos get-threshold e set-threshold
    else if (!strcmp(argv[1], "get-threshold")) {
        cout << "Valor do Threshold: " << smartlamp.getThreshold() << endl;
    }
    else if (!strcmp(argv[1], "set-threshold")) {
        int thresholdValue = atoi(argv[2]);
        if (smartlamp.setThreshold(thresholdValue))
            cout << "Valor do Threshold setado para " << thresholdValue << endl;
        else
            cout << "Erro ao setar valor do Threshold para " << thresholdValue << endl;
    }

    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devtitans::smartcarbosensor; // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main(int argc, char **argv) {
    SmartlampClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}