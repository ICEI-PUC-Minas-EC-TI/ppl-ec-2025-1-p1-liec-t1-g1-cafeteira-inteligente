Testes do Projeto

Inicialmente, os testes foram realizados no Tinkercad. Nela, verificamos a correta conexão do relé com o Arduino e o funcionamento simulado do medidor de temperatura. Essa etapa virtual nos permitiu identificar e corrigir potenciais problemas de fiação e lógica antes da montagem física.

Com a aquisição dos componentes, os testes passaram para o hardware real. Primeiramente, testamos a funcionalidade do relé de forma isolada, sem a conexão à fiação elétrica de 110V, para confirmar seu acionamento e desacionamento. Somente após essa validação inicial, o relé foi conectado à rede elétrica, e sua operação com o ebulidor foi testada em um ambiente controlado.

Simultaneamente, focamos na comunicação entre o Arduino e o aplicativo. Validamos a conexão Bluetooth e a transferência bidirecional de dados, assegurando que as leituras de temperatura eram enviadas corretamente do Arduino para o aplicativo e que os comandos de ligar/desligar eram recebidos e executados pelo Arduino. A funcionalidade de agendamento também foi testada para garantir que o aquecedor ligasse no horário programado
