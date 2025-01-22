
## Opções da Aplicação
A aplicação oferece as seguintes opções:

### Opção 1: Cadastrar Cidade
**Descrição:** Permite cadastrar uma nova cidade no sistema.  
**Parâmetros:** 
- `Nome da Cidade`: Nome da cidade a ser cadastrada.

### Opção 2: Cadastrar Trajeto
**Descrição:** Permite cadastrar um novo trajeto entre duas cidades.  
**Parâmetros:** 
- `Cidade de Origem`: Nome da cidade de origem.
- `Cidade de Destino`: Nome da cidade de destino.
- `Tipo de Trajeto`: Tipo do trajeto (0: Terrestre, 1: Aquático, 2: Aéreo).
- `Distância`: Distância do trajeto.

### Opção 3: Cadastrar Transporte
**Descrição:** Permite cadastrar um novo meio de transporte.  
**Parâmetros:** 
- `Nome do Transporte`: Nome do transporte.
- `Tipo de Transporte`: Tipo do transporte (0: Terrestre, 1: Aquático, 2: Aéreo).
- `Capacidade`: Capacidade do transporte.
- `Velocidade`: Velocidade do transporte.
- `Distância de Descanso`: Distância que o transporte percorre antes de precisar descansar.
- `Tempo de Descanso`: Tempo de descanso do transporte.
- `Cidade Atual`: Cidade onde o transporte está atualmente.

### Opção 4: Cadastrar Passageiro
**Descrição:** Permite cadastrar um novo passageiro no sistema.  
**Parâmetros:** 
- `Nome do Passageiro`: Nome do passageiro.
- `Cidade Atual`: Cidade onde o passageiro está atualmente.

### Opção 5: Iniciar Viagem
**Descrição:** Inicia uma nova viagem com um transporte e passageiros específicos.  
**Parâmetros:** 
- `Nome do Transporte`: Nome do transporte que realizará a viagem.
- `Cidade de Origem`: Cidade de origem da viagem.
- `Cidade de Destino`: Cidade de destino da viagem.
- `Nomes dos Passageiros`: Lista de nomes dos passageiros (separados por espaço, termine com 'end').

### Opção 6: Avançar Horas de Viagem
**Descrição:** Avança o tempo de viagem de um transporte específico.  
**Parâmetros:** 
- `Nome do Transporte`: Nome do transporte cuja viagem será avançada.
- `Horas a Avançar`: Número de horas a avançar na viagem.

### Opção 7: Relatar Status da Viagem
**Descrição:** Relata o status atual de uma viagem em andamento.  
**Parâmetros:** 
- `Nome do Transporte`: Nome do transporte cuja viagem será relatada.

### Opção 8: Sair
**Descrição:** Encerra a aplicação.  
**Parâmetros:** Nenhum.
.

## Configuração
compilação:
```
 g++ -I./include -o main main.cpp include/City.cpp include/Transport.cpp include/Passenger.cpp include/Route.cpp include/Travel.cpp include/Traffic_Controller.cpp
```
