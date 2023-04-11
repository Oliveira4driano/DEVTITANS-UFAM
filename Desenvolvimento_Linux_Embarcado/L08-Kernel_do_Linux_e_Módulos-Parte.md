# Laboratório 8: Kernel do Linux e Módulos - Parte I
## Introdução
O kernel é o principal responsável por fazer o hardware e o software funcionarem juntos em um sistema operacional, usando endereços físicos e 
acessando o hardware em nome dos processos do usuário enquanto aplica as permissões de acesso. O carregador de inicialização faz o que é necessário para 
extrair e descompactar o kernel na RAM e depois passar o controle para ele.
O kernel encontra-se em um estado de sistema elevado, que inclui um espaço de memória protegido e acesso total ao hardware do dispositivo. 
Esse estado do sistema e o espaço de memória são chamados de espaço do kernel. Neste espaço, o acesso principal ao hardware e aos serviços do 
sistema são gerenciados e fornecidos como um serviço para o restante do sistema. Por outro lado, as aplicações do usuário são realizadas no chamado 
espaço do usuário, onde podem alcançar um subconjunto dos recursos disponíveis da máquina por meio de chamadas de sistema do kernel, ou seja, os 
usuários não possuem acesso direto ao hardware.
O kernel tem quatro principais funções:
* Gerenciamento da memória: monitora o volume de memória utilizado para armazenar o que (arquivos, dados etc.) e o local (ambiente).
* Gerenciamento de processos : determina quais processos podem usar a unidade central de processamento (CPU), quando e por quanto tempo.
* Drivers de dispositivos: atua como intermediário/intérprete entre o hardware e os processos.
* Chamadas do sistema e segurança: recebe solicitações dos processos para a execução de serviços.
Ao modificar um kernel, podemos editar o suporte de hardware como nativo ou podemos carregar o suporte como um módulo carregável conforme a necessidade.
### 1. Explorando o Kernel
Para verificar a versão do seu kernel instalado, execute o comando abaixo:
```
uname -r
5.15.0-53-generic
```
Também é possível obter a versão do kernel utilizando as informações contidas em /proc:
```
cat /proc/version
```
```
Linux version 5.15.0-53-generic (buildd@lcy02-amd64-047) (gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0, GNU ld (GNU Binutils for Ubuntu) 2.38) #59-Ubuntu SMP 
Mon Oct 17 18:53:30 UTC 2022
```
Dependendo da distribuição, se você tiver vários kernels instalados, poderá ver vários tipos de arquivo com a versão como parte de seus nomes de arquivo 
e, em seguida, um link simbólico apontando para o mais recente instalado por meio das atualizações da distribuição.
O arquivo do Kernel que é descompactado e carregado na memória pelo carregador de inicialização encontra-se em /boot/vmlinuz-<kernel-versão>. 
Possivelmente várias versões diferentes serão mostradas, além de um link simbólico chamado vmlinuz apontando para o arquivo mais recente. Acesse o diretório /boot e liste os arquivos e pastas neste diretório:
```
cd /boot
ls
```
```
config-5.15.0-52-generic  initrd.img-5.15.0-52-generic  memtest86+_multiboot.bin      vmlinuz-5.15.0-53-generic
config-5.15.0-53-generic  initrd.img-5.15.0-53-generic  System.map-5.15.0-52-generic  vmlinuz.old
efi                       initrd.img.old                System.map-5.15.0-53-generic
grub                      memtest86+.bin                vmlinuz
initrd.img                memtest86+.elf                vmlinuz-5.15.0-52-generic
```
Qual versão do kernel possui um link simbólico apontado pelo vmlinuz? Utilize o comando ls -l para verificar:
```
ls -l vmlinuz
lrwxrwxrwx 1 root root 25 mai 25  2022 vmlinuz -> vmlinuz-5.15.0-33-generic
```
Este é um arquivo grande com três componentes:
* Bloco de inicialização de 512 bytes
* Carregador de inicialização secundário
* Kernel compactado com Gzip
De onde vem esse nome? O Unix tradicionalmente inicializa a partir de um arquivo chamado /unix. Assim, os desenvolvedores do Linux usaram /linux. Com o uso de memória virtual, o arquivo passou a ser /vmlinux. Por fim, a última letra foi trocada por z para indicar que é um kernel compactado (zipped).
## Configuração de Compilação do Kernel
O arquivo de configuração do kernel atual encontra-se em /boot/config-. Este arquivo permite algumas informações caso enfrente problemas de kernel, pois fornece a configuração exata usada durante a compilação. Para verificar o conteúdo do arquivo, execute o comando:
```
cat /boot/config-$(uname -r)
```
Copie do terminal e cole aqui as 8 últimas linhas do arquivo acima:
```
# CONFIG_TEST_FREE_PAGES is not set
# CONFIG_TEST_FPU is not set
# CONFIG_TEST_CLOCKSOURCE_WATCHDOG is not set
CONFIG_ARCH_USE_MEMTEST=y
CONFIG_MEMTEST=y
# CONFIG_HYPERV_TESTING is not set
# end of Kernel Testing and Coverage
# end of Kernel hacking
```
## 2. Detecção de Hardware do Kernel
O sistema de arquivos /proc é realmente uma grande coleção de estruturas de dados do kernel apresentadas em um formato razoavelmente amigável, utilizado para obter as informações de hardware da máquina. Parece ser uma hierarquia de diretórios e arquivos, que você pode explorar com cd e ls e investigar em muitos casos com cat.
Para saber o que o kernel detectou sobre a CPU, execute o comando: cat /proc/cpuinfo. Com base nesse comando, podemos obter quantos processadores estão sendo identificados pelo kernel:
```
cat /proc/cpuinfo | grep processor | wc -l
16
```
Para saber o que o kernel detectou sobre o estado de memória atual, execute o comando: cat /proc/meminfo. Com base nesse comando, qual a memória total da máquina identificada pelo kernel?
```
cat /proc/meminfo | grep MemTotal
MemTotal:       16158340 kB
```
O kernel também pode fornecer para o espaço de usuário informações sobre as partições disponíveis. Para verificar, execute o comando:
```
cat /proc/partitions
```
```
major minor  #blocks  name

   7        0          4 loop0
   7        1     242196 loop1
   7        2     119564 loop2
   7        3     244308 loop3
   7        4      56944 loop4
   7        5    1002908 loop5
   7        6      64760 loop6
   7        7      64836 loop7
 259        0 1000204632 nvme0n1
 259        1     975872 nvme0n1p1
 259        2   31250432 nvme0n1p2
 259        3     976896 nvme0n1p3
 259        4  967000064 nvme0n1p4
   7        8     322128 loop8
   7        9     243264 loop9
   7       10     245632 loop10
   7       11     168712 loop11
   7       12     354608 loop12
   7       13     354640 loop13
   7       14      83212 loop14
   7       15      93888 loop15
   7       16      37980 loop16
   7       18     990652 loop18
   7       19       1112 loop19
   7       20       1116 loop20
   7       21      57904 loop21
   7       22      51036 loop22
   7       23      56948 loop23
```
   
