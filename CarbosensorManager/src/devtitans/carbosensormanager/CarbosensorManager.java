package devtitans.carbosensormanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.carbosensor.ICarbosensor;                      // Criado pelo AIDL

public class CarbosensorManager {
    private static final String TAG = "DevTITANS.CarbosensorManager";
    private IBinder binder;
    private ICarbosensor service;

    private static CarbosensorManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada. 
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private CarbosensorManager() {
        Log.d(TAG, "Nova (única) instância do CarbosensorManager ...");

        binder = ServiceManager.getService("devtitans.carbosensor.ICarbosensor/default");
        if (binder != null) {
            service = ICarbosensor.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço Carbosensor acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço Carbosensor!");
        }
        else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um objeto.
    public static CarbosensorManager getInstance() {
        if (instance == null)
            instance = new CarbosensorManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    // public int getLed() throws RemoteException {
    //     Log.d(TAG, "Executando método getLed() ...");
    //     return service.getLed();
    // }

    // public boolean setLed(int ledValue) throws RemoteException {
    //     Log.d(TAG, "Executando método setLed(" + ledValue + ") ...");
    //     return service.setLed(ledValue);
    // }

    public int getSensor() throws RemoteException {
        Log.d(TAG, "Executando método getSensor() ...");
        return service.getSensor();
    }
}