# AOSP-Android
### requisitos
- git
- python3
### Problem scenario:
```
/usr/bin/env: ‘python’: No such file or directory
```
Possible Solution #1

If Python 3 is not installed, install it: 
```
apt-get install python3
```
Possible Solution #2

If Python 3 has been installed, run these commands: 
```
whereis python3
Then we create a symlink to it: sudo ln -s /usr/bin/python3 /usr/bin/python
```

#### Onde obter o AOSP? E como ele é composto?
O código-fonte do AOSP pode ser obtido em: http://source.android.com/source/index.html. O AOSP é versionado através do git, mas, por ser formado por centenas ou milhares de repositórios distintos, o Google criou uma ferramenta chamada repo para gerenciar todos estes repositórios necessários para compor o AOSP. Para instalar tal ferramenta, siga os passos abaixo:

Crie um diretório chamado bin no seu home e entre neste diretório:
```
cd ~
mkdir bin
cd bin
```
 

Baixe a ferramenta conforme abaixo:
```
wget https://storage.googleapis.com/git-repo-downloads/repo -O repo 
```

Modifique as permissões para todos os arquivos de 
```
~/bin/repo:
chmod a+x ~/bin/repo 
```

Por fim, acrescente a sua variável de ambiente PATH o caminho para o diretório bin:
```
export PATH=~/bin:$PATH
``` 

Nesta ferramenta, quem diz quais repositórios irão compor o AOSP é um arquivo chamado manifest.xml. Inclusive, uma das primeiras etapas de customização dos fabricantes que embarcam o Android em seus produtos é filtrar quais repositórios devem e não devem compor a base do AOSP desejada.

#### Como obter o AOSP?
 Para obter o AOSP, siga os passos abaixo:

* Crie em seu home um diretório para baixar o código-fonte do AOSP e entre neste diretório. Supondo que tal diretório se chame android_aosp_source_code, execute o seguinte comando:
```
cd ~
mkdir android_aosp_source_code
cd android_aosp_source_code
```

* Faça o repo init. O repo init consiste em baixar o manifest.xml em um diretório oculto .repo, além de preparar o terreno para baixar os repositórios (algo a ser feito no próximo passo). executar o comando na /home
```
repo init -u https://android.googlesource.com/platform/manifest
```
* Uma vez feito o repo init, tudo está preparado para baixar de fato os repositórios (listados no manifest). Para isso execute o comando repo sync e aguarde. O download demora bastante, uma vez que pode vir, facilmente, mais de 30 GB de conteúdo.

### BAIXANDO O AOSP COM O REPO (CONT.)
Por padrão, o repo irá baixar a branch de desenvolvimento (master) do AOSP.
Podemos baixar uma versão específica do Android indicando a branch ou tag com o
parâmetro -b:
A lista de branches e tags existentes está disponível no site do projeto:
```
$ repo init -u https://android.googlesource.com/platform/manifest \-b android-11.0.0_r39
repo init -u https://android.googlesource.com/platform/manifest \-b android-13.0.0_r24
```
https://source.android.com/setup/start/build-numbers
```
execute este comando para saber quantos nucleos seu computador suporta e definir no repo sync
$ nproc --all
```
retorno: 8
então seu comando ficaria repo sync -j8 para realizar o processamento com 8 nucleos que sua maquina suporta.
```
cd android_aosp_source_code
repo sync -j8
```

### Baixando o AOSP versão especifica
 Por padrão, o <strong>repo</strong> irá baixar a branch de desenvolvimento (master) do AOSP
 podemos baixar uma versão especifica do Android indicando o branch com <string>-b</strong>
 ```
 repo init -u https://android.googlesource.com/platform/manifest\-b android-12.1.0_r26
 repo init -u https://android.googlesource.com/platform/manifest \-b android-13.0.0_r24
 ```
 A lista de branches existentes está disponivél no site
 ```
 https://source.android.com/docs/setup/about/build-numbers
 https://developer.android.com/ndk/downloads/revision_history
 ```
 ### Repositorios alternativos
 A linaro fornece uma árvore alternativa com suporte a um conjunto maior de dispositivos de hardware com foco em ARM:
 ```
 repo init -u git://android.git.linaro.org/platform/manifest.git #https://git.linaro.org/
 ```
 O lineageOS possui verões customizadas focadas em dispositivos de consumo (smartphones e tablets):
 ```
 repo init -u https://github.com/LineageOS/android.git
 ```
 