Podemos listar também quais dispositivos estão conectados. Observe que o carregamento de módulos do kernel pode levar à detecção de mais hardware e ao aparecimento automático de mais arquivos especiais de dispositivo em /dev. Acessando o /dev, quantos dispositivos são reconhecidos pelo kernel?
```
ls /dev | wc -l
248
```
O Kernel pode fornecer informações de quais os dispositivos com padrão de barramento PCI estão conectados no momento. O lspci é um comando em sistemas operacionais do tipo Unix que imprime informações detalhadas sobre todos os barramentos e dispositivos PCI no sistema. Ele é baseado em uma biblioteca portátil comum libpci, que oferece acesso ao espaço de configuração PCI em vários sistemas operacionais.
```
lspci | tail -5       # Lista os últimos 5 dispositivos
01:00.0 VGA compatible controller: NVIDIA Corporation TU117M [GeForce GTX 1650 Mobile / Max-Q] (rev a1)
01:00.1 Audio device: NVIDIA Corporation Device 10fa (rev a1)
02:00.0 Ethernet controller: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller (rev 15)
03:00.0 SD Host controller: O2 Micro, Inc. SD/MMC Card Reader Controller (rev 01)
04:00.0 Non-Volatile memory controller: ADATA Technology Co., Ltd. Device 33f8 (rev 03)
```

