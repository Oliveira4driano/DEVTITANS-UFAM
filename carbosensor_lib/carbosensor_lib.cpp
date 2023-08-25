#include "carbosensor_lib.h"

using namespace std;                                   // Permite usar string, ifstream diretamente ao invés de std::string
using namespace android::base;                         // Permite usar GetBoolProperty ao invés de android::base::GetBoolProperty

namespace devtitans::carbosensor {                       // Entra no pacote devtitans::smartlamp

int Carbosensor::connect() {
    char dirPath[] = "/sys/kernel/carbosensor";
    struct stat dirStat;
    if (stat(dirPath, &dirStat) == 0)
        if (S_ISDIR(dirStat.st_mode))
            return 1;                                  // Se o diretório existir, retorna 1

    // Diretório não existe, vamos verificar a propriedade
    // bool allowSimulated = GetBoolProperty("devtitans.smartcarbo.allow_simulated", true);
    // if (!allowSimulated)
    //     return 0;                                      // Dispositivo não encontrado
    //else
    return 0; //2                                      // Usando valores simulados
}

int Carbosensor::readFileValue(string file) {
    int connected = this->connect();

    // if (connected == 2) {                               // Usando valores simulados
    //     if (file == "led")
    //         return this->simLedValue;
    //     else if (file == "threshold")
    //         return this->simThresholdValue;
    //     else {
    //         // "ldr" (luminosity): Gera um número aleatório entre 0 e 100
    //         random_device dev;
    //         mt19937 rng(dev());
    //         uniform_int_distribution<mt19937::result_type> dist100(0,100);
    //         return (int) dist100(rng);
    //     }
    // }

    if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
        int value;
        string filename = string("/sys/kernel/carbosensor/") + file;
        ifstream file(filename);                        // Abre o arquivo do módulo do kernel

        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
            file >> value;                              // Lê um inteiro do arquivo
            file.close();
            return value;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return -1;
}

// bool Smartcarbo::writeFileValue(string file, int value) {
//     int connected = this->connect();

//     if (connected == 2) {                                // Usando valores simulados
//         if (file == "led") {
//             this->simLedValue = value;
//             return true;
//         }
//         else if (file == "threshold") {
//             this->simThresholdValue = value;
//             return true;
//         }
//     }

//     else if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
//         string filename = string("/sys/kernel/smartcarbo/") + file;
//         ofstream file(filename, ios::trunc);            // Abre o arquivo limpando o seu conteúdo

//         if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
//             file << value;                              // Escreve o ledValue no arquivo
//             file.close();
//             return true;
//         }
//     }

//     // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
//     return false;
// }

// int Smartcarbo::getLed() {
//     return this->readFileValue("led");
// }

// bool Smartcarbo::setLed(int ledValue) {
//     return this->writeFileValue("led", ledValue);
// }

int Carbosensor::getSensor() {
    return this->readFileValue("mq7");
}

// int Smartcarbo::getThreshold() {
//     return this->readFileValue("threshold");
// }

// bool Smartcarbo::setThreshold(int thresholdValue) {
//     return this->writeFileValue("threshold", thresholdValue);
// }

} // namespace
