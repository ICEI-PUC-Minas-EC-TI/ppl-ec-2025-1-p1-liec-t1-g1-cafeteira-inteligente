
# Materiais

* Os materiais utilizados no projeto foram:
- Arduino UNO.
- Resistor.
- Jumper.
- Módulo Relé 1 Canal 5v.
- Módulo Bluetooth 4.0 AT-09.
- Sensor de temperatura DS18B20
- Ebulidor elétrico.
- Extensão.
- Leiteira.

# Desenvolvimento

## Desenvolvimento do Aplicativo:

### Interface
Desenvolvimento das Telas do Aplicativo: Foco na Usabilidade
A criação das telas do aplicativo foi centrada na facilidade de uso, priorizando uma experiência intuitiva e eficiente para o usuário.

Para alcançar esse objetivo, os elementos de maior importância foram visualmente destacados. O botão de ligar/desligar o ebulidor, o medidor de temperatura e o status da conexão com o Arduino foram intencionalmente projetados com fonte e tamanho maiores em relação aos demais botões e informações. Essa distinção visual permite que o usuário identifique e interaja rapidamente com as funções essenciais, tornando o uso do aplicativo ágil e descomplicado.

### Código
Conectividade Bluetooth
A etapa inicial e fundamental foi a implementação da conexão com o módulo Bluetooth. Utilizamos a extensão BluetoothLE no App Inventor para estabelecer a comunicação com o módulo AT-09. Essa escolha permitiu uma conexão estável e a troca de dados bidirecional entre o aplicativo e o Arduino.

Troca de Informações Bidirecional
Uma vez estabelecida a conexão, focamos na troca de informações entre o Arduino e o aplicativo. Isso envolveu o envio contínuo da temperatura medida pelo sensor do Arduino para ser exibida no aplicativo. Inversamente, o aplicativo envia comandos ao Arduino para ligar ou desligar o relé, controlando assim o aquecedor. Essa comunicação em tempo real é crucial para o monitoramento e a automação.

Funcionalidade de Agendamento
Por fim, implementamos a funcionalidade de agendamento, permitindo que o usuário defina um horário específico para o aquecedor ser ligado automaticamente. Essa característica adiciona um nível de conveniência e automação ao sistema, eliminando a necessidade de intervenção manual no momento desejado.

## Desenvolvimento do Hardware

Montagem
A montagem do projeto começou com a organização dos componentes eletrônicos. Conectamos o módulo relé ao Arduino para controlar o ebulidor de 110V. Em seguida, o sensor de temperatura DS18B20 foi conectado, garantindo que sua parte à prova d'água estivesse pronta para imersão. Por fim, o módulo Bluetooth AT-09 foi integrado ao Arduino, permitindo a comunicação sem fio. A fiação foi cuidadosamente organizada para evitar curtos-circuitos e garantir uma conexão estável para todos os componentes.

### Desenvolvimento do Código
O desenvolvimento do código para o Arduino/ESP teve como base a funcionalidade principal de controle de temperatura e comunicação. Utilizamos as bibliotecas <DallasTemperature.h> e <OneWire.h> para gerenciar o sensor DS18B20 e obter leituras precisas de temperatura. Para a comunicação com o módulo Bluetooth, a biblioteca <SoftwareSerial.h> foi essencial, permitindo a troca de dados com o aplicativo. A lógica do código foi estruturada para receber comandos do aplicativo para ligar/desligar o relé e para enviar os dados de temperatura de volta, garantindo a interação em tempo real.

### Comunicação entre App e Hardware
O processo de comunicação entre o aplicativo e o Arduino/ESP foi um pilar fundamental do projeto. A conexão inicial foi estabelecida utilizando a extensão BluetoothLE do App Inventor no aplicativo, pareando-o com o módulo AT-09 no Arduino. Uma vez conectados, a troca de informações foi bidirecional e contínua. O Arduino enviava as leituras de temperatura do DS18B20 para serem exibidas no aplicativo, enquanto o aplicativo enviava comandos para o Arduino ligar ou desligar o relé, controlando o ebulidor. Além disso, a funcionalidade de agendamento de horário no aplicativo enviava um comando específico para o Arduino, que interpretava e acionava o ebulidor no momento programado
