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
