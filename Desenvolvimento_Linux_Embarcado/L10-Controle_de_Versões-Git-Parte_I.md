# Laboratório 10: Controle de Versões, Git - Parte I
## Introdução
O Git é um sistema de controle de versão que permite rastrear as alterações feitas em seus arquivos ao longo do tempo. Geralmente, acontece de termos muitos desenvolvedores trabalhando numa mesma base de códigos, então um sistema de controle de versão como o Git é necessário para diminuir conflitos entre o código de cada desenvolvedor. Você também pode fazer uma cópia do arquivo, fazer alterações nessa cópia e mesclar essas alterações na cópia original. Você não está limitado a usar o Git apenas para arquivos de código-fonte – pode usá-lo para acompanhar arquivos de texto ou até imagens. Isso significa que o Git não é apenas para desenvolvedores.
Abaixo temos alguns pontos fortes para o uso do Git:
Organização: conforme o desenvolvimento de trechos de código, é possível salvar e, caso necessitem, é possível voltar para versões anteriores.
Trabalho em equipe: quando trabalhamos sozinhos, o procedimento é de uma forma, por outro lado quando trabalhamos em equipe, tudo muda, e o controle de versão nos ajuda neste aspecto. Não é preciso se preocupar com dois desenvolvedores alterarem um mesmo arquivo, ao mesmo tempo, por estarem desenvolvendo um mesmo projeto.
Segurança: todos os projetos serão desenvolvidos sem medo de perder código ou acabar errando alguma atualização, sem ter como voltar.
### 1. Instalação
Para usar o Git você precisa instalá-lo em seu computador. Para fazer isso, é necessário baixar a versão mais recente no site oficial. Você pode fazer o download para o seu sistema operacional a partir das opções fornecidas no site (https://git-scm.com/downloads).
Você também pode instalar o Git usando a linha de comando, mas como os comandos variam de acordo com cada sistema operacional, vamos nos concentrar na abordagem mais geral.
Para instalar no linux basta executar os seguintes comandos:
```
sudo apt update
sudo apt install git
```
Após instalar, verifique a versão instalada utilizando o comando:
```
git --version
```
git version 2.34.1
### Configuração
Fique tranquilo, você não precisará decorar os comandos abaixo, pois, só na primeira vez que estiverem utilizando o Git que é necessário executá-los. Este procedimento é necessário para o Git saber sua identificação. Quando executar qualquer comando, o Git fará o reconhecimendo por estas informações.
```
git config --global user.name "[Seu Nome]"
git config --global user.email "[Seu E-Mail]"
```
2. Criando um repositório localUm repositório é uma pasta onde ficarão armazenados todos os arquivos de um projeto. Quando iniciamos um repositório Git, todos os arquivos dessa pasta passam a fazer parte do controle de versão. O primeiro passo será criar uma pasta do nosso projeto no sistema e acessa-lá. Para isso, executaremos os seguintes comandos:
```
mkdir devtitans-git                # Para criar a pasta
cd devtitans-git                   # Para acessar a pasta
```
Agora que estamos dentro da pasta criada, basta rodarmos, um simples comando, para que esta pasta passe a ser um repositório. Vejam o comando abaixo:
```
git init
```
```
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint: 
hint:   git config --global init.defaultBranch <name>
hint: 
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint: 
hint:   git branch -m <name>
Initialized empty Git repository in /home/devtitans-1/devtitans-git/.git/
```
Isso dirá ao Git para se preparar para começar a observar seus arquivos para cada alteração que ocorrer. Esse comando criará uma pasta oculta chamada .git. Para verificar se a pasta realmente existe, execute o comando a seguir, que lista todos os arquivos e pastas, inclusive os ocultos:
```
ls -al
```
```
total 12
drwxrwxr-x  3 devtitans-1 devtitans-1 4096 mar 31 19:08 .
drwxr-x--- 37 devtitans-1 devtitans-1 4096 mar 31 19:08 ..
drwxrwxr-x  7 devtitans-1 devtitans-1 4096 mar 31 19:08 .git
```
Se você acessar este diretório, verá que existem diversos arquivos e pastas. Estes arquivos e pastas fazem parte da estrutura que o Git utilizará para controlar as versões dos projetos. Para verificar, execute os comandos abaixo:
```
cd .git
ls
branches  config  description  HEAD  hooks  info  objects  refs
```
Desta forma, se quiser destruir um sistema de versão de um projeto, basta apagar esta pasta completa e não terá mais controle de versão, agindo sobre o projeto. Agora iremos retornar a pasta principal do nosso repositório para adicionar um novo arquivo.
```
cd ..
touch dev1.txt
```
Neste momento, só criamos o arquivo, mas ele não tem conteúdo nenhum. Abra este arquivo com qualquer editor de texto e escreva o texto abaixo:
```
Olá mundo, eu sou DevTITAN!
```
### 3. Estágios de um Commit
### Primeiro Estágio - Working Directory
O primeiro estágio é quando os arquivos são criados na pasta, mas como o arquivo é novo, ele se encontra no estágio de Untracked Files, que é o caso do nosso dev1.txt. Isso acontece porque ele é um arquivo desconhecido pelo Git, ou seja, ele está na pasta, mas o Git ainda não está controlando a versão do mesmo. Untracked files são as alterações pendentes que nós precisamos adicionar na staging area. Para verificar este estágio basta digitar o comando abaixo, que listará todos os os arquivos novos e que sofreram modificações.
```
git status
```
```
On branch master
No commits yet
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        dev1.txt
nothing added to commit but untracked files present (use "git add" to track)
```
### Segundo Estágio - Staging Area
Para o nosso arquivo de exemplo passar para o segundo estágio, precisamos rodar um comando que faça ele ser reconhecido pelo git. Execute o comando abaixo:
```
git add dev1.txt
```
Depois que rodamos este comando, o dev1.txt passa para uma posição intermediária. Nesse caso, nosso arquivo está pronto para ser commitado. Quando falamos commitados, estamos querendo dizer que este arquivo fará parte, efetivamente, do repositório, após este procedimento. Para verificarem, execute, novamente, o comando git status.
```
git status
```
```
On branch master
No commits yet
Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   dev1.txt
```       
Para reiterar, o arquivo ainda não foi adicionado a um commit, mas está prestes a ser.
### Terceiro Estágio - Committed
É hora de criar seu primeiro commit! Então rodaremos o comando abaixo para que o nosso arquivo de exemplo faça parte deste último estágio.
```
git commit -m "Meu primeiro commit"
```
```
[master (root-commit) c054b84] Meu primeiro commit
 1 file changed, 1 insertion(+)
 create mode 100644 dev1.txt
 ```
Observe que estamos rodando o comando commit e passando um parâmetro -m que serve para adicionarmos uma mensagem de identificação. É esta mensagem que nos permite acompanhar todos os estágios do desenvolvimento de um projeto. Ela deve ser muito explicativa, para quem ler, saber o que realmente foi feito naquele commit.
Neste estágio, se executar o comando git status, verá que teremos uma mensagem dizendo que não existe mais nada para commitar. Só conseguiremos realizar o procedimento, novamente, caso um novo arquivo seja adicionado, removido ou modificado.
```
git status
On branch master
nothing to commit, working tree clean
devtitans-1@devtitans-15:~/devtitans-gi
```
### 4. Alterando um Arquivo do Controle de Versão
Para entender o funcionamento da atualização de arquivos que já fazem parte do repositório git, abra o arquivo dev1.txt, modifique a frase e salve o arquivo. Por exemplo, edite a frase para:
```
Olá mundo, eu sei usar o Git!
```
Em seguida, acesse o terminal e execute o comando abaixo:
```
git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   dev1.txt
no changes added to commit (use "git add" and/or "git commit -a")
```
Assim, o arquivo dev1.txt está modificado (modified). Portanto, nesse estado, as alterações estão apenas no seu Working Directory. A partir desse ponto, podemos ir para o segundo estágio adicionando o arquivo através do comando git add:
```
git add dev1.txt
```
Depois de rodarmos este comando, o adicionamos ao segundo estágio, ou seja, preparamos, novamente, para um segundo commit:
```
git commit -m "Alterando o dev1.txt"
[master 5313330] Alterando o dev1.txt
 1 file changed, 1 insertion(+), 1 deletion(-)
```
Nunca conseguimos pular um dos estágios. Não conseguiremos commitar, sem antes ter adicionado um arquivo ou vários arquivos. Novamente, se executarmos o comando git status receberemos a mensagem de que não existem mais arquivos a serem comitados.
```
git status
On branch master
nothing to commit, working tree clean
```
### 5. Trabalhando com o Commit
Agora, iremos alterar novamente o conteúdo do arquivo dev1.txt e salvar. Edite o arquivo dev1.txt com o seguinte conteúdo:
```
Olá mundo, eu sei fazer um commit!
```
Iremos agora criar um novo arquivo no nosso repositório para fazer parte do projeto. Para isso, execute o comando abaixo:
```
touch devtitans2.txt
```
Entre no arquivo devtitans2.txt e insira o seguinte conteúdo:
```
Novo arquivo do meu projeto devtitans
```
Em seguida, execute o comando git status para que possa ver o primeiro estágio de Untracked File, por se tratar de um arquivo novo e não fazer parte do controle de versão.
```
git status
```
```
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   dev1.txt
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        devtitans2.txt
no changes added to commit (use "git add" and/or "git commit -a")
```
O próximo passo é executar o comando que prepara o(s) arquivo(s), para serem comitados. Para que possamos ganhar tempo e produtividade, podemos adicionar todos os arquivos modificados de uma só vez. Ao invés de adicionar um por um como anteriormente, executaremos o comando abaixo para adicionar todos:
```
git add .
```
Desta forma, já temos nossos arquivos pronto para ser comitados. Imagine quando existem 10 arquivos, ou mais, para serem adicionados. Existe uma outra maneira de agilizar o processo e comitar todos arquivos de uma vez. Para isso, execute o comando abaixo:
```
git commit -a -m "Comitando todos os arquivos juntos"
```
```
os arquivos juntos"
[master 083ea94] Comitando todos os arquivos juntos
 2 files changed, 1 insertion(+), 1 deletion(-)
 create mode 100644 devtitans2.txt
 ```
A opção -a faz com que os arquivos sejam todos adicionados automaticamente, passando-os para o segundo estágio e já comita usando a mensagem/descrição. Todo processo é feito automaticamente.
### 6. Verificando o Log do Git
O comando git log retorna uma listagem dos últimos commits com o hash de identificação, a data e também o usuário responsável. O git log é uma ferramenta extremamente importante e poderosa. Quando o executamos, conseguimos ver os logs de todos os commits, por ordem decrescente.
```
git log -p
```
```
commit 083ea94de74963d3f6ed82629292b9a024172558 (HEAD -> master)
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:17:42 2023 -0400

    Comitando todos os arquivos juntos

diff --git a/dev1.txt b/dev1.txt
index 0253dcd..5136ae7 100644
--- a/dev1.txt
+++ b/dev1.txt
@@ -1 +1 @@
-Olá mundo, eu sei usar o Git!
+Olá mundo, eu sei fazer um commit!
diff --git a/devtitans2.txt b/devtitans2.txt
new file mode 100644
index 0000000..e69de29

commit 531333098c6b3d9bb678536bd9f128f1b27f788e
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:14:42 2023 -0400

    Alterando o dev1.txt

diff --git a/dev1.txt b/dev1.txt
index 4fd4e7c..0253dcd 100644
--- a/dev1.txt
+++ b/dev1.txt
@@ -1 +1 @@
-Olá mundo, eu sou DevTITAN!
+Olá mundo, eu sei usar o Git!

commit c054b84f051472d3a854a803cc45b9c4cfd53654
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:11:37 2023 -0400

    Meu primeiro commit

diff --git a/dev1.txt b/dev1.txt
new file mode 100644
index 0000000..4fd4e7c
--- /dev/null
+++ b/dev1.txt
@@ -0,0 +1 @@
+Olá mundo, eu sou DevTITAN!
:
```
Este comando, ao mesmo tempo que é muito bom, pode acabar se tornando chato, pois pode ser que não queiramos visualizar todos os logs e alterações. Para isso, temos a opção de rodar o seguinte comando:
```
git log -p -2
```
```
commit 083ea94de74963d3f6ed82629292b9a024172558 (HEAD -> master)
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:17:42 2023 -0400

    Comitando todos os arquivos juntos

diff --git a/dev1.txt b/dev1.txt
index 0253dcd..5136ae7 100644
--- a/dev1.txt
+++ b/dev1.txt
@@ -1 +1 @@
-Olá mundo, eu sei usar o Git!
+Olá mundo, eu sei fazer um commit!
diff --git a/devtitans2.txt b/devtitans2.txt
new file mode 100644
index 0000000..e69de29

commit 531333098c6b3d9bb678536bd9f128f1b27f788e
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:14:42 2023 -0400

    Alterando o dev1.txt

diff --git a/dev1.txt b/dev1.txt
index 4fd4e7c..0253dcd 100644
--- a/dev1.txt
+++ b/dev1.txt
@@ -1 +1 @@
-Olá mundo, eu sou DevTITAN!
+Olá mundo, eu sei usar o Git!
```
Nesse caso o número de resultados exibidos será limitado pelo valor do parâmetro. Este comando é muito utilizado quando queremos saber o que foi alterado no último ou nos últimos commits do projeto e esta é uma forma rápida de se fazer isso.
Outro comando útil que pode ser utilizado é o stat, que mostrará o git log, mas com estatística de todos os commits:
```
git log --stat
```
```
commit 083ea94de74963d3f6ed82629292b9a024172558 (HEAD -> master)
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:17:42 2023 -0400

    Comitando todos os arquivos juntos

 dev1.txt       | 2 +-
 devtitans2.txt | 0
 2 files changed, 1 insertion(+), 1 deletion(-)

commit 531333098c6b3d9bb678536bd9f128f1b27f788e
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:14:42 2023 -0400

    Alterando o dev1.txt

 dev1.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

commit c054b84f051472d3a854a803cc45b9c4cfd53654
Author: Oliveira4driano <oliveira.ifam@gmail.com>
Date:   Fri Mar 31 19:11:37 2023 -0400

    Meu primeiro commit

 dev1.txt | 1 +
 1 file changed, 1 insertion(+)
 ```
No entanto, pode ser que você queira deixar a listagem de logs mais enxuta, removendo alguns dados que poluem o seu terminal, deixando apenas a mensagem do commit e a hash. Para isso rode o seguinte comando:
```
git log --pretty=oneline           # Com este comando, teremos todos os logs de uma forma mais amigável
```
```
083ea94de74963d3f6ed82629292b9a024172558 (HEAD -> master) Comitando todos os arquivos juntos
531333098c6b3d9bb678536bd9f128f1b27f788e Alterando o dev1.txt
c054b84f051472d3a854a803cc45b9c4cfd53654 Meu primeiro commit
```
Por fim, podemos também adicionar parâmetros utilizando o pretty, acrescentando as informações necessárias que queremos. Execute o seguinte comando para exibir as mesmas informações anteriores, além de incluir o autor e a hora:
```
git log --pretty=format:"%h - %an, %ar : %s"
```
```
083ea94 - Oliveira4driano, 3 minutes ago : Comitando todos os arquivos juntos
5313330 - Oliveira4driano, 6 minutes ago : Alterando o dev1.txt
c054b84 - Oliveira4driano, 9 minutes ago : Meu primeiro commit
```
Lembrando que não é preciso decorar todos estes comandos, basta saber que existem estas opções de visualizações e com o tempo se acostumam com os comandos mais utilizados.
### 7. Ignorando Alguns Arquivos
É comum que em nossos projetos existam arquivos indesejados que não queremos que façam parte do nosso repositório, como por exemplo arquivos gerados automaticamente por uma IDE. Para evitar a inclusão desses arquivos no repositório, basta criarmos um arquivo oculto na pasta raiz do projeto, chamado .gitignore. Neste arquivo, iremos adicionar o nome de todos os arquivos e pastas que devem ser ignorados pelo controle de versão.
Para testar no projeto, crie um novo arquivo chamado esteArquivoSeraIgnorado.txt:
```
touch esteArquivoSeraIgnorado.txt  # Execute o comando na raíz da pasta devtitans-git
```
Em seguida, acesse o terminal e rode o comando git status:
```
git status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        esteArquivoSeraIgnorado.txt
nothing added to commit but untracked files present (use "git add" to track)
```
Vocês verão que ele se encontra com o status untracked file, pois acabamos de criá-lo. Agora, no arquivo .gitignore, adicionem o nome deste arquivo, para que ele seja ignorado.
```
code .gitignore     # Adicione neste arquivo a linha abaixo
```
```
esteArquivoSeraIgnorado.txt
```
Podemos adicionar qualquer arquivo ou pasta para ser ignorado, bastando apenas escrever o nome do arquivo ou da pasta em cada linha. Depois de adicionar o arquivo no .gitignore, execute novamente o comando git status:
```
git status
```
```
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        .gitignore
nothing added to commit but untracked files present (use "git add" to track)
```
Podemos visualizar que o arquivo "esteArquivoSeraIgnorado.txt", que antes era untrackad file, não consta mais para ser comitado. Isso ocorre pois o Git ignorou o arquivo e não o reconhece. Também observamos que o arquivo .gitignore, que criamos para listar os arquivos ignorados, aparecerá para ser adicionado ao controle de versão. Para adicioná-lo, executaremos os comandos git add e git commit:
```
git add .gitignore
git commit -m "adicionando o git ignore"
```
```
[master 0390733] adicionando o git ignore
 1 file changed, 1 insertion(+)
 create mode 100644 .gitignore
 ```
### 8. Removendo um Arquivo Antes do Commit
Há casos que queremos reverter uma situação ou remover um arquivo para não fazer parte do commit. Para esses casos, podemos utilizar o comando reset HEAD. Aqui, simularemos um caso muito normal no dia-a-dia do programador, que é adicionar todos os arquivos de uma vez e remover apenas os que não fazem parte. Vamos fazer este teste com 3 arquivos.
Para isso, criaremos os arquivos e utilizamos o comando add do git:
```
touch cod1.txt
touch cod2.txt
touch cod3.txt
git add .
```
Ao executar o git status, obervamos que os arquivos cod1.txt, cod2.txt e cod3.txt encontram-se prestes a serem commitados.
```
git status
```
```
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   cod1.txt
        new file:   cod2.txt
        new file:   cod3.txt
```
Para retirar algum arquivo desse estágio, executamos o comando git reset HEAD com o nome do arquivo:
```
git reset HEAD cod2.txt
```
Depois de executar este comando, se executar o comando git status, observamos que o arquivo selecionado sai do segundo estágio e volta ao primeiro, como Untracked File:
```
git status
```
```
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   cod1.txt
        new file:   cod3.txt
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        cod2.txt
```       
Após preparar todo o commit, deixando somente os arquivos que deverão fazer parte dele, basta realizarem o commit. Saiba que, depois do commit, não é possível fazer mais nada, somente voltar a versão anterior.
### 9. Voltando Versões
Na seção anterior, adicionamos 3 arquivos e depois removemos um deles utilizando o reset HEAD. Falaremos então sobre voltar versões, pois esta é a grande finalidade de se trabalhar com controle de versões.
Existem diversas formas de voltar uma versão. Umas mais simples, outras mais complicadas. No final, temos o mesmo efeito, que é a volta para alguma versão anterior específica.
Uma das maneiras mais simples é utilizando o comando checkout, passando o hash do commit. Vejam o exemplo abaixo:
```
git log --pretty=oneline
```
```
03907334b6d3fa45322fa9a01fb1c817bf0a8b64 (HEAD -> master) adicionando o git ignore
083ea94de74963d3f6ed82629292b9a024172558 Comitando todos os arquivos juntos
531333098c6b3d9bb678536bd9f128f1b27f788e Alterando o dev1.txt
c054b84f051472d3a854a803cc45b9c4cfd53654 Meu primeiro commit
```
Escolhemos então a hash do commit que queremos voltar e utilizamos no comando git checkout. Por exemplo, vamos usar a hash do commit que contém a mensagem "Alterando o dev1.txt":
```
git checkout 531333098c6b3d9bb678536bd9f128f1b27f788e
```
```
A       cod1.txt
A       cod3.txt
Note: switching to '531333098c6b3d9bb678536bd9f128f1b27f788e'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at 5313330 Alterando o dev1.txt
```
Após executar este comando, temos uma mensagem informando que o nosso estado atual está apontando para o commit que informamos no comando checkout. Notem que não voltamos este commit como sendo o atual. Para que possamos trabalhar com os arquivos atuais e os arquivos do commit que selecionamos, o Git cria uma nova camada, chamada branch. Falaremos mais sobre branchs, mas gostaríamos de mostrar que isso é verdade. Para isso, execute o comando abaixo:
```
git branch
* (HEAD detached at 5313330)
  master
devtitans-1@d
```
Geralmente, todas as alterações feitas, são no branch master, mas vocês podem ver que estamos trabalhando em outro branch, o qual está marcado com um asterísco. Vamos supor que já fizemos tudo o que tínhamos que fazer nesta versão que acessamos, então basta retornar para a versão master, e ignorar este branch que foi criado.
```
git checkout master
A       cod1.txt
A       cod3.txt
Previous HEAD position was 5313330 Alterando o dev1.txt
Switched to branch 'master'
```
