# Laboratório 4: Coleções Genéricas I (Desafio)
### Objetivo
Modelagem e implementação de classes em Java que usam listas implementadas pela Java Collections Framework.
### Descrição
* Neste trabalho, você implementará as classes necessárias para representar Iniciados Jedi em uma Sessão Jedi.
* Irá descrever atributos e implementar métodos e construtores com base em um diagrama de classes da UML.
* Em seguida, objetos serão criados a partir das classes implementadas.
* Nesta abstração, uma Sessão Jedi possui um Mestre Jedi e uma lista de Iniciados Jedi.
### Passos Iniciais
* Inicie o Eclipse. Vá em "File" → "New" → "New Java Project". Nome do projeto: "TAP-ColecoesGenericasI".
Na parte Module (parte de baixo da janela), desselecione "Create module-info.java file".
* Nas questões a seguir, será pedido para criar diversas classes. Para isso, vá em "File" → "New" → "Class".
Deixe o campo "package" em branco.
* O Eclipse compila automaticamente as classes sempre que você salva. Para executar e testar, basta ir em "Run" → "Run" (Ctrl+F11).
* A saída e entrada do programa será feita através da aba "Console" do Eclipse.
Nota da questão 0.0 / 2.5
### Q1 Classe IniciadoJedi
![Screenshot from 2023-04-12 01-08-00](https://user-images.githubusercontent.com/33138839/231367469-86fbcc62-7f63-4d1a-b2bd-7db4fb129543.png)

Crie uma classe para representar o IniciadoJedi. Os atributos de um objeto da classe IniciadoJedi poderão ser setados diretamente (e.g., iniciado1.nome="Katooni") ou pelo método construtor. Use a técnica de encadeamento de construtores para criar os construtores da classe, semelhante ao feito em sala e mostrado nos slides.
Implemente os métodos:
* getAnoNascimento: retorna uma String contendo o ano de nascimento do Iniciado Jedi seguido da sigla ABY ("Antes da Batalha de Yavin". caso o anoNacimento seja negativo) ou DBY ("Depois da Batalha de Yavin", caso o anoNascimento seja positivo). Exemplo: "23 ABY", para um anoNascimento=-23.
* getDescricao: retorna uma String contendo a descrição completa do Iniciado Jedi de acordo com o exemplo abaixo:
```
Katooni (especie=Tholothian, nascimento=23 ABY)
```
Para testar a classe, crie uma nova classe chamada SessaoJediMain. Nesta classe, crie o método main, que será o ponto de partida do seu programa. No método main, crie um ou mais objetos da classe IniciadoJedi e, em seguida, imprima o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe IniciadoJedi. Não precisa submeter a classe SessaoJediMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "IniciadoJedi.java"
Nota da questão 0.0 / 2.0
```
public class IniciadoJedi {
    String nome;
    String especie;
    int anoNascimento;

    public IniciadoJedi() {
    }

    public IniciadoJedi(String nome, String especie, int anoNascimento) {
        this.nome = nome;
        this.especie = especie;
        this.anoNascimento = anoNascimento;
    }
       
    String getDescricao(){
        String desc =nome+" (especie="+especie+", nascimento="+getAnoNascimento()+")";   
        return desc;
    }
    
    String getAnoNascimento(){
        
        String ano;
        if(anoNascimento>0){
            ano=anoNascimento+" DBY";
       }else{
            
            ano=Math.abs(anoNascimento)+" ABY";
       }
   
        return ano;
    }
   
}

```
### Q2 Classe TreinadorJedi

![Screenshot from 2023-04-12 01-08-11](https://user-images.githubusercontent.com/33138839/231367466-1d7e2625-e2c4-486d-94ed-23eefd5b2747.png)

De forma semelhante às questões anteriores, crie uma classe para representar o <b>TreinadorJedi</b>.
Implemente o método:
getDescricao: retorna uma String contendo a descrição completa do TreinadorJedi de acordo com o exemplo abaixo (onde a titulacao é "Grão-Mestre"):
Grão-Mestre Fae Coven
Para testar a classe, modifique a classe SessaoJediMain, criada na questão anterior, para criar um ou mais objetos da classe TreinadorJedi e, em seguida, imprima o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe TreinadorJedi. Não precisa submeter a classe SessaoJediMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "TreinadorJedi.java"
Nota da questão 0.0 / 4.5
```
public class TreinadorJedi {
    String titulacao;
    String nome;

    public TreinadorJedi() {
    }

    public TreinadorJedi(String titulacao, String nome) {
        this.titulacao = titulacao;
        this.nome = nome;
    }
    
    String getDescricao(){
        String desc = titulacao+" "+nome;
        return desc;
        
    }
}
```
### Q3 Classe SessaoJedi

![Screenshot from 2023-04-12 01-08-21](https://user-images.githubusercontent.com/33138839/231367464-3a43e257-ba5d-40ff-8ee4-537b73f79518.png)

De forma semelhante às questões anteriores, crie uma classe para representar uma SessaoJedi.
Implemente os métodos:
addIniciado: adiciona um IniciadoJedi na lista de iniciados que farão parte da sessão. Caso já exista um iniciado com o mesmo nome, o iniciado não deve ser adicionado.
getIniciado: retorna um IniciadoJedi da lista de iniciados da sessão que possui o nome especificado. Retorna nulo caso o iniciado não pertença à sessão.
getMediaAnoNascimento: retorna a média do ano de nascimento dos iniciados.
getDescricao: retorna uma String contendo a descrição completa da sessão, incluindo as informações (getDescricao) do treinador e dos iniciados participantes, de acordo com o exemplo abaixo:
--> SESSÃO Instruções de Uso da Força (Treinador: Grão-Mestre Fae Coven)
  - Iniciado 1: Katooni (especie=Tholothian, nascimento=23 ABY)
  - Iniciado 2: Byph (especie=Ithorian, nascimento=21 ABY)
  - Iniciado 3: Gungi (especie=Wookiee, nascimento=23 ABY)
  - Iniciado 4: Petro (especie=Human, nascimento=22 ABY)
Para testar a classe, modifique a classe SessaoJediMain, criada nas questões anteriores, para criar um ou mais objetos da classe SessaoJedi. Adicione iniciados às sessões e, em seguida, imprima o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe SessaoJedi. Não precisa submeter a classe SessaoJediMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "SessaoJedi.java"
Nota da questão 0.0 / 0.5
```
public class SessaoJedi {
    String nome;
    TreinadorJedi treinador;
    ArrayList<IniciadoJedi> iniciados = new ArrayList<>();

    public SessaoJedi() {
    }

    public SessaoJedi(String nome, TreinadorJedi treinador) {
        this.nome = nome;
        this.treinador = treinador;
       
    }
    
    void addIniciado(IniciadoJedi iniciado){
       this.iniciados.add(iniciado);
        
    }
    
    IniciadoJedi getIniciado(String nome){
        for(IniciadoJedi iniciadoJedi : iniciados){
            if(iniciadoJedi.nome == nome)
                return  iniciadoJedi;
                }
       
       return null;
    }
    double getMediaAnoNascimento(){
        int idade = 0;
        for(IniciadoJedi iniciadoJedi : iniciados){
            idade +=iniciadoJedi.anoNascimento;
        }
        return idade / iniciados.size();
        
    }
    String getDescricao(){
        StringBuffer  desc = new StringBuffer();
        desc.append("--> SESSÃO "+this.nome+" (Treinador: "+this.treinador.titulacao+" "+this.treinador.nome+ ")");
        int posicao=0;
        for(IniciadoJedi iniciadoJedi : iniciados){
            posicao +=1;
            desc.append("\n");
            desc.append(" - Iniciado "+ posicao +":"+iniciadoJedi.getDescricao());
        }
        return desc.toString();      
    }
}
```
### Q4 Classe SessaoJediMain
Submeta agora a classe SessaoJediMain, usada para testar as questões anteriores.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "SessaoJediMain.java"
Nota da questão 0.0 / 0.5
```
public class SessaoJediMain {
    public static void main(String[] args){
        IniciadoJedi iniciadoJedi = new IniciadoJedi();
        iniciadoJedi.nome ="Oliveira";
        iniciadoJedi.especie = "Tholothion";
        iniciadoJedi.anoNascimento =22;
        
        TreinadorJedi treinador = new TreinadorJedi();
        treinador.nome = "Gungi";
        treinador.titulacao = "T2";
        
        SessaoJedi sessaoJedi = new SessaoJedi();
        sessaoJedi.nome = "jed";
        sessaoJedi.treinador = treinador;
        sessaoJedi.addIniciado(iniciadoJedi);
        
        System.out.println(iniciadoJedi.getDescricao());
        System.out.println(treinador.getDescricao());
        //descricao da Sessão
        System.out.println(sessaoJedi.getDescricao());
        //descrição de um iniciadoJedi
        System.out.println(sessaoJedi.getIniciado(iniciadoJedi.nome).nome);
        //retorno da média da idade
        System.out.println(sessaoJedi.getMediaAnoNascimento());
                
    }
}

```
### Q5 Documentação JavaDoc
Por fim, gere a documentação do seu código através do JavaDoc. No Eclipse, vá em "Project" → "Generate javadoc...". Selecione o seu projeto e os arquivos e clique no botão "Finish".
Para visualizar a documentação, na aba esquerda do Eclipse ("Package Explorer"), abra o diretório "doc" do seu projeto e clique duas vezes no arquivo "index.html".
Após resolver e testar a questão no Eclipse, submeta-o usando os botões abaixo.
Dica: você pode clicar em apenas um dos botões e submeter os vários arquivos solicitados de uma só vez (ou, ainda, você pode arrastar todos os arquivos para esta janela).

```
Enviar "IniciadoJedi.html" Enviar "TreinadorJedi.html" Enviar "SessaoJedi.html" Enviar "SessaoJediMain.html"
//arquivos gerados na pasta apidocs no netbeans
/home/oliveira/NetBeansProjects/TAP-ColecoesGenericasI/target/site/apidocs
```
