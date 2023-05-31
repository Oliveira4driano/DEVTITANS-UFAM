Laboratório 4.2: Compilando, Executando e Modificando o Android
IntroduçãoEm suas primeiras versões, o AOSP usava o make como sistema de compilação (build system). Arquivos com o nome Android.mk eram usados para configurar a compilação. Entretanto, o make tornou-se lento devido ao tamanho do Android. Ele foi então substituído pelo Soong, que usa arquivos de blueprint chamados Android.bp. Os arquivos Android.mk ainda existentes são convertidos usando a ferramenta Kati. Para agilizar ainda mais o processo de compilação, tanto o Soong quanto o Kati alimentam uma outra ferramenta chamada Ninja, que irá realmente gerar os comandos de compilação das diversas partes do Android. Todo esse processo é ilustrado na figura abaixo:

1. Instalando os Pacotes NecessáriosO processo de compilação do Android requer uma série de utilitários instalados em sua máquina. Para isso, execute os comandos abaixo para instalar os pacotes necessários:
sudo apt install vim git git-core python3 python-is-python3 python-mako openjdk-8-jdk android-tools-adb bc bison build-essential curl flex g++-multilib gcc-multilib gnupg gperf imagemagick lib32ncurses-dev lib32readline-dev lib32z1-dev liblz4-tool libncurses5-dev libsdl1.2-dev libssl-dev libxml2 libxml2-utils lzop pngcrush rsync schedtool squashfs-tools xsltproc yasm zip zlib1g-dev libtinfo5 libncurses5 zip libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev libgl1-mesa-dev screen unzip fontconfig kpartx libcurl4
sudo apt install mplayer pigz pbzip2        # Alguns pacotes extras usados nos laboratórios
Muitos desses pacotes já devem estar instalados no seu sistema e não serão baixados novamente. O próprio APT se encarrega de baixar apenas os pacotes não instalados.
2. Configurando o AmbienteAntes de compilar ou usar qualquer um dos comandos específicos do AOSP, é necessário configurar o ambiente (terminal) usando o script envsetup.sh abaixo:
cd ~/aosp
source build/envsetup.sh
O source executa comandos de um script mudando o ambiente do terminal atual (ao invés de criar um novo ambiente para o script). Já o envsetup.sh é o script que configura no ambiente uma série de funções/comandos que facilitam o uso do AOSP. Este script precisa ser executado sempre que você abre um novo terminal.
Abra o script build/envsetup.sh usando um editor de texto (e.g., code). Qual o nome da primeira função declarada? Olhando para a implementação dela, o que faz essa função?

