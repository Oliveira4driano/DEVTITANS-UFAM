# Laboratório 1: Introdução ao Java
### Objetivo
Aprender/relembrar a sintaxe básica da linguagem Java criando e executando classes simples (que contém apenas o método main) no Eclipse.
### Passos Iniciais
Inicie o Eclipse. Vá em "File" → "New" → "New Java Project". Nome do projeto: "Lab-Introducao".
Na parte Module (parte de baixo da janela), desselecione "Create module-info.java file".
Nas questões a seguir, será pedido para criar diversas classes. Para isso, vá em "File" → "New" → "Class".
Deixe o campo "package" em branco.
O Eclipse compila automaticamente as classes sempre que você salva. Para executar e testar, basta ir em "Run" → "Run" (Ctrl+F11).
A saída e entrada do programa será feita através da aba "Console" do Eclipse.
### Observações Gerais
Nas questões que trabalham com vetores, considere um tamanho máximo de vetor de 100 posições.
### Agradecimentos
Grande parte das questões foram baseadas no material de IPC, produzido pelo professor Leandro Galvão.
Nota da questão 0.5 / 0.5
### Q1 Hello Groot
Crie uma classe em Java chamada HelloGroot que imprima a mensagem "I am Groot".
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "HelloGroot.java" Solução correta!
Nota da questão 1.0 / 1.0
```
public class HelloGroot {

	public static void main(String[] args) {
		System.out.println("I am Groot");

	}

}
```

### Q2 Média
Crie uma classe em Java chamada Media que calcule e imprima, com duas casas decimais, a média aritmética de três números reais lidos do teclado.
### Exemplo de entrada e saída esperada:
* Entrada: 88.0 1.21 70.2
* Saída: 53.14
### Dicas:
* A classe Scanner, usada para ler dados do teclado, usa as configurações do sistema para setar o formato dos números reais. Dependendo da linguagem do seu sistema, um número real pode usar "." (ponto) ou "," (vírgula).
* Você pode representar os números reais usando float ou double.
Em Java, um número real isolado (e.g., 1.21) é considerado como sendo do tipo double. Para usar um número como sendo do tipo float, use o 'f' ao final do número (e.g., 1.21f).
Java converte automaticamente tipos quando não há perda de precisão. Exemplo: double nota = 8.7f; // Converte de float para double automaticamente
Entretanto, quando há perda de precisão, isso não é possível e o uso do cast é obrigatório. Exemplo: float nota = (float) 8.7; // Converte de double para float usando o cast
* Para imprimir algo formatado em Java, use o método System.out.printf(String format, Object... args). Exemplo: System.out.printf("%.3f\n", media);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Media.java" Solução correta!
Nota da questão 0.0 / 1.5
```
public class Media {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    Scanner scan = new Scanner(System.in);
	    System.out.print("");
	    double valor = Double.parseDouble(scan.next());
	    System.out.print("" );
	    double valor2 = Double.parseDouble(scan.next());
	    System.out.print("");
	    double valor3 = Double.parseDouble(scan.next());
	    double media = (valor+valor2+valor3)/3;
	 
	    System.out.printf("%.2f",media);
	    scan.close();
	}

}	
```
### Q3 Temperatura Fahrenheit
Escreva uma classe chamada Fahrenheit que converta uma temperatura digitada de  em . Use apenas uma casa decimal na saída. A fórmula para essa conversão é:

Exemplo de entrada e saída esperada:
Entrada: 42
Saída: 107.6
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Fahrenheit.java"
Nota da questão 0.0 / 2.0
```
import java.util.Scanner;

public class Fahrenheit {

	public static void main(String[] args) {
		float C,F;
		
		Scanner scan = new Scanner(System.in);
	    //System.out.print("Digite a temperatura: ");
	    C = scan.nextFloat();

		F=((C*9)/5)+32;
		System.out.print(F);
		scan.close();
	}

}
```
### Q4 Média de uma Coleção
Escreva um programa (classe MediaColecao) que calcula a média de uma coleção de valores digitados pelo usuário, com precisão de duas casas decimais. O usuário irá inserir -1 para indicar que não há mais valores serem fornecidos.
### Exemplo de entrada e saída esperada:
* Entrada: 5 3 9 3 1 -1
* Saída: 4.20

Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "MediaColecao.java"
Nota da questão 0.0 / 2.5
```
import java.util.Scanner;

public class MediaColecao {
	public static void main(String[] args) {
                     
            int  cont=0; 
            double media = 0;    
            Scanner scan = new Scanner(System.in);
           // System.out.println("Digite numero1: " );
            double  v = scan.nextDouble();  
       
               while(v != -1){
                    
                     //System.out.println("Digite numero: " );
                        
                       media +=v;
                       cont+=1;
                        v = scan.nextDouble();                                               
                } 
                 media = (media)/cont;
                 System.out.printf("%.2f",media );   
            }


        }
```

### Q5 Operações em Números Inteiros
Escreva programa em Java (classe OperacoesInteiros) que leia do teclado um vetor de inteiros. Em seguida, o programa deve imprimir na ordem:
Quantidade de elementos
Quantos são pares
Quantos são ímpares
Soma total
Média (duas casas decimais)
Maior
Menor
O final de um vetor é determinado pelo número -1. Seu programa deve repetir esse procedimento indefinidamente para diversos vetores, de tamanhos variados, até que um vetor sem elementos seja inserido, terminando a execução do programa.
### Exemplo de entrada e saída esperada:
Entrada: 1 5 2 8 4 -1 10 54 23 78 -1 -1
Saída: 5
3
2
20
4.00
8
1
4
3
1
165
41.25
78
10
Dica:
A classe Integer possui as constantes MAX_VALUE e MIN_VALUE para o maior e menor número inteiro armazenável. Exemplo: int numero = Integer.MAX_VALUE;
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "OperacoesInteiros.java"
Nota da questão 0.0 / 2.5
```
a
```
### Q6 Área do Polígono
Se  pontos estão ligados formando um polígono fechado, como mostrado abaixo,

a área  do polígono pode ser determinada por:

Observe que, embora o polígono ilustrado acima tenha apenas seis vértices distintos, temos que  para este polígono, pois o algoritmo espera que o último ponto, , seja uma repetição do ponto inicial, .
Escreva um programa (classe AreaPoligono) que receba como entrada as coordenadas  dos vértices do polígono como dois vetores de valores reais, um contendo os valores das abscissas  e o outro vetor contendo os valores das respectivas ordenadas , ambos finalizados através do número -1. Na saída, deve-se informar a área do polígono, com quatro casas decimais de precisão.
Para simplificar o código, considere que:
Os vetores fornecidos são sempre do mesmo tamanho;
Cada vetor possui pelo menos quatro elementos (o que garante pelo menos a existência de um triângulo); e
O primeiro e o último elementos de cada vetor de entrada são sempre iguais.
Dicas:
Para aplicar a função módulo no resultado do somatório, use o método abs(double a) da classe Math. Exemplo: double sumAbs = Math.abs(sum);
Note que em Java, 1/3 = 1, enquanto que 1.0/3.0 = 1.333.
Atenção para a condição do somatório: menor ou igual a .
Exemplos de entrada e saída esperada:
Entrada: 4 4 7 7 9 7 4 -1 0 7.5 7.5 3 0 0 0 -1
Saída: 25.5000
Entrada: 4 9 11 2 4 -1 10 7 2 2 10 -1
Saída: 45.5000
```
a
```

Fonte:
Hanly & Koffman. “Problem Solving and Program Design in C”, 5th edition. Pearson, 2007. (p. 423)
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AreaPoligono.java"s