# Compilação do AOSP
Assim que a execução do repo sync for terminada, todo o código-fonte do AOSP já estará à sua disposição. O próximo passo é, portanto, fazer a compilação do AOSP. A compilação do Android é formada por duas etapas distintas: preparação do ambiente de compilação (onde as variáveis de ambiente necessárias são configuradas) e a compilação propriamente dita.

* Preparação do ambiente de compilação: para isso, é utilizado um script para preparação das variáveis de ambiente e uma ferramenta (já contida no AOSP) chamada <strong>lunch</strong>. Essa ferramenta tem como utilidade permitir se escolher para qual dispositivo o AOSP será compilado e o tipo de Android a ser compilado (como, por exemplo, o tipo <strong>eng</strong>: um Android com privilégios de <strong>engenharia/root</strong>). Portanto, para preparar o ambiente de compilação, esteja na pasta em que o código-fonte do AOSP foi baixado (este artigo faz a suposição que esteja na pasta ~/android_aosp_source_code) e execute o comando abaixo:
```
source build/envsetup.sh
```

Agora é a hora de se escolher o dispositivo-alvo (target) e tipo de compilação de Android (build) com a ferramenta lunch. Como aqui buscamos testar tudo em emulador e não pretendemos criar uma build com restrições de execução e acessos, será escolhido como target uma plataforma genérica em modo eng. Para isso, execute o comando abaixo e escolha a opção correspondente a aosp_arm-eng.

lunch
#### Compilação do AOSP: 
para compilar, utilize o comando make. É altamente recomendável que você especifique o máximo número de jobs possíveis (atributo atrelado ao processador do computador host/que irá compilar). Para um computador com processador de 8 núcleos/cores, um bom número de jobs é 4.
```
make -j4
```

A compilação é um processo bem demorado e com desempenho altamente dependente da quantidade de memória RAM disponível e tipo de unidade de armazenamento do computador host.

Ao final do processo de compilação, a build Android gerada estará disponível em: 
 ```
~/android_aosp_source_code/out/target/product/generic/
 ```
 ### ENVSETUP.SH
 * lunch: seleciona o produtoe a variante de build para compilação.
 * croot: volta para o diretório raiz do AOSP
 * godir: vai para o diretório contendo o arquivo especifico
 * cgrep: execute um grep em arquivos <strong>.c, .cpp e .h</strong>
 * resgrep: executa um grep em arquivos de recurso <strong>*.xml</strong>
 * mangrep: executa um grep em arquivos <strong>AndroidManifest.xml</strong>.
 * hmm: exibe a lista completa de comandos disponíveis.
 # Emulação do AOSP
O AOSP já vem com um emulador, o que facilita muito o aprendizado, testes e desenvolvimento com Android Embarcado.

Este emulador, na verdade, consiste em um qemu customizado para rodar builds Android. Antes de utilizá-lo, assegure-se de ter rodado o script de preparação de variáveis de ambiente. Isto é importante para que o emulador saiba qual plataforma emular e onde está a build Android compilada.
```
source build/envsetup.sh
```
Feito isso, utilize o comando abaixo para emular o Android que você compilou:
```
emulator &
```
O emulador ainda dá acesso, via adb, ao console do Android.

#### Construindo sua primeira aplicação C nativa do Android
Uma vez com o código baixado, compilado e apto a rodar no emulador, podemos finalmente iniciar o desenvolvimento da primeira aplicação em C para rodar na camada nativa do Android.

### Considerações sobre compilação de aplicações nativas no Android
A compilação de qualquer aplicação / módulo nativo no Android é feita junto com a compilação do Android ou separadamente (e, posteriormente, adicionada às respectivas imagens na build Android final).

É importante relembrar que o Android tem seu próprio sistema de build, o que significa dizer que o programador não pode “mandar” o Android compilar algo com parâmetros específicos, mas sim deve se limitar a escrever o código-fonte da aplicação e um makefile para a mesma, e o sistema de build do Android se encarrega de compilar. Obrigatoriamente, todos os makefiles de aplicações nativas no Android devem se chamar Android.mk. Visando maior organização e modularização, makefiles com nomes diferentes podem ser utilizados, desde que incluídos, em algum ponto, por algum makefile chamado Android.mk.