Outros comandos úteis declarados pelo script incluem:
Comando	Descrição
lunch	Seleciona o produto de destino que será trabalhado na sessão do terminal.
croot	Volta para o diretório raiz do aosp (comando cd ~/aosp).
m	Compila o Android inteiro (mesma coisa que make).
Conforme mostrado acima, um dos comandos declarados pelo envsetup.sh é o comando lunch. Este comando seleciona qual o produto que iremos trabalhar nessa seção do terminal. Basicamente ele configura uma série de variáveis de ambiente do seu terminal relacionadas ao dispositivo selecionado. Assim como o envsetup.sh, esse comando precisa ser executado em cada terminal aberto. Para ver a lista de produtos, simplesmente execute o comando:
lunch
O comando acima irá mostrar uma lista de produtos disponíveis para serem compilados. Você pode pressionar CTRL+C para sair do comando, pois iremos executá-lo novamente. Analisando a lista de produtos, note que alguns deles se destinam a processadores genéricos, enquanto que outros são mais específicos. A lista a seguir mostra um resumo dos principais nomes encontrados:
Produto	Descrição do Produto
aosp_barbet-userdebug	Produto para ser usado no dispositivo Google Pixel 5a.
aosp_car_x86_64-userdebug	Usado para emular um Android sendo executado em um veículo.
aosp_cf_x86_64_phone-userdebug	Android sendo emulado no Cuttlefish, usando um processador X86 de 64 bits.
aosp_cf_x86_64_tv-userdebug	Usado para emular um Android em uma TV usando o Cuttlefish.
aosp_flame-userdebug	Produto para ser usado no dispositivo Google Pixel 4.
beagle_x15-userdebug	Produto específico para a placa Beagle x15.
sdk_phone_x86_64-userdebug	Produto para o Emulator executado em um X86 de 64 bits. Usaremos nesse curso.
Além disso, observando o final dos nomes, pode-se notar três variações diferentes de compilação:
Variação	Descrição
user	Versão final do Android que será executado pelos usuários, sem informações de debug e sem acesso a root.
userdebug	Mesmo do anterior, mas com informações de debug e com acesso a root.
eng	Versão de desenvolvimento, com ferramentas extras, informações de debug e acesso a root.
Neste curso, usaremos a versão eng ou userdebug dos produtos, para termos acesso ao usuário root do Linux no Android. Mais especificamente, usaremos o produto sdk_phone_x86_64-userdebug. Conforme mencionado, o produto sdk_phone_x86_64-userdebug gera uma versão do Android para ser executado no emulator em um computador com processador X86 de 64 bits, provavelmente o mesmo do seu computador, tornando a execução mais eficiente. Para configurar o produto sdk_phone_x86_64-userdebug, pressione CTRL+C no lunch anterior (caso não tenha feito ainda), e execute o comando lunch abaixo.
lunch sdk_phone_x86_64-userdebug
Conforme mencionado, este comando precisará ser executado a cada novo terminal, logo depois do comando source build/envsetup.sh. Observe a saída do comando lunch. Ele lista algumas das variáveis internas criadas e seus valores. Estes valores são usados para configurar diversas variáveis de ambiente. Para ver as variáveis de ambiente configuradas no seu terminal atual, execute o comando export:
export
Observe, em especial, as variáveis que começam com ANDROID_, TARGET_, e a variável PATH:
export | grep "ANDROID_\|TARGET_\|PATH"
Uma variável importante é a ANDROID_HOST_OUT. No AOSP, "out" indica a saída das compilações e outros resultados de comandos (imagem final do Android, arquivos intermediários, etc). Basicamente, o AOSP separa todo o seu código-fonte dos códigos compilados. Indique abaixo o valor da variável mencionada.

O AOSP vem com o seu próprio Java para compilar as aplicações Android. Este é configurado via variáveis de ambiente. Indique abaixo o diretório do Java no AOSP.

Assim como no caso do Java, o AOSP vem com seu próprio compilador C/C++ e outros utilitários também. Nessa versão atual do Android (Android 13) houve substituição do GCC para o LLVM como compilador padrão de códigos nativos. Indique o path desse novo compilador no AOSP.

3. Compilando o AndroidFinalmente, chegou a hora de compilar o Android. Para isso, execute o comando m:
m
Se você baixou o AOSP e este está sendo compilado pela primeira vez, este processo deve demorar entre 3 e 5 horas, dependendo da configuração da sua máquina. Se você está usando o AOSP já disponível na máquina, a compilação deve demorar alguns poucos minutos, uma vez que ele já está pré-compilado. Em alguns outros casos menos comuns (e.g., o comando lunch foi executado com outro produto), o processo de compilação pode demorar entre 15 a 30 minutos. Os seguintes fatores impactam o tempo de compilação:
Quantidade de processadores/núcleos da máquina
Velocidade do processador
Memória (mínimo: 16GB)
Velocidade do disco (recomendado: disco SSD)
Além disso, é necessário pelo menos 500GB de espaço livre em disco.
O resultado final da compilação é a imagem do Android, no arquivo out/target/product/emulator_x86_64/system-qemu.img. Execute o comando abaixo para ver o seu tamanho:
ls -lh out/target/product/emulator_x86_64/system-qemu.img
Copie a saída do comando anterior e cole aqui.
4. Executando o EmuladorPara executar o emulator já abrindo o Android compilado, execute:
emulator &      # Executa o emulator em background (sem prender o terminal)
Quando o emulator estiver aberto, clique no botão abaixo para fazer um screenshot da sua tela. Na permissão do navegador, selecione a tela inteira ou apenas a janela do emulador. Em qualquer caso, certifique-se que o emulator esteja aparecendo em sua tela dentro de 3 segundos.

