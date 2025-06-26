# 🐶 | AumigosDoCoracao - Sistema de Cliníca Veterinária feito em C

### **A aplicação perfeita para sua cliníca veterinária!**  🐕

Sistema completo para gerenciamento de pacientes (animais) em clínicas veterinárias, desenvolvido em C puro. Oferece cadastro, consultas personalizadas e edição de dados, com armazenamento persistente em arquivo.

## 🐾 Funcionalidades
- **Cadastrar Novo Paciente**:
Registra nome, espécie, raça, idade, tutor e contato.
ID único gerado automaticamente (evita duplicatas).

- **Consultar Paciente por ID**:
Busca pelo ID gerado pelo sistema.

- **Consultar Paciente por Nome**:
Busca exata (case-sensitive).

- **Consultar por Espécie ou Raça**:
Filtra por espécie (ex: "Felino") ou raça (ex: "Persa").

- **Alterar Dados do Paciente**:
Edita todas as informações exceto o ID (imutável).

- **Visualizar Todos os Pacientes**:
Lista ordenada por ID, nome ou espécie.

## ⚙️ Geração Automática de ID
O sistema atribui um ID sequencial (ex: 1, 2, 3...) ou baseado em timestamp (ex: 202406283).
Evita erros de digitação e garante unicidade.

Implementação exemplo:

```
int gerar_id() {  
static int ultimo_id = 0;  
return ++ultimo_id;  
}
```

## 📁 Estrutura do Arquivo de Dados
```
ID|Nome|Espécie|Raça|Idade|Tutor|Contato  
1|Rex|Cachorro|Labrador|5|Maria|(11) 98765-4321  
2|Mimi|Gato|Siamês|3|Carlos|(21) 1234-5678  
```

## 🚀 Tecnologias Utilizadas
- **Linguagem:** C


## 📖 Como Compilar e Executar
1. **Clone o repositório**

   "https://github.com/anitaspossar/AumigosDoCoracao.git"

2. **Abra o código na IDE CLion (ou qualquer outra IDE que você esteja acostumado)**

3. **Compile e execute os arquivos C**
