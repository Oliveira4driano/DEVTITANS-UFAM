### L6-Q1
```
package br.edu.icomp.ufam.lab_heranca;

public abstract class FormaGeometrica {

	public int posX;
	public int posY;
	public FormaGeometrica() {
		super();
		// TODO Auto-generated constructor stub
	}
	public FormaGeometrica(int posx, int posy) {
		super();
		this.posX = posx;
		this.posY = posy;
	}
	public abstract double getArea();
		
	
	public abstract double getPerimetro();
		
	public String getPosString() {
		String pos= "posição ("+posX+", "+posY+")";
		return pos;
		
	}
}
```
```
package br.edu.icomp.ufam.lab_heranca;

public class Circulo extends FormaGeometrica {
	public double raio;
	
	
	
	public Circulo() {
		super();
		// TODO Auto-generated constructor stub
	}
	


	public Circulo(int posx, int posy,double raio) {
		super(posx, posy);
		this.raio = raio;
		// TODO Auto-generated constructor stub
	}
	public Circulo(int posx, int posy) {
		super(posx, posy);
		
		// TODO Auto-generated constructor stub
	}

	@Override
	public double getArea() {
		double pi = Math.PI;
		double area = pi * Math.pow(raio, 2);
		return area;
	}

	@Override
	public double getPerimetro() {
		double pi = Math.PI;
		double circulo =  2* pi * raio;
		return circulo;
	}

	@Override
	public String toString() {
		return "Círculo na posição ("######") com raio de "+raio+"cm (área="+getArea()+"cm2, perímetro="+getPerimetro()+"cm)";
	}
	
	
}
```