Explore o Android recém-compilado. Note como ele é um pouco diferente do Android no seu celular. Este é o Android "puro" sendo, em especial, bem mais enxuto e com poucos aplicativos, todos livres e de código-fonte aberto. No seu celular pessoal, boa parte dos apps são aplicativos proprietários do Google Apps, da fabricante ou da operadora. Para ver os aplicativos instalados no emulador, faça como você faria em um celular, mas usando o mouse: na tela principal, clique e arraste o mouse de baixo para cima.
Abra o aplicativo Settings e clique no último item (About emulated device). Navegue até o último item, aonde diz Build number. Note o nome sdk_phone_x86_64-userdebug, o nome do produto selecionado pelo comando lunch. Clique no botão abaixo para fazer um screenshot da tela.

Para prosseguir, finalize o emulator aberto. Para isso, clique no "×" da janela do emulator, ou clique e mantenha pressionado o botão de "power" e desligue o Android, ou vá para o terminal e digite CTRL+C.
5. Modificando o Código-Fonte I - SettingsA seguir, iremos fazer uma pequena modificação no código-fonte do Android, recompilar e testar. Mais especificamente, iremos mudar uma string no app de configurações (Settings) do Android. Para isso, edite o arquivo res/values/strings.xml do aplicativo Settings. Este arquivo é o mesmo arquivo de strings de suas aplicações feitas no Android Studio:
code packages/apps/Settings/res/values/strings.xml
Procure pela string de nome build_number. Modifique seu conteúdo de "Build number" para "Build number (DevTITANS)".
Salve o arquivo, feche o emulador se já não o fez (libera memória) e recompile o Android:
m
Essa compilação deve demorar uns 2 minutos, uma vez que só é necessário recompilar o app Settings e gerar novamente a imagem do Android. Em seguida, execute o emulador para ver as mudanças:
emulator
Abra o aplicativo Settings e navegue até o Build number modificado. Clique no botão abaixo para fazer um screenshot da tela.

Usaremos o Git para retornar o código ao seu estado original. Entre no diretório packages/apps/Settings e observe que você tem códigos modificados sem nenhum commit.
cd packages/apps/Settings
git status
Copie a saída do comando anterior e cole aqui.
Para restaurar o repositório Git atual para o estado original, execute o comando abaixo. Em seguida, observe o status do Git e volte para o diretório raiz do AOSP:
git reset --hard HEAD     # Restaura o repositório git
git status                # Mostra o status do git
croot                     # Volta ao diretório do AOSP
Copie a saída do comando anterior e cole aqui.
6. Modificando o Código-Fonte II - Screenshot WatermarkAgora faremos uma alteração mais complexa no Android. Iremos modificar o resultado retornado pela operação de screenshot. Mas antes disso, vamos observar o comportamento normal de um screenshot no emulador. Para isso, com o emulador aberto, execute o seguinte comando no seu terminal e, imediatamente, observe o emulador. Copie e cole todas as linhas abaixo de uma só vez no seu terminal:
adb shell "
    su root sendevent /dev/input/event1 1 114 1
    su root sendevent /dev/input/event1 1 116 1
    su root sendevent /dev/input/event1 0 0 0
    sleep 1
    su root sendevent /dev/input/event1 1 114 0
    su root sendevent /dev/input/event1 1 116 0
    su root sendevent /dev/input/event1 0 0 0"
