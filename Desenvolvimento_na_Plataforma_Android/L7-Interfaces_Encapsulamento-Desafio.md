# Laboratório 7: Interfaces, Encapsulamento (Desafio)
### Objetivo
* Implementação de classes e interfaces em Java usando
os conceitos de encapsulamento.
### Descrição
* Neste trabalho, você implementará as classes ao lado
necessárias para representar alguns objetos em um
Sistema de Informação Geográfica (GIS - Geographic
Information System). Nestes sistemas, alguns objetos são
passíveis de se localizarem (usando GPS, localização WiFi).
Tais objetos são instâncias de classes que implementam a
interface Localizavel.
* Passos Iniciais
Inicie o Eclipse. Vá em "File" → "New" →
"New Java Project". Nome do projeto:
"Lab-Encapsulamento".
Nas questões a seguir, será pedido para criar diversas
classes. Para isso, vá em "File" → "New" → "Class".
Na caixa que abre, indique o nome da classe e o nome do
pacote ("br.edu.ufam.icomp.lab_encapsulamento").
Para criar uma interface, siga os mesmos passos, mas na
opção "Interface" do menu.

![classeL7](https://user-images.githubusercontent.com/33138839/231965624-c5f9a65f-dc3e-4b32-824f-2dba3caeaaa6.png)

Nota da questão 0.0 / 2.0
### Q1 Classe Posicao
ClasseEste ícone indica uma classe pública (public)	Posicao
AtributoEste ícone indica um atributo privado (private)	latitude: double
AtributoEste ícone indica um atributo privado (private)	longitude: double
AtributoEste ícone indica um atributo privado (private)	altitude: double
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	Posicao(double latitude, double longitude, double altitude)
MétodoEste ícone indica um método público (public)	setLatitude(double latitude): void
MétodoEste ícone indica um método público (public)	getLatitude(): double
MétodoEste ícone indica um método público (public)	setLongitude(double longitude): void
MétodoEste ícone indica um método público (public)	getLongitude(): double
MétodoEste ícone indica um método público (public)	setAltitude(double altitude): void
MétodoEste ícone indica um método público (public)	getAltitude(): double
MétodoEste ícone indica um método público (public)	toString(): String


![posicao](https://user-images.githubusercontent.com/33138839/231965622-e81da6c0-e374-4374-bdaf-ea56d6b6e16e.png)
  
Crie uma classe para representar uma Posicao (composta de latitude, longitude e altitude). Os atributos da classe são todos privados (private) e não poderão ser acessados diretamente, apenas através dos métodos getters e setters.
Além dos métodos getters e setters, sobreponha o método:
toString: retorna uma String contendo a descrição da posição conforme o exemplo abaixo (na ordem latitude, longitude, altitude):
Posição: -3.089242, -59.964874, 88.374
Para testar a classe, crie uma nova classe chamada GISMain. Nesta classe, crie o método main, que será o ponto de partida do seu programa. No método main, crie um ou mais objetos da classe Posicao e, em seguida, imprima os objetos (eles serão convertidos automaticamente para String usando o método toString).
Para essa questão, submeta apenas a classe Posicao. Não precisa submeter a classe GISMain.

Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Posicao.java"
Nota da questão 0.0 / 2.0
```
a
```
### Q2 Interface Localizavel
ClasseEste ícone indica uma classe pública (public)	<<interface>>
Localizavel
MétodoEste A indica um método abstrado. Note que o nome do método está em itálico.	getPosicao(): Posicao
MétodoEste A indica um método abstrado. Note que o nome do método está em itálico.	getErroLocalizacao(): double
  
![localizavel](https://user-images.githubusercontent.com/33138839/231965619-3b7ee3c0-5546-4126-83e0-88cf9d5cd6e6.png)
    
Crie uma interface para representar um objeto Localizavel. As classes que implementarem esta interface terão que implementar os métodos descritos nela.
Por ser uma interface, não tem como instanciar um objeto dela. Para usarmos a interface, primeiro precisamos criar uma classe que a implemente (próxima questão).
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Localizavel.java"
```
  a
```
Nota da questão 0.0 / 2.0 
### Q3 Classe Celular
ClasseEste ícone indica uma classe pública (public)	Celular
AtributoEste ícone indica um atributo privado (private)	codPais: int
AtributoEste ícone indica um atributo privado (private)	codArea: int
AtributoEste ícone indica um atributo privado (private)	numero: int
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	Celular(int codPais, int codArea, int numero)
MétodoEste F indica um método final, que não pode ser sobreposto pelas subclasses	setCodPais(int codPais): void
MétodoEste ícone indica um método público (public)	getCodPais(): int
MétodoEste F indica um método final, que não pode ser sobreposto pelas subclasses	setCodArea(int codArea): void
MétodoEste ícone indica um método público (public)	getCodArea(): int
MétodoEste F indica um método final, que não pode ser sobreposto pelas subclasses	setNumero(int numero): void
MétodoEste ícone indica um método público (public)	getNumero(): int
MétodoEste ícone indica um método público (public)	getPosicao(): Posicao
MétodoEste ícone indica um método público (public)	getErroLocalizacao(): double

![celular](https://user-images.githubusercontent.com/33138839/231965617-6624df6a-c3fa-4ab1-8f14-5b54ae739ab1.png)
 
Crie uma classe para representar um Celular. Um celular é Localizavel (ou seja, ele implementa a interface Localizavel) e possui algumas regras para seus atributos que deverão ser escondidos (private) e verificados nos métodos setters. Caso algum valor passado para o setter não esteja correto, o valor do atributo deverá ser setado para -1:
codPais: deve estar entre os valores 1 e 1999 (inclusive).
codArea: deve estar entre os valores 10 e 99 (inclusive).
numero: deve estar entre os valores 10000000 e 999999999 (inclusive).
Note que os métodos setCodPais(), setCodArea() e setNumero() estão marcados como final, indicando que estes métodos não poderão ser sobrepostos por subclasses da classe Celular. Além dos métodos getters e setters, implemente os métodos declarados na interface Localizavel:
getPosicao: deverá retornar uma posição geográfica aleatória dentro da cidade de Manaus (isso irá simular um "GPS"), ou seja:
latitude: entre -3.160000 e -2.960000.
longitude: entre -60.120000 e -59.820000.
altitude: entre 15.0 e 100.0.
Em java, para gerar um número aleatório entre dois números, importe todas as classes do pacote java.util e use:
Random r = new Random();
double latitude = valorMinimo + (valorMaximo - valorMinimo) * r.nextDouble();
getErroLocalizacao: como estamos usando um celular, que possui GPS menos preciso, este método irá simplesmente retornar o valor 50.0.
Para testar a classe, modifique a classe GISMain, criada na primeira questão, para criar um ou mais objetos da classe Celular e, em seguida, imprima a posição do celular executando o método getPosicao.
Para essa questão, submeta apenas a classe Celular. Não precisa submeter a classe GISMain.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Celular.java"
```
  a
```
Nota da questão 0.0 / 1.5
### Q4 Classe Carro
ClasseEste ícone indica uma classe pública (public)	Carro
AtributoEste ícone indica um atributo protegido (protected)	placa: String
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	Carro(String placa)
MétodoEste ícone indica um método público (public)	setPlaca(String placa): void
MétodoEste ícone indica um método público (public)	getPlaca(): String
  
![carro](https://user-images.githubusercontent.com/33138839/231965616-b4056653-6dcc-4306-905d-0cb9bfc58f2f.png) 
  
Crie uma classe para representar um Carro. O seu único atributo, placa deve ser setado como protected e seu getter/setter deve ser implementado. Note que:
um carro simples não é Localizavel, uma vez que ele não possui GPS.
o atributo placa da classe é protected, ou seja, ele só poderá ser acessado pelas subclasses e pelas classes no mesmo pacote.

Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "Carro.java"
```
  a
```
Nota da questão 0.0 / 2.0
### Q5 Classe CarroLuxuoso
ClasseEste ícone indica uma classe pública (public)	CarroLuxuoso
Método construtorEste C indica um método construtorEste ícone indica um atributo público (public)	CarroLuxuoso(String placa)
MétodoEste ícone indica um método público (public)	getPosicao(): Posicao
MétodoEste ícone indica um método público (public)	getErroLocalizacao(): double
  
 ![carroLuxuoso](https://user-images.githubusercontent.com/33138839/231965610-7c405a31-eeb8-405e-9d27-eec4b9542b40.png)
 
Crie uma classe para representar um CarroLuxuoso, que herda a classe Carro e implementa a interface Localizavel. Como o CarroLuxuoso implementa a interface Localizavel, este deverá implementar os seus métodos, que serão iguais aos da classe Celular com exceção do método getErroLocalizacao que deverá retornar 15.0.
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "CarroLuxuoso.java"
```
  a
```
  
Nota da questão 0.0 / 0.5
### Q6 Classe GISMain
Por fim, para exercitar o conceito de polimorfismo (agora usando interfaces) modifique a classe GISMain. Crie um vetor de objetos de classes que implementam a interface Localizavel. Crie e insira no vetor um ou mais objetos das classes Celular e CarroLuxuoso. Em seguida, faça um for para iterar entre todos os elementos e mande imprimir a posição de cada um dos objetos. Como você sobrepôs o método toString na classe Posicao, você pode mandar imprimir diretamente o resultado do método getPosicao diretamente. Exemplo: System.out.println(vetorLocalizaveis[i].getPosicao());
Após resolver e testar a questão no Eclipse, submeta-o usando o botão abaixo:
Enviar "GISMain.java"
