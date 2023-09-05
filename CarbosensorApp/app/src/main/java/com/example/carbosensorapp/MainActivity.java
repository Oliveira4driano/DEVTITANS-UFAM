package com.example.carbosensorapp;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlarmManager;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.graphics.drawable.Drawable;
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
    private TextView textStatus, textSensor, textContador ;
    private CarbosensorManager manager;

    private ImageView imgCirculo;
    private Drawable drawableGreen, drawableRed;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textStatus   =  findViewById(R.id.textStatus);                      // Acessa os componentes da tela
        textSensor   =  findViewById(R.id.textSensor);
        botaoIniciar =  findViewById(R.id.buttonIniciar);
        manager      =  CarbosensorManager.getInstance();
        imgCirculo   =  (ImageView) findViewById(R.id.imgCirculo);
        drawableGreen= getResources().getDrawable(R.drawable.circulo_vermelho);
        drawableRed= getResources().getDrawable(R.drawable.circulo);

        textStatus.setText("Aguardando ...");
        textStatus.setTextColor(Color.parseColor("#c47e00"));

    }
        public void iniciaThead(View view){
            pararExecucao = false;
            SensorRunnable runnable = new SensorRunnable();
            new Thread( runnable ).start();
           // imgCirculo.setColorFilter(Color.RED, PorterDuff.Mode.LIGHTEN);
    }
    public void pararThread(View view){
        pararExecucao = true;
        textStatus.setText("Parado");
    }
    public void updateAll(View view) {
        Log.d(TAG, "Atualizando dados do dispositivo ...");

        try {

            int status = manager.connect();                                  // Executa o método connect via manager
            if (status == 0) {
                textStatus.setText("Desconectado");
                textStatus.setTextColor(Color.parseColor("#73312f"));

            }

            else if (status == 1) {
             //   int ppm = 400 / 1023;
                int senMq7 = manager.getSensor();
                textStatus.setText("Conectado");
                textStatus.setTextColor(Color.parseColor("#6d790c"));
               // int co = ppm * senMq7;
                textSensor.setText(String.valueOf(senMq7));
                if(senMq7<4095) {
                    imgCirculo.setImageDrawable(drawableGreen);
                }else{
                    imgCirculo.setImageDrawable(drawableRed);
                }
//                if(senMq7 >=200){
//                    Toast.makeText(this, "Gás Perigoso Detectado!", Toast.LENGTH_LONG).show();
//                }

            }

        } catch (android.os.RemoteException e) {
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show();
            Log.e(TAG, "Erro atualizando dados:", e);
        }

    }

    //inner class
    class SensorRunnable implements Runnable {

        @Override
        public void run() {

            while (!pararExecucao){

                if(pararExecucao)
                    return;
             //   Log.d("Thread", "contador: " + i );
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        updateAll(null);
                    }
                });

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
        }
    }

}