# Laboratório 6: Pacotes, Herança
### Objetivo
* Exercitar os conceitos de pacotes, herança, sobreposição, polimorfismo
e classes abstratas.
* Use os slides do arquivo "" como
exemplos de código em Java para resolver este laboratório.
* Neste trabalho, você implementará a hierarquia de classes ao lado para
representar formas geométricas.
* O detalhamento das classes, seus atributos e métodos, serão
descritos nas questões abaixo.
### Obervações Importantes
Nome do projeto: "Lab-Heranca".
As classes deste trabalho deverão estar dentro do
pacote br.edu.icomp.ufam.lab_heranca
Para isso, ao criar uma nova classe, vá em "File" →
"New" → "Class" e preencha o campo "package".
Como estamos usando pacotes, use o modificador
public na declaração das classes, dos atributos e dos métodos.
Explicaremos isso na próxima aula.

![Classe](https://user-images.githubusercontent.com/33138839/231910272-fce6f420-2dd1-41bb-b7a5-22c7e1e072a5.png)

Nota da questão 1.5 / 1.5

### Q1 Classe FormaGeometrica
ClasseEste A indica que a classe é uma classe abstrata. Note que o nome dela está em itálico também.Este ícone indica uma classe pública (public)	
FormaGeometrica
AtributoEste ícone indica um atributo público (public)	posX: int
AtributoEste ícone indica um atributo público (public)	posY: int
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	FormaGeometrica(int posX, int posY)
MétodoEste A indica um método abstrado. Note que o nome do método está em itálico.	getArea(): double
MétodoEste A indica um método abstrado. Note que o nome do método está em itálico.	getPerimetro(): double
MétodoEste ícone indica um método público (public)	getPosString(): String

![formaGeometrica](https://user-images.githubusercontent.com/33138839/231910270-6fb1c96b-6364-44eb-99a7-9bdf65654b98.png)

Crie uma classe para representar uma FormaGeometrica. Uma FormaGeometrica possui os atributos posX e posY indicando a posição da forma na tela.
Esta classe possui os métodos:
* getPosString: retorna uma String contendo a posição da forma geométrica na tela conforme o exemplo abaixo (para posX = 32 e posY = 87):
```
posição (32, 87)
```
* getArea(): método abstrato, não possui implementação.
* getPerimetro(): método abstrato, não possui implementação.
Note que como a classe possui métodos abstratos, ela também deverá ser declarada como abstrata. Note também que como a classe é abstrata, você não terá como gerar instâncias dela (objetos) para testar o método getPosString.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "FormaGeometrica.java" Solução correta!
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
Nota da questão 0.6 / 2.0
### Q2 Classe Circulo
ClasseEste ícone indica uma classe pública (public)	Circulo
AtributoEste ícone indica um atributo público (public)	raio: double
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	Circulo(int posX, int posY, double raio)
MétodoEste ícone indica um método público (public)	getArea(): double
MétodoEste ícone indica um método público (public)	getPerimetro(): double
MétodoEste ícone indica um método público (public)	toString(): String

![circulo](https://user-images.githubusercontent.com/33138839/231910268-e7e5fa54-8447-43c2-8613-b5a37ce1ec56.png)

Crie uma classe para representar um Circulo. Um Circulo é uma subclasse da classe FormaGeometrica que, além dos atributos e métodos herdados, possui o atributo raio e os métodos:
* getArea(): implementação do método abstrato que veio da superclasse. Retorna a área do círculo. Importante: use a constante PI do java para realizar o cálculo (veja dicas abaixo).
* getPerimetro(): implementação do método abstrato que veio da superclasse. Retorna o perímetro do círculo. Importante: use a constante PI do java para realizar o cálculo (veja dicas abaixo).
* toString: sobrepõe o método toString da classe Object. Deve retornar uma descrição do círculo atual conforme exemplo abaixo. Importante: como este método sobrepõe outro, este precisa ter o mesmo modificador de acesso (ou um mais permissível) que o original. Neste caso, o método precisa ser public (note o círculo verde na descrição do método no diagrama de classes ao lado).
```
Círculo na posição (32, 87) com raio de 6.0cm (área=113.09733552923255cm2, perímetro=37.69911184307752cm)
```
### Dicas:
* A área de um círculo é dada pela fórmula: ![area](https://user-images.githubusercontent.com/33138839/231930982-fe93e73e-1b86-4fa1-93a1-78f854652462.png)
* O perímetro de um círculo é dado pela fórmula: ![perimetroCirculo](https://user-images.githubusercontent.com/33138839/231930950-5c2f2cc1-7c9e-44c6-8945-f234ba565606.png)
* Use a constante PI presente na classe Math do Java para pegar o valor de . Exemplo: double pi = Math.PI;
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Circulo.java" Compilou, mas a resposta está parcialmente errada. Veja mensagens abaixo.
A saída do último comando abaixo não corresponde ao esperado.

```
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
        return "Círculo na posição ("+Circulo.super.posX+", "+Circulo.super.posY
                +") com raio de "+raio+"cm (área="+getArea()+"cm2, perímetro="+getPerimetro()+"cm)";
    }
```    
### Q3 Classe Retangulo
ClasseEste ícone indica uma classe pública (public)	Retangulo
AtributoEste ícone indica um atributo público (public)	largura: double
AtributoEste ícone indica um atributo público (public)	altura: double
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	Retangulo(int posX, int posY, double largura, double altura)
MétodoEste ícone indica um método público (public)	getArea(): double
MétodoEste ícone indica um método público (public)	getPerimetro(): double
MétodoEste ícone indica um método público (public)	toString(): String

![retangulo](https://user-images.githubusercontent.com/33138839/231910266-5f98845c-e282-4482-b6b1-c47af213f85d.png)

Crie uma classe para representar um Retangulo. Um Retangulo é uma subclasse da classe FormaGeometrica que, além dos atributos e métodos herdados, possui os atributos largura e altura e os métodos:
* getArea(): implementação do método abstrato que veio da superclasse. Retorna a área do retângulo.
* getPerimetro(): implementação do método abstrato que veio da superclasse. Retorna o perímetro do retângulo.
* toString: sobrepõe o método toString da classe Object. Deve retornar uma descrição do retângulo atual conforme exemplo abaixo.
Retângulo na posição (12, 65) com largura de 2.0cm e altura de 7.0cm (área=14.0cm2, perímetro=18.0cm)
### Dicas:
A área de um retângulo é dada pela fórmula: ![AreaRetangulo](https://user-images.githubusercontent.com/33138839/231938224-3d27cf44-8f94-48df-849e-3cc8721c7de2.png)

O perímetro de um retângulo é dado pela fórmula: ![perimetroRetangulo](https://user-images.githubusercontent.com/33138839/231938262-e4e9d5a1-e36b-4fb6-afce-74451416869e.png)

Nota da questão 0.0 / 3.0
```
public class Retangulo extends FormaGeometrica {
    public double largura;
    public double altura;

    public Retangulo() {
        super();
    }
    public Retangulo(int posx, int posy, double largura, double altura) {
        super(posx, posy);
        this.largura = largura;
        this.altura = altura;
    }
    @Override
    public double getArea() {
        return largura * altura;
    }
    @Override
    public double getPerimetro() {
        return 2*(largura + altura);
    }
    @Override
    public String toString() {
        return "Retângulo na posição ("+Retangulo.super.posX+", "+Retangulo.super.posY+") com largura de "
                +largura+"cm e altura de "+altura+"cm (área="+getArea()+"cm2, perímetro="+getPerimetro()+"    cm)";
    }
}
```
### Q4 Classe Quadrado
ClasseEste ícone indica uma classe pública (public)	Quadrado
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	Quadrado(int posX, int posY, double lado)
MétodoEste ícone indica um método público (public)	toString(): String

![quadrado](https://user-images.githubusercontent.com/33138839/231910263-28408b3c-766c-4b9e-9d1b-25939274b4a6.png)

Crie uma classe para representar um Quadrado. Um Quadrado é uma subclasse da classe Retangulo. Note que ele não possui atributos adicionais (irá usar os atributos largura e altura da superclasse). Os métodos getArea e getPerimetro serão herdados da superclasse. Será necessário apenas sobrepor o método toString.
* toString: sobrepõe o método toString da classe Object. Deve retornar uma descrição do quadrado atual conforme exemplo abaixo.
```
Quadrado na posição (45, 39) com lado de 6.0cm (área=36.0cm2, perímetro=24.0cm)
```
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Quadrado.java"
Nota da questão 0.0 / 0.5
```
a
```
### Q5 Classe FormasMain
Por fim, para exercitar o conceito de polimorfismo crie uma classe chamada FormasMain que terá o método main. Neste método, crie um vetor de objetos da classe FormaGeometrica. Crie e insira no vetor um ou mais objetos das classes Circulo, Retangulo e Quadrado. Em seguida, faça um for para iterar entre todos os elementos e mande imprimir cada um dos objetos. Como você sobrepôs o método toString, você pode mandar imprimir diretamente. Exemplo: System.out.println(circulo1);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
```
a
```
