# Laboratório 2: Relembrando Programação (Desafio)
### Objetivo
Aprender/relembrar a sintaxe básica da linguagem Java criando e executando classes simples (que contém apenas o método main) no Eclipse.
### Passos Iniciais
Inicie o Eclipse. Vá em "File" → "New" → "New Java Project". Nome do projeto: "Lab-RelembrandoProgramacao".
Na parte Module (parte de baixo da janela), desselecione "Create module-info.java file".
Nas questões a seguir, será pedido para criar diversas classes. Para isso, vá em "File" → "New" → "Class".
Deixe o campo "package" em branco.
O Eclipse compila automaticamente as classes sempre que você salva. Para executar e testar, basta ir em "Run" → "Run" (Ctrl+F11).
A saída e entrada do programa será feita através da aba "Console" do Eclipse.
### Observações Gerais
O trabalho é individual! Plágio resultará em nota zero para todos os envolvidos. Lembre-se que existem meios automáticos de se verificar plágio e você não será notificado até que seja tarde.
Nas questões que trabalham com vetores, considere um tamanho máximo de vetor de 100 posições.
### Agradecimentos
Grande parte das questões foram baseadas no material de IPC, produzido pelo professor Leandro Galvão.
Nota da questão 0.0 / 0.1
### Q1 Hello UFAM
Crie uma classe em Java chamada HelloUfam que imprima a mensagem "Universidade Federal do Amazonas".
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "HelloUfam.java"
Nota da questão 0.0 / 0.1
```
public class HelloUfam {
    
    public static void main(String[] args) {
        System.out.println("Universidade Federal do Amazonas");
    }
    
}
```
### Q2 Hello Groot
Crie uma classe em Java chamada HelloGroot que imprima a mensagem "I am Groot".
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "HelloGroot.java"
Nota da questão 0.0 / 0.1
```
public class HelloGroot {
    public static void main(String[] args) {
        System.out.println("I am Groot");
    }
}
```

### Q3 May the Force be With You
Crie uma classe em Java chamada TheForce que imprima a mensagem "May the Force be with you".
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "TheForce.java"
Nota da questão 0.0 / 0.1
```
public class TheForce {
    public static void main(String[] args) {
        System.out.println("May the Force be with you");
    }
}
```
### Q4 Coelho
Crie uma classe em Java chamada Coelho que imprima no console a seguinte figura:
```
(\ (\
(='.')
((^)(^)
```
Dicas:
Assim como em outras linguagens, no Java o "\" é usado para imprimir caracteres especiais (e.g., "\n", "\t"). Para imprimir uma barra, use "\\".
O rosto tem três linhas. Logo, será necessário executar o método println três vezes.
O Java já imprime uma linha nova ao final do método println.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Coelho.java"
Nota da questão 0.0 / 0.1
```
public class Coelho {
    public static void main(String[] args) {
        System.out.println("(\\ (\\");
        System.out.println("(='.')");
        System.out.println("((^)(^)");
    }
}

```
### Q5 Macaco
Crie uma classe em Java chamada Macaco que imprima no console a seguinte figura:
```
  *****
(* o o *)
 *  ^  *
 * --- *
  *****
```

Dicas:
O rosto tem cinco linhas. Logo, será necessário executar o método println cinco vezes.
Os olhos são representados com a letra "o" minúscula. Não use o símbolo do zero, nem a letra "O" maiúscula.
O Java já imprime uma linha nova ao final do método println.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Macaco.java"
Nota da questão 0.0 / 0.1
```
public class Macaco {
    public static void main(String[] args) {
        System.out.println("  ***** ");
        System.out.println("(* o o *)");
        System.out.println(" *  ^  *");
        System.out.println(" * --- *");
        System.out.println("  ***** ");
    }
}
```

