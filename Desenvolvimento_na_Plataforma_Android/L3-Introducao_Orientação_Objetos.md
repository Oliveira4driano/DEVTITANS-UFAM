# Laboratório 3: Introdução à Orientação a Objetos
### Objetivo
Modelagem, implementação, compilação e execução de classes em java usando o Eclipse.
### Descrição
Neste trabalho, você implementará as classes necessárias para representar um computador.
Irá descrever atributos e implementar métodos e construtores com base em um diagrama de classes da UML.
Em seguida, objetos serão criados a partir das classes implementadas.
Nesta abstração, um computador é constituído de processador, memória e disco.
### Passos Iniciais
Inicie o Eclipse. Vá em "File" → "New" → "New Java Project". Nome do projeto: "Lab-IntroducaoPOO".
Na parte Module (parte de baixo da janela), desselecione "Create module-info.java file".
Nas questões a seguir, será pedido para criar diversas classes. Para isso, vá em "File" → "New" → "Class".
Deixe o campo "package" em branco.
O Eclipse compila automaticamente as classes sempre que você salva. Para executar e testar, basta ir em "Run" → "Run" (Ctrl+F11).
A saída e entrada do programa será feita através da aba "Console" do Eclipse.
Nota da questão 2.5 / 2.5
### Q1-Classe Processador
![processador](https://user-images.githubusercontent.com/33138839/231196953-eeca7d2b-4991-483e-ae18-e2bdc74e68e6.png)
Crie uma classe para representar um Processador de acordo com o diagrama de classe ao lado. Os atributos de um objeto da classe Processador poderão ser setados diretamente (e.g., proc1.marca="Intel") ou pelo método construtor. Use a técnica de encadeamento de construtores para criar os dois construtores da classe, semelhante ao feito em sala e mostrado nos slides. Implemente os métodos:
* getVelocidadeParalela: retorna um double contendo a multiplicação da velocidade do processador pela quantidade total de núcleos.
* getDescricao: retorna uma String contendo a descrição do processador de acordo com a linha a seguir:
Processador: marca=Intel, modelo=i7, velocidade=3.2GHz, numNucleos=8, velocidadeParalela=25.6GHz.
Para testar a classe, crie uma nova classe chamada ComputadorMain. Nesta classe, crie o método main, que será o ponto de partida do seu programa. No método main, crie um ou mais objetos da classe Processador e, em seguida, imprima o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe Processador. Não precisa submeter a classe ComputadorMain.
Dica:
Um número real em Java (e.g., "8.4") é, por padrão, do tipo double. Para escrever um número que seja do tipo double, deve-se usar um "f" no final (e.g., "8.4f").
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Processador.java" Solução correta!
Nota da questão 2.5 / 2.5
```
questao lab 3
public class Processador {
		String marca;
		String modelo;
		double velocidade;
		int numNucleos;
	public Processador() {
		super();
		// TODO Auto-generated constructor stub
	}
	public Processador(String marca,String modelo, double velocidade, int numNucleos) { 
		this.marca = marca;
		this.modelo = modelo;
		this.velocidade = velocidade;
		this.numNucleos = numNucleos;	
	}
	
	double getVelocidadeParalela() {
		return velocidade*numNucleos;
	}
	
	String getDescricao() {
	
		Processador.this.getVelocidadeParalela();
		String processador= "Processador: marca="+marca+", modelo="+modelo+", velocidade="+velocidade+"GHz, numNucleos="+numNucleos+", velocidadeParalela="+velocidade*numNucleos+"GHz.";
		return processador;
	}
		

}
```
### Q2-Classe Memoria

![memoria](https://user-images.githubusercontent.com/33138839/231196949-8c0b2273-79ef-4b8c-bbf4-8860e4efdadc.png)
De forma semelhante à questão anterior, implemente uma classe para representar a Memoria do computador de acordo com o diagrama de classe ao lado. Implemente os métodos:
* getTamanhoTotal: retorna um double contendo a multiplicação da quantidade pelo tamanho dos pentes de memória.
* getVelocidadeParalela: retorna um double contendo a multiplicação da quantidade pela velocidade dos pentes de memória.
* getDescricao: retorna uma String contendo a descrição da memória de acordo com a linha a seguir:
Memoria: marca=Kingston, tipo=DDR4, tamanho=8.0GB, velocidade=3.2GHz, numPentes=4, tamanhoTotal=32.0GB, velocidadeParalela=12.8GHz.
Para testar esta segunda classe, modifique a classe ComputadorMain, criada na questão anterior para criar um ou mais objetos da classe Memoria e, em seguida, imprimir o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe Memoria. Não precisa submeter a classe ComputadorMain.
Dica:
Note que não estamos usando acentos nas strings.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Memoria.java" Solução correta!
Nota da questão 2.0 / 2.0
```
public class Memoria {
	 
	String marca;
	 String tipo;
	 double tamanho;
	 double velocidade;
	 int numPentes;
	
	
	public Memoria(String marca, String tipo, double tamanho, double velocidade, int numPentes) {
		super();
		this.marca = marca;
		this.tipo = tipo;
		this.tamanho = tamanho;
		this.velocidade = velocidade;
		this.numPentes = numPentes;
	}


	public Memoria() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	double 	getTamanhoTotal() {
		return numPentes*tamanho;
		
	}
	
	double getVelocidadeParalela() {
		return numPentes*velocidade;
		
	}
	String 	getDescricao() {
		String desc = "Memoria: marca="+marca+", tipo="+tipo+", tamanho="+tamanho+"GB, velocidade="+velocidade+"GHz, numPentes="+numPentes+", tamanhoTotal="+numPentes*tamanho+"GB, velocidadeParalela="+numPentes*velocidade+"GHz.";
		return desc;
	}
}
```
### Q3-Classe Disco
![disco](https://user-images.githubusercontent.com/33138839/231196943-7bfac7d6-d97e-4433-b8d8-b79ad00d8fd5.png)
Como nas questões anteriores, implemente uma classe para representar o Disco do computador de acordo com o diagrama de classe ao lado. Implemente o método:
* getDescricao: retorna uma String contendo a descrição da memória de acordo com a linha a seguir:
Disco: marca=Western Digital, tipo=HDD, capacidade=4000.0GB, rpm=9600rpm.
Para testar esta terceira classe, modifique a classe ComputadorMain, criada nas questões anteriores para criar um ou mais objetos da classe Disco e, em seguida, imprimir o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe Disco. Não precisa submeter a classe ComputadorMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Disco.java" Solução correta!
Nota da questão 0.0 / 2.5
```
public class Disco {
	String marca;
	String tipo;
	double capacidade;
	int rpm;
	
	public Disco(String marca, String tipo, double capacidade, int rpm) {
		super();
		this.marca = marca;
		this.tipo = tipo;
		this.capacidade = capacidade;
		this.rpm = rpm;
	}

	public Disco() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	String 	getDescricao() {
		String desc = "Disco: marca="+marca+", tipo="+tipo+", capacidade="+capacidade+"GB, rpm="+rpm+"rpm.";
		return desc;
	}
	
}
```
### Q4-Classe Computador
![computador](https://user-images.githubusercontent.com/33138839/231196939-d8a7626b-4062-42d1-ac10-e6cc43e67cb8.png)
Implemente uma classe para Computador. Conforme o diagrama de classe ao lado, o computador deverá ter um atributo para seu fabricante (String), um atributo da classe Processador (criada na Questão 1), um atributo da classe Memoria (criada na Questão 2) e um atributo da classe Disco (criada na Questão 3).
Crie o método getDescricao que retorne uma String contendo todos os dados do computador. Este método deverá se basear na execução do método getDescricao dos objetos das outras classes (Processador, Memória e Disco), gerando uma String como a seguinte:
Computador da fabricante Dell. Processador: marca=Intel, modelo=i7, velocidade=3.2GHz, numNucleos=8, velocidadeParalela=25.6GHz. Memoria: marca=Kingston, tipo=DDR4, tamanho=8.0GB, velocidade=3.2GHz, numPentes=4, tamanhoTotal=32.0GB, velocidadeParalela=12.8GHz. Disco: marca=Western Digital, tipo=HDD, capacidade=4000.0GB, rpm=9600rpm.
Para testar esta classe, modifique a classe ComputadorMain, criada nas questões anteriores para criar um ou mais objetos da classe Computador e, em seguida, imprimir o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe Computador. Não precisa submeter a classe ComputadorMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Computador.java"
Nota da questão 0.0 / 0.5
```
public class Computador {
    String fabricante;
    Processador processador;
    Memoria memoria;
    Disco disco;

    public Computador() {
    }

    public Computador(String fabricante, Processador processador, Memoria memoria, Disco disco) {
        this.fabricante = fabricante;
        this.processador = processador;
        this.memoria = memoria;
        this.disco = disco;
    }
    
    String getDescricao(){
        String desc ="Computador da fabricante"+fabricante+". Processador: marca="+processador.marca
                +", modelo="+processador.modelo+", velocidade="+processador.velocidade+"GHz, numNucleos="+processador.numNucleos
                +", velocidadeParalela="+processador.getVelocidadeParalela()+"GHz. Memoria: marca="+memoria.marca
                +", tipo="+memoria.tipo+", tamanho="+memoria.tamanho+"GB, velocidade="+memoria.velocidade+"GHz, numPentes="+memoria.numPentes
                +", tamanhoTotal="+memoria.getTamanhoTotal()+"GB, velocidadeParalela="+memoria.getVelocidadeParalela()+"GHz. Disco: marca="+disco.marca
                +", tipo="+disco.tipo+", capacidade="+disco.capacidade+"GB, rpm="+disco.rpm+"rpm.";
        return desc;
    }
}
```
### Q5-Classe ComputadorMain
Por fim, submeta a classe ComputadorMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "ComputadorMain.java"
```
public class ComputadorMain {
     public static void main(String[] args) {
        Processador processador = new Processador();
        processador.marca="intel";
        processador.modelo="i7";
        processador.numNucleos=8;
        processador.velocidade=3.0;
        Memoria memoria = new Memoria();
        memoria.marca="Kingston";
        memoria.tipo="DDR5";
        memoria.tamanho=32;
        memoria.velocidade=3.2;
        memoria.numPentes=2;
        Disco disco = new Disco();
        disco.marca = "Kingston";
        disco.tipo="SSD";
        disco.capacidade=6000.0;
        disco.rpm = 9600;
       Computador computador = new Computador();
       computador.fabricante="Dell";
       computador.processador.modelo="I7";
       computador.memoria.tamanho=32.0;
       computador.disco.capacidade=980;
    }
}
```


