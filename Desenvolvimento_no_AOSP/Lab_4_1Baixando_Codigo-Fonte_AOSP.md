# Laboratório 4.1: Baixando o Código-Fonte do AOSP
### Introdução
O Android é o sistema operacional para dispositivos embarcados móveis mais usado no mundo, sendo, atualmente, instalado em aproximadamente 80% dos smartphones. Um dos principais fatores que resultaram em sua popularidade é o fato de ser um sistema operacional de código-fonte aberto. Isso permite que o Android possa ser adaptado e instalado em diversos dispositivos de fabricantes diferentes e, até mesmo, com propósitos diferentes que vão muito além dos smartphones como, por exemplo, eletrodomésticos, veículos e relógios. Toda essa diversidade resultou em contribuições ao projeto vindas dos mais diversos lugares e convergindo em um dos projetos de software mais inovadores do mundo.
O ponto de partida para a personalização e criação de um novo sistema baseado em Android é o Android Open Source Project (AOSP). O AOSP provê as informações necessárias e todo o repositório de código-fonte que permite a criação de novos sistemas Android personalizados para novos dispositivos de hardware com acessórios, serviços e interfaces diferenciados. Além disso, o AOSP é o principal responsável por garantir a compatibilidade entre dispositivos de fabricantes diferentes, uma vez que todos se baseiam no mesmo código-fonte. Por fim, o AOSP não só distribui o código-fonte, mas aceita, também, contribuições de implementações que poderão ser, eventualmente, incorporadas à solução final. Tal característica faz com que o Android seja um dos maiores projetos cooperativos da atualidade.
Você está prestes a embarcar em uma jornada que o fará parte desse ecossistema de profissionais que mantém e aprimoram o Android.
### 1. Instalando o Git e o Repo
O código-fonte do Android é composto por vários repositórios Git diferentes. Para gerenciar esses vários repositórios, usa-se a ferramenta Repo. Portanto, o primeiro passo é instalar o Git e o Repo na sua máquina. Para instalar o git, execute:
```
sudo apt update
sudo apt install git
sudo apt install wget python3 python-is-python3
```
O utilitário APT, presente em sistemas Linux baseados no Ubuntu, é usado para baixar e instalar o git. Aproveitamos para instalar também outros programas que usaremos nesse e nos próximos laboratórios. Para verificar se o git foi instalado com sucesso ou se ele já existe no seu sistema, execute:
```
git --version
git version 2.34.1
```
Dica: em muitos códigos e campos desde laboratório será necessário copiar e colar do terminal. Para copiar algo do terminal, selecione o texto e pressione CTRL+Shift+C. Para colar algo no terminal, pressione CTRL+Shift+V.
Configure o Git para usar seu nome e e-mail:
```
git config --global user.name [Seu Nome]
git config --global user.email [Seu E-Mail]
```
Para instalar o repo, execute:
```
mkdir bin; cd bin                                             # Cria e entre no diretório de binários (executáveis)
wget https://storage.googleapis.com/git-repo-downloads/repo   # Faz download do repo
chmod 755 repo                                                # Seta permissão para execução do repo
export PATH=$PATH:~/bin/                                      # Adiciona o diretório ~/bin/ no PATH
echo "export PATH=$PATH:~/bin/" >> ~/.bashrc                  # Executado quando um terminal novo é aberto
```
Em seguida, feche o seu terminal e abra um novo. Para verificar se o repo foi instalado com sucesso ou se ele já existe no seu sistema, execute:
```
repo version
```
```
<repo not installed>
repo launcher version 2.32
       (from /home/dev/bin/repo)
git 2.34.1
Python 3.10.6 (main, Mar 10 2023, 10:55:28) [GCC 11.3.0]
OS Linux 5.19.0-42-generic (#43~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Fri Apr 21 16:51:08 UTC 2)
CPU x86_64 (x86_64)
Bug reports: https://bugs.chromium.org/p/gerrit/issues/entry?template=Repo+tool+issue
```
### 2. Inicializando o Repo do AOSP
Crie um diretório para armazenar o código-fonte do AOSP:
```
cd ~         # Vai para o seu diretório Home
mkdir aosp   # Cria um diretório novo
cd aosp      # Entra no diretório criado
```
Inicialize o repositório Repo dentro do diretório:
```
repo init --depth=1 -u https://android.googlesource.com/platform/manifest -b android-13.0.0_r24
```
A opção --depth=1 configura o Git para baixar apenas a versão mais atual do código-fonte, sem baixar todo o histórico dos repositórios. Isso faz com que o download caia de aproximadamente 80GB para "apenas" 20GB. Entretanto, após a descompactação dos códigos, o diretório ocupará aproximadamente 90GB. A opção -u indica a URL de downloads. Por fim, a opção -b indica o branch (versão) do Android a ser baixado. Para ver uma lista das branches disponíveis, clique aqui.
Copie a saída do comando anterior e cole no campo abaixo.

Downloading Repo source from https://gerrit.googlesource.com/git-repo

Your identity is: adriano Oliveira <oliveira.ifam@gmail.com>
If you want to change this, please re-run 'repo init' with --config-name