### Q6 ASCII Art
Escreva um programa (classe AsciiArt) que imprima uma figura semelhante à representada abaixo, a partir da leitura do número de asteriscos presentes na base. Por exemplo, para uma entrada igual a 5, o resultado produzido será igual ao da figura abaixo.
```
**********
****  ****
***    ***
**      **
*        *
```
Dicas:
Para imprimir algo em Java sem a nova linha no final, use o método System.out.print(). Exemplo: System.out.print('*');
Para imprimir apenas uma nova linha use System.out.println();
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AsciiArt.java"
Nota da questão 0.0 / 0.1
```
import java.util.Scanner;

/**
 *
 * @author oliveira
 */
public class AsciiArt {

    
    public static void main(String[] args) {
	System.out.print("Digite numero: " ); 
        Scanner scan = new Scanner(System.in);
         int tam = scan.nextInt();
        //int tam =5;
        int k,l;
        
        for (int i = tam; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
                
            }
            l =(2*(tam-i));
            for (k=1; k <= l; k++){  
                System.out.print(" ");
            }
            for (int j = 0; j < i; j++) {
                System.out.print("*");
                
            }
            
           System.out.println("");
           
        }
      
    }
 
    
}
```
```
public class AsciiArt {
    //Função que imprime o preechimento
    public static void preenche(int n) {
        int i;
        for (i=1; i <= n; i++){
            System.out.print("*");
        }
        //System.out.print("\n");
    }
    
    //Função que imprime o espaçamento
    public static void espaco(int n){
            int i;
            for (i=1; i <= n; i++){  
                System.out.print(" ");
            }
    }
    
    public static void main(String[] args) {
	int tam, i;
         tam =5;

	for (i=tam; i>0; i--){		//Superior
		preenche(i);		//Preenchimento esquerdo
		espaco(2*(tam-i));	//Espaçamento central
		preenche(i);		//Preenchimento direito
		 System.out.printf("\n");	//Quebra de linha
	}

        
    }
    
    
}
```
```
public class AsciiArt {
    //Função que imprime o preechimento
    public static void preenche(int n) {
        int i;
        for (i=1; i <= n; i++){
            System.out.print("*");
        }
        //System.out.print("\n");
    }
    
    //Função que imprime o espaçamento
    public static void espaco(int n){
            int i;
            for (i=1; i <= n; i++){  
                System.out.print(" ");
            }
    }
    
    public static void main(String[] args) {
	int  i;
          Scanner scan = new Scanner(System.in);
         int tam = scan.nextInt();

	for (i=tam; i>0; i--){		//Superior
		preenche(i);		//Preenchimento esquerdo
		espaco(2*(tam-i));	//Espaçamento central
		preenche(i);		//Preenchimento direito
		 System.out.printf("\n");	//Quebra de linha
	}

        
    }
    
    
}
```
### Q6-2 ASCII Art
Escreva um programa (classe AsciiArt) que imprima uma figura semelhante à representada abaixo, a partir da leitura do número de asteriscos presentes na base. Por exemplo, para uma entrada igual a 5, o resultado produzido será igual ao da figura abaixo.
```
*****
****
***
**
*
*
**
***
****
*****
```
```
public class AsciiArt2 {
    public static void main(String[] args) {
       
       // Scanner scan = new Scanner(System.in);
        // int tam = scan.nextInt();
        int tam =5;
        // System.out.print("Digite numero: " );
        for (int i = tam; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
                
            }
            System.out.println("");
        }
        for (int i = 1; i <= tam; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
                
            }
            System.out.println("");
        }
        
    }
    
}
```
```
\\Com metodo
public class AsciiArt {
    //Função que imprime o preechimento
    public static void preenche(int n) {
        int i;
        for (i=1; i <= n; i++){
            System.out.print("*");
        }
        System.out.print("\n");
    }
    
    //Função que imprime o espaçamento
    public static void espaco(int n){
            int i;
            for (i=1; i <= n; i++){  
                System.out.print(" ");
            }
    }
    
    public static void main(String[] args) {
	int tam, i, j;
         tam =5;

	for (i=tam; i>0; i--){	//Triângulo regular
            
            preenche(i);
	}
	for (i=1; i<=tam; i++){	//Triângulo invertido
		preenche(i);
	}
        
    }
    
    
}
```
### Q6-3 ASCII ArtJava
Escreva um programa (classe AsciiArt) que imprima uma figura semelhante à representada abaixo, a partir da leitura do número de asteriscos presentes na base. Por exemplo, para uma entrada igual a 5, o resultado produzido será igual ao da figura abaixo.
```
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
000000000000    000000000      0000000     00000000     0000000      0000000000000000000000000000000
000000000000    00000000        000000     00000000     000000        000000000000000000000000000000
000000000000    00000000        000000      000000      000000        000000000000000000000000000000
000000000000    0000000         0000000     000000     000000         000000000000000000000000000000
000000000000    0000000          000000     000000     000000          00000000000000000000000000000
000000000000    0000000          000000      0000      000000          00000000000000000000000000000
000000000000    000000            000000     0000     000000            0000000000000000000000000000
000000000000    000000            000000      00      000000            0000000000000000000000000000
000000000000    000000     00     000000      00      000000     00     0000000000000000000000000000
000000000000    00000      00      000000     00     000000      00      000000000000000000000000000
000000000000    00000      00      000000            000000      00      000000000000000000000000000
000000000000    00000     0000     000000            000000     0000     000000000000000000000000000
000000000000    0000                000000          000000                00000000000000000000000000
000000000000    0000                000000          000000                00000000000000000000000000
000000000000    0000                000000         0000000                00000000000000000000000000
000000000000    000      000000      000000        000000      000000      0000000000000000000000000
00000000000     000     00000000     000000        000000     00000000     0000000000000000000000000
00000000000     000     00000000     0000000      0000000     00000000     0000000000000000000000000
00000000000     000000000000000000000000000000000000000000000000000000000000000000000000000000000000
000000000       000000000000000000000000000000000000000000000000000000000000000000000000000000000000
00000000        000000000000000000000000000000000000000000000000000000000000000000000000000000000000
00000000       0000000000000000000000000000000000000000000000000000000000000000000000000000000000000
00000000      00000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
```
```
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 *
 * @author oliveira
 */
public class AsciiArtJava {
    public static void main(String[] args) throws IOException {

        int width = 100;
        int height = 30;

        //BufferedImage image = ImageIO.read(new File("/Users/mkyong/Desktop/logo.jpg"));
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics g = image.getGraphics();
        g.setFont(new Font("SansSerif", Font.BOLD, 24));

        Graphics2D graphics = (Graphics2D) g;
        graphics.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
                RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
        graphics.drawString("JAVA", 10, 20);

        //save this image
        //ImageIO.write(image, "png", new File("/users/mkyong/ascii-art.png"));

        for (int y = 0; y < height; y++) {
            StringBuilder sb = new StringBuilder();
            for (int x = 0; x < width; x++) {

                sb.append(image.getRGB(x, y) == -16777216 ? "0" : " ");

            }

            if (sb.toString().trim().isEmpty()) {
                continue;
            }

            System.out.println(sb);
        }

    }
    
}
```
### Q6-4 ASCII Art Ampulheta
Escreva um programa (classe AsciiArt) que imprima uma figura semelhante à representada abaixo, a partir da leitura do número de asteriscos presentes na base. Por exemplo, para uma entrada igual a 10, o resultado produzido será igual ao da figura abaixo.
```
\            *            /
 \          ***          /
  \        *****        /
   \      *******      /
    \    *********    /
     \  ***********  /
      \*************/
       \***********/
        \*********/
         \*******/
          \*****/
           \***/
            \*/
            /*\
           /***\
          /*****\
         /*******\
        /*********\
       /***********\
      /*************\
     /  ***********  \
    /    *********    \
   /      *******      \
  /        *****        \
 /          ***          \
/            *            \
```
```
public class AsciiArt {
    //Função que imprime o preechimento
    public static void preenche(int n) {
        int i;
        for (i=1; i <= n; i++){
            System.out.print("*");
        }
        //System.out.print("\n");
    }
    
    //Função que imprime o espaçamento
    public static void espaco(int n){
            int i;
            for (i=1; i <= n; i++){  
                System.out.print(" ");
            }
    }
    
    public static void main(String[] args) {
	int tam, i;
         tam =10;
	 
        //Superior
	for (i=0; i<tam; i++){
		espaco(i);
		System.out.printf("\\");
		espaco(2*(tam-i-1));
		preenche(2*i+1);
		espaco(2*(tam-i-1));
		System.out.printf("/");
		System.out.printf("\n");
	}
	for (i=tam-1; i>0; i--){
		espaco(2*tam-1-i);
		System.out.printf("\\");
		preenche(2*i-1);
		System.out.printf("/");
		System.out.printf("\n");
	}
        //Inferior
	for (i=0; i<tam-1; i++){
		espaco(2*tam-2-i);
		System.out.printf("/");
		preenche(2*i+1);
		System.out.printf("\\");
		System.out.printf("\n");
	}
	for (i=tam-1; i>=0; i--){
		espaco(i);
		System.out.printf("/");
		espaco(2*(tam-i-1));
		preenche(2*i+1);
		espaco(2*(tam-i-1));
		System.out.printf("\\");
		System.out.printf("\n");
	}
       
        
    }
    
    
}
```
### Q6-5 ASCII Art Losango
Escreva um programa (classe AsciiArt) que imprima uma figura semelhante à representada abaixo, a partir da leitura do número de asteriscos presentes na base. Por exemplo, para uma entrada igual a 5, o resultado produzido será igual ao da figura abaixo.
```
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
```
```
public class AsciiArt {
    //Função que imprime o preechimento
    public static void preenche(int n) {
        int i;
        for (i=1; i <= n; i++){
            System.out.print("*");
        }
        //System.out.print("\n");
    }
    
    //Função que imprime o espaçamento
    public static void espaco(int n){
            int i;
            for (i=1; i <= n; i++){  
                System.out.print(" ");
            }
    }
    
    public static void main(String[] args) {
	int tam, i;
         tam =5;

	for (i=tam; i>0; i--){		//Superior
		preenche(i);		//Preenchimento esquerdo
		espaco(2*(tam-i));	//Espaçamento central
		preenche(i);		//Preenchimento direito
		 System.out.printf("\n");	//Quebra de linha
	}
	for (i=1; i<=tam; i++){		//Inferior
		preenche(i);		//Preenchimento esquerdo
		espaco(2*(tam-i));	//Espaçamento central
		preenche(i);		//Preenchimento direito
		System.out.printf("\n");	//Quebra de linha
	}
      
       
        
    }
    
    
}
```
### Q7 Idade UFAM
Crie uma classe em Java chamada IdadeUfam que leia o ano atual do teclado e imprima "A UFAM tem X anos de fundacao", trocando o X pela idade da UFAM.
Dicas:
Consulte o site da UFAM, se você não souber o ano de fundação.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "IdadeUfam.java"
Nota da questão 0.0 / 0.1
```
public class IdadeUfam {
    public static void main(String[] args) {
        System.out.println("Digite o ano: ");
        Scanner scan = new Scanner(System.in); 
        int anoAtual = scan.nextInt();
        int anoFundada = 1909;
        anoFundada = (anoAtual - anoFundada);
        System.out.printf("A UFAM tem %d anos de fundacao",anoFundada);
    }
    
}
```
### Q8 Raiz Quadrada
Crie uma classe em Java chamada RaizQuadrada que calcule e imprima a raiz quadrada de um número inteiro lido do teclado. Sua saída deverá ter 4 casas decimais.
Dicas:
Você pode representar os números reais usando float ou double.
Em Java, um número real isolado (e.g., 1.21) é considerado como sendo do tipo double. Para usar um número como sendo do tipo float, use o 'f' ao final do número (e.g., 1.21f).
Java converte automaticamente tipos quando não há perda de precisão. Exemplo: double nota = 8.7f; // Converte de float para double automaticamente
Entretanto, quando há perda de precisão, isso não é possível e o uso do cast é obrigatório. Exemplo: float nota = (float) 8.7; // Converte de double para float usando o cast
Para calcular uma raiz quadrada em Java, usa-se o método sqrt(double a) da classe Math. Exemplo: double raiz = Math.sqrt(24601);
Para imprimir algo formatado em Java, use o método System.out.printf(String format, Object... args). Exemplo: System.out.printf("%.3f\n", media);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "RaizQuadrada.java"
Nota da questão 0.0 / 0.1
```
public class RaizQuadrada {
    public static void main(String[] args) {
       
        System.out.println("Digite a raiz");
        Scanner scan = new Scanner(System.in);
        double raiz = Math.sqrt(scan.nextInt());
        System.out.printf("%.4f\n", raiz);
    }
}
```
### Q9 Pintura do Muro
Mário precisa pintar um muro, que tem 12m de comprimento e 3m de altura. O material de pintura (galão de tinta, lixa, rolo, etc.) custa R$100. Cada pintor cobra um preço diferente por m² pelo serviço de pintura. Escreva uma classe chamada PinturaMuro em Java que, dado o valor cobrado por um pintor (R$/m²), informe o custo total da pintura (com uma casa decimal).
Exemplo de entrada e saída esperada:
Entrada: 3.2
Saída: 215.2
Dicas:
Você pode representar os números reais usando float ou double.
Em Java, um número real isolado (e.g., 1.21) é considerado como sendo do tipo double. Para usar um número como sendo do tipo float, use o 'f' ao final do número (e.g., 1.21f).
Java converte automaticamente tipos quando não há perda de precisão. Exemplo: double nota = 8.7f; // Converte de float para double automaticamente
Entretanto, quando há perda de precisão, isso não é possível e o uso do cast é obrigatório. Exemplo: float nota = (float) 8.7; // Converte de double para float usando o cast
A classe Scanner, usada para ler dados do teclado, usa as configurações do sistema para setar o formato dos números reais. Dependendo da linguagem do seu sistema, um número real pode usar "." (ponto) ou "," (vírgula).
Para imprimir algo formatado em Java, use o método System.out.printf(String format, Object... args). Exemplo: System.out.printf("%.3f\n", media);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "PinturaMuro.java"
Nota da questão 0.0 / 0.1
```
public class PinturaMuro {
    public static void main(String[] args) {
        System.out.println("Digite o valor do M2: ");
        Scanner scan = new Scanner(System.in);
        double valor = scan.nextDouble();
        int comprimento = 12;
        int largura =3;
        double material = 100;
        double area = (comprimento * largura);
        double custoTotal = (valor*area)+material;
        System.out.printf("%.1f\n", custoTotal);
    }
}
```
### Q10 Xadrez
Crie uma classe em Java chamada Xadrez que leia a quantidade de linhas do usuário e imprima o padrão abaixo (para entrada 6).
```
* * * * * *
 * * * * * *
* * * * * *
 * * * * * *
* * * * * *
 * * * * * *
```
Dicas:
Note que tanto a quantidade de linhas quanto a quantidade de "*" é 6 (número digitado pelo usuário).
Para imprimir algo em Java sem a nova linha no final, use o método System.out.print(). Exemplo: System.out.print('*');
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Xadrez.java"
Nota da questão 0.0 / 0.2
```
public class Xadrez {
    public static void main(String[] args) {
        //System.out.println("Digite o numero: ");
        Scanner scan = new Scanner(System.in);
        int valor = scan.nextInt();
        //int valor =6;
        boolean verdadeiro = true;
        for (int i = 0; i < valor; i++) {
            for (int j = 0; j < valor; j++) {
                System.out.print('*');
                System.out.print(' ');
        }
            
            System.out.print('\n');
            if(verdadeiro){
            System.out.print(' ');
            verdadeiro = false;
            }else{
                verdadeiro = true;
            }
        }
       
    }
}
```
### Q11 Caixa Eletrônico
Um cliente de um banco deseja sacar uma quantia em um caixa eletrônico que possui apenas notas de R$50, R$10 e R$2 disponíveis. Escreva uma classe chamada CaixaEletronico que exiba quantas notas de cada tipo devem ser entregues ao cliente. Considere que o cliente pode inserir – intencionalmente ou não – um valor inválido, tal como um número negativo ou um número ímpar. Seu programa deve exibir a mensagem "Valor Invalido" nessas situações. A saída do seu programa deve ser de acordo com o exemplo abaixo.
Exemplo de entrada e saída esperada:
Entrada: 378
Saída: 7 notas de R$50, 2 notas de R$10 e 4 notas de R$2
Dicas:
Comece pelas notas de valor mais alto.
Use o operador de resto da divisão (%) para determinar a quantidade de notas de valor imediatamente mais baixo.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "CaixaEletronico.java"
Nota da questão 0.0 / 0.2
```
public class CaixaEletronico {
    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        double valor = scan.nextDouble();
       // double valor =378;
        int[] cedulas = {50,10,2};
        String[] ponto ={", "," e "," "};
       // System.out.println("sinal "+ Math.signum(valor)); //verifica o sinal positivo ou não
        if(valor % 2 ==0 && Math.signum(valor) ==1.0 ){
		for(int i = 0; i < cedulas.length; i++){
			if( valor >= cedulas[i] ){
				System.out.print( (int)valor/cedulas[i] + " notas de R$" + cedulas[i]+ponto[i]);
				valor = valor % cedulas[i];                               
			}
			
		}	
	
	}else{
                    System.out.println("Valor Invalido");
                }
    }
    
}
```
### Q12 Área do Triângulo
Considere um triângulo cujos lados sejam designados por ,  e . Considere ainda que . ![areaTriangulo](https://user-images.githubusercontent.com/33138839/230797552-8ef8ab01-db82-456a-aed4-77969a72a8aa.png)
A área do triângulo pode ser calculada usando a seguinte fórmula:
![areaTriangulo2](https://user-images.githubusercontent.com/33138839/230797579-52c782ce-0b1c-4b5e-b95a-031889016858.png)
Escreva um programa em Java (nome da classe: AreaTriangulo) que leia os comprimentos dos lados de um triângulo e mostre a sua área com duas casas decimais. Assuma que as entradas podem também corresponder a um triângulo inválido. Neste caso, imprima a mensagem "Triangulo invalido".
Exemplo de entrada e saída esperada:
Entrada: 4 8 6
Saída: 11.62
Dicas:
Em um triângulo, a soma dos comprimentos de quaisquer dois lados é maior que o comprimento do terceiro lado [Wiki].
Para calcular uma raiz quadrada em Java, usa-se o método sqrt(double a) da classe Math. Exemplo: double raiz = Math.sqrt(24601);
Para imprimir algo formatado em Java, use o método System.out.printf(String format, Object... args). Exemplo: System.out.printf("%.3f\n", media);
Você pode representar os números reais usando float ou double.
Em Java, um número real isolado (e.g., 1.21) é considerado como sendo do tipo double. Para usar um número como sendo do tipo float, use o 'f' ao final do número (e.g., 1.21f).
Java converte automaticamente tipos quando não há perda de precisão. Exemplo: double nota = 8.7f; // Converte de float para double automaticamente
Entretanto, quando há perda de precisão, isso não é possível e o uso do cast é obrigatório. Exemplo: float nota = (float) 8.7; // Converte de double para float usando o cast
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AreaTriangulo.java"
Nota da questão 0.0 / 0.2
```
public class AreaTriangulo {
    public static void main(String[] args) {
       
      //  System.out.println("Digite a raiz");
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
       
        if (a < (b + c) && b < (a+c) && c < (a+b)){		

            double s = (a+b+c)/2;
            double raiz = Math.sqrt(s*(s-a)*(s-b)*(s-c));
            System.out.printf("%.2f\n", raiz);

        }else{
            System.out.println("Triangulo invalido");
        }     
    }
}
```
### Q13 Soma dos Dígitos
Desenvolva um programa (classe SomaDigitos) que leia um número inteiro a partir do teclado e exiba a soma dos dígitos do número.
Exemplo de entrada e saída esperada:
Entrada: 3141
Saída: 9
Dica:
Use o operador de resto da divisão (%).
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "SomaDigitos.java"
Nota da questão 0.0 / 0.2
```
public class SomaDigitos {
    public static List<Integer> SeparaDigitos(int valor) {
        List<Integer> numerosGerados = new ArrayList<>();
        int positivo = Math.abs(valor);
        int tamanho = (int)(Math.log10(positivo) + 1);
        int posicao = 0;
        while(posicao < tamanho) {
            int digito = valor / (int)Math.pow(10, tamanho - posicao - 1) * Integer.signum(valor);
            numerosGerados.add(digito);
            valor %= digito * Math.pow(10, tamanho - posicao - 1);
            posicao++;
        }
        return numerosGerados;
    }

    public static void ImprimeSomaLista(List<Integer> lista) {
        int soma = 0;
        for (int item : lista) {
            soma = soma+item;
        }
        System.out.println(soma);
    }
    
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       int a = scan.nextInt();
        ImprimeSomaLista(SeparaDigitos(a));
      
    }
    
}
```
```
public class SomaDigitos {
    public static List<Integer> SeparaDigitos(int valor) {
        List<Integer> numerosGerados = new ArrayList<>();
        int positivo = Math.abs(valor);
        int tamanho = (int)(Math.log10(positivo) + 1);
        int posicao = 0;
        while(posicao < tamanho) {
            int digito = valor / (int)Math.pow(10, tamanho - posicao - 1) * Integer.signum(valor);
            numerosGerados.add(digito);
            valor %= digito * Math.pow(10, tamanho - posicao - 1);
            posicao++;
        }
        return numerosGerados;
    }
    public static List<Integer> SeparaDigitosNegativo(int valor) {
        List<Integer> numerosGerados = new ArrayList<>();
        int positivo = Math.abs(valor);
        int tamanho = (int)(Math.log10(positivo) + 1);
        int posicao = 0;
        while(posicao < tamanho) {
            int digito = valor / (int)Math.pow(10, tamanho - posicao - 1) * (posicao == 0 ? 1 : Integer.signum(valor));
            numerosGerados.add(digito);
            valor %= digito * Math.pow(10, tamanho - posicao - 1);
            posicao++;
        }
        return numerosGerados;
    }
    public static void ImprimeLista(List<Integer> lista) {
        for (int item : lista) {
            System.out.println(item);
        }
        System.out.println();
    }
    public static void ImprimeSomaLista(List<Integer> lista) {
        int soma = 0;
        for (int item : lista) {
            soma = soma+item;
        }
        System.out.println(soma);
    }
    
    public static void main(String[] args) {
       // System.out.println("May the Force be with you");
       // int numero  = 3141
       Scanner scan = new Scanner(System.in);
       int a = scan.nextInt();
        ImprimeSomaLista(SeparaDigitos(a));
      
    }
    
}
```
```
public class SomaDigitos {
    public static void main(String[] args) {
       // System.out.println("May the Force be with you");
       // int numero  = 3141
       Scanner scan = new Scanner(System.in);
       int a = scan.nextInt();
       int soma=0;
       List<Integer> numerosGerados = new ArrayList<>();

        int x = a > 0 ? a : -a;
        do {
            numerosGerados.add(0, x % 10);
            x /= 10;
        } while (x > 0);

        if (a < 0) numerosGerados.set(0, -numerosGerados.get(0));

        for (int item : numerosGerados) {
           // System.out.println(item);
            soma = soma+item;
        }
        System.out.println(soma);
        
    }
    
}
```
### Q14 Área do Círculo, Volume da Esfera
Escreva um programa (classe AreaVolume) que leia o valor de um raio |r|, inserido a partir do teclado. O programa deverá mostrar a área de um círculo com o raio |r| e o volume de uma esfera com raio , de acordo com o exemplo abaixo. Para esta questão, use apenas variáveis do tipo double.
### Exemplo de entrada e saída esperada:
* Entrada: 45
* Saída: Um circulo com raio de 45.00 centimetros tem uma area de 6361.73 centimetros quadrados.
	Uma esfera com raio de 45.00 centimetros tem um volume de 381703.51 centimetros cubicos.
### Fórmulas:
* A área de um círculo é dada pela fórmula . ![area](https://user-images.githubusercontent.com/33138839/230807998-97708771-0c0f-4bbf-8192-4dbe16c582c7.png)
* O volume de uma esfera é dada pela fórmula . ![volume](https://user-images.githubusercontent.com/33138839/230808022-f00a3cba-201e-4df4-8f2d-0135884b0581.png)
### Dicas:
Use apenas variáveis do tipo double para não perder precisão e não dar erro na correção automática.
Use a constante PI presente na classe Math do Java para pegar o valor de . Exemplo: double pi = Math.PI;
Note que em Java, 1/3 = 1, enquanto que 1.0/3.0 = 1.333.
Para calcular uma exponenciação em Java, usa-se o método pow(double a, double b) da classe Math. Exemplo: double exp = Math.sqrt(2, 8);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AreaVolume.java"
Nota da questão 0.0 / 0.2
```
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class AreaVolume {
    public double raio;
    double pi = Math.PI;
    public AreaVolume() {
    }

    public AreaVolume(double raio) {
        this.raio = formata(raio);
    }
    // HALF_EVEN arredondamento sempre deve acontecer para o valor mais próximo
     public double formata(double valor){
        BigDecimal big = new  BigDecimal(valor).setScale(2, RoundingMode.HALF_EVEN);
        return big.doubleValue();
    }
    
    public double getArea() {		
		double area = pi * Math.pow(raio, 2);
		return formata(area);
	}
    
    public double getVolume(){
            double volume = (4.0/3.0 * pi * Math.pow(raio, 3));
        return formata(volume);
        
    }
    public String formataArea(double raio){
        DecimalFormat df = new DecimalFormat("###.00");
          df.setRoundingMode(RoundingMode.UP);
        return df.format(raio);
    }
    @Override
    public String toString() {
        String st1 = "Um circulo com raio de "+formataArea(raio)+" centimetros tem uma area de "+getArea()+" centimetros quadrados.";
        String st2 = "Uma esfera com raio de "+formataArea(raio)+" centimetros tem um volume de "+getVolume()+" centimetros cubicos.";
        return  st1+"\n"+st2;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double valor = scan.nextDouble();
        AreaVolume av = new AreaVolume(valor);
        System.out.println(av.toString());
    
    }
}
```
### Q15 Rota Ortodrômica
Como o GoogleMaps calcula a distância entre dois pontos na superfície da Terra? A superfície da Terra é curva, e a distância entre os graus de longitude varia com a latitude. Como resultado, encontrar a distância entre dois pontos na superfície da Terra é mais complicado do que simplesmente usando o Teorema de Pitágoras. Para isso, usamos Rotas Ortodrômicas: sejam  e  a latitude e longitude de dois pontos  e  na superfície da Terra. A distância  entre esses pontos, na superfície da Terra, em km é dada por:

onde  é o raio médio da Terra.
Escreva um programa (classe RotaOrtodromica) em que o usuário digite a latitude e longitude de dois pontos na Terra em graus. Seu programa deve exibir a distância entre os pontos, na superfície da Terra, em quilômetros, de acordo com o exemplo abaixo. Para esta questão, use apenas variáveis do tipo double.
Exemplo de entrada e saída esperada:
Entrada: 28.485867 -80.544439 -3.088144 -59.964330
Saída: A distancia entre os pontos (28.485867, -80.544439) e (-3.088144, -59.964330) e de 4142.52 km
Dicas:
Use apenas variáveis do tipo double para não perder precisão e não dar erro na correção automática.
Funções trigonométricas do Java operam em radianos. Como resultado, você vai precisar converter a entrada do usuário de graus para radianos antes de calcular a distância. Para isso, use o método toRadians(double angdeg) da classe Math. Exemplo: double radians = Math.toRadians(45);
Use os métodos trigonométricos da classe Math para calcular o seno – Math.sin(double a), cosseno – Math.cos(double a) e arco cosseno – Math.acos(double a).
Note que, na saída, as coordenadas possuem 6 casas decimais, enquanto que a distância possui duas casas decimais.
É possível ver as coordenadas de um local na URL do Google Maps. É possível pesquisar uma coordenada no Google Maps.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "RotaOrtodromica.java"
Nota da questão 0.0 / 0.2
```
a
```
### Q16 Ponto e Reta
Faça um programa (classe PontoReta) para indicar se um ponto  do plano cartesiano pertence à reta . Sua saída deverá ser de acordo com os exemplos abaixo.
Exemplos de entrada e saída esperada:
Entrada: 0.5 2.0
Saída: Ponto (0.5, 2.0) pertence a reta 2x + y = 3.
Entrada: 6.0 3.8
Saída: Ponto (6.0, 3.8) nao pertence a reta 2x + y = 3.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "PontoReta.java"
Nota da questão 0.0 / 0.2
```
a
```
### Q17 Desconto
Para atrair mais clientes, uma loja de roupas oferece um desconto de 5% em compras de R$200,00 ou mais. Escreva um programa (classe Desconto) que lê o preço sem desconto de uma compra e imprime o valor a ser pago pelo cliente (com duas casas decimais).
Exemplo de entrada e saída esperada:
Entrada: 320.99
Saída: 304.94
Dica:
A classe Scanner, usada para ler dados do teclado, usa as configurações do sistema para setar o formato dos números reais. Dependendo da linguagem do seu sistema, um número real pode usar "." (ponto) ou "," (vírgula).
Você pode representar os números reais usando float ou double.
Em Java, um número real isolado (e.g., 1.21) é considerado como sendo do tipo double. Para usar um número como sendo do tipo float, use o 'f' ao final do número (e.g., 1.21f).
Java converte automaticamente tipos quando não há perda de precisão. Exemplo: double nota = 8.7f; // Converte de float para double automaticamente
Entretanto, quando há perda de precisão, isso não é possível e o uso do cast é obrigatório. Exemplo: float nota = (float) 8.7; // Converte de double para float usando o cast
Para imprimir algo formatado em Java, use o método System.out.printf(String format, Object... args). Exemplo: System.out.printf("%.3f\n", media);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Desconto.java"
Nota da questão 0.0 / 0.2
```
a
```
### Q18 Tanque de Combustível
Um tanque de combustível tem o formato esférico. Escreva um programa (classe TanqueCombustivel) que leia o valor do raio () do tanque, o valor da altura do ar () e a opção para saber se deseja calcular o volume de ar (opção 1) ou o volume de combustível no tanque (opção 2).

Figura: tanque de combustível
A saída do programa deverá ser o volume conforme a opção selecionada, com quatro casas decimais de precisão. Não é necessário verificar situações inválidas (opções diferentes de 1 ou 2, ou valores de altura maiores que o raio da esfera).
Fórmulas:
Volume da esfera de raio : 
Volume da calota esférica de raio  e altura : 
Exemplos de entrada e saída esperada:
Entrada: 30 27 1
Saída: 48094.6419
Entrada: 30 27 2
Saída: 65002.6936
Dica:
O volume de ar corresponde à formula da calota esférica. Já o volume do combustível corresponde ao complemento do volume da calota esférica em relação ao volume total da esfera.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "TanqueCombustivel.java"
Nota da questão 0.0 / 0.2
```
a
```
### Q19 Tipo do Triangulo
Escreva um programa (classe TipoTriangulo) que leia as medidas dos três lados de um triângulo, fornecidas pelo usuário, em qualquer ordem, e imprima o nome do tipo de triângulo: "equilatero" (todos os três lados iguais), "isosceles" (apenas dois lados iguais), ou "escaleno" (nenhum par de lados iguais).
Se pelo menos um dos lados for negativo ou os três lados não formarem um triângulo, o programa deverá imprimir a mensagem "invalido" na tela.
Dicas:
A saída é em minúsculo, sem acentos.
Em um triângulo, a soma dos comprimentos de quaisquer dois lados é maior que o comprimento do terceiro lado [Wiki].
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "TipoTriangulo.java"
Nota da questão 0.0 / 0.2
### Q20 Animais nas Cédulas do Real
As cédulas do real começaram a entrar em circulação no Brasil em 1994. Diferentemente das moedas que haviam circulado anteriormente, o real não traz na sua nota personalidades da história nacional, mas sim animais da fauna brasileira, conforme mostra a tabela abaixo.
<table border=1>
    <tr>
        <td>Animal</td>
        <td>Valor da Cédula</td>
    </tr>
    <tr>
        <td>Tartaruga</td>
        <td>R$ 2</td>
    </tr>
    <tr>
        <td>Garça</td>
        <td>R$ 5</td>
    </tr>
    <tr>
        <td>Arara</td>
        <td>R$ 10</td>
    </tr>
    <tr>
        <td>Mico-leão-dourado</td>
        <td>R$ 20</td>
    </tr>
    <tr>
        <td>Onça-pintada</td>
        <td>R$ 50</td>
    </tr>
    <tr>
        <td>Garoupa</td>
        <td>R$ 100</td>
    </tr>
    
</table>
	
Escreva um programa (classe AnimaisCedulas) que leia o valor de uma cédula e apresente na tela o nome do animal representado no verso da nota. Se não existir uma cédula no valor inserido, o programa deverá imprimir "erro".
### Dica:
A saída é com acentos e com a primeira letra em maiúsculo.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AnimaisCedulas.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q21 Conta de Energia
Escreva um programa (classe ContaEnergia) que determine o preço a pagar pelo fornecimento de energia elétrica. Como entrada, ele deve receber o consumo de energia (em kWh) e o tipo de instalação (R para residências, I para indústrias, e C para comércios). Use a tabela a seguir para calcular o preço devido:
Preço por tipo e faixa de consumo
Tipo	Faixa (kWh)	Preço
Residencial	Até 500	R$ 0,40
Acima de 500	R$ 0,65
Comercial	Até 1000	R$ 0,55
Acima de 1000	R$ 0,60
Industrial	Até 5000	R$ 0,55
Acima de 5000	R$ 0,60
A saída deve ter duas casas decimais. Caso algum valor inválido seja inserido, o programa deve imprimir -1.00.
### Exemplo de entrada e saída esperada:
Entrada: 6340 R
Saída: 4121.00
Dica:
A classe Scanner não possui o método nextChar(). Para ler um caractere do teclado use: char tipo = scan.next().charAt(0);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "ContaEnergia.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q22 Volume de Combustível
Considere um tanque de combustível com o formato descrito na figura abaixo.

Figura: tanque de combustível
Escreva um programa (classe VolumeCombustivel) que calcule o volume de combustível (em litros), com três casas decimais de precisão, dadas as medidas (em metros) de altura total do tanque (), nível de combustível no tanque () e raio dos bojos semi-esféricos (). Caso algum dos dados sejam inválidos, a saída deve ser -1.000.
Fórmulas:

Figura: esfera
Volume da esfera de raio : 
Volume da calota esférica de raio  e altura : 
Volume do cilindro de raio  e altura : 
Dicas:
Verifique as diversas possibilidades do nível de combustível  em relação à altura do tanque .
Desenhe! Use papel e caneta para melhor visualizar as diversas variáveis e diferentes casos.
Use a constante PI presente na classe Math do Java para pegar o valor de . Exemplo: double pi = Math.PI;
Para calcular uma exponenciação em Java, usa-se o método pow(double a, double b) da classe Math. Exemplo: double exp = Math.sqrt(2, 8);
Exemplo de entrada e saída esperada:
Entrada: 50 40 10
Saída: 11519.173
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "VolumeCombustivel.java"
Nota da questão 0.0 / 0.3
### Q23 Soma de uma Coleção
Escreva um programa (classe SomaColecao) que calcula a soma de uma coleção de valores digitados pelo usuário. O usuário irá inserir -1 para indicar que não há mais valores a serem fornecidos.
Exemplo de entrada e saída esperada:
Entrada: 1 2 3 4 -1
Saída: 10
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "SomaColecao.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q24 Soma de Várias Coleções
Escreva um programa (classe SomaColecoes) que calcula a soma de várias coleções de valores digitados pelo usuário. O usuário irá inserir -1 para indicar o fim de uma coleção e o início da próxima. Uma coleção sem elementos indica o final do programa.
Exemplo de entrada e saída esperada:
Entrada: 20 30 40 -1 8 7 64 -1 38 26 15 95 -1 -1
Saída: 90
79
174
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "SomaColecoes.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q25 Média de uma Coleção
Escreva um programa (classe MediaColecao) que calcula a média de uma coleção de valores digitados pelo usuário, com precisão de duas casas decimais. O usuário irá inserir -1 para indicar que não há mais valores serem fornecidos.
Exemplo de entrada e saída esperada:
Entrada: 5 3 9 3 1 -1
Saída: 4.20
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "MediaColecao.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q26 Aproximação de PI 
O valor de  pode ser aproximado pela seguinte série infinita:

Escreva um programa (classe AproximacaoPi) que exibe  aproximações de , sendo  um número natural inserido pelo usuário. A primeira aproximação deve fazer uso de apenas o primeiro termo da série infinita (número 3). Cada aproximação adicional indicada pelo seu programa deve incluir mais um termo na série, fazendo uma melhor aproximação de  cada vez que um termo é incluído na soma. Utilize até seis casas decimais de precisão. Para esta questão, use apenas variáveis do tipo double.
Dica:
Use apenas variáveis do tipo double para não perder precisão e não dar erro na correção automática.
Determine o termo geral da série antes de começar a programar.
Exemplos de entrada e saída esperada:
Entrada: 1
Saída: 3.000000
Entrada: 2
Saída: 3.000000
3.166667
Entrada: 5
Saída: 3.000000
3.166667
3.133333
3.145238
3.139683
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AproximacaoPi.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q27 Aproximação do Número E 
O número , o número neperiano, pode ser calculado através da seguinte série de Taylor:

Escreva um programa (classe NumeroNeperiano) que leia um número k, digitado pelo usuário, e informe o valor aproximado dessa série para a soma dos seus k primeiros termos, com seis casas decimais de precisão. Para esta questão, use apenas variáveis do tipo double.
Dica:
Use apenas variáveis do tipo double para não perder precisão e não dar erro na correção automática.
Determine o termo geral da série antes de começar a programar.
Java não possui uma implementação do cálculo de fatorial. Você precisará implementar dentro do seu main ou criar um método (função) para fazer isso.
Exemplos de entrada e saída esperada:
Entrada: 1
Saída: 1.000000
Entrada: 2
Saída: 2.000000
Entrada: 3
Saída: 2.500000
Entrada: 20
Saída: 2.718282
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "NumeroNeperiano.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q28 Aproximação do Seno
O seno de um ângulo , medido em radianos, , pode ser calculado através da seguinte série de Taylor:

Escreva um programa (classe AproximacaoSeno) que leia um ângulo, medido em graus, e o número k de termos da série, nessa ordem, e imprima o valor da série com dez casas decimais de precisão para cada um dos termos, de 1 a k. Para esta questão, use apenas variáveis do tipo double.
Dicas:
Use apenas variáveis do tipo double para não perder precisão e não dar erro na correção automática.
Determine o termo geral da série antes de começar a programar.
Use o double, devido à precisão pedida.
Para converter a entrada do usuário de graus para radianos use o método toRadians(double angdeg) da classe Math. Exemplo: double radians = Math.toRadians(45);
Java não possui uma implementação do cálculo de fatorial. Você precisará implementar dentro do seu main ou criar um método (função) para fazer isso.
Exemplos de entrada e saída esperada:
Entrada: 45 2
Saída: 0.7853981634
0.7046526512
Entrada: 90 8
Saída: 1.5707963268
0.9248322293
1.0045248555
0.9998431014
1.0000035426
0.9999999437
1.0000000007
1.0000000000
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AproximacaoSeno.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q29 Porcentagem de Acerto
As respostas de um candidato a uma prova de múltipla escolha são guardadas em um vetor. O gabarito é guardado em outro vetor de mesmo tamanho. Escreva um programa (classe PorcentagemAcerto) que leia o vetor de respostas e o vetor do gabarito, nessa ordem, e imprima na saída a porcentagem de acerto do candidato, com duas casas decimais de precisão. Considere que os dois vetores inseridos são sempre do mesmo tamanho, possuem pelo menos um elemento e, para indicar o fim do vetor, o número -1 é inserido.
Exemplo de entrada e saída esperada:
Entrada: 1 2 3 4 5 -1 1 2 3 1 1 -1
Saída: 60.00
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "PorcentagemAcerto.java"
Nota da questão 0.0 / 0.3
```
a
```
### Q30 Área do Polígono
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
Fonte:
Hanly & Koffman. “Problem Solving and Program Design in C”, 5th edition. Pearson, 2007. (p. 423)
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AreaPoligono.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q31 Data por Extenso
Escreva um programa em Java (classe DataExtenso) que leia do teclado uma data no formato "ddmmaaaa" e imprima essa data por extenso (suponha valores sempre válidos).
Exemplo de entrada e saída esperada:
Entrada: 21102015
Saída: 21 de outubro de 2015
Dicas:
Existem diversas formas de se isolar os números. Sugestão - implemente e teste as duas formas diferentes abaixo:
Leia a data como uma String e use o método substring(int beginIndex, int endIndex) da classe String para isolar os valores e o método parseInt(String s) da classe Integer para converter de String para int. Exemplo:
    String valorStr = "24601";
    String numStr = valorStr.substring(2, 5); // Pega os caracteres 2 a 5 "601"
    int num = Integer.parseInt(numStr);       // Converte a String "601" para o int 601
Leia a data como um int e use operações de divisão e resto para isolar o dia/mês/ano. Esta é a forma mais eficiente.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "DataExtenso.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q32 Cifra de César
A criptografia tem por objetivo esconder o significado de uma mensagem para um possível interceptador. Para tanto, os caracteres do texto podem ser misturados de acordo com um protocolo (algoritmo) previamente estabelecido entre emissor e receptor. Assim, o receptor da mensagem pode reverter o protocolo misturador e tornar a mensagem compreensível.
Uma maneira de se criptografar uma mensagem é substituir o "alfabeto original" por um "alfabeto cifrado", deslocado por um determinado número de letras (5, no exemplo abaixo), em relação ao alfabeto original. O registro mais antigo desse procedimento é atribuído ao general romano Júlio César (100-44 a.C.). Por isso, ele é conhecido como Cifra de César. Por convenção, escreve-se o alfabeto original em minúsculas e o alfabeto cifrado em maiúsculas.
Exemplo da Cifra de César (Código: 5):
Alfabeto original: a b c d e f g h i j k l m n o p q r s t u v w x y z
Alfabeto cifrado: F G H I J K L M N O P Q R S T U V W X Y Z A B C D E
Texto original: v o v o  v i u  a  u v a
Texto cifrado: A T A T  A N Z  F  Z A F
Escreva um programa (classe CifraCesar) que leia o valor do deslocamento (tal como 5 no exemplo acima) e depois leia um texto a ser codificado. A saída deve ser o texto criptografado segundo a Cifra de César explicada acima.
Independentemente dos caracteres de entrada, a saída deverá ser apresentada em caracteres MAIÚSCULOS. Durante a criptografia, ignore qualquer caractere que não seja uma letra do alfabeto, tais como números, pontuação e caracteres com acentos. Estes deverão ser repetidos na saída tal qual foram inseridos na entrada.
Exemplo de entrada e saída esperada:
Entrada: 12 it's an older code, sir, but it checks out
Saída: UF'E MZ AXPQD OAPQ, EUD, NGF UF OTQOWE AGF
Entrada: 4 well... here we are all together for the first time
Saída: AIPP... LIVI AI EVI EPP XSKIXLIV JSV XLI JMVWX XMQI
Dicas:
Note que, em Java, uma String usa aspas duplas (e.g., "string"), enquanto que um char usa aspas simples (e.g., 'c').
Para ler uma string que possui espaços, use o método nextLine() da classe Scanner. Exemplo: String linha = scan.nextLine();
Para pegar um caractere de uma String usando seu índice, use o método charAt(int index) da classe String. Exemplo: char carac = textoLimpo.charAt(i);
Assim como em outras linguagens, um char em Java é um número inteiro de acordo com a Tabela ASCII. Você pode fazer:
operações matemáticas. Exemplo: carac - 'a';
comparações de um caractere com um número. Exemplo: carac > 65
comparações entre caracteres. Exemplo: carac > 'a'
Uma maneira de encontrar a letra do alfabeto cifrado que vai além da letra 'Z' é utilizando o resto da divisão com o número total de letras do alfabeto. Exemplo: 
   char cCifrado;
   cCifrado = (char) (cOriginal - 'a');          // Conv. de char para int entre 0-26
   cCifrado = (char) ((cCifrado + desloc) % 26); // Pega a letra cifrada como int entre 0-26
   cCifrado += 'A';                              // Conv. de int entre 0-26 para char entre A-Z
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "CifraCesar.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q33 Palíndromos
Um palíndromo é uma sequência de caracteres cuja leitura é idêntica se feita da direita para esquerda ou vice−versa. Por exemplo: "OSSO" e "OVO" são palíndromos. Em textos mais complexos, espaços, acentos e pontuação são ignorados. A frase "SUBI NO ONIBUS" é o exemplo de uma frase palíndroma onde os espaços foram ignorados.
Escreva um programa (classe Palindromos) que leia uma sequência de caracteres. Em seguida, o programa deve imprimir a mesma sequência em letras maiúsculas com os espaços removidos e informar se ela é um palíndromo (saída 1) ou não (saída 0).
Exemplos de entrada e saída esperada:
Entrada: A Rara Arara
Saída: ARARAARARA 1
Entrada: Tecnicas Avancadas de Programacao
Saída: TECNICASAVANCADASDEPROGRAMACAO 0
Entrada: a torre da derrota
Saída: ATORREDADERROTA 1
Dicas:
Para ler uma string que possui espaços, use o método nextLine() da classe Scanner. Exemplo: String linha = scan.nextLine();
Para converter uma string para maiúscula, use o método toUpperCase() da classe String. Exemplo: String linhaMaiusc = linha.toUpperCase();
Use o método replace(CharSequence target, CharSequence replacement) da classe String para remover os espaços. Exemplo: linha = linha.replace(" ", "");
Para pegar um caractere de uma String usando seu índice, use o método charAt(int index) da classe String. Exemplo: char carac = textoLimpo.charAt(i);
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Palindromos.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q34 Operações em Números Inteiros
Escreva programa em Java (classe OperacoesInteiros) que leia do teclado um vetor de inteiros. Em seguida, o programa deve imprimir na ordem:
Quantidade de elementos
Quantos são pares
Quantos são ímpares
Soma total
Média (duas casas decimais)
Maior
Menor
O final de um vetor é determinado pelo número -1. Seu programa deve repetir esse procedimento indefinidamente para diversos vetores, de tamanhos variados, até que um vetor sem elementos seja inserido, terminando a execução do programa.
Exemplo de entrada e saída esperada:
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
Nota da questão 0.0 / 0.4
```
a
```
### Q35 Mediana de uma Coleção
A Mediana é uma forma de resumir os valores típicos associados com os membros de uma população (Wiki).
A mediana de um conjunto ordenado com número de elementos ímpar é o valor do elemento na posição central. Por exemplo, para o conjunto {1, 3, 5, 7, 9}, a mediana será o elemento na posição 3, i.e., o elemento com valor 5. Já a mediana de um conjunto ordenado com número de elementos par é a média dos dois elementos centrais. Por exemplo, para o conjunto {1, 2, 5, 8, 9, 10}, a mediana será a média entre os elementos nas posições 3 e 4, i.e., 6.5.
Escreva um programa em Java (classe Mediana) que leia do teclado um vetor de inteiros já ordenados e imprima a mediana (sempre com uma casa decimal). O final de um vetor é determinado pelo número -1.
Exemplos de entrada e saída esperada:
Entrada: 2 4 5 7 9 12 15 -1
Saída: 7.0
Entrada: 4 7 16 25 32 45 -1
Saída: 20.5
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Mediana.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q36 Time de Futebol
Os resultados das partidas de um time de futebol ao longo de um campeonato são armazenados em dois vetores de mesmo tamanho. O primeiro vetor guarda o número de gols efetuados por esse time em cada partida. O segundo vetor guarda o número de gols efetuados pelo time adversário. Uma posição  de cada vetor indica a -ésima partida realizada.
Escreva um programa (classe TimeFutebol) que leia esses dois vetores, na ordem em que foram explicados. Como saída, deve ser informado em uma única linha os seguintes dados, em ordem, em relação ao time:
Número de vitórias
Número de empates
Número de derrotas
Considere que o final de um vetor é indicado pelo número -1 e as entradas fornecidas são sempre válidas, i.e., o tamanho dos dois vetores de gols são iguais e cada elemento do vetor, que indica o número de gols, é um inteiro não-negativo.
Exemplo de entrada e saída esperada:
Entrada: 4 0 2 3 1 3 -1 0 0 2 5 1 2 -1
Saída: 2 3 1
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "TimeFutebol.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q37 Aprovação em Disciplina
Na Universidade Federal do Amazonas, um aluno é aprovado em uma disciplina se atender a dois critérios: ter média igual ou superior a 5.0 e ter frequência igual ou superior a 75% da carga horária. Se sua frequência for menor que esse limiar, o aluno é reprovado por frequência, independentemente da sua nota. Por fim, o aluno é reprovado por nota se, tendo comparecido ao número mínimo de aulas, não atingiu a média exigida.
As notas dos alunos de uma classe são guardadas em um vetor de reais. A quantidade de presenças às aulas (em horas) é armazenada em outro vetor de mesmo tamanho, mas contendo elementos inteiros.
Escreva um programa (classe AprovacaoDisciplina) que leia o vetor de notas (reais), o vetor de presença (inteiros) e a carga horária da disciplina (inteiro), nessa ordem, usando o número -1 para indicar o final de um vetor. Como saída, deve ser informado, em uma única linha, os seguintes dados em ordem:
Número de alunos aprovados
Número de alunos reprovados por nota
Número de alunos reprovados por frequência
Considere que as entradas fornecidas são sempre válidas: notas entre 0.0 e 10.0, frequência entre 0 e a carga horária, tamanhos iguais dos vetores de notas e frequência.
Exemplo de entrada e saída esperada:
Entrada: 10.0 10.0 9.0 -1 44 45 46 -1 60
Saída: 2 0 1
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "AprovacaoDisciplina.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q38 Dia da Semana
Suponha que as horas de trabalho semanais dos funcionários de uma empresa são armazenadas em uma tabela semelhante à do exemplo abaixo. Cada linha registra o número de horas trabalhadas por um funcionário em sete colunas, uma para cada dia da semana, de domingo a sábado. Por exemplo, a tabela a seguir armazena as horas de trabalho para quatro funcionários.
 	DOM	SEG	TER	QUA	QUI	SEX	SAB
Funcionário 0	2	4	3	4	5	8	8
Funcionário 1	7	3	4	3	3	4	4
Funcionário 2	3	3	4	3	3	2	2
Funcionário 3	9	3	4	7	3	4	1
Escreva um programa (classe DiaSemana) que leia uma matriz Nx7, sendo N>1, e imprima qual(is) o(s) dia(s) da semana em que os funcionários mais trabalham. A saída do programa deverá ser um número inteiro de 1 a 7, indicando respectivamente domingo, segunda, ..., sábado. Entretanto, se houver coincidência de dois ou mais dias serem igualmente os de mais horas trabalhadas, os números correspondentes a todos eles devem ser impressos (um em cada linha).
Considere o número -1 como o final da entrada, ou seja, os 7 primeiros números correspondem ao Funcionário 0, seguido dos 7 números para o Funcionário 1, e assim por diante.
Exemplos de entrada e saída esperada:
Entrada: 2 4 3 4 5 8 8 7 3 4 3 3 4 4 3 3 4 3 3 2 2 9 3 4 7 3 4 1 -1
Saída: 1
Entrada: 2 2 3 4 5 8 8 7 7 4 3 3 4 4 3 3 4 3 3 2 2 9 9 4 7 3 4 1 -1
Saída: 1
2
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "DiaSemana.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q39 Distância Percorrida pelo Avião
O tempo que um determinado avião dispensa para percorrer o trecho entre duas cidades distintas está disponível através da seguinte tabela:
 	111	222	333	444	555	666	777
111	0	2	11	6	15	11	1
222	2	0	7	12	4	2	15
333	11	7	0	11	8	3	13
444	6	12	11	0	10	2	1
555	15	4	8	10	0	5	13
666	11	2	3	2	5	0	14
777	1	15	13	1	13	14	0
Escreva um programa que, tendo a tabela acima armazenada como uma matriz, leia uma sequência de números correspondentes às cidades dessa tabela até que o número -1 seja lido. Em seguida, mostre ao usuário o tempo necessário para percorrer o circuito de cidades por ele informadas.
Exemplos de entrada e saída esperada:
Entrada: 222 444 333 555 -1
Saída: 31
Entrada: 777 111 777 -1
Saída: 2
Dica:
Em Java, você pode inicializar um vetor ou matriz diretamente com seus dados. Exemplo de inicialização de um vetor: int[] code = { 4, 5, 1 };
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "DistanciaAviao.java"
Nota da questão 0.0 / 0.4
```
a
```
### Q40 Fração Contínua: Raiz Quadrada de Dois
Contextualização
Seja  o conjunto dos números inteiros. Sabemos que a quantidade de elementos em  é infinita. Contudo, tomando-se dois números inteiros  e  quaisquer, com , teremos uma quantidade finita de elementos  tais que , ou seja, compreendidos entre  e . Por outro lado, no conjunto  dos números reais, tomando-se dois elementos  e  quaisquer, com , teremos uma quantidade infinita de elementos  tais que . Esse fato dificulta a representação de números reais em máquinas com recursos limitados de armazenamento, tais como os computadores. Uma vez que a memória de qualquer computador é finita, não há como representar nela todos os números reais, cuja quantidade é infinita.
Uma maneira de contornar esse problema é utilizar frações contínuas (assunto desta questão) para representar números reais, pois elas nos fornecem aproximações racionais surpreendentemente boas de números reais, além de serem conceitualmente simples. De um modo geral, uma fração contínua é uma expressão da seguinte forma:

Note que a expressão acima também é infinita, tal como uma dízima periódica.
Quando usamos um algoritmo para computar uma série infinita, como a série  abaixo, nós conhecemos o primeiro termo (neste caso, é o termo 1), mas não conhecemos o último termo.

Por outro lado, quando usamos um algoritmo para computar uma fração contínua, como no exemplo abaixo, nós não conhecemos o primeiro termo, pois ele remonta ao infinito (simbolizado pelo ):

Por conta disso, ao tratar frações contínuas de forma algorítmica, somos obrigados a arbitrar um começo qualquer, o qual chamamos de "semente". Embora a escolha da semente seja arbitrária, o que influencia a qualidade da aproximação é o número de passos (divisões) que resolvemos a fração contínua. Escolhamos apenas um passo:

Por exemplo, se arbitrarmos que semente=10, o resultado aproximado da fração acima será o seguinte:

distante do valor esperado, que é . Contudo, usando esse mesmo valor de semente na aproximação abaixo,

o resultado será , que é bem mais próximo do valor esperado.
Além disso, note que a fração contínua de  é composta por duas partes:
Constante: o número  logo após o sinal de "aproximado".
Cíclica: 
Problema
Escreva um programa (classe RaizDois) que leia um número N do teclado e determine o valor de  através da sua expansão em fração contínua com N termos. Na saída, devem ser mostrados os resultados intermediários, com 14 casas decimais de precisão. Utilize uma semente igual a 1. Para esta questão, use apenas variáveis do tipo double.

Dicas:
Use apenas variáveis do tipo double para não perder precisão e não dar erro na correção automática.
Na expressão da fração contínua, identifique qual a parte constante e qual a parte que se repete. Esta última deverá ser controlada por uma variável acumuladora dentro de um laço de repetição.
Utilize uma variável acumuladora para guardar o valor parcial da parte cíclica, e uma variável contadora para controlar o número de iterações. Note que elas são independentes uma da outra.
Para ter 14 casas decimais, o uso do double é obrigatório, uma vez que o float não tem essa precisão.
Exemplos de entrada e saída esperada:
Entrada: 1
Saída: 1.33333333333333
Entrada: 2
Saída: 1.33333333333333
1.42857142857143
Entrada: 5
Saída: 1.33333333333333
1.42857142857143
1.41176470588235
1.41463414634146
1.41414141414141

Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
```
a
```
