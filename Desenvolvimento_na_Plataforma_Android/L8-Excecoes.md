# Laboratório 8: Exceções
### Introdução
A empresa privada SpaceX anunciou que irá enviar pessoas a Marte até o ano de 2028 (em 5 anos). Já a agência espacial NASA anunciou que irá enviar pessoas a Marte até 2030 (em 7 anos). Um passo importante em ambos os casos é encontrar o local mais apropriado em Marte para começar a colonização. Para isso, rovers como Curiosity, Perseverance e Ingenuity são usados para encontrar tais locais (dentre outros objetivos). Tais rovers são semiautomáticos, no sentido que um caminho básico (lista de coordenadas) é enviado para eles a partir da Terra e eles seguem o caminho tomando decisões locais quando necessário. Entretanto, como os dados enviados da Terra seguem um meio de comunicação muito instável, medidas precisam ser tomadas para tratar imprevistos como coordenadas inválidas, caminhos inválidos, etc.

Figura 1: Auto-retrato do rover
Curiosity em Marte
### Objetivo
* Neste trabalho, você implementará uma hierarquia de classes de exceções para representar possíveis problemas em um caminho enviado para um rover.
* Além das classes, você irá declarar/implementar métodos que podem disparar exceções (throws/throw) bem com irá usar tais métodos capturando (try) e tratando (catch) as possíveis exceções.
### Informações
Use os slides do arquivo "" como exemplos de código em Java para resolver este laboratório.
Nome do pacote para todas as classes: br.edu.ufam.icomp.lab_excecoes
Nota da questão 2.0 / 2.0
### Q1 Classes de Exceções
Crie uma hierarquia de classes de exceções conforme figura abaixo. Estas classes serão usadas pelas classes das questões seguintes.
Atenção: Use o último exemplo dos slides para criar essas classes.


Cada classe de exceção possui uma "mensagem", que será impressa quando ela ocorrer. Seguem as mensagens das classes:
* RoverException: "Exceção geral do rover"
* RoverCoordenadaException: "Exceção geral de coordenada do rover"
* RoverCaminhoException: "Exceção geral de caminho do rover"
* CoordenadaNegativaException: "Coordenada com valor negativo"
* CoordenadaForaDosLimitesException: "Coordenada com valores fora dos limites"
* DigitoInvalidoException: "Digito da coordenada inválido"
* TamanhoMaximoExcedidoException: "Quantidade máxima de coordenadas excedida"
* DistanciaEntrePontosExcedidaException: "Distância máxima entre duas coordenadas vizinhas excedida"
Após resolver e testar a questão no Eclipse, submeta os arquivos usando os botões abaixo:
```
package br.edu.ufam.icomp.lab_excecoes;

public class Exception extends RuntimeException {
	private static final long serialVersionUID = 1L;
	
	public String s;
	public Exception() {
		this("Arquivo texto não encontrado");

		// TODO Auto-generated constructor stub
	}
	public Exception(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
	
	

}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class RoverException extends Exception   {
	private static final long serialVersionUID = 1L;

	public RoverException() {
		this("Exceção geral do rover");
	}
	public RoverException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
	

}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class RoverCoordenadaException extends RoverException {
	private static final long serialVersionUID = 1L;
	public RoverCoordenadaException() {
		this("Exceção geral de coordenada do rover");
	}
	
	
	public RoverCoordenadaException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
	
	

}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class CoordenadaNegativaException extends RoverCoordenadaException {
	private static final long serialVersionUID = 1L;

	public CoordenadaNegativaException() {
		this("Coordenada com valor negativo");
	}

	public CoordenadaNegativaException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
	
	
}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class CoordenadaForaDosLimitesException extends RoverCoordenadaException{
	private static final long serialVersionUID = 1L;

	public CoordenadaForaDosLimitesException() {
		this("Coordenada com valores fora dos limites");
		// TODO Auto-generated constructor stub
	}

	public CoordenadaForaDosLimitesException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class DigitoInvalidoException extends RoverCoordenadaException {
	private static final long serialVersionUID = 1L;

	public DigitoInvalidoException() {
		this( "Digito da coordenada inválido");
		// TODO Auto-generated constructor stub
	}

	public DigitoInvalidoException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
	
	
}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class RoverCaminhoException extends RoverException {
	private static final long serialVersionUID = 1L;

	public RoverCaminhoException() {
		this("Exceção geral de caminho do rover");
		// TODO Auto-generated constructor stub
	}

	public RoverCaminhoException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
	
}
```
************************
```
package br.edu.ufam.icomp.lab_excecoes;

public class TamanhoMaximoExcedidoException extends RoverCaminhoException {


	public TamanhoMaximoExcedidoException() {
		
		this( "Quantidade máxima de coordenadas excedida");
	}
	
	public TamanhoMaximoExcedidoException(String s) {
		super(s);
		
	}
   
}
```
```
package br.edu.ufam.icomp.lab_excecoes;

public class DistanciaEntrePontosExcedidaException extends RoverCaminhoException {
	private static final long serialVersionUID = 1L;

	public DistanciaEntrePontosExcedidaException() {
		this("Distância máxima entre duas coordenadas vizinhas excedida");
		// TODO Auto-generated constructor stub
	}

	public DistanciaEntrePontosExcedidaException(String s) {
		super(s);
		// TODO Auto-generated constructor stub
	}
}
```

Nota da questão 0.0 / 3.3
### Q2 Classe Coordenada