### Projeto da primeira aplicação em C nativa no Android
Esta aplicação, para fins de exemplo, será um Hello World. Para isso, siga o procedimento abaixo:

* Assumindo que você esteja com o código-fonte do AOSP baixado em ~/android_aosp_source_code, vá até o diretório device/generic/aosp_arm:

```
cd ~/android_aosp_source_code/device/generic/aosp_arm
```

* Neste diretório, crie um diretório específico para sua aplicação. Aqui será considerado o nome hello_world como nome do diretório:

```
mkdir hello_world
```
* Crie no diretório específico da sua aplicação (ou seja, o diretório ~/android_aosp_source_code/device/generic/aosp_arm/hello_world) um arquivo chamado hello_world.c (código-fonte de sua aplicação C) com o seguinte conteúdo:
```
/* Primeira aplicacao nativa em C para Android */
#include <stdio.h>


int main(void)
 
{

printf(“\r\nHello world\n”);
printf(“\r\nEsta eh minha primeira aplicacao em C nativa para Android!!!\n”);
return 0;

}
```
 
* Agora, é hora de criar o makefile de sua aplicação. Para isso, no mesmo diretório (~/android_aosp_source_code/device/generic/aosp_arm/hello_world), crie um arquivo chamado <p>Android.mk</p> com o seguinte conteúdo:
```
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES = hello_world.c

LOCAL_MODULE = hello_world

#define que sua aplicacao somente sera incluida em builds do tipo eng e/ou quando for

#explicitamente solicitada em scripts init.rc

LOCAL_MODULE_TAGS = optional

#define que sua aplicacao sera um executavel no Android

include $(BUILD_EXECUTABLE)
```
* Agora, é preciso especificar que sua aplicação deve estar presente na build Android a ser compilada, uma vez que ela foi definida como opcional. Para isso, edite o arquivo ~/android_aosp_source_code/device/generic/aosp_arm/common.mk de forma a adicionar o seguinte trecho após a definição original de PRODUCT_PACKAGES:
```
PRODUCT_PACKAGES += \
hello_world
```
* Observação: infelizmente, nomes de makefiles podem sofrer alterações de tempos em tempos (devido à falta de padrões no AOSP em alguns aspectos, conforme já mencionado anteriormente neste artigo). Se o makefile common.mk não existir neste diretório, o makefile correspondente (neste mesmo diretório) é aquele onde está definido o PRODUCT_PACKAGES (só haverá um makefile nesta pasta com esta definição).

Pronto! Agora basta compilar o AOSP (conforme explicado no tópico “Compilação do AOSP” deste artigo) e a sua aplicação já estará contida na build Android compilada.

### Testando a aplicação desenvolvida
Finalmente, é hora de testar a aplicação desenvolvida rodando na build Android compilada. Para isso, siga o procedimento abaixo:

1. Execute o emulador (veja como no tópico “Emulação do AOSP” deste artigo).
2. Comunique-se com o Emulador através da ferramenta adb. Para isso, execute o comando 
```
adb wait-for-device 
```
no terminal Linux de seu computador host. Assim que a execução do comando for terminada, execute o comando 
```
adb devices 
```
e certifique-se que o emulador Android consta na lista de dispositivos exibida.
3. Execute o comando abaixo para abrir uma sessão de terminal com o Android do emulador:
```
adb shell
```
* Execute a sua aplicação pelo seu nome (no caso, o makefile construído neste artigo a nomeia como hello_world).
hello_world
 

 ### Considerações finais sobre Android Embarcado
O Android é um sistema operacional dominante, sendo parte integrante de muitos dispositivos que utilizamos rotineiramente, como, por exemplo: smartphones, tablets, smart TVs, smart watches e veículos. Além disso, é um sistema operacional, em essência, open-source, o que faz com que sua aplicação e evolução aumentem exponencialmente.

Porém, talvez devido ao crescimento exponencial de desenvolvedores e ferramentas para o Android, o AOSP (Android Open-Source Project) possui um grande ponto negativo: documentação fraca. Isso dificulta o aprendizado rápido e força a leitura de códigos-fonte para completo entendimento do funcionamento de um módulo. Apesar disso, é um sistema com arquitetura muito bem definida e robusta.

