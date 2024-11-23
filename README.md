# SmartHome IoT
## Link do video
- https://www.youtube.com/watch?v=0kfSysyUzLA
## Descrição do Projeto

Este repositório contém a parte de **Internet das Coisas (IoT)** do projeto **SmartHome**, cujo objetivo principal é monitorar o consumo de energia residencial. O sistema utiliza um circuito eletrônico simulado, desenvolvido no **Wokwi**, para medir o consumo energético em kWh.

Os dados gerados pelo simulador podem ser integrados ao sistema completo, proporcionando ferramentas de análise e relatórios detalhados sobre o consumo energético, bem como funcionalidades para cadastro e monitoramento de dispositivos.

### Componentes do Sistema IoT
1. **Simulação do Circuito:**
   - Desenvolvido no Wokwi, utilizando um microcontrolador e um potenciômetro para medir e simular o consumo energético.

2. **Node-RED :**
   - Utilizado para criar fluxos de dados e realizar integrações.

3. **Código-fonte:**
   - O código utilizado para a simulação do circuito está disponível na pasta `prototipo`.

---

## Tecnologias Utilizadas
- **Wokwi:** Para criação e simulação do circuito eletrônico.
- **Node-RED:** Para integração e visualização de fluxos de dados.
- **Arduino IDE:** Para edição e upload do código em microcontroladores físicos, caso necessário.

---

## Estrutura do Repositório
- **`README.md`**: Este arquivo com informações detalhadas do projeto.
- **`flows.json`**: Arquivo contendo os fluxos para o Node-RED.
- **Pasta `prototipo`:**
  - Contém os arquivos do simulador Wokwi, incluindo o código e diagramas necessários para replicar o circuito.

---

## Como Configurar e Testar a Solução

### Pré-requisitos
- Acesso à plataforma Wokwi (https://wokwi.com).
- Arduino IDE para edição de código, se necessário.
- Node-RED configurado para uso opcional de fluxos de dados.

### Passo a Passo

1. **Simulação do Circuito no Wokwi**
   - Abra a plataforma Wokwi em [wokwi.com](https://wokwi.com).
   - Importe os arquivos da pasta `prototipo`, incluindo o código e o esquema do circuito.
   - Execute a simulação diretamente no Wokwi para verificar o funcionamento do sistema.

2. **Código do Microcontrolador**
   - Caso queira adaptar o sistema para uso com hardware físico, abra o código fornecido na pasta `prototipo` utilizando a **Arduino IDE**.
   - Faça as adaptações necessárias e faça o upload para o microcontrolador.

3. **Fluxos no Node-RED**
   - Importe o arquivo `flows.json` no Node-RED para visualizar ou testar os fluxos de integração.

---

 **Integrantes**
- Camila Soares Pedra RM98246
- Gustavo Bertti RM552243
- Gustavo Macedo da Silva RM552333
- Rafael da Silva Camargo RM551127 

