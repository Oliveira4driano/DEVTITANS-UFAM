# Laboratório 5: Coleções Genéricas II (Desafio)
### Objetivo
* Modelagem e implementação de classes em Java que usam listas implementadas pela Java Collections Framework.
* Data de entrega: 31/05/2023 23:59:59
### Descrição
* Neste trabalho, você implementará as classes necessárias para representar para um Sistema de Ensalamento. 
Um sistema de ensalamento é responsável por alocar turmas nas salas disponíveis.
* Irá descrever atributos e implementar métodos e construtores com base em um diagrama de classes da UML.
* Em seguida, objetos serão criados a partir das classes implementadas.
* Nesta abstração, o ensalamento possui uma lista de salas, uma lista de turmas, e uma lista de turma em sala, que indica que uma 
determinada turma está alocada em uma sala.
### Passos Iniciais
* Inicie o Eclipse. Vá em "File" → "New" → "New Java Project". Nome do projeto: "TAP-ColecoesGenericasII".
Na parte Module (parte de baixo da janela), desselecione "Create module-info.java file".
* Nas questões a seguir, será pedido para criar diversas classes. Para isso, vá em "File" → "New" → "Class".
Deixe o campo "package" em branco.
* O Eclipse compila automaticamente as classes sempre que você salva. Para executar e testar, basta ir em "Run" → "Run" (Ctrl+F11).
* A saída e entrada do programa será feita através da aba "Console" do Eclipse.
Nota da questão 0.5 / 0.5
### Q1-Classe Sala
Classe	Sala
Atributo	bloco: int
Atributo	sala: int
Atributo	capacidade: int
Atributo	acessivel: boolean
Método construtorEste C indica um método construtor	Sala()
Método construtorEste C indica um método construtor	Sala(int bloco, int sala, int capacidade, boolean acessivel)
Método	getDescricao(): String

