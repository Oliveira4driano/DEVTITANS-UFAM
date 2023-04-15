### L8 Q1
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
### L8 Q2
package br.edu.ufam.icomp.lab_excecoes;

public class Coordenada {
	public int posX;
	public int posY;
	public int digito;
	
	
	public Coordenada() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Coordenada(int posX, int posY, int digito) {
		super();
		this.posX = posX;
		this.posY = posY;
		this.digito = digito;
	}
	
	public int getPosX() {
		return digito;
		
	}
	
	public int getPosY() {
		return digito;
		
	}
	public double distancia(Coordenada coordenada) {
		int aux=0;
		try {
			if(coordenada.posX <0 || coordenada.posY < 0) {
				aux =1;
			}else if(coordenada.posX <=30000 || coordenada.posY <=30000) {
				aux =2;
			}
		} catch (Exception e) {
			// TODO: handle exception
		}
		return null;
		
	}


	@Override
	public String toString() {
		return "Coordenada [posX=" + posX + ", posY=" + posY + ", digito=" + digito + "]";
	}

}

```
### L8 Q3
```
https://github.com/callmatos/devtitans
