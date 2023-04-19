# Laboratório 9: Android - Introdução, Android Studio
### Introdução

O Android é o sistema operacional e plataforma de desenvolvimento para dispositivos móveis com maior taxa de crescimento.
Sendo um software de código-fonte aberto (FOSS, Free Open Source Software), o Android tira proveito de vários outros projetos também abertos começando com o próprio Linux, que é kernel que roda abaixo da interface gráfica. Outros projetos livres incluem várias bibliotecas usadas no Linux como, por exemplo, o SQLite, LibC, WebKit, OpenSSL, OpenGL, zLib, FreeType, dentre vários outros.
Aplicativos Android podem ser desenvolvidos nas linguagens em Java, Kotlin, ou em C++. Em geral, a escolha fica mais entre Java ou Kotlin, uma vez que C++ é usado mais para aproveitar códigos ou bibliotecas já existentes previamente. Entretanto, no final das contas, tudo acaba sendo executado pela máquina virtual Java, uma vez que códigos Kotlin são compilados para bytecode.
A linguagem Java é mais recomendada para quem está aprendendo a programar, uma vez que, além de ser usado pelo Android, ela é usada em milhares de outros projetos, possui uma comunidade imensa de programadores e possui também maior documentação e oportunidades.
Por outro lado, Kotlin é a linguagem oficial do Android desde 2017. Possui uma sintaxe mais limpa que o Java e é fácil de aprender, principalmente se você já conhece Java. Entretanto, ela é usada basicamente apenas pelo Android.
Neste e nos próximos laboratórios iremos implementar, na prática, os slides de Android. Basicamente, você irá implementar todo o app PlainText, utilizado como exemplo nos slides. Futuramente, em outros laboratórios, será pedido para você fazer modificações no app.
### 1. Instalação do Android Studio
O Android Studio é o modo recomendado de desenvolvimento Android desde dez/2014. Ele substituiu o Eclipse, que era usado até então para a criação de apps. O Android Studio contém:
* InteliJ IDE, editor muito usado no mercado para programação Java
* Android SDK Tools
* Android Platform-tools
* Imagem do Sistema Android para o Emulator
Para instalar o Android Studio, o primeiro passo é fazer download dele no site https://developer.android.com/studio/. O arquivo possui aproximadamente 1GB de tamanho.
Em seguida, se você estiver usando o Linux, execute os comandos abaixo substituindo o nome do arquivo baixado.
```
tar -xvf android-studio-xxxx.x.x.xx-linux.tar.gz
cd android-studio/bin/
./studio.sh
```
Na primeira execução, serão baixados e instalados componentes extras necessários para a execução do Android Studio. No total, serão baixados aproximadamente 1.6GB. Basta seguir os passos do instalador.
Após a instalação dos componentes, irá aparecer a janela incial do Android Studio com o título "Welcome to Android Studio". Essa janela permite escolher um projeto/app para trabalhar. Se seu Android Studio já tinha um projeto criado, ele irá abrir o projeto diretamente sem mostrar essa janela de "welcome". Neste caso, peça para fechar o projeto atual (File→Close).
Clique no botão abaixo para fazer um screenshot da sua tela mostrando a janela de "welcome". Na permissão do navegador, selecione a tela inteira ou apenas a janela do Android Studio. Em qualquer caso, certifique-se que a janela esteja aparecendo em sua tela dentro de 3 segundos.

![WelcomeAndroid](https://user-images.githubusercontent.com/33138839/232947394-2dbeaeb4-909f-428a-803f-8fe115789e4b.png)

### 2. Criando um Novo Projeto
Na janela de "Welcome", clique no botão para criar um novo projeto. Siga os passos a partir do slide "Tela Inicial, Novo App".
Clique no botão abaixo para fazer um screenshot do seu Android Studio mostrando o "Editor de Códigos" (arquivo MainActivity.java).

![MainActivity](https://user-images.githubusercontent.com/33138839/232947390-727ee63b-aefd-405c-8923-e837f910af70.png)

Clique no botão abaixo para fazer um screenshot do seu Android Studio mostrando o "Editor de Design" (Interface Gráfica, arquivo activity_main.xml).

![DesignXML](https://user-images.githubusercontent.com/33138839/232947387-cba2330a-d1f6-43f0-99e2-bce00588be8d.png)
Clique no botão abaixo para fazer um screenshot do seu Android Studio mostrando o "Editor de XML" (arquivo activity_main.xml).

![codeXML](https://user-images.githubusercontent.com/33138839/232947384-656e6de5-d05f-415b-b1bf-7e23d056d157.png)


### 3. AVD - Android Virtual Device
O Android Virtual Device (AVD) é um emulador que permite executar os aplicativos Android em sua máquina. Ele emula um celular e executa uma versão completa do Android, o mesmo do seu celular, mas sem os aplicativos da operadora e do fabricante. O emulador permite testar o aplicativo em celulares de configurações e Android diferentes.
Siga os passos dos slides "AVD - Android Virtual Device" para criar e executar o AVD.
Clique no botão abaixo para fazer um screenshot do seu AVD executando.
![AVD](https://user-images.githubusercontent.com/33138839/232947376-5538f374-e92d-47cc-b427-cd504c055fa4.png)