![sala](https://user-images.githubusercontent.com/33138839/231961628-a29baa16-0437-4461-a693-b4b32b8af3a8.png)

Crie uma classe para representar uma Sala de aula. Os atributos de um objeto da classe Sala poderão ser setados diretamente (e.g., sala1.bloco=6) 
ou pelo método construtor. Use a técnica de encadeamento de 
construtores para criar os construtores da classe, semelhante ao feito em sala e mostrado nos slides. No diagrama ao lado, o atributo capacidade 
indica a capacidade máxima (quantidade máxima de alunos) que uma sala comporta. Já o atributo booleano acessivel indica se uma sala é de fácil 
acesso (para um cadeirante) ou não.
Implemente o método:
* getDescricao: retorna uma String contendo a descrição da sala de acordo com o exemplo abaixo:
```
Bloco 6, Sala 101 (50 lugares, acessível)
```
Para testar a classe, crie uma nova classe chamada EnsalamentoMain. Nesta classe, crie o método main, que será o ponto de partida do seu programa. No método main, crie um ou mais objetos da classe Sala e, em seguida, imprima o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe Sala. Não precisa submeter a classe EnsalamentoMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Sala.java" Solução correta!
Nota da questão 0.0 / 1.0
```
public class Sala {
    public int bloco;
    public int sala;
    public int capacidade;
    public boolean acessivel;

    public Sala() {
    }
    public Sala(int bloco, int sala, int capacidade, boolean acessivel) {
        this.bloco = bloco;
        this.sala = sala;
        this.capacidade = capacidade;
        this.acessivel = acessivel;
    }    
    public String acesso(boolean acessivel){
        String ac;
        if(acessivel){
            ac ="acessível";
        }else{
            ac ="não acessível";
        }
        return ac;
    }
    public String getDescricao(){
        
        return "Bloco "+bloco+", Sala "+sala+" ("+capacidade+" lugares, "+acesso(acessivel)  +")";
        
    }
//    public static void main(String[] args){
//        Sala s = new Sala(4, 202, 45, true);
//        
//        System.out.println(s.getDescricao());
//    }
}
```
### Q2 Classe Turma

![turma](https://user-images.githubusercontent.com/33138839/231961625-94b44acd-e6d4-4f10-8749-5a846dfc59cf.png)
    
De forma semelhante às questões anteriores, crie uma classe para representar uma Turma. Nesta classe, o atributo numAlunos indica a quantidade de 
alunos matriculados na disciplina. O atributo acessivel indica se algum aluno na turma requer uma sala de fácil acesso. Já o atributo horarios, 
que é uma lista 
de inteiros, indica os horários desta turma de acordo com a tabela abaixo:
<table border=1>
    <tr>
        <td>Hs/Dia</td>
        <td>Seg</td>
        <td>Ter</td>
        <td>Qua</td>
        <td>Qui</td>
        <td>Sex</td>
    </tr>
     <tr>
        <td>8	</td>
        <td>1	</td>
        <td>8	</td>
        <td>15	</td>
        <td>22	</td>
        <td>29</td>
    </tr>
     <tr>
        <td>10	</td>
        <td>2	</td>
        <td>9	</td>
        <td>16	</td>
        <td>23	</td>
        <td>30</td>
    </tr>
     <tr>
        <td>12	</td>
        <td>3	</td>
        <td>10	</td>
        <td>17	</td>
        <td>24	</td>
        <td>31</td>
    </tr>
     <tr>
        <td>14	</td>
        <td>4	</td>
        <td>11	</td>
        <td>18	</td>
        <td>25	</td>
        <td>32</td>
    </tr>
     <tr>
        <td>16	</td>
        <td>5	</td>
        <td>12	</td>
        <td>19	</td>
        <td>26	</td>
        <td>33</td>
    </tr>
     <tr>
        <td>18	</td>
        <td>6	</td>
        <td>13	</td>
        <td>20	</td>
        <td>27	</td>
        <td>34</td>
    </tr>
     <tr>
        <td>20	</td>
        <td>7	</td>
        <td>14	</td>
        <td>21	</td>
        <td>28	</td>
        <td>35</td>
    </tr>
</table>

ou seja, se a lista de horários de uma turma contém os números 1, 15 e 29, isso indica que esta turma tem aulas nas segundas, quartas e sextas 
das 8 às 10hs.
Ainda a respeito do atributo horarios, note que como as coleções genéricas em Java só aceitam classes (e não tipos primitivos), estamos usando 
a classe Integer ao invés do tipo primitivo int. Entretanto, as conversões entre a classe e o tipo primitivo são feitos de forma automática 
devido ao autoboxing/auto-unboxing da linguagem Java (ver slides).
Implemente os métodos:
* addHorario: adiciona um horário à lista de horários da turma.
* getHorariosString: retorna uma String contendo o horário da turma, de acordo com o exemplo abaixo:
```
segunda 8hs, quarta 8hs, sexta 8hs
```
* getDescricao: retorna uma String contendo a descrição completa da turma de acordo com o exemplo abaixo:
```
Turma: Algoritmos e Estrutura de Dados I
Professor: Edleno Silva
Número de Alunos: 60
Horário: segunda 8hs, quarta 8hs, sexta 8hs
Acessível: sim
```
Para testar a classe, modifique a classe EnsalamentoMain, criada na questão anterior, para criar um ou mais objetos da classe Turma e, em seguida, imprima o resultado da execução do método getDescricao dos objetos criados.
Para essa questão, submeta apenas a classe Turma. Não precisa submeter a classe EnsalamentoMain.
```
import java.util.ArrayList;

public class Turma {

    public String nome;
    public String professor;
    public int numAlunos;
    public boolean acessivel;
    public ArrayList<Integer> horarios = new ArrayList<>();
    
    public Turma() {
    }

    public Turma(String nome, String professor, int numAlunos, boolean acessivel) {
        this.nome = nome;
        this.professor = professor;
        this.numAlunos = numAlunos;
        this.acessivel = acessivel;
    }

    public void addHorario(int horario) {
        this.horarios.add(horario);
    }

    public String getHorariosString() {

        StringBuffer horaS = new StringBuffer();

        for (int i = 0; i < horarios.size(); i++) {

            Integer valorOut = horarios.get(i);
            horaS.append(CalendarioHorarioUtil.getInstance().horaTurma(valorOut)).toString();
            if (i != (horarios.size() - 1))
                horaS.append(", ");
        }
        return horaS.toString();
    }

    public String getDescricao() {

        StringBuffer out = new StringBuffer();

        out.append("Turma: " + this.nome + "\n");
        out.append("Professor: " + this.professor + "\n");
        out.append("Número de Alunos: " + this.numAlunos + "\n");
        out.append("Horário: " + this.getHorariosString() + "\n");
        out.append("Acessível: " + (this.acessivel == true ? "sim" : "não"));
        return out.toString();
    }
}

class CalendarioHorarioUtil {

    private static CalendarioHorarioUtil instance = null;

    private CalendarioHorarioUtil() {
    }
    public static synchronized CalendarioHorarioUtil getInstance() {
        if (instance == null)
            instance = new CalendarioHorarioUtil();
        return instance;
    }

    public static String horaTurma(Integer hh) {

        final String[] diaSemanaArray = { "segunda", "terça", "quarta", "quinta", "sexta" };
        final int[] hhDias = { 8, 10, 12, 14, 16, 18, 20 };

        int AuxhhDias = hh % 7 == 0 ? 6 : (hh % 7) - 1;
        int auxSemanaArray = 5 - ((35 - hh) / 7) - 1;
        return diaSemanaArray[auxSemanaArray] + " " + hhDias[AuxhhDias] + "hs";
    }
}
```
Nota da questão 0.0 / 0.2
### Q3 Classe TurmaEmSala
    
![turmaEmSala](https://user-images.githubusercontent.com/33138839/231961622-518650cd-0285-4214-b959-eed8f917b83e.png)
    
De forma semelhante às questões anteriores, crie uma classe para representar uma TurmaEmSala, que indica que uma turma está alocada em uma 
determinada sala.

Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "TurmaEmSala.java"
```
public class TurmaEmSala {

    public Turma turma;
    public Sala sala;

    public TurmaEmSala() {
        super();
    }

    public TurmaEmSala(Turma turma, Sala sala) {
        this.turma = turma;
        this.sala = sala;
    }

}
```
Nota da questão 0.0 / 8.0
### Q4 Classe Ensalamento
   
![ensalamento](https://user-images.githubusercontent.com/33138839/231961613-6ff1ab56-e4e3-47f3-b3ed-954dc5cb8a7b.png)

De forma semelhante às questões anteriores, crie uma classe para representar um Ensalamento. Esta classe será a principal parte do sistema, 
pois terá como atributos uma lista de salas e uma lista de turmas e, adicionalmente, terá métodos para gerar o ensalamento (alocar salas às turmas) 
e métodos para gerar relatórios.
O "resultado" do ensalamento será o atributo ensalamento, que terá uma lista de objetos da classe TurmaEmSala, em que cada objeto da lista "liga" 
uma turma a uma determinada sala. Este atributo terá todas as informações necessárias para responder perguntas e executar ações como:
* Qual a sala de uma determinada turma? -- método Sala getSala(Turma turma)
* Uma determinada sala está disponível em um determinado horário? -- método salaDisponivel(Sala sala, int horario)
* Uma determinada sala está disponível em todos os horários de uma lista? -- método boolean salaDisponivel(Sala sala, ArrayList<Integer> horarios)
* Aloque, caso seja possível, uma determinada turma em uma determinada sala. -- método alocar(Turma turma, Sala sala)
* Aloque todas as turmas da lista de turmas. -- método alocarTodas()
* Quantas turmas foram alocadas em uma sala com sucesso? -- método getTotalTurmasAlocadas()
* Qual o total de espaços livres nas salas? -- método getTotalEspacoLivre()
Segue um detalhamento, e dicas de implementação, para os métodos da classe:
* addSala(Sala sala): adiciona um objeto da classe Sala na lista de salas;
* addTurma(Turma turma): adiciona uma Turma na lista de turmas;
* getSala(Turma turma): retorna a sala alocada a uma determinada turma. Se nenhuma sala for encontrada, retorna null.
Para implementar este método, será necessário percorrer a lista do atributo ensalamento procurando pelo objeto cujo atributo turma seja igual ao 
parâmetro turma do método. Como uma turma só será alocada a uma única sala, após encontrar o primeiro elemento cuja turma seja a procurada, 
pode-se 
retornar a turma encontrada (sem precisar continuar percorrendo a lista de ensalamento).
* salaDisponivel(Sala sala, int horario): retorna true se a sala está disponível em um determinado horário. false caso contrário.
Para implementar este método, será necessário percorrer a lista do atributo ensalamento procurando por todos os objetos cujo atributo sala sejam 
iguais ao parâmetro sala do método. Para cada objeto encontrado, deve-se verificar o atributo horarios do atributo turma. Se um dos elementos 
elementos do atributo horarios for igual ao parâmetro horario, isso significa que a sala encontra-se ocupada naquele horário (retorna false). Se 
o horário de nenhuma 
turma bater com o horário procurado, isso significa que a sala está disponível (não possui nenhuma outra turma naquele dia/horário, returna true).
* salaDisponivel(Sala sala, ArrayList<Integer> horarios): retorna true se a sala está disponível em todos os horários do parâmetro horarios (lista 
de inteiros). false caso contrário.
Para implementar este método, execute o método anterior para cada elemento do parâmetro horarios.
* alocar(Turma turma, Sala sala): tenta alocar uma turma em uma determinada sala. Caso consiga, um objeto da classe TurmaEmSala com a turma e a 
sala deve ser adicionada na lista ensalamento e deve-se retornar true. Caso não seja possível alocar a turma na sala, retorna-se false. 
Para uma turma poder ser alocada em uma sala, os seguintes requisitos precisam ser atendidos:
Uma turma acessivel só pode ser alocada em uma sala também acessivel.
A quantidade de alunos na turma deve ser igual ou menor à capacidade da sala.
A sala precisa estar disponível em todos os horários da turma.
* alocarTodas(): aloca uma sala para todas as turmas do atributo turmas, caso seja possível.
Uma implementação simples (até demais) para este método é executar o método anterior para cada elemento da lista turmas e, para cada turma, ir 
tentando alocar em cada sala até que uma esteja disponível. Entretanto, esta solução poderá gerar um ensalamento menos eficiente (ver método 
* getTotalEspacoLivre) e, em alguns casos, deixar algumas turmas sem sala (ver método getTotalTurmasAlocadas) enquanto que uma solução 
mais elaborada poderia ser capaz de gerar um ensalamento mais eficiente e alocando uma sala para todas as turmas, assunto da questão "ponto extra".
* getTotalTurmasAlocadas(): retorna a quantidade de turmas que tiveram uma sala alocada com sucesso. O ideal é que este número seja igual ao total de turmas. Entretanto, caso não haja salas disponíveis para todas as turmas ou caso o seu algoritmo não seja eficaz, este número será 
menor que a quantidade de turmas, o que significa que algumas turma não terão salas de aula.
Para implementar este método, percorra o atributo ensalamento e conte a quantidade de objetos cujo atributo sala seja diferente de null.
getTotalEspacoLivre(): retorna um número que indica a eficiência do seu algoritmo de ensalamento. Um algoritmo "ineficiente" seria um algoritmo que alocasse uma turma pequena em uma sala muito grande (evitando que esta sala seja usada por turmas maiores, e, possivelmente, fazendo 
com que as turmas grandes fiquem sem sala).
Para gerar este número, inicie um acumulador em zero e, para cada turma alocada, incremente o acumulador com a subtração do tamanho da turma pela capacidade da sala (e.g., total += salaAtual.capacidade - turmaAtual.numAlunos). Quanto menor este número, mais 
eficiente é o ensalamento (pois as turmas foram alocadas em salas de tamanho compatível).
* relatorioResumoEnsalamento(): retorna uma String contendo um resumo do ensalamento, conforme o exemplo a seguir:
```
    Total de Salas: 4
Total de Turmas: 4
Turmas Alocadas: 3
Espaços Livres: 65
```
* relatorioTurmasPorSala(): retorna uma String contendo um relatório das salas com suas turmas alocadas, conforme o exemplo a seguir:
```
Total de Salas: 4
Total de Turmas: 4
Turmas Alocadas: 3
Espaços Livres: 65

--- Bloco 6, Sala 101 (50 lugares, acessível) ---

Turma: Técnicas de Programação
Professor: Horácio Fernandes
Número de Alunos: 50
Horário: terça 14hs, quinta 14hs, sexta 14hs
Acessível: não

Turma: Laboratório de Programação C
Professor: Edson Nascimento
Número de Alunos: 25
Horário: segunda 8hs, quarta 8hs, sexta 8hs
Acessível: sim

--- Bloco 6, Sala 102 (100 lugares, acessível) ---

Turma: Algoritmos e Estrutura de Dados I
Professor: Edleno Silva
Número de Alunos: 60
Horário: segunda 8hs, quarta 8hs, sexta 8hs
Acessível: não

--- Bloco 6, Sala 203 (50 lugares, não acessível) ---

--- Bloco 6, Sala 204 (100 lugares, não acessível) ---
```
* relatorioSalasPorTurma(): retorna uma String contendo um relatório das salas com suas turmas alocadas, conforme o exemplo a seguir (note que quando não há sala alocada, tem-se "SEM SALA"):
```
Total de Salas: 4
Total de Turmas: 4
Turmas Alocadas: 3
Espaços Livres: 65

Turma: Algoritmos e Estrutura de Dados I
Professor: Edleno Silva
Número de Alunos: 60
Horário: segunda 8hs, quarta 8hs, sexta 8hs
Acessível: não
Sala: Bloco 6, Sala 102 (100 lugares, acessível)

Turma: Técnicas de Programação
Professor: Horácio Fernandes
Número de Alunos: 50
Horário: terça 14hs, quinta 14hs, sexta 14hs
Acessível: não
Sala: Bloco 6, Sala 101 (50 lugares, acessível)

Turma: Laboratório de Programação C
Professor: Edson Nascimento
Número de Alunos: 25
Horário: segunda 8hs, quarta 8hs, sexta 8hs
Acessível: sim
Sala: Bloco 6, Sala 101 (50 lugares, acessível)

Turma: Redes de Computadores
Professor: Edjair Souza
Número de Alunos: 70
Horário: segunda 10hs, quarta 10hs
Acessível: sim
Sala: SEM SALA
```
Para testar a classe, modifique a classe EnsalamentoMain, criada na questão anterior, para criar um objeto da classe Ensalamento e, em seguida, adicione salas e turmas no ensalamento e, por fim, execute os métodos para alocar as salas. Imprima o resultado da execução dos métodos implementados.
Para essa questão, submeta apenas a classe Ensalamento. Não precisa submeter a classe EnsalamentoMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Ensalamento.java"
```
 a
```
Nota da questão 0.0 / 0.3

###  Q5 Classe EnsalamentoMain
Por fim, submeta a classe EnsalamentoMain, usada para testar as questões anteriores.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "EnsalamentoMain.java"
```
 a
```
###  Pontos Extras
Três (3.0) pontos extras serão dados aos dois alunos com maiores quantidades de "Turmas Alocadas" nos experimentos realizados pelo sistema. Quando dois ou mais trabalhos apresentarem a mesma quantidade de turmas alocadas, a quantidade de "Espaços Livres" será usada no desempate. Por fim, a data de submissão será usada como última forma de desempate. Os pontos extras só serão divulgados após o prazo de entrega do trabalho.
OBS: Os valores de "Turmas Alocadas" e "Espaços Livres" do seu trabalho serão mostrados após você submeter uma solução correta para a Questão 4 (Classe Ensalamento). Você pode re-submeter uma nova solução para a questão quantas vezes você quiser. Assim, você pode ir acompanhando se a sua nova solução é melhor ou pior do que a anterior.
