#include <stdio.h>
int get_length(char *word) {
    int length = 0;
    
    while(word[length] != '\0'){
        length++;
    }
    return length;
}

int handle_get_length(){
    int length;
    printf("%s\n", "Digite uma palavra:");
    char word[100];
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    fgets(word, sizeof(word), stdin);
    length = get_length(word);
    if(word[length - 1] == '\n'){
        length = length - 1;
    }
    printf("O tamanho da palavra é: %d\n", length);
    return 0;
}

int sum_numbers_in_array(int *numbers) {
    int i;
    int result = 0;
    for(i = 0; i < 5; i++){
        result = result + numbers[i];
    }
    return result;
}

int handle_sum_numbers(){
    int numbers[5];
    int i;
    printf("%s\n", "Digite 5 números separados por espaço:");
    for(i = 0; i < 5; i++){
        scanf("%d", &numbers[i]);
    }
    int result = sum_numbers_in_array(numbers);
    printf("A soma dos números é: %d\n", result);
    return 0;
}

int fatorial(int number) {
    if(number == 1){
        return 1;
    }
    return number * fatorial(number - 1);
}

int handle_fatorial(){
    int number;
    printf("%s\n", "Digite um número:");
    scanf("%d", &number);
    int f = fatorial(number);
    printf("O fatorial de %d é: %d\n", number, f);
    return 0;
}

int is_prime(int number) {
    int prime = 1;
    int middle = number/2;
    int i;
    for(i = 2; i <= middle; i++){
        if(number % i == 0){
            prime = 0;
        }
    }
    return prime;
}

int handle_is_prime(){
    int number;
    printf("%s\n", "Digite um número:");
    scanf("%d", &number);
    int prime = is_prime(number);
    if(prime){
        printf("%d é primo\n", number);
    }else{
        printf("%d não é primo\n", number);
    }
    return 0;
}

int show_options() {
    printf("%s\n", "Selecione uma das opções abaixo:");
    printf("%s\n", "1 - Contar o tamanho de uma palavra");
    printf("%s\n", "2 - Somar 5 números");
    printf("%s\n", "3 - Calcular o fatorial de um número");
    printf("%s\n", "4 - Verificar se um número é primo");
    printf("%s\n", "5 - Sair");
    return 0;
}

int handle_options() {
    int option;
    scanf("%d", &option);
    int number;
    switch(option){
        case 1:
           handle_get_length();
            break;
        case 2:
           handle_sum_numbers();
            break;
        case 3:
            handle_fatorial();
            break;
        case 4:
            handle_is_prime();
            break;
        case 5:
            return 1;
        default:
            printf("%s\n", "Opção inválida");
            break;
    }
    return 0;
}

int main() {
   int option;
   while(1){
    show_options();
    if(handle_options()){
        break;
    }
   }
   printf("%s\n", "O programa foi encerrado");
    return 0;
}