repo has been initialized in /home/dev/aosp
O comando init do repo (executado no comando anterior) não baixa o código, apenas inicializa o diretório atual. Para isso, ele cria um diretório oculto chamado .repo. Para ver o conteúdo desse diretório, digite os comandos abaixo:
```
ls -al
ls -al .repo
```
Note o arquivo manifest.xml. Ele é o primeiro arquivo a ser lido pelo repo. Abra esse arquivo e observe seu conteúdo, o que ele faz?
```
code .repo/manifest.xml
```
Como você pode ver, ele basicamente chama outro arquivo de manifest. Este está localizado dentro do diretório .repo/manifests. Abra esse arquivo para ver seu conteúdo:
```
code .repo/manifests/default.xml
```
Neste arquivo, as tags remote indicam endereços de servidores Git (apenas um atualmente). A tag default indica algumas configurações padrões, incluindo o servidor git padrão (atributo remote). Em seguida, diversas tags project listam os diversos projetos Git que compõem o repo do Android. Use o Find do editor ou o comando abaixo para descobrir quantos projetos diferentes existem no Android hoje:
```
cat .repo/manifests/default.xml | grep '<project' | wc -l
```
```
1142
```
Yep! É uma quantidade grande de projetos. Cada um é um git diferente e mantido por pessoas diferentes. Voltando para o arquivo manifest, cada tag project possui um atributo path que indica o diretório local aonde o código será armazenado, e possui também um atributo name que indica o nome do repositório no servidor remoto. Sabendo disso, responda a pergunta abaixo:
O repositório remoto de nome platform/packages/apps/Settings contém o código-fonte do aplicativo Settings (Configurações) do Android. Em qual diretório local ficará armazenado o código desse app?
```
<project path="packages/apps/Settings" name="platform/packages/apps/Settings" groups="pdk-fs" />
```
### 3. Fazendo Download do AOSP
O processo de deixar o seu diretório local com o mesmo código do servidor remoto é chamado de "sincronização". Na primeira execução, a sincronização basicamente baixa todo o código-fonte do AOSP. Para sincronizar seu repositório local, execute:
```
repo sync -c -j$(nproc)
```
A opção -c (current) irá sincronizar a branch atual. A opção -j indica quantos processadores/núcleos utilizar na sincronização. O ideal é usar o número máximo disponível no seu sistema. Você pode ver informações do seu processador abrindo o arquivo /proc/cpuinfo. Qualquer um dos comandos abaixo mostram a quantidade de processadores/núcleos do seu sistema:
```
code /proc/cpuinfo
cat /proc/cpuinfo | grep processor | wc -l
nproc --all
```
Execute o comando repo sync mostrado anteriormente usando todos os processadores/núcleos do seu computador. O AOSP começará a ser baixado para a sua máquina. Como o download irá demorar, devido ao tamanho do AOSP, pressione as teclas CTRL+C para cancelar o download. Nós iremos utilizar um código já baixado em sua máquina. Para isso, execute os comandos abaixo.
```
cd ~
rm -rf aosp              # Apaga um diretório e todo o seu conteúdo
mv aosp-original aosp    # Renomeia o aosp já baixado ("aosp-original") para "aosp"
```
### 4. Explorando o Código do AOSP
Antes de compilar o Android, iremos explorar um pouco o código-fonte do AOSP. Liste os arquivos no diretório principal do repositório:
```
cd ~/aosp   # Diretório com o código baixado do AOSP
ls
```
O AOSP possui alguns diretórios principais:
Diretório	Descrição	Camada do Android
art	ART (Android Runtime), o ambiente de execução (máquina virtual Java) usado atualmente pelo Android.	Java Runtime
bionic	O Bionic é a biblioteca C padrão do Android. Faz o papel do glibc (GNU C Library).	Nativa
dalvik	O Dalvik é o antigo ambiente de execução (máquina virtual Java) do Android.	Java Runtime
device	Armazena os produtos, personalizações do Android. Será bastante usado nos próximos laboratórios.	Hardware e Outras
external	Projetos externos ao AOSP como o libssl (criptografia), webkit (biblioteca HTML e JavaScript), etc.	Nativa
frameworks	Componentes da camada Framework, que provê serviços para os aplicativos Android (apps).	Framework
hardware	Camada HAL (Hardware Abstraction Layer). Provê acesso a componentes de hardware (audio, camera, etc).	HAL
kernel	Kernel do Linux e módulos já compilados. Contém também arquivos de configuração.	Kernel
libcore	Biblioteca Java padrão (OpenJDK). Provê classes como ArrayList, String, Object, etc.	Java Runtime
packages	Aplicações Android. Contém o código de apps como Settings, Calendar, Dialer, Launcher3, Gallery, etc.	Aplicações
system	Bibliotecas e processos nativos do Android (liblog, vold, lmkd, e outros).	Nativa
O código-fonte do AOSP contém coisas bem interessantes, em especial para quem usa e/ou desenvolve apps no sistema. A seguir, iremos explorar alguns componentes que você pode ou não reconhecer, dependendo de sua experiência na plataforma.
O SQLite é o banco de dados usado pelas aplicações Android. Ele é incluído no AOSP como uma biblioteca nativa externa. Procure o diretório no AOSP que contém o código-fonte do SQLite e digite-o no campo abaixo.
```
external/sqlite/android/
```
Algumas vezes, queremos procurar um arquivo pelo seu nome (ou parte do nome). Para isso, pode-se usar o comando find para listar todos os arquivos e o comando grep para filtrar o que queremos. Por exemplo, para pesquisar todos os arquivos cujo nome contém "Integer.java", pode-se executar:
```
find . | grep Integer.java
```
Executando o comando anterior, você deve ter percebido que várias linhas foram retornadas. Você precisa analisar e deduzir informações da saída para encontrar o que você procura. Dentre as linhas retornadas, qual você acha que corresponde ao código-fonte da classe Integer da linguagem Java?
```
./libcore/ojluni/src/main/java/java/lang/Integer.java
```
O LocationManager é um Serviço de Sistema da camada Framework que disponibiliza para os aplicativos Android informações de posicionamento do dispositivo. Encontre o diretório do seu código-fonte e digite-o abaixo. Dica: ignore qualquer diretório começando por out/soong, ele contém arquivos de compilação e não faz parte do código-fonte do AOSP (veremos isso mais adiante).
```
frameworks/base/location/java/android/location/LocationManager.java
```
### 5. Usando o Android Code Search
O comando find é útil para encontrar arquivos rapidamente. Entretanto, para filtros mais complexos, ele deixa de ser prático. Além disso, ele não pesquisa pelo conteúdo dos arquivos, só pelo nome. Desta forma, para pesquisas mais completas no código-fonte do AOSP, deve-se usar um serviço mais completo como os dois sites abaixo:
- Android Code Search: https://cs.android.com/android/platform/superproject
- AOSP-XRef: http://aospxref.com/
Neste curso, focaremos no Android Code Search, por ser desenvolvido e mantido pelo Google. Abra o site e se familiarize com ele. Ele será sua fonte de informações durante todo o curso. Abra os diretórios do AOSP, observe os arquivos, e faça as buscas anteriores (e.g., LocationManager). Note como a busca é mais rápida, mostra os melhores resultados primeiro, e a interface é bem mais fácil de ser lida.
É importantíssimo que você se acostume a usar o Android Code Search como sua fonte de informações sobre o AOSP. Muitas das coisas que nós faremos durante este curso não possuem documentação na Internet. Pense no código-fonte do AOSP como sendo um grande "stack overflow" de códigos de exemplo. Neste ponto de vista, o Android Code Search seria a funcionalidade de busca e navegação no código.
Basicamente, tudo que você precisar fazer provavelmente já existe um código de exemplo no próprio AOSP. O único detalhe é que você precisa analisar o código para ver se é aquilo mesmo que você precisa, uma vez que não terá uma pessoa respondendo diretamente a sua dúvida. Devido a isso, recomendamos fortemente que você faça um bookmark do Android Code Search. Para facilitar ainda mais o acesso, faça um link do site no seu Desktop. Para isso, no Chrome, clique nos "três pontos" no canto superior direito do navegador, vá em "Mais Ferramentas" e depois em "Criar Atalho".
Uma mensagem muito comum para desenvolvedores de aplicativos Android é "Você agora é um desenvolvedor!". Essa mensagem aparece quando você clica várias vezes no "Número da versão" nas opções do dispositivo e é necessário para testar e executar aplicativos desenvolvidos no Android Studio usando o seu próprio smartphone. Procure essa mensagem no Android Code Search e indique o nome do arquivo dela abaixo. Dica: o Android Code Search possui um botão para "copiar o caminho do arquivo" se você colocar o mouse em cima do nome do arquivo.
```
packages/apps/Settings/res/values-pt/strings.xml
```
A partir da tela anterior no Android Code Search, encontre o arquivo e a mesma frase em Italiano (sem usar tradutores). Digite a frase em Italiano abaixo.
```
<string name="show_dev_on" msgid="2840850085134853754">"Ora sei uno sviluppatore."</string>
```
Ainda no arquivo de strings em Italiano, um pouco acima da mensagem anterior tem uma tag chamada show_dev_countdown e dentro dela tem uma tag com o atributo quantity="other". Qual as três primeiras palavras da frase nessa tag?
```
Ora ti mancano
```
Uma outra vantagem do Android Code Search é a possibilidade de "navegar" no código. Por exemplo, você pode clicar em funções que estão sendo executadas para ser enviado para a implementação desta função e analisar o seu código. Eventualmente, você pode "navegar" na sequência de chamada das funções só clicando no nome delas.
O SurfaceFlinger é um serviço do Android responsável por organizar a pintura da tela do dispositivo. Procure no Android Code Search o arquivo SurfaceFlinger.cpp e veja o seu código. O método captureDisplay é responsável por criar e definir um buffer com todos os pixels da tela sendo mostrado atualmente (i.e., screenshot). Olhando a implementação desse método, qual o nome do método que eventualmente é executado e retornado por ele?
```
return fenceStatus(future.get());
```
