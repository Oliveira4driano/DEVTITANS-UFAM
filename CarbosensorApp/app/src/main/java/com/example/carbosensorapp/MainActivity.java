package com.example.carbosensorapp;

import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.os.Bundle;
import android.os.Handler;
import android.os.RemoteException;
import android.text.TextWatcher;
import android.view.View;
import android.widget.TextView;
import android.util.Log;
import android.widget.*;

import devtitans.carbosensormanager.CarbosensorManager;                          // Biblioteca do Manager
public class MainActivity extends AppCompatActivity {
    private static final String TAG = "DevTITANS.CarbosensorApp";
    private Button botaoIniciar;
    private boolean pararExecucao = false;
    private TextView textStatus, textSensor;
    private CarbosensorManager manager;
    private int numero;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textStatus =    findViewById(R.id.textStatus);                      // Acessa os componentes da tela
        textSensor =    findViewById(R.id.textSensor);
        botaoIniciar =  findViewById(R.id.buttonIniciar);
        manager = CarbosensorManager.getInstance();
        textStatus.setText("Atualizando ...");
        textStatus.setTextColor(Color.parseColor("#c47e00"));

    }
    public void iniciaThead(View view){
            pararExecucao = false;
            //botaoIniciar.setText("Parar");
            SensorThread runable = new SensorThread();
            new Thread(runable).start();

    }
    public void pararThread(View view){
        pararExecucao = true;
        textStatus.setText("Parado");
    }
    public void updateAll(View view) {
        Log.d(TAG, "Atualizando dados do dispositivo ...");
        textStatus.setText("Atualizando ...");
        textStatus.setTextColor(Color.parseColor("#c47e00"));

        try {

            int status = manager.connect();                                  // Executa o método connect via manager
            if (status == 0) {
                textStatus.setText("Desconectado");
                textStatus.setTextColor(Color.parseColor("#73312f"));

            }
            else if (status == 1) {

                int senMq7 = manager.getSensor();
                textStatus.setText("Conectado");
                textStatus.setTextColor(Color.parseColor("#6d790c"));
                textSensor.setText(String.valueOf(senMq7));

            }

        } catch (android.os.RemoteException e) {
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show();
            Log.e(TAG, "Erro atualizando dados:", e);
        }

    }


    //inner class
    class SensorThread implements Runnable {

        @Override
        public void run() {
        //    for (int i = 0; i < 15; i++) {
                if(pararExecucao)
                    return;
          //      numero =i;
          //      Log.d("Thread","contador"+i);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                   //     textSensor.setText(String.valueOf(numero));
                        int status = 0;
                        try {
                            status = manager.connect();
                            int senMq7 = manager.getSensor();

                      //  if(status == 1) {


                            textStatus.setText("Conectado");
                            textStatus.setTextColor(Color.parseColor("#6d790c"));
                            textSensor.setText(String.valueOf(senMq7));

                       // }
                        } catch (RemoteException e) {
                            throw new RuntimeException(e);
                        }



                        try {
                            Thread.sleep(1000);
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }


                    }
                });

          //  }
        }
    }
}