Assim como os dispositivos PCI, o Kernel tem informações sobre os dispositivos USB conectados ao sistema. As informações podem ser obtidas através do comando:
```
$ lsusb
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 002: ID 04f2:b729 Chicony Electronics Co., Ltd Chicony USB2.0 Camera
Bus 001 Device 005: ID 22b8:2e81 Motorola PCS moto g(10)
Bus 001 Device 003: ID 8087:0026 Intel Corp. AX201 Bluetooth
Bus 001 Device 004: ID 046d:c534 Logitech, Inc. Unifying Receiver
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```
Para obter informações mais detalhadas sobre os dispositivos, execute os comandos acima com o parâmetro -v. Exemplo: lsusb -v
As informações acima e muitas outras são fornecidas diretamente pelo kernel para as aplicações do espaço do usuário. Dessa forma, as aplicações não precisam se preocupar em ter acesso diretamente ao hardware da máquina e nem de fazer modificações complexas no sistema. Tudo fica por responsábilidade do kernel em fornecer as informações necessárias de maneira simples.
## 3. Variaveis do Kernel
O Kernel possui algumas variáveis já definidas e que podem ser encontradas em sysctl. Para verificar quais variáveis estão definidas, use o comando:
```
$ sysctl -a
```
O comando acima reune diversas variáveis para configuração. Por exemplo, a estrutura de dados do kernel net.ipv4.tcp_fin_timeout que define o timeout no tcp é acessível como o arquivo /proc/sys/net/ipv4/tcp_fin_timeout. Em vez desse comando sysctl, você poderia ter alterado para o diretório /proc/sys/net/ipv4 e exibido seu conteúdo com cat:
```
$ cat /proc/sys/net/ipv4/tcp_fin_timeout
```
```
60
```
Observe que o arquivo acima resultou na mesma saída do comando sysctl quando buscamos pelo arquivo tcp_fin_timeout:
```
$ sysctl -a | grep net.ipv4.tcp_fin_timeout
```
```
sysctl: permission denied on key 'fs.protected_fifos'
sysctl: permission denied on key 'fs.protected_hardlinks'
sysctl: permission denied on key 'fs.protected_regular'
sysctl: permission denied on key 'fs.protected_symlinks'
sysctl: permission denied on key 'kernel.apparmor_display_secid_mode'
sysctl: permission denied on key 'kernel.cad_pid'
sysctl: permission denied on key 'kernel.unprivileged_userns_apparmor_policy'
sysctl: permission denied on key 'kernel.usermodehelper.bset'
sysctl: permission denied on key 'kernel.usermodehelper.inheritable'
sysctl: permission denied on key 'net.core.bpf_jit_harden'
sysctl: permission denied on key 'net.core.bpf_jit_kallsyms'
sysctl: permission denied on key 'net.core.bpf_jit_limit'
sysctl: permission denied on key 'net.ipv4.tcp_fastopen_key'
sysctl: permission denied on key 'net.ipv6.conf.all.stable_secret'
net.ipv4.tcp_fin_timeout = 60
sysctl: permission denied on key 'net.ipv6.conf.default.stable_secret'
sysctl: permission denied on key 'net.ipv6.conf.enp2s0.stable_secret'
sysctl: permission denied on key 'net.ipv6.conf.lo.stable_secret'
sysctl: permission denied on key 'net.ipv6.conf.wlp0s20f3.stable_secret'
sysctl: permission denied on key 'vm.mmap_rnd_bits'
sysctl: permission denied on key 'vm.mmap_rnd_compat_bits'
sysctl: permission denied on key 'vm.stat_refresh'
```
Você pode ler os valores atuais desses temporizadores de kernel, contadores e outros campos. Você também pode alterá-los! Agora vamos dizer que sua modificação entusiasmada dos valores do kernel acidentalmente coloca seu kernel em execução em um estado critico - isso não é nada improvável se você não for cuidadoso. Tudo o que você modificou é o kernel em execução na RAM, o arquivo do kernel armazenado no disco permanece inalterado. Então, bastaria reiniciar e você estaria de volta ao estado padrão. Mas por que você iria querer mexer com os valores do kernel? Pois pode ser feito um ajuste nos parâmetros do kernel em execução com finalidade de desempenho ou segurança.
## 4. Módulos do Kernel
Também conhecido como LKM (Loadable Kernel Modules), este é um mecanismo para adicionar ou remover código do kernel Linux em tempo de execução. Eles são ideais para drivers de dispositivo, permitindo que o kernel se comunique com o hardware sem precisar saber como o hardware funciona. A alternativa aos LKMs seria ter que recompilar o kernel para cada novo driver.
Sem essa capacidade modular, o kernel do Linux seria muito grande, pois teria que suportar todos os drivers que seriam necessários. Também seria necessário reconstruir o kernel toda vez que quisesse adicionar um novo hardware ou atualizar um driver de dispositivo.
Os LKMs são carregados em tempo de execução, mas não são executados no espaço do usuário, assim, o código do kernel não pode acessar bibliotecas de código que são escritas para o espaço do usuário Linux. A interface entre o espaço do kernel e o espaço do usuário é claramente definida e controlada.
Assim, a maioria dos drivers são implementados como módulos de kernel do Linux. Quando esses drivers não são necessários, podemos descarregar apenas esse driver específico, o que reduzirá o tamanho da imagem do kernel.
Os módulos do kernel terão uma extensão .ko. Em um sistema linux normal, os módulos do kernel residirão dentro do diretório /lib/modules/kernel_version/kernel/. Mostre o conteúdo desse diretório:
```
ls /lib/modules/$(uname -r)/kernel
```
```
arch    drivers  lib  nvidia-390     nvidia-470     nvidia-510srv  nvidia-520  ubuntu
block   fs       mm   nvidia-418srv  nvidia-470srv  nvidia-515     samples     v4l2loopback
crypto  kernel   net  nvidia-450srv  nvidia-510     nvidia-515srv  sound       zfs
```
Você pode facilmente listar todos os módulos do kernel que estão atualmente carregados no kernel executando o comando lsmod, por exemplo:
```
$ lsmod
```
Copie do terminal e cole aqui as 8 últimas linhas do arquivo acima:
```
libahci                45056  1 ahci
idma64                 20480  0
xhci_pci_renesas       20480  1 xhci_pci
intel_pmt              16384  0
hid                   151552  6 i2c_hid,usbhid,hid_multitouch,hid_generic,hid_logitech_dj,hid_logitech_hidpp
wmi                    32768  1 mxm_wmi
video                  61440  1 i915
pinctrl_tigerlake      32768  0
```
Cada linha de saída lsmod especifica o nome de um módulo do kernel atualmente carregado na memória, a quantidade de memória que usa e a soma total dos processos que estão usando o módulo e outros módulos que dependem dele.
Finalmente, observe que a saída lsmod é menos detalhada e consideravelmente mais fácil de ler do que o conteúdo do pseudo-arquivo /proc/modules.
Você também pode encontrar informações sobre um módulo específico usando o comando $ modinfo nome_do_modulo. Por exemplo, para obter o nome do arquivo do modulo de video, utilize:
```
modinfo video | grep filename
```
```
filename:       /lib/modules/5.15.0-53-generic/kernel/drivers/acpi/video.ko
```
Assim vemos que o utilitário modinfo fornece várias informações sobre este módulo. As informações que você obtém são de responsabilidade dos 
desenvolvedores desse módulo. Então você pode obter algo muito útil, com uma explicação, uma lista de parâmetros opcionais de tempo de carregamento 
e o que eles significam, e assim por diante. Ou você pode obter uma tabela enigmática de endereços hexadecimais e uma lista de endereços de 
barramento PCI e um lembrete de que você sempre pode ler o código-fonte C e descobrir a partir daí.