Não se preocupe em entender o comando. Nós iremos estudar o ADB e o comando sendevent nos laboratórios seguintes. Basicamente, o que o comando faz é simular o pressionamento dos botões power e baixar volume do celular ao mesmo tempo. Esse conjunto de teclas é usado para tirar um screenshot da tela. Se você nunca fez isso, faça no seu celular pessoal e veja funcionando.
Após executar o comando, observe no emulador a tela sendo capturada. Uma outra forma de fazer isso sem nem precisar ir no emulador é executando o comando a seguir:
adb exec-out screencap -p > screen.png
xdg-open screen.png
O primeiro comando executa o utilitário screencap do Android (que captura a tela) usando o adb e manda a saída para o arquivo screen.png. Em seguida, a segunda linha abre e mostra o arquivo (imagem da tela).
Agora sim, nós iremos modificar essa captura de tela. Conforme visto no laboratório anterior, o SurfaceFlinger é um serviço do Android responsável por organizar a pintura da tela do dispositivo, incluindo também a captura de tela. Abra a implementação da classe:
code frameworks/native/services/surfaceflinger/SurfaceFlinger.cpp
Procure pelo código em cinza abaixo e insira o código em negrito, de forma que o seu arquivo fique igual ao código a seguir:
        clientCompositionLayers.insert(clientCompositionLayers.end(),
                                       std::make_move_iterator(results.begin()),
                                       std::make_move_iterator(results.end()));
        renderedLayers.push_back(layer);
    }

});

compositionengine::LayerFE::LayerSettings watermarkLayer;
watermarkLayer.source.buffer.buffer = nullptr;
watermarkLayer.source.solidColor = half3(0.0, 0.0, 0.0);
watermarkLayer.geometry.boundaries = FloatRect(sourceCrop.left+200, sourceCrop.top+200, sourceCrop.right-200, sourceCrop.bottom-200);
watermarkLayer.alpha = half(0.8);
clientCompositionLayers.push_back(watermarkLayer);

std::vector clientRenderEngineLayers;
clientRenderEngineLayers.reserve(clientCompositionLayers.size());
std::transform(clientCompositionLayers.begin(), clientCompositionLayers.end(),
       std::back_inserter(clientRenderEngineLayers),
       [](compositionengine::LayerFE::LayerSettings& settings)
               -> renderengine::LayerSettings { return settings; });
Não se preocupe em entender o código. Mas, basicamente, nós estamos incluindo um novo layer (camada) a ser pintado. Essa camada começa no pixel (200, 200), na parte superior-esquerda do dispositivo, e vai até o canto inferior-direito (também há 200 pixels do canto). O conteúdo da camada, ao invés de ser uma imagem, é apenas um fundo preto com transparência (alpha) de 80%.
Após a modificação, recompile o Android e abra o emulador. Em seguida, tire novamente um screenshot usando uma das duas formas mostradas anteriormente. Note como o screenshot veio com um retângulo escuro no meio da imagem como se fosse uma marca d'água (watermark).
Clique no botão abaixo para tirar um screenshot da sua tela mostrando o screenshot do emulador com a marca d'água. Se você tirou o screenshot dentro do emulador, use o app Gallery para ver a imagem.

O interessante dessa modificação é que como ela foi feita no núcleo do Android, basicamente é impossível para o usuário tirar um screenshot da tela sem ela vir com essa marca d'água. Uma aplicação interessante para essa modificação seria algo relacionado à segurança da informação ou algo nesse sentido.
Por fim, use o Git para restaurar o repositório frameworks/native ao seu estado original.
7. Super-Resumo de Compilação do AndroidComo nas seções anteriores o processo de compilação do Android foi muito detalhado, a seguir será mostrado um resumo dos comandos necessários para baixar e compilar o Android. Você não precisa executar esses comandos novamente neste laboratório.
1. Baixando o AOSP:
cd ~
mkdir aosp
cd aosp
repo init --depth=1 -u https://android.googlesource.com/platform/manifest -b android-13.0.0_r24
repo sync -c -j$(nproc)
2. Configurando o ambiente:
source build/envsetup.sh
lunch sdk_phone_x86_64-userdebug
3. Compilando o Android:
m 
4. Executando:
emulator 