Crie uma classe para representar uma Coordenada. O construtor da classe deverá verificar os dados passados e disparar as seguintes exceções caso seja necessário (em ordem de prioridade):
* CoordenadaNegativaException: esta exceção deverá ser disparada caso alguma das coordenadas seja menor que zero.
* CoordenadaForaDosLimitesException: disparada quando alguma das coordenadas não estiver entre os valores 0 e 30000.
* DigitoInvalidoException: disparada quando o resto da divisão da soma das coordenadas (posX + posY) por 10 for diferente do dígito (que deverá estar entre 0 e 9).
O método distancia(Coordenada coordenada) deverá retornar a distância entre a coordenada atual e a do argumento.
Já o método toString deverá imprimir as coordenadas de acordo com o exemplo abaixo:
```
32, 67
```
```
package br.edu.ufam.icomp.lab_excecoes;

public class Coordenada { 
    private int posX; 
    private int posY; 
    private int digito;

    public Coordenada() {
    }

    public Coordenada(int posX, int posY, int digito)throws CoordenadaNegativaException, CoordenadaForaDosLimitesException, DigitoInvalidoException {

            if(posX <0 || posY < 0) throw new  CoordenadaNegativaException();

            if(posX <0 || posX > 30000 || posY <0 || posY > 30000) throw new CoordenadaForaDosLimitesException();

                int validarDigito = (posX + posY) % 10;
                if(validarDigito <0 || validarDigito >9)  throw new DigitoInvalidoException();

                if(validarDigito != digito )  throw new DigitoInvalidoException();

                  this.posX = posX;
                  this.posY = posY;
                  this.digito = digito;
    }

    public int getPosX() {
            return posX;	
    }

    public int getPosY() {
            return posY;	
    }
    public int getDigito(){
            return digito;
    }

    public double distancia(Coordenada coordenada) {
            double distancia = 0;
            double posx = this.posX - coordenada.posX;
            double posy = this.posY - coordenada.posY;
            distancia = Math.sqrt(posx * posx +  posy * posy);         
            return distancia;	
    }

    @Override
    public String toString() {
            return getPosX() + ", " + getPosY() ;
    }
}
// raiz (x2 -x1)^2 + (y2 - y1) ^2 
```
Nota da questão 0.0 / 4.3
### Q3 Classe Caminho

Crie uma classe para representar um Caminho, que gerenciará um vetor de Coordenadas. O método addCoordenada poderá dispará as seguintes exceções (em ordem de prioridade), caso algo inesperado ocorra:
TamanhoMaximoExcedidoException: disparada ao tentar adicionar mais uma coordenada, mas o tamanho máximo foi atingido.
DistanciaEntrePontosExcedidaException: disparada quando a distância entre o último ponto adicionado e o ponto atual é maior que 15m.
Note que caso alguma das exceções acima ocorra, o método addCoordenada não deverá adicionar a coordenada na lista (vetor).
O método reset deverá zerar a lista (vetor) de coordenadas (criando uma nova ou setando os elementos para nulo) e também o seu tamanho.
O método toString deverá imprimir o caminho completo, conforme exemplo abaixo:
```
Dados do caminho:
  - Quantidade de pontos: 6
  - Pontos:
    -> 32, 30
    -> 35, 40
    -> 38, 30
    -> 30, 36
    -> 40, 36
    -> 33, 31
```
```
package br.edu.ufam.icomp.lab_excecoes;

public class Caminho {
    

    private Coordenada [] caminho = null;
    private int tamanho = 0;

    public Caminho(int maxTam){
        this.caminho = new Coordenada[maxTam];
    }

    public int tamanho(){
        return this.tamanho;
    }

    public void addCoordenada(Coordenada coordenada) throws TamanhoMaximoExcedidoException, DistanciaEntrePontosExcedidaException{

        // Primeiro registro
        if( tamanho == 0){
            this.caminho[this.tamanho] = coordenada;           
            this.tamanho++;
            return;
        }

        int tamanhoAux = this.tamanho + 1;

        if(tamanhoAux > this.caminho.length){
            throw new TamanhoMaximoExcedidoException();

        }else if(tamanho > 0 && coordenada.distancia(caminho[tamanho - 1]) > 15){
            throw new DistanciaEntrePontosExcedidaException("A distancia entre pontos nao pode ser maior que 15m!");
        }else{
            this.caminho[tamanho] = coordenada;
            this.tamanho++;

        }

    }

    public void reset(){
        this.caminho = new Coordenada[this.tamanho];
    }
    
    @Override
    public String toString() {
        
        StringBuffer saida = new StringBuffer("Dados do caminho:");
        saida.append("  - Quantidade de pontos: "+this.tamanho+"\n");
        saida.append("  - Pontos:\n");
        
        for(int i = 0; i < tamanho; i++){
            saida.append("    -> "+this.caminho[i].toString()+"\n");
        } 
        return saida.toString();
    }
}
```
Nota da questão 0.0 / 0.5
### Q4 Classe RoverMain
Por fim, crie uma classe camada RoverMain que irá conter o método main e simular a recepção de um caminho vindo da central de comando na Terra para o Rover criando várias Coordenadas e adicionando-os a um objeto da classe Caminho. Por fim, imprima o caminho completo. Seu código deverá capturar qualquer exceção do rover (RoverException) e imprimir a mensagem de erro caso ocorra. Adicionalmente, em caso de qualquer exceção, o método reset do caminho deverá ser executado, para evitar que o rover use um caminho inválido (i.e., ele deverá ficar parado caso tenha algum problema com o caminho).
Para imprimir a mensagem de erro da exceção, você pode executar o método getMessage() do objeto de exceção passado pelo catch ou pode simplesmente mandar imprimir o objeto, uma vez que a classe Throwable sobrepõe o método toString. Tente criar coordenadas e caminhos inválidos para ver as mensagens de exceção.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:

```
a
```
